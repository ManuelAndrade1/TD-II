section .data
  arreglo: dd -2, -3, 4, -5, 6
                               
global _start
section .text

  _start:                

    ; En la etiqueta arreglo se encuentran los 10 numeros a sumar.
    ; dejar el resultado en eax

    mov rsi, arreglo
    mov edi, 5
    mov ecx, 0
    call sumNotIf
    mov rdi, rax ; paso como parametro rax como rdi
    call printHex

    mov rsi, arreglo
    mov edi, 5
    call sumSorted
    mov rdi, rax ; paso como parametro rax como rdi
    call printHex

    ; Exit
    mov rax, 1     ; funcion 1 
    mov rbx, 0     ; codigo    
    int 0x80                   

sumNotIf:
  push rsi
  push rdi
  mov eax, 0
  loop:
    cmp ecx, [rsi]
    jz next
    add eax, [rsi]
  next:
    add rsi, 4
    dec edi
    cmp edi, 0
    jnz loop
  pop rdi
  pop rsi
  ret
  
sumSorted:
  push rsi
  push rdi
  push rbx
  mov eax, [rsi]
  mov ebx, [rsi]
  loop2:
    cmp ebx, [rsi]
    jge next2
    add eax, [esi]
  next2:
    add rsi, 4
    dec edi
    cmp edi, 0
    jnz loop2
  pop rbx
  pop rdi
  pop rsi
  ret
  
  
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
