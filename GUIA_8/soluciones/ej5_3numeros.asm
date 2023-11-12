section .data
  numero1: db 10
  numero2: dw -9
  numero3: dd 120
  mezcla: db 'Hay positivos y negativos', 10
  len_mezcla: EQU $ -mezcla
  neg: db 'Son todos negativos', 10
  len_neg: EQU $ -neg
  pos: db 'Son todos positivos', 10
  len_pos: EQU $ -pos
                               
global _start
section .text

  _start:                

    ; En las etiquetas numero1, numero2 y numero3 se encuentran los tres numeros a comparar

    call tresNumeros

    ; Exit
    mov rax, 1     ; funcion 1 
    mov rbx, 0     ; codigo    
    int 0x80                   

tresNumeros:
  push rax
  push rbx
  push rcx
  push rdx
  push rsi

  mov rsi, 0
  mov rax, 0
  cmp [numero1], al
  js sum1
  cont1: cmp [numero2], ax
  js sum2
  cont2: cmp [numero2], eax
  js sum3
  cont3:
  cmp rsi, 3
  jz negativos
  cmp rsi, 0
  jz positivos
  
  mov rax, 4
  mov rbx, 1
  mov rcx, mezcla
  mov rdx, len_mezcla
  int 0x80

  return:
    pop rsi
    pop rdx
    pop rcx
    pop rbx
    pop rax
    ret

sum1:
    inc rsi
    jmp cont1
sum2:
    inc rsi
    jmp cont2
sum3:
    inc rsi
    jmp cont3

negativos:
  mov rax, 4
  mov rbx, 1
  mov rcx, neg
  mov rdx, len_neg
  int 0x80
  jmp return

positivos:
  mov rax, 4
  mov rbx, 1
  mov rcx, pos
  mov rdx, len_pos
  int 0x80
  jmp return