section .data
  arreglo: dd -10, 2, -8, -7, -1, -1, -9, 2, 4, 12
  positivo: db 'Positivo', 10
  largo_pos: EQU $ -positivo
  negativo: db 'Negativo', 10
  largo_neg: EQU $ -negativo
                               
global _start
section .text

  _start:                

    ; En la etiqueta arreglo se encuentran los 10 numeros a sumar.
    ; dejar el resultado en eax

    call sumarArreglo

    ; Exit
    mov rax, 1     ; funcion 1 
    mov rbx, 0     ; codigo    
    int 0x80                   

sumarArreglo:
  push rbx
  push rcx
  push rdx
  push rdi
  mov rax, 0x0000000000000000 ; sum variable
  mov rbx, 10 ; counter
  mov rcx, arreglo
  
  ciclo: 
    add eax, [rcx]
    add rcx, 4
    dec rbx
    jz decide
    jmp ciclo

  decide:
    cmp eax, 0
    js esNegativo
    
    mov rax, 4
    mov rbx, 1
    mov rcx, positivo
    mov rdx, largo_pos
    int 0x80

  callback:
    pop rdi
    pop rdx
    pop rcx
    pop rbx
    ret
  
  esNegativo:
    mov rax, 4
    mov rbx, 1
    mov rcx, negativo
    mov rdx, largo_neg
    int 0x80
    jmp callback