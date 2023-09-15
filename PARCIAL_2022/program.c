#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node* next;
    int* data;
    int len;
};

struct list {
    struct node* first;
    int size;
};


void addLast(struct list* ls, int* arr, int len) {
    struct node* new = (struct node*) malloc(sizeof(struct node));
    new->len = len;
    new->data = (int*) malloc(sizeof(int)*len);
    for (int i = 0; i < len; i++) {
        new->data[i] = arr[i];
    }
    new->next = 0;
    struct node* first = ls->first;
    if (!first) {
        ls->first = new;
        return;
    } 
    struct node* curr = first;
    while(curr->next != 0) {
        curr = curr->next;
    }
    curr->next = new;
    return;
}
void printList(struct list* ls) {
    struct node* first = ls->first;
    if (!first) return;
    struct node* curr = first;
    while (curr != 0) {
        printf("[ ");
        for (int i = 0; i < curr->len; i++) {
            printf("%i - ", curr->data[i]);
        }
        printf("]\n");
        curr = curr->next;
    }
    return;
}
int main () {
    struct list* my_list;
    int a[3] = {1, 2, 3};
    int b[2] = {3, 6};
    int c[4] = {10, 11, 22, 4};
    addLast(my_list, a, 3);
    addLast(my_list, b, 2);
    addLast(my_list, c, 4);
    printList(my_list);
}