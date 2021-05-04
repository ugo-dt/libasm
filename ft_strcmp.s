global ft_strcmp

ft_strcmp:
	xor		rcx, rcx
	xor		rax, rax

compare:
	cmp		byte [rdi + rcx], 0
	je		return
	cmp		byte [rsi + rcx],  0
	je		return
	mov		al, byte [rdi + rcx]
	cmp		byte [rsi + rcx], al
	jne		return
	inc		rcx
	jmp		compare

return:
	movzx	rax, byte [rdi + rcx]
	movzx	rdx, byte [rsi + rcx]
	sub		rax, rdx
	ret