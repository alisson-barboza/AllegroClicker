#include<stdio.h>
#include<stdlib.h>
#include"fazenda.h"



void iniciarVariaveis(Tovelha * ovelhaStruct, Tlobo * loboStruct, Trepolho *repolhoStruct, Tpescador * pescadorStruct){
	//pegando as dimensoes das imagens
	repolhoStruct->height = al_get_bitmap_height(bitmapsFazenda[Repolho]);
	repolhoStruct->width = al_get_bitmap_width(bitmapsFazenda[Repolho]);
	ovelhaStruct->height = al_get_bitmap_height(bitmapsFazenda[Ovelha]);
	ovelhaStruct->width = al_get_bitmap_width(bitmapsFazenda[Ovelha]);
	loboStruct->height = al_get_bitmap_height(bitmapsFazenda[Lobo]);
	loboStruct->width = al_get_bitmap_width(bitmapsFazenda[Lobo]);
	pescadorStruct->height = al_get_bitmap_height(bitmapsFazenda[Pescador]);
	pescadorStruct->width = al_get_bitmap_width(bitmapsFazenda[Pescador]);
	smokeHeight = al_get_bitmap_height(bitmapsFazenda[Fumaca]);
	smokeWidth = al_get_bitmap_width(bitmapsFazenda[Fumaca]);

	//iniciando minhas variaveis
	repolhoStruct->x = 740;
	repolhoStruct->y = 320;
	repolhoStruct->limiteX = repolhoStruct->x + repolhoStruct->width;
	repolhoStruct->limiteY = repolhoStruct->y + repolhoStruct->height;
	repolhoStruct->withPescador = false;
	repolhoStruct->lado = 1;

	ovelhaStruct->x = 694;
	ovelhaStruct->y = 523;
	ovelhaStruct->limiteX = ovelhaStruct->x + ovelhaStruct->width;
	ovelhaStruct->limiteY = ovelhaStruct->y + ovelhaStruct->height;
	ovelhaStruct->withPescador = false;
	ovelhaStruct->lado = 1;
	ovelhaStruct->animando = false;

	loboStruct->x = 670;
	loboStruct->y = 390;
	loboStruct->limiteX = loboStruct->x + loboStruct->width;
	loboStruct->limiteY = loboStruct->y + loboStruct->height;
	loboStruct->withPescador = false;
	loboStruct->lado = 1;
	loboStruct->animando = false;

	pescadorStruct->full = false;
	pescadorStruct->lado = 1;
	pescadorStruct->x = 390;
	pescadorStruct->y = 350;//300
	pescadorStruct->limiteX = pescadorStruct->x + pescadorStruct->width;
	pescadorStruct->limiteY = pescadorStruct->y + pescadorStruct->height;
	pescadorStruct->objeto = 0;
	pescadorStruct->animando = false;

}

bool inicializarFazenda(Tovelha * ovelhaStruct, Tlobo * loboStruct, Trepolho *repolhoStruct, Tpescador * pescadorStruct){

	//instanciando e colocando os sons
	al_reserve_samples(10);

	sample[MusicaDaFazenda] = al_load_sample("gctheme.ogg");
	sample[MusicaDoMenu] = al_load_sample("world.ogg");
	sample[SomDaGalinha] = al_load_sample("galinha.ogg");
	sample[Yay] = al_load_sample("mariana.ogg");
	sample[MordidaCanibal] = al_load_sample("mordida.ogg");
	sample[VitoriaCanibalSong] = al_load_sample("vitoriacanibal.ogg");
	sample[VirarPagina] = al_load_sample("virarPagina.ogg");
	sample[MusicaDoCanibal] = al_load_sample("ellia.ogg");

	// VirarPagina, MordidaCanibal, VitoriaCanibal, MusicaDoCanibal };
	sampleInstance[MordidaCanibal] = al_create_sample_instance(sample[MordidaCanibal]);
	sampleInstance[VitoriaCanibalSong] = al_create_sample_instance(sample[VitoriaCanibalSong]);
	sampleInstance[VirarPagina] = al_create_sample_instance(sample[VirarPagina]);
	sampleInstance[MusicaDoCanibal] = al_create_sample_instance(sample[MusicaDoCanibal]);
	sampleInstance[Yay] = al_create_sample_instance(sample[Yay]);
	sampleInstance[SomDaGalinha] = al_create_sample_instance(sample[SomDaGalinha]);
	sampleInstance[MusicaDaFazenda] = al_create_sample_instance(sample[MusicaDaFazenda]);
	sampleInstance[MusicaDoMenu] = al_create_sample_instance(sample[MusicaDoMenu]);
	
	al_set_sample_instance_playmode(sampleInstance[MusicaDoCanibal], ALLEGRO_PLAYMODE_LOOP);
	al_set_sample_instance_playmode(sampleInstance[MusicaDaFazenda], ALLEGRO_PLAYMODE_LOOP);
	al_set_sample_instance_playmode(sampleInstance[MusicaDoMenu], ALLEGRO_PLAYMODE_LOOP);

	al_attach_sample_instance_to_mixer(sampleInstance[MusicaDoCanibal], al_get_default_mixer());
	al_attach_sample_instance_to_mixer(sampleInstance[VirarPagina], al_get_default_mixer());
	al_attach_sample_instance_to_mixer(sampleInstance[VitoriaCanibalSong], al_get_default_mixer());
	al_attach_sample_instance_to_mixer(sampleInstance[MordidaCanibal], al_get_default_mixer());
	al_attach_sample_instance_to_mixer(sampleInstance[Yay], al_get_default_mixer());
	al_attach_sample_instance_to_mixer(sampleInstance[SomDaGalinha], al_get_default_mixer());
	al_attach_sample_instance_to_mixer(sampleInstance[MusicaDaFazenda], al_get_default_mixer());
	al_attach_sample_instance_to_mixer(sampleInstance[MusicaDoMenu], al_get_default_mixer());

	//carregando a imagem e fontes
	font[midnight] = al_load_font("midnight.ttf", 34, 0);
	font[cloning] = al_load_font("cloning.ttf", 44, 0);
	font[kelam] = al_load_font("kelam.ttf", 24, 0);
	font[bubblegum] = al_load_font("Bubblegum.ttf", 36, 0);

	bitmapsFazenda[Fumaca] = al_load_bitmap("smoke.png");
	bitmapsFazenda[BackGround] = al_load_bitmap("meio.png");
	bitmapsFazenda[Repolho] = al_load_bitmap("repolho.png");
	bitmapsFazenda[Lobo] = al_load_bitmap("lobo.png");
	bitmapsFazenda[Ovelha] = al_load_bitmap("ovelha.png");
	bitmapsFazenda[Pescador] = al_load_bitmap("pescador.png");
	bitmapsFazenda[PescadorComLobo] = al_load_bitmap("pescadorComLobo.png");
	bitmapsFazenda[PescadorComOvelha] = al_load_bitmap("pescadorComOvelha.png");
	bitmapsFazenda[PescadorComRepolho] = al_load_bitmap("pescadorComRepolho.png");
	bitmapsFazenda[Carne] = al_load_bitmap("carne.png");

	//Tirando o fundo das imagens, enquanto não passar todas elas para PNG

	al_convert_mask_to_alpha(bitmapsFazenda[Carne], al_map_rgb(255, 255, 255));
	al_convert_mask_to_alpha(bitmapsFazenda[Fumaca], al_map_rgb(255, 255, 255));
	al_convert_mask_to_alpha(bitmapsFazenda[PescadorComRepolho], al_map_rgb(0, 0, 0));
	al_convert_mask_to_alpha(bitmapsFazenda[PescadorComOvelha], al_map_rgb(0, 0, 0));
	al_convert_mask_to_alpha(bitmapsFazenda[PescadorComLobo], al_map_rgb(0, 0, 0));
	al_convert_mask_to_alpha(bitmapsFazenda[Repolho], al_map_rgb(0, 0, 0));
	al_convert_mask_to_alpha(bitmapsFazenda[Pescador], al_map_rgb(0, 0, 0));
	al_convert_mask_to_alpha(bitmapsFazenda[Ovelha], al_map_rgb(0, 0, 0));
	al_convert_mask_to_alpha(bitmapsFazenda[Lobo], al_map_rgb(255, 255, 255));

	iniciarVariaveis(ovelhaStruct, loboStruct, repolhoStruct, pescadorStruct);

	return true;
}

void desenharPlano(Tovelha ovelhaStruct, Tlobo loboStruct, Tpescador pescadorStruct, Trepolho repolhoStruct, int modoDaDerrota){

	if (pescadorStruct.objeto == 0){
		al_clear_to_color(al_map_rgb(120, 236, 83));
		al_draw_bitmap(bitmapsFazenda[BackGround], 0, 0, 0);
		al_draw_textf(font[midnight], al_map_rgb(240, 240, 240), 100, 2, 0, "Tempo : %d", count / 60);
		al_draw_bitmap(bitmapsFazenda[Pescador], pescadorStruct.x, pescadorStruct.y, 0);
		if (modoDaDerrota != 1){
			al_draw_bitmap(bitmapsFazenda[Lobo], loboStruct.x, loboStruct.y, 0);
		}
		if (modoDaDerrota != 2){
			al_draw_bitmap(bitmapsFazenda[Repolho], repolhoStruct.x, repolhoStruct.y, 0);
		}
		if (modoDaDerrota != 1 && modoDaDerrota != 2){
			al_draw_bitmap(bitmapsFazenda[Ovelha], ovelhaStruct.x, ovelhaStruct.y, 0);
		}
	}
	else if (pescadorStruct.objeto == 1){
		al_clear_to_color(al_map_rgb(120, 236, 83));
		al_draw_bitmap(bitmapsFazenda[BackGround], 0, 0, 0);
		al_draw_textf(font[midnight], al_map_rgb(240, 240, 240), 100, 2, 0, "Tempo : %d", count / 60);
		al_draw_bitmap(bitmapsFazenda[PescadorComOvelha], pescadorStruct.x, pescadorStruct.y, 0);

		if (modoDaDerrota != 1){
			al_draw_bitmap(bitmapsFazenda[Lobo], loboStruct.x, loboStruct.y, 0);
		}
		if (modoDaDerrota != 2){
			al_draw_bitmap(bitmapsFazenda[Repolho], repolhoStruct.x, repolhoStruct.y, 0);
		}
	}
	else if (pescadorStruct.objeto == 2){
		al_clear_to_color(al_map_rgb(120, 236, 83));
		al_draw_bitmap(bitmapsFazenda[BackGround], 0, 0, 0);
		al_draw_textf(font[midnight], al_map_rgb(240, 240, 240), 100, 2, 0, "Tempo : %d", count / 60);
		al_draw_bitmap(bitmapsFazenda[PescadorComLobo], pescadorStruct.x, pescadorStruct.y, 0);
		if (modoDaDerrota != 1 && modoDaDerrota != 2){
			al_draw_bitmap(bitmapsFazenda[Ovelha], ovelhaStruct.x, ovelhaStruct.y, 0);
		}
		if (modoDaDerrota != 2){
			al_draw_bitmap(bitmapsFazenda[Repolho], repolhoStruct.x, repolhoStruct.y, 0);
		}
	}
	else if (pescadorStruct.objeto == 3){
		al_clear_to_color(al_map_rgb(120, 236, 83));
		al_draw_bitmap(bitmapsFazenda[BackGround], 0, 0, 0);
		al_draw_textf(font[midnight], al_map_rgb(240, 240, 240), 100, 2, 0, "Tempo : %d", count / 60);
		al_draw_bitmap(bitmapsFazenda[PescadorComRepolho], pescadorStruct.x, pescadorStruct.y, 0);
		if (modoDaDerrota != 1 && modoDaDerrota != 2){
			al_draw_bitmap(bitmapsFazenda[Ovelha], ovelhaStruct.x, ovelhaStruct.y, 0);
		}
		if (modoDaDerrota != 1){
			al_draw_bitmap(bitmapsFazenda[Lobo], loboStruct.x, loboStruct.y, 0);
		}
	}
}

void fazerAnimacoes(Tovelha * ovelhaStruct, Tlobo * loboStruct, Tpescador * pescadorStruct, Trepolho * repolhoStruct){

	if (pescadorStruct->animando){
		if (pescadorStruct->lado == 1){

			pescadorStruct->x = pescadorStruct->x - 5;
			pescadorStruct->limiteX = pescadorStruct->x + pescadorStruct->width;

			if (pescadorStruct->x == 180){
				pescadorStruct->lado = 0;
				pescadorStruct->animando = false;
			}
		}
		else{
			pescadorStruct->x = pescadorStruct->x + 5;
			pescadorStruct->limiteX = pescadorStruct->x + pescadorStruct->width;

			if (pescadorStruct->x == 390){
				pescadorStruct->lado = 1;
				pescadorStruct->animando = false;
			}
		}
	}
	else if (ovelhaStruct->animando){
		ovelhaStruct->y = ovelhaStruct->y - 2;
		ovelhaStruct->limiteY = ovelhaStruct->y + ovelhaStruct->height;

		if (ovelhaStruct->y <= repolhoStruct->limiteY){
			al_draw_bitmap(bitmapsFazenda[Fumaca], (repolhoStruct->x - 30), repolhoStruct->y - 20, 0);
			al_flip_display();
			al_rest(0.1);
			ovelhaStruct->animando = false;
		}
	}
	else if (loboStruct->animando){
		if (loboStruct->limiteY >= ovelhaStruct->y){
			desenharPlano(*ovelhaStruct, *loboStruct, *pescadorStruct, *repolhoStruct, 1);
			al_draw_bitmap(bitmapsFazenda[Fumaca], (ovelhaStruct->x - 5), ovelhaStruct->y, 0);
			al_flip_display();
			al_rest(0.2);
			loboStruct->animando = false;
		}
		else{
			loboStruct->y = loboStruct->y + 1;
			loboStruct->limiteY = loboStruct->y + loboStruct->height;
		}
	}
}

void moverImagem(Tovelha * ovelhaStruct, Tlobo * loboStruct, Tpescador * pescadorStruct, Trepolho * repolhoStruct, int click){

	if (click == 0){// o cara clicou na ovelha, independente de onde ela esteja, farei as comparações aqui dentro
		if (ovelhaStruct->withPescador){
			if (pescadorStruct->lado == 1){
				ovelhaStruct->x = 694;
				ovelhaStruct->y = 523;
				ovelhaStruct->withPescador = false;
				pescadorStruct->full = false;
				pescadorStruct->objeto = 0;
				ovelhaStruct->lado = pescadorStruct->lado;
				ovelhaStruct->limiteX = ovelhaStruct->x + ovelhaStruct->width;
				ovelhaStruct->limiteY = ovelhaStruct->y + ovelhaStruct->height;
			}
			else{//ovelha com o pescador, do lado ESQUERDO
				ovelhaStruct->x = 5;
				ovelhaStruct->y = 523;
				ovelhaStruct->withPescador = false;
				pescadorStruct->full = false;
				pescadorStruct->objeto = 0;
				ovelhaStruct->lado = pescadorStruct->lado;
				ovelhaStruct->limiteX = ovelhaStruct->x + ovelhaStruct->width;
				ovelhaStruct->limiteY = ovelhaStruct->y + ovelhaStruct->height;
			}
		}
		else if (ovelhaStruct->lado == pescadorStruct->lado && !pescadorStruct->full){	//ovelha está no mesmo lado do pescador 
			//mas pode ser que tenha gente com o pescador
			if (ovelhaStruct->lado == 1){
				ovelhaStruct->x = 446;
				ovelhaStruct->y = 416;//449
				ovelhaStruct->withPescador = true;
				pescadorStruct->full = true;
				pescadorStruct->objeto = 1;
				ovelhaStruct->limiteX = ovelhaStruct->x + ovelhaStruct->width;
				ovelhaStruct->limiteY = ovelhaStruct->y + ovelhaStruct->height - 33;

			}
			else{
				ovelhaStruct->x = 238;
				ovelhaStruct->y = 416;
				ovelhaStruct->withPescador = true;
				pescadorStruct->full = true;
				pescadorStruct->objeto = 1;
				ovelhaStruct->limiteX = ovelhaStruct->x + ovelhaStruct->width;
				ovelhaStruct->limiteY = ovelhaStruct->y + ovelhaStruct->height;
			}

		}

	}
	else if (click == 1){//click no lobo

		if (loboStruct->withPescador){
			if (pescadorStruct->lado == 1){
				loboStruct->x = 670;
				loboStruct->y = 390;
				loboStruct->withPescador = false;
				loboStruct->lado = pescadorStruct->lado;
				pescadorStruct->full = false;
				pescadorStruct->objeto = 0;
				loboStruct->limiteX = loboStruct->x + loboStruct->width;
				loboStruct->limiteY = loboStruct->y + loboStruct->height;

			}
			else{
				loboStruct->x = 0;
				loboStruct->y = 390;
				loboStruct->withPescador = false;
				loboStruct->lado = pescadorStruct->lado;
				pescadorStruct->full = false;
				pescadorStruct->objeto = 0;
				loboStruct->limiteX = loboStruct->x + loboStruct->width;
				loboStruct->limiteY = loboStruct->y + loboStruct->height;
			}
		}
		else if (pescadorStruct->lado == loboStruct->lado && !pescadorStruct->full){
			if (loboStruct->lado == 1){//lobo vai entrar no barco
				loboStruct->x = 435;
				loboStruct->y = 394;
				loboStruct->withPescador = true;
				pescadorStruct->full = true;
				pescadorStruct->objeto = 2;
				loboStruct->limiteX = loboStruct->x + loboStruct->width;
				loboStruct->limiteY = loboStruct->y + loboStruct->height;
			}
			else {
				loboStruct->x = 226;
				loboStruct->y = 395;
				loboStruct->withPescador = true;
				pescadorStruct->full = true;
				pescadorStruct->objeto = 2;
				loboStruct->limiteX = loboStruct->x + loboStruct->width;
				loboStruct->limiteY = loboStruct->y + loboStruct->height;
			}
		}
	}
	else if (click == 2){
		if (repolhoStruct->withPescador){
			if (pescadorStruct->lado == 1){
				repolhoStruct->x = 740;
				repolhoStruct->y = 320;
				repolhoStruct->withPescador = false;
				repolhoStruct->lado = pescadorStruct->lado;
				repolhoStruct->limiteX = repolhoStruct->x + repolhoStruct->width;
				repolhoStruct->limiteY = repolhoStruct->y + repolhoStruct->height;

				//ajustando o pescador
				pescadorStruct->full = false;
				pescadorStruct->objeto = 0;
			}
			else {
				repolhoStruct->x = 5;
				repolhoStruct->y = 320;
				repolhoStruct->withPescador = false;
				repolhoStruct->lado = pescadorStruct->lado;
				repolhoStruct->limiteX = repolhoStruct->x + repolhoStruct->width;
				repolhoStruct->limiteY = repolhoStruct->y + repolhoStruct->height;

				pescadorStruct->full = false;
				pescadorStruct->objeto = 0;
			}

		}
		else if (pescadorStruct->lado == repolhoStruct->lado && !pescadorStruct->full){
			if (repolhoStruct->lado == 1){
				repolhoStruct->x = 478;
				repolhoStruct->y = 450;//390
				repolhoStruct->withPescador = true;
				repolhoStruct->limiteX = repolhoStruct->x + repolhoStruct->width;
				repolhoStruct->limiteY = repolhoStruct->y + repolhoStruct->height;

				pescadorStruct->full = true;
				pescadorStruct->objeto = 3;
			}
			else{
				repolhoStruct->x = 268;
				repolhoStruct->y = 440;
				repolhoStruct->withPescador = true;
				repolhoStruct->limiteX = repolhoStruct->x + repolhoStruct->width;
				repolhoStruct->limiteY = repolhoStruct->y + repolhoStruct->height;

				pescadorStruct->full = true;
				pescadorStruct->objeto = 3;
			}

		}

	}
	else if (click == 3)//click no pescador, fazer a animação do pescador andando
	{
		if (pescadorStruct->lado == 1){// pescador do lado direito		
			if (pescadorStruct->objeto == 0){

				pescadorStruct->animando = true;

			}
			else if (pescadorStruct->objeto == 1){
				pescadorStruct->animando = true;

				ovelhaStruct->x = 238;
				ovelhaStruct->limiteX = ovelhaStruct->x + ovelhaStruct->width;


			}
			else if (pescadorStruct->objeto == 2){
				pescadorStruct->animando = true;
				loboStruct->x = 226;
				loboStruct->limiteX = loboStruct->x + loboStruct->width;
			}
			else if (pescadorStruct->objeto == 3){
				pescadorStruct->animando = true;
				repolhoStruct->x = 268;
				repolhoStruct->limiteX = repolhoStruct->x + repolhoStruct->width;
			}
		}
		else{//pescador do lado esquerdo

			if (pescadorStruct->objeto == 0){
				pescadorStruct->animando = true;

			}
			else if (pescadorStruct->objeto == 1){//ovelha
				pescadorStruct->animando = true;

				ovelhaStruct->x = 400;
				ovelhaStruct->limiteX = ovelhaStruct->x + 106;

			}
			else if (pescadorStruct->objeto == 2){//lobo
				pescadorStruct->animando = true;

				loboStruct->x = 400;
				loboStruct->limiteX = loboStruct->x + 130;


			}
			else if (pescadorStruct->objeto == 3){
				pescadorStruct->animando = true;

				repolhoStruct->x = 460;
				repolhoStruct->limiteX = repolhoStruct->x + repolhoStruct->width;
			}
		}
	}
}

int calcularClick(int pos_x, int pos_y, Tovelha ovelhaStruct, Tlobo loboStruct, Tpescador pescadorStruct, Trepolho repolhoStruct){

	if ((pos_x >= ovelhaStruct.x && pos_x <= ovelhaStruct.limiteX) && (pos_y >= ovelhaStruct.y && pos_y <= ovelhaStruct.limiteY)){
		return 0;
	}
	else if (((pos_x >= loboStruct.x + 20) && (pos_x <= loboStruct.limiteX)) && (pos_y >= loboStruct.y && pos_y <= loboStruct.limiteY)){
		return 1;
	}
	else if ((pos_x >= repolhoStruct.x && pos_x <= repolhoStruct.limiteX) && (pos_y >= repolhoStruct.y && pos_y <= repolhoStruct.limiteY)){
		return 2;
	}
	else if ((pos_x >= pescadorStruct.x && pos_x <= pescadorStruct.limiteX) && (pos_y >= pescadorStruct.y && pos_y <= pescadorStruct.limiteY)){
		return 3;
	}
	return -1;
}

int checarJogada(Tovelha * ovelhaStruct, Tlobo * loboStruct, Trepolho *repolhoStruct, Tpescador * pescadorStruct){
	if (repolhoStruct->lado == 0 && ovelhaStruct->lado == 0 && loboStruct->lado == 0 && (!loboStruct->withPescador) && (!ovelhaStruct->withPescador) && (!repolhoStruct->withPescador)){
		return Vitoria;
	}
	else if (loboStruct->lado == ovelhaStruct->lado && (!loboStruct->withPescador) && (!ovelhaStruct->withPescador) && !(loboStruct->lado == pescadorStruct->lado)){
		
		loboStruct->animando = true;
		return DerrotaLoboComOvelha;
	}
	else if (ovelhaStruct->lado == repolhoStruct->lado && (!repolhoStruct->withPescador) && (!ovelhaStruct->withPescador) && !(ovelhaStruct->lado == pescadorStruct->lado)){
		ovelhaStruct->animando = true;
		return DerrotaOvelhaComRepolho;
	}
	else{
		return NadaAconteceu;
	}
}

void derrotaFazenda(Tovelha *ovelhaStruct, Tlobo * loboStruct, Tpescador *pescadorStruct, Trepolho *repolhoStruct, int modoDaDerrota){
	
	if (modoDaDerrota == DerrotaLoboComOvelha){
		if (loboStruct->animando){
			fazerAnimacoes(ovelhaStruct, loboStruct, pescadorStruct, repolhoStruct);
			desenharPlano(*ovelhaStruct, *loboStruct, *pescadorStruct, *repolhoStruct, NadaAconteceu);
		}
		else{
			if (gambiarra){
				desenharPlano(*ovelhaStruct, *loboStruct, *pescadorStruct, *repolhoStruct, modoDaDerrota);
				al_draw_bitmap(bitmapsFazenda[Carne], (ovelhaStruct->x + 30), (ovelhaStruct->y + 20), 0);
				al_flip_display();
				al_rest(0.2);
				gambiarra = 0;
			}
			else{
				desenharPlano(*ovelhaStruct, *loboStruct, *pescadorStruct, *repolhoStruct, modoDaDerrota);
				al_draw_filled_rectangle(250, 100, 650, 300, al_map_rgb(30, 30, 150));
				al_draw_rectangle(260, 110, 640, 290, al_map_rgb(255, 255, 255), 5);
				al_draw_text(font[cloning], al_map_rgb(250, 250, 250), 290, 130, 0, "Voce Perdeu");
				al_draw_textf(font[kelam], al_map_rgb(255, 255, 255), 290, 230, 0, "Jogar Novamente");
				al_draw_text(font[kelam], al_map_rgb(255, 255, 255), 570, 230, 0, "Inicio");
			}
			al_draw_bitmap(bitmapsFazenda[Lobo], ovelhaStruct->x - 25, ovelhaStruct->y - 40, 0);
		}
	}
	else if (modoDaDerrota == DerrotaOvelhaComRepolho){
		if (ovelhaStruct->animando){
			fazerAnimacoes(ovelhaStruct, loboStruct, pescadorStruct, repolhoStruct);
			desenharPlano(*ovelhaStruct, *loboStruct, *pescadorStruct, *repolhoStruct, NadaAconteceu);
		}
		else{
			desenharPlano(*ovelhaStruct, *loboStruct, *pescadorStruct, *repolhoStruct, modoDaDerrota);
			al_draw_filled_rectangle(250, 100, 650, 300, al_map_rgb(30, 30, 150));
			al_draw_rectangle(260, 110, 640, 290, al_map_rgb(255, 255, 255), 5);
			al_draw_text(font[cloning], al_map_rgb(250, 250, 250), 290, 130, 0, "Voce Perdeu");
			al_draw_textf(font[kelam], al_map_rgb(255, 255, 255), 290, 230, 0, "Jogar Novamente");
			al_draw_text(font[kelam], al_map_rgb(255, 255, 255), 570, 230, 0, "Inicio");
			al_draw_bitmap(bitmapsFazenda[Ovelha], repolhoStruct->x - 40, repolhoStruct->y - 25, 0);
		}

	}	
}

void vitoriaFazenda(Tovelha ovelhaStruct, Tlobo loboStruct, Tpescador pescadorStruct, Trepolho repolhoStruct){	
	desenharPlano(ovelhaStruct, loboStruct, pescadorStruct, repolhoStruct, NadaAconteceu);
	al_draw_filled_rectangle(250, 100, 650, 300, al_map_rgb(30, 30, 150));
	al_draw_rectangle(260, 110, 640, 290, al_map_rgb(255, 255, 255), 5);
	al_draw_text(font[cloning], al_map_rgb(250, 250, 250), 290, 130, 0, "Voce Ganhou");
	al_draw_textf(font[kelam], al_map_rgb(255, 255, 255), 350, 250, 0, "Jogar Novamente");
	al_draw_text(font[kelam], al_map_rgb(255, 255, 255), 350, 200, 0, "Salvar Resultado");	
}