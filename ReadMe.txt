OBJETIVO DO JOGO:
O jogo tem como objetivo exercitar o racioc�nio l�gico do jogador com jogos de clique que requerem uma ordem l�gica para serem completados (vencidos).
A biblioteca proposta para a cria��o do jogo foi a Allegro (utilizei a vers�o 5) e a linguagem de programa��o escolhida foi C.

INSTRU��ES PARA INSTALAR O ALLEGRO:
Baixe o allegro 5, e coloque a pasta dele na pasta C do seu computador e siga as instru��es abaixo.


INSTRU��ES PARA CONFIGURAR O ALLEGRO (NO VISUAL STUDIO):
1- Abra as propriedades do seu projeto, clicando com o bot�o direito abaixo do Solution Explorer

2- Em Configuration Properties -> Debugging > Environment, coloque:
PATH=C:\allegro5010\bin;%PATH% (supondo que a sua pasta do allegro esteja no C: e que o nome da mesma seja allegro5010, falarei mais sobre isso em seguida)

3- Em Configuration Properties -> Linker -> General > in Additional Library Directories, coloque:
C:\allegro5010\lib

4- Em Configuration Properties ->Linker->Input > Additional Dependecies, insira um ponto e v�rgula bem ao final sem deixar espa�o, e logo ap�s insira:
allegro-5.0.1.0-monolith-md-debug.lib



