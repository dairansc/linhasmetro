using namespace std;
#include <iostream>
#include <string>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <pthread.h>

//cabeçalhos próprios
#include "openGLlib.h"
#include "defines.h"
#include "lib.h"

Central CENTRAL_TRENS[TREM_QNT_MAX];

pthread_t t_trens[TREM_QNT_MAX],
          t_paineis[PAINEL_QNT_MAX];

int ids_trens[TREM_QNT_MAX],
    ids_paineis[PAINEL_QNT_MAX];

void *thread_trem(void*);
void *thread_painel(void*);

//Classes
#include "Plataformas.h"
Plataformas plataformas[PLATAFORMA_QNT_MAX];
#include "Conexoes.h"
Conexoes conexoes[CON_QNT_MAX];
#include "Trens.h"
Trens trens[TREM_QNT_MAX];
#include "Linhas.h"
Linhas linhas[LINHA_QNT_MAX];
#include "Paineis.h"
Paineis paineis[PAINEL_QNT_MAX];

void *thread_trem(void * argumentos){
    int id = * (int *)argumentos;
    int qnt_conexoes, cont_conexoes = 0, cont_tempo = 0;
    float intervalo_tempo = TREM_INTERVALO_COMUNICACAO/CENTESIMO;
    trens[id].plataforma_atual_id = -1;
    trens[id].conexao_atual_id = linhas[ trens[id].linha_id ].conexoes[cont_conexoes];
    qnt_conexoes = linhas[ trens[id].linha_id ].qnt_conexoes;
    cout << "Nova thread Trem[" << id << "] pertencente a linha " << trens[id].linha_id << endl;
    //cout << linhas[ trens[id].linha_id ].qnt_trens << endl;
    sleep((id - linhas[ trens[id].linha_id -1 ].qnt_trens) * TREM_INTERVALO_SAIDA);
    while(1){
        usleep(CENTESIMO * 1000000);
        //cout << "Thread Trem: " << id << endl;
        if(trens[id].velocidade_atual < VELOCIDADE_MAXIMA){
            trens[id].velocidade_atual += ACELERACAO;
        }
        if((conexoes[ trens[id].conexao_atual_id ].distancia - trens[id].percorrido) < trens[id].velocidade_atual/DESACELERACAO){
            trens[id].velocidade_atual -= DESACELERACAO;
        }

        if((conexoes[ trens[id].conexao_atual_id ].distancia - trens[id].percorrido)<=0){
            trens[id].velocidade_atual = 0;
            trens[id].percorrido = 0;
            trens[id].plataforma_atual_id = conexoes[ trens[id].conexao_atual_id ].ate_plataforma_id;
            trens[id].conexao_atual_id = -1;
            CENTRAL_TRENS[id] = atualiza_posicao_trem(id, trens[id].plataforma_atual_id, trens[id].conexao_atual_id, trens[id].percorrido, trens[id].velocidade_atual);
            sleep(TEMPO_NA_PLATAFORMA);
            trens[id].plataforma_atual_id = -1;

            if(cont_conexoes == (qnt_conexoes-1)){
                cont_conexoes=0;
            }
            else{
                cont_conexoes++;
            }
            trens[id].conexao_atual_id = linhas[ trens[id].linha_id ].conexoes[cont_conexoes];
            //cout<< "Conexão atual: "<<trens[id].conexao_atual_id<< "  Contador: " << cont_conexoes << endl;
        }
        else{
            trens[id].percorrido += trens[id].velocidade_atual * CENTESIMO;
        }

        if(intervalo_tempo == cont_tempo){
            cont_tempo = 0;
            CENTRAL_TRENS[id] = atualiza_posicao_trem(id, trens[id].plataforma_atual_id, trens[id].conexao_atual_id, trens[id].percorrido, trens[id].velocidade_atual);
        }
        else{
            cont_tempo++;
        }
    }
    return (NULL);
}

void *thread_painel(void * argumentos){
    int id = * (int *)argumentos;
    int i, prox_qnt_plat = 0, prox_qnt_cons = 0;

/*
    for(i=0; i<TREM_QNT; i++){
        cout << CENTRAL_TRENS[i].plataforma_id << endl;
    }*/


    cout << "Nova thread Painel[" << id << "] na plataforma " << paineis[id].plataforma_id << ",  pertencente a linha " << paineis[id].linha_id << endl;

    while(1){
        usleep(CENTESIMO * 1000000);
        // verifica se tem trem na plataforma do painel
        //if(paineis[id].trem_esta_na_plataforma(linhas)){
        //    paineis[id].set_tempo(0);
        //}
        if(paineis[id].proximo_trem_pos_vet >= 0 && CENTRAL_TRENS[ paineis[id].proximo_trem_pos_vet ].plataforma_id == paineis[id].plataforma_id){
            paineis[id].set_tempo(0);
            paineis[id].proximo_trem_pos_vet = -1;
        }
        else if(paineis[id].proximo_trem_pos_vet < 0 && CENTRAL_TRENS[ paineis[id].proximo_trem_pos_vet ].plataforma_id != paineis[id].plataforma_id){
            paineis[id].procura_prox_trem(linhas, conexoes);
            //for(i=0; i<qnt_conexoes && !encontrou; i++){

            //}
        }
        else if(CENTRAL_TRENS[ paineis[id].proximo_trem_pos_vet ].plataforma_id != paineis[id].plataforma_id){
            paineis[id].calcula_tempo(linhas, conexoes);
        }
    }

    return (NULL);
}

#include "inicializacao.h"


int main(int argc, char** argv){
    glutInit(&argc, argv);
    //  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (JANELA_TAM_X, JANELA_TAM_Y);
    glutInitWindowPosition (10, 10);
    glutCreateWindow (JANELA_TITULO);
    init();

    glutDisplayFunc(display);
    glutTimerFunc(CENTESIMO*1000 ,atualiza, 1);
    glutKeyboardFunc(keyboard);
    //glutMouseFunc(mouse);
    glutMainLoop();

    int i;
    for(i=0; i<TREM_QNT; i++){
        pthread_join(t_trens[i], NULL);
    }
    for(i=0; i<PAINEL_QNT; i++){
        pthread_join(t_paineis[i], NULL);
    }
    return 0;

}
