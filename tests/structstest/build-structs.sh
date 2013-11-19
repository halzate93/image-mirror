#gcc testMat.c -o testMat.out //line to test the .c
nasm -f elf64 -l mirror.lst mirror.s
gcc -c testMat.c
gcc -g -o test.out mirror.o testMat.o
rm -f mirror.o mirror.lst testMat.o