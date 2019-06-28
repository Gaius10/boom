#include "../libs/gui.h"
#include "../libs/draws.h"
#include "../libs/events.h"
#include <GL/glut.h>
#include <stdio.h>
#include <time.h>

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
    glutMouseFunc(clickTelaInicial);
    glutReshapeFunc(resizeTelaInicial);

    init();
    glutMainLoop();
}

void tabuleiro(int w, int h)
{
    FILE *logFile;

    switch(w)
    {
        case 8:
            break;
        case 16:
            break;
        case 30:
            break;
        default:
            // Registra erro
            logFile = fopen("error_logs.txt", "a");
            time_t date = time(NULL);

            fprintf(logFile,"Falha ao definir tamanho do tabuleiro - %s", 
                asctime(gmtime(&date)));

            fclose(logFile);
            break;
    }
}
