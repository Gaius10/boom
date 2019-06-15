#include <GL/glut.h>
#include "../libs/draws.h"

void init(void)
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void telaInicial(int *argc, char **argv)
{
	glutInit(argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 400);
    glutInitWindowPosition(300, 200);
    glutCreateWindow("Boom! - Campo Minado");
    glutDisplayFunc(drawTelaInicial);
    init();
    glutMainLoop();
}
