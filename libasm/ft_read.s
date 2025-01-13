;############################### Read Syscall ###############################
;               rax               rdi               rsi               rdx
;                0          unsigned int fd      char *buf       size_t count

;############ Function Parameters ############
;          rdi          rsi          rdx
;        int fd      void *buf   size_t count

extern __errno_location
section .text
global ft_read

ft_read:									;	int ft_read(int fd, void *buf, unsigned int count) {
	xor rax, rax							;		rax = 0;
	syscall									;		syscall(rax);
	cmp rax, 0								;		if (rax > 0)
	jl set_errno
	ret										;			return (rax);
	set_errno:
	mov rdi, -1								;		rdi = -1;
	mul rdi									;		rax = rax * rdi;
	mov rdi, rax							;		rdi = rax;
	call [rel __errno_location wrt ..got]	;		rax = errno_location();
	mov [rax], rdi							;		*rax = rdi;
	mov rax, -1								;		rax = -1
	ret										;		return (rax);