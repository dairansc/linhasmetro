#include <iostream>
#include <string>
#include <gl\glut.h>
using namespace std;

typedef struct GLfloat3v{
    GLfloat r;
    GLfloat g;
    GLfloat b;
}GLcor;

#include "openGLlib.h"
#include "Defines.h"
#include "Linhas.h"
#include "Trens.h"
#include "Plataformas.h"
#include "Paineis.h"

Plataformas plataformas[PLATAFORMA_QNT];
Linhas linhas[LINHA_QNT];

#include "libs.h"

int main(int argc, char** argv)
{
	glutInit(&argc, argv);                              // inicializa o glut
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);           // especifica o uso de cores e buffers
    glutInitWindowSize (1000, 500);                          // especifica as dimensoes da janela
    glutInitWindowPosition (10, 10);                      // especifica aonde a janela aparece na tela
    glutCreateWindow ("Linhas de Metro");              // cria a janela

	init();
	
	glutDisplayFunc(display);                               // funcao que sera redesenhada pelo GLUT
    glutKeyboardFunc(keyboard);                             // funcoes de teclado
    glutMainLoop();                                         // mostra todas as janelas criadas

	return 0;
}