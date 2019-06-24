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
    
    glVertex2f(-0.55f, 0.5f);
    glVertex2f(-0.15f, 0.5f);
    glVertex2f(-0.15f, 0.0f);
    glVertex2f(-0.55f, 0.0f);

    glVertex2f(0.55f, 0.5f);
    glVertex2f(0.15f, 0.5f);
    glVertex2f(0.15f, 0.0f);
    glVertex2f(0.55f, 0.0f);

    glVertex2f(-0.15f, 0.0f);
    glVertex2f(0.15f, 0.0f);
    glVertex2f(0.15f, -0.25f);
    glVertex2f(-0.15f, -0.25f);

    // glVertex2f(-0.15f, -0.15f);
    // glVertex2f(-0.45f, -0.15f);
    // glVertex2f(-0.45f, -0.55f);
    // glVertex2f(-0.15f, -0.55f);

    glEnd();


    // Atualiza tela e buffers
    glutSwapBuffers();
}
