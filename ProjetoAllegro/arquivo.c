#include"arquivo.h"
#include<string.h>
#include<stdlib.h>


void pegarDadosDigitados(ALLEGRO_EVENT evento, char str[])
{
	if (evento.type == ALLEGRO_EVENT_KEY_CHAR)
	{
		if (strlen(str) <= 16)
		{
			char temp[] = { evento.keyboard.unichar, '\0' };
			if (evento.keyboard.unichar == ' ')
			{
				strcat(str, temp);
			}
			else if (evento.keyboard.unichar >= '0' &&
				evento.keyboard.unichar <= '9')
			{
				strcat(str, temp);
			}
			else if (evento.keyboard.unichar >= 'A' &&
				evento.keyboard.unichar <= 'Z')
			{
				strcat(str, temp);
			}
			else if (evento.keyboard.unichar >= 'a' &&
				evento.keyboard.unichar <= 'z')
			{
				strcat(str, temp);
			}
		}

		if (evento.keyboard.keycode == ALLEGRO_KEY_BACKSPACE && strlen(str) != 0)
		{
			str[strlen(str) - 1] = '\0';
		}
	}
}

void cadastrarArquivo(int tempo, FILE * arq, char nome[]){
	Tarquivo arquivoStruct;
	int status, i;

	fseek(arq, 0, 2);
	
	strcpy(arquivoStruct.nome, nome);
	arquivoStruct.tempo = tempo / 60;
	status = fwrite(&arquivoStruct, sizeof(Tarquivo), 1, arq);
	
}

	void lerArquivo(FILE *arq){
		Tarquivo lido;
		int status = 0;
		int i = 1;

		fseek(arq, 0, 0);
		al_clear_to_color(al_map_rgb(0, 0, 0));
		while (1){
			status = fread(&lido, sizeof(Tarquivo), 1, arq);
			if (status != 1){
				if (i == 1){
					al_draw_text(font[kelam], al_map_rgb(255, 255, 255), 200, 100, 0, "Nenhum Score Cadastrado");
					al_flip_display();
					break;
				}
				else{
					break;
				}
			}
			else{
				al_draw_text(font[kelam], al_map_rgb(255, 255, 255), 200, 50, 0, "Nome             Tempo");
				al_draw_textf(font[kelam], al_map_rgb(255, 255, 255), 200, 100 * i, 0, "%d - %s ______ %d", i, lido.nome, lido.tempo);
				i++;
				al_flip_display();
			}
		}

	}
