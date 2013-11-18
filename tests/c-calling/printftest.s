 sys_exit equ 1

 global _start	
 extern printf

	
segment .data
	format:	db "%s", 0AH, 0

segment .text
 _start:
	pop rcx			;args count
	cmp rcx, 1
	
	je noargs

	pop rcx 		;path to app
	pop rcx			;first arg
	mov rax, 0
	mov rdi, format
	mov rsi, rcx 
	call printf

	jmp exit
	
 noargs:
	jmp exit
	
 exit:
	mov eax, sys_exit
	int 80H