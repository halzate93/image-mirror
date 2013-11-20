nasm -f elf64 -l mirror.lst mirror.s
g++ -c imagemirror.cpp
g++ -g -o mirror.out mirror.o imagemirror.o `pkg-config --cflags --libs opencv`
rm mirror.o imagemirror.o mirror.lst