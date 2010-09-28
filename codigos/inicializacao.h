//#include <stdio.h>
// definicao de cada funcao


void init(){
    glClearColor(0.0, 0.0, 0.0, 0.0);    // cor de fundo
    glOrtho (0, 1000, 0, 500, -1 ,1);     // modo de projecao ortogonal
    glEnable( GL_LINE_SMOOTH );

    plataformas[0].inicializa("A",60,60);
    plataformas[1].inicializa("B",400,400);
    plataformas[2].inicializa("C",550,400);
    plataformas[3].inicializa("D",400,100);
    plataformas[4].inicializa("E",800,300);

    linhas[0].inicializa("Centro", VERDE);
    linhas[0].add_conexao(0,1,CON_TIPO_INICIO,conexoes);
    linhas[0].add_conexao(1,3,CON_TIPO_FIM,conexoes);

    linhas[1].inicializa("PUC", BRANCO);
    linhas[1].add_conexao(1,2,CON_TIPO_INICIO,conexoes);
    linhas[1].add_conexao(2,3,CON_TIPO_FIM,conexoes);
    linhas[1].add_conexao(3,1,CON_TIPO_NORMAL,conexoes);

    linhas[2].inicializa("Inter", VERMELHO);
    linhas[2].add_conexao(3,0,CON_TIPO_INICIO,conexoes);
    linhas[2].add_conexao(0,1,CON_TIPO_FIM,conexoes);
    linhas[2].add_trem(trens, conexoes);

    linhas[3].inicializa("Outra", AZUL);
    linhas[3].add_conexao(2,4,CON_TIPO_INICIO,conexoes);

    int linha_id, i, j, k, l;
    for(i=0; i < PLATAFORMA_QNT; i++){// para cada plataforma
        //cout << "Procurando na plataforma " << plataformas[i].nome << endl;
        for(j=0; j<CON_QNT; j++){// para cada conector
            if(conexoes[j].ate_plataforma_id == plataformas[i].id){ // todos conectores que estiverem indo até a plataforma
                linha_id = -1;
                for(k=0; k<LINHA_QNT || linha_id<0; k++){
                    for(l=0; l<linhas[k].qnt_conexoes; l++){
                        if(conexoes[j].id == linhas[k].conexoes[l]){
                            linha_id = linhas[k].id;
                        }
                    }
                }
                //cout << "Criar painel da plataforma " << plataformas[i].nome << " pertencente a linha " << linhas[linha_id].nome << endl;
                paineis[PAINEL_QNT].inicializa(plataformas[i].id, linha_id, linhas[linha_id].cor, plataformas);
            }
        }
    }



}

void exibe_plataforma(string nome, GLint posX, GLint posY){//, GLfloat cor_texto[], GLfloat cor_circulo[]){
    /*glColor3fv(cor_texto);
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
    glFlush();*/
int i=0;
    //glClear(GL_COLOR_BUFFER_BIT);               // limpa a janela


    //linhas[0].desenha(conexoes);
    //linhas[1].desenha(conexoes);
    //linhas[2].desenha(conexoes);
    //linhas[0].inicializa("Centro", VERDE);
    conexoes[i].desenha(0,0);
    i++;
    conexoes[i].desenha(0,0);
    i++;

    //linhas[1].inicializa("PUC", BRANCO);
    conexoes[i].desenha(0,0);
    i++;
    conexoes[i].desenha(0,0);
    i++;
    conexoes[i].desenha(3,0);
    i++;

    //linhas[2].inicializa("Inter", VERMELHO);
    conexoes[i].desenha(2,0);
    i++;
    conexoes[i].desenha(4,0);
    i++;

    //linhas[3].inicializa("Outra", AZUL);
    conexoes[i].desenha(0,0);
    i++;

    plataformas[0].desenha();
    plataformas[1].desenha();
    plataformas[2].desenha();
    plataformas[3].desenha();
    plataformas[4].desenha();

    for(int i=0; i<PAINEL_QNT; i++){
        paineis[i].desenha();
    }

    GLfloat circle_points = 100.0f;
    GLfloat angle;

    glColor3f(PLATAFORMA_COR_FUNDO.r, PLATAFORMA_COR_FUNDO.g, PLATAFORMA_COR_FUNDO.b);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(posX, posY);
    for (angle=0; angle<=361; angle++){
        glVertex2f(posX + sin(angle) * PLATAFORMA_RAIOX, posY + cos(angle) * PLATAFORMA_RAIOY);
    }
//glEnd();
    glColor3f(PLATAFORMA_COR_BORDA.r, PLATAFORMA_COR_BORDA.g, PLATAFORMA_COR_BORDA.b);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < circle_points; i++) {
        angle = 2*M_PI*i/circle_points;
        glVertex2f(cos(angle)*PLATAFORMA_RAIOX + posX, sin(angle)*PLATAFORMA_RAIOX + posY);
    }
    glEnd();

    glColor3f(PLATAFORMA_COR_TEXTO.r, PLATAFORMA_COR_TEXTO.g, PLATAFORMA_COR_TEXTO.b);
    bitmap_output(posX-5, posY-5, nome, GLUT_BITMAP_HELVETICA_12);

    glFlush();
}

void exibe_borda_painel(GLfloat posX, GLfloat posY, int sentido, GLfloat cor[]){
    GLint metadeX = 19, metadeY = 5;

    glColor3f(PAINEL_COR_FUNDO.r, PAINEL_COR_FUNDO.g, PAINEL_COR_FUNDO.b);
    glBegin(GL_POLYGON);
    glVertex2f(posX - metadeX, posY - metadeY);
    glVertex2f(posX + metadeX, posY - metadeY);
    glVertex2f(posX + metadeX, posY + metadeY);
    glVertex2f(posX - metadeX, posY + metadeY);
    //glEnd();

    char texto[30];
    sprintf(texto,"%c",sentido);
    glColor3fv(cor);
    bitmap_output(posX - metadeX - 7, posY - 3, texto, GLUT_BITMAP_HELVETICA_12);
    glBegin(GL_LINE_LOOP);
    glVertex2f(posX - metadeX, posY - metadeY);
    glVertex2f(posX + metadeX, posY - metadeY);
    glVertex2f(posX + metadeX, posY + metadeY);
    glVertex2f(posX - metadeX, posY + metadeY);
    glEnd();

    //glFlush();
}

//void set_tempo_painel(int qual, int valor, GLfloat cor[]){

//}

void display(void){

    //Pl_B.desenha();
/*
int x1 = 300, y1 = 300, r = 20;
glColor3f(VERMELHO.r,VERMELHO.g,VERMELHO.b);                  // cor da linha
glBegin(GL_TRIANGLE_FAN);
glVertex2f(x1, y1);
for (int angle = 0; angle<=360; angle+=1){
    glVertex2f(x1 + sin(angle) * r, y1 + cos(angle) * r);
}
 glEnd();*/
    GLfloat branco[] = {1.0, 1.0, 1.0}, vermelho[] = {1.0, 0.0, 0.0}, verde[] = {0.0, 1.0, 0.0}, azul[] = {0.2, 0.2, 1.0}, amarelo[] = {1.0, 1.0, 0.0}, rosa[] = {1.0, 0.0, 1.0}, preto[] = {0.0, 0.0, 0.0};
    /*glColor3f(1.0, 1.0, 1.0);
    int posX = 300, posY = 300, metadeX = 200, metadeY = 100;
    glBegin(GL_POLYGON);
    glVertex2f(posX - metadeX, posY - metadeY);
    glVertex2f(posX + metadeX, posY - metadeY);
    glVertex2f(posX + metadeX, posY + metadeY);
    glVertex2f(posX - metadeX, posY + metadeY);
    glEnd();
    glFlush();*/

/*int posX = 300, posY = 300;
    GLfloat circle_points = 100.0f;
    GLfloat angle;

    glColor3f(TREM_COR_FUNDO.r, TREM_COR_FUNDO.g, TREM_COR_FUNDO.b);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(posX, posY);
    for (angle=0; angle<=361; angle++){
        glVertex2f(posX + sin(angle) * TREM_RAIO, posY + cos(angle) * TREM_RAIO);
    }
glEnd();
    glColor3f(PLATAFORMA_COR_BORDA.r, PLATAFORMA_COR_BORDA.g, PLATAFORMA_COR_BORDA.b);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < circle_points; i++) {
        angle = 2*M_PI*i/circle_points;
        glVertex2f(cos(angle)*TREM_RAIO + posX, sin(angle)*TREM_RAIO + posY);
    }
    glEnd();

    glColor3f(TREM_COR_TEXTO.r, TREM_COR_TEXTO.g, TREM_COR_TEXTO.b);
    bitmap_output(posX-2, posY-4, "0", GLUT_BITMAP_TIMES_ROMAN_10);

    glFlush();
*/
    int bx = 930, by = 75;
    exibe_plataforma("A",bx,by);




    exibe_borda_painel(bx, by+27, 60, verde);
    exibe_borda_painel(bx, by+38, 62, verde);

    exibe_borda_painel(bx, by+49, 60, vermelho);
    exibe_borda_painel(bx, by+60, 62, vermelho);

    exibe_borda_painel(bx, by-27, 60, branco);
    exibe_borda_painel(bx, by-38, 62, branco);

    exibe_borda_painel(bx, by-49, 60, azul);
    exibe_borda_painel(bx, by-60, 62, azul);

    exibe_borda_painel(bx-47, by+17, 60, amarelo);
    exibe_borda_painel(bx-47, by+6, 62, amarelo);

    exibe_borda_painel(bx-47, by-5, 60, rosa);
    exibe_borda_painel(bx-47, by-16, 62, rosa);

    exibe_borda_painel(bx+47, by+17, 60, azul);
    exibe_borda_painel(bx+47, by+6, 62, azul);

    exibe_borda_painel(bx+47, by-5, 60, vermelho);
    exibe_borda_painel(bx+47, by-16, 62, vermelho);

    char texto[30];
    sprintf(texto,"%02d:%02d:%02d",80,20,40);
    glColor3fv(preto);
    bitmap_output(bx-17, by+23, texto, GLUT_BITMAP_TIMES_ROMAN_10);
    bitmap_output(bx-17, by+56, texto, GLUT_BITMAP_TIMES_ROMAN_10);


    //glColor3fv(branco);

    //exibe_plataforma("B",900,400,verde,vermelho);
    //exibe_plataforma("C",500,100,vermelho,branco);



    //glFlush();
    //glutSwapBuffers();
    //glutSwapBuffers();
    //glClearColor(0.0, 0.0, 1.0, 1.0);
}
