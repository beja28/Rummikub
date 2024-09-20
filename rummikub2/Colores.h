#ifndef colores_h
#define colores_h

#include <iostream>
#include <iomanip>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;


typedef enum tColor { ROJO, VERDE, AZUL, AMARILLO, BLANCO, LIBRE };

void colorTexto(tColor color);

#endif colores_h