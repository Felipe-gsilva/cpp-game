#include "Game.h"
#include "util/TextureHandler.h"
#include "util/InputHandler.h"


#include <iostream>
#include <memory>

using namespace Application;
using namespace Texture;


Game* Game::instance = nullptr;

void Game::loadScene() {
  gameObjects.push_back(new Player(new LoaderParams(100, 100, 32, 32, "animate")));
  gameObjects.push_back(new Enemy(new LoaderParams(200, 200, 32, 32, "animate")));
  gameObjects.push_back(new AmbienceObject(new LoaderParams(50, 50, 32, 32, "fire")));
}


bool Game::init() {
  try {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
      std::cerr << "Error initializing SDL" << std::endl;
      return false;
    }

    window = SDL_CreateWindow(windowSettings.projectName, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowSettings.width, windowSettings.height, windowSettings.flags);
    if (window == nullptr) {
      std::cerr << "Error creating window" << std::endl;
      return false;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer == nullptr) {
      std::cerr << "Error creating renderer" << std::endl;
      return false;
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    if (!TextureHandler::Instance()->load("assets/sPlayerAttack.png", "animate", renderer)) {
      throw std::runtime_error("Error loading texture");
    }

    if (!TextureHandler::Instance()->load("assets/fire.png", "fire", renderer)) {
      throw std::runtime_error("Error loading texture");
    }

    loadScene();

  } catch (const std::exception& e) {
    std::cerr << "Exception: " << e.what() << std::endl;
    return false;
  }

  return true;
}

void Game::render() {
  SDL_RenderClear(renderer);

  for(auto& gameObject : gameObjects){
    gameObject->draw();
  } 

  SDL_RenderPresent(renderer);
}

bool Game::running() const {
  return Running;
}

void Game::clean() {
  for (auto& gameObject : gameObjects) {
    delete gameObject;
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
  Event::InputHandler::Instance()->update(); 
}

void Game::update() {
  for(auto& gameObject : gameObjects){
    gameObject->update();
  } 
}

int main() {
  u32 frameStart, frameTime;

  if(Game::Instance()->init()) {
    Game::Instance()->setRunnable(true);
  }

  while (Game::Instance()->running()) {
    frameStart = SDL_GetTicks();

    Game::Instance()->handleEvents();
    Game::Instance()->update();
    Game::Instance()->render();


    frameTime = SDL_GetTicks() - frameStart;
    if(frameTime < Game::Instance()->windowSettings.frameTargetTime) {
      SDL_Delay((int)(Game::Instance()->windowSettings.frameTargetTime - frameTime));
    }
  }

  Game::Instance()->clean();
  return 0;
}

