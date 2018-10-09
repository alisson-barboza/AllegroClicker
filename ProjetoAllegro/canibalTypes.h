#ifndef ESTRUTURA_CANIBAL
#define ESTRUTURA_CANIBAL
#include"globais.h"

typedef struct Tcanibal1{

	int lado;
	int x, y;
	int width, height;
	bool animando;
	int limiteX, limiteY;
	bool naJangada;
	int vagaOcupada;

}Tcanibal1;

typedef struct Tcanibal2{

	int lado;
	int x, y;
	int width, height;
	bool animando;
	int limiteX, limiteY;
	bool naJangada;
	int vagaOcupada;

}Tcanibal2;

typedef struct Tcanibal3{

	int lado;
	int x, y;
	int width, height;
	bool animando;
	int limiteX, limiteY;
	bool naJangada;
	int vagaOcupada;

}Tcanibal3;

typedef struct Tpastor1{

	int lado;
	int x, y;
	int width, height;
	bool animando;
	int limiteX, limiteY;
	bool naJangada;
	int vagaOcupada;

}Tpastor1;

typedef struct Tpastor2{

	int lado;
	int x, y;
	int width, height;
	bool animando;
	int limiteX, limiteY;
	bool naJangada;
	int vagaOcupada;

}Tpastor2;

typedef struct Tpastor3{

	int lado;
	int x, y;
	int width, height;
	bool animando;
	int limiteX, limiteY;
	bool naJangada;
	int vagaOcupada; 

}Tpastor3;

typedef struct Tjangada{

	int lado;
	int x, y;
	int width, height;
	bool animando;
	int limiteX, limiteY;	
	bool vaga1Ocupada, vaga2Ocupada;
	int objeto1, objeto2;

}Tjangada;

enum RetornoDoClick{ ClickCanibal1, ClickCanibal2, ClickCanibal3, ClickPastor1, ClickPastor2, ClickPastor3, ClickJangada };
enum VagasOcupadas{ Nenhuma, Vaga1, Vaga2 };
enum Objetos{Nenhum, Canibal1, Canibal2, Canibal3, Pastor1, Pastor2, Pastor3};//Saber quem está na jangada para mover o objeto junto

#endif