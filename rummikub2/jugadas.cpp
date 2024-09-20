#include "jugadas.h"


void mostrar(const tJugada& jugada)  //muestra una jugada
{
	for (int i = 0; i < jugada.fichas_jugada; i++) //muestra ficha por ficha hasta llegar al final del contador
	{
		mostrar(jugada.ArrayJugada[i]);
	}
	cout << endl;
}

int buscar(const tJugada& jugada, const tFicha& ficha) {
	int posicion;
	bool ficha_encontrada = false;
	int i = 0;
	while ((i < jugada.fichas_jugada) && !ficha_encontrada) {
		if (ficha.numeroFicha == jugada.ArrayJugada[i].numeroFicha && ficha.color == jugada.ArrayJugada[i].color) {
			posicion = i;
			ficha_encontrada = true;
		}
		else {
			posicion = -1;
		}
		i++;
	}
	return posicion;
}



bool ponerFicha(tJugada& jugada, tFicha& ficha) //funcion para introducir una ficha dentro de una jugdad
{
	bool ret = false;
	bool fin = false;
	int i = 0;
	bool es_serie, es_escalera;
	//comprueba si la jugada es una serie o una escalera
	es_serie = serie(jugada);
	es_escalera = escalera(jugada);
	if (es_serie)
	{
		for (int i = 0; i < jugada.fichas_jugada; i++)
		{
			if (fin == false)
			{
				//comprueba que la ficha no sea del mismo color que alguna otra de la jugada
				if (ficha.color != jugada.ArrayJugada[i].color && ficha.numeroFicha == jugada.ArrayJugada[i].numeroFicha)
				{
					ret = true;
				}
				else
				{
					ret = false;
					fin = true;
				}
			}
		}
	}
	else if (es_escalera)
	{
		if (ret == false)
		{
			//comprueba con la primera ficha de la jugada
			if (ficha.color == jugada.ArrayJugada[0].color && jugada.ArrayJugada[0].numeroFicha - ficha.numeroFicha == 1) {
				ret = true;
			}
			//comprueba con la ultima ficha de la jugada
			else if (ficha.color == jugada.ArrayJugada[jugada.fichas_jugada - 1].color && ficha.numeroFicha - jugada.ArrayJugada[jugada.fichas_jugada - 1].numeroFicha == 1)
			{
				ret = true;
			}
		}
	}
	return ret;
}

bool serie(const tJugada& jugada) //comprueba si es una serie
{
	bool serie = true;
	int i = 0;
	while (i < jugada.fichas_jugada - 1 && serie == true)
	{
		for (int j = i; j < jugada.fichas_jugada - 1; j++)
		{
			if (jugada.ArrayJugada[j + 1].numeroFicha == jugada.ArrayJugada[i].numeroFicha && jugada.ArrayJugada[j + 1].color != jugada.ArrayJugada[i].color)
			{
				serie = true;
			}
			else
			{
				serie = false;
			}
		}
		i++;
	}
	return serie;
}
bool escalera(const tJugada& jugada) //comprueba si es una escalera
{
	bool escalera = true;
	int i = 0;
	while (i < jugada.fichas_jugada - 1 && escalera == true)
	{
		if (jugada.ArrayJugada[i + 1].numeroFicha - jugada.ArrayJugada[i].numeroFicha == 1 && jugada.ArrayJugada[i + 1].color == jugada.ArrayJugada[i].color)
		{
			escalera = true;
		}
		else
		{
			escalera = false;
		}
		i++;
	}
	return escalera;
}

void iniJugada(tJugada& jugada)
{
	jugada.ArrayJugada = new tFicha[NumFichas + 1];
	for (int i = 0; i < NumFichas; i++)
	{
		jugada.ArrayJugada[i].numeroFicha = -1;
	}
}