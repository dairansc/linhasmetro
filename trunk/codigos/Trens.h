class Trens
{
public:
    void atualiza_posicao ();
    int id;
    int linha_id;
    int thread_id;
    int plataforma_atual_id;
    int conexao_atual_id;
    float velocidade_atual;
    float percorrido;
    GLcor cor;
};
