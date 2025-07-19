# Ferramenta 3D em OpenGL (GLUT)
Este projeto foi desenvolvido depois que a professora da disciplina de **Computação Gráfica** deu a proposta de construir um **objeto 3D manualmente**, utilizando apenas primitivas do OpenGL, sem bibliotecas externas que facilitassem a modelagem.

A partir daí, tive a ideia de criar uma **ferramenta interativa** que facilitasse esse processo: com ela, é possível mover, rotacionar e redimensionar o objeto em tempo real, e então copiar os comandos gerados automaticamente no terminal para serem usados diretamente no código.

Isso transformou a tarefa de posicionar objetos 3D em algo muito mais prático e visual.


## 🧱 Como funciona

A tecla pressionada altera alguma propriedade (posição, rotação, escala). O terminal exibe o bloco `glPushMatrix()` com os valores atuais. É só copiar e colar.

### 📦 Controles:

| Tecla | Ação                             |
|-------|----------------------------------|
| `W/S` | Rotaciona o mundo (X)           |
| `A/D` | Rotaciona o mundo (Y)           |
| `+/-` | Zoom (mundo)                    |
| `1/2` | Move o objeto no eixo Z (frente e atrás)        |
| `4/6` | Move o objeto no eixo X (esquerda e direita)       |
| `8/5` | Move o objeto no eixo Y (cima e baixo)        |
| `Z/X` | Escala largura (X)              |
| `C/V` | Escala altura (Y)               |
| `B/N` | Escala profundidade (Z)         |
| `I/K` | Rotação do objeto (X)           |
| `J/L` | Rotação do objeto (Y)           |
| `ESC`| Sai do programa                  |

---

## 🔧 Instalação e Execução

### 1. Pré-requisitos

Este projeto pode ser executado em **Linux** ou **Windows**, desde que tenha:

* Um compilador C (`gcc`, `MinGW`, ou `Visual Studio`)
* OpenGL e a biblioteca **FreeGLUT** instalados/configurados

---

### 💻 No Linux (testado no Kali/Ubuntu)

#### 1. Instalar as bibliotecas necessárias:

```bash
sudo apt update
sudo apt install freeglut3-dev build-essential
```

#### 2. Compilar:

```bash
gcc main.c ferramenta.c -o ferramenta3d -lGL -lGLU -lglut -lm
```

> ⚠️ Certifique-se de que os arquivos `main.c` e `ferramenta.c` estejam na mesma pasta.

#### 3. Executar:

```bash
./ferramenta3d
```

---

### 🪟 No Windows (MinGW + FreeGLUT)

#### 1. Instalar:

* [MinGW](https://www.mingw-w64.org/)
* Bibliotecas `freeglut`, `opengl32`, `glu32` (você pode baixar binários ou instalar via pacotes como MSYS2)

#### 2. Compilar (via terminal do MinGW):

```bash
gcc main.c ferramenta.c -o ferramenta3d.exe -lfreeglut -lopengl32 -lglu32 -lm
```

> Inclua os headers e libs do FreeGLUT no diretório do MinGW, ou configure as variáveis de ambiente.

#### 3. Executar:

```bash
./ferramenta3d.exe
```
---

## 💡 Exemplo de saída (terminal)

Durante o uso da ferramenta, você poderá movimentar, rotacionar e escalar o objeto interativamente em tempo real.
Sempre que uma transformação é aplicada, o terminal imprime um bloco pronto para uso em seu código.

### 🧱 Estrutura recomendada no código:

```c
//---------- Desenho do cubo com a ferramenta ----------
glPushMatrix();
    glTranslatef(posX, posY, posZ);        // posição do cubo com a ferramenta
    glRotatef(eixoX1, 1.0, 0.0, 0.0);      // rotação do cubo com a ferramenta (eixo X)
    glRotatef(eixoY1, 0.0, 1.0, 0.0);      // rotação do cubo com a ferramenta (eixo Y)
    glScalef(escalaX, escalaY, escalaZ);   // escala do cubo com a ferramenta
    criaCubo(-1.9, 1.9, 9);                // base do desenho do cubo
glPopMatrix();
//-------------------------------
```

### 📤 Exemplo real impresso no terminal:

```c
glPushMatrix();
    glTranslatef(0.00f, 0.50f, -5.50f);
    glRotatef(10.00f, 1.0f, 0.0f, 0.0f);
    glRotatef(15.00f, 0.0f, 1.0f, 0.0f);
    glScalef(1.10f, 0.90f, 1.00f);
```

📌 **Basta copiar esse trecho e colá-lo diretamente no seu projeto**, substituindo os valores genéricos pelas transformações geradas, para fixar a posição, orientação e escala do objeto 3D desejado.

```c
//---------- Desenho do cubo com a ferramenta ----------
glPushMatrix();
    glTranslatef(0.00f, 0.50f, -5.50f);
    glRotatef(10.00f, 1.0f, 0.0f, 0.0f);
    glRotatef(15.00f, 0.0f, 1.0f, 0.0f);
    glScalef(1.10f, 0.90f, 1.00f);
    criaCubo(-1.9, 1.9, 9);                // base do desenho do cubo
glPopMatrix();
//-------------------------------
```
---

## 📚 Sobre

Esta ferramenta foi criada como apoio ao aprendizado de modelagem 3D manual com OpenGL, permitindo experimentar transformações visuais e gerar os comandos prontos no terminal.

**Disciplina:** Computação Gráfica
**Curso:** Ciência da Computação - UESC
**Autor:** Tiago Alcantara

---

## 📁 Estrutura do projeto

- `usandoFerramenta.c`: Código principal que cria a janela e o objeto 3D.
- `ferramenta.c`: Implementação da ferramenta interativa.
- `README.md`: Documentação do projeto.

---

## © Direitos Autorais

© 2025 Tiago Alcantara. Todos os direitos reservados.

---
