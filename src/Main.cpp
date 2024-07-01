#include <iostream>
#include "App.h"
#include "Main.h"

using namespace Application;

int main() {
  App app;
  if(app.init(PROJECT_NAME, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN)) {
    app.run(); 
  }

  while (app.runnable()) {
    app.render();
  }

}
