section .data
  arreglo:  dd 1, -2, 3, 0, -9, 2, 4, 2, 1, 9
  len: EQU $ -arreglo
  objetivo: dd 5
  true: db 'Verdadero', 10
  len_true: EQU $ -true
  false: db 'Falso', 10
  len_false: EQU $ -false
                               
global _start
section .text

  _start:                

    ; En la etiqueta arreglo se encuentran los numeros a sumar y comparar
    ; en Objetivo se encuentra el numero que deben sumar en el caso que exista.

    call sumarObjetivo

    ; Exit
    mov rax, 1     ; funcion 1 
    mov rbx, 0     ; codigo    
    int 0x80                   

sumarObjetivo:
    push rax
    push rbx
    push rcx
    push rdx
    push rdi

    mov rcx, arreglo
    mov rbx, len
    
    loop:
      mov rdx, rcx
      mov rdi, rbx

      nestedLoop:
        add rdx, 4
        sub rdi, 4
        cmp rdi, 0
        jz endNested
        mov eax, [rcx]
        add eax, [edx]
        cmp eax, [objetivo]
        jz verdadero
        ;push rdi
        ;mov rdi, rax
        ;call printHex
        ;pop rdi
        jmp nestedLoop

      endNested: 
      add rcx, 4
      sub rbx, 4
      jnz loop
      jmp falso

    return:
      pop rdi
      pop rdx
      pop rcx
      pop rbx
      pop rax
      ret

verdadero:
  mov rax, 4
  mov rbx, 1
  mov rcx, true
  mov rdx, len_true
  int 0x80
  jmp return

falso:
  mov rax, 4
  mov rbx, 1
  mov rcx, false
  mov rdx, len_false
  int 0x80
  jmp return


