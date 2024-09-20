#include "soportes.h"


void repartir(tBolsa& bolsa, tSoportes& soportes) //funcion que reparte las fichas de la bolsa a los soportes de los jugadores
{
	tFicha ficha;
	iniSoporte(soportes);
	for (int i = 0; i < NumJugadores; i++) //va aumentando la i hasta el numero de jugadores
	{
		soportes[i].contador = 0; // inicializa los soportes en 0 fichas
		for (int j = 0; j < IniFichas; j++) //aumenta la j de 0 hasta el numero de fichas inciales que tiene cada jugador
		{
			ficha = robar(bolsa); //iguala las posiciones del soporte a la ficha aleatoria que te saca robar()
			nuevaFicha(ficha, soportes[i]);			 //aumenta en 1 el contador de fichas del soporte
		}

	}
}


	int menor(const tSoportes & soporte) //funcion que determina que soporte tiene menos fichas
	{
		int menor;
		menor = 0;
		for (int i = 0; i < NumJugadores - 1; i++)
		{
			if (soporte[i + 1].contador < soporte[i].contador)
				menor = i + 1;
			else if (soporte[i + 1].contador == soporte[i].contador)
			{
				menor = -2;
			}
		}
		return menor;
	}

	void iniSoporte(tSoportes& soportes)
	{
		for (int i = 0; i < NumJugadores; i++)
		{
			soportes[i].ptr_a_fichas = new tFicha[soportes[i].capacidad]; 
		}
	}

	void resize(tSoporte& soporte)
	{
		puntero_f nuevo_Reg = new tFicha[soporte.capacidad * 2];
		if (nuevo_Reg == nullptr)
		{
			cout << "insuficiente" << endl;
			exit(0);
		}
		else {
			for (int i = 0; i < soporte.contador; i++) {
				nuevo_Reg[i] = soporte.ptr_a_fichas[i];
			}
			soporte.capacidad *= 2;
			delete[] soporte.ptr_a_fichas;
			soporte.ptr_a_fichas = nuevo_Reg;
		}
	}

	void nuevaFicha(tFicha& ficha, tSoporte& soporte)
	{
		if (soporte.contador >= 8)
		{
			resize(soporte);
		}
		soporte.ptr_a_fichas[soporte.contador] = ficha;
		soporte.contador++;
	}

	void reduce(tSoporte& soporte)
	{
		puntero_f nuevo_Reg = new tFicha[soporte.capacidad - 4];
		if (nuevo_Reg == nullptr)
		{
			cout << "insuficiente" << endl;
			exit(0);
		}
		else {
			for (int i = 0; i < soporte.contador; i++) {
				nuevo_Reg[i] = soporte.ptr_a_fichas[i];
			}
			soporte.capacidad -= 4; 
			delete[] soporte.ptr_a_fichas; 
			soporte.ptr_a_fichas = nuevo_Reg; 
		}
	}

	void delSoporte(tSoportes& soportes)
	{
		for (int i = 0; i < NumJugadores; i++)
		{
			delete[] soportes[i].ptr_a_fichas;
			soportes[i].ptr_a_fichas = nullptr;
			soportes[i].contador = 0;
			soportes[i].capacidad = 0;
		}
	}