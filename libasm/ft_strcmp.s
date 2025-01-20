;####### Function Parameters #######
;          rdi             rsi
;     const char *s1  const char *s2

section .text
global ft_strcmp

ft_strcmp:					;	int ft_strcmp(const char *s1, const char *s2) {
	push rbx				;		int aux = rbx;
	.loop_start:			;		while (true) {
	movzx rax, BYTE[rdi]	;			rax = *s1;
	movzx rbx, BYTE[rsi]	;			rbx = *s2;
	sub rax, rbx			;			rax -= rbx;

	cmp BYTE[rdi], 0		;			if (*s1 == 0)
	je .loop_end			;				break;
	cmp BYTE[rsi], 0		;			if (*s2 == 0)
	je .loop_end			;				break;

	cmp rax, 0				;			if (rax != 0)
	jnz .loop_end			;				break;
	add rdi, 1				;			s1++;
	add rsi, 1				;			s2++;
	jmp .loop_start			;		}
	.loop_end:
	pop rbx					;		rbx = aux;
	cmp rax, 0				;		if (rax > 0)
	jg .greater				;			return (1);
	jl .lower				;		else if (rax < 0) return (-1);
	ret						;		else return (0);
	.greater:				;	}
	mov  rax, 1
	ret
	.lower:
	mov rax, -1
	ret
