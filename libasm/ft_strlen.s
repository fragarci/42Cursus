;### Function Parameters ###
;           rdi
;      const char *s

section .text
global ft_strlen

ft_strlen:					;	unsigned int ft_strlen(const char *s) {
	xor rax, rax			;		rax = 0;
	.loop_start:			;		while (*s != 0) {
	cmp BYTE[rdi], 0		;			if (*s == 0)
	je .loop_end			;				break;
	add rax, 1				;			rax++;
	add rdi, 1				;			s++;
	jmp .loop_start			;	}
	.loop_end:				;		return (rax);
	ret