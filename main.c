#include "libs/logica.h"
#include "libs/cui.h"
#include <stdio.h>
#define DEBUG 1
// #include "libs/gui.h"
// #include "libs/events.h"
// #include "libs/draws.h"

int main(int argc, char **argv)
{
    int mode;
    int nextX;
    int nextY;
    Jogo jogo;
    jogo.status = 0;

    // Mostrar tela de escolha do tamanho do tabuleiro
    // telaInicial(&argc, argv);
    getFieldSize(&jogo);

    // Captar regiao do clique e gerar tabuleiro (Parte lógica)
    setField(&jogo);

    showField(&jogo, DEBUG);
    
    // [Ciclo]
    // Captar clique
    // Processar clique (Parte lógica)
    // Saída
    do
    {
        getNextPlayed(&nextX, &nextY, &jogo, &mode);
        play(nextX, nextY, &jogo, mode);
        showField(&jogo, DEBUG);
    } while(jogo.status == 0);
    
    // [Em caso de erros]
    // Criar arquivo para log (Parte lógica)
    
    // [Ao fim do jogo]
    if (jogo.status > 0)
    {
        printf("Parabéns, você venceu! :)\n");
        saveRanking();
    }
    else
    {
        printf("Você perdeu, tente novamente. :(");
    }
	// No caso de vitória, salvar dados do jogador num ranking e 
	// dados da partida
	
    return 0;
}
