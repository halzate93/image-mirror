 sys_exit equ 1
 global main
 extern mockupMatrix
 extern printMatrix
segment .data

segment .bss

segment .text
 _start:
	jmp main
 main:
	mov rax, 0
	call mockupMatrix

	mov rdi, rax
	mov rax, 0
	call printMatrix
	
	jmp exit
	
 exit:	
	mov eax, sys_exit
	int 80h









	