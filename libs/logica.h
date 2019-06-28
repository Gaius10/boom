#ifndef LOGICA_H
#define LOGICA_H

typedef struct {
    int status;
    int qtdBombas;
    int **campo;
    int **campoVisivel;
} Jogo;

/**
 * Cria tabuleiro de dimensoes w por h
 * Planta bombas
 * Conta bombas
 */
void prepare(int w, int h, Jogo *jogo);

/**
 * Registra jogada e atualiza status
 */
void play(int x, int y);

/**
 *  Salva ranking num arquivo
 */
void saveRanking();

#endif
