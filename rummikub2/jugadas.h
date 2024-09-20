#ifndef jugadas_h
#define jugadas_h

#include <iostream>
#include <iomanip>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "constantes.h"
#include "fichas.h"


using namespace std;

struct tJugada{
	puntero_f ArrayJugada;
	int fichas_jugada;
};
typedef tJugada* puntero_arrayJ;
typedef tJugada tMaxJugadas[MAXJUGADAS];

void mostrar(const tJugada& jugada);
int buscar(const tJugada& jugada, const tFicha& ficha);
bool ponerFicha(tJugada& jugada, tFicha& ficha);

bool serie(const tJugada& jugada);
bool escalera(const tJugada& jugada);
void iniJugada(tJugada& jugada);


#endif jugadas_h