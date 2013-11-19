 sys_exit equ 1
 ;channel equ 3
 one equ 1
 global main
 extern print
segment .data
	i:	 dd 0 			;declaración de i en 0
	j:	 dd 0 			;//
	k:	 dd 0 			;//		;
	channel: dd 3	
segment .bss
	;data:	 resq 1			; 8 bytes para el puntero al struct
	rows:	 resd 1 		; 4 bytes para el entero de rows
	cols:	 resd 1 		; 4 bytes para las columnas
	;img:	 resq 1 		; 8 bytes para el puntero a la imagen
	indexSrc:	 resd 1 	; index origen
	indexDst:	 resd 1 	; index destino

segment .text

 _start:
        jmp main

 main:
	mov [cols], dword 3
	mov [rows], dword 3
	;; poner argumentos en stack, llamar funciones...
 rowsLoop:

 colsLoop:

 chLoop:
	;; Se calcula el index de destino.
	mov eax, dword [cols]
	sub eax, dword one
	sub eax, dword [j]
	imul dword [channel]
	add eax, dword [k]
	mov [indexDst], dword eax
	mov eax, dword [i]
	imul dword [cols]
	imul dword [channel]
	add eax, dword [indexDst]
	mov [indexDst], dword eax


	;; Se calcula el indice fuente.
	mov eax,dword [j]
	imul dword [channel]
	add eax, dword [k]
	mov [indexSrc], dword eax
	mov eax, dword [i]
	imul dword [cols]
	imul dword [channel]
	add eax, dword [indexSrc]
	mov [indexSrc], dword eax

	mov rax,0
	mov rdi, [indexSrc]
	call print

	;; Se revisa el ciclo de k.
	mov eax,dword [k]
	add eax,one
	mov [k],dword eax
	mov ebx, dword [channel]
        cmp ebx,eax
	jne chLoop
	mov [k], dword 0

	
	;; Se revisa el ciclo de j.
	mov eax, dword [j]
	add eax,one
	mov [j], dword eax
	mov ebx, dword [cols]
	cmp eax, ebx
	jne colsLoop
	mov [j], dword 0


	;; Se revisa el ciclo de i.
	mov eax, dword[i]
	add eax, one
	mov [i], dword eax
	mov ebx, dword [rows]
	cmp ebx, eax
	jne rowsLoop

 exit:
	mov eax, sys_exit
	int 80h
	