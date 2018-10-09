#include"fazendaTypes.h"
#include"globais.h"

void iniciarVariaveis(Tovelha * ovelhaStruct, Tlobo * loboStruct, Trepolho *repolhoStruct, Tpescador * pescadorStruct);
void desenharPlano(Tovelha ovelhaStruct, Tlobo loboStruct, Tpescador pescadorStruct, Trepolho repolhoStruct, int modoDaDerrota);
void fazerAnimacoes(Tovelha * ovelhaStruct, Tlobo * loboStruct, Tpescador * pescadorStruct, Trepolho * repolhoStruct);
int calcularClick(int pos_x, int pos_y, Tovelha ovelhaStruct, Tlobo loboStruct, Tpescador pescadorStruct, Trepolho repolhoStruct);
int checarJogada(Tovelha * ovelhaStruct, Tlobo * loboStruct, Trepolho *repolhoStruct, Tpescador * pescadorStruct);
void moverImagem(Tovelha * ovelhaStruct, Tlobo * loboStruct, Tpescador * pescadorStruct, Trepolho * repolhoStruct, int click);
void declararDerrota(Tovelha * ovelhaStruct, Tlobo * loboStruct, Trepolho *repolhoStruct, Tpescador * pescadorStruct, int modoDaDerrota);
bool checarClick(int x, int y);
bool inicializarFazenda(Tovelha * ovelhaStruct, Tlobo * loboStruct, Trepolho *repolhoStruct, Tpescador * pescadorStruct);
void declararVitoria(Tovelha * ovelhaStruct, Tlobo * loboStruct, Trepolho *repolhoStruct, Tpescador * pescadorStruct);
void derrotaFazenda(Tovelha *ovelhaStruct, Tlobo * loboStruct, Tpescador *pescadorStruct, Trepolho *repolhoStruct, int modoDaDerrota);
void vitoriaFazenda(Tovelha ovelhaStruct, Tlobo loboStruct, Tpescador pescadorStruct, Trepolho repolhoStruct);