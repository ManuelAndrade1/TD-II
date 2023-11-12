; Respuesta inciso b:
; Se deberia cambiar simplemente el condicional JA a JG
section .data
  arreglo: dw 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1
                               
global _start
section .text

  _start:                

    ; En la etiqueta arreglo se encuentran los 16 numeros a comparar.
    ; dejar el resultado en eax

    call mayor

    ; Imprimo el valor en rax
    mov rdi, rax ; paso como parametro rax como rdi
    call printHex

    ; Exit
    mov rax, 1     ; funcion 1 
    mov rbx, 0     ; codigo    
    int 0x80

mayor:
  push rbx
  push rcx
  push rdx

  mov rbx, 16
  mov rcx, arreglo
  mov ax, [rcx]
  loop:
    cmp [rcx], ax
    ja modif ; salta si [rcx] es mayor a ax
    continue:
    add rcx, 2
    dec rbx
    jz return
    jmp loop

  return:
    pop rdx
    pop rcx
    pop rbx
    ret

modif: 
  mov ax, [rcx]
  jmp continue

; ---------------------------------------------
; printHex toma como parametro un valor en rdi
; e imprime dicho valor en hexadecimal
; ---------------------------------------------

printHex:
  push rbx
  push r12
  push r13
  push r14
  push r15
  push rbp
  mov rcx, 15
  mov rbx, hexachars
  .ciclo:
    mov rax, rdi
    and rax, 0xF
    mov dl, [rbx+rax]
    mov [number+rcx], dl
    dec rcx
    shr rdi, 4
    cmp rcx, -1
    jnz .ciclo
  mov rax, 4      ; funcion 4
  mov rbx, 1      ; stdout
  mov rcx, number ; mensaje
  mov rdx, 17     ; longitud
  int 0x80
  pop rbp
  pop r15
  pop r14
  pop r13
  pop r12
  pop rbx
ret

section .rodata
  hexachars: db "0123456789ABCDEF"

section .data
  number:    db "0000000000000000",10
