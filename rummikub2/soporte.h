#ifndef soporte_h
#define soporte_h

#include <iostream>
#include <iomanip>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "constantes.h"
#include "Fichas.h"
#include "jugadas.h"

using namespace std;

 struct tSoporte {
	puntero_f ptr_a_fichas;
	int contador;
	int capacidad = 8;
};



void mostrar(const tSoporte& soporte);
void ordenarPorNum(tSoporte& soporte);
void ordenarPorColor(tSoporte& soporte);
void mostrarEscaleras(const tSoporte& soporte);
void mostrarSeries(const tSoporte& soporte);
void eliminaFichas(tSoporte& soporte, const tJugada& jugada);
void nuevaJugada(tSoporte& soporte, tJugada& jugada);
void iniSoporte(tSoporte& soporte);

#endif soporte_h