;### Function Parameters ###
;           rdi
;      const char *s

section .text
global ft_strlen

ft_strlen:
	xor rax, rax
	ft_strlen_start:
	cmp BYTE[rdi], 0
	je ft_strlen_exit
	add rax, 1
	add rdi, 1
	jmp ft_strlen_start
	ft_strlen_exit:
	ret