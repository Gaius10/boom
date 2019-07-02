#include "../libs/cui.h"
#include <stdio.h>
#include <stdlib.h>

void getFieldSize(Jogo *jogo)
{
    char opt;

    printf("\n Defina o tamanho do tabuleiro:\n \
        (1) 8x8 - 10 Minas\n \
        (2) 16x16 - 40 Minas\n \
        (3) 30x16 - 99 Minas\n");

    do
    {
        printf(" > ");
        scanf(" %c", &opt);
    } while (opt != '1' && opt != '2' && opt != '3');

    switch(opt)
    {
        case '1':
            jogo->fieldSize[0] = 8;
            jogo->fieldSize[1] = 8;
            jogo->mines = 10;
            break;
        case '2':
            jogo->fieldSize[0] = 16;
            jogo->fieldSize[1] = 16;
            jogo->mines = 40;
            break;
        case '3':
            jogo->fieldSize[0] = 30;
            jogo->fieldSize[1] = 16;
            jogo->mines = 99;
            break;
    }

    jogo->field = malloc(sizeof(int *) * jogo->fieldSize[0]);
    jogo->visibleField = malloc(sizeof(int *) * jogo->fieldSize[0]);

    for (int i = 0; i < jogo->fieldSize[1]; i++)
    {
        jogo->field[i] = malloc(sizeof(int) * jogo->fieldSize[1]);
        jogo->visibleField[i] = malloc(sizeof(int) * jogo->fieldSize[1]);
    }
}

void showField(Jogo *jogo, int debug)
{    
    printf("\n");
    if (debug)
    {
        for (int i = 0; i < jogo->fieldSize[0]; i++)
        {
            for (int j = 0; j < jogo->fieldSize[1]; j++)
            {
                printf(" [%2i] ", jogo->field[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }

    for (int i = 0; i < jogo->fieldSize[0]; i++)
    {
        for (int j = 0; j < jogo->fieldSize[1]; j++)
        {
            printf(" [%2i] ", jogo->visibleField[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("\n");
}

void getNextPlayed(int *nextX, int *nextY, Jogo *jogo, int *mode)
{
    printf("Você deseja _jogar_(1) ou _marcar mina_(0)?\n");
    do
    {
        printf(" > ");
        scanf("%i", mode);
    } while(*mode != 0 && *mode != 1);

    printf("Digite sua próxima jogada: \n");
    do
    {
        printf(" X > ");
        scanf("%i", nextX);
    } while (*nextX < 1 || *nextX > jogo->fieldSize[0]);
    
    do
    {
        printf(" Y > ");
        scanf("%i", nextY);
    } while (*nextY < 1 || *nextY > jogo->fieldSize[0]);
}
