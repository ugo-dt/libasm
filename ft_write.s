extern __errno_location
global ft_write

ft_write:
	mov		rax, 1				;1 car on veut syscall a write
	syscall
	cmp		rax, 0
	jl		error
	ret

error:
	neg		rax					;le syscall renvoie la valeur de errno en negatif
	mov		rdi, rax			;temporaire, rax prendra le pointeur sur errno
	call	__errno_location	;renvoie un pointeur sur errno dans rax
	mov		[rax], rdi			;on met la valeur de errno à l'emplacement pointé
	mov		rax, -1				;la fonction write renvoie -1 en cas d'erreur
	ret