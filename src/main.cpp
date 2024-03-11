#include "main.hpp"

using namespace app;

int main(int argc, char *argv[]) {
  app::Application app;
  app.createWindow();
  app.render();
  app.closeWindow();
  return 0;
}



