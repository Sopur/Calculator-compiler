# Linux only because fuck you
nasm -f elf64 -o ./out/calc.o ./inputs/input.calc.asm &&
ld ./out/calc.o -o ./out/calc -lc --dynamic-linker /lib/ld-linux-x86-64.so.2
