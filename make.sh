#!/bin/bash
set -x

BUILD=build
mkdir $BUILD
rm $BUILD/*.o

nasm -f elf32 a20.asm -o $BUILD/a20.o
nasm -f elf32 kernel.asm -o $BUILD/kasm.o
nasm -f elf32 ints.asm -o $BUILD/ints.o
gcc -m32 -c kernel.c -o $BUILD/kc.o
gcc -m32 -c tty.c -o $BUILD/tty.o
ld -m elf_i386 -T kernel.ld -o $BUILD/kernel $BUILD/kasm.o $BUILD/ints.o $BUILD/a20.o $BUILD/kc.o $BUILD/tty.o
objdump -x $BUILD/kernel
