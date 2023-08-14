#include <stdio.h>
#include <stdlib.h>

int len(char* s) {

    int i = 0, counter = 0;
    while (s[i] != '\0') {
        i++;
        counter++;
    }
    return counter;
}

char* copy(char* s) {
    int length = 0;
    while (s[length] != '\0') {
        length++;
    }
    char *p = (char*) malloc(sizeof(char*) * length);
    for (int i = 0; i < length+1; i++) {
        p[i] = s[i];
    }
    
    return p;
}

void replaceChar(char* s, char old, char new) {

    int size = len(s);
    for (int i = 0; i < size; i++) {
        if (s[i] == old) {
            s[i] = new;
        }
    }

}

char* concatenate(char* s1, char* s2) {

    int size1 = len(s1);
    int size2 = len(s2);
    int pos = size1-1; // Posicion del string res en la que termina el s1.

    char *res = (char*) malloc(sizeof(char) * (size1 + size2));
    for (int i = 0; i < size1; i++){
        res[i] = s1[i];
    }
    for (int j = 0; j < size2; j++) {
        pos += 1;
        res[pos] = s2[j];

    }
    return res;
}

int main() {
    
    // -- Descomentar para probar --
    // Lo siguiente es un ejemplo y DEBE ser modificado.

    char* s1 = "Ramon";
    char* s2 = "Ricardo";

    printf("El string \"%s\" mide %i\n",s1, len(s1));
    printf("El string \"%s\" mide %i\n",s2, len(s2));

    char* copyS1 = copy(s1);
    char* copyS2 = copy(s2);

    printf("El string \"%s\" es una copia de  %s\n",copyS1, s1);
    printf("El string \"%s\" es una copia de  %s\n",copyS2, s2);

    replaceChar(copyS1, 'a', 'o');
    replaceChar(copyS2, 'R', 'T');

    printf("Sobre el string \"%s\" remplazo 'a' por 'o': %s\n",s1, copyS1);
    printf("Sobre el string \"%s\" remplazo 'R' por 'T': %s\n",s2, copyS2);

    printf("Concateno \"%s\" con \"%s\":",copyS1, copyS2);

    char* concat = concatenate(copyS1, copyS2);

    printf(" \"%s\"\n",concat);
    
    free(concat);


    return 0;
}
