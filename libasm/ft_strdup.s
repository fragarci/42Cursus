;### Function Parameters ###
;           rdi
;      const char *s

extern ft_strlen
extern malloc
extern ft_strcpy
section .text
global ft_strdup

ft_strdup:							;	char *ft_strdup(const char *s) {
	push rdi						; 		const char *aux = s;
	call [rel ft_strlen wrt ..got]	;		rax = ft_strlen(s);
	mov rdi, rax					;		rdi = rax;
	call [rel malloc wrt ..got]		;		rax = malloc(rdi);
	mov rdi, rax					;		rdi = rax;
	pop rsi							;		rsi = aux;
	call [rel ft_strcpy wrt ..got]	;		rax = ft_strcpy(rdi, rsi);
	ret								;		return (rax);
									;	}