#include <iostream>
#include <string>
using namespace std;

class Plataformas 
{
public:
        void desenha ();
        int id;
        string nome;
        int posX;
        int posY;
        int paineis_ocupados;
        bool com_defeito;
		void inicializa (string,int,int, int);
};

void Plataformas::inicializa(string name, int coordX, int coordY, int Id)
{
	nome = name;
	posX = coordX;
	posY = coordY;
	id = Id;
	com_defeito = false;
}

void Plataformas::desenha(){
    glColor3f(PLATAFORMA_COR_TEXTO.r, PLATAFORMA_COR_TEXTO.g, PLATAFORMA_COR_TEXTO.b);
    bitmap_output(this->posX-5, this->posY-5, this->nome, GLUT_BITMAP_HELVETICA_12);

    GLfloat circle_points = 100.0f;
    GLfloat angle;
    glColor3f(PLATAFORMA_COR_BORDA.r, PLATAFORMA_COR_BORDA.g, PLATAFORMA_COR_BORDA.b);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < circle_points; i++) {
        angle = 2*PI*i/circle_points;
        glVertex2f(cos(angle)*PLATAFORMA_RAIOX + this->posX, sin(angle)*PLATAFORMA_RAIOY + this->posY);
    }
    glEnd();
    glFlush();
}
