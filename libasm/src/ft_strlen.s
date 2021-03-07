section	.text
global  ft_strlen

ft_strlen:
		xor		rax, rax
		cmp		rdi, 0
		je		return
		jmp		count

increment:
		inc		rax

count:
		cmp		BYTE[rdi + rax], 0
		jne		increment

return:
		ret