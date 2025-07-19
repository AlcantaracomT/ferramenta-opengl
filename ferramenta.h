//----- ângulos de rotação e zoom do mundo todo ----
float eixoX = 0, eixoY = 0, escala = 0.35f;

//----- posição do cubo com a ferramenta ----
float posX = 0.0f, posY = 0.0f, posZ = -5.0f;         //| mover o cubo com a ferramenta
float eixoX1 = 0.0f, eixoY1 = 0.0f;                   //| rotação do cubo com a ferramenta
float escalaX = 1.0f, escalaY = 1.0f, escalaZ = 1.0f; //| escala do cubo com a ferramenta

void Teclado(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27: // esc sair
        exit(0);
        break; 
        
    //----- rotacionar mundo todo ---
    case 'a':
        eixoY += 5; //     |gira direita
        break; 

    case 'd': //           |gira esquerda
        eixoY -= 5;
        break; 

    case 'w': //           |gira baixo
        eixoX += 5;
        if(eixoX > 180)
            eixoX = 180;
        break; 

    case 's': //           |gira cima
        eixoX -= 5;
        if(eixoX < 0)
            eixoX = 0;
        break; 
    //---------------------------

    //----- zoom no mundo todo -----
    case '+':
        escala += 0.1f; //   |aumentar tamanho
        if(escala > 0.80f)
            escala = 0.80f;
        break;

    case '-':
        escala -= 0.1f; //   |diminuir tamanho
        if(escala < 0.20f)
            escala = 0.20f;
        break;
    //---------------------------

    //-------- mover o objeto 3D-----
    case '1': 
        posZ -= 0.5f;//   |mover para frente
        break;

    case '2': //           |mover para trás
        posZ += 0.5f;
        break;

    case '4': //           |mover para esquerda
        posX -= 0.5f;
        break;

    case '6': //           |mover para direita
        posX += 0.5f;
        break;

    case '8':
        posY += 0.5f; //  |mover para cima
        break;
    case '5':
        posY -= 0.5f; //  |mover para baixo
        break;
    // -----------------------------

    //----- tamanho do objeto 3D -----
    case 'z': 
        escalaX += 0.1f;// |aumenta largura
        break;

    case 'x': //           |diminui largura
        escalaX -= 0.1f;
        break;

    case 'c': //           |aumenta altura
        escalaY += 0.1f;
        break;

    case 'v': //           |diminui altura
        escalaY -= 0.1f;
        break;

    case 'b': //           |aumenta profundidade
        escalaZ += 0.1f; 
        break; 

    case 'n': //           |diminui profundidade
        escalaZ -= 0.01f;
        break;
    // ------------------------------

    //----- rotação do objeto 3D -----
    case 'j':
        eixoY1 -= 5;
        break; //       |gira esquerda

    case 'l':
        eixoY1 += 5;
        break; //       |gira direita

    case 'i':
        eixoX1 -= 5;
        break; //       |gira cima

    case 'k':
        eixoX1 += 5;
        break; //       |gira baixo
    }
    // --------------------------------
    glutPostRedisplay();
}

/*
-------------------- estrutura para usar a ferramenta --------------------
* glTranslatef(posX, posY, posZ);
* glRotatef(eixoX1, 1.0, 0.0, 0.0);
* glRotatef(eixoY1, 0.0, 1.0, 0.0);
* glScalef(escalaX, escalaY, escalaZ);

---------- print necessário para usar a ferramenta -----------------------
printf("\nglPushMatrix();\n");
    printf("    glTranslatef(%.2ff, %.2ff, %.2ff);\n", posX, posY, posZ);
    printf("    glRotatef(%.2f, 1.0, 0.0, 0.0);\n", eixoX1);
    printf("    glRotatef(%.2f, 0.0, 1.0, 0.0);\n", eixoY1);
    printf("    glScalef(%.2f, %.2f, %.2f);\n", escalaX, escalaY, escalaZ);

*/