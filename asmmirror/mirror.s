 sys_exit equ 1
 ;channel equ 3
 one equ 1
 two equ 2
 global main
 extern loadImage
 extern saveImage
 extern printf
 extern getCols
 extern getRows
 extern getData
 extern copyPixels
	
segment .data
	i:	 dd 0 			;declaración de i en 0
	j:	 dd 0 			;//
	k:	 dd 0 			;//		;
	channel: dd 3	
	format:	db "%d", 0AH, 0
	emptyargs: db "Invalid args, please input two valid image paths.", 0AH, 0
	msg:	 db "", 0AH, 0
segment .bss
	data:	 resq 1			; 8 bytes para el puntero al struct
	rows:	 resd 1 		; 4 bytes para el entero de rows
	cols:	 resd 1 		; 4 bytes para las columnas
	colsmed:	resd 1
	;img:	 resq 1 		; 8 bytes para el puntero a la imagen
	src:	resq 1
	dest:	resq 1
	indexSrc:	 resd 1 	; index origen
	indexDst:	 resd 1 	; index destino

segment .text

 main:
	cmp rdi, 3
	jne noargs

	mov rdx, qword [rsi + 8] ;Se recibe el path origen
	mov [src], rdx
	mov rdx, qword [rsi + 16] ;Se recibe el path destino
	mov [dest], rdx

	mov rdi, [src] 		;Se pasa el path origen como parámetro
	mov rax, 0
	call loadImage

	cmp rax, 0		;Verificar si la imagen se cargo
	je exit

	mov rax, 0
	call getRows
	
	mov [rows], rax

	mov rax, 0
	call getCols
	mov [cols], rax

	mov rax, 0
	call getData
	mov [data], rax

	mov rax, [cols]
	mov rdx, 0
	mov rdi, 2
	div rdi
	mov [colsmed], eax
	
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
	mov eax, dword [j]
	imul dword [channel]
	add eax, dword [k]
	mov [indexSrc], dword eax
	mov eax, dword [i]
	imul dword [cols]
	imul dword [channel]
	add eax, dword [indexSrc]
	mov [indexSrc], dword eax
	
	mov rax, 0
	mov rdi, [indexSrc]
	mov rsi, [indexDst]
	call copyPixels
	;mov rbx, [rax + indexSrc]
	
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
	mov ebx, dword [colsmed]
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

	mov rax,0
	mov rdi, [dest]
	call saveImage
	jmp exit
	
 noargs:
	mov rdi, emptyargs
	mov rax, 0
	call printf
	jmp exit
 exit:
	mov    rax, 60        	; sys_exit
	mov    rdi, 0        	; return 0 (success)
	syscall
	;mov eax, sys_exit
	;mov ebx, 0
	;int 80h
	