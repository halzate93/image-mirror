 sys_exit equ 1

 global _start	
 extern printf

	
segment .data
	format:	db "%s\n", 0AH, 0
	
segment .text
	
 _start:
	mov ebp, esp

	cmp dword [ebp + 4], 1
	je noargs
	
	mov ebx, 3
	mov rax, 0
	mov rdi, format
	mov rsi, 8 
	call printf

	jmp exit
	
 noargs:
	jmp exit

 exit:
	mov esp, ebp

	mov eax, sys_exit
	xor ebx, ebx 		;volver 0 un registro
	int 80H