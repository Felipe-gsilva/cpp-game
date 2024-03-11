#include <iostream>
#include <string>
#include "GLFW/glfw3.h"


namespace app{
class Application{
public:
  int createWindow(){
    return 0;
  } 
  int render()
  {
    return 0;
  }

private:
};
}

int main(int argc, char *argv[]) {
  app::Application app;
  app.createWindow();
  
  return 0;
}



