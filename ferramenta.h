#ifndef REST_H
#define REST_H

// Variáveis globais (somente extern)
extern char c;
extern int a;
extern float escala;
extern float cameraX, cameraY;
extern int move, eixoX, eixoY;
extern float posX, posY, posZ;
extern float eixoX1, eixoY1;
extern float escalaX, escalaY, escalaZ;
extern int entrada;
extern int largura, altura;
extern int cor;

// Protótipos
void mouse(int button, int state, int x, int y);
void movimento(int x, int y);
void Teclado(unsigned char key, int x, int y);
void tecladoEspecial(int key, int x, int y);
void cria(char *buffer, int pos, long tamanho);
void criaCubo(float menos, float mais, int cor);
void desenho3D();
void iniciar();
void percorre();

#endif