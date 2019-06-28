#include "../libs/events.h"
#include "../libs/gui.h"
#include <GL/glut.h>
#include <stdio.h>


/* ############################# */
/* # Movimentos passivos mouse # */
/* ############################# */

/**
 *  Localizações dos retangulos importantes
 *
 *  ## 8x8 ##
 *  X - -0.55 até -0.15
 *  Y -  0.00 até  0.50
 *
 *  ## 16x16 ##
 *  X -  0.15 até  0.55
 *  Y -  0.00 até  0.50
 *
 *  ## 30x16 ##
 *  X - -0.30 até  0.30
 *  Y - -0.25 até -0.75
 */
void mouseMoveTelaInicial(int x, int y)
{
    float coord_x = (float) x / 600;
    float coord_y = (float) y / 400;

    if (coord_x >= 0.225 && coord_x <= 0.425 &&
        coord_y >= 0.25  && coord_y <= 0.5)
    {
        // Hover no botão 8x8
        glutSetCursor(GLUT_CURSOR_INFO);
    }
    else if (coord_x >= 0.575 && coord_x <= 0.775 &&
             coord_y >= 0.25  && coord_y <= 0.5) 
    {
        // Hover no botão 16x16
        glutSetCursor(GLUT_CURSOR_INFO);
    }
    else if ( coord_x >= 0.35 && coord_x <= 0.65 &&
              coord_y >= 0.625  && coord_y <= 0.875)
    {
        // Hover no botão 30x16
        glutSetCursor(GLUT_CURSOR_INFO);
    }
    else
    {
        glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
        printf("X: %i Y: %i\n", x, y);
    }

    // DEBUG
    // printf("%f %f\n", coord_x/600, coord_y / 400);
}

/* ########### */
/* # Cliques # */
/* ########### */
void clickTelaInicial(int button, int status, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && status == GLUT_DOWN)
    {
        // Pintar tabuleiro desejado
        float coord_x = (float) x / 600;
        float coord_y = (float) y / 400;

        if (coord_x >= 0.225 && coord_x <= 0.425 &&
            coord_y >= 0.25  && coord_y <= 0.5)
        {
            // Hover no botão 8x8
            glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
            tabuleiro(8, 8);
        }
        else if (coord_x >= 0.575 && coord_x <= 0.775 &&
                 coord_y >= 0.25  && coord_y <= 0.5) 
        {
            // Hover no botão 16x16
            glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
            tabuleiro(16, 16);
        }
        else if (coord_x >= 0.35 && coord_x <= 0.65 &&
                 coord_y >= 0.625  && coord_y <= 0.875)
        {
            // Hover no botão 30x16
            glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
            tabuleiro(30, 16);
        }
        else
        {
            glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
            printf("X: %i Y: %i\n", x, y);
        }
    }
}


/* ############################### */
/* # Manter tamanhos das janelas # */
/* ############################### */

void resizeTelaInicial(int x, int y)
{
    glutReshapeWindow(600, 400);
}
