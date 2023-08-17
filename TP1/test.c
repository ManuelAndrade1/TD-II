#include <stdio.h>
#include <stdlib.h>


struct littleEnigma {
    struct wheel** wheels;
    int wheelsCount;
};

struct wheel {
    struct letter* first;
    char* alphabet;
    int count;
};

struct letter {
    char letter;
    int  position;
    struct letter* next;
};

void wheelPrint(struct wheel* w);

int strLen(char* src) {

    int res = 0;

    for (int i = 0; src[i] != 0; i++) {
        res++;
    }

    return res;
}

char* strDup(char* src) {

    int length = strLen(src);
    char *res = (char*) malloc(sizeof(char) * length);
    
    for (int i = 0; src[i] != 0; i++) {
        res[i] = src[i];
    }
    res[length] = '\0';
    return res;
}

struct littleEnigma* littleEnigmaNew(char** alphabetPermutation, int count){

    // COMPLETAR

    return 0;
}

void littleEnigmaSet(struct littleEnigma* le, int* password) {

    // COMPLETAR
}

char* littleEnigmaEncrypt(struct littleEnigma* le, char* text){

    // COMPLETAR

    return 0;
}

char* littleEnigmaDecrypt(struct littleEnigma* le, char* code) {

    // COMPLETAR

    return 0;
}

void littleEnigmaDelete(struct littleEnigma* le) {

    // COMPLETAR

}

void littleEnigmaPrint(struct littleEnigma* le) {
    for(int i=0; i<le->wheelsCount; i++) {
        wheelPrint(le->wheels[i]);
        printf("\n");
    }
}

// Funcion auxiliar para lista circular
void addLast (struct letter* first, struct letter* next) {
    struct letter* temp = first;
    while (temp-> next != NULL) {
        temp = temp->next;
    }
    temp->next = next;
}
struct wheel* makeWheelFromString(char* alphabetPermutation) {

    struct wheel* newWheel = (struct wheel*) malloc(sizeof(struct wheel));
    newWheel->alphabet = strDup(alphabetPermutation);
    newWheel->count = strLen(alphabetPermutation);
    for (int i = 0; i < newWheel->count; i++) {
        struct letter* l = (struct letter*) malloc(sizeof(struct letter));
        l->letter = alphabetPermutation[i];
        l->position = i;
        l->next = NULL;
        if (i == 0) {
            newWheel->first = l;
        }
        else {
            addLast(newWheel->first, l);
            if (i == newWheel->count-1) {
                l->next = newWheel->first;
            }
        }

    }
    return newWheel;
}

void setWheel(struct wheel* w, int position) {
    struct letter* current = w->first;
    while(current->position != position) {
        current = current->next;
    }
    w->first = current;   
}

void rotateWheel(struct wheel* w, int steps) {

    struct letter* temp = w->first;

    for (int i = 0; i < steps; i++) {
        temp = temp->next;
    }
    w->first = temp;
}

void rotateWheels(struct wheel** wheels, int wheelsCount) {

    // COMPLETAR

}

void wheelDelete(struct wheel* w) {
    int length = strLen(w->alphabet);
    struct letter* curr = w->first;
    struct letter* prev = NULL;
    for (int i = 0; i < length; i++) {
        prev = curr;
        if (i != length-1) {
            curr = curr->next;
        }
        free(prev);
    }
    free(w->alphabet);
    free(w);
}

void wheelPrint(struct wheel* w) {
    printf("%s", w->alphabet);
    struct letter* current = w->first;
    int i = 0;
    while(i<w->count) {
        printf("(%c-%i)", current->letter, current->position);
        current = current->next;
        i++;
    }
}

int letterToIndex(char letter) {
    if('A' <= letter && letter <= 'Z') return letter-'A';
    return 0;
}

char indexToletter(int index) {
    if(0 <= index && index <= 25) return index+'A';
    return 0;
}

char encryptWheel(struct wheel* w, char letter) {
    int index =  letterToIndex(letter);
    struct letter* current = w->first;
    int i = 0;
    while(i<index) {
        current = current->next;
        i++;
    }
    return current->letter;
}

char decryptWheel(struct wheel* w, char letter) {
    struct letter* current = w->first;
    int i = 0;
    while(current->letter != letter) {
        current = current->next;
        i++;
    }
    return indexToletter(i);
}

char encryptOneLetter(struct littleEnigma* le, char letter) {

    // COMPLETAR

    return 0;
}

char decryptOneLetter(struct littleEnigma* le, char letter) {

    // COMPLETAR

    return 0;
}

int main () {
    // strLen
    int len = strLen("hola");
    printf("strLen(\"hola\") -> \"%i\"\n", len);
    printf("\n");

    // strDup
    char* dup = strDup("hola");
    printf("strDup(\"hola\") -> \"%s\"\n", dup);
    free(dup);
    printf("\n");

    // wheel
    struct wheel* w = makeWheelFromString("QWERTYUIOPASDFGHJKLMNBVCXZ"); // 
    wheelPrint(w);
    printf("\n");

    setWheel(w, 5);
    wheelPrint(w);
    printf("\n");

    rotateWheel(w, 3);
    wheelPrint(w);
    printf("\n");

    printf("Borrando rueda...\n");
    wheelDelete(w);
    printf("\n\n");

}