section	.text
global	ft_write
extern	__errno_location

ft_write:
		mov		rax, 0x01
		syscall
		test	rax, rax
		jnl		return

_fail:
		neg		rax
		mov		rdx, rax
		call	__errno_location
		mov		[rax], rdx
		mov		rax, -1

return:
		ret