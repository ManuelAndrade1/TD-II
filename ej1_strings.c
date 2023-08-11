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

    // COMPLETAR

}

char* concatenate(char* s1, char* s2) {

    // COMPLETAR
    
    return 0;
}

int main() {
    /*
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

    // */

    return 0;
}
