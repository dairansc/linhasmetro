//#define PI 3.1415926535898
#define JANELA_TITULO "Linhas de Metro"
#define JANELA_TAM_X 1000
#define JANELA_TAM_Y 500
//#define JANELA_COR_FUNDO PRETO
//#define JANELA_COR_TEXTO BRANCO

GLcor BRANCO =   {1.0, 1.0, 1.0},
      PRETO =    {0.0, 0.0, 0.0},
      VERMELHO = {1.0, 0.25, 0.25},
      VERDE =    {0.25, 1.0, 0.25},
      AZUL =     {0.25, 0.25, 1.0},
      AMARELO =  {1.0, 1.0, 0.25},
      CINZA   =  {0.5, 0.5, 0.5},
      ROSA =     {1.0, 0.25, 1.0};


#define PLATAFORMA_RAIOX 20.0
#define PLATAFORMA_RAIOY 10.0
#define PLATAFORMA_QNT_MAX 10
int PLATAFORMA_QNT = 0;
GLcor PLATAFORMA_COR_BORDA = PRETO,
      PLATAFORMA_COR_FUNDO = BRANCO,
      PLATAFORMA_COR_TEXTO = VERMELHO;
int PLATAFORMA_SLOTS[16][2] = //posição de cada painel em relação a plataforma
           {{0,27},  {0,38},
            {0,-27}, {0,-38},
            {0,49},  {0,60},
            {0,-49}, {0,-60},
            {-47,17},{-47,6},
            {-47,-5},{-47,-16},
            {47,17}, {47,6},
            {47,-5}, {47,-16}};

#define CON_TIPO_NORMAL 0
#define CON_TIPO_INICIO 1
#define CON_TIPO_FIM    2
#define CON_QNT_MAX     50
int CON_QNT = 0;

#define LINHA_CON_QNT_MAX 50
#define LINHA_QNT_MAX 8
int LINHA_QNT = 0;

#define TREM_QNT_MAX 30
int TREM_QNT = 0;

#define PAINEL_QNT_MAX 30
int PAINEL_QNT = 0;
GLcor PAINEL_COR_FUNDO = CINZA,
      PAINEL_COR_TEXTO = BRANCO;


#define ERRO_CRITICO 0
#define ERRO_INFO 1
