    SECTION .data
fmt:    db "Compiled output: %d", 10, 0
        SECTION .text
        extern printf
        global main, _start
main:
_start: