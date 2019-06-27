#ifndef LOGICA_H
#define LOGICA_H

/**
 * Cria tabuleiro de dimensoes w por h
 * Planta bombas
 * Conta bombas
 */
void prepare(int w, int h);

/**
 * Registra jogada e atualiza status
 */
void play(int x, int y);

/**
 *  Salva ranking num arquivo
 */
void saveRanking();

#endif
