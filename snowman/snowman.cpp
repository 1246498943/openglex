#include "gltools.h"
#include "math3d.h"
#include <stdio.h>

void SetupRC()
{
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  
  //������ȼ�⣬����������
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE);
  glCullFace(GL_BACK);
  glFrontFace(GL_CCW);

  //��������
  GLfloat whiteLight[] = {0.05f, 0.05f, 0.05f, 1.0f};
  GLfloat sourceLight[] = {0.25f, 0.25f, 0.25f, 1.0f};
  GLfloat lightPos[] = {-10.0f, 5.0f, 5.0f, 1.0f};

  glEnable(GL_LIGHTING);
  glLightModelfv(GL_LIGHT_MODEL_AMBIENT, whiteLight);
  glLightfv(GL_LIGHT0, GL_AMBIENT_AND_DIFFUSE, sourceLight);
  glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
  glEnable(GL_LIGHT0);

  //������ɫ׷��
  glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
  glEnable(GL_COLOR_MATERIAL);

}

void ChangeSize(GLsizei w, GLsizei h)
{
  if (h == 0)
    h = 1;

  glViewport(0, 0, w, h);
  GLfloat aspect = (GLfloat)w/(GLfloat)h;

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  gluPerspective(35.0, aspect, 1.0, 40.0);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void RenderScene()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  GLUquadricObj *quadricObj = gluNewQuadric();
  gluQuadricNormals(quadricObj, GLU_SMOOTH);

  glTranslatef(0.0f, -.5f, -4.0f);
  glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    gluSphere(quadricObj, .65f, 26, 13);

    glTranslatef(0.0f, 0.85f, 0.0f);
    gluSphere(quadricObj, 0.42f, 26, 13);

    glTranslatef(0.0f, 0.63f, 0.0f);
    gluSphere(quadricObj, 0.36f, 26, 13);

    glTranslatef(-0.05f, 0.1f, 0.2f);
    glColor3f(1.0f, 0.0f, 0.0f);
    gluSphere(quadricObj, 0.15f, 26, 13);
    
  glPopMatrix();
  glutSwapBuffers();
}

void SpecialKey(int value)
{
  if (value == GLUT_KEY_DOWN)
  {

  }
}
int main(int args, char **argv)
{
  glutInit(&args, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
  glutInitWindowSize(800, 600);
  glutCreateWindow("snowman");

  glutDisplayFunc(RenderScene);
  glutReshapeFunc(ChangeSize);
  SetupRC();
  glutMainLoop();
  return 0;
}
