#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* addLast(struct node* n, int data) {

    struct node* new = (struct node*) malloc(sizeof(struct node));
    new->data = data;
    new->next = 0;
    if (n == 0) {
        n = new;
    }
    else {
        struct node* temp = n;
        while (temp->next != 0) {
            temp = temp->next;
        }
        temp->next = new;
    }
    return n;
}

struct node* removeFirst(struct node* n) {

    struct node* temp = n;
    if (temp->next == 0) {
        free(n);
        return 0;
    }
    n = n->next;
    free(temp);
    return n;
}

struct node* join(struct node* n1, struct node* n2) {

    struct node* temp = n1;
    while (temp->next != 0) {
        temp = temp->next;
    }
    temp->next = n2;
    return n1;
}

struct node* removeData(struct node* n, int data) {
    struct node* prev = n;
    struct node* curr = n;
    struct node* next = n->next;
    int running = 1;
    while (running) {
        next = curr->next;
        if (curr->data == data) {
            if (curr == n) {
                n = next;
                free(curr);
                curr = next;
            } 
            else {
                free(curr);
                prev->next = next;
                curr = next;
            }
        }
        else {
            prev = curr;
            curr = next;
            }
        if (curr == 0) {running = 0;}
        

    }
    return n;

}

void printList(struct node* n) {
    printf("[");
    if(n == 0){
        printf("]\n");
    } else {
        while(n->next != 0){
            printf("%i, ", n->data);
            n = n->next;
        }
        printf("%i]\n", n->data);
    }
}

int main() {
    // -- Descomentar para probar --
    // Lo siguiente es un ejemplo y DEBE ser modificado.

    struct node *n1 = NULL;
    printList(n1);
    printf("\n");

    printf("Agrego datos a la lista: n1\n");
    n1 = addLast(n1, 2021);
    n1 = addLast(n1, 42);
    n1 = addLast(n1, 0x400);
    printList(n1);
    printf("\n");

    printf("Agrego datos a la lista: n2\n");
    struct node *n2 = NULL;
    n2 = addLast(n2, 0);
    n2 = addLast(n2, 42);
    printList(n2);
    printf("\n");
    
    printf("Join lista n1 y n2: n3\n");
    struct node *n3 = join(n1, n2);
    printList(n3);
    printf("\n");

    printf("RemoveFirst: n3\n");
    n3 = removeFirst(n3);
    printList(n3);
    printf("\n");
    
    printf("RemoveData: 42\n");
    n3 = removeData(n3, 42);
    printList(n3);
    printf("\n");
    
    printf("RemoveFirst dos veces: n3\n");
    n3 = removeFirst(n3);
    n3 = removeFirst(n3);
    printList(n3);
    printf("\n");


    return 0;
}
