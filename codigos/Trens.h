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
    void desenha();
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

    cout << "Novo Trem da Linha " << this->linha_id << " plataforma inicial: "<< this->plataforma_atual_id << endl;
}
