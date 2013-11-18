nasm -f elf64 -l mirror.lst mirror.asm
ld -m elf_x86_64 mirror.o -o mirror
rm -f mirror.o mirror.lst