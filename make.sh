#!/bin/bash
set -x
rm *.o
nasm -f elf32 a20.asm -o a20.o
nasm -f elf32 kernel.asm -o kasm.o
nasm -f elf32 ints.asm -o ints.o
gcc -m32 -c kernel.c -o kc.o
gcc -m32 -c tty.c -o tty.o
ld -m elf_i386 -T kernel.ld -o kernel kasm.o ints.o a20.o kc.o tty.o
objdump -x kernel
