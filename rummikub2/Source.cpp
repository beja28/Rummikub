//ALEJANDRO BEJARANO DEL CASTILLO Y FERNANDO GUZMÁN MUÑOZ: 1º A

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <time.h>

#include "tablero.h"
#include "bolsa.h"
#include "soporte.h"
#include "soportes.h"
#include "Colores.h"
#include "Fichas.h"
#include "constantes.h"
#include "jugadas.h"

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <cstdlib>
using namespace std;



//TIPOS






























//FUNCIONES





int menu();
void TITULO();

int main() {
	srand(time(NULL));
	int opcion;
	bool juego;
	bool hay_jugada = false;
	bool hayGanador = false;
	int contador_pasar = 0;
	tBolsa bolsa;
	tFicha ficha;
	tFicha ficha_robada;
	tSoportes soportes;
	tJugada jugada;
	tTablero tablero;
	tablero.cont_jugadas = 0;
	int i = rand() % NumJugadores;

	int ganador = -1;
	cout << endl;
	TITULO();
	cout << "        Numero de Jugadores: " << NumJugadores << endl;
	inicializarBolsa(bolsa);
	repartir(bolsa, soportes);
	cout << endl;
	cout << "Empieza a jugar el jugador: " << i + 1 << endl;
	cout << endl;
	bool acabar = false;

	while (ganador == -1 && i < NumJugadores && !acabar )
	{

		hay_jugada = false;
		cout << "Turno del jugador " << i + 1 << endl;
		cout << endl;
		cout << "Tablero: " << endl;
		mostrar(tablero);


		cout << endl;
		cout << endl;
		do
		{
			cout << "Soporte : ";
			mostrar(soportes[i]);
			cout << endl;
			opcion = menu();
			switch (opcion)
			{
			case 1: ordenarPorNum(soportes[i]);
				break;
			case 2: ordenarPorColor(soportes[i]);
				break;
			case 3: mostrarEscaleras(soportes[i]);
				mostrarSeries(soportes[i]);
				break;
			case 4: juego = jugar(tablero, soportes[i]);
				if (juego)
				{
					hay_jugada = true;
					contador_pasar = 0;
				}
				break;
			case 5:
			{
				if (hay_jugada == false && soportes[i].contador < MAXFICHAS && bolsa.fichas_disp >0)
				{
					ficha_robada = robar(bolsa);
					if (ficha_robada.numeroFicha != -1)
					{
						soportes[i].ptr_a_fichas[soportes[i].contador] = ficha_robada;
						soportes[i].contador++;
					}
					else cout << "La bolsa a sacado un -1" << endl;

				}
				if (bolsa.fichas_disp == 0 && hay_jugada == false) // aumento un contador cada vez que los jugadores pasen y la bolsa no tenga fichas
				{
					contador_pasar++;
				}
				break;
			}
			case 0:
			{
				acabar = true;
			}
			
			}
			if (soportes[i].contador == 0)
			{
				ganador = i; // si un soporte se queda sin fichas ese es el que gana
				opcion = 0; //cambio a 0 la opcion para que no vuelva a preguntar el menu de opciones
			}
			if (contador_pasar == NumJugadores) // si han pasado todos los jugadores con la bolsa vacia llama a menor
			{
				ganador = menor(soportes); //determina el jugador con menos fichas
				hayGanador = true;
			}


		} while (opcion != 5 && opcion != 0); //se va a repetir hasta que el jugador lo pulse 0

		if (ganador == -1) //si no hay ganador aún, aumenta la i (pasa al siguiente jugador)
		{
			i++;
			if (i == NumJugadores) //llega al ultimo jugador y sigue sin haber ganador, pasa al jugador 1
			{
				i = 0;
			}
		}
		else if (ganador != -1) //si hay ganador igualo i a NumJugadores para que salga del while principal
		{
			i = NumJugadores;
		}

	}
	if (!acabar)
	{
		if (ganador != -1 && ganador != -2)
		{
			cout << "FIN DE LA PARTIDA" << endl;
			cout << "GANADOR : JUGADOR " << ganador + 1;
		}
		else if (ganador == -2)
		{
			cout << "EMPATE";
		}
	}
	delBolsa(bolsa);
	delSoporte(soportes);
	delTablero(tablero);

	_CrtDumpMemoryLeaks();
	return 0;
}

int menu() { //funcion menu
	int  numero;
	cout << "1: Ordenar por num., 2: Ordenar por color, 3: Sugerir, 4: Poner, 5: Sig, 0: Fin>>> ";
	cin >> numero;

	while (numero < 0 || numero >5) { //si no metes una opcion del 0 al 4 te dice que esta mal
		cout << "Opcion incorrecta, vuelva a introducir: " << endl;
		cout << "1: Ordenar por num., 2: Ordenar por color, 3: Sugerir, 4: Poner, 5: Sig, 0: Fin>>> ";
		cin >> numero;
	}
	cout << endl;
	return numero;
}

void TITULO()
{
	colorTexto(AMARILLO);
	cout << "      ______     __  __     __    __     __    __     __     __  __     __  __     ______    " << endl;
	cout << "     /\\  == \\   /\\ \\/\\ \\   /\\ "" -. / \\   /\\  ""-./  \\   /\\ \\   /\\ \\/ /    /\\ \\/\\ \\   /\\  == \\   " << endl;
	cout << "     \\ \\  __<   \\ \\ \\_\\ \\  \\ \\ \\-./\\ \\  \\ \\ \\-./\\ \\  \\ \\ \\  \\ \\  _""- .  \\ \\ \\_\\ \\  \\ \\  __ < " << endl;
	cout << "      \\ \\_\\ \\_\\  \\ \\_____\\  \\ \\_\\ \\ \\_\\  \\ \\_\\ \\ \\_\\  \\ \\_\\  \\ \\_\\ \\_\\  \\ \\_____\\  \\ \\_____\\ " << endl;
	cout << "       \\/_/ /_/   \\/_____/   \\/_/  \\/_/   \\/_/  \\/_/   \\/_/   \\/_/\\/_/   \\/_____/   \\/_____/ " << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	colorTexto(BLANCO);
}