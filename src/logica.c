#include "../libs/logica.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void setField(Jogo *jogo)
{
	srand(time(NULL));
    /* Preenche todo o tabuleiro com zeros */
  	for(int i = 0; i < jogo->fieldSize[0]; i++)
	{
		for(int j = 0; j < jogo->fieldSize[1]; j++)
		{
			jogo->field[i][j] = 0;
		}
	}

	/* Localiza bombas */
   	for(int i = 0; i < jogo->mines; i++)
    {
	    int x = rand() % jogo->fieldSize[0];
	    int y = rand() % jogo->fieldSize[1];

	    if(jogo->field[x][y] == 9)
	   		i--;
	   	else
	   		jogo->field[x][y] = 9;
	}


	/* Contar bombas */
	for(int i = 0; i < jogo->fieldSize[0] - 1; i++)
	{
		for(int j = 0; j < jogo->fieldSize[1] - 1; j++)
		{	
			if(jogo->field[i][j] != 9)
			{
				if (i > 0)
				{
					jogo->field[i][j] += jogo->field[i-1][j-1] == 9 ? 1 : 0;
					jogo->field[i][j] += jogo->field[i-1][j] == 9   ? 1 : 0;
					jogo->field[i][j] += jogo->field[i-1][j+1] == 9 ? 1 : 0;
				}
				if (i < jogo->fieldSize[1] - 2)
				{
					jogo->field[i][j] += jogo->field[i+1][j-1] == 9 ? 1 : 0;
					jogo->field[i][j] += jogo->field[i+1][j] == 9   ? 1 : 0;
					jogo->field[i][j] += jogo->field[i+1][j+1] == 9 ? 1 : 0;
				}
				if (j > 0)
					jogo->field[i][j] += jogo->field[i][j-1] == 9 ? 1 : 0;

				if (j < jogo->fieldSize[0] - 2)
					jogo->field[i][j] += jogo->field[i][j+1] == 9 ? 1 : 0;
			}
		}
	}  
}

void play(int x, int y, Jogo *jogo, int mode)
{
	/* Colocar "bandeirinha" */
	if (mode == 0)
	{
		if (jogo->visibleField[x-1][y-1] == -1)
		{
			jogo->visibleField = 0;
			if (jogo->field[x-1][y-1] == 9)
				jogo->mines++;
		}
		else
		{
			jogo->visibleField[x-1][y-1] = -1;
			if (jogo->field[x-1][y-1] == 9)
				jogo->mines--;
		}
		return;
	}

	// Perde o jogo
	if (jogo->field[x-1][y-1] == 9)
	{
		jogo->status--;
		return;
	}
	else
	{
		// Torna campo visível pro jogador
		jogo->visibleField[x-1][y-1] = jogo->field[x-1][y-1];
	}


	// Ganha o jogo
	if (jogo->mines == 0)
	{
		jogo->status++;
		return;
	}
}

void saveRanking()
{
	char c, lixo;
	char *string = (char *)malloc(1);
	int k = 0;
	FILE *ranking;
	time_t date = time(NULL);

	scanf("%c", &lixo);
	printf("Digite seu nome, você será salvo na lista dos deuses: \n > ");
	do
	{
		k++;
		string = realloc(string, sizeof(char) * k);

		scanf("%c", &c);
		string[k-1] = c == '\n' ? '\0' : c;
	} while (c != '\n');

	ranking = fopen("ranking.txt", "a");
	fprintf(ranking, "%s - %s", string, asctime(gmtime(&date)));
	fclose(ranking);
}
