#include<stdio.h>
#include<stdlib.h>
#include"fazenda.h"
#include"arquivo.h"
#include"canibal.h"
//========================================
//LEMBRETE: NOMES QUE COMEÇAM COM LETRA MAIUSCULA SAO ENUMS
//========================================

ALLEGRO_DISPLAY	* display = NULL;
ALLEGRO_BITMAP * bitmapsMenu[7] = { NULL };
ALLEGRO_EVENT_QUEUE	* event_queueMain = NULL;
ALLEGRO_TIMER * timer = NULL;

enum bitmapsMenu{ PlanoDeFundoFazenda, InstrucoesFazenda, SetaDireita, EmConstrucao, SetaEsquerda, PlanoDeFundoCanibal, InstrucoesCanibal };
//enum modoDoJogo{ Menu, Scores, JogoDaFazenda, DerrotaFazenda, VitoriaFazenda, SalvarResultado, JogoDosCanibais, VitoriaCanibal, DerrotaCanibalTeste };
enum modoDoJogo{ JogoDosCanibais, VitoriaCanibal, DerrotaCanibalTeste, Menu, Scores, JogoDaFazenda, DerrotaFazenda, VitoriaFazenda, SalvarResultado, Arquivos };
void desenharMenu(int x, int y, int jogo);
bool inicializar();
FILE * criar_Arquivo(char nome[]);

int main(){
	FILE * fazendaArq, * canibalArq;
	char nome[20];
	int x = 0, y = 0;
	int jogo = 0;
	bool done = false;
	int modoDoJogo = Menu;
	bool desenhar = true;
	int retornoDoClick = 4;
	int retornoDaJogada = NadaAconteceu;
	//========================================
	//VARIAVEIS DO JOGO DA FAZENDA
	//========================================
	Tovelha ovelhaStruct;
	Tlobo loboStruct;
	Tpescador pescadorStruct;
	Trepolho repolhoStruct;
	//========================================
	//VARIAVEIS DO JOGO DOS CANIBAIS
	//========================================
	Tcanibal1 canibal1;
	Tcanibal2 canibal2;
	Tcanibal3 canibal3;

	Tpastor1 pastor1;
	Tpastor2 pastor2;
	Tpastor3 pastor3;

	Tjangada jangada;

	strcpy(nome, "");

	fazendaArq = criar_Arquivo("fazenda.dat");
	canibalArq = criar_Arquivo("canibal.dat");

	if (!inicializar()){
		return -1;
	}
	inicializarFazenda(&ovelhaStruct, &loboStruct, &repolhoStruct, &pescadorStruct);
	inicializarCanibal(&canibal1, &canibal2, &canibal3, &pastor1, &pastor2, &pastor3, &jangada);
	al_play_sample_instance(sampleInstance[MusicaDoMenu]);

	al_start_timer(timer);

	while (!done){
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queueMain, &ev);
		//========================================
		//MENU
		//========================================
		if (modoDoJogo == Menu){
			if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
				if (ev.mouse.button & 1){
					
					if (jogo == 0){
						if ((x >= 350 && x <= 450) && (y >= 500 && y <= 530)){
							count = 0;
							modoDoJogo = JogoDaFazenda;
							retornoDaJogada = NadaAconteceu;
							iniciarVariaveis(&ovelhaStruct, &loboStruct, &repolhoStruct, &pescadorStruct);
							al_stop_sample_instance(sampleInstance[MusicaDoMenu]);
							al_play_sample_instance(sampleInstance[MusicaDaFazenda]);
							al_play_sample_instance(sampleInstance[SomDaGalinha]);
						}
						else if ((x >= 750 && x <= 800) && (y >= 300 && y <= 400)){
							al_play_sample_instance(sampleInstance[VirarPagina]);
							jogo = 1;
						}
						else if ((x >= 340 && x <= 458) && (y >= 554 && y <= 581)){
							modoDoJogo = Arquivos;
							lerArquivo(fazendaArq);
						}
					}
					else{
						if ((x >= 350 && x <= 450) && (y >= 500 && y <= 530)){
							al_stop_sample_instance(sampleInstance[MusicaDoMenu]);
							al_play_sample_instance(sampleInstance[MusicaDoCanibal]);
							modoDoJogo = JogoDosCanibais;
							count = 0;
							retornoDaJogada = NadaAconteceu;
							iniciarVariaveisCanibais(&canibal1, &canibal2, &canibal3, &pastor1, &pastor2, &pastor3, &jangada);
						}
						else if ((x >= 0 && x <= 50) && (y >= 300 && y <= 400)){
							jogo = 0;
							al_play_sample_instance(sampleInstance[VirarPagina]);
						}
						else if ((x >= 340 && x <= 458) && (y >= 554 && y <= 581)){
							modoDoJogo = Arquivos;
							lerArquivo(canibalArq);
						}
					}
				}
			}
			else if (ev.type == ALLEGRO_EVENT_MOUSE_AXES){
				x = ev.mouse.x;
				y = ev.mouse.y;
			}
			else if (ev.type == ALLEGRO_EVENT_KEY_DOWN){
				switch (ev.keyboard.keycode){
				case ALLEGRO_KEY_ESCAPE:
					done = true;
				}
			}
			else if (ev.type == ALLEGRO_EVENT_TIMER){
				desenhar = true;
			}
		}
		//========================================
		//JOGO DA FAZENDA
		//========================================
		else if (modoDoJogo == JogoDaFazenda){
			if (ev.type == ALLEGRO_EVENT_KEY_DOWN){
				switch (ev.keyboard.keycode){
				case ALLEGRO_KEY_ESCAPE:
					modoDoJogo = Menu;
					al_stop_sample_instance(sampleInstance[MusicaDaFazenda]);
					al_play_sample_instance(sampleInstance[MusicaDoMenu]);
					break;
				}
			}
			else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
				if (ev.mouse.button & 1){
					retornoDoClick = calcularClick(ev.mouse.x, ev.mouse.y, ovelhaStruct, loboStruct, pescadorStruct, repolhoStruct);
					moverImagem(&ovelhaStruct, &loboStruct, &pescadorStruct, &repolhoStruct, retornoDoClick);
				
				}
			}
			else if (ev.type == ALLEGRO_EVENT_TIMER){
				count++;
				desenhar = true;
			}
		}
		//========================================
		//JOGO DOS CANIBAIS
		//========================================
		else if (modoDoJogo == JogoDosCanibais){			
			if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
				if (ev.mouse.button & 1){					
					retornoDoClick = calcularClickCanibal(canibal1, canibal2, canibal3, pastor1, pastor2, pastor3, jangada, ev.mouse.x, ev.mouse.y);
					moverImagensCanibal(&canibal1, &canibal2, &canibal3, &pastor1, &pastor2, &pastor3, &jangada, retornoDoClick);
				}
			}
			else if (ev.type == ALLEGRO_EVENT_KEY_DOWN){
				if (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE){
					al_stop_sample_instance(sampleInstance[MusicaDoCanibal]);
					al_play_sample_instance(sampleInstance[MusicaDoMenu]);
					modoDoJogo = Menu;
				}
			}
			else if (ev.type == ALLEGRO_EVENT_TIMER){
				desenhar = true;
				count++;
			}
		}
		//========================================
		//CASO O JOGADOR GANHE NO JOGO DOS CANIBAIS
		//========================================
		else if (modoDoJogo == VitoriaCanibal){
			if (ev.type == ALLEGRO_EVENT_KEY_DOWN){
				switch (ev.keyboard.keycode)
				{
				case ALLEGRO_KEY_ESCAPE:
					modoDoJogo = Menu;	
					al_stop_sample_instance(sampleInstance[MusicaDoCanibal]);
					al_play_sample_instance(sampleInstance[MusicaDoMenu]);
					break;
				default:
					break;
				}
			}

			else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
				if (ev.mouse.button & 1){
				
					if ((ev.mouse.x >= 345 && ev.mouse.x <= 569) && (ev.mouse.y >= 257 && ev.mouse.y <= 271)){
						modoDoJogo = JogoDosCanibais;
						retornoDaJogada = NadaAconteceu;
						count = 0;
						iniciarVariaveisCanibais(&canibal1, &canibal2, &canibal3, &pastor1, &pastor2, &pastor3, &jangada);
					}
					else if ((ev.mouse.x >= 351 && ev.mouse.x <= 557) && (ev.mouse.y >= 200 && ev.mouse.y <= 219)){
					
						modoDoJogo = SalvarResultado;
					}
				}
			}
			else if (ev.type == ALLEGRO_EVENT_TIMER){
				desenhar = true;
			}
		}
		//========================================
		//CASO O JOGADOR PERCA NO JOGO DOS CANIBAIS
		//========================================
		else if (modoDoJogo == DerrotaCanibalTeste){
		
			if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
				if (ev.mouse.button & 1){
					if ((ev.mouse.x >= 293 && ev.mouse.x <= 511) && (ev.mouse.y >= 238 && ev.mouse.y <= 258)){
						modoDoJogo = JogoDosCanibais;
						retornoDaJogada = NadaAconteceu;
						count = 0;
						iniciarVariaveisCanibais(&canibal1, &canibal2, &canibal3, &pastor1, &pastor2, &pastor3, &jangada);
						al_play_sample_instance(sampleInstance[MusicaDoCanibal]);
					}
					else if ((ev.mouse.x >= 570 && ev.mouse.x <= 626) && (ev.mouse.y >= 230 && ev.mouse.y <= 254)){
						modoDoJogo = Menu;						
						al_stop_sample_instance(sampleInstance[MusicaDoCanibal]);
						al_play_sample_instance(sampleInstance[MusicaDoMenu]);
						retornoDaJogada = NadaAconteceu;
					}
				}
			}
			else if (ev.type == ALLEGRO_EVENT_KEY_DOWN){
				if (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE){
					modoDoJogo = Menu;
				}
			}
			else if (ev.type == ALLEGRO_EVENT_TIMER){
				desenhar = true;
			}
		}
		//========================================
		//CASO O JOGADOR PERCA NO JOGO DA FAZENDA
		//========================================
		else if (modoDoJogo == DerrotaFazenda){
			if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
				if (ev.mouse.button & 1){
					
					if ((ev.mouse.x >= 293 && ev.mouse.x <= 511) && (ev.mouse.y >= 238 && ev.mouse.y <= 258)){
						modoDoJogo = JogoDaFazenda;
						retornoDaJogada = NadaAconteceu;
						count = 0;
						iniciarVariaveis(&ovelhaStruct, &loboStruct, &repolhoStruct, &pescadorStruct);
						al_play_sample_instance(sampleInstance[JogoDaFazenda]);
					}
					else if ((ev.mouse.x >= 570 && ev.mouse.x <= 626) && (ev.mouse.y >= 230 && ev.mouse.y <= 254)){
						modoDoJogo = Menu;
						al_stop_sample_instance(sampleInstance[MusicaDaFazenda]);
						al_play_sample_instance(sampleInstance[MusicaDoMenu]);
						retornoDaJogada = NadaAconteceu;
					}
				}
			}
			else if (ev.type == ALLEGRO_EVENT_TIMER){
				desenhar = true;
			}
		}
		//========================================
		//CASO O JOGADOR GANHE NO JOGO DA FAZENDA
		//========================================
		else if (modoDoJogo == VitoriaFazenda){
			if (ev.type == ALLEGRO_EVENT_KEY_DOWN){
				switch (ev.keyboard.keycode)
				{
				case ALLEGRO_KEY_ESCAPE:
					modoDoJogo = Menu;
					al_stop_sample_instance(sampleInstance[MusicaDaFazenda]);
					al_play_sample_instance(sampleInstance[MusicaDoMenu]);
					break;
				default:
					break;
				}
			}
			else if (ev.type == ALLEGRO_EVENT_TIMER){
				desenhar = true;
			}
			else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
				if (ev.mouse.button & 1){
					
					if ((ev.mouse.x >= 345 && ev.mouse.x <= 569) && (ev.mouse.y >= 257 && ev.mouse.y <= 271)){
						modoDoJogo = JogoDaFazenda;
						retornoDaJogada = NadaAconteceu;
						count = 0;
						iniciarVariaveis(&ovelhaStruct, &loboStruct, &repolhoStruct, &pescadorStruct);
						al_play_sample_instance(sampleInstance[Yay]);
						al_play_sample_instance(sampleInstance[MusicaDaFazenda]);
					}
					else if ((ev.mouse.x >= 351 && ev.mouse.x <= 557) && (ev.mouse.y >= 200 && ev.mouse.y <= 219)){
						
						modoDoJogo = SalvarResultado;
					}
				}
			}
		}
		//========================================
		//SALVAR O NOME DO JOGADOR
		//========================================
		else if (modoDoJogo == SalvarResultado){
			pegarDadosDigitados(ev, nome);
			if (ev.type == ALLEGRO_EVENT_KEY_DOWN){


				if (ev.keyboard.keycode == ALLEGRO_KEY_ENTER){
					if (jogo == 0){
						cadastrarArquivo(count, fazendaArq, nome);
					}
					else{
						cadastrarArquivo(count, canibalArq, nome);
					}
					
					modoDoJogo = Menu;
					al_play_sample_instance(sampleInstance[MusicaDoMenu]);
					retornoDaJogada = NadaAconteceu;
					strcpy(nome, "");
				}
			}
			else if (ev.type == ALLEGRO_EVENT_TIMER){
				desenhar = true;
			}
		}
		else if (modoDoJogo == Arquivos){
			if (ev.type == ALLEGRO_EVENT_KEY_DOWN){
				if (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE){
					modoDoJogo = Menu;
				}
			}
		}
		
		//========================================
		//PARTE DE DESENHOS
		//========================================
		if (desenhar){
			desenhar = false;
			if (modoDoJogo == Menu){
				desenharMenu(x, y, jogo);
			}
			else if (modoDoJogo == JogoDaFazenda){
				fazerAnimacoes(&ovelhaStruct, &loboStruct, &pescadorStruct, &repolhoStruct);
				desenharPlano(ovelhaStruct, loboStruct, pescadorStruct, repolhoStruct, 0);
				//A FUNCAO ABAIXO NAO É PARA DESENHAR MAS PRECISO DELA NO LOOP PARA SABER SE O JOGADOR PERDEU OU VENCEU
				retornoDaJogada = checarJogada(&ovelhaStruct, &loboStruct, &repolhoStruct, &pescadorStruct);

			}
			else if (modoDoJogo == JogoDosCanibais){
				desenharPlanoCanibal(canibal1, canibal2, canibal3, pastor1, pastor2, pastor3, jangada, NadaAconteceu);
				fazerAnimacoesCanibal(&canibal1, &canibal2, &canibal3, &pastor1, &pastor2, &pastor3, &jangada);
				//A FUNCAO ABAIXO NAO É PARA DESENHAR MAS PRECISO DELA NO LOOP PARA SABER SE O JOGADOR PERDEU OU VENCEU
				retornoDaJogada = checarJogadaCanibal(canibal1, canibal2, canibal3, pastor1, pastor2, pastor3);
				
			}
			else if (modoDoJogo == DerrotaCanibalTeste){				
				desenharDerrotaCanibal(canibal1, canibal2, canibal3, pastor1, pastor2, pastor3, jangada, retornoDaJogada);
			}
			else if (modoDoJogo == VitoriaCanibal){
				desenharVitoriaCanibal(canibal1, canibal2, canibal3, pastor1, pastor2, pastor3, jangada);
			}
			else if (modoDoJogo == DerrotaFazenda){
				derrotaFazenda(&ovelhaStruct, &loboStruct, &pescadorStruct, &repolhoStruct, retornoDaJogada);
			}
			else if (modoDoJogo == VitoriaFazenda){
				vitoriaFazenda(ovelhaStruct, loboStruct, pescadorStruct, repolhoStruct);
			}
			else if (modoDoJogo == SalvarResultado){
				al_clear_to_color(al_map_rgb(0, 0, 0));
				al_draw_text(font[kelam], al_map_rgb(255, 255, 200), 280, 100, 0, "Digite seu nome: ");
				al_draw_textf(font[kelam], al_map_rgb(255, 255, 255), 280, 130, 0, "%s", nome);
				al_draw_text(font[kelam], al_map_rgb(255, 255, 255), 280, 300, 0, "Tempo: ");
				al_draw_textf(font[kelam], al_map_rgb(255, 255, 255), 290, 330, 0, "%d segundos", count / 60);
			}
			al_flip_display();
		}

		//========================================
		//MUDANDO DE MODO A PARTIR DO JOGO DA FAZENDA EM CASO DE VITORIA OU DERROTA DO JOGADOR
		//========================================
		if (modoDoJogo == JogoDaFazenda && retornoDaJogada != NadaAconteceu){
			if (retornoDaJogada == DerrotaLoboComOvelha || retornoDaJogada == DerrotaOvelhaComRepolho){
				al_stop_sample_instance(sampleInstance[MusicaDaFazenda]);

				modoDoJogo = DerrotaFazenda;
				gambiarra = 1;
			}
			else if (retornoDaJogada == Vitoria){
				al_stop_sample_instance(sampleInstance[MusicaDaFazenda]);
				al_play_sample_instance(sampleInstance[Yay]);
				modoDoJogo = VitoriaFazenda;
			}
		}
		else if (modoDoJogo == JogoDosCanibais && retornoDaJogada != NadaAconteceu){
			
			if (retornoDaJogada == Vitoria){
				al_stop_sample_instance(sampleInstance[MusicaDoCanibal]);
				al_play_sample_instance(sampleInstance[VitoriaCanibalSong]);

				modoDoJogo = VitoriaCanibal;
			}
			else if (retornoDaJogada == DerrotaDireita || retornoDaJogada == DerrotaEsquerda){		
				al_stop_sample_instance(sampleInstance[MusicaDoCanibal]);
				al_play_sample_instance(sampleInstance[MordidaCanibal]);
				modoDoJogo = DerrotaCanibalTeste;	
				gambiarra = 1;
			}
		}
	}

	al_destroy_event_queue(event_queueMain);
	fclose(fazendaArq);
	fclose(canibalArq);
	return 0;
}


bool inicializar(){
	int displayHight = 800;
	int displayWidth = 600;

	//inicializando a allegro
	if (!al_init()){
		return false;
	}

	//criando display
	display = al_create_display(displayHight, displayWidth);

	if (!display){
		return false;
	}

	al_install_keyboard();
	al_install_mouse();
	al_install_audio();


	//Criando tempo para 60fps
	timer = al_create_timer(1.0 / 60);

	//inicializando o que vou precisar para o Menu
	al_init_font_addon();
	al_init_acodec_addon();
	al_init_ttf_addon();
	al_init_primitives_addon();
	al_init_image_addon();
	al_init_acodec_addon();

	bitmapsMenu[PlanoDeFundoFazenda] = al_load_bitmap("imagemdefundofazenda.png");
	bitmapsMenu[InstrucoesFazenda] = al_load_bitmap("instrucoesfazenda.png");
	bitmapsMenu[SetaDireita] = al_load_bitmap("seta.png");
	bitmapsMenu[EmConstrucao] = al_load_bitmap("construcao.png");
	bitmapsMenu[SetaEsquerda] = al_load_bitmap("setainv.png");
	bitmapsMenu[PlanoDeFundoCanibal] = al_load_bitmap("imagemdefundocanibal.png");
	bitmapsMenu[InstrucoesCanibal] = al_load_bitmap("instrucoescanibal.png");

	event_queueMain = al_create_event_queue();
	al_register_event_source(event_queueMain, al_get_mouse_event_source());
	al_register_event_source(event_queueMain, al_get_keyboard_event_source());
	al_register_event_source(event_queueMain, al_get_timer_event_source(timer));

	return true;
}

void desenharMenu(int x, int y, int jogo){
	if (jogo == 0){
		al_clear_to_color(al_map_rgb(63, 72, 209));
		al_draw_bitmap(bitmapsMenu[PlanoDeFundoFazenda], 100, 50, 0);
		if (x >= 100 && x <= 700 && y >= 50 && y <= 450){
			al_draw_bitmap(bitmapsMenu[InstrucoesFazenda], 100, 50, 0);
		}
		al_draw_text(font[bubblegum], al_map_rgb(100, 200, 200), 400, 500, ALLEGRO_ALIGN_CENTER, "JOGAR");
		if (x >= 350 && x <= 450 && y >= 500 && y <= 530){
			al_draw_text(font[bubblegum], al_map_rgb(200, 200, 200), 400, 500, ALLEGRO_ALIGN_CENTER, "JOGAR");
		}

		al_draw_text(font[bubblegum], al_map_rgb(100, 200, 200), 400, 550, ALLEGRO_ALIGN_CENTER, "SCORES");
		if ((x >= 340 && x <= 458) && (y >= 554 && y <= 581)){
			al_draw_text(font[bubblegum], al_map_rgb(200, 200, 200), 400, 550, ALLEGRO_ALIGN_CENTER, "SCORES");
		}
		al_draw_bitmap(bitmapsMenu[SetaDireita], 750, 300, 0);
	}
	else{
		al_clear_to_color(al_map_rgb(63, 72, 209));
		al_draw_bitmap(bitmapsMenu[PlanoDeFundoCanibal], 100, 50, 0);
		if (x >= 100 && x <= 700 && y >= 50 && y <= 450){
			al_draw_bitmap(bitmapsMenu[InstrucoesCanibal], 100, 50, 0);
		}
		al_draw_text(font[bubblegum], al_map_rgb(100, 200, 200), 400, 500, ALLEGRO_ALIGN_CENTER, "JOGAR");
		if (x >= 350 && x <= 450 && y >= 500 && y <= 530){
			al_draw_text(font[bubblegum], al_map_rgb(200, 200, 200), 400, 500, ALLEGRO_ALIGN_CENTER, "JOGAR");
		}
		al_draw_text(font[bubblegum], al_map_rgb(100, 200, 200), 400, 550, ALLEGRO_ALIGN_CENTER, "SCORES");
		if ((x >= 340 && x <= 458) && (y >= 554 && y <= 581)){
			al_draw_text(font[bubblegum], al_map_rgb(200, 200, 200), 400, 550, ALLEGRO_ALIGN_CENTER, "SCORES");
		}
		al_draw_bitmap(bitmapsMenu[SetaEsquerda], 0, 300, 0);
	}
}

FILE * criar_Arquivo(char nome[]){
	FILE *aux;
	aux = fopen(nome, "r+b");
	if (aux == NULL){
		aux = fopen(nome, "w+b");
	}
	return aux;
}
