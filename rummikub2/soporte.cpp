#include "soporte.h"

void mostrar(const tSoporte& soporte) //muestra soportes
{
	for (int i = 0; i < soporte.contador; i++) //muestra una por una las fichas del soporte 
	{
		mostrar(soporte.ptr_a_fichas[i]);
	}
	cout << endl;
}

void ordenarPorNum(tSoporte& soporte)//funcion que ordena los soportes por numeros
{
	tFicha aux;
	//ordenamos por el metodo de la burbuja
	for (int i = 0; i < soporte.contador - 1; i++)
	{
		for (int j = soporte.contador - 1; j > i; j--)
		{
			if (soporte.ptr_a_fichas[j].numeroFicha < soporte.ptr_a_fichas[j - 1].numeroFicha)
			{
				aux = soporte.ptr_a_fichas[j];
				soporte.ptr_a_fichas[j] = soporte.ptr_a_fichas[j - 1];
				soporte.ptr_a_fichas[j - 1] = aux;
			}
		}
	}
}

void ordenarPorColor(tSoporte& soporte)
{
	tFicha aux;
	ordenarPorNum(soporte); //ordenamos por num
	//volvemos a ordenar por el metodo de la burbuja
	for (int i = 0; i < soporte.contador - 1; i++) {
		for (int j = soporte.contador - 1; j > i; j--) {
			if (soporte.ptr_a_fichas[j].color < soporte.ptr_a_fichas[j - 1].color) {
				aux = soporte.ptr_a_fichas[j];
				soporte.ptr_a_fichas[j] = soporte.ptr_a_fichas[j - 1];
				soporte.ptr_a_fichas[j - 1] = aux;
			}
		}
	}
}



void mostrarSeries(const tSoporte& soporte) {

    tSoporte soporteTmp; //Copio el soporte en una variable temporal para no variar el soporte al ordenarlo abajo
    soporteTmp = soporte;

    int fichasIguales;
    int i, j, k;
    bool posibleSerie, cuartoRepiteColor;
    tFicha serieFicha[4]; // array donde almacenas la posible serie

    ordenarPorNum(soporteTmp);

    i = 0;
    do { //recorro el soporteTmp
        fichasIguales = 0;
        serieFicha[fichasIguales] = soporteTmp.ptr_a_fichas[i]; // almaceno la posible primera ficha;
        j = i + 1; // siguiente elemento al que comparo
        posibleSerie = false;
        cuartoRepiteColor = false;


        do { // recorro el soporteTmp hasta i + 3 como max (series tienen que ser mayores que 2 y maximo 4)
            if (soporteTmp.ptr_a_fichas[j].numeroFicha == soporteTmp.ptr_a_fichas[i].numeroFicha) { // si coinciden en el numero:
                k = i;
                posibleSerie = true;

                // compruebo que son colores distintos a los anteriores
                do {
                    if (soporteTmp.ptr_a_fichas[j].color == soporteTmp.ptr_a_fichas[k].color) {
                        if (fichasIguales == 2) {
                            cuartoRepiteColor = true; // Si encuentro un cuarto numero del mismo color tengo que ignorarlo xq ya tengo una serie formada x 3 fichas
                        }
                        else {
                            posibleSerie = false;
                        }
                    }
                    k++;
                } while (posibleSerie == true && k < j);

                if (posibleSerie && !cuartoRepiteColor) {
                    fichasIguales++;
                    serieFicha[fichasIguales] = soporteTmp.ptr_a_fichas[j];
                    j++;
                }
                else if (cuartoRepiteColor) {
                    j++; // cuando tenemos 4 iguales y ha fallado el color del 4to, incremento j para salirme del while y parar de comparar ese numero
                }
            }
            else {
                if (fichasIguales < 2) { // aunq el 4to sea distinto si tenemos ya 3 iguales la serie es posible
                    posibleSerie = false;
                }
                else {
                    j++; // cuando tenemos 3 iguales y ha fallado el 4to incremento j para salirme del while
                }
            }
        } while (posibleSerie == true && j != soporteTmp.contador && (j - i) < 4); // (j - i) longitud de la serie

        if (!posibleSerie) {
            i++;
        }
        else {
            mostrar(serieFicha[0]);
            mostrar(serieFicha[1]);
            mostrar(serieFicha[2]);
            if (fichasIguales == 3) { // si son 4 iguales
                mostrar(serieFicha[3]);
            }
            cout << endl;
            i = i + fichasIguales;
            posibleSerie = false; // me busque otra serie
        }

    } while (i < soporteTmp.contador - 2); // Siempre tienes que tener como minimo dos fichas mas a la dcha para formar una serie
}

void mostrarEscaleras(const tSoporte& soporte) {
    tSoporte soporteTmp; //Copio el soporte en una variable temporal para no variar el soporte al ordenarlo abajo
    soporteTmp = soporte;
    int fichasConsec = 0;
    bool posibleEsc;
    tFicha escaleraFicha[13];


    ordenarPorColor(soporteTmp);

    escaleraFicha[fichasConsec] = soporteTmp.ptr_a_fichas[0];

    for (int i = 0; i < soporteTmp.contador - 1; i++) { // pongo hasta el contador - 1 para no pasarme del contador al hacer i + 1
        if ((((soporteTmp.ptr_a_fichas[i + 1].numeroFicha) - (soporteTmp.ptr_a_fichas[i].numeroFicha)) == 1) && soporteTmp.ptr_a_fichas[i + 1].color == soporteTmp.ptr_a_fichas[i].color) {
            fichasConsec++;
            posibleEsc = true;
            escaleraFicha[fichasConsec] = soporteTmp.ptr_a_fichas[i + 1];
        }
        else {
            if (fichasConsec >= 2) {
                for (int j = 0; j <= fichasConsec; j++) {
                    mostrar(escaleraFicha[j]);
                }
                cout << endl;
            }
            else {
                posibleEsc = false;
            }
            fichasConsec = 0;
            escaleraFicha[fichasConsec] = soporteTmp.ptr_a_fichas[i + 1]; // para volver a empezar
        }
    }
}

void eliminaFichas(tSoporte& soporte, const tJugada& jugada)//funcion que elimina una ficha del soporte
{
	for (int j = 0; j < jugada.fichas_jugada; j++)//recorro las fichas de la jugada
	{
		for (int i = 0; i < soporte.contador; i++)//recorro el soprote
		{
			//comparo cada ficha con cada una de las fichas del soporte, si son iguales, entonces la eliminaré recorriendo los elementos siguientes a la izquierda
			if (jugada.ArrayJugada[j].numeroFicha == soporte.ptr_a_fichas[i].numeroFicha && jugada.ArrayJugada[j].color == soporte.ptr_a_fichas[i].color)
			{
				for (int w = i; w < soporte.contador; w++)
				{
					soporte.ptr_a_fichas[w] = soporte.ptr_a_fichas[w + 1];
				}soporte.contador--;

			}
		}
	}
}


void nuevaJugada(tSoporte& soporte, tJugada& jugada)//crear una nueva jugada
{
	int choosed_ficha;
	int ArrayAux[MAXFICHAS];
	iniJugada(jugada);
	for (int i = 0; i < MAXFICHAS; i++)//incializo un array auxiliar a 0
	{
		ArrayAux[i] = 0;
	}
	jugada.fichas_jugada = 0;
	for (int i = 0; i < soporte.contador; i++)//muestro los indices de las fichas del soporte
	{
		cout << setw(3) << i + 1 << "  ";

	}
	cout << endl;
	mostrar(soporte);

	cout << "ficha a introducir (terminar = 0) : ";
	do
	{

		cin >> choosed_ficha;
		if (choosed_ficha != 0 && ArrayAux[choosed_ficha - 1] != 1 && choosed_ficha <= soporte.contador && jugada.fichas_jugada <= MAXFICHAS)
		{
			ArrayAux[choosed_ficha - 1] = 1; //indica que esa posicon ya se ha elegido
			jugada.ArrayJugada[jugada.fichas_jugada] = soporte.ptr_a_fichas[choosed_ficha - 1]; //mete la ficha indicada dentro de la jugada
			jugada.fichas_jugada++;
		}
		else if (ArrayAux[choosed_ficha - 1] == 1) //si esa posicon del array tiene un 1 significa que ya has elegido esa ficha
		{
			cout << "Esta ficha ya la has elegido " << endl;
			cout << "ficha a introducir (terminar = 0) : ";
		}
	} while (choosed_ficha != 0);

	cout << "Jugada: ";
	mostrar(jugada); //muestra la jugada final
	cout << endl;
}