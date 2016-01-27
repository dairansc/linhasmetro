# Introdução #

_**Data de Entrega: 30/09/2010**_

Projeto a ser desenvolvido para a disciplina de **Sistemas de Tempo Real**.
Consiste em implementar painéis em cada estação onde esses irão informar o tempo que um determinado trem do metrô levará para chegar na estação, os trens deverão percorrer suas rotas informando suas posições de tempo em tempo (threads trens), enquanto os painéis recebem esse sinal, efetuam a operação do tempo restante e mostra na tela (outras threads paineis).

# Especificações #

  * Deve conter no mínimo **8 linhas** de trem.

# Detalhes #

  * O professor sugeriu desenhar na tela com a biblioteca conio\_linux.h disponibilizada em http://www.inf.pucrs.br/~celso/Progs/ mas como é no modo texto, é quase certo que teríamos problemas com a monitoração visual. Como solução para isso será utilizada a biblioteca gráfica **OpenGL**, que para esse projeto seu uso é bem simples.
  * Introdução e consulta de diversos exemplos para a biblioteca OpenGL em
    * http://www.ft.unicamp.br/~magic/opengl/index2006.html
    * http://www.inf.pucrs.br/~manssour/OpenGL/Tutorial.html
  * Instalação da biblioteca OpenGL no linux para poder compilar:
> > `apt-get install freeglut3 freeglut3-dev libglut3 libglut3-dev`