;####### Function Parameters #######
;          rdi             rsi
;     const char *s1  const char *s2

section .text
global ft_strcmp

ft_strcmp:
	xor rax, rax
	ft_strcmp_start:
	; check if string is over ;
	cmp BYTE[rdi], 0
	je ft_strcmp_exit
	cmp BYTE[rsi], 0
	je ft_strcmp_exit

	movzx rax, BYTE[rdi]
	movzx rbx, BYTE[rsi]
	sub rax, rbx
	cmp rax, 0
	jnz ft_strcmp_exit
	add rdi, 1
	add rsi, 1
	jmp ft_strcmp_start
	ft_strcmp_exit:
	movzx rax, BYTE[rdi]
	movzx rbx, BYTE[rsi]
	sub rax, rbx
	ret