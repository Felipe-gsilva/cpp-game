#include <iostream>
#include "App.h"

using namespace Application;

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
}

void App::run() {
  App::isRunning = true;
}

bool App::runnable() {
  return isRunning;
}

