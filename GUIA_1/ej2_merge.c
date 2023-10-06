#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int* arr, int size) {
    for (int i = 0; i < size-1; i++) {
        for (int j = i+1; j < size-1; j++) {
            if(arr[j] < arr[i]) {
                swap(&arr[j], &arr[i]);
            }
        }
    }
}

int* merge(int* A, int sizeA, int* B, int sizeB) {

    int *res = (int*) malloc(sizeof(int) * (sizeA + sizeB));
    int pos = sizeA-1;

    for (int i = 0; i < sizeA; i++) {
        res[i] = A[i];
    }
    for (int j = 0; j < sizeB; j++) {
        pos += 1;
        res[pos] = B[j];
    }
    sort(res, sizeA+sizeB);
    return res;
}

void swap_float(float* a, float* b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}
void sort_float(float* arr, int size) {
    for (int i = 0; i < size-1; i++) {
        for (int j = i+1; j < size-1; j++) {
            if(arr[j] < arr[i]) {
                swap_float(&arr[j], &arr[i]);
            }
        }
    }
}

float* merge_to_float(int* A, int sizeA, int* B, int sizeB) {

    float *res = (float*) malloc(sizeof(float) * (sizeA + sizeB));
    int pos = sizeA-1;

    for (int i = 0; i < sizeA; i++) {
        res[i] =  (float) A[i];
    }
    for (int j = 0; j < sizeB; j++) {
        pos += 1;
        res[pos] = (float) B[j];
    }
    sort_float(res, sizeA+sizeB);
    return res;
}

int main() {
    // -- Descomentar para probar --
    // Lo siguiente es un ejemplo y DEBE ser modificado.

    int a[5] = {4,5,6,7,8};
    int b[4] = {1,2,3,9};

    int* result = merge(a, 5, b, 4);

    printf("Result:");
    for(int i=0; i<9; i++) {
        printf(" %i", result[i]);
    }
    printf("\n");

    free(result);

    float* result2 = merge_to_float(a, 5, b, 4);

    printf("Result:");
    for(int i=0; i<9; i++) {
        printf(" %.1f", result2[i]);
    }
    printf("\n");

    free(result2);


    return 0;
}
