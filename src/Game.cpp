#include "Game.h"

using namespace Application;
using namespace Texture;


Game* Game::instance = nullptr;

void Game::loadScene() {
  phaseObjects.push_back(new Player(new LoaderParams(ws.width/2 - (SprDefaultSize/2), ws.height/2 - (SprDefaultSize/2), SprDefaultSize, SprDefaultSize, "animate")));

  phaseObjects.push_back(new Enemy(new LoaderParams(ws.width * 0.2f, ws.height * 0.2f, SprDefaultSize, SprDefaultSize, "animate")));

  phaseObjects.push_back(new AmbienceObject(new LoaderParams(50, 50, 32, 32, "fire")));
  phaseObjects.push_back(new Crosshair(new LoaderParams(ws.width/2 - (SprDefaultSize/2), ws.height/2 - (SprDefaultSize/2), SprDefaultSize, SprDefaultSize, "crosshair")));

}


bool Game::init() {
  try {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
      std::cerr << "Error initializing SDL" << std::endl;
      return false;
    }

    window = SDL_CreateWindow(ws.projectName, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, ws.width, ws.height, ws.flags);
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

    TextureHandler::Instance()->loadTextures(renderer);
    
    gsm = new GameStateMachine();
    gsm->changeState(new MenuState());


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
  for (auto& gameObject : phaseObjects) {
    delete gameObject;
  }

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

  if(Event::InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN))
     gsm->changeState(new PlayState());
}

void Game::update() {
  gsm->update();
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
    if(frameTime < Game::Instance()->ws.frameTargetTime) {
      SDL_Delay((int)(Game::Instance()->ws.frameTargetTime - frameTime));
    }
  }

  Game::Instance()->clean();
  return 0;
}

