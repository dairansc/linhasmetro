#ifndef GL_H
#define GL_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cmath>
#include <GL/glut.h>

class Renderer;

class GL {
	public:
		// Inicializa a biblioteca gráfica, cria a janela e recebe o objeto Renderer
		static void init(std::string titulo, Renderer* render);

		// Métodos de desenho: todas as coordenadas são CARTESIANAS

		// Desenha um retângulo: informar os pontos dos cantos
		// superior esquerdo e inferior direito
		static void drawRect(float x1, float y1, float x2, float y2);
		// Pinta um retângulo, idem
		static void fillRect(float x1, float y1, float x2, float y2);

		// Desenha um triângulo: recebe 3 pontos
		static void drawTri(float x1, float y1, float x2, float y2, float x3, float y3);

		// Pinta um triângulo, idem
		static void fillTri(float x1, float y1, float x2, float y2, float x3, float y3);

		// Desenha um círculo, recebe o centro e o raio
		static void drawCirc(float x1, float y1, float r);

		// Pinta um círculo, idem
		static void fillCirc(float x1, float y1, float r);

		// Desenha uma linha: recebe o ponto inicial e final
		static void drawLine(float x1, float y1, float x2, float y2);

		// Seta a cor de desenho, especificada em RGB (0-255 para cada componente)
		static void setColor(GLubyte r, GLubyte g, GLubyte b);

		// Seta a largura das linhas, especificada como um float (1.0 = 1 pixel de largura)
        static void setLineWidth(GLfloat w);

		// Ativa o loop principal de desenho, não retorna
		static void loop();
	private:
		// O objeto Renderer, responsável por fazer o desenho
		static Renderer* renderer;

		// Métodos privados, não podem ser utilizados externamente
		static void clear();
		static void draw();
		static void reshape(int width, int height);
		static void keyboard(unsigned char key, int x, int y);
		static void rect(GLenum prim, float x1, float y1, float x2, float y2);
		static void tri(GLenum prim, float x1, float y1, float x2, float y2, float x3, float y3);
};

#endif

