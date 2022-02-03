.syntax unified

.extern _start
.extern __kernel_stack_start
.extern _exit

.section .boot
.global boot_start
boot_start:
	ldr ip, =__kernel_stack_start
	mov sp, ip

	ldr ip, =_start
	blx ip

	// this should not occur as _start calls exit, but handle it anyway
	mov r0, 0
	b _exit
