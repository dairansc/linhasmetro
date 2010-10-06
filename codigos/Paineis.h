class Paineis
{
public:
    void inicializa (int, int, GLcor, Plataformas*, Linhas*, Conexoes*);
    void desenha ();
    void procura_prox_trem (Linhas*, Conexoes*);
    void set_tempo (int);
    void atualiza_tempo_tela ();
    //bool trem_esta_na_plataforma (Linhas*);
    void calcula_tempo (Linhas*, Conexoes*);

    int id;
    int plataforma_id;
    int linha_id;
    int thread_id;
    int proximo_trem_pos_vet;
    int posX;
    int posY;

    int conexoes[LINHA_CON_QNT_MAX];
    int qnt_conexoes;
    int plataformas[LINHA_CON_QNT_MAX];
    int qnt_plataformas;
    int trens[LINHA_TREM_QNT_MAX];
    int qnt_trens;


    GLcor cor;
private:
    int horas;
    int minutos;
    int segundos;
};

void Paineis::set_tempo(int segundos){
    int resto = (int)segundos%3600;

    this->horas = (int)segundos/3600;
    this->minutos = (int)resto/60;
    this->segundos = (int)resto%60;
}

void Paineis::inicializa (int plat_id, int linha_id, GLcor c, Plataformas *plat, Linhas *lin, Conexoes *con){
    int i, j, pos_vet_con = -1;

    this->id = PAINEL_QNT;
    PAINEL_QNT++;
    this->plataforma_id = plat_id;
    this->linha_id = linha_id;
    this->proximo_trem_pos_vet = -1;
    this->cor = c;
    this->posX = plat[plat_id].posX + PLATAFORMA_SLOTS[ plat[plat_id].paineis_ocupados ][0];
    this->posY = plat[plat_id].posY + PLATAFORMA_SLOTS[ plat[plat_id].paineis_ocupados ][1];
    plat[plat_id].paineis_ocupados++;

    this->horas = this->minutos = this->segundos = -1;

    this->qnt_conexoes = lin[linha_id].qnt_conexoes;
    this->qnt_plataformas = lin[linha_id].qnt_conexoes;
    this->qnt_trens = lin[linha_id].qnt_trens;

    // procura qual conexão aponta para plataforma em que o painel está
    for(i=0; i < this->qnt_conexoes && pos_vet_con<0; i++){
        if(con[ lin[linha_id].conexoes[i] ].ate_plataforma_id == plat_id){
            pos_vet_con = i;
        }
    }

    // reorganiza o vetor de conexões de forma contrária do original a partir da conexão atual
    j=0;
    for(i=pos_vet_con; j < this->qnt_conexoes ; i--){
        this->conexoes[j] = lin[linha_id].conexoes[i];
        this->plataformas[j] = con[ lin[linha_id].conexoes[i] ].de_plataforma_id;
        if(i==0){
            i=this->qnt_conexoes;
        }
        j++;
    }

    // copia trens pertencentes a linha
    for(i=0; i < this->qnt_trens; i++){
        this->trens[i] = lin[this->linha_id].trens[i];
    }

    //this->thread_id =
    pthread_create(&t_paineis[this->id], NULL, thread_painel, &ids_paineis[this->id]);

    cout << "Novo Painel na plataforma " << this->plataforma_id << " pertencente a linha "<< this->linha_id << ", posição (" << this->posX << "," << this->posY << ")" << endl;
    /*cout << "Conexoes: ";
    for (int i = 0; i<this->qnt_conexoes; i++){
        cout << this->conexoes[i] << " ";
    }
    cout << "\nTrens: ";
    for (int i = 0; i<this->qnt_trens; i++){
        cout << this->trens[i] << " ";
    }
    cout << "\nPlataformas: ";
    for (int i = 0; i<this->qnt_plataformas; i++){
        cout << this->plataformas[i] << " ";
    }
    cout << endl;
    cout << "----------------------------------" << endl;*/
}

void Paineis::desenha(){
    GLint metadeX = 19, metadeY = 5;
    char texto[10]="<\0";

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
    //glFlush();
}

void Paineis::atualiza_tempo_tela(){
    if(segundos>=0 && minutos>=0 && horas>=0){
        char texto[10];
        sprintf(texto,"%02d:%02d:%02d",horas,minutos,segundos);
        glColor3f(PAINEL_COR_TEXTO.r, PAINEL_COR_TEXTO.g, PAINEL_COR_TEXTO.b);
        bitmap_output(posX-18, posY-3, texto, GLUT_BITMAP_TIMES_ROMAN_10);
    }
}

// apagar
/*bool Paineis::trem_esta_na_plataforma(Linhas *lin){
    bool sim = false;
    int i;
    for(i=0; i<lin[linha_id].qnt_trens && !sim; i++){
        //cout << "TESTE -----------------" << CENTRAL_TRENS[  linhas[ paineis[id].linha_id ].trens[i]  ].plataforma_id << endl;
        if(CENTRAL_TRENS[ lin[linha_id].trens[i] ].plataforma_id == plataforma_id){
            sim = true;
        }
    }

    return sim;
}*/

void Paineis::procura_prox_trem(Linhas *lin, Conexoes *cons){
    bool encontrou = false;
    int i, j;/*,
        qnt_conexoes = lin[linha_id].qnt_conexoes,
        *cons_ids = lin[linha_id].conexoes,
        plat_id = plataforma_id;*/

    /*cout << "Central Trens: \n";
    for (int i = 0; i<TREM_QNT; i++){
        cout << "Trem[" << i << "], plataforma: " << CENTRAL_TRENS[i].plataforma_id << ", conexao: " << CENTRAL_TRENS[i].conexao_id << ", percorrido: " << CENTRAL_TRENS[i].percorrido << ",\tvelocidade: " << CENTRAL_TRENS[i].velocidade << endl;
    }*/

    //cout << "-----------Painel: " << id << endl;
    for(i=0; i<qnt_conexoes && !encontrou; i++){
        //cout << "procurando na conexão: " << this->conexoes[i] << endl;
        for(j=0; j<qnt_trens && !encontrou; j++){
            //cout << "\tverificando trem: " << this->trens[j] << endl;
            if((CENTRAL_TRENS[ this->trens[j] ].conexao_id == this->conexoes[i]) || (CENTRAL_TRENS[ this->trens[j] ].plataforma_id == this->plataformas[i])){
                //cout << "\t\tEncontrado" << endl;
                proximo_trem_pos_vet = j;
                encontrou = true;
            }
        }
    }

    //if(id==1){
        cout << "Painel[" << id << "], proximo trem[" << proximo_trem_pos_vet << "] = " << this->trens[proximo_trem_pos_vet] << endl;
    //}
    //encontrou = false;

    //for(i=con_inicial; i!=(con_inicial+1) && !encontrou; i--){


//qual conexao em cons_id possui o campo ate como plataforma

    if(!encontrou){
        erro("Problema na procura do próximo trem", ERRO_CRITICO);
    }
}

void Paineis::calcula_tempo(Linhas *lin, Conexoes *cons){
    bool encontrou = false;
    int i, j;
    float acumulador_distancia = 0, acumulador_tempo = 0;

    for(i=0; i<qnt_conexoes && !encontrou; i++){
        //cout << "procurando na conexão: " << this->conexoes[i] << endl;
        if(CENTRAL_TRENS[proximo_trem_pos_vet].conexao_id == this->conexoes[i]){
            acumulador_distancia += CENTRAL_TRENS[proximo_trem_pos_vet].percorrido;
            encontrou = true;
        }
        else if(CENTRAL_TRENS[proximo_trem_pos_vet].plataforma_id == this->plataformas[i]){
            encontrou = true;
        }
        else{
            acumulador_distancia += cons[ CENTRAL_TRENS[proximo_trem_pos_vet].conexao_id ].distancia;
            acumulador_tempo += TEMPO_NA_PLATAFORMA;
        }


    }
    if(id==1){
        cout << "------------------" << endl;
        cout << "Painel[" << id << "], distancia acum: " << acumulador_distancia << ", tempo acum: " << acumulador_tempo << endl;
    }
    set_tempo((int)((acumulador_distancia/CENTRAL_TRENS[proximo_trem_pos_vet].velocidade)));
}
