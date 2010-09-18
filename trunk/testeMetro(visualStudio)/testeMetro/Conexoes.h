#include <iostream>
#include <string>
using namespace std;

class Conexoes
{
public:
	int id;
	int de_painel_id;
	int ate_painel_id;
	int distancia;
	int com_defeito;
	void desenha ();
	Conexoes(void);
	~Conexoes(void);
private:
    GLcor cor;
};

Conexoes::Conexoes(void)
{
}


Conexoes::~Conexoes(void)
{
}

