#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node {
    struct node* next;
    int* data;
    int len;
};

struct list {
    struct node* first;
    int size;
};

void addLast(struct list* list, int* arr, int len) {
    struct node* new = (struct node*) malloc(sizeof(struct node));
    new->next = 0;
    new->data = (int*) malloc(sizeof(int) * len);
    new->len = len;
    for (int i = 0; i < len; i++) {
        new->data[i] = arr[i];
    }
    if (list->first == 0) {
        list->first = new;
        return;
    }
    struct node* curr = list->first;
    while(curr->next != 0) {
        curr = curr->next;
    }
    curr->next = new;
    return;
}
void deleteList(struct list* list) {
    if (list->first == 0) {
        free(list);
        return;
    }
    struct node* curr = list->first;
    struct node* prev = list->first;
    while(curr != 0) {
        prev = curr;
        curr = curr->next;
        free(prev->data);
        free(prev);
    }
    free(list);
    return;
}
void printList(struct list* list) {
    if (list->first == 0) return;
    struct node* curr = list->first;
    while(curr != 0) {
        printf("[ ");
        for(int i = 0; i < curr->len; i++) {
            if (i == curr->len - 1) printf("%i ", curr->data[i]);
            else printf("%i - ", curr->data[i]);
        }
        printf("]\n");
        printf("\n\n");
        curr = curr->next;
    }
    return;
}
float average(struct node* n) {
    int count = 0;
    for (int i = 0; i < n->len; i++) {
        count += n->data[i];
    }
    float avg = (float) count / n->len;
    return avg;
}
void getGreatestAverageArray(struct list* list, int** data) {
    if (list->first == 0) {
        *data = 0;
        return;
    }
    struct node* curr = list->first;
    float avg = average(curr);
    *data = curr->data;
    while (curr != 0) {
        float avg_tmp = average(curr);
        if (avg_tmp > avg) {
            avg = avg_tmp;
            *data = curr->data;
        }
        curr = curr->next;
    }
    return;
}
void printArray(struct node* n) {
    printf("The array with largest average is: \n");
    for (int i = 0; i < n->len; i ++) {
        printf("%i - ", n->data[i]);
    }
    printf("\n");
}
void findArray(struct list* list, int* arr) {
    if (list->first == 0) return;
    struct node* curr = list->first;
    while (curr != 0) {
        if (curr->data == arr) {
            printArray(curr);
        }
        curr = curr->next;
    }
    return;
}

int main () {
    struct list* ls = (struct list*) malloc(sizeof(struct list));
    ls->first = 0;
    int arr[3] = {1, 2, 3};
    int arr2[2] = {10, 10};
    int** d = (int**) malloc(sizeof(int*));
    *d = 0;
    addLast(ls, arr, 3);
    addLast(ls, arr2, 2);
    getGreatestAverageArray(ls, d);
    findArray(ls, *d);
    printList(ls);
    deleteList(ls);
    free(d);
    return 0;
}
