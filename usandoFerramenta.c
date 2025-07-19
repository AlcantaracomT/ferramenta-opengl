#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include "ferramenta.h"

// Protótipos
void iniciar();
void criaCubo(float menos, float mais, int cor);
void desenho3D();
void Teclado(unsigned char key, int x, int y);


// Variáveis globais
int largura = 1200, altura = 900; // dimensões da janela
int cor = 0; // cor do desenho


void criaCubo(float menos, float mais, int cor)
{
    glBegin(GL_QUADS);
    
        //--- Definindo a cor com base na variável global 'cor' ---
        if(cor == 1)
            glColor3f(1.0f, 0.992f, 0.9647f);//   |branco
        else if(cor == 2)
            glColor3f(0.545f, 0.271f, 0.075f); // |Marrom 
        else if(cor == 3)
            glColor3f(0.0f, 0.0f, 0.0f);//        |preto
        else if(cor == 4)
            glColor3f(0.941f, 0.894f, 0.827f); // |claro
        else if(cor == 5)
            glColor4f(0.0f, 0.5f, 0.7f, 0.5f);//  |azul com transparência
        else if(cor == 6)
            glColor3f(0.13f, 0.55f, 0.13f); //    |verde floresta
        else if(cor == 7)
            glColor3f(1.0f, 0.843f, 0.0f); //     |amarelo
        else if(cor == 8)
            glColor3f(0.8f, 0.3f, 0.5f); //       |rosa
        // ------------------------------------------------------
        
        // Frente
        if(cor == 9)
           glColor3f(1.0f, 0.992f, 0.9647f);//branco
        
        glVertex3f(menos, menos, mais);
        glVertex3f(mais, menos, mais);
        glVertex3f(mais, mais, mais);
        glVertex3f(menos, mais, mais);

        // Traseira
        if(cor == 9)
            glColor3f(0.545f, 0.271f, 0.075f); // Marrom

        glVertex3f(menos, menos, menos);
        glVertex3f(menos, mais, menos);
        glVertex3f(mais, mais, menos);
        glVertex3f(mais, menos, menos);

        // Esquerda
        if(cor == 9)
            glColor4f(0.0f, 0.5f, 0.7f, 0.5f);// azul com transparência

        glVertex3f(menos, menos, menos);
        glVertex3f(menos, menos, mais);
        glVertex3f(menos, mais, mais);
        glVertex3f(menos, mais, menos);

        // Direita
        if(cor == 9)
            glColor3f(1.0f, 0.843f, 0.0f); // Amarelo

        glVertex3f(mais, menos, menos);
        glVertex3f(mais, mais, menos);
        glVertex3f(mais, mais, mais);
        glVertex3f(mais, menos, mais);

        // Superior
        if(cor == 9)
            glColor3f(0.941f, 0.894f, 0.827f); // Claro

        glVertex3f(menos, mais, menos);
        glVertex3f(menos, mais, mais);
        glVertex3f(mais, mais, mais);
        glVertex3f(mais, mais, menos);

        // Inferior
        if(cor == 9)
            glColor3f(0.8f, 0.3f, 0.5f); // rosa

        glVertex3f(menos, menos, menos);
        glVertex3f(mais, menos, menos);
        glVertex3f(mais, menos, mais);
        glVertex3f(menos, menos, mais);

    glEnd();
}

void desenho3D()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    iniciar();
    glRotatef(eixoX, 1.0, 0.0, 0.0);
    glRotatef(eixoY, 0.0, 1.0, 0.0);
    
    glPushMatrix();
        glScalef(escala, escala, escala); //  | zoom no mundo todo


        //---------- Desenho do cubo com a ferramenta ----------
        glPushMatrix();
            glTranslatef(posX, posY, posZ); //     |posição do cubo com a ferramenta
            glRotatef(eixoX1, 1.0, 0.0, 0.0); //   |rotação do cubo com a ferramenta
            glRotatef(eixoY1, 0.0, 1.0, 0.0); //   |rotação do cubo com a ferramenta
            glScalef(escalaX, escalaY, escalaZ);// |escala do cubo com a ferramenta
            criaCubo(-1.9, 1.9, 9); //             |Base Desenho cubo
        glPopMatrix();
        //-------------------------------

        //---------- coordenadas do objeto 3D com a ferramenta ----------
        printf("\nglPushMatrix();\n");
        printf("    glTranslatef(%.2ff, %.2ff, %.2ff);\n", posX, posY, posZ);
        printf("    glRotatef(%.2ff, 1.0f, 0.0f, 0.0f);\n", eixoX1);
        printf("    glRotatef(%.2ff, 0.0f, 1.0f, 0.0f);\n", eixoY1);
        printf("    glScalef(%.2ff, %.2ff, %.2ff);\n", escalaX, escalaY, escalaZ);
        //-------------------------------


        // chão
        glPushMatrix();
            glTranslatef(0.00, -1.36, -1.76);
            glScalef(13.70, 0.10, 15.66);
            criaCubo(-1.9, 1.9, 6);
        glPopMatrix();

    glPopMatrix();
    glFlush();
}

// função para iniciar a janela OpenGL
void iniciar()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (float)largura / altura, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

// função principal
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(largura, altura);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("3D");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glutDisplayFunc(desenho3D);
    glutKeyboardFunc(Teclado);
    glutMainLoop();
    return 0;
}
