section .data                  
  msg: DB 'Pepe', 10     
  largo EQU $ - msg
  msg2: DB 'P', 10, 'e', 10, 'p', 10, 'e', 10 
  largo2: EQU $ - msg2          
                               
global _start                
section .text

  _start:                

    call nombre
    call nombre_enter
    mov rax, 1     ; funcion 1 
    mov rbx, 0     ; codigo    
    int 0x80                   

nombre:
  mov rax, 4
  mov rbx, 1
  mov rcx, msg
  mov rdx, largo
  int 0x80
  ret

nombre_enter:
  mov rax, 4
  mov rbx, 1
  mov rcx, msg2
  mov rdx, largo2
  int 0x80
  ret
