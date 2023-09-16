#include <stdio.h>
#include <stdlib.h>

/*
En base a la estructura de datos creada, realizar la funcion pedida
de modo que cumpla con la especificacion dada.

AYUDITA: Si ya al filo con el tema, enfocate princiipalmente en:
    - removeNodes()
    - lastToFirst()

Dificultad de funciones:
"Facil": findValue
"Medio": removeNode - firstToLast
"Dificil": removeNodes - lastToFirst
*/

struct node {
    struct node* next;
    int value;
};

struct list {
    struct node* first;
    int size;
};

void addLast(struct list* ls, int v);
void deleteList(struct list* ls);
void printList(struct list* ls);
struct list** createLists();
struct list** createListsBis();
void deleteTest(struct list** ls);
int compareLists(struct list* ls, int* arr, int len);
struct node* iterList(struct list* ls, int max);
void testFindValue(struct list** ls);

struct node* findValue(struct list* ls, int v) {
    // COMPLETAR
    /*
    Parametros: puntero a lista y entero "v" a hallar.
    devuelve un puntero al primer nodo encontrado que tenga el valor
    pasado como parametro. Devuelve 0 si no existe ese valor.
    */
   struct node* curr = ls->first;
   while (curr != 0) {
    if (curr->value == v) return curr;
    curr = curr->next; 
   }
   return 0;
}

void removeNode(struct list* ls, int v) {
    // COMPLETAR
    /*
    Parametros: puntero a lista y entero "v".
    La funcion debe ELIMINAR (borrar de la lista y liberar memoria) el primer nodo
    que coincida con el valor pasado como parametro. Si ninguno coincide, la lista queda igual.
    */
   if (ls->first == 0) return;
   if (ls->first->value == v) {
    struct node* aux = ls->first;
    ls->first = aux->next;
    free(aux);
    ls->size--;
    return;
   }
   struct node* prev = ls->first;
   struct node* curr = ls->first->next;
   while (curr != 0) {
    if (curr->value == v) {
        struct node* aux = curr;
        curr = curr->next;
        prev->next = curr;
        free(aux);
        ls->size--;
        return;
    }
    prev = curr;
    curr = curr->next;
   }
   return;
}

void removeNodes(struct list* ls, int v) {
    // COMPLETAR
    /*
    Parametros: puntero a lista y entero "v".
    La funcion debe ELIMINAR (borrar de la lista y liberar memoria) TODOS los nodos
    cuyo valor coinida con el entero pasado como parametro. Si ninguno coincide, la
    lista queda igual. 
    */
   if (ls->first == 0) return;
   struct node* prev = ls->first;
   struct node* curr = ls->first->next;
   while (curr != 0) {
    if (curr->value == v) {
        struct node* aux = curr;
        curr = curr->next;
        prev->next = curr;
        free(aux);
        ls->size--;
    }
    else {
        prev = curr;
        curr = curr->next;
    }
   }
   if (ls->first->value == v) {
    struct node* aux = ls->first;
    ls->first = aux->next;
    free(aux);
    ls->size--;
   }
   return;
}

void firstToLast(struct list* ls) {
    // COMPLETAR
    /*
    Parametros: puntero a lista
    La funcion debe "mover" el primer nodo de la lista al final de la lista.
    Si la lista esta vacia, o si la lista contiene un solo nodo no debe hacer nada.
    */
   if (ls->first == 0 || ls->size == 1) return;
    struct node* first = ls->first;
    struct node* curr = first;
    ls->first = first->next;
   while (curr->next != 0) curr = curr->next;
   curr->next = first;
   first->next = 0;  
   return;
}

void lastToFirst(struct list* ls) {
    // COMPLETAR
    /*
    Parametros: puntero a lista
    La funcion debe "mover" el ultimo nodo de la lista al principio de la lista.
    Si la lista esta vacia, o si la lista contiene un solo nodo no debe hacer nada.
    */
    if (ls->first == 0 || ls->size == 1) return;
    struct node* curr = ls->first->next;
    struct node* prev = ls->first;
    while (curr->next != 0) {
        prev = curr;
        curr = curr->next;
    }
    prev->next = 0;
    curr->next = ls->first;
    ls->first = curr;
    return;
}

int main() {
    struct list** ls;
    ls = createLists();
    printf("First samples:\n");
    printList(ls[0]);
    printList(ls[1]);
    printList(ls[2]);
    printList(ls[3]);
    printf("\n\n");   
    deleteTest(ls);
    ls = createListsBis(ls);
    printf("Second samples:\n");
    printList(ls[0]);
    printList(ls[1]);
    printList(ls[2]);
    printList(ls[3]); 
    printf("\n\n");
    deleteTest(ls);

    // TEST findValue
    ls = createLists();
    printf("Testing findValue()...\n\n");
    testFindValue(ls);
    deleteTest(ls);

    // TEST removeNode
    ls = createLists();
    printf("Testing removeNode()...\n\n");
    removeNode(ls[0], 2);
    removeNode(ls[1], 1);
    removeNode(ls[2], 5);
    removeNode(ls[3], 4);
    int data[5] = {1, 2, 3, 2, 5};
    int data2[5] = {3, 3, 3, 3, 5};
    int data3[5] = {0, 1, 4, 3, 16};
    int data4[6] = {1, 1, 1, 1, 1, 1};
    int test_res[4] = {compareLists(ls[0], data, 5), compareLists(ls[1], data2, 5), 
                        compareLists(ls[2], data3, 5), compareLists(ls[3], data4, 6)};
    for (int i = 0; i < 3; i++) {
        if (test_res[i]) printf("Test successful!\n");
        else printf("Test failed!\n"); 
    }
    printf("\n\n");
    deleteTest(ls);

    // TEST removeNodes
    ls = createLists();
    printf("Testing removeNodes()...\n\n");
    removeNodes(ls[0], 2);
    removeNodes(ls[1], 3);
    removeNodes(ls[2], 16);
    removeNodes(ls[3], 1);
    int n_data[3] = {1, 3, 5};
    int n_data2[2] = {1, 5};
    int n_data3[5] = {0, 1, 4, 3, 5};
    int n_data4[0] = {};
    int n_test_res[4] = {compareLists(ls[0], n_data, 3), compareLists(ls[1], n_data2, 2), 
                        compareLists(ls[2], n_data3, 5), compareLists(ls[3], n_data4, 0)};
    for (int i = 0; i < 3; i++) {
        if (n_test_res[i]) printf("Test successful!\n");
        else printf("Test failed!\n"); 
    }
    printf("\n\n");
    deleteTest(ls);

    // TEST firstToLast
    ls = createListsBis();
    printf("Testing firstToLast()...\n\n");
    firstToLast(ls[0]);
    firstToLast(ls[1]);
    firstToLast(ls[2]);
    firstToLast(ls[3]);
    int f_data[1] = {1};
    int f_data2[2] = {4, 3};
    int f_data3[8] = {2, 3, 4, 5, 6, 7, 8, 1};
    int f_data4[0] = {};
    int f_test_res[4] = {compareLists(ls[0], f_data, 1), compareLists(ls[1], f_data2, 2), 
                        compareLists(ls[2], f_data3, 8), compareLists(ls[3], f_data4, 0)};
    for (int i = 0; i < 3; i++) {
        if (f_test_res[i]) printf("Test successful!\n");
        else printf("Test failed!\n"); 
    }
    printf("\n\n");
    deleteTest(ls);

    // TEST lastToFirst
    ls = createListsBis();   
    printf("Testing lastToFirst()...\n\n");
    lastToFirst(ls[0]);
    lastToFirst(ls[1]);
    lastToFirst(ls[2]);
    lastToFirst(ls[3]);
    int l_data[1] = {1};
    int l_data2[2] = {4, 3};
    int l_data3[8] = {8, 1, 2, 3, 4, 5, 6, 7};
    int l_data4[0] = {};
    int l_test_res[4] = {compareLists(ls[0], l_data, 1), compareLists(ls[1], l_data2, 2), 
                        compareLists(ls[2], l_data3, 8), compareLists(ls[3], l_data4, 0)};
    for (int i = 0; i < 3; i++) {
        if (l_test_res[i]) printf("Test successful!\n");
        else printf("Test failed!\n"); 
    }
    printf("\n\n");
    deleteTest(ls);
    return 0;
}


void addLast(struct list* ls, int v) {
    // Agrega un nodo al final de la lista
    struct node* new = (struct node*) malloc(sizeof(struct node));
    new->next = 0; // No apunta a nadie dado que es el ultimo
    new->value = v;
    ls->size++; // Actualizo size de la lista

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
    if (ls->first == 0) {
        printf("[ ]\n");
        return;
    }

    printf("[ ");
    struct node* curr = ls->first;
    while(curr != 0) {
        printf("%i ", curr->value);
        curr = curr->next;
    }
    printf("]\n");
    return;
}

struct list** createLists() {
    // Crea 4 listas para testing
    struct list** lists = (struct list**) malloc(sizeof(struct list*) * 4);
    for (int i = 0; i < 4; i++) {
        lists[i] = (struct list*) malloc(sizeof(struct list));
        lists[i]->first = 0;
        lists[i]->size = 0;
    }

    for (int i = 0; i < 6; i++) {
        if (i % 2 == 0) {
            addLast(lists[0], 2);
            addLast(lists[1], 3);
            addLast(lists[2], i*i);
        }
        else {
            addLast(lists[0], i);
            addLast(lists[1], i);
            addLast(lists[2], i);
        }
        addLast(lists[3], 1);
    }
    return lists;
}

struct list** createListsBis() {
    // Creo 4 listas para firstToLast y lastToFirst
    struct list** lists = (struct list**) malloc(sizeof(struct list*) * 4);
    for (int i = 0; i < 4; i++) {
        lists[i] = (struct list*) malloc(sizeof(struct list));
        lists[i]->first = 0;
        lists[i]->size = 0;
    }

    addLast(lists[0], 1);
    addLast(lists[1], 3);
    addLast(lists[1], 4);
    for (int i = 0; i < 8; i++) addLast(lists[2], i+1);
    return lists;
}

void deleteTest(struct list** ls) {
    for (int i = 0; i < 4; i++) {
        deleteList(ls[i]);
    }
    free(ls);
}

int compareLists(struct list* ls, int* arr, int len) {
    // Devuelve 1 (true) si las listas son iguales, 0 (false) si las listas son diff.
    struct node* curr = ls->first; // Nodo que itera por toda la lista
    if (ls->size != len) return 0; // La lista no tiene el tamano deseado
    for (int i = 0; i < len; i++) {
        if (curr->value != arr[i]) return 0; // Los valores no coinciden
        curr = curr->next;
    }
    return 1; // Las listas son iguales
}

struct node* iterList(struct list* ls, int max) {
    struct node* curr = ls->first;
    for (int i = 0; i < max; i++){ 
        curr = curr->next;
    }
    return curr;
} 
void testFindValue(struct list** ls) {
    struct node** expected_res = (struct node**) malloc(sizeof(struct node*) * 4);
    expected_res[0] = iterList(ls[0], 5);
    expected_res[1] = iterList(ls[1], 1);
    expected_res[2] = iterList(ls[2], 4);
    expected_res[3] = iterList(ls[3], 0);

    int search_for[4] = {5, 1, 16, 1};
    for (int i = 0; i < 4; i++) {
        struct node* tmp = findValue(ls[i], search_for[i]);
        if (tmp == expected_res[i]) printf("Test successful!\n");
        else printf("Test failed!\n");
    }
    printf("\n\n");
    free(expected_res);
    return;
}