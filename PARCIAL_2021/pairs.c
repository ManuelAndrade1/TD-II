#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node* next;
    int data[3];
};

struct pair {
    struct node* first;
    struct node* second;
};

void addLast(struct pair* p, int index, int* arr) {
    struct node* new = (struct node*) malloc(sizeof(struct node));
    for (int i = 0; i < 3; i++) {
        new->data[i] = arr[i];
    }
    new->next = 0;
    if (index == 0 && p->first == 0) {
        p->first = new; 
        return;
    }
    if (index == 1 && p->second == 0) {
        p->second = new;
        return;
    }
    struct node* temp;
    if (index == 0) {
        temp = p->first;
    }
    else {
        temp = p->second;
    }

    while (temp->next != 0) {
        temp = temp->next;
    }
    temp->next = new;
}

void printList(struct node* n) {
    struct node* temp = n;
    while(temp != 0) {
        printf("[%i, %i, %i] - ", temp->data[0], temp->data[1], temp->data[2]);
        temp = temp->next;
    }
    printf("\n\n");
}

void printPair(struct pair* p) {
    if (p->first != 0) {
        printf("First Branch:\n");
        printList(p->first);
    }
    if (p->second != 0) {
        printf("Second Branch:\n");
        printList(p->second);
    }
}

void deleteBranch(struct node* n) {
    while (n != 0){
        struct node* temp = n;
        n = n-> next;
        free(temp);
    }
} 

void deletePair(struct pair* p) {
    deleteBranch(p->first);
    deleteBranch(p->second);
    free(p);
}

void changeFirst(struct pair* p) {

    struct node* temp = p->first;
    struct node* temp2 = p->second;

    p->first = p->first->next;
    p->second = p->second->next;
    return;
}
void firstToLast(struct pair* p){
    struct node* temp = p->first;
    while (temp->next != 0) {
        temp = temp->next;
    }
    temp->next = p->first;
    p->first = p->first->next;
    temp->next->next = 0;

    temp = p->second;
    while (temp->next != 0) {
        temp = temp->next;
    }
    temp->next = p->second;
    p->second = p->second->next;
    temp->next->next = 0;

}
void removeAndRotate(struct pair* p) {
    changeFirst(p);
    firstToLast(p);
}

int main() {
    struct pair* s = (struct pair*) malloc(sizeof(struct pair));
    s->first = 0;
    s->second = 0;
    int d[3] = {23, 54, 19};
    int d2[3] = {23, 28, 12};
    int d3[3] = {61, 99, 34};
    int d4[3] = {18, 21, 37};
    int d5[3] = {66, 45, 13};
    int d6[3] = {15, 38, 19};
    int d7[3] = {45, 55, 13};
    addLast(s, 0, d);
    addLast(s, 0, d2);
    addLast(s, 0, d3);
    addLast(s, 0, d4);
    addLast(s, 1, d5);
    addLast(s, 1, d6);
    addLast(s, 1, d7);
    printPair(s);
    removeAndRotate(s);
    printPair(s);
    deletePair(s);
}