#include "tablero.h"


void mostrar(const tTablero& tablero) //muestra el tablero
{
	if (tablero.cont_jugadas == 0) {
		cout << "No hay jugadas" << endl;
	}
	for (int i = 0; i < tablero.cont_jugadas; i++) {
		cout << i + 1 << ": ";
		mostrar(*tablero.arrayJugadas[i]);
		cout << endl;
	}
}

bool jugar(tTablero& tablero, tSoporte& soporte)//funcion que conlleva el juego
{
	tTablero auxTablero;
	tJugada jugada;
	bool es_serie;
	bool es_escalera;
	nuevaJugada(soporte, jugada);
	int jugada_colocar;;
	bool posible = false;
	int cont_posibles = 0;
	int indices_posibles[MAXJUGADAS];
	bool hay_jugada = false;

	tablero.arrayJugadas[tablero.cont_jugadas] = new tJugada[MAXJUGADAS];

	for (int i = 0; i < tablero.cont_jugadas; i++)
	{
		auxTablero.arrayJugadas[i] = new tJugada;
		auxTablero.arrayJugadas[i]->ArrayJugada = new tFicha[NumFichas + 1];
		for (int j = 0; j < tablero.arrayJugadas[i]->fichas_jugada; j++)
		{
			auxTablero.arrayJugadas[i]->ArrayJugada[j] = tablero.arrayJugadas[i]->ArrayJugada[j];
		}
		auxTablero.arrayJugadas[i]->fichas_jugada = tablero.arrayJugadas[i]->fichas_jugada;
	}
	auxTablero.cont_jugadas = tablero.cont_jugadas;



	if (jugada.fichas_jugada == 1) //si solo se ha elegido una ficha
	{

		for (int i = 0; i < tablero.cont_jugadas; i++) //recorre las jugadas del tablero
		{
			posible = ponerFicha(*auxTablero.arrayJugadas[i], jugada.ArrayJugada[0]); //aqui llamo a ponerficha para comprobar si se pueden poner en cada jugada
			if (posible == true)
			{
				hay_jugada = true;
				indices_posibles[cont_posibles] = i;
				cont_posibles++; //aqui aumento un contador para saber en cuantas posibles jugadas se puede meter esa funcion
			}
		}
		if (hay_jugada == false) //si no se ha conseguido ninguna posible jugada muestra que no se puede
		{
			cout << "No es posible colocar la ficha" << endl;
		}
		else if (hay_jugada == true) //si si que hay posible, divide en si se han podido en una jugada o en varias
		{
			cout << "Jugadas del tablero donde poner la ficha: ";
			for (int j = 0; j < cont_posibles; j++)
			{
				cout << indices_posibles[j] + 1 << " "; //muestra las jugadas donde se puede poner la ficha
			}
			if (cont_posibles == 1) // si solo se puede meter en una
			{
				meterFicha(indices_posibles[0], tablero, jugada); //llama a la funcion meter ficha en esa unica jugada
			}
			else if (cont_posibles > 1) //si hay mas de una jugada posible deja al jugador elegir la jugada
			{
				bool jugada_correcta = false;

				cout << endl;
				cout << "Elige la jugada: ";
				cin >> jugada_colocar;
				meterFicha(jugada_colocar - 1, tablero, jugada); //introduce la ficha dentro de la jugada que ha eleigido el jugador

			}
			eliminaFichas(soporte, jugada); //elimina la ficha que se ha elegido
		}
	}
	else if (jugada.fichas_jugada >= 3) // si la jugada tiene 3 fichas o más
	{
		//comprueba si es una serie o una escalera
		es_serie = serie(jugada);
		es_escalera = escalera(jugada);
		if (tablero.cont_jugadas < MAXJUGADAS)
		{
			if (es_serie == true || es_escalera == true) //si es una cierta de las dos
			{
				hay_jugada = true;
				*tablero.arrayJugadas[tablero.cont_jugadas] = jugada; //introduce en la ultima posicion del tablero esa jugada
				tablero.cont_jugadas++;
				eliminaFichas(soporte, jugada); //elimina las fichas de la jugada del soporte del jugador que las ha colocado
				//indica que la serie o la escalera es correcta dependiendo de lo que sea
				if (es_serie)
					cout << "  Serie correcta!" << endl;
				else if (es_escalera)
				{
					cout << "  Escalera correcta!" << endl;
				}
			}
			else //si no es serie o escalera te dice que no se puede introducir
			{
				hay_jugada = false;
				cout << "No es posible introducir " << endl;
			}
		}
		else
		{
			cout << "No caben mas jugadas en el tablero" << endl;
		}

	}
	else if (jugada.fichas_jugada == 2 || jugada.fichas_jugada == 0) //si la jugada tiene 2 o 0 fichas no se puede
	{
		posible = false;
		cout << "no es posible introducir" << endl;
	}
	cout << endl;
	//muestro el tablero
	cout << "Tablero" << endl;
	mostrar(tablero);
	return hay_jugada;

}





void meterFicha(int Indice, tTablero& tablero, tJugada jugada)
{
	bool es_serie, es_escalera;
	es_serie = serie(*tablero.arrayJugadas[Indice]);		//indices_posibles[0], Z
	es_escalera = serie(*tablero.arrayJugadas[Indice]);
	if (es_serie == true)
	{
		tablero.arrayJugadas[Indice]->fichas_jugada++;
		tablero.arrayJugadas[Indice]->ArrayJugada[tablero.arrayJugadas[Indice]->fichas_jugada - 1] = jugada.ArrayJugada[0];
	}
	else
	{
		if (jugada.ArrayJugada[0].numeroFicha < tablero.arrayJugadas[Indice]->ArrayJugada[0].numeroFicha)
		{
			tablero.arrayJugadas[Indice]->fichas_jugada++;
			for (int i = tablero.arrayJugadas[Indice]->fichas_jugada - 1; i >= 0; i--) //abro un hueco a la derecha del todo y voy metiendo el valor de [i] en [i+1]
			{
				tablero.arrayJugadas[Indice]->ArrayJugada[i] = tablero.arrayJugadas[Indice]->ArrayJugada[i - 1];

			}
			tablero.arrayJugadas[Indice]->ArrayJugada[0] = jugada.ArrayJugada[0]; //el primer valor que se ha quedado vacio ahí meto la ficha;
		}
		else if (jugada.ArrayJugada[0].numeroFicha > tablero.arrayJugadas[Indice]->ArrayJugada[tablero.arrayJugadas[Indice]->fichas_jugada - 1].numeroFicha)
		{
			tablero.arrayJugadas[Indice]->fichas_jugada++; //abro una nueva posicion
			tablero.arrayJugadas[Indice]->ArrayJugada[tablero.arrayJugadas[Indice]->fichas_jugada - 1] = jugada.ArrayJugada[0]; //meto en la nueva posicion la ficha
		}
	}

	cout << "  -> Colocada!" << endl;
}

void delTablero(tTablero& tablero)
{
	for (int i = 0; i < tablero.cont_jugadas; i++)
	{
		delete[] tablero.arrayJugadas[i];
		tablero.arrayJugadas[i] = nullptr;
		tablero.cont_jugadas = 0;
	}
}