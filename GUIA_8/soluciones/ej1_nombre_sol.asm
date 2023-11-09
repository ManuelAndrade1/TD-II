section .data                  
  msg: DB 'Felisberto', 10
  msgV: DB 'F', 10, 'e', 10, 'l', 10, 'i', 10, 's', 10, 'b', 10, 'e', 10, 'r', 10, 't', 10, 'o', 10
  largo EQU $ - msg       
  enter: DB 10     
                               
global _start                
section .text

  _start:                

    call nombre

    mov rax, 1     ; funcion 1 
    mov rbx, 0     ; codigo    
    int 0x80                   

nombre:
  ; Impresión del nombre en horizontal.
  mov rax, 4     ; funcion 4: write
  mov rbx, 1     ; stdout
  mov rcx, msg   ; mensaje
  mov rdx, largo ; longitud
  int 0x80

  ; Impresión del nombre en vertical (Version 1)
  mov rcx, msg   ; mensaje
  mov rdi, 10    ; cantidad de letras del nombre

  loop:
  push rcx

  mov rax, 4     ; funcion 4: write
  mov rbx, 1     ; stdout
  mov rdx, 1     ; longitud
  int 0x80

  mov rax, 4     ; funcion 4: write
  mov rbx, 1     ; stdout
  mov rcx, enter ; mensaje (enter)
  mov rdx, 1     ; longitud
  int 0x80

  pop rcx
  inc rcx
  dec rdi
  JZ fin
  JMP loop

  ; Impresión del nombre en vertical (Version 2)
  mov rax, 4     ; funcion 4: write
  mov rbx, 1     ; stdout
  mov rcx, msgV  ; mensaje
  mov rdx, 1     ; longitud

  fin:
  ret

