void erro(string mensagem, int tipo){
    cout << mensagem << endl;
    switch(tipo){
        case ERRO_CRITICO:
            cout << "Ocorreu um erro crítico, o programa será terminado" << endl;
            exit(-1);
        break;
    }
}

typedef struct central_global{
    int plataforma_id;
    int conexao_id;
    float percorrido;
    float velocidade;
}Central;

Central atualiza_posicao_trem(int trem_id, int plat_id, int con_id, float perc, float veloc){
    Central t;
    t.plataforma_id = plat_id;
    t.conexao_id = con_id;
    t.percorrido = perc;
    t.velocidade = veloc;
    if(trem_id >= 0){
        cout << "Trem[" << trem_id << "], plataforma: " << t.plataforma_id << ", conexao: " << t.conexao_id << ", percorrido: " << t.percorrido << ",\tvelocidade: " << t.velocidade << endl;
    }
    return t;
}

void debug(int tipo, int quem, int aux){
    if(MODO_DEBUG){
        switch(tipo){
            case DEBUG_TREM:
                printf("Trem[%d] aguardando semáforo Trem[%d]...\n", quem, aux);
            break;
            /*case DEBUG_TREM_OK:
                printf("Trem[%d] liberado pelo semáforo Trem[%d]...\n", quem, aux);
            break;*/
            case DEBUG_PAINEL:
                printf("Painel[%d] aguardando semáforo Trem[%d]...\n", quem, aux);
            break;
            /*case DEBUG_PAINEL_OK:
                printf("Painel[%d] liberado pelo semáforo Trem[%d]...\n", quem, aux);
            break;*/
        }
    }
}
