global ft_strdup
extern malloc
extern ft_strlen
extern ft_strcpy
extern __errno_location

ft_strdup:
	call	ft_strlen			;call ft_strlen sur rdi (la string *s)
	push	rdi					;push rdi dans la stack pour ne pas la perdre
	inc		rax					;rax a la taille de la string, +1 pour le \0
	mov		rdi, rax			;malloc utilise rdi, on lui donne la taille
	call	malloc				;malloc renvoie le pointeur sur l'espace alloué dans rax
	cmp		rax, 0				;on check si malloc échoue
	je		error				;si oui on jump vers error
	mov		rdi, rax			;on met le pointeur dans rdi, qu'on passe ensuite a strcpy
	pop		rsi					;pop rappelle le dernier push (ici rdi qui etait la string) vers rsi, utilisé par strcpy
	call	ft_strcpy			;en gros ft_strcpy(rdi, rsi) avec rdi le pointeur vers la nouvelle, et rsi la string de base
	ret							;et on return rax, qui contient le retour de strcpy soit le pointeur sur la string dest

error:
	neg		rax					;en cas d'erreur malloc renvoie errno mais en negatif
	mov		rdi, rax			;temporaire, rax prendra le pointeur sur errno
	call	__errno_location	;renvoie dans rax un pointeur sur errno
	mov		[rax], rdi			;on met la valeur de errno qui etait dans rdi a sa place
	mov		rax, 0				;on veut renvoyer NULL en cas d'erreur de strdup
	ret