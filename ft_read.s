section .text
global ft_read
extern __errno_location

ft_read:
	mov		rax, 0				;0 car on veut syscall a read
	syscall
	cmp		rax, 0
	jl		error
	ret

error:
	neg		rax					;car syscall renvoie errno en negatif
	mov		rdi, rax			;temporaire, rax prendra le pointeur sur errno apres le call sur errno location
	call	__errno_location	;renvoie un pointeur sur errno dans rax
	mov		[rax], rdi			;on met rdi à l'emplacement pointé par rax
	mov		rax, -1				;on met -1 car c'est la valeur de retour en cas d'erreur de read
	ret