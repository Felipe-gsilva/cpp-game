#include "util/InputHandler.h"
#include "Game.h"

using namespace Event;

InputHandler* InputHandler::instance = 0;

void InputHandler::update() {
  SDL_Event event;
  while(SDL_PollEvent(&event)) {
    if(event.type == SDL_QUIT) {
      Application::Game::Instance()->clean();
    }
    if(event.type == SDL_MOUSEMOTION) {
      mousePosition->setX(event.motion.x);
      mousePosition->setY(event.motion.y);
    }
    if(event.type == SDL_MOUSEBUTTONDOWN){
      if(event.button.button == SDL_BUTTON_LEFT) {
        mouseButtonState[LEFT] = true;
        std::cout << "mouse left";
      }
      if(event.button.button == SDL_BUTTON_MIDDLE) {
        mouseButtonState[MIDDLE] = true;
      }
      if(event.button.button == SDL_BUTTON_RIGHT) {
        mouseButtonState[RIGHT] = true;
      }
    }
    if(event.type == SDL_MOUSEBUTTONUP) {
      if(event.button.button == SDL_BUTTON_LEFT) {
        mouseButtonState[LEFT] = false;
      }
      if(event.button.button == SDL_BUTTON_MIDDLE) {
        mouseButtonState[MIDDLE] = false;
      }
      if(event.button.button == SDL_BUTTON_RIGHT) {
        mouseButtonState[RIGHT] = false;
      }
    }

  }
}

bool InputHandler::getMouseState(int mouseNumber) {
  return mouseButtonState[mouseNumber];
}
