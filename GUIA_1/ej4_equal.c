#include <stdio.h>
#include <stdlib.h>

void pairOfEquals(char v[], int size, char** a, char** b) {
    // Implementacion suponiendo que se devuelve al primer coincidencia.
    *a = 0;
    *b = 0;
    for (int i = 0; i < size; i++) {
        if (i == size-1) break;
        for(int j = i+1; j < size; j++) {
            if (v[i] == v[j]) {
                *a = &v[i];
                *b = &v[j];
                return;
            }
        }
    }
    return;
}

int main() {

    // -- Descomentar para probar --
    // Lo siguiente es un ejemplo y DEBE ser modificado.

    char v[7] = {9, 4, 5, 6, 1, 4, 1};

    char* a;
    char* b;

    pairOfEquals(v, 7, &a, &b);

    if(a == 0 || b == 0) {
        printf("No hay iguales");
    } else {
        printf("Los valores iguales son: %i == %i\n", (char)(*a), (char)(*b));
    }

    return 0;
}
