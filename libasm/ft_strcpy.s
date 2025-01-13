;####### Function Parameters #######
;          rdi             rsi
;       char *dest      char *src

section .text
global ft_strcpy

ft_strcpy:						;	char *ft_strcpy(char *dest, char *src) {
	mov rax, rdi				;		rax = dest;
	push rbx
	xor rbx, rbx				;		rbx = 0;
	.loop_start:				;		while (*dest != 0) {
	cmp BYTE[rsi], 0			;			if (*dest == 0)
	je .loop_end				;				break;
	mov bh, BYTE[rsi]			;			rbx = *dest;
	mov BYTE[rdi], bh			;			*src = rbx;
	add rdi, 1					;			dest++;
	add rsi, 1					;			src++;
	jmp .loop_start				;		}
	.loop_end:
	mov BYTE[rdi], 0			;	*dest = 0;
	pop rbx
	ret							;	return (dest);