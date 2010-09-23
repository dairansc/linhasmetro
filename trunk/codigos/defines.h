//#define PI 3.1415926535898
#define JANELA_TITULO "Linhas de Metro"
#define JANELA_TAM_X 1000
#define JANELA_TAM_Y 500
//#define JANELA_COR_FUNDO PRETO
//#define JANELA_COR_TEXTO BRANCO

GLcor BRANCO =   {1.0, 1.0, 1.0},
      PRETO =    {0.0, 0.0, 0.0},
      VERMELHO = {1.0, 0.0, 0.0},
      VERDE =    {0.0, 1.0, 0.0},
      AZUL =     {0.0, 0.0, 1.0},
      AMARELO =  {1.0, 1.0, 0.0},
      ROSA =     {1.0, 0.0, 1.0};


#define PLATAFORMA_RAIOX 20.0
#define PLATAFORMA_RAIOY 10.0
#define PLATAFORMA_QNT_MAX 10
int PLATAFORMA_QNT = 0;
GLcor PLATAFORMA_COR_BORDA = BRANCO,
      PLATAFORMA_COR_TEXTO = VERDE;
int PLATAFORMA_SLOTS[16][2] = //posição de cada painel em relação a plataforma
           {{0,17},  {0,28},
            {0,39},  {0,50},
            {0,-17}, {0,-28},
            {0,-39}, {0,-50},
            {-47,17},{-47,6},
            {-47,-5},{-47,-16},
            {47,17}, {47,6},
            {47,-5}, {47,-16}};

#define CON_TIPO_NORMAL 0
#define CON_TIPO_INICIO 1
#define CON_TIPO_FIM    2
#define CON_QNT_MAX     50
int CON_QNT = 0;

#define LINHA_QNT_MAX 8
int LINHA_QNT = 0;
