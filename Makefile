ARCH_TUPLE := arm-none-eabi-

GCC := $(ARCH_TUPLE)gcc
LD := $(ARCH_TUPLE)gcc
OBJCOPY := $(ARCH_TUPLE)objcopy
CARGO := cargo
REVENG_CLI := /run/media/matt/zdani/code/v5-reveng/cli/target/debug/v5_cli

MFLAGS := -mcpu=cortex-a9 -mfpu=neon-fp16 -mfloat-abi=softfp
GCCFLAGS := $(MFLAGS) -O2 -pipe -Wall -Wextra -Wl,-Bstatic -iquoteinclude -ffunction-sections -fdata-sections
CARGOFLAGS := +nightly

DIR_SRC := src
DIR_BUILD := build
DIR_DIST := dist
DIR_LINKER := linker

DIR_COLD_BUILD := $(DIR_BUILD)/cold
DIR_HOT_BUILD := $(DIR_BUILD)/hot

COLD_SCRIPT := $(DIR_LINKER)/cold.ld
HOT_SCRIPT := $(DIR_LINKER)/hot.ld
COLD_SCRIPT_DEPS := $(DIR_LINKER)/cold-sections.ld $(DIR_LINKER)/prelude.ld $(DIR_LINKER)/memory.ld
HOT_SCRIPT_DEPS := $(DIR_LINKER)/hot-sections.ld $(DIR_LINKER)/prelude.ld $(DIR_LINKER)/memory.ld

COLD_SOURCES := stubs.c boot.s cold_magic.s api.c main.s crt.c
COLD_SOURCES := $(addprefix $(DIR_SRC)/,$(COLD_SOURCES))
COLD_OBJS := $(patsubst $(DIR_SRC)/%,$(DIR_COLD_BUILD)/%.o,$(COLD_SOURCES))
COLD_RUST_ARCHIVE := $(DIR_COLD_BUILD)/rust_cold.a

HOT_SOURCES := hot_magic.s hot.c crt.c
HOT_SOURCES := $(addprefix $(DIR_SRC)/,$(HOT_SOURCES))
HOT_OBJS := $(patsubst $(DIR_SRC)/%,$(DIR_HOT_BUILD)/%.o,$(HOT_SOURCES))

COLD_ELF := $(DIR_COLD_BUILD)/all.elf
COLD_BIN := $(DIR_DIST)/cold.bin
HOT_ELF := $(DIR_HOT_BUILD)/all.elf
HOT_BIN := $(DIR_DIST)/hot.bin

COLD_UPLOADED_TAG := $(DIR_COLD_BUILD)/.uploaded
HOT_UPLOADED_TAG := $(DIR_HOT_BUILD)/.uploaded

# use = rather than := to evaluate at expansion-time
cold_bin_hash = $(shell sha256sum $(COLD_BIN) | cut -d' ' -f1 | head -c18)
cold_bin_name = $(cold_bin_hash).bin
cold_bin_qual_name = reveng:$(cold_bin_name)

hot_bin_qual_name := user:slot_1.bin

$(HOT_OBJS): $(DIR_HOT_BUILD)/%.o: $(DIR_SRC)/%
	mkdir -p $(dir $@)
	$(GCC) $(GCCFLAGS) $< -c -o $@
$(COLD_OBJS): $(DIR_COLD_BUILD)/%.o: $(DIR_SRC)/%
	mkdir -p $(dir $@)
	$(GCC) $(GCCFLAGS) $< -c -o $@

FORCE: ;
$(COLD_RUST_ARCHIVE): FORCE
	mkdir -p $(dir $@)
	$(CARGO) $(CARGOFLAGS) build --release
	cp target/armv7a-none-eabi/release/libcold.a $@

$(HOT_ELF): $(HOT_SCRIPT) $(HOT_SCRIPT_DEPS) $(HOT_OBJS) $(COLD_ELF)
	mkdir -p $(dir $@)
	$(LD) $(GCCFLAGS) -o $@ -T $(HOT_SCRIPT) -nostdlib -nostartfiles $(HOT_OBJS) -Wl,-R,$(COLD_ELF) -lc -lm -lgcc

$(HOT_BIN): $(HOT_ELF)
	mkdir -p $(dir $@)
	$(OBJCOPY) $< -O binary $@

$(COLD_ELF): $(COLD_SCRIPT) $(COLD_SCRIPT_DEPS) $(COLD_OBJS) # $(COLD_RUST_ARCHIVE)
	mkdir -p $(dir $@)
	$(LD) $(GCCFLAGS) -o $@ -T $(COLD_SCRIPT) -nostdlib -nostartfiles -Wl,--whole-archive $(COLD_OBJS) -Wl,--no-whole-archive -lc -lm -lgcc

$(COLD_BIN): $(COLD_ELF)
	mkdir -p $(dir $@)
	$(OBJCOPY) $< -O binary $@

$(COLD_UPLOADED_TAG): $(COLD_BIN)
	mkdir -p $(dir $@)
	touch $@
	$(REVENG_CLI) filesystem sponge $(cold_bin_qual_name) --address 0x03800000 --force < $<
$(HOT_UPLOADED_TAG): $(HOT_BIN) $(COLD_UPLOADED_TAG)
	mkdir -p $(dir $@)
	touch $@
	$(REVENG_CLI) filesystem sponge $(hot_bin_qual_name) --address 0x07800000 --link $(cold_bin_qual_name) --force < $<
	
.PHONY: upload
upload: $(HOT_UPLOADED_TAG)

.PHONY: clean distclean devclean
clean:
	rm -rf build dist
distclean: clean
	rm -rf target
devclean:
	# this may be cleaner after implementing JSON output
	$(REVENG_CLI) filesystem ls reveng | sed '1,3d;s/^.* \([^ ]*\.bin\)$$/reveng:\1/' | xargs -I'{}' $(REVENG_CLI) filesystem rm \{\}
	test -e $(COLD_UPLOADED_TAG) && rm $(COLD_UPLOADED_TAG) || true
