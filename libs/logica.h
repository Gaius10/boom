#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Cria tabuleiro de dimensoes w por h
 * Planta bombas
 * Conta bombas
 */
void init(int w, int h);

/**
 * Registra jogada e atualiza status
 */
void play(int x, int y);

/**
 *  Salva ranking num arquivo
 */
void saveRanking();
