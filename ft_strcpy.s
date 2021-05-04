global ft_strcpy

ft_strcpy:
	xor		rcx, rcx				;loop counter, rcx = 0

copy:
	cmp		byte [rsi + rcx], 0
	je		return
	mov		al, byte [rsi + rcx]	;temp variable al
	mov		byte [rdi + rcx], al	;dest[rcx] = al
	jmp		copy

return:
	mov		byte [rdi + rcx], 0		;add \0 at the end of dest
	mov		rax, rdi				;return the start of dest
	ret