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
	ret