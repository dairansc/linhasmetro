
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
//#include "classes/carrega_classes.cc"

#define PI 3.1415926535898
#define TEXT_BUFFER 30
GLfloat BRANCO[] =   {1.0, 1.0, 1.0},
        VERMELHO[] = {1.0, 0.0, 0.0},
        VERDE[] =   {0.0, 1.0, 0.0},
        AZUL[] =     {0.0, 0.0, 1.0},
        AMARELO[] =  {1.0, 1.0, 0.0},
        ROSA[] =     {1.0, 0.0, 1.0};




int QNT_PLATAFORMAS = 9;
GLfloat *COR_BORDA_PLATAFORMAS = BRANCO,
        *COR_TEXTO_PLATAFORMAS = VERDE;



// prototipos das funcoes
void bitmap_output(int x, int y, char *string, void *font);
void init(void);
void display(void);
void keyboard(unsigned char key, int x, int y);




class Plataformas {
public:
    int id;
    char nome[TEXT_BUFFER];
    int posX;
    int posY;
    //Paineis paineis[PLAT_MAX_PAINES];
    int com_defeito;

    void desenha ();
    Plataformas(char *, int, int);
};
/*
Plataformas::Plataformas(char * n, int x, int y){
    this->id = QNT_PLATAFORMAS;
    QNT_PLATAFORMAS--;
    strcpy(this->nome, n);
    this->posX = x;
    this->posY = y;
    this->com_defeito = 0;
}*/

void Plataformas::desenha(){
    glColor3fv(COR_TEXTO_PLATAFORMAS);
    bitmap_output(this->posX-5, this->posY-5, this->nome, GLUT_BITMAP_HELVETICA_12);

    GLfloat circle_points = 100.0f;
    GLfloat angle, raioX=20.0f, raioY=10.0f;
    glColor3fv(COR_BORDA_PLATAFORMAS);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < circle_points; i++) {
        angle = 2*PI*i/circle_points;
        glVertex2f(cos(angle)*raioX + this->posX, sin(angle)*raioY + this->posY);
    }
    glEnd();
    glFlush();
}


//Plataformas * plataforma[QNT_PLATAFORMAS];
Plataformas plat[3] = new Plataformas("A", 0, 0);
//colocar no display
plat[0].nome = "plat0";
plat[0].posX = 155;
plat = new Platafomas[3];
//Plataformas Pl_B("B", 500, 400);
//plat[0] = *aux;
//Plataformas Pl_A[1] = new Plataformas("B", 500, 400);

/*
plataforma[QNT_PLATAFORMAS] = new Plataformas("I", 900, 400);
plataforma[QNT_PLATAFORMAS] = new Plataformas("H", 800, 400);
plataforma[QNT_PLATAFORMAS] = new Plataformas("G", 700, 400);
plataforma[QNT_PLATAFORMAS] = new Plataformas("F", 600, 400);
plataforma[QNT_PLATAFORMAS] = new Plataformas("E", 500, 400);
plataforma[QNT_PLATAFORMAS] = new Plataformas("D", 400, 400);
plataforma[QNT_PLATAFORMAS] = new Plataformas("C", 300, 400);
plataforma[QNT_PLATAFORMAS] = new Plataformas("B", 200, 400);
plataforma[QNT_PLATAFORMAS] = new Plataformas("A", 100, 400);
*/



// funcao principal
int main(int argc, char** argv){
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



// definicao de cada funcao
void bitmap_output(int x, int y, char *string, void *font){
  int len, i;

  glRasterPos2f(x, y);
  len = (int) strlen(string);
  for (i = 0; i < len; i++) {
    glutBitmapCharacter(font, string[i]);
  }
}



void init(void){
  glClearColor(0.0, 0.0, 0.0, 0.0);    // cor de fundo
  glOrtho (0, 1000, 0, 500, -1 ,1);     // modo de projecao ortogonal
}

void exibe_plataforma(char *nome, GLint posX, GLint posY, GLfloat cor_texto[], GLfloat cor_circulo[]){
    glColor3fv(cor_texto);
    bitmap_output(posX-5, posY-5, nome, GLUT_BITMAP_HELVETICA_12);

    GLfloat circle_points = 100.0f;
    GLfloat angle, raioX=20.0f, raioY=10.0f;
    glColor3fv(cor_circulo);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < circle_points; i++) {
        angle = 2*PI*i/circle_points;
        glVertex2f(cos(angle)*raioX + posX, sin(angle)*raioY + posY);
    }
    glEnd();
    glFlush();
}

void exibe_borda_painel(GLfloat posX, GLfloat posY, int sentido, GLfloat cor[]){
    GLint metadeX = 19, metadeY = 5;
    char texto[30];
    sprintf(texto,"%c",sentido);
    glColor3fv(cor);
    bitmap_output(posX - metadeX - 7, posY - 3, texto, GLUT_BITMAP_HELVETICA_12);
    glBegin(GL_LINE_LOOP);          // Face lateral direita
    glVertex2f(posX - metadeX, posY - metadeY);
    glVertex2f(posX + metadeX, posY - metadeY);
    glVertex2f(posX + metadeX, posY + metadeY);
    glVertex2f(posX - metadeX, posY + metadeY);
    glEnd();
    glFlush();
}

//void set_tempo_painel(int qual, int valor, GLfloat cor[]){

//}

void display(void){
    //int i;
    glClear(GL_COLOR_BUFFER_BIT);               // limpa a janela
    GLfloat branco[] = {1.0, 1.0, 1.0}, vermelho[] = {1.0, 0.0, 0.0}, verde[] = {0.0, 1.0, 0.0}, azul[] = {0.0, 0.0, 1.0}, amarelo[] = {1.0, 1.0, 0.0}, rosa[] = {1.0, 0.0, 1.0};

    Pl_A.desenha();
    Pl_B.desenha();

    glColor3fv(branco);                  // cor da linha
    glBegin(GL_LINES);
    glVertex2f(250, 300);
    glVertex2f(150, 350);
    glEnd();

    exibe_plataforma("A",200,200,vermelho,verde);

    char texto[30];
    sprintf(texto,"%02d:%02d:%02d",80,20,40);
    glColor3fv(branco);
    bitmap_output(183, 214, texto, GLUT_BITMAP_TIMES_ROMAN_10);

    exibe_borda_painel(200, 217, 60, verde);
    exibe_borda_painel(200, 228, 62, verde);

    exibe_borda_painel(200, 239, 60, vermelho);
    exibe_borda_painel(200, 250, 62, vermelho);

    exibe_borda_painel(200, 183, 60, branco);
    exibe_borda_painel(200, 172, 62, branco);

    exibe_borda_painel(200, 161, 60, azul);
    exibe_borda_painel(200, 150, 62, azul);

    exibe_borda_painel(153, 217, 60, amarelo);
    exibe_borda_painel(153, 206, 62, amarelo);

    exibe_borda_painel(153, 195, 60, rosa);
    exibe_borda_painel(153, 184, 62, rosa);

    exibe_borda_painel(247, 217, 60, azul);
    exibe_borda_painel(247, 206, 62, azul);

    exibe_borda_painel(247, 195, 60, vermelho);
    exibe_borda_painel(247, 184, 62, vermelho);


    glColor3fv(branco);

    exibe_plataforma("B",900,400,verde,vermelho);
    exibe_plataforma("C",500,100,vermelho,branco);



glFlush();
}

void keyboard(unsigned char key, int x, int y){
  switch (key) {
  case 27: case 13:                           // tecla Esc ou Enter(encerra o programa)
	exit(0);
	break;
  }
}
