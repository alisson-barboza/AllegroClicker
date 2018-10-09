#ifndef FAZENDA_TYPES
#define FAZENDA_TYPES
#include<allegro5\allegro.h>

typedef struct ovelha{

	int x, y;
	int limiteX, limiteY;
	bool withPescador;
	int lado; //0 esquerda -- 1 direita
	int height, width;
	bool animando;

}Tovelha;

typedef struct lobo{

	int x, y;
	int limiteX, limiteY;
	bool withPescador;
	int lado; //0 esquerda -- 1 direita
	int height, width;
	bool animando;

}Tlobo;

typedef struct repolho{

	int x, y;
	int limiteX, limiteY;
	bool withPescador;
	int lado; //0 esquerda -- 1 direita
	int height, width;

}Trepolho;

typedef struct pescador{

	bool full;
	int lado; //0 esquerda -- 1 direita
	int x, y;
	int limiteX, limiteY;
	int objeto; //0 vazio - 1 ovelha - 2 lobo - 3 couve
	int height, width;
	bool animando;

}Tpescador;






#endif