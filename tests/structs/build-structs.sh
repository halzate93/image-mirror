nasm -f elf64 -l mirror.lst mirror.s
gcc -c matTest.cpp
ar rcs libmatTest.a matTest.o
gcc -g -o mirror mirror.o libmatTest.a
rm -f mirror.o mirror.lst matTest.o libmatTest.a