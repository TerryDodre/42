section	.text
global	ft_strcpy

ft_strcpy:
		xor		rcx, rcx
		cmp		rdi, 0
		je		return
		cmp		rsi, 0
		je		return
		jmp		copy

increment:
		inc		rcx

copy:
		mov		al, BYTE[rsi + rcx]
		mov		BYTE[rdi + rcx], al
		cmp		al, 0
		jne		increment

return:
		mov		rax, rdi
		ret