section	.text
global	ft_read
extern	__errno_location

ft_read:
		mov		rax, 0x00
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