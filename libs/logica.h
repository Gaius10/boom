#ifndef LOGICA_H
#define LOGICA_H

typedef struct {
    int status;
    int mines;
    int fieldSize[2];
    int **field;
    int **visibleField;
    char * error;
} Jogo;

/* Configura o campo antes do jogo começar (Define localização das bombas) */
void setField(Jogo *jogo);

/* Registra próxima jogada e verifica viórias e derrotas */
void play(int x, int y, Jogo *jogo, int mode);

/* Registra nomes dos jogadores vencedores */
void saveRanking();

#endif
