#include "Game.h"

using namespace Application;
using namespace Texture;
using namespace States;

Game* Game::instance = nullptr;

bool Game::init() {
  try {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) 
      throw new std::runtime_error("Error initializing SDL");


    window = SDL_CreateWindow(ws.projectName, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, ws.width, ws.height, ws.flags);
    if (window == nullptr) 
      throw new std::runtime_error("Error creating window");


    renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer == nullptr) 
      throw new std::runtime_error("Error creating renderer");

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    TextureHandler::Instance()->loadTextures(renderer);

    gsm = new GameStateMachine();

    menu = new MenuState();
    gsm->pushState(menu);

    play = new PlayState();
    gsm->pushState(play);

    gsm->changeState(menu);
    std::cout << "menu";


  } catch (const std::exception& e) {
    std::cerr << "Exception: " << e.what() << std::endl;
    return false;
  }

  return true;
}

void Game::render() {
  SDL_RenderClear(renderer);

  gsm->render(); 

  SDL_RenderPresent(renderer);
}

bool Game::running() const {
  return Running;
}

void Game::clean() {
  gsm->popState(menu);

  delete menu;
  delete gsm;
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
  gsm->update();
}

int main() {
  u32 frameStart, frameTime;

  if(Game::Instance()->init()) 
    Game::Instance()->setRunnable(true);

  while (Game::Instance()->running()) {
    frameStart = SDL_GetTicks();

    Game::Instance()->handleEvents();
    Game::Instance()->update();
    Game::Instance()->render();

    frameTime = SDL_GetTicks() - frameStart;
    std::string title;
    title = std::to_string(frameTime);
    SDL_SetWindowTitle(Game::Instance()->getWindow(), title.c_str());

    if(frameTime < Game::Instance()->ws.frameTargetTime) {
      SDL_Delay((int)(Game::Instance()->ws.frameTargetTime - frameTime));
    }
  }

  Game::Instance()->clean();
  return 0;
}

