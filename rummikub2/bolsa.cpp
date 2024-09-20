#include "bolsa.h"

void inicializarBolsa(tBolsa& bolsa) //llena la bolsa de todas las fichas
{
	for (int i = 0; i < 8; i++) //recorre las filas (4 colores repetidos dos veces)
	{
		for (int j = 0; j < NumFichas; j++) //recorre el numero de fichas de cada serie de color
		{
			bolsa.matriz_bidimensional[i][j] = new tFicha;
			bolsa.matriz_bidimensional[i][j]->numeroFicha = j + 1;
			if (i < 4) //si la i es 0,1,2,3 va progresivamente cambiando de color
				bolsa.matriz_bidimensional[i][j]->color = tColor(i);
			else // si pasa de 3 vuelve a comenzar por el color 0
			{
				bolsa.matriz_bidimensional[i][j]->color = tColor(i - 4);
			}

		}
	}
}
tFicha robar(tBolsa& bolsa) //funcion para robar una ficha
{
	int fila, f_aleatoria;
	int columna, c_aleatoria;
	f_aleatoria = rand() % 8;
	c_aleatoria = rand() % NumFichas;
	fila = f_aleatoria;
	columna = c_aleatoria;
	tFicha ficha;
	ficha.color = LIBRE;
	ficha.numeroFicha = -1;
	bool hay_ficha = false;
	//recorro la bolsa desde la ficha que he sacado aleatoriamente hasta el final
	while (hay_ficha == false && fila < 8)
	{
		while (columna < NumFichas && hay_ficha == false)
		{

			if (bolsa.matriz_bidimensional[fila][columna] != nullptr)//si encuentra una ficha 
			{

				ficha = *bolsa.matriz_bidimensional[fila][columna];
				bolsa.fichas_disp--;
				//esa ficha se vuelve un espacio dentro de la bolsa
				delete bolsa.matriz_bidimensional[fila][columna];
				bolsa.matriz_bidimensional[fila][columna] = nullptr;
				
				hay_ficha = true;
				 //quito una ficha del contador de la bolsa
			}
			else
				columna++;
		}
		fila++;
		columna = 0;
	}
	//aqui llega al final de la matriz, por tanto tengo que empezar desde 0.
	if (hay_ficha == false)
	{
		fila = 0;
		columna = 0;
		while (hay_ficha == false && fila < 8)
		{
			while (columna < NumFichas && hay_ficha == false)
			{
				if (bolsa.matriz_bidimensional[fila][columna] != nullptr)
				{
					//hago lo mismo que antes
					ficha = *bolsa.matriz_bidimensional[fila][columna];
					delete bolsa.matriz_bidimensional[fila][columna];
					bolsa.matriz_bidimensional[fila][columna] = nullptr;
					
					bolsa.fichas_disp--;
					hay_ficha = true;
				}
				else
				{
					if (fila == f_aleatoria && columna == c_aleatoria) //si llega a la posicion del principio, deja de buscar, devolverá un espacio
					{
						hay_ficha = true;
					}
					columna++;
				}
			}
			fila++;
			columna = 0;
		}
	}

	return ficha;
}




void mostrar(const tBolsa& bolsa) //muestra la bolsa
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < NumFichas; j++)
		{

			if (bolsa.matriz_bidimensional[i][j] == nullptr)// si hay un hueco lo pone de color blanco
			{
				colorTexto(BLANCO),
					cout << setw(3) << " -1  ";
			}
			else
			{
				colorTexto(bolsa.matriz_bidimensional[i][j]->color);
				cout << setw(3) << bolsa.matriz_bidimensional[i][j]->numeroFicha << "  ";

			}
			colorTexto(BLANCO);
		}
		cout << endl;
	}
}

void delBolsa(tBolsa& bolsa)
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < bolsa.ini_fichas; j++) {
			if (bolsa.matriz_bidimensional[i][j] != nullptr) {
				delete bolsa.matriz_bidimensional[i][j];
			}
		}
	}
}