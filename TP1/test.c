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

int strLen(char* src);
char* strDup(char* src);
struct littleEnigma* littleEnigmaNew(char** alphabetPermutation, int count);
void littleEnigmaSet(struct littleEnigma* le, int* password);
char* littleEnigmaEncrypt(struct littleEnigma* le, char* text);
char* littleEnigmaDecrypt(struct littleEnigma* le, char* code);
void littleEnigmaDelete(struct littleEnigma* le);
void littleEnigmaPrint(struct littleEnigma* le);
void addLast (struct letter* first, struct letter* next);
struct wheel* makeWheelFromString(char* alphabetPermutation);
void setWheel(struct wheel* w, int position);
void rotateWheel(struct wheel* w, int steps);
void rotateWheels(struct wheel** wheels, int wheelsCount);
void wheelDelete(struct wheel* w);
void wheelPrint(struct wheel* w);
int letterToIndex(char letter);
char indexToletter(int index);
char encryptWheel(struct wheel* w, char letter);
char decryptWheel(struct wheel* w, char letter);
char encryptOneLetter(struct littleEnigma* le, char letter);
char decryptOneLetter(struct littleEnigma* le, char letter);


int strLen(char* src) {

    int res = 0;

    for (int i = 0; src[i] != 0; i++) {
        res++;
    }

    return res;
}

char* strDup(char* src) {

    int length = strLen(src);
    char *res = (char*) malloc(sizeof(char) * (length+1));
    
    for (int i = 0; src[i] != 0; i++) {
        res[i] = src[i];
    }
    res[length] = '\0'; // agrega el caracter nulo para evitar errores
    return res;
}

struct littleEnigma* littleEnigmaNew(char** alphabetPermutation, int count){

    struct littleEnigma* res = (struct littleEnigma*) malloc(sizeof(struct littleEnigma));
    struct wheel** ruedas = (struct wheel**) malloc(sizeof(struct wheel) * count);

    // Itera tantas veces como ruedas se necesiten crear
    for (int i = 0; i < count; i++) {
        ruedas[i] = makeWheelFromString(alphabetPermutation[i]);
    }
    res->wheels = ruedas;
    res->wheelsCount = count;
    return res;
}

void littleEnigmaSet(struct littleEnigma* le, int* password) {

    for (int i = 0; i < le->wheelsCount; i++){
        setWheel(le->wheels[i], password[i]);
    }
}

char* littleEnigmaEncrypt(struct littleEnigma* le, char* text){

    int length = strLen(text);
    char* res = (char*) malloc(sizeof(char) * (length+1));

    // Itera caracter a caracter y encripta 1 a 1
    for(int i = 0; i < length; i++){
        res[i] = encryptOneLetter(le, text[i]);
    }
    res[length] = '\0';
    return res;
}

char* littleEnigmaDecrypt(struct littleEnigma* le, char* code) {

    int length = strLen(code);
    char* res = (char*) malloc(sizeof(char) * (length+1));

    // Itera caracter a caracter y desencripta 1 a 1
    for(int i = 0; i < length; i++){
        res[i] = decryptOneLetter(le, code[i]);
    }
    res[length] = '\0';
    return res;

}

void littleEnigmaDelete(struct littleEnigma* le) {

    // Borra todas las ruedas
    for(int i = 0; i < le->wheelsCount; i++){
        wheelDelete(le->wheels[i]);
    }
    // Borra el puntero restante y la maquina en si
    free(le->wheels); 
    free(le);
}

void littleEnigmaPrint(struct littleEnigma* le) {

    for(int i = 0; i < le->wheelsCount; i++) {
        wheelPrint(le->wheels[i]);
        printf("\n");
    }
}

// PREGUNTAR
// Funcion auxiliar para lista circular
void addLast (struct letter* first, struct letter* next) {

    struct letter* temp = first;
    
    // Itera sobre la lista hasta llegar al ultimo elemento y lo agrega al final
    while (temp-> next != NULL) {
        temp = temp->next;
    }
    temp->next = next;
}
struct wheel* makeWheelFromString(char* alphabetPermutation) {

    struct wheel* newWheel = (struct wheel*) malloc(sizeof(struct wheel));

    newWheel->alphabet = strDup(alphabetPermutation);
    newWheel->count = strLen(alphabetPermutation);

    // Itera letra a letra del alfabeto pasado y crea la lista circular
    for (int i = 0; i < newWheel->count; i++) {
        struct letter* l = (struct letter*) malloc(sizeof(struct letter));
        l->letter = alphabetPermutation[i];
        l->position = i;
        l->next = NULL;
        if (i == 0) {
            newWheel->first = l;
        }
        else { // Conecta las letras con su respectiva siguiente
            addLast(newWheel->first, l);
            if (i == newWheel->count-1) { // Conecta la ultima a la primera
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
    int i = 0;
    int running = 1; // Variable seteada True
    while (running && i != wheelsCount) {
        rotateWheel(wheels[i], 1);
        if (wheels[i]->first->position != 0) {
            running = 0; // Rompe el ciclo;
        }
        i++;
    }
    // PREGUNTAR
    // for (int i = 0; i < wheelsCount; i++) {
    //     rotateWheel(wheels[i], 1);
    //     if (wheels[i]->first->position != 0) {
    //         break;
    //     }
    // }
}

void wheelDelete(struct wheel* w) {

    int length = strLen(w->alphabet);
    struct letter* curr = w->first;
    struct letter* prev = NULL;

    // Itera sobre la lista circular borrando letra a letra
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

    char res = letter;

    // Encripta la letra pasada por el parametro tantas veces como discos haya
    for (int i = 0; i < le->wheelsCount; i++) {
        res = encryptWheel(le->wheels[i], res);
    }
    rotateWheels(le->wheels, 1); 
    return res;
}

char decryptOneLetter(struct littleEnigma* le, char letter) {

    char res = letter;

    // Desencripta la letra disco a disco hasta que vuelva a su forma original
    for (int i = le->wheelsCount-1; i >= 0; i--) {
        res = decryptWheel(le->wheels[i], res);
    }
    rotateWheels(le->wheels, 1);
    return res;
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

   // littleEnigma
    char* alphabetPermutation[2];
    alphabetPermutation[0] = "JGDQOXUSCAMIFRVTPNEWKBLZYH";
    alphabetPermutation[1] = "NTZPSFBOKMWRCJDIVLAEYUXHGQ";
    struct littleEnigma* le = littleEnigmaNew(alphabetPermutation, 2);
    littleEnigmaPrint(le);
    printf("\n\n");

    int password[2] = { 3, 5 };
    littleEnigmaSet(le, password);
    littleEnigmaPrint(le);
    printf("\n\n");

    char* text = "HOLA";
    char* code = littleEnigmaEncrypt(le, text);
    littleEnigmaPrint(le);
    printf("%s -> %s\n\n", text, code);

    littleEnigmaSet(le, password);
    littleEnigmaPrint(le);
    printf("\n\n");

    char* decode = littleEnigmaDecrypt(le, code);
    littleEnigmaPrint(le);
    printf("%s -> %s -> %s\n\n", text, code, decode);

    if(code) free(code);
    if(decode) free(decode);

    littleEnigmaDelete(le);

}