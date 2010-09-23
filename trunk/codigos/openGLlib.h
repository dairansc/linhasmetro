typedef struct GLfloat3v{
    GLfloat r;
    GLfloat g;
    GLfloat b;
}GLcor;

void bitmap_output(int x, int y, string str, void *font){
  int len, i;

  glRasterPos2f(x, y);
  len = str.length();
  for (i = 0; i < len; i++) {
    glutBitmapCharacter(font, str[i]);
  }
}

void keyboard(unsigned char key, int x, int y){
    switch (key) {
    case 27: case 13:                           // tecla Esc ou Enter(encerra o programa)
        exit(0);
        break;
    }
}
