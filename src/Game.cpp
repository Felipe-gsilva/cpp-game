#include "Game.h"
#include <memory>

using namespace Application;


bool Game::init(){
  if(SDL_Init (SDL_INIT_EVERYTHING) >= 0) {
    window = SDL_CreateWindow(windowSettings.projectName, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowSettings.width, windowSettings.height, windowSettings.flags);

    if (window != 0) {
      renderer = SDL_CreateRenderer(window, -1, 0);
      if(renderer != 0) {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        surface = SDL_LoadBMP("assets/dots.bmp");

        texture = SDL_CreateTextureFromSurface(renderer,surface);

        SDL_FreeSurface(surface);

        SDL_QueryTexture(texture, nullptr, nullptr, &srcRect.w, &srcRect.h);

        destRect.w = 200;
        destRect.h = 200;
        destRect.x = windowSettings.width * 0.5f - (destRect.w * 0.5f);
        destRect.y = windowSettings.height * 0.5f - (destRect.h * 0.5f);

      }
    }
  } else {
    return false;
  }
  return true;
}

void Game::render() {
  SDL_RenderClear(renderer);
  SDL_RenderCopy(renderer, texture, &srcRect, &destRect);
  //SDL_RenderCopy(renderer, texture, 0, 0);
  SDL_RenderPresent(renderer);
}

bool Game::runnable() {
  return Running;
}

void Game::clean() {
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
  exit(1);
}

void Game::setRunnable(bool runnable) {
  Running = runnable;
}
void Game::handleEvents() {
  if(SDL_PollEvent(&event)) {
    switch(event.type) {
      case SDL_QUIT:
        setRunnable(false);
        break;

      defaut:
        break;
    }
  }
}

void Game::update() {}

int main() {
  std::unique_ptr<Game> game = std::make_unique<Game>();

  if(game->init()) {
    game->setRunnable(true);
  }

  while (game->runnable()) {
    game->update();
    game->handleEvents();
    game->render();
  }

  game->clean();
  return 0;
}

