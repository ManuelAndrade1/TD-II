#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int main() {

    // COMPLETAR

    // A Continuacion dejamos algunos ejemplos de como
    // llama a las funciones pedidas. Este codigo debe
    // ser borrado / modificado.

    // Strings para testing
    char* strTest1 =  "";
    char* strTest2 = "c";
    char* strTest3 = "123456789qwertyuiopasdfghjklzxcvbnm<!@#$^&*()_+=>,.;:'[]{}";
    // strLen
    int test1 = strLen(strTest1);
    int test2 = strLen(strTest2);
    int test3 = strLen(strTest3);
    printf("strLen(\"%s\") -> %i\n", strTest1, test1);
    printf("strLen(\"%s\") -> %i\n", strTest2, test2);
    printf("strLen(\"%s\") -> %i\n", strTest3, test3);
    printf("\n");

    // strDup
    char* dup1 = strDup(strTest1);
    char* dup2 = strDup(strTest2);
    char* dup3 = strDup(strTest3);
    printf("strDup(\"%s\") -> \"%s\"\n", strTest1, dup1);
    printf("strDup(\"%s\") -> \"%s\"\n", strTest2, dup2);
    printf("strDup(\"%s\") -> \"%s\"\n", strTest3, dup3);
    free(dup1);
    free(dup2);
    free(dup3);
    printf("\n");

    // wheel
    struct wheel* w1 = makeWheelFromString("A");
    printf("Test rueda de 1 caracter: \"A\"\n");
    wheelPrint(w1);
    printf("\n\n");
    struct wheel* w2 = makeWheelFromString("ASDFGHJKLZ");
    printf("Test rueda de 10 caracteres: \"ASDFGHJKLZ\"\n");
    wheelPrint(w2);
    printf("\n\n");
    struct wheel* w3 = makeWheelFromString("POIUYTREWQMNBVCXZLKJHGFDSA");
    printf("Test rueda de 26 caracteres: \"POIUYTREWQMNBVCXZLKJHGFDSA\"\n");
    wheelPrint(w3);
    printf("\n\n");

    printf("Test rotar rueda de 26 caracteres 1 posicion\n");
    printf("Antes:\n");
    wheelPrint(w3);
    printf("\nDespues:\n");
    rotateWheel(w3, 1);
    wheelPrint(w3);
    printf("\n\n");

    setWheel(w3, 0);

    printf("Test rotar rueda de 26 caracteres 26 posiciones\n");
    printf("Antes:\n");
    wheelPrint(w3);
    printf("\nDespues:\n");
    rotateWheel(w3, 26);
    wheelPrint(w3);
    printf("\n\n");

    struct wheel* w4 = makeWheelFromString("ASDFG");
    printf("Test rotar rueda de 5 caracteres 26 posiciones\n");
    printf("Antes:\n");
    wheelPrint(w4);
    rotateWheel(w4, 26);
    printf("\nDespues:\n");
    wheelPrint(w4);
    printf("\n\n");

    printf("Test rotar rueda de 1 caracteres 26 posiciones\n");
    printf("Antes:\n");
    wheelPrint(w1);
    printf("\nDespues:\n");
    rotateWheel(w1, 26);
    wheelPrint(w1);
    printf("\n\n");

    wheelDelete(w1);
    wheelDelete(w2);
    wheelDelete(w3);
    wheelDelete(w4);
    
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

    char* text = "TEXT";
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

    return 0;
}
