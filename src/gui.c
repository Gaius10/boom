#include "../libs/gui.h"
#include "../libs/draws.h"
#include "../libs/events.h"
#include <GL/glut.h>

void init(void)
{
    glClearColor(0.0f, 0.6f, 0.0f, 1.0f);
}

void telaInicial(int *argc, char **argv)
{
	glutInit(argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
   
    glutInitWindowSize(600, 400);
    glutInitWindowPosition(300, 200);
    
    glutCreateWindow("Boom! - Campo Minado");
    
    glutDisplayFunc(drawTelaInicial);
    glutPassiveMotionFunc(mouseMoveTelaInicial);
    glutReshapeFunc(resizeTelaInicial);

    init();
    glutMainLoop();
}
