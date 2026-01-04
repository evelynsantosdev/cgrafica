#include <GL/glut.h>
#include <math.h>
#include "scene.h"

#define NUM_TORRES 5
#define RAIO 10.0f // raio das torres ao redor do centro

static void desenhaLosango(float altura)
{
    float h = altura / 2.0f;
    float s = altura / 3.0f;

    float claro[3] = {0.3f, 1.0f, 0.3f};
    float escuro[3] = {0.0f, 0.6f, 0.0f};

    glBegin(GL_TRIANGLES);
    // metade de cima
    glColor3fv(claro);
    glVertex3f(0.0f, h, 0.0f);
    glVertex3f(-s, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, s);

    glColor3fv(escuro);
    glVertex3f(0.0f, h, 0.0f);
    glVertex3f(0.0f, 0.0f, s);
    glVertex3f(s, 0.0f, 0.0f);

    glColor3fv(claro);
    glVertex3f(0.0f, h, 0.0f);
    glVertex3f(s, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, -s);

    glColor3fv(escuro);
    glVertex3f(0.0f, h, 0.0f);
    glVertex3f(0.0f, 0.0f, -s);
    glVertex3f(-s, 0.0f, 0.0f);

    // metade de baixo
    glColor3fv(claro);
    glVertex3f(0.0f, -h, 0.0f);
    glVertex3f(0.0f, 0.0f, s);
    glVertex3f(-s, 0.0f, 0.0f);

    glColor3fv(escuro);
    glVertex3f(0.0f, -h, 0.0f);
    glVertex3f(s, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, s);

    glColor3fv(claro);
    glVertex3f(0.0f, -h, 0.0f);
    glVertex3f(0.0f, 0.0f, -s);
    glVertex3f(s, 0.0f, 0.0f);

    glColor3fv(escuro);
    glVertex3f(0.0f, -h, 0.0f);
    glVertex3f(-s, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, -s);
    glEnd();
}

void desenhaChao()
{
    glColor3f(0.2f, 0.2f, 0.2f);
    glBegin(GL_QUADS);
    glVertex3f(-80.0f, 0.0f, -80.0f);
    glVertex3f(80.0f, 0.0f, -80.0f);
    glVertex3f(80.0f, 0.0f, 80.0f);
    glVertex3f(-80.0f, 0.0f, 80.0f);
    glEnd();
}

void desenhaTorresELosangos()
{
    float alturaTorre = 2.5f;
    float w = 0.7f;

    float ang0 = -M_PI / 2.0f;
    float passo = 2.0f * M_PI / NUM_TORRES;

    for (int i = 0; i < NUM_TORRES; i++)
    {
        float ang = ang0 + passo * i;
        float x = RAIO * cosf(ang);
        float z = RAIO * sinf(ang);

        glPushMatrix();
        glTranslatef(x, 0.0f, z);

        // Torre roxa
        glPushMatrix();
        glColor3f(0.6f, 0.0f, 0.8f);
        glTranslatef(0.0f, alturaTorre / 2.0f, 0.0f);
        glScalef(w, alturaTorre, w);
        glutSolidCube(1.0f);
        glPopMatrix();

        // Losango verde girando em cima 
        glPushMatrix();
        glTranslatef(0.0f, alturaTorre + 1.2f, 0.0f);
        glRotatef(anguloPiramide, 0.0f, 1.0f, 0.0f);
        desenhaLosango(1.5f);
        glPopMatrix();

        glPopMatrix();
    }
}

void desenhaPiramideDegraus()
{
    float alturaDegrau = 0.5f;
    float tamanhoBase = 6.0f;
    float reducao = 0.65f;

    glPushMatrix();

    float roxo1[3] = {0.55f, 0.00f, 0.75f};
    float roxo2[3] = {0.65f, 0.10f, 0.85f};
    float roxo3[3] = {0.75f, 0.20f, 0.95f};

    // Degrau 1
    glColor3f(roxo1[0], roxo1[1], roxo1[2]);
    glPushMatrix();
    glTranslatef(0.0f, alturaDegrau / 2.0f, 0.0f);
    glScalef(tamanhoBase, alturaDegrau, tamanhoBase);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Degrau 2
    glColor3f(roxo2[0], roxo2[1], roxo2[2]);
    glPushMatrix();
    glTranslatef(0.0f, alturaDegrau + alturaDegrau / 2.0f, 0.0f);
    glScalef(tamanhoBase * reducao, alturaDegrau, tamanhoBase * reducao);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Degrau 3
    glColor3f(roxo3[0], roxo3[1], roxo3[2]);
    glPushMatrix();
    glTranslatef(0.0f, 2 * alturaDegrau + alturaDegrau / 2.0f, 0.0f);
    glScalef(tamanhoBase * reducao * reducao,
             alturaDegrau,
             tamanhoBase * reducao * reducao);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Esfera flutuando acima
    float topoDegrausY = 5.0f * alturaDegrau;
    float raioEsfera = 3.0f;

    glPushMatrix();
    glTranslatef(0.0f, topoDegrausY + raioEsfera + 0.2f, 0.0f);

    glRotatef(anguloEsfera, 1.0f, 1.5f, 0.0f);

    double eq[4];

    // metade de cima
    glColor3f(0.40f, 0.00f, 0.00f);
    eq[0] = 0;
    eq[1] = -1;
    eq[2] = 0;
    eq[3] = 0;
    glClipPlane(GL_CLIP_PLANE0, eq);
    glEnable(GL_CLIP_PLANE0);
    glutSolidSphere(raioEsfera, 40, 40);
    glDisable(GL_CLIP_PLANE0);

    // metade de baixo
    glColor3f(0.80f, 0.00f, 0.00f);
    eq[0] = 0;
    eq[1] = 1;
    eq[2] = 0;
    eq[3] = 0;
    glClipPlane(GL_CLIP_PLANE1, eq);
    glEnable(GL_CLIP_PLANE1);
    glutSolidSphere(raioEsfera, 40, 40);
    glDisable(GL_CLIP_PLANE1);

    glPopMatrix();

    glPopMatrix();
}

void desenhaRodaComRaios(float raio, float espessura, int numRaios)
{
    // Desenha o pneu (torus)
    glColor3f(0.1f, 0.1f, 0.1f);
    glutSolidTorus(espessura, raio, 12, 20);
    
    // Desenha disco de fundo (prato)
    glColor3f(0.2f, 0.2f, 0.2f);
    GLUquadric* quad = gluNewQuadric();
    gluDisk(quad, 0.0f, raio - espessura, 30, 1);
    
    // Desenha os raios principais (mais grossos)
    glLineWidth(3.0f);
    glColor3f(0.8f, 0.8f, 0.8f);
    glBegin(GL_LINES);
    for (int i = 0; i < numRaios; i++)
    {
        float angulo = (2.0f * M_PI * i) / numRaios;
        float x = (raio - espessura) * cosf(angulo);
        float y = (raio - espessura) * sinf(angulo);
        
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(x, y, 0.0f);
    }
    glEnd();
    
    // Desenha raios secundários (mais finos)
    glLineWidth(1.5f);
    glColor3f(0.6f, 0.6f, 0.6f);
    glBegin(GL_LINES);
    for (int i = 0; i < numRaios * 2; i++)
    {
        float angulo = (2.0f * M_PI * i) / (numRaios * 2);
        float x = (raio - espessura) * 0.7f * cosf(angulo);
        float y = (raio - espessura) * 0.7f * sinf(angulo);
        
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(x, y, 0.0f);
    }
    glEnd();
    glLineWidth(1.0f);
    
    // Cubo central (eixo)
    glPushMatrix();
    glColor3f(0.3f, 0.3f, 0.3f);
    glScalef(0.15f, 0.15f, 0.15f);
    glutSolidCube(1.0f);
    glPopMatrix();
    
    gluDeleteQuadric(quad);
}

void desenhaBicicleta()
{
    

    
    glPushMatrix();
    glTranslatef(9.0f, 0.0f, -2.48f);
    glRotatef(0.0f, 0.0f, 1.0f, 0.0f);
    
    float raioRoda = 0.4f;
    float espessuraRoda = 0.08f;
    float alturaSelim = 0.87f;
    
    // Cor cinza escuro para o quadro
    glColor3f(0.3f, 0.3f, 0.3f);
    
    // Roda traseira
    glPushMatrix();
    glTranslatef(-1.0f, raioRoda, 0.0f);
    glRotatef(0.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(anguloRodas, 0.0f, 0.0f, 1.0f);
    desenhaRodaComRaios(raioRoda, espessuraRoda, 12);
    // glColor3f(0.1f, 0.1f, 0.1f);
    // glutSolidTorus(espessuraRoda, raioRoda, 12, 20);
    glPopMatrix();
    
    // Roda dianteira
    glPushMatrix();
    glTranslatef(1.0f, raioRoda, 0.0f);
    glRotatef(0.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(anguloRodas, 0.0f, 0.0f, 1.0f);
    desenhaRodaComRaios(raioRoda, espessuraRoda, 12);
    glPopMatrix();
    
    // Quadro - barra horizontal baixa
    glPushMatrix();
    glTranslatef(0.0f, raioRoda + 0.1f, 0.0f);
    glScalef(1.2f, 0.04f, 0.04f);
    glColor3f(0.227f, 0.89f, 0.89f); 
    glutSolidCube(1.0f);
    glPopMatrix();
    
    // Quadro - barra diagonal traseira
    glPushMatrix();
    glTranslatef(-0.3f, raioRoda + 0.3f, 0.0f);
    glRotatef(60.0f, 0.0f, 0.0f, 1.0f);
    glScalef(0.04f, 0.6f, 0.04f);
    glColor3f(0.227f, 0.89f, 0.89f); 
    glutSolidCube(1.0f);
    glPopMatrix();
    
    // Selim (banco)
    glPushMatrix();
    glTranslatef(-0.5f, alturaSelim, 0.0f);
    glScalef(0.30f, 0.05f, 0.1f);
    glColor3f(0.1f, 0.1f, 0.1f);
    glutSolidCube(1.0f);
    glPopMatrix();
    
    // Guidão - tubo vertical
    glPushMatrix();
    glTranslatef(0.5f, raioRoda + 0.38f, 0.0f);
    glScalef(0.03f, 0.6f, 0.03f);
    glColor3f(0.227f, 0.89f, 0.89f);
    glutSolidCube(1.0f);
    glPopMatrix();
    
    // Guidão - barra horizontal
    glPushMatrix();
    glTranslatef(0.5f, raioRoda + 0.67f, 0.0f);
    glScalef(0.06f, 0.06f, 0.6f);
    glColor3f(0.227f, 0.89f, 0.89f);
    glutSolidCube(1.0f);
    glPopMatrix();
    
    glPopMatrix();
}