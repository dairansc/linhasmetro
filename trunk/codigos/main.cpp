using namespace std;
#include <iostream>
#include <string>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include "openGLlib.h"
#include "defines.h"
#include "Plataformas.h"
Plataformas plataformas[PLATAFORMA_QNT_MAX];
#include "Conexoes.h"
Conexoes conexoes[CON_QNT_MAX];
#include "Linhas.h"
Linhas linhas[LINHA_QNT_MAX];
#include "Trens.h"
#include "Paineis.h"

#include "libs.h"


int main(int argc, char** argv)
{
    glutInit(&argc, argv);                             // inicializa o glut
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);      // especifica o uso de cores e buffers
    glutInitWindowSize (JANELA_TAM_X, JANELA_TAM_Y);   // especifica as dimensoes da janela
    glutInitWindowPosition (10, 10);                   // especifica aonde a janela aparece na tela
    glutCreateWindow (JANELA_TITULO);              // cria a janela

    init();

    glutDisplayFunc(display);                               // funcao que sera redesenhada pelo GLUT
    glutKeyboardFunc(keyboard);                             // funcoes de teclado
    glutMainLoop();                                         // mostra todas as janelas criadas

    return 0;
}
