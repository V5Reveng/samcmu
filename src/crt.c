#include <stdint.h>

int main(void);
void _exit(int) __attribute__((noreturn));
void __attribute__((weak)) _init(void) {}
void __attribute__((weak)) _fini(void) {}

typedef void (*void_fn_ptr)(void);

#define MAX_ATEXIT_HANDLERS 32
static unsigned int num_atexit_handlers = 0;
static void_fn_ptr atexit_handlers[MAX_ATEXIT_HANDLERS];

int atexit(void_fn_ptr callback) {
	if (num_atexit_handlers >= MAX_ATEXIT_HANDLERS) {
		return -1;
	}
	atexit_handlers[num_atexit_handlers] = callback;
	++num_atexit_handlers;
	return 0;
}
static void call_atexit(void) {
	for (unsigned int i = 0; i < num_atexit_handlers; ++i) {
		atexit_handlers[i]();
	}
}

static void call_init(void) {
	extern void_fn_ptr __preinit_array_start[];
	extern void_fn_ptr __preinit_array_end[];
	extern void_fn_ptr __init_array_start[];
	extern void_fn_ptr __init_array_end[];

	for (void_fn_ptr* entry = __preinit_array_start; entry < __preinit_array_end; ++entry) {
		(*entry)();
	}
	_init();
	for (void_fn_ptr* entry = __init_array_start; entry < __init_array_end; ++entry) {
		(*entry)();
	}
}

static void call_fini(void) {
	extern void_fn_ptr __fini_array_start[];
	extern void_fn_ptr __fini_array_end[];

	for (void_fn_ptr* entry = __fini_array_end - 1; entry >= __fini_array_start; --entry) {
		(*entry)();
	}
	_fini();
}

extern uint32_t __bss_start[];
extern uint32_t __bss_end[];

static void zero_bss(void) {
	for (uint32_t* entry = __bss_start; entry < __bss_end; ++entry) {
		*entry = 0;
	}
}

void __attribute__((noreturn)) exit(int const code) {
	call_atexit();
	call_fini();
	_exit(code);
}

void _start() {
	zero_bss();
	call_init();
	int ret = main();
	exit(ret);
}
