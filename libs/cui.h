#ifndef CUI_LIB
#define CUI_LIB

#include "logica.h"

/**
 * Console User Interface
 */

/* Lê tamanho de tabuleiro desejado pelo jogador */
void getFieldSize(Jogo *jogo);

/* Mostra o campo */
void showField(Jogo *jogo, int debug);

/* Lê próxima jogada */
void getNextPlayed(int *nextX, int *nextY, Jogo *jogo, int *mode);

#endif
