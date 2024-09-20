#include "Fichas.h"


void mostrar(const tFicha& ficha) //muestra una ficha, con su color correspondiente
{
	colorTexto(ficha.color);
	cout << setw(3) << ficha.numeroFicha << "  ";
	colorTexto(BLANCO);
}

