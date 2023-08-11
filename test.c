#include <stdio.h>
#include <stdlib.h>

char* copy(char* s) {
    int length = 0;
    while(s[length] != '\0') {
        length++;
    }

    char *p = NULL;
    for(int i= 0; i < length+1; i++) {
        p[i] = s[i];
    }
    return p;
}

int main() {
    char* h = "Hola";
    char* r = copy(h);
    printf("%s, %s\n", h, r);
    printf("%d, %d", *h, *r);
}