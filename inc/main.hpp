#include <iostream>
#include "GLFW/glfw3.h"

namespace app{
class Application{
public:

  int createWindow(){
    if(!glfwInit())
      return -1;

    window = glfwCreateWindow(width, height, "Title", nullptr, nullptr);

    if(!window){
      glfwTerminate();
      return -1;
    }

    return 0;
  } 

  int render()
  {
    while(!glfwWindowShouldClose(window)){ 
      glColor3d(1.0, 0.0,0.0);
      glBegin(GL_TRIANGLES);
      glVertex2d(-1,1);
      glVertex2d(1,1);
      glVertex2d(0,1);
      glEnd();
    }
    return 0;
  }
  int closeWindow()
  {
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
  }
private:
  GLFWwindow *window;  
  int width = 800, height = 600;
  std::string name;
};
}
