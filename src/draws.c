#include <GL/glut.h>
#include <stdio.h>

void drawTelaInicial(void)
{
    // Limpa buffer de imagem
    glClear(GL_COLOR_BUFFER_BIT);



    // Atualiza tela e buffers
    glutSwapBuffers();
}
