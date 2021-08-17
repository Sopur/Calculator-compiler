        mov     eax, ebx
        mov     esi, eax
        mov     edi, fmt
        mov     eax, 0
        call    printf
        mov     ebx, 0
        mov     eax, 1
        int     0x80
