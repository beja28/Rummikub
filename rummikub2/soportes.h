#ifndef soportes_h
#define soportes_h

#include <iostream>
#include <iomanip>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "constantes.h"
#include "soporte.h"
#include "bolsa.h"

using namespace std;


typedef tSoporte tSoportes[NumJugadores];

int menor(const tSoportes& soporte);
void repartir(tBolsa& bolsa, tSoportes& soportes);
void iniSoporte(tSoportes& soportes);
void resize(tSoporte& soporte);
void nuevaFicha(tFicha& ficha, tSoporte& soporte);
void reduce(tSoporte& soporte);
void delSoporte(tSoportes& soportes);


#endif soportes_h
