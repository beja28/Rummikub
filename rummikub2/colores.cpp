#include "Colores.h"

void colorTexto(tColor color) //funcion determinar color
{
	switch (color) {
	case AMARILLO:
		cout << "\033[1;40;33m";
		break;
	case AZUL:
		cout << "\033[40;34m";
		break;
	case ROJO:
		cout << "\033[40;31m";
		break;
	case VERDE:
		cout << "\033[40;32m";
		break;
	case BLANCO:
		cout << "\033[40;37m";
		break;
	}
}



