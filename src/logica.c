#include "../libs/logica.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void prepare(int w, int h, Jogo *jogo)
{
   jogo->campo = malloc(sizeof(int *) * h);
   jogo->campo[0] = malloc(sizeof(int) * w);
   int totBombas = 0;


   for(int i=0; i<w; i++)
	{	
		for(int j=0; j<h; j++)
		{	
			jogo->campo[i][j]=0;
		}
	}		
   for(int i=0; i<totBombas; i++)
   {
	   srand(time(NULL));
	   int x = rand() % w;
	   int y = rand() % h;

	   if(jogo->campo[x][y]==9)
	   		i--;	

	   jogo->campo[x][y] = 9;
	}
	for(int i=0; i<w; i++)
	{	
		for(int j=0; j<h; j++)
		{	
			if(jogo->campo[i][j] == 9)
			{
				if(jogo->campo[i - 1][j - 1] != 9 && i - 1 >= 0 && j - 1 >= 0)
					jogo->campo[i - 1][j - 1]++;

				if(jogo->campo[i - 1][j + 1] != 9 && i - 1 >= 0 && j + 1 >= 0)
					jogo->campo[i - 1][j + 1]++;

				if(jogo->campo[i - 1][j + 1] != 9 && i - 1 >= 0 && j + 1 >= 0)
					jogo->campo[i - 1][j + 1]++;

				if(jogo->campo[i + 1][j - 1] != 9 && i + 1 >= 0 && j - 1 >= 0)
					jogo->campo[i + 1][j - 1]++;

				if(jogo->campo[i + 1][j + 1] != 9 && i + 1 >= 0 && j + 1 >= 0)
					jogo->campo[i + 1][j + 1]++;

				if(jogo->campo[i + 1][j + 1] != 9 && i + 1 >= 0 && j + 1 >= 0)
					jogo->campo[i + 1][j + 1]++;

				if(jogo->campo[i+1][j-1] != 9 && i + 1 >= 0 && j - 1 >= 0)
					jogo->campo[i + 1][j - 1]++;

				if(jogo->campo[i+1][j+1] != 9 && i + 1 >= 0 && j + 1 >= 0)
					jogo->campo[i + 1][j + 1]++;
			}
		}
	}  
}
