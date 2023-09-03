#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int array[20];

// static void* fillArray(void* arg) {
//     for(int i=10; i<20; i++) {
//         array[i] = i+1;
//     }   
//     return 0;
// }


// int main() {
//     pthread_t thread;
//     pthread_create(&thread, NULL, fillArray, NULL);
//     for(int i=0; i<10; i++) {
//         array[i] = i+1;
//     }
    
//     pthread_join(thread, NULL);

//     for(int i=0; i<20; i++) {
//         printf("%i\n", array[i]);
//     }
//     return 0;
// }

/*
a. El programa crea un thread a traves de la llamada a la funcion
pthread_crate. En esta, se le especifica al thread creado que ejecute la funcion
pasada como parametro. El thread creado itera sobre la variable array desde la posicion
10 a la posicion 19, llenando los valores segun las instrucciones dadas. A su vez, el proceso padre
(segundo thread), itera a traves de la variabale array desde la posicion 0 a la 9, llenando los valores
segun las instrucciones dadas. Luego, a traves de la llamada a pthread_join(), se juntan los threads en un
mismo thread, y se termina por printear los valores del arreglo.
*/


static void* fillArray1(void* arg) {
    for (int i=5; i<10; i++) {
        array[i] = i+1; 
    }
    return 0;
}

static void* fillArray2(void* arg) {
    for (int i=10; i<15; i++) {
        array[i] = i+1; 
    }
    return 0;
}

static void* fillArray3(void* arg) {
    for (int i=15; i<20; i++) {
        array[i] = i+1; 
    }
    return 0;
}


int main() {
    pthread_t thread, thread2, thread3;
    pthread_create(&thread, NULL, fillArray1, NULL);
    pthread_create(&thread2, NULL, fillArray2, NULL);
    pthread_create(&thread3, NULL, fillArray3, NULL);

    for(int i=0; i<5; i++) {
        array[i] = i+1;
    }
    
    pthread_join(thread, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);

    for(int i=0; i<20; i++) {
        printf("%i\n", array[i]);
    }
    return 0;
}

/*
c. Si usaramos fork() y wait(), los valores del array no se llenarian dado
que fork crea una copia del proceso padre en un espacio distinto ed memoria. Por ende, 
los valores que llenen los hijos no se verian reflejados/actualizados en el proceso original.
*/

/*
d. Las variables i y j se encuentran en el stack, son dependientes de la "vida util" de sus funciones
cuando terminan de ejecutarse dichas funciones, i y j dejan de existir. Por otro lado, array forma parte
de los datos del programa. Es una variable global, por ende "todos" pueden acceder a ella. En el proceso de 4
thread existen 4 instancias de i, una por cada thread.
*/