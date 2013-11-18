nasm -f elf64 -l mirror.lst mirror.s
g++ -c matTest.cpp
g++ -g -nostartfiles -o mirror mirror.o matTest.o
rm -f mirror.o mirror.lst matTest.o