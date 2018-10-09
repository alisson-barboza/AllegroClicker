OBJETIVO DO JOGO:
O jogo tem como objetivo exercitar o raciocínio lógico do jogador com jogos de clique que requerem uma ordem lógica para serem completados (vencidos).
A biblioteca proposta para a criação do jogo foi a Allegro (utilizei a versão 5) e a linguagem de programação escolhida foi C.

INSTRUÇÕES PARA INSTALAR O ALLEGRO:
Baixe o allegro 5, e coloque a pasta dele na pasta C do seu computador e siga as instruções abaixo.


INSTRUÇÕES PARA CONFIGURAR O ALLEGRO (NO VISUAL STUDIO):
1- Abra as propriedades do seu projeto, clicando com o botão direito abaixo do Solution Explorer

2- Em Configuration Properties -> Debugging > Environment, coloque:
PATH=C:\allegro5010\bin;%PATH% (supondo que a sua pasta do allegro esteja no C: e que o nome da mesma seja allegro5010, falarei mais sobre isso em seguida)

3- Em Configuration Properties -> Linker -> General > in Additional Library Directories, coloque:
C:\allegro5010\lib

4- Em Configuration Properties ->Linker->Input > Additional Dependecies, insira um ponto e vírgula bem ao final sem deixar espaço, e logo após insira:
allegro-5.0.1.0-monolith-md-debug.lib



