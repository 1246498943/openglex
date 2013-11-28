#include "gltools.h"
//����λͼ
GLubyte fire[128] = { 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0xc0,
0x00, 0x00, 0x01, 0xf0,
0x00, 0x00, 0x07, 0xf0,
0x0f, 0x00, 0x1f, 0xe0,
0x1f, 0x80, 0x1f, 0xc0,
0x0f, 0xc0, 0x3f, 0x80,	
0x07, 0xe0, 0x7e, 0x00,
0x03, 0xf0, 0xff, 0x80,
0x03, 0xf5, 0xff, 0xe0,
0x07, 0xfd, 0xff, 0xf8,
0x1f, 0xfc, 0xff, 0xe8,
0xff, 0xe3, 0xbf, 0x70, 
0xde, 0x80, 0xb7, 0x00,
0x71, 0x10, 0x4a, 0x80,
0x03, 0x10, 0x4e, 0x40,
0x02, 0x88, 0x8c, 0x20,
0x05, 0x05, 0x04, 0x40,
0x02, 0x82, 0x14, 0x40,
0x02, 0x40, 0x10, 0x80, 
0x02, 0x64, 0x1a, 0x80,
0x00, 0x92, 0x29, 0x00,
0x00, 0xb0, 0x48, 0x00,
0x00, 0xc8, 0x90, 0x00,
0x00, 0x85, 0x10, 0x00,
0x00, 0x03, 0x00, 0x00,
0x00, 0x00, 0x10, 0x00 };

void RenderScene()
{

  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0.0f, 0.0f, 0.0f);

  for (int y = 0; y < 16; ++y)
  {
    //���ù�դ����λ��
    glRasterPos2i(0, 32 * y);
    for (int x = 0; x < 16; ++x)
    {
      //����λͼ��������ɺ���x�����ƶ�32������
      glBitmap(32, 32, 0.0f, 0.0f, 32.0f, 0.0f, fire);
    }
  }

  glutSwapBuffers();
}

void ChangeSize(int w, int h)
{
  if (h == 0)
    h = 1;

  glViewport(0, 0, (GLsizei)w, (GLsizei)h);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  //����ͶӰ�Ĵ�С����Ļ�Ŀ��߶�Ӧ
  gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void SetupRC()
{
  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

int main(int args, char *argv[])
{
  glutInit(&args, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
  //����512X512�Ĵ���
  glutInitWindowSize(512, 512);

  glutCreateWindow("BITMPAS");
  glutDisplayFunc(RenderScene);
  glutReshapeFunc(ChangeSize);
  SetupRC();
  glutMainLoop();

  return 0;
}