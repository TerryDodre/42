section	.text
global	ft_strcmp

ft_strcmp:
		xor		rcx, rcx
		cmp		rdi, 0
		je		null
		cmp		rsi, 0
		je		null
		jmp		compare

increment:
		inc		rcx
		cmp		BYTE[rdi + rcx], 0
		je		return
		cmp		BYTE[rsi + rcx], 0
		je		return

compare:
		mov		al, BYTE[rdi + rcx]
		cmp		BYTE[rsi + rcx], al
		je		increment

return:
		movsx	rax, BYTE[rdi + rcx]
		movsx	rbx, BYTE[rsi + rcx]
		sub		rax, rbx
		ret

null:
		xor		rax, rax
		ret