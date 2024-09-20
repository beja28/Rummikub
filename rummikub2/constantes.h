#ifndef constantes_h
#define constantes_h

//CONSTANTES
const int NumJugadores = 2;
const int NumFichas = 13;
const int IniFichas = 14;
const int MAXFICHAS = 50;
const int MAXJUGADAS = MAXFICHAS * 2;

typedef struct {
	int arrayJugadores[NumJugadores];
	int contJ;
}tNumJugadores;


typedef struct {
	int arrayFichas[NumFichas];
	int contF;
}tNumFichs;



typedef struct {
	int arrayIniFichas[IniFichas];
	int contIniF;
}tIniFichas;


typedef int tArrayMaxFichas[MAXFICHAS];

#endif contantes_h