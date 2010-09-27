//#include <iostream>
//#include <string>
//#include "Conexoes.h"
//using namespace std;

class Linhas
{
public:
    void inicializa (string , GLcor);
    void add_conexao (int, int, int, Conexoes*);
    void desenha(Conexoes*);

    int id;
    string nome;
    int conexoes[LINHA_CON_QNT_MAX];
    int qnt_conexoes;
    GLcor cor;
};

void Linhas::desenha(Conexoes *cons){
    /*for (int i = 0; i<this->qnt_conexoes; i++){
        cons[this->conexoes[i]].desenha();
    }*/
}

void Linhas::inicializa(string n, GLcor c){
    this->id = LINHA_QNT;
    LINHA_QNT++;
    this->nome = n;
    this->cor = c;
    this->qnt_conexoes = 0;
    cout << "Nova Linha " << this->nome << "["<< this->id << "]" << endl;
}

void Linhas::add_conexao(int de, int para, int tipoConexao, Conexoes *cons){
    this->conexoes[this->qnt_conexoes] = CON_QNT;
    this->qnt_conexoes++;
    cons[CON_QNT].inicializa(de, para, tipoConexao, this->cor);
    cout << "\tLinha " << this->nome << "[" << this->id << "], com conexões: ";
    for (int i = 0; i<this->qnt_conexoes; i++){
        cout << this->conexoes[i] << " ";
    }
    cout << endl;
}
/*
void chama_ini(de, para, tipoConexao, this->cor){

}*/

