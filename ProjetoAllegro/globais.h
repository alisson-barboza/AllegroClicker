#ifndef VARIAVEIS_GLOBAIS
#define VARIAVEIS_GLOBAIS	

#include<allegro5\allegro.h>
#include <allegro5\allegro.h>
#include<allegro5\allegro_font.h>
#include<allegro5\allegro_ttf.h>
#include <allegro5\allegro_primitives.h>				
#include <allegro5\allegro_image.h>
#include<allegro5\allegro_audio.h>
#include<allegro5\allegro_acodec.h>

ALLEGRO_BITMAP * bitmapsFazenda[10];
ALLEGRO_FONT * font[4];
ALLEGRO_SAMPLE * sample[10];
ALLEGRO_SAMPLE_INSTANCE * sampleInstance[10];
ALLEGRO_BITMAP * bitmapsCanibal[10];
int smokeWidth;
int smokeHeight;

enum font{ midnight, cloning, kelam, bubblegum };
enum bitmapsCanibal{ Canibal, Padre, Jangada, BackGroundCanibal, Terco };
enum bitmapsFazenda{ Pescador, PescadorComOvelha, PescadorComLobo, PescadorComRepolho, Ovelha, Lobo, Repolho, Fumaca, BackGround, Carne };
enum retornodajogada { Vitoria, DerrotaLoboComOvelha, DerrotaOvelhaComRepolho, Derrota, NadaAconteceu, DerrotaEsquerda, DerrotaDireita };
enum sample{ MusicaDaFazenda, MusicaDoMenu, SomDaGalinha, Yay, VirarPagina, MordidaCanibal, VitoriaCanibalSong, MusicaDoCanibal };

int count;
int gambiarra;

#endif