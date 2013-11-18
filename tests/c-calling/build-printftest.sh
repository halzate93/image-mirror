nasm -f elf64 -l printftest.lst printftest.s
gcc -g -nostartfiles -o printftest.out printftest.o
rm -f printftest.o printftest.lst