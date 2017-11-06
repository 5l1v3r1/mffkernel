#!/bin/bash
rm *.o
nasm -f elf32 kernel.asm -o kasm.o
gcc -m32 -c kernel.c -o kc.o
ld -m elf_i386 -T kernel.ld -o kernel kasm.o kc.o
