#ifndef fichas_h
#define fichas_h

#include <iostream>
#include <iomanip>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "constantes.h"
#include "Colores.h"

using namespace std;

typedef struct {
	tColor color;
	int numeroFicha;
}tFicha;

typedef tFicha* puntero_f;
typedef puntero_f tArrayFichas[MAXFICHAS];
typedef puntero_f tMatrizB[8][NumFichas];
typedef tFicha tAuxJugada[NumFichas];

void mostrar(const tFicha& ficha);

#endif fichas_h



