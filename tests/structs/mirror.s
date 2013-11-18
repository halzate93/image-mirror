 sys_exit equ 1

 global _start
 extern testFunction
	
segment .data

segment .bss
	
segment .text
 _start:
	mov rax, 0
	mov rdi, 5
	mov rsi, 10
	call testFunction

	jmp exit
	
 exit:
	mov eax, sys_exit
	int 80h
