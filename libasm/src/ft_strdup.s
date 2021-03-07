section	.text
global	ft_strdup
extern	ft_strlen
extern	malloc
extern	ft_strcpy

ft_strdup:
		xor		rax, rax
		cmp		rdi, 0
		je		return
		call	ft_strlen
		inc		rax
		push	rdi
		mov		rdi, rax
		call	malloc
		pop		rdi
		cmp		rax, 0
		je		return
		mov		rsi, rdi
		mov		rdi, rax
		call	ft_strcpy

return:
		ret