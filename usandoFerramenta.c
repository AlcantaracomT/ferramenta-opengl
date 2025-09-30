#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <GL/glut.h>
#include "ferramenta.h"

// Definição das variáveis globais
char c;
int a = 0;
float escala = 0.35f;
float cameraX = 0, cameraY = 0;
int move = 0, eixoX = 0, eixoY = 0;
float posX = 0.0f, posY = 0.0f, posZ = -5.0f;
float eixoX1 = 0.0f, eixoY1 = 0.0f, eixoZ1 = 0.0f;
float escalaX = 1.0f, escalaY = 1.0f, escalaZ = 1.0f;
int entrada = 0;
int largura = 1200, altura = 900;
int cor = 0;



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

    // aplica rotação da câmera em torno do objeto
    glTranslatef(0.0f, 0.0f, -5.0f);
    glRotatef(cameraX, 1, 0, 0);
    glRotatef(cameraY, 0, 1, 0);
    
    glPushMatrix();
        glScalef(escala, escala, escala); //  | zoom no mundo todo


        //---------- Desenho do cubo com a ferramenta ----------
        glPushMatrix();
            glTranslatef(posX, posY, posZ);
            glRotatef(eixoX1, 1.0, 0.0, 0.0);
            glRotatef(eixoY1, 0.0, 1.0, 0.0);
            glRotatef(eixoZ1, 0.0, 0.0, 1.0);
            glScalef(escalaX, escalaY, escalaZ);
            criaCubo(-1.9, 1.9, 9);  
        glPopMatrix();

	    //imprimir
        
        if (c == 'p') 
        {
            percorre();
        }

        if(a == 1)
        {
            system("rm -f a");
            system("gcc usandoFerramenta.c ferramenta.h -o a -lGL -lGLU -lglut -lm");
            execl("./a", "./a", NULL);
            perror("exec");
        }

        
    glPopMatrix();
    glFlush();
}

void iniciar()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (float)largura / altura, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

// usando o mouse

//ok
void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON)
    {
        if (state == GLUT_DOWN)
        {
            move = 1;
            eixoY = x;
            eixoX = y;
        }
        else if (state == GLUT_UP)
        {
            move = 0;
        }
    }
}


//ok
void movimento(int x, int y)
{
    if (move)
    {
        int dx = x - eixoY;
        int dy = y - eixoX;

        cameraX += dy * 0.5f;
        cameraY += dx * 0.5f;

        eixoY = x;
        eixoX = y;
        glutPostRedisplay();
    }
}   


// usando teclado
//ok
void Teclado(unsigned char key, int x, int y)
{
    if(key == 'c')
        entrada = 0;
    if(key == 'z')
        entrada = 1;
    if(key == 'x')
        entrada = 2;
    if(key == 'p')
        c = 'p';

    if(entrada == 0)
    {
        switch (key)
        {
        case 27: // esc sair
            exit(0);
            break;

        case 'w':
            posY += 0.5f; //  |mover para cima
            break;

        case 's':
            posY -= 0.5f; //  |mover para baixo
            break;

        case 'a': //           |mover para esquerda
            posX -= 0.5f;
            break;

        case 'd': //           |mover para direita
            posX += 0.5f;
            break;

        case 'e':
            posZ -= 0.5f; //   |mover para frente
            break;

        case 'r': //           |mover para trás
            posZ += 0.5f;
            break;
        
        //----- zoom no mundo todo -----
        case '+':
            escala += 0.1f; //   |aumentar tamanho
            if (escala > 0.80f)
                escala = 0.80f;
            break;

        case '-':
            escala -= 0.1f; //   |diminuir tamanho
            if (escala < 0.20f)
                escala = 0.20f;
            break;
        //---------------------------

        default:
            
            break;
        }
    }

    if(entrada == 1) //escala
    {
        switch (key)
        {
        case 27: // esc sair
            exit(0);
            break;
        case 'w': //           |aumenta altura
            escalaY += 0.1f;
            break;

        case 's'://           |diminui altura
            escalaY -= 0.1f;
            break;

        case 'a'://           |diminui profundidade
            escalaZ -= 0.1f;
            break;

        case 'd': //           |aumenta profundidade
            escalaZ += 0.1f;
            break;

        case 'e': 
            escalaX += 0.1f;// |aumenta largura
            break;

        case 'r': //           |diminui largura
            escalaX -= 0.1f;
            break;

        //----- zoom no mundo todo -----
        case '+':
            escala += 0.1f; //   |aumentar tamanho
            if (escala > 0.80f)
                escala = 0.80f;
            break;

        case '-':
            escala -= 0.1f; //   |diminuir tamanho
            if (escala < 0.20f)
                escala = 0.20f;
            break;
        //---------------------------

        default:
            
            break;
        break;
        }
    }

    if(entrada == 2)
    {
        switch (key)
        {
        case 27: // esc sair
            exit(0);
            break;
        case 'w': 
            eixoX1 -= 5;
            break; //       |gira cima

        case 's':
            eixoX1 += 5;
            break; //       |gira baixo

        case 'a':
            eixoY1 -= 5;
            break; //       |gira esquerda

        case 'd':
            eixoY1 += 5;
            break; //       |gira direita
        case 'e':
            eixoZ1 += 5;  // gira sentido horário (↻)
            break;

        case 'r':
            eixoZ1 -= 5;  // gira sentido anti-horário (↺)
            break;

        
         //----- zoom no mundo todo -----
        case '+':
            escala += 0.1f; //   |aumentar tamanho
            if (escala > 0.80f)
                escala = 0.80f;
            break;

        case '-':
            escala -= 0.1f; //   |diminuir tamanho
            if (escala < 0.20f)
                escala = 0.20f;
            break;
        //---------------------------
        
        default:
            
            break;
        break;
        }
    }
    glutPostRedisplay();
}


//rotação do objeto 3D -----
void tecladoEspecial(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_UP:
        eixoX1 -= 5;
        break; //       |gira cima

    case GLUT_KEY_DOWN:
        eixoX1 += 5;
        break; //       |gira baixo

    case GLUT_KEY_LEFT:
        eixoY1 += 5;
        break; //       |gira direita

    case GLUT_KEY_RIGHT:
        eixoY1 -= 5;
        break; //       |gira esquerda
    }

    glutPostRedisplay();
}

void cria(char *buffer, int pos, long tamanho) 
{
    char texto[312];

    //vai receber
    snprintf(texto, sizeof(texto), "\nglPushMatrix();\n    glTranslatef(%.2ff, %.2ff, %.2ff);\n    glRotatef(%.2ff, 1.0f, 0.0f, 0.0f);\n    glRotatef(%.2ff, 0.0f, 1.0f, 0.0f);\n    glScalef(%.2ff, %.2ff, %.2ff);\n    criaCubo(-1.9, 1.9, 9);\nglPopMatrix();", posX, posY, posZ, eixoX1, eixoY1, escalaX, escalaY, escalaZ);
  
    // novo arquivo sobrescrevendo .c
    FILE *f = fopen("usandoFerramenta.c", "w");
    if (!f) { perror("fopen"); return; }

    fwrite(buffer, 1, pos, f);

    // Escreve o texto
    fprintf(f, "%s\n\t", texto);

    // Escreve o resto do arquivo
    fwrite(buffer + pos, 1, tamanho - pos, f);

    fclose(f);
}

void percorre() 
{
    a = 1;
    FILE *f = fopen("usandoFerramenta.c", "r");
    if (!f) { perror("fopen"); return; }

    // Descobre tamanho do arquivo
    fseek(f, 0, SEEK_END);
    long tamanho = ftell(f);
    rewind(f);

    // Lê tudo em memória
    char *buffer = malloc(tamanho + 1);
    fread(buffer, 1, tamanho, f);
    buffer[tamanho] = '\0';
    fclose(f);

    for (long pos = 0; pos < tamanho; pos++) {
        if (strncmp(&buffer[pos], "//imprimir", 10) == 0) {
            cria(buffer, pos, tamanho);
            break;
        }
    }
    free(buffer);
}

//rodar: gcc usandoTerramenta.c -lGL -lGLU -lglut -o a


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
    glutMouseFunc(mouse); 
    glutMotionFunc(movimento);
    glutSpecialFunc(tecladoEspecial);
    glutMainLoop();
    return 0;
}
