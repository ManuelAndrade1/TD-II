/* ************************************************************************* */
/*   LTD - Tecnologia Digital 2 - Trabajo Practico 2                         */
/* ************************************************************************* */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "lib/libbmp.h"
#include "lib/utils.h"
#include "common.h"

uint32_t width;
uint32_t height;
uint8_t* data;
uint8_t* result;

// Definimos 3 procesos paralelos
static void* process2(__attribute__((unused)) void* _) {
  step_blur3(width, height, data, result, 1, width/4, 1, height-2);
}
static void* process3(__attribute__((unused)) void* _) {
  step_blur3(width, height, data, result, width/4+1, width/2, 1, height-2);
}
static void* process4(__attribute__((unused)) void* _) {
  step_blur3(width, height, data, result, width/2+1, 3*(width/4), 1, height-2);
}

int main(int argc, char **argv) {

  char* inputFileName;
  char* outputFileName;
  int count;
  BMP* img;

  // Cargado de imagen en memoria
  loadImageAndParams(argc, argv, &inputFileName, &outputFileName, &img, &count);
  width = bmp_width(img);
  height = bmp_height(img);
  data = bmp_data(img);

  // Solicito memoria para datos temporales
  result = (uint8_t*) malloc(width * height * sizeof(bgra_t));
  step_copy(width, height, data, result, 0, width-1, 0, height-1);
  
  // Procesamiento de la imagen
  for(int i = 0; i<count; i++) {
    uint8_t* tmp;
    pthread_t thread, thread2, thread3;
    // Creamos los 4 threads (3 paralelos + padre)
    pthread_create(&thread, NULL, process2, NULL);
    pthread_create(&thread2, NULL, process3, NULL);
    pthread_create(&thread3, NULL, process4, NULL);
    step_blur3(width, height, data, result, 3*(width/4)+1, width-2, 1, height-2);
    // Esperamos la terminacion de los threads
    pthread_join(thread, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    tmp = data;
    data = result;
    result = tmp;
  }
  paintEdges(width, height, result);

  // Liberacion de memoria
  free(data);

  // Guardado de la imagen
  setResultAndSaveImage(img, result, outputFileName);

  return 0;
}
