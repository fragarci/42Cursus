global _start
extern sprintf
extern dprintf
extern access
extern exit
extern system
section .data
count:dq 5
file_name:db "Sully_%d.s",0
cmd:db "nasm -f elf64 Sully_%1$d.s -o Sully_%1$d.o && cc -Wall -Wextra -Werror -nostartfiles Sully_%1$d.o -o Sully_%1$d && ./Sully_%1$d"
access_str:db "Sully_5.s",0
source:db "global _start%1$cextern sprintf%1$cextern dprintf%1$cextern access%1$cextern exit%1$cextern system%1$csection .data%1$ccount:dq %2$d%1$cfile_name:db %3$cSully_%4$cd.s%3$c,0%1$ccmd:db %3$cnasm -f elf64 Sully_%4$c1$d.s -o Sully_%4$c1$d.o && cc -Wall -Wextra -Werror -nostartfiles Sully_%4$c1$d.o -o Sully_%4$c1$d && ./Sully_%4$c1$d%3$c%1$caccess_str:db %3$cSully_5.s%3$c,0%1$csource:db %3$c%5$s%3$c,0%1$cfile_buff:db 100 dup(0)%1$ccmd_buff:db 120 dup(0)%1$csection .text%1$c_start:cmp QWORD[count],0%1$cje e%1$clea rdi,[rel access_str]%1$cmov rsi,4%1$ccall [rel access wrt ..got]%1$ccmp rax,0%1$cje decrement%1$ckeep_going:lea rdi,[rel file_buff]%1$clea rsi,[rel file_name]%1$cmov rdx,[count]%1$ccall [rel sprintf wrt ..got]%1$clea rdi,[rel cmd_buff]%1$clea rsi,[rel cmd]%1$cmov rdx,[count]%1$ccall [rel sprintf wrt ..got]%1$cmov rax,2%1$clea rdi,[rel file_buff]%1$cmov rsi,1|100%1$cmov rdx,0o644%1$csyscall%1$cmov rdi,rax%1$clea rsi,[rel source]%1$cmov rdx,10%1$cmov rcx,[count]%1$cmov r8,34%1$cmov r9,37%1$csub rsp,8%1$cpush rsi%1$ccall [rel dprintf wrt ..got]%1$clea rdi,[rel cmd_buff]%1$ccall [rel system wrt ..got]%1$ce:xor rdi,rdi%1$ccall [rel exit wrt ..got]%1$cdecrement: dec QWORD[count]%1$cjmp keep_going%1$c",0
file_buff:db 100 dup(0)
cmd_buff:db 120 dup(0)
section .text
_start:cmp QWORD[count],0
je e
lea rdi,[rel access_str]
mov rsi,4
call [rel access wrt ..got]
cmp rax,0
je decrement
keep_going:lea rdi,[rel file_buff]
lea rsi,[rel file_name]
mov rdx,[count]
call [rel sprintf wrt ..got]
lea rdi,[rel cmd_buff]
lea rsi,[rel cmd]
mov rdx,[count]
call [rel sprintf wrt ..got]
mov rax,2
lea rdi,[rel file_buff]
mov rsi,1|100
mov rdx,0o644
syscall
mov rdi,rax
lea rsi,[rel source]
mov rdx,10
mov rcx,[count]
mov r8,34
mov r9,37
sub rsp,8
push rsi
call [rel dprintf wrt ..got]
lea rdi,[rel cmd_buff]
call [rel system wrt ..got];;
e:xor rdi,rdi
call [rel exit wrt ..got]
decrement: dec QWORD[count]
jmp keep_going
