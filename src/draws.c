#include "../libs/draws.h"
#include <GL/glut.h>
#include <stdio.h>

void drawTelaInicial(void)
{
    glClear(GL_COLOR_BUFFER_BIT); // Limpa buffer de imagem
    glColor3f(0.0f, 0.0f, 0.0f);  // Cor da fonte

    /* Escreve nome do jogo na tela */
    char *nome = "BOOM! - Seja bem vindo!";
    glRasterPos2f(-0.33f, 0.85f);
    while(*nome != '\0')
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *(nome++));
    }

    /* Texto informativo */
    char *text = "Escolha o tamanho desejado para o tabuleiro:";
    glRasterPos2f(-0.4f, 0.7f);
    while(*text != '\0')
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *(text++));
    }

    /** 
     *  Desenha os três quadrados de opções
     */
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    
    /** Opção 8x8 */
     glVertex2f(-0.55f, 0.5f);
     glVertex2f(-0.15f, 0.5f);
     glVertex2f(-0.15f, 0.0f);
     glVertex2f(-0.55f, 0.0f);

    /** Opção 16x16 */
     glVertex2f(0.55f, 0.5f);
     glVertex2f(0.15f, 0.5f);
     glVertex2f(0.15f, 0.0f);
     glVertex2f(0.55f, 0.0f);

     glVertex2f(-0.15f,  0.0f);
     glVertex2f( 0.15f,  0.0f);
     glVertex2f( 0.15f, -0.25f);
     glVertex2f(-0.15f, -0.25f);

    /** Opção 30x16 **/
     glVertex2f(-0.3f, -0.25f);
     glVertex2f( 0.3f, -0.25f);
     glVertex2f( 0.3f, -0.75f);
     glVertex2f(-0.3f, -0.75f);

    glEnd();

    /**
     * Desenha os números
     */
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINE_LOOP);

     glVertex2f(-0.46f, 0.375f);
     glVertex2f(-0.39f, 0.375f);
     glVertex2f(-0.39f, 0.25f);
     glVertex2f(-0.46f, 0.25f);

     glVertex2f(-0.46f, 0.25f);
     glVertex2f(-0.39f, 0.25f);
     glVertex2f(-0.39f, 0.125f);
     glVertex2f(-0.46f, 0.125f);

    glEnd();
    glBegin(GL_LINES);

     glVertex2f(-0.38f, 0.3145f);
     glVertex2f(-0.31f, 0.3145f - 0.125f);

     glVertex2f(-0.31f, 0.3145f);
     glVertex2f(-0.38f, 0.3145f - 0.125f);

    glEnd();
    glBegin(GL_LINE_LOOP);

     glVertex2f(-0.30f, 0.375f);
     glVertex2f(-0.23f, 0.375f);
     glVertex2f(-0.23f, 0.25f);
     glVertex2f(-0.30f, 0.25f);

     glVertex2f(-0.30f, 0.25f);
     glVertex2f(-0.23f, 0.25f);
     glVertex2f(-0.23f, 0.125f);
     glVertex2f(-0.30f, 0.125f);

    glEnd();

    // Atualiza tela e buffers
    glutSwapBuffers();
}
