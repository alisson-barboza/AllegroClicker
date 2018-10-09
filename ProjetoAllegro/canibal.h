#include"canibalTypes.h"


bool inicializarCanibal(Tcanibal1 * canibal1, Tcanibal2 * canibal2, Tcanibal3 * canibal3, Tpastor1 * pastor1, Tpastor2 * pastor2, Tpastor3 * pastor3, Tjangada * jangada);
void iniciarVariaveisCanibais(Tcanibal1 * canibal1, Tcanibal2 * canibal2, Tcanibal3 * canibal3, Tpastor1 * pastor1, Tpastor2 * pastor2, Tpastor3 * pastor3, Tjangada * jangada);
void desenharPlanoCanibal(Tcanibal1 canibal1, Tcanibal2 canibal2, Tcanibal3 canibal3, Tpastor1 pastor1, Tpastor2 pastor2, Tpastor3 pastor3, Tjangada jangada, int modoDaDerrota);
int calcularClickCanibal(Tcanibal1 canibal1, Tcanibal2 canibal2, Tcanibal3 canibal3, Tpastor1 pastor1, Tpastor2 pastor2, Tpastor3 pastor3, Tjangada jangada, int x, int y);
void moverImagensCanibal(Tcanibal1 * canibal1, Tcanibal2 * canibal2, Tcanibal3 * canibal3, Tpastor1 * pastor1, Tpastor2 * pastor2, Tpastor3 * pastor3, Tjangada * jangada, int click);
void fazerAnimacoesCanibal(Tcanibal1 * canibal1, Tcanibal2 * canibal2, Tcanibal3 * canibal3, Tpastor1 * pastor1, Tpastor2 * pastor2, Tpastor3 * pastor3, Tjangada * jangada);
int checarJogadaCanibal(Tcanibal1 canibal1, Tcanibal2 canibal2, Tcanibal3 canibal3, Tpastor1 pastor1, Tpastor2 pastor2, Tpastor3 pastor3);
void desenharVitoriaCanibal(Tcanibal1 canibal1, Tcanibal2 canibal2, Tcanibal3 canibal3, Tpastor1 pastor1, Tpastor2 pastor2, Tpastor3 pastor3, Tjangada jangada);
void desenharDerrotaCanibal(Tcanibal1 canibal1, Tcanibal2 canibal2, Tcanibal3 canibal3, Tpastor1 pastor1, Tpastor2 pastor2, Tpastor3 pastor3, Tjangada jangada);