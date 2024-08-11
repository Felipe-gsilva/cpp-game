#include "Game.h"
#include "TextureHandler.h"

#include "Player.h"
#include "Enemy.h"

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

    player = new Player();
    player->load(windowSettings.width * 0.5f- (SprDefaultSize * 0.5f), windowSettings.height* 0.5f - (SprDefaultSize * 0.5f), SprDefaultSize, SprDefaultSize, "animate");

    enemy1 = new Enemy();
    enemy1->load(200, 200, 32, 32, "animate");

    gameObjects.push_back(player);
    gameObjects.push_back(enemy1);

  } catch (std::exception ) {
    std::cout << "error" << std::endl;
    return false;
  }
  return true;
}

void Game::render() {
  SDL_RenderClear(renderer);

  for(std::vector<GameObject*>::size_type i = 0; i < gameObjects.size(); i++){
    gameObjects[i]->draw(renderer);
  } 

  SDL_RenderPresent(renderer);
}

bool Game::running() {
  return Running;
}

void Game::clean() {
  for(std::vector<GameObject*>::size_type i = 0; i !=gameObjects.size(); i++){

  } 
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
  //

  for(std::vector<GameObject*>::size_type i = 0; i !=gameObjects.size(); i++){
    gameObjects[i]->update();
  } 
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

