%define S"%3$cdefine S%2$c%4$s%2$c%1$c%3$cdefine N%2$cGrace_kid.s%2$c%1$c%3$cmacro start 1%1$cextern dprintf%1$cextern exit%1$csection .text%1$cs db S,0%1$cn db N,0%1$cglobal _start%1$c_start:mov rax,2%1$clea rdi,[rel n]%1$cmov rsi,1|100%1$cmov rdx,0o644%1$csyscall%1$cmov rdi,rax%1$clea rsi,[rel s]%1$cmov rdx,10%1$cmov rcx,34%1$cmov r8,37%1$clea r9,[rel s]%1$ccall [rel dprintf wrt ..got]%1$ccall [rel exit wrt ..got]%1$c%3$cendmacro%1$cstart S;a"
%define N"Grace_kid.s"
%macro start 1
extern dprintf
extern exit
section .text
s db S,0
n db N,0
global _start
_start:mov rax,2
lea rdi,[rel n]
mov rsi,1|100
mov rdx,0o644
syscall
mov rdi,rax
lea rsi,[rel s]
mov rdx,10
mov rcx,34
mov r8,37
lea r9,[rel s]
call [rel dprintf wrt ..got]
call [rel exit wrt ..got]
%endmacro
start S;a