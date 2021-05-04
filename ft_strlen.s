global ft_strlen

ft_strlen:
	xor		rcx, rcx			;rcx : compteur, rcx = 0

count:
	cmp		byte [rdi + rcx], 0	;if rdi[rcx] == '\0'
	je		return				;string is finished
	inc		rcx					;else, rcx++
	jmp		count				;loop

return:
	mov		rax, rcx			; rax = rcx
	ret							;return rax