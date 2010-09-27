//#include <iostream>
//#include <string>
//using namespace std;

class Conexoes
{
public:
    int id;
    int de_plataforma_id;
    int ate_plataforma_id;
    float distancia;
    bool com_defeito;
    int tipo_conexao;

    void inicializa (int, int, int, GLcor);
    void desenha (int, int);
    GLcor cor;
};

void Conexoes::inicializa (int de_plat_id, int ate_plat_id, int tipo_con, GLcor c){
    this->id = CON_QNT;
    CON_QNT++;
    this->de_plataforma_id = de_plat_id;
    this->ate_plataforma_id = ate_plat_id;
    this->com_defeito = false;
    this->tipo_conexao = tipo_con;
    this->cor = c;

    int x1, x2, y1, y2;
    x1 = plataformas[de_plat_id].posX;
    x2 = plataformas[ate_plat_id].posX;
    y1 = plataformas[de_plat_id].posY;
    y2 = plataformas[ate_plat_id].posY;

    this->distancia = sqrt( pow(x2-x1,2) + pow(y2-y1,2) );

    cout << "Nova Conexão da Plataforma " << this->de_plataforma_id << " ate "<< this->ate_plataforma_id << ", ditancia: " << this->distancia << endl;
}

void Conexoes::desenha(int offsetX, int offsetY){
    glColor3f(cor.r, cor.g, cor.b);
    glBegin(GL_LINES);
    glVertex2f(plataformas[de_plataforma_id].posX + offsetX, plataformas[de_plataforma_id].posY + offsetY);
    glVertex2f(plataformas[ate_plataforma_id].posX + offsetX, plataformas[ate_plataforma_id].posY + offsetY);
    glEnd();
}
