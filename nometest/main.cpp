#include <GL/glut.h>
#include <stdlib.h>

// ============================================================
// CONFIGURACAO GERAL
// ============================================================

// Nome que sera desenhado na tela.
#define NOME "RICARDO"

// ============================================================
// VARIAVEIS DAS TRANSFORMACOES
// ============================================================

// F2 e F3 - Escala
float escala = 0.80f;

// O nome nunca ficara pequeno demais a ponto de desaparecer.
const float ESCALA_MIN = 0.20f;
const float ESCALA_MAX = 3.00f;

// F4 - Translacao
float posX = 0.0f;
float posY = 0.0f;

// F5 - Rotacao
// 0 = eixo X
// 1 = eixo Y
// 2 = eixo Z
float angulo[3] = {0.0f, 0.0f, 0.0f};

// O eixo Z comeca selecionado.
int eixoAtual = 2;

// ============================================================
// TAMANHO DA JANELA E SISTEMA DE COORDENADAS
// ============================================================

int larguraJanela = 800;
int alturaJanela = 600;

float limEsq = -1.0f;
float limDir = 1.0f;
float limBaixo = -1.0f;
float limCima = 1.0f;

// ============================================================
// CONFIGURACAO DOS BOTOES X, Y E Z
// ============================================================

const float BTN_TAM = 0.14f;
const float BTN_ESP = 0.05f;

const char rotulos[3] = {'x', 'y', 'z'};

// ============================================================
// DESENHA UMA LINHA
// ============================================================

void linha(float x1, float y1, float x2, float y2)
{
    glBegin(GL_LINES);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
    glEnd();
}

// ============================================================
// DESENHA O NOME RICARDO
//
// O nome e formado somente por primitivas GL_LINES.
// Assim, atende a F1: desenhar o primeiro nome usando
// primitivas graficas.
// ============================================================

void desenharNome()
{
    // --------------------------------------------------------
    // R
    // --------------------------------------------------------
    linha(-0.85f, -0.2f, -0.85f,  0.2f);
    linha(-0.85f,  0.2f, -0.70f,  0.2f);
    linha(-0.70f,  0.2f, -0.60f,  0.1f);
    linha(-0.60f,  0.1f, -0.70f,  0.0f);
    linha(-0.70f,  0.0f, -0.85f,  0.0f);
    linha(-0.70f,  0.0f, -0.58f, -0.2f);

    // --------------------------------------------------------
    // I
    // --------------------------------------------------------
    linha(-0.48f,  0.2f, -0.28f,  0.2f);
    linha(-0.38f,  0.2f, -0.38f, -0.2f);
    linha(-0.48f, -0.2f, -0.28f, -0.2f);

    // --------------------------------------------------------
    // C
    // --------------------------------------------------------
    linha(-0.05f,  0.2f, -0.15f,  0.2f);
    linha(-0.15f,  0.2f, -0.20f,  0.1f);
    linha(-0.20f,  0.1f, -0.20f, -0.1f);
    linha(-0.20f, -0.1f, -0.15f, -0.2f);
    linha(-0.15f, -0.2f, -0.05f, -0.2f);

    // --------------------------------------------------------
    // A
    // --------------------------------------------------------
    linha(0.02f, -0.2f, 0.12f,  0.2f);
    linha(0.12f,  0.2f, 0.22f, -0.2f);
    linha(0.06f,  0.0f, 0.18f,  0.0f);

    // --------------------------------------------------------
    // R
    // --------------------------------------------------------
    linha(0.32f, -0.2f, 0.32f,  0.2f);
    linha(0.32f,  0.2f, 0.47f,  0.2f);
    linha(0.47f,  0.2f, 0.57f,  0.1f);
    linha(0.57f,  0.1f, 0.47f,  0.0f);
    linha(0.47f,  0.0f, 0.32f,  0.0f);
    linha(0.47f,  0.0f, 0.59f, -0.2f);

    // --------------------------------------------------------
    // D
    // --------------------------------------------------------
    linha(0.68f,  0.2f, 0.80f,  0.2f);
    linha(0.80f,  0.2f, 0.88f,  0.1f);
    linha(0.88f,  0.1f, 0.88f, -0.1f);
    linha(0.88f, -0.1f, 0.80f, -0.2f);
    linha(0.80f, -0.2f, 0.68f, -0.2f);
    linha(0.68f, -0.2f, 0.68f,  0.2f);

    // --------------------------------------------------------
    // O
    // --------------------------------------------------------
    linha(0.98f,  0.2f, 1.12f,  0.2f);
    linha(1.12f,  0.2f, 1.18f,  0.1f);
    linha(1.18f,  0.1f, 1.18f, -0.1f);
    linha(1.18f, -0.1f, 1.12f, -0.2f);
    linha(1.12f, -0.2f, 0.98f, -0.2f);
    linha(0.98f, -0.2f, 0.92f, -0.1f);
    linha(0.92f, -0.1f, 0.92f,  0.1f);
    linha(0.92f,  0.1f, 0.98f,  0.2f);
}

// ============================================================
// DESENHA O NOME COM AS TRANSFORMACOES
//
// F2/F3 -> escala
// F4    -> translacao
// F5    -> rotacao
//
// glPushMatrix/glPopMatrix garantem que as transformacoes
// aplicadas ao nome nao alterem os botoes.
// ============================================================

void desenharNomeTransformado()
{
    glPushMatrix();

    // O centro aproximado do nome e deslocado para a origem.
    // Isso faz a escala e a rotacao acontecerem em torno
    // do centro do nome.
    glTranslatef(-0.165f, 0.0f, 0.0f);

    // F4 - translacao
    glTranslatef(posX, posY, 0.0f);

    // F5 - rotacao no eixo selecionado
    glRotatef(angulo[0], 1.0f, 0.0f, 0.0f); // eixo X
    glRotatef(angulo[1], 0.0f, 1.0f, 0.0f); // eixo Y
    glRotatef(angulo[2], 0.0f, 0.0f, 1.0f); // eixo Z

    // F2 - escala
    glScalef(escala, escala, 1.0f);

    // O nome sera desenhado em uma unica cor.
    // Removemos o efeito arco-iris do codigo original.
    glColor3f(1.0f, 1.0f, 1.0f);

    glLineWidth(3.0f);
    desenharNome();

    glPopMatrix();
}

// ============================================================
// POSICAO DOS BOTOES
// ============================================================

float btnX(int i)
{
    return limEsq + BTN_ESP + i * (BTN_TAM + BTN_ESP);
}

float btnY()
{
    return limBaixo + BTN_ESP;
}

// ============================================================
// DESENHA OS BOTOES X, Y E Z
//
// F5 - O botao selecionado muda a cor de fundo.
// ============================================================

void desenharBotoes()
{
    // Os botoes ficam no canto inferior esquerdo da janela.
    // Eles NAO recebem as transformacoes do nome.
    for (int i = 0; i < 3; i++)
    {
        float x = btnX(i);
        float y = btnY();

        // ----------------------------------------------------
        // FUNDO DO BOTAO
        //
        // O eixo atualmente selecionado fica verde.
        // Os outros dois ficam cinza.
        // ----------------------------------------------------
        if (i == eixoAtual)
            glColor3f(0.2f, 0.8f, 0.2f);
        else
            glColor3f(0.25f, 0.25f, 0.25f);

        glBegin(GL_QUADS);
            glVertex2f(x, y);
            glVertex2f(x + BTN_TAM, y);
            glVertex2f(x + BTN_TAM, y + BTN_TAM);
            glVertex2f(x, y + BTN_TAM);
        glEnd();

        // ----------------------------------------------------
        // BORDA DO BOTAO
        // ----------------------------------------------------
        glColor3f(1.0f, 1.0f, 1.0f);
        glLineWidth(2.0f);

        glBegin(GL_LINE_LOOP);
            glVertex2f(x, y);
            glVertex2f(x + BTN_TAM, y);
            glVertex2f(x + BTN_TAM, y + BTN_TAM);
            glVertex2f(x, y + BTN_TAM);
        glEnd();

        // ----------------------------------------------------
        // LETRA DO BOTAO
        // ----------------------------------------------------
        if (i == eixoAtual)
            glColor3f(0.0f, 0.0f, 0.0f);
        else
            glColor3f(1.0f, 1.0f, 1.0f);

        glRasterPos2f(
            x + BTN_TAM * 0.38f,
            y + BTN_TAM * 0.35f
        );

        glutBitmapCharacter(
            GLUT_BITMAP_HELVETICA_18,
            rotulos[i]
        );
    }
}

// ============================================================
// CONVERTE O CLIQUE DO MOUSE PARA COORDENADAS DO OPENGL
// ============================================================

void selecionarEixoPeloMouse(int px, int py)
{
    // Converte X do mouse (pixels) para coordenada do OpenGL.
    float mx = limEsq +
        ((float)px / (float)larguraJanela) *
        (limDir - limEsq);

    // Converte Y do mouse.
    // No mouse, Y=0 fica no topo da janela.
    // No OpenGL, Y cresce de baixo para cima.
    float my = limCima -
        ((float)py / (float)alturaJanela) *
        (limCima - limBaixo);

    // Verifica os tres botoes.
    for (int i = 0; i < 3; i++)
    {
        float x = btnX(i);
        float y = btnY();

        bool dentroDoBotao =
            mx >= x &&
            mx <= x + BTN_TAM &&
            my >= y &&
            my <= y + BTN_TAM;

        if (dentroDoBotao)
        {
            // Guarda qual eixo foi escolhido.
            eixoAtual = i;

            // Mostra imediatamente a nova cor do botao.
            glutPostRedisplay();

            return;
        }
    }
}


// ============================================================
// FUNCAO DE EXIBICAO
// ============================================================

void display()
{
    // Fundo preto simples.
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Desenha o nome transformado.
    desenharNomeTransformado();

    // Desenha os botoes depois do nome para que fiquem fixos.
    desenharBotoes();

    glutSwapBuffers();
}

// ============================================================
// REDIMENSIONAMENTO DA JANELA
//
// F1 - O nome continua sendo exibido quando a janela muda
// de tamanho.
//
// O glOrtho ajusta o sistema de coordenadas mantendo a
// proporcao do desenho e evitando que o nome fique esticado.
// ============================================================

void redimensiona(int w, int h)
{
    if (h == 0)
        h = 1;

    larguraJanela = w;
    alturaJanela = h;

    glViewport(0, 0, w, h);

    float aspecto = (float)w / (float)h;

    if (aspecto >= 1.0f)
    {
        limEsq = -aspecto;
        limDir =  aspecto;
        limBaixo = -1.0f;
        limCima =  1.0f;
    }
    else
    {
        limEsq = -1.0f;
        limDir =  1.0f;
        limBaixo = -1.0f / aspecto;
        limCima =  1.0f / aspecto;
    }

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(
        limEsq, limDir,
        limBaixo, limCima,
        -10.0, 10.0
    );

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// ============================================================
// TECLADO
//
// F2 - '+' aumenta e '-' diminui a escala.
// F3 - ESCALA_MIN impede que o nome desapareca.
//
// F4 - translacao:
//      A = esquerda
//      D = direita
//      W = cima
//      S = baixo
//
// F5 - rotacao:
//      Q = sentido anti-horario
//      E = sentido horario
// ============================================================

void teclado(unsigned char tecla, int x, int y)
{
    switch (tecla)
    {
        // ----------------------------------------------------
        // F4 - TRANSLACAO
        // ----------------------------------------------------
        case 'a':
        case 'A':
            posX -= 0.05f;
            break;

        case 'd':
        case 'D':
            posX += 0.05f;
            break;

        case 'w':
        case 'W':
            posY += 0.05f;
            break;

        case 's':
        case 'S':
            posY -= 0.05f;
            break;

        // ----------------------------------------------------
        // F2 - ESCALA
        // ----------------------------------------------------
        case '+':
        case '=':
            escala += 0.10f;

            if (escala > ESCALA_MAX)
                escala = ESCALA_MAX;

            break;

        case '-':
        case '_':
            escala -= 0.10f;

            // F3 - impede que o nome desapareca.
            if (escala < ESCALA_MIN)
                escala = ESCALA_MIN;

            break;

        // ----------------------------------------------------
        // F5 - ROTACAO
        //
        // O eixo usado aqui e o ultimo botao selecionado:
        // x -> rotacao em X
        // y -> rotacao em Y
        // z -> rotacao em Z
        // ----------------------------------------------------
        case 'q':
        case 'Q':
            angulo[eixoAtual] += 5.0f;
            break;

        case 'e':
        case 'E':
            angulo[eixoAtual] -= 5.0f;
            break;

        // ESC fecha o programa.
        case 27:
            exit(0);
            break;
    }

    // Solicita uma nova exibicao depois de qualquer tecla.
    glutPostRedisplay();
}

// ============================================================
// MOUSE
//
// Permite selecionar o eixo de rotacao clicando nos botoes.
// ============================================================

void mouse(int botao, int estado, int px, int py)
{
    // Somente o botao esquerdo do mouse seleciona os eixos.
    if (botao == GLUT_LEFT_BUTTON && estado == GLUT_DOWN)
    {
        selecionarEixoPeloMouse(px, py);
    }
}


// ============================================================
// FUNCAO PRINCIPAL
// ============================================================

int main(int argc, char** argv)
{
    // Inicializa o GLUT.
    glutInit(&argc, argv);

    // Janela com dois buffers para uma exibicao mais suave.
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    // Tamanho inicial da janela.
    glutInitWindowSize(800, 600);

    // Titulo da janela.
    glutCreateWindow("Transformacoes Afins - RICARDO");

    // Registra as funcoes usadas pelo GLUT.
    glutDisplayFunc(display);
    glutReshapeFunc(redimensiona);
    glutKeyboardFunc(teclado);
    glutMouseFunc(mouse);

    // Inicia o loop principal do programa.
    glutMainLoop();

    return 0;
}
