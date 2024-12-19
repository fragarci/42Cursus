;############################### Read Syscall ###############################
;               rax               rdi               rsi               rdx
;                0          unsigned int fd      char *buf       size_t count

;############ Function Parameters ############
;          rdi          rsi          rdx
;        int fd      void *buf   size_t count

extern __errno_location
section .text
global ft_read

ft_read:
	xor rax, rax
	syscall
	cmp rax, 0
	jl set_errno
	ret
	set_errno:
	mov rdi, -1
	mul rdi ;rax = rax * rsi
	mov rdi, rax ;save errno in rdi
	call [rel __errno_location wrt ..got] ;get errno location
	mov [rax], rdi
	mov rax, -1
	ret