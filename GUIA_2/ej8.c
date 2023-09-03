#include <stdio.h>
#include <pthread.h>

int array[5];

void doSomething() {return;};

static void* doIt() {
    for(int i=0; i<5; i++) {
        array[i] = array[i] + 1;
        doSomething();
    }
}

int main() {
    pthread_t th1;
    pthread_t th2;
    pthread_t th3;

    pthread_create(&th1, 0, doIt, 0);
    pthread_create(&th2, 0, doIt, 0);
    pthread_create(&th3, 0, doIt, 0);
    
    pthread_join(th1,0);
    pthread_join(th2,0);
    pthread_join(th3,0);

    for(int i=0; i<5; i++) {
        printf("%i\n",array[i]);
    }
    return 0;
}

/*
a. El programa crea 3 threads que alteran la variable array, sumandole 1 al valor
contenido dentro de la posicion del array. Dos posibles resultados de esto podrian ser:
2, 2, 2, 2, 2 y 3, 3, 3, 3, 3. El primer ejemplo podria darse si, por ejemplo, se ejecuta el primer thread
actualizando los valores del array, pero mientras se ejecutan el segundo y el tercero, estos se pisan y 
no logran ver la variable actualizada por el otro, dado que no hay ningun tiempo de espera, ambos podrian estar
leyendo la variable array a la vez, sin ver la actualizada. Asi, en vez de llegar a 3, 3, 3, 3, 3, se llega
a 2, 2, 2, 2, 2,

c. Una posible solucion, podria realizarse implementando un semaforo o un lock en el que los threads
tengan que pasara alguna condicion antes de poder acceder y modificar los valores de la variable array.
*/ 