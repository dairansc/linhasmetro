class Paineis
{
public:
    void inicializa (int, int, GLcor, Plataformas*);
    void desenha ();
    void procura_prox_trem ();
    void set_tempo (int segundos);

    int id;
    int plataforma_id;
    int linha_id;
    int thread_id;
    int proximo_trem_id;
    int posX;
    int posY;
    GLcor cor;
private:
    void atualiza_tempo_tela ();

    int horas;
    int minutos;
    int segundos;
};

void Paineis::inicializa (int plat_id, int linha_id, GLcor c, Plataformas *plat){
    this->id = PAINEL_QNT;
    PAINEL_QNT++;
    this->plataforma_id = plat_id;
    this->linha_id = linha_id;
    this->proximo_trem_id = -1;
    this->cor = c;
    this->posX = plat[plat_id].posX + PLATAFORMA_SLOTS[ plat[plat_id].paineis_ocupados ][0];
    this->posY = plat[plat_id].posY + PLATAFORMA_SLOTS[ plat[plat_id].paineis_ocupados ][1];
    plat[plat_id].paineis_ocupados++;
    //this->thread_id =
    cout << "Novo Painel na plataforma " << this->plataforma_id << " pertencente a linha "<< this->linha_id << ", posição (" << this->posX << "," << this->posY << ")" << endl;
}

void Paineis::desenha(){
    GLint metadeX = 19, metadeY = 5;
    char texto[5]="<\0";

    glColor3f(PAINEL_COR_FUNDO.r, PAINEL_COR_FUNDO.g, PAINEL_COR_FUNDO.b);
    glBegin(GL_POLYGON);
    glVertex2f(posX - metadeX, posY - metadeY);
    glVertex2f(posX + metadeX, posY - metadeY);
    glVertex2f(posX + metadeX, posY + metadeY);
    glVertex2f(posX - metadeX, posY + metadeY);
    //glEnd();

    //sprintf(texto,"%c",this->);
    glColor3f(cor.r, cor.g, cor.b);
    bitmap_output(posX - metadeX - 7, posY - 3, texto, GLUT_BITMAP_HELVETICA_12);
    glBegin(GL_LINE_LOOP);
    glVertex2f(posX - metadeX, posY - metadeY);
    glVertex2f(posX + metadeX, posY - metadeY);
    glVertex2f(posX + metadeX, posY + metadeY);
    glVertex2f(posX - metadeX, posY + metadeY);
    glEnd();
    glFlush();
}
