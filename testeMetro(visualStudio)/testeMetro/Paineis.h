class Paineis 
{
private:
        void atualiza_tempo_tela ();
        int horas;
        int minutos;
        int segundos;
        GLcor cor;
public:
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
		void inicializa (int, int, int, GLcor);
};

void Paineis::inicializa(int idPlat, int idLinha, int ocuparPainel, GLcor color)
{
	plataforma_id = idPlat;
	linha_id = idLinha;
	cor = color;
}