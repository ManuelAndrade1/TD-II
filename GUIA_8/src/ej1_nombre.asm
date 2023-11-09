section .data                  
  msg: DB 'MiNombre', 10     
  largo EQU $ - msg            
                               
global _start                
section .text

  _start:                

    call nombre

    mov rax, 1     ; funcion 1 
    mov rbx, 0     ; codigo    
    int 0x80                   

nombre:
  ; COMPLETAR
ret
