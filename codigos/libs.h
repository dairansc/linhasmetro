//#include <stdio.h>
// definicao de cada funcao
void erro(string mensagem){

}

void init(){
    glClearColor(0.0, 0.0, 0.0, 0.0);    // cor de fundo
    glOrtho (0, 1000, 0, 500, -1 ,1);     // modo de projecao ortogonal

    plataformas[0].inicializa("A",30,30,0);
    plataformas[1].inicializa("B",400,400,1);
    plataformas[2].inicializa("C",550,400,2);

    linhas[0].inicializa("Centro", BRANCO,0);
}

void exibe_plataforma(string nome, GLint posX, GLint posY, GLfloat cor_texto[], GLfloat cor_circulo[]){
    glColor3fv(cor_texto);
    bitmap_output(posX-5, posY-5, nome, GLUT_BITMAP_HELVETICA_12);

    GLfloat circle_points = 100.0f;
    GLfloat angle, raioX=20.0f, raioY=10.0f;
    glColor3fv(cor_circulo);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < circle_points; i++) {
        angle = 2*M_PI*i/circle_points;
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



    plataformas[0].desenha();
    plataformas[1].desenha();
    plataformas[2].desenha();
    //Pl_B.desenha();

    glColor3fv(branco);                  // cor da linha
    glBegin(GL_LINES);
    glVertex2f(250, 300);
    glVertex2f(150, 350);
    glEnd();

    int bx = 400, by = 300;
    exibe_plataforma("A",bx,by,vermelho,verde);

    char texto[30];
    sprintf(texto,"%02d:%02d:%02d",80,20,40);
    glColor3fv(branco);
    bitmap_output(183, 214, texto, GLUT_BITMAP_TIMES_ROMAN_10);

    exibe_borda_painel(bx, by+17, 60, verde);
    exibe_borda_painel(bx, by+28, 62, verde);

    exibe_borda_painel(bx, by+39, 60, vermelho);
    exibe_borda_painel(bx, by+50, 62, vermelho);

    exibe_borda_painel(bx, by-17, 60, branco);
    exibe_borda_painel(bx, by-28, 62, branco);

    exibe_borda_painel(bx, by-39, 60, azul);
    exibe_borda_painel(bx, by-50, 62, azul);

    exibe_borda_painel(bx-47, by+17, 60, amarelo);
    exibe_borda_painel(bx-47, by+6, 62, amarelo);

    exibe_borda_painel(bx-47, by-5, 60, rosa);
    exibe_borda_painel(bx-47, by-16, 62, rosa);

    exibe_borda_painel(bx+47, by+17, 60, azul);
    exibe_borda_painel(bx+47, by+6, 62, azul);

    exibe_borda_painel(bx+47, by-5, 60, vermelho);
    exibe_borda_painel(bx+47, by-16, 62, vermelho);


    glColor3fv(branco);

    exibe_plataforma("B",900,400,verde,vermelho);
    exibe_plataforma("C",500,100,vermelho,branco);



    glFlush();
}
