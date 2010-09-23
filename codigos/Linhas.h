//#include <iostream>
//#include <string>
//#include "Conexoes.h"
//using namespace std;

class Linhas
{
public:
    void inicializa (string , GLcor , int);
    void add_conexao (int, int, int, int);
    void desenha_legenda ();

    int id;
    string nome;
    Conexoes * conexoes;
private:
    GLcor cor;
};

void Linhas::desenha_legenda()
{
}

void Linhas::inicializa(string n, GLcor c, int id){
    this->id = id;
    this->nome = n;
    this->cor = c;
}

void Linhas::add_conexao(int de, int para, int tipoConexao, int id_conexao){

}
