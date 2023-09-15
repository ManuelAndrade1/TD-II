#include <stdio.h>
#include <stdlib.h>

/*
En base a la estructura de datos creada, realizar la funcion pedida
de modo que cumpla con la especificacion dada.

AYUDITA: Si ya al filo con el tema, enfocate princiipalmente en:
    - removeNodes()
    - lastToFirst()

Dificultad de funciones:
"Facil": average - findValue
"Medio": removeNode - firstToLast
"Dificil": removeNodes - lastToFirst
*/

struct node {
    struct node* next;
    int value;
};

struct list {
    struct node* first;
};

void addLast(struct list* ls, int v) {
    // Agrega un nodo al final de la lista
    struct node* new = (struct node*) malloc(sizeof(struct node));
    new->next = 0; // No apunta a nadie dado que es el ultimo
    new->value = v;

    if (ls->first == 0) { // Caso base: Lista vacia
        ls->first = new;
        return;
    }
    struct node* curr = ls->first;
    while (curr->next != 0) {
        curr = curr->next;
    }
    // Al salir del ciclo, curr es un puntero al ultimo nodo de la lista
    curr->next = new; // Agrego el ultimo al final
    return;
}
void deleteList(struct list* ls) {
    // Borra la lista - Libera la memoria
    if (ls->first == 0) return;
    struct node* curr = ls->first;
    while (curr != 0) { // Uso solo curr porque quiero iterar hasta el ultimo INCLUSIVE
        struct node* tmp = curr;
        curr = curr->next;
        free(tmp);
    }
    free(ls);
    return;
}
void printList(struct list* ls) {
    if (ls->first == 0) return;

    printf("[ ");
    struct node* curr = ls->first;
    while(curr != 0) {
        printf("%i ", curr->value);
        curr = curr->next;
    }
    printf("]\n");
    return;
}
float average(struct list* ls) {
    // COMPLETAR
    /*
    Parametros: puntero a lista
    La funcion debe devolver el promedio de la suma de los nodos de la lista.
    */
   return 0;
}

struct node* findValue(struct list* ls, int v) {
    // COMPLETAR
    /*
    Parametros: puntero a lista y entero "v" a hallar.
    devuelve un puntero al primer nodo encontrado que tenga el valor
    pasado como parametro. Devuelve 0 si no existe ese valor.
    */
   return 0;
}

void removeNode(struct list* ls, int v) {
    // COMPLETAR
    /*
    Parametros: puntero a lista y entero "v".
    La funcion debe ELIMINAR (borrar de la lista y liberar memoria) el primer nodo
    que coincida con el valor pasado como parametro. Si ninguno coincide, la lista queda igual.
    */
}

void removeNodes(struct list* ls, int v) {
    // COMPLETAR
    /*
    Parametros: puntero a lista y entero "v".
    La funcion debe ELIMINAR (borrar de la lista y liberar memoria) TODOS los nodos
    cuyo valor coinida con el entero pasado como parametro. Si ninguno coincide, la
    lista queda igual. 
    */
   return;
}

void firstToLast(struct list* ls) {
    // COMPLETAR
    /*
    Parametros: puntero a lista
    La funcion debe "mover" el primer nodo de la lista al final de la lista.
    Si la lista esta vacia, o si la lista contiene un solo nodo no debe hacer nada.
    */
   return;
}

void lastToFirst(struct list* ls) {
    // COMPLETAR
    /*
    Parametros: puntero a lista
    La funcion debe "mover" el ultimo nodo de la lista al principio de la lista.
    Si la lista esta vacia, o si la lista contiene un solo nodo no debe hacer nada.
    */
   return;
}

int main() {
    struct list* ls = (struct list*) malloc(sizeof(struct list));
    ls->first = 0;
    for (int i = 0; i < 12; i++) {
        addLast(ls, i);
    }
    printList(ls);
    deleteList(ls);
    return 0;
}