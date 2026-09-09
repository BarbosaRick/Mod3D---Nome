#include <GL/glut.h>

// =====================================================
// CONTROLES DE TAMANHO
// =====================================================

// Tamanho geral
float escala = 0.50f;

// Largura
float escalaX = 0.50f;

// Altura
float escalaY = 0.50f;


// =====================================================
// CONTROLES DE POSIÇÃO
// =====================================================

// Posição horizontal
float posX = 0.0f;

// Posição vertical
float posY = 0.0f;


// =====================================================
// CONTROLE DE ROTAÇÃO
// =====================================================

// Ângulo de rotação
float angulo = 0.0f;


// =====================================================
// DESENHAR RICARDO
// =====================================================

void DesenharLetrasComLineStrip()
{
    glColor3f(0.0f, 1.0f, 0.0f);
    glLineWidth(3.0f);

    // Salva a matriz atual
    glPushMatrix();


    // =================================================
    // TRANSLACAO
    // =================================================

    glTranslatef(posX, posY, 0.0f);


    // =================================================
    // ROTACAO
    // =================================================

    glRotatef(
        angulo,
        0.0f,
        0.0f,
        1.0f
    );


    // =================================================
    // ESCALA
    // =================================================

    glScalef(
        escala * escalaX,
        escala * escalaY,
        1.0f
    );


    // =================================================
    // R
    // =================================================

    glBegin(GL_LINE_STRIP);

    glVertex2f(-0.85f, -0.2f);
    glVertex2f(-0.85f,  0.2f);
    glVertex2f(-0.70f,  0.2f);
    glVertex2f(-0.60f,  0.1f);
    glVertex2f(-0.70f,  0.0f);
    glVertex2f(-0.85f,  0.0f);

    glEnd();

    glBegin(GL_LINE_STRIP);

    glVertex2f(-0.70f, 0.0f);
    glVertex2f(-0.58f, -0.2f);

    glEnd();


    // =================================================
    // I
    // =================================================

    glBegin(GL_LINE_STRIP);

    glVertex2f(-0.48f, 0.2f);
    glVertex2f(-0.28f, 0.2f);

    glEnd();

    glBegin(GL_LINE_STRIP);

    glVertex2f(-0.38f, 0.2f);
    glVertex2f(-0.38f, -0.2f);

    glEnd();

    glBegin(GL_LINE_STRIP);

    glVertex2f(-0.48f, -0.2f);
    glVertex2f(-0.28f, -0.2f);

    glEnd();


    // =================================================
    // C
    // =================================================

    glBegin(GL_LINE_STRIP);

    glVertex2f(-0.05f,  0.2f);
    glVertex2f(-0.15f,  0.2f);
    glVertex2f(-0.20f,  0.1f);
    glVertex2f(-0.20f, -0.1f);
    glVertex2f(-0.15f, -0.2f);
    glVertex2f(-0.05f, -0.2f);

    glEnd();


    // =================================================
    // A
    // =================================================

    glBegin(GL_LINE_STRIP);

    glVertex2f(0.02f, -0.2f);
    glVertex2f(0.12f,  0.2f);
    glVertex2f(0.22f, -0.2f);

    glEnd();

    glBegin(GL_LINE_STRIP);

    glVertex2f(0.06f, 0.0f);
    glVertex2f(0.18f, 0.0f);

    glEnd();


    // =================================================
    // R
    // =================================================

    glBegin(GL_LINE_STRIP);

    glVertex2f(0.32f, -0.2f);
    glVertex2f(0.32f,  0.2f);
    glVertex2f(0.47f,  0.2f);
    glVertex2f(0.57f,  0.1f);
    glVertex2f(0.47f,  0.0f);
    glVertex2f(0.32f,  0.0f);

    glEnd();

    glBegin(GL_LINE_STRIP);

    glVertex2f(0.47f, 0.0f);
    glVertex2f(0.59f, -0.2f);

    glEnd();


    // =================================================
    // D
    // =================================================

    glBegin(GL_LINE_STRIP);

    glVertex2f(0.68f,  0.2f);
    glVertex2f(0.80f,  0.2f);
    glVertex2f(0.88f,  0.1f);
    glVertex2f(0.88f, -0.1f);
    glVertex2f(0.80f, -0.2f);
    glVertex2f(0.68f, -0.2f);
    glVertex2f(0.68f,  0.2f);

    glEnd();


    // =================================================
    // O
    // =================================================

    glBegin(GL_LINE_STRIP);

    glVertex2f(0.98f,  0.2f);
    glVertex2f(1.12f,  0.2f);
    glVertex2f(1.18f,  0.1f);
    glVertex2f(1.18f, -0.1f);
    glVertex2f(1.12f, -0.2f);
    glVertex2f(0.98f, -0.2f);
    glVertex2f(0.92f, -0.1f);
    glVertex2f(0.92f,  0.1f);
    glVertex2f(0.98f,  0.2f);

    glEnd();


    // Recupera a matriz anterior
    glPopMatrix();
}


// =====================================================
// DISPLAY
// =====================================================

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    DesenharLetrasComLineStrip();

    glFlush();
}


// =====================================================
// TECLADO
// =====================================================

void teclado(unsigned char tecla, int x, int y)
{
    switch (tecla)
    {
        // =============================================
        // W = SOBE
        // =============================================

        case 'w':
        case 'W':
            posY += 0.05f;
            break;


        // =============================================
        // S = DESCE
        // =============================================

        case 's':
        case 'S':
            posY -= 0.05f;
            break;


        // =============================================
        // A = ESQUERDA
        // =============================================

        case 'a':
        case 'A':
            posX -= 0.05f;
            break;


        // =============================================
        // D = DIREITA
        // =============================================

        case 'd':
        case 'D':
            posX += 0.05f;
            break;


        // =============================================
        // V = ROTA PARA A DIREITA
        // =============================================

        case 'v':
        case 'V':
            angulo -= 5.0f;
            break;


        // =============================================
        // C = ROTA PARA A ESQUERDA
        // =============================================

        case 'c':
        case 'C':
            angulo += 5.0f;
            break;


        // =============================================
        // + = AUMENTA TAMANHO GERAL
        // =============================================

        case '+':
            escala += 0.1f;
            break;


        // =============================================
        // - = DIMINUI TAMANHO GERAL
        // =============================================

        case '-':
            escala -= 0.1f;

            if (escala < 0.1f)
                escala = 0.1f;

            break;


        // =============================================
        // * = AUMENTA ALTURA
        // =============================================

        case '*':
            escalaY += 0.1f;
            break;


        // =============================================
        // / = DIMINUI ALTURA
        // =============================================

        case '/':
            escalaY -= 0.1f;

            if (escalaY < 0.1f)
                escalaY = 0.1f;

            break;


        // =============================================
        // ESC = FECHAR
        // =============================================

        case 27:
            exit(0);
            break;
    }

    glutPostRedisplay();
}


// =====================================================
// TECLAS ESPECIAIS
// =====================================================

void tecladoEspecial(int tecla, int x, int y)
{
    switch (tecla)
    {
        // =============================================
        // SETA DIREITA = AUMENTA LARGURA
        // =============================================

        case GLUT_KEY_RIGHT:
            escalaX += 0.1f;
            break;


        // =============================================
        // SETA ESQUERDA = DIMINUI LARGURA
        // =============================================

        case GLUT_KEY_LEFT:
            escalaX -= 0.1f;

            if (escalaX < 0.1f)
                escalaX = 0.1f;

            break;


        // =============================================
        // SETA CIMA = AUMENTA ALTURA
        // =============================================

        case GLUT_KEY_UP:
            escalaY += 0.1f;
            break;


        // =============================================
        // SETA BAIXO = DIMINUI ALTURA
        // =============================================

        case GLUT_KEY_DOWN:
            escalaY -= 0.1f;

            if (escalaY < 0.1f)
                escalaY = 0.1f;

            break;
    }

    glutPostRedisplay();
}


// =====================================================
// MAIN
// =====================================================

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(800, 600);

    glutCreateWindow("Nome com GL_LINE_STRIP - Ricardo");

    glClearColor(
        0.0f,
        0.0f,
        0.0f,
        1.0f
    );

    glutDisplayFunc(display);

    // Teclas W, A, S, D, V, C, +, -, *, /
    glutKeyboardFunc(teclado);

    // Setas
    glutSpecialFunc(tecladoEspecial);

    glutMainLoop();

    return 0;
}

