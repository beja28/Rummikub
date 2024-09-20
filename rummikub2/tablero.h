#ifndef tablero_h
#define tablero_h

#include <iostream>
#include <iomanip>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "constantes.h"
#include "jugadas.h"
#include "soporte.h"

using namespace std;


typedef puntero_arrayJ Array_tablero[MAXJUGADAS];

struct tTablero {
	int cont_jugadas;
	Array_tablero arrayJugadas;
};

void mostrar(const tTablero& tablero);
bool jugar(tTablero& tablero, tSoporte& soporte);
void meterFicha(int Indice, tTablero& tablero, tJugada jugada);
void delTablero(tTablero& tablero);

#endif tablero_h