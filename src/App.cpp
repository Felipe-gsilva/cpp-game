#include "App.h"

using namespace Application;


Application::App *app;

bool App::init(const char* title, int x, int y, int width, int height ,int flags){
  if(SDL_Init (SDL_INIT_EVERYTHING) >= 0) {
    window = SDL_CreateWindow(title, x, y, width, height, flags);

    if (window != 0) {
      renderer = SDL_CreateRenderer(window, -1, 0);
    }
  } else {
    return 1;
  }
  return true;
}

void App::render() {
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);
  SDL_RenderPresent(renderer);
  SDL_Delay(5000);
  SDL_Quit();
  setRunnable(false);  
}

bool App::runnable() {
  return isRunning;
}

void App::clean() {
  exit(1);
}

void App::setRunnable(bool runnable) {
  isRunning = runnable;
}

int main() {
  app = new App();

  if(app->init(PROJECT_NAME, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN)) {
    app->setRunnable(true);
  }

  while (app->runnable()) {
    app->updateHandler.update();
    app->eventHandler.handleEvents();
    app->render();
  }

  app->clean();
}

