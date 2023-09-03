#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>


// int main() {
// fork();
// printf("Aqui hay eco.\n");
// return 0;
// }

/*
a. El siguiente programa ejecuta la sys call fork, creando un nuevo
proceso hijo que corre el codigo del programa a partir de la linea 8
Como tanto el padre y el hijo corren lo mismo, se printea en la consola
dos veces el string "Aqui hay eco".
*/

// int main() {
// fork();
// fork();
// fork();
// printf("TD2.\n");
// return 0;
// }
/*
b. TD2 se va a printear 8 veces. El programa ejecuta un fork() creando
un segundo proceso. Inmediatamente despues, tanto el proceso original como
el nuevo crean un proceso hijo. Asi, luego del segundo fork tenemos: 
padre, hijo, padre->hijo, padre->hijo->hijo. LUego, en el tercer fork, se crea
un proceso hijo para cada uno de los procesos existentes, creando asi un total
de 8 procesos que ejecutan la linea printf("TD\n");
*/

int main() {
    int data = 0;
    pid_t pid = fork();

    if (pid == 0) {
        data++;
        printf("Valor de data del hijo: %d\n", data);
    } 
    else if (pid > 0) {
        srand(time(0)); // Init Random Seed
        sleep(rand()%2); // Wait for random time
        printf("Valor de data del padre: %d\n", data);
    }
    return 0;
}

/*
c. El programa ejecuta un fork() y guarda el pid
del proceso en una variable llamada pid. Si la variable
contiene el valor 0, es decir, se trata del proceso hijo, 
se actualiza el valor de la variable data en 1 y se ejecuta el printf
dentro del primer if.
En caso de que pid sea mayor a 0, se mete en el else if y ejecuta el codigo
que hay ahi dentro.
*/