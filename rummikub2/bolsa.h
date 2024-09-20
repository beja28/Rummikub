#ifndef bolsa_h
#define bolsa_h

#include <iostream>
#include <iomanip>
#include <string> 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "constantes.h"
#include "Fichas.h"


using namespace std;

struct tBolsa {
	tMatrizB matriz_bidimensional;
	int fichas_disp = NumFichas * 8;
	int ini_fichas = 8;
};

void inicializarBolsa(tBolsa& bolsa);
tFicha robar(tBolsa& bolsa);
void mostrar(const tBolsa& bolsa);
void delBolsa(tBolsa& bolsa);


#endif bolsa_h