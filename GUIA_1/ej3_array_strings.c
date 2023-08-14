#include <stdio.h>
#include <stdlib.h>

int len(char *s) {
    int i = 0;
    while (s[i] != 0) {
        i++;
    }
    return i;
}


char* longest(char* v[], int size) {
    int max_len = 0;
    for (int i = 0; i < size; i++) {
        int cur_len = len(v[i]);
        if (max_len < cur_len) {
            max_len = cur_len;
        }
    }
    char *res = (char*) malloc(sizeof(char) * max_len);
    for (int j = 0; j < size; j++) {
        int cur_len = len(v[j]);
        if (max_len == cur_len) {
            res = v[j];
            break;
        }
    }

    return res;
}

char* superConcatenate(char* v[], int size) {

    int pos = 0;
    int super_size = 0;
    for (int i = 0; i < size; i++) {
        super_size += len(v[i]);
    }
    char *res = (char*) malloc(sizeof(char) * super_size);
    for (int j = 0; j < size; j ++) {
        int iter = len(v[j]);
        for (int z = 0; z < iter; z ++) {
            res[pos] = v[j][z];
            pos++;
        }
    }
 
    return res;
}

char* superConcatenateWithSep(char* v[], int size, char* s) {

    int pos = 0;
    int super_size = 0;
    for (int i = 0; i < size; i++) {
        super_size += len(v[i]);
    }
    char *res = (char*) malloc(sizeof(char) * super_size);
    for (int j = 0; j < size; j ++) {
        int iter = len(v[j]);
        for (int z = 0; z < iter; z ++) {
            res[pos] = v[j][z];
            pos++;
        }
        int sub_iter = len(s);
        if (j != size-1) { // Garantiza que no se agregue el step al final del string.
            for (int r = 0; r < sub_iter; r++) {
                res[pos] = s[r];
                pos++;   
            }
        }
    }
 
    return res;
}

int main() {
    
    // -- Descomentar para probar --
    // Lo siguiente es un ejemplo y DEBE ser modificado.

    char* v[5] = {"hola", "como", "va", "el", "dia"};

    char* l = longest(v, 5);

    printf("El string mas largo es: \"%s\"\n", l);

    char* sc = superConcatenate(v, 5);

    printf("El arreglo de string super concatenado es: \"%s\"\n", sc);

    char* scs = superConcatenateWithSep(v, 5, "...");

    printf("El arreglo de string super concatenado con separadores es: \"%s\"\n", scs);

    free(sc);
    free(scs);


    return 0;
}
