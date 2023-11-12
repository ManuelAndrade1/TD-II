
global _start
section .text

  _start:                

    mov esi, 0xFF0081A1
    mov edi, 0x00ABBA0F
    call mergeLow1
    mov rdi, rax ; paso como parametro rax como rdi
    call printHex

    mov esi, 0xFF0081A1
    mov edi, 0x00ABBA0F
    call mergeLow2
    mov rdi, rax ; paso como parametro rax como rdi
    call printHex

  exit:
    ; Exit
    mov rax, 1     ; funcion 1 
    mov rbx, 0     ; codigo    
    int 0x80                   

mergeLow1:
  push rbx
  push rcx
  push rdx
  push rsi
  push rdi
  push rbp

  mov ebx, 0xFF000000
  mov ecx, 0x00FF0000
  mov edx, 0x0000FF00
  mov ebp, 0x000000FF

  push rsi
  shl rsi, 16
  and esi, ebx
  mov eax, esi
  pop rsi
  push rdi
  shl rdi, 8
  and edi, ecx
  add eax, edi
  pop rdi
  push rsi
  shl rsi, 8
  and esi, edx
  add eax, esi
  pop rsi
  push rdi
  and edi, ebp
  add eax, edi
  pop rdi

  pop rbp
  pop rdi
  pop rsi
  pop rdx
  pop rcx
  pop rbx
  ret

mergeLow2:
  push rbx
  push rcx

  mov ebx, 0xFFFF0000
  mov ecx, 0x0000FFFF
  mov rax, 0

  push rsi
  shl rsi, 16
  and esi, ebx
  mov eax, esi
  pop rsi
  push rdi
  and edi, ecx
  add eax, edi
  pop rdi
  
  pop rcx
  pop rbx
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
