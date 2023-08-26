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
    
    // Test de littleEnigma

    char* emptyStr = "";
    char* longStr = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
    char* mediumStr = "BUENOSDIAS";


    // Creamos las y setteamos las maquinas

    // 1 disco
    char* permutationTest[1];
    permutationTest[0] = "POIUYTREWQLKJHGFDSAMNBVCXZ";
    struct littleEnigma* leTest = littleEnigmaNew(permutationTest, 1);
    printf("Maquina enigma de 1 disco:\n");
    littleEnigmaPrint(leTest);
    printf("\n\n");

    int password[1] = {10};
    littleEnigmaSet(leTest, password);
    printf("Maquina luego de inicializarla:\n");
    littleEnigmaPrint(leTest);
    printf("\n\n");


    // 3 discos
    char *permutationTest2[3];
    permutationTest2[0] = "QWERTYUIOPASDFGHJKLZXCVBNM";
    permutationTest2[1] = "ASDFGHJKLZXCVBNMQWERTYUIOP";
    permutationTest2[2] = "PQWOIERUTYALKSJDFHGZMNXCBV";
    struct littleEnigma* leTest2 = littleEnigmaNew(permutationTest2, 3);
    printf("Maquina enigma de 3 discos:\n");
    littleEnigmaPrint(leTest2);
    printf("\n\n");

    int password2[3] = {12, 9, 6};
    littleEnigmaSet(leTest2, password2);
    printf("Maquina luego de inicializarla:\n");
    littleEnigmaPrint(leTest2);
    printf("\n\n");

    // 5 discos
    char* permutationTest3[5];
    permutationTest3[0] = "QAWSEDRFTGYHUJIKOLPZXCVBNM";
    permutationTest3[1] = "ZAXSCDVFBGNHMJKLQOWPERTYUI";
    permutationTest3[2] = "ZAQXSWCDEVFRBGTNHYMJUKILOP";
    permutationTest3[3] = "PLOKMIJNUHBYGVTFCRDXESZWAQ";
    permutationTest3[4] = "QPALWOSKIEDJRUFHTYGZMNXCBV";
    struct littleEnigma* leTest3 = littleEnigmaNew(permutationTest3, 5);
    printf("Maquina enigma de 5 discos:\n");
    littleEnigmaPrint(leTest3);
    printf("\n\n");

    int password3[5] = {20, 0, 1, 25, 23};
    littleEnigmaSet(leTest3, password3);
    printf("Maquina luego de inicializarla:\n");
    littleEnigmaPrint(leTest3);
    printf("\n\n");

    // 8 discos
    char* permutationTest4[8];
    permutationTest4[0] = "QAWSEDRFTGYHUJIKOLPZXCVBNM";
    permutationTest4[1] = "ASDFGHJKLZXCVBNMQWERTYUIOP";
    permutationTest4[2] = "PQWOIERUTYALKSJDFHGZMNXCBV";
    permutationTest4[3] = "ZAXSCDVFBGNHMJKLQOWPERTYUI";
    permutationTest4[4] = "ZAQXSWCDEVFRBGTNHYMJUKILOP";
    permutationTest4[5] = "QWERTYUIOPASDFGHJKLZXCVBNM";    
    permutationTest4[6] = "PLOKMIJNUHBYGVTFCRDXESZWAQ";
    permutationTest4[7] = "QPALWOSKIEDJRUFHTYGZMNXCBV";
    struct littleEnigma* leTest4 = littleEnigmaNew(permutationTest4, 8);
    printf("Maquina enigma de 8 discos:\n");
    littleEnigmaPrint(leTest4);
    printf("\n\n");

    int password4[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    littleEnigmaSet(leTest4, password4);
    printf("Maquina luego de inicializarla:\n");
    littleEnigmaPrint(leTest4);
    printf("\n\n");    

    // Encriptar y desencriptar string vacio
    char* testCode = littleEnigmaEncrypt(leTest, emptyStr);
    littleEnigmaSet(leTest, password);
    char* testDecode = littleEnigmaDecrypt(leTest, testCode);
    littleEnigmaSet(leTest, password);
    printf("Encriptar y desencriptar string vacio:\n");
    printf("Encriptar \"%s\" -> \"%s\"\n", emptyStr, testCode);
    printf("Desencriptar: \"%s\" -> \"%s\"\n", testCode, testDecode);
    printf("\n\n");

    // Encriptar y desencriptar mensaje 35 caracteres iguales
    char* testCode2 = littleEnigmaEncrypt(leTest, longStr);
    littleEnigmaSet(leTest, password);
    char* testDecode2 = littleEnigmaDecrypt(leTest, testCode2);
    littleEnigmaSet(leTest, password);
    printf("Encriptar y desencriptar 35 caracteres iguales:\n");
    printf("Encriptar \"%s\" -> \"%s\"\n", longStr, testCode2); 
    printf("Desencriptar: \"%s\" -> \"%s\"\n", testCode2, testDecode2);
    printf("\n\n");

    // Encriptar y desencriptar mensaje de 10 caracteres en enigma de 3 discos
    char* testCode3 = littleEnigmaEncrypt(leTest2, mediumStr);
    littleEnigmaSet(leTest2, password2);
    char* testDecode3 = littleEnigmaDecrypt(leTest2, testCode3);
    littleEnigmaSet(leTest2, password2);
    printf("Encriptar y desencriptar 10 caracteres en maquina de 3 discos:\n");
    printf("Encriptar \"%s\" -> \"%s\"\n", mediumStr, testCode3);
    printf("Desencriptar: \"%s\" -> \"%s\"\n", testCode3, testDecode3);
    printf("\n\n");

    // Encriptar y desencriptar mensaje de 10 caracteres en enigma de 5 discos
    char* testCode4 = littleEnigmaEncrypt(leTest3, mediumStr);
    littleEnigmaSet(leTest3, password3);
    char* testDecode4 = littleEnigmaDecrypt(leTest3, testCode4);
    littleEnigmaSet(leTest3, password3);
    printf("Encriptar y desencriptar 10 caracteres en maquina de 5 discos:\n");
    printf("Encriptar \"%s\" -> \"%s\"\n", mediumStr, testCode4);
    printf("Desencriptar: \"%s\" -> \"%s\"\n", testCode4, testDecode4);
    printf("\n\n");

    // Encriptar y desencriptar mensaje de 10 caracteres en enigma de 8 discos
    char* testCode5 = littleEnigmaEncrypt(leTest4, mediumStr);
    littleEnigmaSet(leTest4, password4);
    char* testDecode5 = littleEnigmaDecrypt(leTest4, testCode5);
    littleEnigmaSet(leTest4, password4);
    printf("Encriptar y desencriptar 10 caracteres en maquina de 8 discos:\n");
    printf("Encriptar \"%s\" -> \"%s\"\n", mediumStr, testCode5);
    printf("Desencriptar: \"%s\" -> \"%s\"\n", testCode5, testDecode5);
    printf("\n\n");


    // Borramos todas las estructuras
    littleEnigmaDelete(leTest);
    littleEnigmaDelete(leTest2);
    littleEnigmaDelete(leTest3);
    littleEnigmaDelete(leTest4);

    if (testCode) free(testCode);
    if (testDecode) free(testDecode);

    if (testCode2) free(testCode2);
    if (testDecode2) free(testDecode2);

    if (testCode3) free(testCode3);
    if (testDecode3) free(testDecode3);

    if (testCode3) free(testCode4);
    if (testDecode3) free(testDecode4);

    if (testCode4) free(testCode5);
    if (testDecode4) free(testDecode5);

    return 0;
}
