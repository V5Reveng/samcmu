#![feature(restricted_std)]
#![feature(default_alloc_error_handler)]
#![no_main]

use mallocator::Mallocator;

#[no_mangle]
pub unsafe fn __aeabi_unwind_cpp_pr0() -> () {
	loop {}
}

#[global_allocator]
static ALLOCATOR: Mallocator = Mallocator;
