section .text
global ft_list_size

ft_list_size:
	push	rdi
	xor		rax, rax

count:
	cmp		rdi, 0
	je		return
	mov		rdi, [rdi + 8]
	inc		rax
	jmp		count

return:
	pop		rdi
	ret