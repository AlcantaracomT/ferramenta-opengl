# Ferramenta 3D em OpenGL (GLUT) - Versão 2.0

O projeto foi desenvolvido depois que a professora da disciplina de **Computação Gráfica** deu a proposta de construir um **objeto 3D manualmente**, utilizando apenas primitivas do OpenGL.

A partir daí, criei a **versão 1.0**, uma ferramenta interativa para mover, rotacionar e redimensionar um objeto, gerando o código no terminal.

Agora, na **versão 2.0**, a ferramenta foi totalmente reformulada: em vez de apenas exibir o código, ela **injeta o novo objeto diretamente no arquivo-fonte** e **recompila o programa em tempo real**. Com isso, é possível adicionar múltiplos objetos à cena de forma persistente, transformando a ferramenta em um modelador visual simples e poderoso.

## 🧱 Como funciona

A ferramenta opera em três modos: **Posição**, **Escala** e **Rotação**. Você alterna entre os modos e usa as teclas de controle para manipular o objeto. Quando o objeto estiver como desejado, pressione a tecla `P` para salvar.

Ao salvar:

1.  A ferramenta localiza o comentário `//imprimir` no arquivo `usandoFerramenta.c`.
2.  Insere um novo bloco de código `glPushMatrix()` com as transformações (posição, rotação, escala) do objeto atual.
3.  Salva o arquivo, recompila o programa e o reinicia automaticamente com o novo objeto fixado na cena.

Dessa forma, você pode adicionar quantos objetos quiser, um após o outro.

### 📦 Controles:

A ferramenta possui 3 modos de operação para manipular o objeto.

| Tecla | Ação |
| :---: | :--- |
| `c` | Ativa o **Modo Posição** (mover o objeto) |
| `z` | Ativa o **Modo Escala** (redimensionar o objeto) |
| `x` | Ativa o **Modo Rotação** (girar o objeto) |
| `p` | **Salva** o objeto atual no código e reinicia o programa |
| `ESC` | Sai do programa |

-----

#### Controles de Câmera e Zoom

| Ação | Controle |
| :--- | :--- |
| **Girar a câmera** | Mantenha o **botão esquerdo do mouse** pressionado e mova |
| **Zoom geral** | Teclas `+` / `-` |

-----

#### Controles do Objeto (dependem do modo ativo)

| Tecla | Modo Posição | Modo Escala | Modo Rotação |
|:---:|---|---|---|
| `w` | Mover para cima | Aumentar altura (Y) | Girar para cima (eixo X) |
| `s` | Mover para baixo | Diminuir altura (Y) | Girar para baixo (eixo X) |
| `a` | Mover para esquerda | Diminuir profundidade (Z) | Girar para esquerda (eixo Y) |
| `d` | Mover para direita | Aumentar profundidade (Z) | Girar para direita (eixo Y) |
| `e` | Mover para frente | Aumentar largura (X) | Girar sentido horário (eixo Z) |
| `r` | Mover para trás | Diminuir largura (X) | Girar sentido anti-horário (eixo Z) |
| **Setas** | *Sem ação* | *Sem ação* | Gira nos eixos X e Y |

-----

## 🔧 Instalação e Execução

### 1\. Pré-requisitos

O projeto pode ser executado em **Linux**. Você precisará de:

  * Um compilador C (`gcc`)
  * OpenGL e a biblioteca **FreeGLUT** instalados

-----

### 💻 No Linux (testado no Kali/Ubuntu)

#### 1\. Instalar as bibliotecas necessárias:

```bash
sudo apt update
sudo apt install freeglut3-dev build-essential
```

#### 2\. Compilar:

```bash
gcc usandoFerramenta.c -o a -lGL -lGLU -lglut -lm
```

> ⚠️ Certifique-se de que os arquivos `usandoFerramenta.c` e `ferramenta.h` estejam na mesma pasta.

#### 3\. Executar:

```bash
./a
```

-----

### 🪟 No Windows

A funcionalidade de autocompilação (`system("gcc ...")` e `execl(...)`) foi pensada para ambientes Linux. Para usar no Windows, seria necessário adaptar os comandos no código-fonte para o seu compilador (ex: MinGW) e o sistema de arquivos do Windows.

-----

## 💡 Exemplo de Uso

1.  Execute o programa. Um cubo aparecerá no centro.
2.  Pressione `c` para entrar no modo de Posição e use as teclas `W/A/S/D` para movê-lo.
3.  Pressione `z` para entrar no modo de Escala e use `E/R` para deixá-lo mais largo.
4.  Pressione `x` para entrar no modo de Rotação e gire-o com as setas do teclado.
5.  Quando estiver satisfeito, pressione `P`.
6.  O programa irá fechar e reabrir instantaneamente. Agora, o primeiro cubo está salvo e um novo cubo controlável apareceu para você posicionar.

O código em `usandoFerramenta.c` será atualizado automaticamente. A seção de desenho ficará assim:

```c
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
// O NOVO CUBO SALVO APARECERÁ AQUI:
glPushMatrix();
    glTranslatef(1.00f, 0.50f, -5.00f);
    glRotatef(-15.00f, 1.0f, 0.0f, 0.0f);
    glRotatef(20.00f, 0.0f, 1.0f, 0.0f);
    glScalef(1.50f, 1.00f, 1.00f);
    criaCubo(-1.9, 1.9, 9);
glPopMatrix();
        
```

-----
## 📚 Sobre

Esta ferramenta foi criada como apoio ao aprendizado de modelagem 3D manual com OpenGL, permitindo experimentar transformações visuais e gerar os comandos diretamente no código-fonte.

**Disciplina:** Computação Gráfica
**Curso:** Ciência da Computação - UESC
**Autor:** Tiago Alcantara

-----

## 📁 Estrutura do projeto

  * `usandoFerramenta.c`: Código principal que implementa a lógica da janela, controles e a funcionalidade de autocompilação.
  * `ferramenta.h`: Arquivo de cabeçalho com as declarações de funções e variáveis globais.
  * `README.md`: Documentação do projeto.

-----

## © Direitos Autorais

© 2025 Tiago Alcantara. Todos os direitos reservados.

-----
