#include <stdio.h>
#include "libs/gui.h"
#include "libs/logica.h"
#include "libs/draws.h"

typedef struct
{
    int status = 0;

} Jogo;

int main(int argc, char **argv)
{
    // Mostrar tela de escolha do tamanho do tabuleiro
    telaInicial(&argc, argv);
    
    // Captar regiao do clique e gerar tabuleiro (Parte lógica)w
    // Mostrar tabuleiro
    
    // [Ciclo]
    // Captar clique
    // Processar clique (Parte lógica)
    // Saída
    
    // [Em caso de erros]
    // Criar arquivo para log (Parte lógica)
    
    // [Ao fim do jogo]
	// No caso de quebra de records, salvar dados do jogador num ranking e 
	// dados da partida
	
    return 0;
}
