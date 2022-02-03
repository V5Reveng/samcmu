INCLUDE linker/prelude.ld
INCLUDE linker/memory.ld

ENTRY(boot_start)

REGION_ALIAS("ACTIVE", COLD)
INCLUDE linker/cold-sections.ld

__sysapi_func_table_start = 0x037fc000;
