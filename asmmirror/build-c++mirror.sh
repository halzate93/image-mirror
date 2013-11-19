nasm -f elf64 -l mirror.lst mirror.s
g++ -c test.cpp
g++ -g -o mirror.out mirror.o test.o `pkg-config --cflags --libs opencv`
rm mirror.o test.o mirror.lst