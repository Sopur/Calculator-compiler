; ----------------------------------------------------------------------------------------
; About: Generated with CALCULATOR-COMPILER                                              |
; Author: Sopur (Someguy1834)                                                            |
; Warn: Runs on 64-bit Linux only.                                                       |
; ----------------------------------------------------------------------------------------
    SECTION .data
fmt:    db "Compiled output: %d", 10, 0
        SECTION .text
        extern printf
        global main, _start
main:
_start:
	mov	ebx, 2
	add	ebx, 2
	sub	ebx, 2
	mov	eax, 2
	mul	ebx
	mov	ebx, eax
	mov	edx, 0
	mov	eax, ebx
	mov	ecx, 2
	div	ecx
	mov	ebx, eax
        mov     eax, ebx
        mov     esi, eax
        mov     edi, fmt
        mov     eax, 0
        call    printf
        mov     ebx, 0
        mov     eax, 1
        int     0x80
; ----------------------------------------------------------------------------------------
; About: Generated with CALCULATOR-COMPILER                                              |
; Author: Sopur (Someguy1834)                                                            |
; Warn: Runs on 64-bit Linux only.                                                       |
; ----------------------------------------------------------------------------------------
