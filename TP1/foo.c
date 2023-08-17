#include <stdio.h> 
#include <stdlib.h>

// struct persona {
//     char *nombre;
//     int edad;
// };
// void cambiarEdad(struct persona* p);

// int main() {
//     struct persona manuel;
//     manuel.nombre = "Manuel";
//     manuel.edad = 19;
//     printf("Mi nombre es %s, mi edad es %i\n", manuel.nombre, manuel.edad);
//     struct persona* punteroManuel = &manuel;
//     cambiarEdad(punteroManuel);
//     printf("Mi nombre es %s, mi edad es %i\n", manuel.nombre, manuel.edad);
//     struct persona *paula = (struct persona*) malloc(sizeof(struct persona));
//     paula->nombre = "Paula";
//     paula->edad = 18;
//     printf("Mi nombre es %s, mi edad es %i\n", paula->nombre, paula->edad);
//     cambiarEdad(paula);
//     printf("Mi nombre es %s, mi edad es %i\n", paula->nombre, paula->edad);
// }

// void cambiarEdad(struct persona* p) {
//     p->edad = 21;
// }

int main () {
    char* s = (char*) malloc(sizeof(char) * 4);
    s = "Hola";
    free(s);
}