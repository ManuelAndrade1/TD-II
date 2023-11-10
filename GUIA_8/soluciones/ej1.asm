section .data
nombre2: DB 'Pepe'
enter: DB 10
nombre: DB 'Pepe', 10
largo: EQU $ -nombre

global _start
section .text

_start:
    call nombre_simple

    mov rax, 1
    mov rbx, 0
    int 0x80


nombre_simple:
    push rax 
    push rbx
    push rcx
    push rdx

    mov rax, 4
    mov rbx, 1
    mov rcx, nombre
    mov rdx, largo
    int 0x80

    pop rdx
    pop rcx
    pop rbx
    pop rax
    ret

nombre_enter:
    push rax
    push rbx
    push rcx
    push rdx
    push rsi

    mov rcx, nombre
    mov rsi, 8

    loop:
        push rcx
        mov rax, 4
        mov rbx, 1
        mov rdx, 1
        int 0x80

        mov rax, 4
        mov rbx, 1
        mov rcx, enter
        mov rdx, 1
        int 0x80

        pop rcx
        inc rcx
        dec rsi
        jz return
        jmp loop
    return:
        pop rsi
        pop rdx
        pop rcx
        pop rbx
        pop rax

        ret

    

    
