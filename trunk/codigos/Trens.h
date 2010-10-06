class Trens
{
public:
    int id;
    int linha_id;
    int thread_id;
    int plataforma_atual_id;
    int conexao_atual_id;
    float velocidade_atual;
    float percorrido;
    GLcor cor;

    void inicializa (int, int, GLcor);
    void desenha(Plataformas*, Conexoes*);
};

void Trens::inicializa (int linha_id, int plat_inicial_id, GLcor c){
    this->id = TREM_QNT;
    TREM_QNT++;
    this->linha_id = linha_id;
    this->plataforma_atual_id = plat_inicial_id;
    this->cor = c;

    this->conexao_atual_id = -1;
    this->velocidade_atual = 0;
    this->percorrido = 0;

    //this->thread_id =
    //Arg_Trem dado_trem;
    //int id = this->id;
    pthread_create(&t_trens[this->id], NULL, thread_trem, &ids_trens[this->id]);
    //pthread_create(&t_trens[this->id],NULL,thread_trem, (void*) &id);

    cout << "Novo Trem[" << this->id << "] da Linha " << this->linha_id << " plataforma inicial: "<< this->plataforma_atual_id << endl;
}

void Trens::desenha(Plataformas *plat, Conexoes *cons){
    GLfloat circle_points = 100.0f;
    GLfloat angle;
    int posX = -1, posY,
        posXde_plat = plat[ cons[conexao_atual_id].de_plataforma_id ].posX,
        posYde_plat = plat[ cons[conexao_atual_id].de_plataforma_id ].posY,
        posXate_plat = plat[ cons[conexao_atual_id].ate_plataforma_id ].posX,
        posYate_plat = plat[ cons[conexao_atual_id].ate_plataforma_id ].posY;

    if(plataforma_atual_id>=0){
        posX = plat[plataforma_atual_id].posX;
        posY = plat[plataforma_atual_id].posY;
    }
    else{
        posX = (int)posXde_plat + (posXate_plat - posXde_plat)*(percorrido/cons[conexao_atual_id].distancia);
        posY = (int)posYde_plat + (posYate_plat - posYde_plat)*(percorrido/cons[conexao_atual_id].distancia);
    }
    //cout << "posX: " << posX << "\nposY: " << posY << endl;
    if(posX>=0 && posY>=0 && posX<=JANELA_TAM_X && posY<=JANELA_TAM_Y){
        glColor3f(TREM_COR_FUNDO.r, TREM_COR_FUNDO.g, TREM_COR_FUNDO.b);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(posX, posY);
        for (angle=0; angle<=361; angle++){
            glVertex2f(posX + sin(angle) * TREM_RAIO, posY + cos(angle) * TREM_RAIO);
        }
        glEnd();
        glColor3f(cor.r, cor.g, cor.b);
        glBegin(GL_LINE_LOOP);
        for (int i = 0; i < circle_points; i++) {
            angle = 2*M_PI*i/circle_points;
            glVertex2f(cos(angle)*TREM_RAIO + posX, sin(angle)*TREM_RAIO + posY);
        }
        glEnd();

        glColor3f(TREM_COR_TEXTO.r, TREM_COR_TEXTO.g, TREM_COR_TEXTO.b);
        char texto[2];
        sprintf(texto,"%d",this->id);
        bitmap_output(posX-2, posY-4, texto, GLUT_BITMAP_TIMES_ROMAN_10);

        //glFlush();
    }
    else{
        erro("Trem perdido", ERRO_CRITICO);
    }
}
