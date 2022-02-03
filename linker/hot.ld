INCLUDE linker/prelude.ld
INCLUDE linker/memory.ld

ENTRY(_start)

REGION_ALIAS("ACTIVE", HOT)
INCLUDE linker/hot-sections.ld
