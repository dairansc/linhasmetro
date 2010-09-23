class Paineis
{
public:
    void inicializa (int, int, int, GLcor, int);
    void desenha ();
    void procura_prox_trem ();
    void set_tempo (int segundos);

    int id;
    int plataforma_id;
    int linha_id;
    int thread_id;
    int proximo_trem_id;
    int posX;
    int posY;
private:
    void atualiza_tempo_tela ();

    int horas;
    int minutos;
    int segundos;
    GLcor cor;
};

void inicializa (int plat_id, int linha_id, int ocupar_painel, GLcor c, int id)
{

}
