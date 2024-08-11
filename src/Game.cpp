#include "Game.h"
#include "TextureHandler.h"

#include <iostream>
#include <memory>

using namespace Application;
using namespace Texture;

bool Game::init() {
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

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    if(!TextureHandler::Instance()->load("assets/sPlayerAttack.png", "animate", renderer))
      throw new std::exception();

    gameObj.load(100, 100, 32, 32, "animate");
    player.load(200, 200, 32, 32, "animate");

  } catch (std::exception ) {
    std::cout << "error" << std::endl;
    return false;
  }
  return true;
}

void Game::render() {
  SDL_RenderClear(renderer);

//  TextureHandler::Instance()->draw("animate", 0, 0, 32 * 2, 32 * 2, renderer) ;

// TextureHandler::Instance()->drawFrame("animate", windowSettings.width * 0.5f, windowSettings.height * 0.5f, 32, 32, 1, currentFrame, renderer);
  gameObj.draw(renderer);

  player.draw(renderer);

  SDL_RenderPresent(renderer);
}

bool Game::running() {
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
  //  currentFrame =  int(((SDL_GetTicks() / 100) % 6));
  player.update();
  gameObj.update();
}

int main() {
  std::unique_ptr<Game> game = std::make_unique<Game>();

  if(game->init()) {
    game->setRunnable(true);
  }

  while (game->running()) {
    game->update();
    game->handleEvents();
    game->render();

    SDL_Delay(10);
  }

  game->clean();
  return 0;
}

