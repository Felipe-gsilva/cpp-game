#include "Game.h"

using namespace Application;


bool Game::init(){
  try {
    if (SDL_Init (SDL_INIT_EVERYTHING) < 0)  {
      std::cerr << "error while initializing SDL" << std::endl;
    }

    window = SDL_CreateWindow(windowSettings.projectName, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowSettings.width, windowSettings.height, windowSettings.flags);

    if (window == 0) 
      std::cerr << "error while creating renderer" << std::endl;

    renderer = SDL_CreateRenderer(window, -1, 0);
    if(renderer == 0) 
      std::cerr << "error while creating window" << std::endl;

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
   
    textureManager.load("assets/sPlayerAttack.png", "animate", renderer);

  } catch (std::exception ) {
    std::cout << "error" << std::endl;
    return false;
  }
  return true;
}

void Game::render() {
  SDL_RenderClear(renderer);

  textureManager.draw("animate", 0, 0, 32, 32, renderer);

  textureManager.drawFrame("animate", 100, 100, 32, 32, 1, currentFrame, renderer);

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

void Game::update() {
  currentFrame = SprDefaultSize * int(((SDL_GetTicks() / 100) % 6));
}

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

