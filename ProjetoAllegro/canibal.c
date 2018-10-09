#include"canibal.h"

bool inicializarCanibal(Tcanibal1 * canibal1, Tcanibal2 * canibal2, Tcanibal3 * canibal3, Tpastor1 * pastor1, Tpastor2 * pastor2, Tpastor3 * pastor3, Tjangada * jangada){
	bitmapsCanibal[Canibal] = al_load_bitmap("canibal.png");
	bitmapsCanibal[Padre] = al_load_bitmap("padre.png");
	bitmapsCanibal[Jangada] = al_load_bitmap("jangada.png");
	bitmapsCanibal[BackGroundCanibal] = al_load_bitmap("back.png");
	bitmapsCanibal[Terco] = al_load_bitmap("terco.png");

	iniciarVariaveisCanibais(canibal1, canibal2, canibal3, pastor1, pastor2, pastor3, jangada);
}

void iniciarVariaveisCanibais(Tcanibal1 * canibal1, Tcanibal2 * canibal2, Tcanibal3 * canibal3, Tpastor1 * pastor1, Tpastor2 * pastor2, Tpastor3 * pastor3, Tjangada * jangada){

	canibal1->x = 650;
	canibal1->y = 250;
	canibal1->animando = false;
	canibal1->lado = 1;
	canibal1->width = al_get_bitmap_width(bitmapsCanibal[Canibal]);
	canibal1->height = al_get_bitmap_height(bitmapsCanibal[Canibal]);
	canibal1->limiteX = canibal1->x + canibal1->width;
	canibal1->limiteY = canibal1->y + canibal1->height;
	canibal1->naJangada = false;
	canibal1->vagaOcupada = Nenhuma;

	canibal2->x = 650;
	canibal2->y = 350;
	canibal2->animando = false;
	canibal2->lado = 1;
	canibal2->width = al_get_bitmap_width(bitmapsCanibal[Canibal]);
	canibal2->height = al_get_bitmap_height(bitmapsCanibal[Canibal]);
	canibal2->limiteX = canibal2->x + canibal2->width;
	canibal2->limiteY = canibal2->y + canibal2->height;
	canibal2->naJangada = false;
	canibal2->vagaOcupada = Nenhuma;

	canibal3->x = 650;
	canibal3->y = 450;
	canibal3->animando = false;
	canibal3->lado = 1;
	canibal3->width = al_get_bitmap_width(bitmapsCanibal[Canibal]);
	canibal3->height = al_get_bitmap_height(bitmapsCanibal[Canibal]);
	canibal3->limiteX = canibal3->x + canibal3->width;
	canibal3->limiteY = canibal3->y + canibal3->height;
	canibal3->naJangada = false;
	canibal3->vagaOcupada = Nenhuma;

	pastor1->x = 720;
	pastor1->y = 250;
	pastor1->animando = false;
	pastor1->lado = 1;
	pastor1->width = al_get_bitmap_width(bitmapsCanibal[Padre]);
	pastor1->height = al_get_bitmap_height(bitmapsCanibal[Padre]);
	pastor1->limiteX = pastor1->x + pastor1->width;
	pastor1->limiteY = pastor1->y + pastor1->height;
	pastor1->naJangada = false;
	pastor1->vagaOcupada = Nenhuma;

	pastor2->x = 720;
	pastor2->y = 350;
	pastor2->animando = false;
	pastor2->lado = 1;
	pastor2->width = al_get_bitmap_width(bitmapsCanibal[Padre]);
	pastor2->height = al_get_bitmap_height(bitmapsCanibal[Padre]);
	pastor2->limiteX = pastor2->x + pastor2->width;
	pastor2->limiteY = pastor2->y + pastor2->height;
	pastor2->naJangada = false;
	pastor2->vagaOcupada = Nenhuma;

	pastor3->x = 720;
	pastor3->y = 450;
	pastor3->animando = false;
	pastor3->lado = 1;
	pastor3->width = al_get_bitmap_width(bitmapsCanibal[Padre]);
	pastor3->height = al_get_bitmap_height(bitmapsCanibal[Padre]);
	pastor3->limiteX = pastor3->x + pastor3->width;
	pastor3->limiteY = pastor3->y + pastor3->height;
	pastor3->naJangada = false;
	pastor3->vagaOcupada = Nenhuma;

	jangada->animando = false;
	jangada->lado = 1;
	jangada->x = 400;
	jangada->y = 500;
	jangada->height = al_get_bitmap_height(bitmapsCanibal[Jangada]);
	jangada->width = al_get_bitmap_width(bitmapsCanibal[Jangada]);
	jangada->limiteX = jangada->x + jangada->width;
	jangada->limiteY = jangada->y + jangada->height;
	jangada->vaga1Ocupada = false;
	jangada->vaga2Ocupada = false;
}

void desenharPlanoCanibal(Tcanibal1 canibal1, Tcanibal2 canibal2, Tcanibal3 canibal3, Tpastor1 pastor1, Tpastor2 pastor2, Tpastor3 pastor3, Tjangada jangada, int modoDaDerrota){
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_draw_bitmap(bitmapsCanibal[BackGroundCanibal], 0, 0, 0);		
	al_draw_bitmap(bitmapsCanibal[Jangada], jangada.x, jangada.y, 0);
	if (modoDaDerrota == DerrotaDireita){
		if (pastor1.lado == 0){
			al_draw_bitmap(bitmapsCanibal[Padre], pastor1.x, pastor1.y, 0);
		}
		if (pastor2.lado == 0){
			al_draw_bitmap(bitmapsCanibal[Padre], pastor2.x, pastor2.y, 0);
		}
		if (pastor3.lado == 0){
			al_draw_bitmap(bitmapsCanibal[Padre], pastor3.x, pastor3.y, 0);
		}
	}
	else if(modoDaDerrota == DerrotaEsquerda){
		if (pastor1.lado == 1){
			al_draw_bitmap(bitmapsCanibal[Padre], pastor1.x, pastor1.y, 0);
		}
		if (pastor2.lado == 1){
			al_draw_bitmap(bitmapsCanibal[Padre], pastor2.x, pastor2.y, 0);
		}
		if (pastor3.lado == 1){
			al_draw_bitmap(bitmapsCanibal[Padre], pastor3.x, pastor3.y, 0);
		}
	}
	else{
		al_draw_bitmap(bitmapsCanibal[Padre], pastor1.x, pastor1.y, 0);
		al_draw_bitmap(bitmapsCanibal[Padre], pastor2.x, pastor2.y, 0);
		al_draw_bitmap(bitmapsCanibal[Padre], pastor3.x, pastor3.y, 0);
	}	
	

	al_draw_bitmap(bitmapsCanibal[Canibal], canibal1.x, canibal1.y, 0);
	al_draw_bitmap(bitmapsCanibal[Canibal], canibal2.x, canibal2.y, 0);
	al_draw_bitmap(bitmapsCanibal[Canibal], canibal3.x, canibal3.y, 0);


	al_draw_textf(font[midnight], al_map_rgb(240, 240, 240), 100, 2, 0, "Tempo : %d", count / 60);
}

int calcularClickCanibal(Tcanibal1 canibal1, Tcanibal2 canibal2, Tcanibal3 canibal3, Tpastor1 pastor1, Tpastor2 pastor2, Tpastor3 pastor3, Tjangada jangada, int x, int y){
	if (x >= canibal1.x && x <= canibal1.limiteX && y >= canibal1.y && y <= canibal1.limiteY){
		return ClickCanibal1;
	}
	else if (x >= canibal2.x && x <= canibal2.limiteX && y >= canibal2.y && y <= canibal2.limiteY){
		return ClickCanibal2;
	}
	else if (x >= canibal3.x && x <= canibal3.limiteX && y >= canibal3.y && y <= canibal3.limiteY){
		return ClickCanibal3;
	}
	else if (x >= pastor1.x && x <= pastor1.limiteX && y >= pastor1.y && y <= pastor1.limiteY){
		return ClickPastor1;
	}
	else if (x >= pastor2.x && x <= pastor2.limiteX && y >= pastor2.y && y <= pastor2.limiteY){
		return ClickPastor2;
	}
	else if (x >= pastor3.x && x <= pastor3.limiteX && y >= pastor3.y && y <= pastor3.limiteY){
		return ClickPastor3;
	}
	else if (x >= jangada.x && x <= jangada.limiteX && y >= jangada.y && y <= jangada.limiteY){
		return ClickJangada;
	}



}

void moverImagensCanibal(Tcanibal1 * canibal1, Tcanibal2 * canibal2, Tcanibal3 * canibal3, Tpastor1 * pastor1, Tpastor2 * pastor2, Tpastor3 * pastor3, Tjangada * jangada, int click){

	if (click == ClickCanibal1){
		
		if (!canibal1->naJangada){
			if (!jangada->vaga1Ocupada){
				if (canibal1->lado == jangada->lado && jangada->lado == 1){
					canibal1->x = 430;
					canibal1->y = 410;
					canibal1->naJangada = true;
					canibal1->limiteX = canibal1->x + canibal1->width;
					canibal1->limiteY = canibal1->y + canibal1->height;

					canibal1->vagaOcupada = Vaga1;
					jangada->vaga1Ocupada = true;
				}
				else if (canibal1->lado == jangada->lado && jangada->lado == 0){
					canibal1->x = 180;
					canibal1->y = 410;
					canibal1->naJangada = true;
					canibal1->limiteX = canibal1->x + canibal1->width;
					canibal1->limiteY = canibal1->y + canibal1->height;

					canibal1->vagaOcupada = Vaga1;
					jangada->vaga1Ocupada = true;
				}
			}
			else if (!jangada->vaga2Ocupada){
			
				if (canibal1->lado == jangada->lado && jangada->lado == 1){
					canibal1->x = 500;
					canibal1->y = 410;
					canibal1->naJangada = true;
					canibal1->limiteX = canibal1->x + canibal1->width;
					canibal1->limiteY = canibal1->y + canibal1->height;

					canibal1->vagaOcupada = Vaga2;
					jangada->vaga2Ocupada = true;
				}
				else if (canibal1->lado == jangada->lado && jangada->lado == 0){
					canibal1->x = 250;
					canibal1->y = 410;
					canibal1->naJangada = true;
					canibal1->limiteX = canibal1->x + canibal1->width;
					canibal1->limiteY = canibal1->y + canibal1->height;

					canibal1->vagaOcupada = Vaga2;
					jangada->vaga2Ocupada = true;
				}
			}
		}
		else{
			if (jangada->lado == 1){
				canibal1->x = 650;
				canibal1->y = 250;
				canibal1->naJangada = false;

				canibal1->limiteX = canibal1->x + canibal1->width;
				canibal1->limiteY = canibal1->y + canibal1->height;

				if (canibal1->vagaOcupada == Vaga1){
					jangada->vaga1Ocupada = false;
					canibal1->vagaOcupada = Nenhuma;
				}
				else if (canibal1->vagaOcupada == Vaga2){
					jangada->vaga2Ocupada = false;
					canibal1->vagaOcupada = Nenhuma;
				}

			}
			else if (jangada->lado == 0){
				canibal1->x = 70;
				canibal1->y = 250;
				canibal1->naJangada = false;

				canibal1->limiteX = canibal1->x + canibal1->width;
				canibal1->limiteY = canibal1->y + canibal1->height;

				if (canibal1->vagaOcupada == Vaga1){
					jangada->vaga1Ocupada = false;
					canibal1->vagaOcupada = Nenhuma;
				}
				else if (canibal1->vagaOcupada == Vaga2){
					jangada->vaga2Ocupada = false;
					canibal1->vagaOcupada = Nenhuma;
				}

			}
		}

	}
	else if (click == ClickCanibal2){//====================Canibal2======================================================
	
		if (!canibal2->naJangada){
			if (!jangada->vaga1Ocupada){
				if (canibal2->lado == jangada->lado &&jangada->lado == 1){
					canibal2->x = 430;
					canibal2->y = 410;
					canibal2->naJangada = true;
					canibal2->limiteX = canibal2->x + canibal2->width;
					canibal2->limiteY = canibal2->y + canibal2->height;

					canibal2->vagaOcupada = Vaga1;
					jangada->vaga1Ocupada = true;
				}
				else if (canibal2->lado == jangada->lado && jangada->lado == 0){
					canibal2->x = 180;
					canibal2->y = 410;
					canibal2->naJangada = true;
					canibal2->limiteX = canibal2->x + canibal2->width;
					canibal2->limiteY = canibal2->y + canibal2->height;

					canibal2->vagaOcupada = Vaga1;
					jangada->vaga1Ocupada = true;
				}
			}
			else if (!jangada->vaga2Ocupada){
				if (canibal2->lado == jangada->lado && jangada->lado == 1){
					canibal2->x = 500;
					canibal2->y = 410;
					canibal2->naJangada = true;
					canibal2->limiteX = canibal2->x + canibal2->width;
					canibal2->limiteY = canibal2->y + canibal2->height;

					canibal2->vagaOcupada = Vaga2;
					jangada->vaga2Ocupada = true;
				}
				else if (canibal2->lado == jangada->lado && jangada->lado == 0){
					canibal2->x = 250;
					canibal2->y = 410;
					canibal2->naJangada = true;
					canibal2->limiteX = canibal2->x + canibal2->width;
					canibal2->limiteY = canibal2->y + canibal2->height;

					canibal2->vagaOcupada = Vaga2;
					jangada->vaga2Ocupada = true;
				}
			}
		}
		else{
			if (jangada->lado == 1){
				canibal2->x = 650;
				canibal2->y = 350;
				canibal2->naJangada = false;

				canibal2->limiteX = canibal2->x + canibal2->width;
				canibal2->limiteY = canibal2->y + canibal2->height;

				if (canibal2->vagaOcupada == Vaga1){
					jangada->vaga1Ocupada = false;
					canibal2->vagaOcupada = Nenhuma;
				}
				else if (canibal2->vagaOcupada == Vaga2){
					jangada->vaga2Ocupada = false;
					canibal2->vagaOcupada = Nenhuma;
				}
			}
			else if (jangada->lado == 0){
				canibal2->x = 70;
				canibal2->y = 350;
				canibal2->naJangada = false;

				canibal2->limiteX = canibal2->x + canibal2->width;
				canibal2->limiteY = canibal2->y + canibal2->height;

				if (canibal2->vagaOcupada == Vaga1){
					jangada->vaga1Ocupada = false;
					canibal2->vagaOcupada = Nenhuma;
				}
				else if (canibal2->vagaOcupada == Vaga2){
					jangada->vaga2Ocupada = false;
					canibal2->vagaOcupada = Nenhuma;
				}
			}
		}
	}
	else if (click == ClickCanibal3){//====================Canibal3======================================================
		
		if (!canibal3->naJangada){
			if (!jangada->vaga1Ocupada){
				if (canibal3->lado == jangada->lado && jangada->lado == 1){
					canibal3->x = 430;
					canibal3->y = 410;
					canibal3->naJangada = true;
					canibal3->limiteX = canibal3->x + canibal3->width;
					canibal3->limiteY = canibal3->y + canibal3->height;

					canibal3->vagaOcupada = Vaga1;
					jangada->vaga1Ocupada = true;
				}
				else if (canibal3->lado == jangada->lado && jangada->lado == 0){
					canibal3->x = 180;
					canibal3->y = 410;
					canibal3->naJangada = true;
					canibal3->limiteX = canibal3->x + canibal3->width;
					canibal3->limiteY = canibal3->y + canibal3->height;

					canibal3->vagaOcupada = Vaga1;
					jangada->vaga1Ocupada = true;
				}
			}
			else if (!jangada->vaga2Ocupada){
				if (canibal3->lado == jangada->lado && jangada->lado == 1){
					canibal3->x = 500;
					canibal3->y = 410;
					canibal3->naJangada = true;
					canibal3->limiteX = canibal3->x + canibal3->width;
					canibal3->limiteY = canibal3->y + canibal3->height;

					canibal3->vagaOcupada = Vaga2;
					jangada->vaga2Ocupada = true;
				}
				else if (canibal3->lado == jangada->lado && jangada->lado == 0){
					canibal3->x = 250;
					canibal3->y = 410;
					canibal3->naJangada = true;
					canibal3->limiteX = canibal3->x + canibal3->width;
					canibal3->limiteY = canibal3->y + canibal3->height;

					canibal3->vagaOcupada = Vaga2;
					jangada->vaga2Ocupada = true;
				}
			}
		}
		else{
			if (jangada->lado == 1){
				canibal3->x = 650;
				canibal3->y = 450;
				canibal3->naJangada = false;

				canibal3->limiteX = canibal3->x + canibal3->width;
				canibal3->limiteY = canibal3->y + canibal3->height;

				if (canibal3->vagaOcupada == Vaga1){
					jangada->vaga1Ocupada = false;
					canibal3->vagaOcupada = Nenhuma;
				}
				else if (canibal3->vagaOcupada == Vaga2){
					jangada->vaga2Ocupada = false;
					canibal3->vagaOcupada = Nenhuma;
				}

			}
			else{
				canibal3->x = 70;
				canibal3->y = 450;
				canibal3->naJangada = false;

				canibal3->limiteX = canibal3->x + canibal3->width;
				canibal3->limiteY = canibal3->y + canibal3->height;

				if (canibal3->vagaOcupada == Vaga1){
					jangada->vaga1Ocupada = false;
					canibal3->vagaOcupada = Nenhuma;
				}
				else if (canibal3->vagaOcupada == Vaga2){
					jangada->vaga2Ocupada = false;
					canibal3->vagaOcupada = Nenhuma;
				}
			}
		}
	}
	else if (click == ClickPastor1){//====================Pastor1======================================================
		if (!pastor1->naJangada){
			if (!jangada->vaga1Ocupada){
				if (pastor1->lado == jangada->lado && jangada->lado == 1){
					pastor1->x = 430;
					pastor1->y = 410;
					pastor1->naJangada = true;
					pastor1->limiteX = pastor1->x + pastor1->width;
					pastor1->limiteY = pastor1->y + pastor1->height;

					pastor1->vagaOcupada = Vaga1;
					jangada->vaga1Ocupada = true;
				}
				else if (pastor1->lado == jangada->lado && jangada->lado == 0){
					pastor1->x = 180;
					pastor1->y = 410;
					pastor1->naJangada = true;
					pastor1->limiteX = pastor1->x + pastor1->width;
					pastor1->limiteY = pastor1->y + pastor1->height;

					pastor1->vagaOcupada = Vaga1;
					jangada->vaga1Ocupada = true;
				}
			}
			else if (!jangada->vaga2Ocupada){
				if (pastor1->lado == jangada->lado && jangada->lado == 1){
					pastor1->x = 500;
					pastor1->y = 410;
					pastor1->naJangada = true;
					pastor1->limiteX = pastor1->x + pastor1->width;
					pastor1->limiteY = pastor1->y + pastor1->height;

					pastor1->vagaOcupada = Vaga2;
					jangada->vaga2Ocupada = true;
				}
				else if (pastor1->lado == jangada->lado && jangada->lado == 0){
					pastor1->x = 250;
					pastor1->y = 410;
					pastor1->naJangada = true;
					pastor1->limiteX = pastor1->x + pastor1->width;
					pastor1->limiteY = pastor1->y + pastor1->height;

					pastor1->vagaOcupada = Vaga2;
					jangada->vaga2Ocupada = true;
				}
			}
		}
		else{
			if (jangada->lado == 1){
				pastor1->x = 720;
				pastor1->y = 250;
				pastor1->naJangada = false;

				pastor1->limiteX = pastor1->x + pastor1->width;
				pastor1->limiteY = pastor1->y + pastor1->height;

				if (pastor1->vagaOcupada == Vaga1){
					jangada->vaga1Ocupada = false;
					pastor1->vagaOcupada = Nenhuma;
				}
				else if (pastor1->vagaOcupada == Vaga2){
					jangada->vaga2Ocupada = false;
					pastor1->vagaOcupada = Nenhuma;
				}
			}
			else{
				pastor1->x = 2;
				pastor1->y = 250;
				pastor1->naJangada = false;

				pastor1->limiteX = pastor1->x + pastor1->width;
				pastor1->limiteY = pastor1->y + pastor1->height;

				if (pastor1->vagaOcupada == Vaga1){
					jangada->vaga1Ocupada = false;
					pastor1->vagaOcupada = Nenhuma;
				}
				else if (pastor1->vagaOcupada == Vaga2){
					jangada->vaga2Ocupada = false;
					pastor1->vagaOcupada = Nenhuma;
				}
			}
		}
	}
	else if (click == ClickPastor2){//====================Pastor2======================================================
		
		if (!pastor2->naJangada){
			if (!jangada->vaga1Ocupada){
				if (pastor2->lado == jangada->lado && jangada->lado == 1){
					pastor2->x = 430;
					pastor2->y = 410;
					pastor2->naJangada = true;
					pastor2->limiteX = pastor2->x + pastor2->width;
					pastor2->limiteY = pastor2->y + pastor2->height;

					pastor2->vagaOcupada = Vaga1;
					jangada->vaga1Ocupada = true;
				}
				else if (pastor2->lado == jangada->lado && jangada->lado == 0){
					pastor2->x = 180;
					pastor2->y = 410;
					pastor2->naJangada = true;
					pastor2->limiteX = pastor2->x + pastor2->width;
					pastor2->limiteY = pastor2->y + pastor2->height;

					pastor2->vagaOcupada = Vaga1;
					jangada->vaga1Ocupada = true;
				}
			}
			else if (!jangada->vaga2Ocupada){
				if (pastor2->lado == jangada->lado && jangada->lado == 1){
					pastor2->x = 500;
					pastor2->y = 410;
					pastor2->naJangada = true;
					pastor2->limiteX = pastor2->x + pastor2->width;
					pastor2->limiteY = pastor2->y + pastor2->height;

					pastor2->vagaOcupada = Vaga2;
					jangada->vaga2Ocupada = true;
				}
				else if (pastor2->lado == jangada->lado && jangada->lado == 0){
					pastor2->x = 250;
					pastor2->y = 410;
					pastor2->naJangada = true;
					pastor2->limiteX = pastor2->x + pastor2->width;
					pastor2->limiteY = pastor2->y + pastor2->height;

					pastor2->vagaOcupada = Vaga2;
					jangada->vaga2Ocupada = true;
				}
			}
		}
		else{
			if (jangada->lado == 1){
				pastor2->x = 720;
				pastor2->y = 350;
				pastor2->naJangada = false;

				pastor2->limiteX = pastor2->x + pastor2->width;
				pastor2->limiteY = pastor2->y + pastor2->height;

				if (pastor2->vagaOcupada == Vaga1){
					jangada->vaga1Ocupada = false;
					pastor2->vagaOcupada = Nenhuma;
				}
				else if (pastor2->vagaOcupada == Vaga2){
					jangada->vaga2Ocupada = false;
					pastor2->vagaOcupada = Nenhuma;
				}
			}
			else if (jangada->lado == 0){
				pastor2->x = 2;
				pastor2->y = 350;
				pastor2->naJangada = false;

				pastor2->limiteX = pastor2->x + pastor2->width;
				pastor2->limiteY = pastor2->y + pastor2->height;

				if (pastor2->vagaOcupada == Vaga1){
					jangada->vaga1Ocupada = false;
					pastor2->vagaOcupada = Nenhuma;
				}
				else if (pastor2->vagaOcupada == Vaga2){
					jangada->vaga2Ocupada = false;
					pastor2->vagaOcupada = Nenhuma;
				}
			}
		}
	}
	else if (click == ClickPastor3){//====================Pastor3======================================================
		

		if (!pastor3->naJangada){
			if (!jangada->vaga1Ocupada){
				if (pastor3->lado == jangada->lado && jangada->lado == 1){
					pastor3->x = 430;
					pastor3->y = 410;
					pastor3->naJangada = true;
					pastor3->limiteX = pastor3->x + pastor3->width;
					pastor3->limiteY = pastor3->y + pastor3->height;

					pastor3->vagaOcupada = Vaga1;
					jangada->vaga1Ocupada = true;
				}
				else if (pastor3->lado == jangada->lado && jangada->lado == 0){
					pastor3->x = 180;
					pastor3->y = 410;
					pastor3->naJangada = true;
					pastor3->limiteX = pastor3->x + pastor3->width;
					pastor3->limiteY = pastor3->y + pastor3->height;

					pastor3->vagaOcupada = Vaga1;
					jangada->vaga1Ocupada = true;
				}
			}
			else if (!jangada->vaga2Ocupada){
				if (pastor3->lado == jangada->lado && jangada->lado == 1){
					pastor3->x = 500;
					pastor3->y = 410;
					pastor3->naJangada = true;
					pastor3->limiteX = pastor3->x + pastor3->width;
					pastor3->limiteY = pastor3->y + pastor3->height;

					pastor3->vagaOcupada = Vaga2;
					jangada->vaga2Ocupada = true;
				}
				else if (pastor3->lado == jangada->lado && jangada->lado == 0){
					pastor3->x = 250;
					pastor3->y = 410;
					pastor3->naJangada = true;
					pastor3->limiteX = pastor3->x + pastor3->width;
					pastor3->limiteY = pastor3->y + pastor3->height;

					pastor3->vagaOcupada = Vaga2;
					jangada->vaga2Ocupada = true;
				}
			}
		}
		else{
			if (jangada->lado == 1){
				pastor3->x = 720;
				pastor3->y = 450;
				pastor3->naJangada = false;

				pastor3->limiteX = pastor3->x + pastor3->width;
				pastor3->limiteY = pastor3->y + pastor3->height;

				if (pastor3->vagaOcupada == Vaga1){
					jangada->vaga1Ocupada = false;
					pastor3->vagaOcupada = Nenhuma;
				}
				else if (pastor3->vagaOcupada == Vaga2){
					jangada->vaga2Ocupada = false;
					pastor3->vagaOcupada = Nenhuma;
				}
			}
			else{
				pastor3->x = 2;
				pastor3->y = 450;
				pastor3->naJangada = false;

				pastor3->limiteX = pastor3->x + pastor3->width;
				pastor3->limiteY = pastor3->y + pastor3->height;

				if (pastor3->vagaOcupada == Vaga1){
					jangada->vaga1Ocupada = false;
					pastor3->vagaOcupada = Nenhuma;
				}
				else if (pastor3->vagaOcupada == Vaga2){
					jangada->vaga2Ocupada = false;
					pastor3->vagaOcupada = Nenhuma;
				}
			}
		}

	}
	else if (click == ClickJangada){
		if (jangada->vaga1Ocupada || jangada->vaga2Ocupada){
			jangada->animando = true;
		}
	}
}

void fazerAnimacoesCanibal(Tcanibal1 * canibal1, Tcanibal2 * canibal2, Tcanibal3 * canibal3, Tpastor1 * pastor1, Tpastor2 * pastor2, Tpastor3 * pastor3, Tjangada * jangada){
	if (jangada->animando){
		if (jangada->lado == 1){
			jangada->x = jangada->x - 5;
			jangada->limiteX = jangada->x + jangada->width;
			if (pastor1->naJangada){
				pastor1->x = pastor1->x - 5;
				pastor1->limiteX = pastor1->x + pastor1->width;

			}
			if (pastor2->naJangada){
				pastor2->x = pastor2->x - 5;
				pastor2->limiteX = pastor2->x + pastor2->width;

			}
			if (pastor3->naJangada){
				pastor3->x = pastor3->x - 5;
				pastor3->limiteX = pastor3->x + pastor3->width;

			}
			if (canibal1->naJangada){
				canibal1->x = canibal1->x - 5;
				canibal1->limiteX = canibal1->x + canibal1->width;

			}
			if (canibal2->naJangada){
				canibal2->x = canibal2->x - 5;
				canibal2->limiteX = canibal2->x + canibal2->width;

			}
			if (canibal3->naJangada){
				canibal3->x = canibal3->x - 5;
				canibal3->limiteX = canibal3->x + canibal3->width;

			}

			//saber quando é pra parar de animar a jangada
			if (jangada->x <= 150){

				jangada->animando = false;
				jangada->lado = 0;
			
				if (pastor1->naJangada){
					pastor1->lado = jangada->lado;
				}
				if (pastor2->naJangada){
					pastor2->lado = jangada->lado;
				}
				if (pastor3->naJangada){
					pastor3->lado = jangada->lado;
				}
				if (canibal1->naJangada){
					canibal1->lado = jangada->lado;
				}
				if (canibal2->naJangada){
					canibal2->lado = jangada->lado;
				}
				if (canibal3->naJangada){
					canibal3->lado = jangada->lado;
				}
			}
		}
		else if (jangada->lado == 0){
			jangada->x = jangada->x + 5;
			jangada->limiteX = jangada->x + jangada->width;

			if (pastor1->naJangada){
				pastor1->x = pastor1->x + 5;
				pastor1->limiteX = pastor1->x + pastor1->width;

			}
			if (pastor2->naJangada){
				pastor2->x = pastor2->x + 5;
				pastor2->limiteX = pastor2->x + pastor2->width;

			}
			if (pastor3->naJangada){
				pastor3->x = pastor3->x + 5;
				pastor3->limiteX = pastor3->x + pastor3->width;

			}
			if (canibal1->naJangada){
				canibal1->x = canibal1->x + 5;
				canibal1->limiteX = canibal1->x + canibal1->width;

			}
			if (canibal2->naJangada){
				canibal2->x = canibal2->x + 5;
				canibal2->limiteX = canibal2->x + canibal2->width;

			}
			if (canibal3->naJangada){
				canibal3->x = canibal3->x + 5;
				canibal3->limiteX = canibal3->x + canibal3->width;

			}

			//saber quando é pra parar de animar a jangada
			if (jangada->x >= 400){
				jangada->animando = false;
				jangada->lado = 1;

				if (pastor1->naJangada){

					pastor1->lado = jangada->lado;
				}
				if (pastor2->naJangada){

					pastor2->lado = jangada->lado;
				}
				if (pastor3->naJangada){

					pastor3->lado = jangada->lado;
				}
				if (canibal1->naJangada){

					canibal1->lado = jangada->lado;
				}
				if (canibal2->naJangada){

					canibal2->lado = jangada->lado;
				}
				if (canibal3->naJangada){
					canibal3->lado = jangada->lado;
				}
			}
		}
	}
}

int checarJogadaCanibal(Tcanibal1 canibal1, Tcanibal2 canibal2, Tcanibal3 canibal3, Tpastor1 pastor1, Tpastor2 pastor2, Tpastor3 pastor3){
	int canibalDireito = 0, padreDireito = 0, padreEsquerdo = 0, canibalEsquerdo = 0;
	if (canibal1.lado == 1){
		canibalDireito++;
	}
	if (canibal2.lado == 1){
		canibalDireito++;
	}
	if (canibal3.lado == 1){
		canibalDireito++;
	}
	if (pastor1.lado == 1){
		padreDireito++;
	}
	if (pastor2.lado == 1){
		padreDireito++;
	}
	if (pastor3.lado == 1){
		padreDireito++;
	}
	padreEsquerdo = 3 - padreDireito;
	canibalEsquerdo = 3 - canibalDireito;

	if (canibalDireito > padreDireito && padreDireito != 0){
		return DerrotaDireita;
	}
	else if (canibalEsquerdo > padreEsquerdo && padreEsquerdo != 0){
		return DerrotaEsquerda;
	}
	else if (canibalEsquerdo == 3 && padreEsquerdo == 3){
		return Vitoria;
	}
	else{
		return NadaAconteceu;
	}
}

void desenharVitoriaCanibal(Tcanibal1 canibal1, Tcanibal2 canibal2, Tcanibal3 canibal3, Tpastor1 pastor1, Tpastor2 pastor2, Tpastor3 pastor3, Tjangada jangada){
	desenharPlanoCanibal(canibal1, canibal2, canibal3, pastor1, pastor2, pastor3, jangada, NadaAconteceu);
	al_draw_filled_rectangle(250, 100, 650, 300, al_map_rgb(30, 30, 150));
	al_draw_rectangle(260, 110, 640, 290, al_map_rgb(255, 255, 255), 5);
	al_draw_text(font[cloning], al_map_rgb(250, 250, 250), 290, 130, 0, "Voce Ganhou");
	al_draw_textf(font[kelam], al_map_rgb(255, 255, 255), 350, 250, 0, "Jogar Novamente");
	al_draw_text(font[kelam], al_map_rgb(255, 255, 255), 350, 200, 0, "Salvar Resultado");
}

void desenharDerrotaCanibal(Tcanibal1 canibal1, Tcanibal2 canibal2, Tcanibal3 canibal3, Tpastor1 pastor1, Tpastor2 pastor2, Tpastor3 pastor3, Tjangada jangada, int modoDaDerrota){
	
	desenharPlanoCanibal(canibal1, canibal2, canibal3, pastor1, pastor2, pastor3, jangada, modoDaDerrota);
	if (modoDaDerrota == DerrotaEsquerda){
		if (pastor1.lado == 0){
			if (gambiarra){
				al_draw_bitmap(bitmapsFazenda[Fumaca], pastor1.x, pastor1.y, 0);	
			
			}
			else{
				al_draw_bitmap(bitmapsCanibal[Terco], pastor1.x, pastor1.y, 0);
			}
		}
		if (pastor2.lado == 0){
			if (gambiarra){
				al_draw_bitmap(bitmapsFazenda[Fumaca], pastor2.x, pastor2.y, 0);
				
			}
			else{
				al_draw_bitmap(bitmapsCanibal[Terco], pastor2.x, pastor2.y, 0);
			}
		}
		if (pastor3.lado == 0){
			if (gambiarra){
				al_draw_bitmap(bitmapsFazenda[Fumaca], pastor3.x, pastor3.y, 0);
			
			}
			else{
				al_draw_bitmap(bitmapsCanibal[Terco], pastor3.x, pastor3.y, 0);
			}
		}
		if (gambiarra){
			al_flip_display();
			al_rest(0.2);
		}
		gambiarra = 0;
	}

	else if(modoDaDerrota == DerrotaDireita){
		if (pastor1.lado == 1){
			if (gambiarra){
				al_draw_bitmap(bitmapsFazenda[Fumaca], pastor1.x, pastor1.y, 0);
			}
			else{
				al_draw_bitmap(bitmapsCanibal[Terco], pastor1.x, pastor1.y, 0);
			}
		}
		if (pastor2.lado == 1){
			if (gambiarra){
				al_draw_bitmap(bitmapsFazenda[Fumaca], pastor2.x, pastor2.y, 0);
			}
			else{
				al_draw_bitmap(bitmapsCanibal[Terco], pastor2.x, pastor2.y, 0);
			}
		}
		if (pastor3.lado == 1){
			if (gambiarra){
				al_draw_bitmap(bitmapsFazenda[Fumaca], pastor3.x, pastor3.y, 0);
				
			}
			else{
				al_draw_bitmap(bitmapsCanibal[Terco], pastor3.x, pastor3.y, 0);
			}
		}
		if (gambiarra){
			al_flip_display();
			al_rest(0.2);
		}
		gambiarra = 0;
	}
	al_draw_filled_rectangle(250, 100, 650, 300, al_map_rgb(30, 30, 150));
	al_draw_rectangle(260, 110, 640, 290, al_map_rgb(255, 255, 255), 5);
	al_draw_text(font[cloning], al_map_rgb(250, 250, 250), 290, 130, 0, "Voce Perdeu");
	al_draw_textf(font[kelam], al_map_rgb(255, 255, 255), 290, 230, 0, "Jogar Novamente");
	al_draw_text(font[kelam], al_map_rgb(255, 255, 255), 570, 230, 0, "Inicio");
}