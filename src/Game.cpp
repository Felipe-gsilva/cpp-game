#include "Game.h"
#include "util/TextureHandler.h"


#include <iostream>
#include <memory>

using namespace Application;
using namespace Texture;


Game* Game::instance = 0;

void Game::loadScene() {
  gameObjects.push_back(new Player(new LoaderParams(100, 100, 32, 32, "animate")));
  gameObjects.push_back(new Enemy(new LoaderParams(200, 200, 32, 32, "animate")));
}
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

    loadScene();

  } catch (std::exception ) {
    std::cout << "error" << std::endl;
    return false;
  }
  return true;
}

void Game::render() {
  SDL_RenderClear(renderer);

  for(std::vector<GameObject*>::size_type i = 0; i < gameObjects.size(); i++){
    gameObjects[i]->draw();
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

  if(Game::Instance()->init()) {
    Game::Instance()->setRunnable(true);
  }

  while (Game::Instance()->running()) {
    Game::Instance()->update();
    Game::Instance()->handleEvents();
    Game::Instance()->render();

    SDL_Delay(10);
  }

  Game::Instance()->clean();
  return 0;
}

