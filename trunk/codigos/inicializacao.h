void init(void){
    int linha_id, i, j, k, l;

    glClearColor(0.0, 0.0, 0.0, 0.0);
    glOrtho (0, JANELA_TAM_X, 0, JANELA_TAM_Y, -1 ,1);

    // inicialização dos semáforos
    //for(i=0; i < TREM_QNT_MAX; i++){
        sem_init(&s_central, 0, 1);
    //}
    /*for(i=0; i < PAINEL_QNT_MAX; i++){
        sem_init(&s_paineis[i], 0, 1);
    }*/


    plataformas[0].inicializa("A",70,420);
    plataformas[1].inicializa("B",100,250);
    plataformas[2].inicializa("C",250,350);
    plataformas[3].inicializa("D",120,100);
    plataformas[4].inicializa("E",350,70);
    plataformas[5].inicializa("F",500,420);
    plataformas[6].inicializa("G",500,250);
    plataformas[7].inicializa("H",900,420);
    plataformas[8].inicializa("I",750,300);
    plataformas[9].inicializa("J",650,150);

    linhas[0].inicializa("ACGJ", VERDE);
    linhas[0].add_conexao(0,2,CON_TIPO_INICIO,conexoes);
    linhas[0].add_conexao(2,6,CON_TIPO_NORMAL,conexoes);
    linhas[0].add_conexao(6,9,CON_TIPO_FIM,conexoes);
    linhas[0].add_conexao(9,6,CON_TIPO_INICIO,conexoes);
    linhas[0].add_conexao(6,2,CON_TIPO_NORMAL,conexoes);
    linhas[0].add_conexao(2,0,CON_TIPO_FIM,conexoes);
    ids_trens[TREM_QNT]=TREM_QNT;
    linhas[0].add_trem(trens, conexoes);
    ids_trens[TREM_QNT]=TREM_QNT;
    linhas[0].add_trem(trens, conexoes);
    //ids_trens[TREM_QNT]=TREM_QNT;
    //linhas[0].add_trem(trens, conexoes);


    linhas[1].inicializa("DEGIH", VERMELHO);
    linhas[1].add_conexao(3,4,CON_TIPO_INICIO,conexoes);
    linhas[1].add_conexao(4,6,CON_TIPO_NORMAL,conexoes);
    linhas[1].add_conexao(6,8,CON_TIPO_NORMAL,conexoes);
    linhas[1].add_conexao(8,7,CON_TIPO_FIM,conexoes);
    linhas[1].add_conexao(7,8,CON_TIPO_INICIO,conexoes);
    linhas[1].add_conexao(8,6,CON_TIPO_NORMAL,conexoes);
    linhas[1].add_conexao(6,4,CON_TIPO_NORMAL,conexoes);
    linhas[1].add_conexao(4,3,CON_TIPO_FIM,conexoes);
    ids_trens[TREM_QNT]=TREM_QNT;
    linhas[1].add_trem(trens, conexoes);
    ids_trens[TREM_QNT]=TREM_QNT;
    linhas[1].add_trem(trens, conexoes);


    linhas[2].inicializa("FGJ", AMARELO);
    linhas[2].add_conexao(5,6,CON_TIPO_INICIO,conexoes);
    linhas[2].add_conexao(6,9,CON_TIPO_FIM,conexoes);
    linhas[2].add_conexao(9,6,CON_TIPO_INICIO,conexoes);
    linhas[2].add_conexao(6,5,CON_TIPO_FIM,conexoes);
    ids_trens[TREM_QNT]=TREM_QNT;
    linhas[2].add_trem(trens, conexoes);
    ids_trens[TREM_QNT]=TREM_QNT;
    linhas[2].add_trem(trens, conexoes);


    linhas[3].inicializa("ABD", ROSA);
    linhas[3].add_conexao(0,1,CON_TIPO_INICIO,conexoes);
    linhas[3].add_conexao(1,3,CON_TIPO_FIM,conexoes);
    linhas[3].add_conexao(3,1,CON_TIPO_INICIO,conexoes);
    linhas[3].add_conexao(1,0,CON_TIPO_FIM,conexoes);
    ids_trens[TREM_QNT]=TREM_QNT;
    linhas[3].add_trem(trens, conexoes);
    ids_trens[TREM_QNT]=TREM_QNT;
    linhas[3].add_trem(trens, conexoes);


    linhas[4].inicializa("GEDBCG", AZUL);
    linhas[4].add_conexao(6,4,CON_TIPO_INICIO,conexoes);
    linhas[4].add_conexao(4,3,CON_TIPO_NORMAL,conexoes);
    linhas[4].add_conexao(3,1,CON_TIPO_NORMAL,conexoes);
    linhas[4].add_conexao(1,2,CON_TIPO_NORMAL,conexoes);
    linhas[4].add_conexao(2,6,CON_TIPO_FIM,conexoes);
    ids_trens[TREM_QNT]=TREM_QNT;
    linhas[4].add_trem(trens, conexoes);
    ids_trens[TREM_QNT]=TREM_QNT;
    linhas[4].add_trem(trens, conexoes);
        //ids_trens[TREM_QNT]=TREM_QNT;
    //linhas[1].add_trem(trens, conexoes);

/*
    linhas[5].inicializa("GIHF", AMARELO);
    linhas[5].add_conexao(6,8,CON_TIPO_INICIO,conexoes);
    linhas[5].add_conexao(8,7,CON_TIPO_NORMAL,conexoes);
    linhas[5].add_conexao(7,5,CON_TIPO_NORMAL,conexoes);
    linhas[5].add_conexao(5,6,CON_TIPO_FIM,conexoes);
    ids_trens[TREM_QNT]=TREM_QNT;
    linhas[5].add_trem(trens, conexoes);
    ids_trens[TREM_QNT]=TREM_QNT;
    linhas[5].add_trem(trens, conexoes);*/



    // Inicializa dados da central
    for(i=0; i < TREM_QNT; i++){
        cout << "---" << trens[i].plataforma_atual_id << endl;
        CENTRAL_TRENS[i] = atualiza_posicao_trem(-1, trens[i].plataforma_atual_id, trens[i].conexao_atual_id, trens[i].percorrido, trens[i].velocidade_atual);
    }

    // inicializa plataformas
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
                ids_paineis[PAINEL_QNT]=PAINEL_QNT;
                paineis[PAINEL_QNT].inicializa(plataformas[i].id, linha_id, linhas[linha_id].cor, plataformas, linhas, conexoes);
            }
        }
    }
}


void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    int i=0;
    //linhas[0].inicializa("ACGJ", VERDE);
    conexoes[i].desenha(0,-2); i++;
    conexoes[i].desenha(0,-3); i++;
    conexoes[i].desenha(0,-2); i++;
    conexoes[i].desenha(0,1); i++;
    conexoes[i].desenha(0,0); i++;
    conexoes[i].desenha(0,1); i++;

    //linhas[1].inicializa("DEGIH", VERMELHO);
    conexoes[i].desenha(0,0); i++;
    conexoes[i].desenha(0,0); i++;
    conexoes[i].desenha(0,0); i++;
    conexoes[i].desenha(0,0); i++;
    conexoes[i].desenha(-1,2); i++;
    conexoes[i].desenha(0,2); i++;
    conexoes[i].desenha(-1,2); i++;
    conexoes[i].desenha(0,2); i++;


    //linhas[2].inicializa("FGJ", AMARELO);
    conexoes[i].desenha(2,0); i++;
    conexoes[i].desenha(1,4); i++;
    conexoes[i].desenha(1,7); i++;
    conexoes[i].desenha(-1,0); i++;

    //linhas[3].inicializa("ABD", ROSA);
    conexoes[i].desenha(-3,0); i++;
    conexoes[i].desenha(-3,0); i++;
    conexoes[i].desenha(0,0); i++;
    conexoes[i].desenha(0,0); i++;

    //linhas[4].inicializa("GEDBCG", AZUL);
    conexoes[i].desenha(-4,4); i++;
    conexoes[i].desenha(0,5); i++;
    conexoes[i].desenha(3,0); i++;
    conexoes[i].desenha(0,0); i++;
    conexoes[i].desenha(-2,-5); i++;
/*
    //linhas[5].inicializa("GIHF", AMARELO);
    conexoes[i].desenha(0,0); i++;
    conexoes[i].desenha(0,0); i++;
    conexoes[i].desenha(0,0); i++;
    conexoes[i].desenha(0,0); i++;*/

    //conexoes[i].desenha(0,0); i++;

    for(i=0; i<PLATAFORMA_QNT; i++){
        plataformas[i].desenha();
    }

    for(i=0; i<PAINEL_QNT; i++){
        paineis[i].desenha();
    }

    for(i=0; i<TREM_QNT; i++){
        trens[i].desenha(plataformas,conexoes);
    }

    for(i=0; i<PAINEL_QNT; i++){
        paineis[i].atualiza_tempo_tela();
    }
    glutSwapBuffers();
}

void atualiza(int passo){
    glutPostRedisplay();
    glutTimerFunc(CENTESIMO*1000, atualiza, 1);

}
