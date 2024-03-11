#include <iostream>
#include "GLFW/glfw3.h"
#include <GL/freeglut.h>

namespace app{
class Application{
public:
  int createWindow(){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH); 

    glutInitWindowSize(1024, 768);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Tutorial 01");

    glutDisplayFunc(RenderSceneCB);

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    glutMainLoop();

    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
    return 0;
  } 
  int render()
  {
    return 0;
  }

private:
  int argc;
  char *argv[];
  
};
}

int main(int argc, char *argv[]) {
  app::Application app;
  app.createWindow();

  return 0;
}



