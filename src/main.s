.syntax unified
.extern __user_stack_start
.extern __hot_entry_point
.global main
main:
	push {lr}

	// save kernel stack
	ldr ip, =kernel_stack_ptr
	str sp, [ip]
	// load the user stack
	// note: newlib _start already does this. However, we don't just want to support newlib. By not having any remnant of the kernel stack, there's less chance of something going wrong for whatever reason.
	ldr ip, =__user_stack_start
	mov sp, ip
	// load the user entry point
	ldr ip, =__hot_entry_point
	ldr ip, [ip] // __hot_entry_point is a vector holding the actual start address
	// run the user code!
	blx ip
	// restore kernel stack
	ldr ip, =kernel_stack_ptr
	ldr sp, [ip]

	pop {pc}

.section .bss
kernel_stack_ptr:
	.skip 4
