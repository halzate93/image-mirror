global _start

segment .data
	image times 10 times 10 db 255, 255, 255 ; white pixels 10x10 matrix
	rowsize equ 30	; 10 pixels with 3 bytes each one
	pixelsize equ 3	; 3 bytes per pixel, one for each RGB component
	i db 0
	j db 0
	k db 0
_start:
	jmp rowloop
rowloop:
	jmp pixelloop
pixelloop:
	jmp rgbloop
rgbloop:
	;; copy value
	jmp endrgbloop
endrgbloop:
	inc byte [k]
	cmp byte [k],3
	jne rgbloop
	mov byte [k],0
	jmp endpixelloop
endpixelloop:
	inc byte [j]
	cmp byte [j],10
	jne pixelloop
	mov byte [j],0
	jmp endrowloop
endrowloop:
	inc byte [i]
	cmp byte [i],10
	jne rowloop
	jmp _exit
_exit:
	mov eax, 1	;sysExit
	mov ebx, 0
	int 80h
