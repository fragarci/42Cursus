global _start;a
extern printf
extern exit
section .text
m db"global _start;a%1$cextern printf%1$cextern exit%1$csection .text%1$cm db%2$c%3$s%2$c,0%1$c_start:lea rdi,[rel m]%1$cmov rsi,10%1$cmov rdx,34%1$clea rcx,[rel m]%1$ccall[rel printf wrt ..got]%1$ccall e;b%1$ce:call[rel exit wrt ..got]",0
_start:lea rdi,[rel m]
mov rsi,10
mov rdx,34
lea rcx,[rel m]
call[rel printf wrt ..got]
call e;b
e:call[rel exit wrt ..got]