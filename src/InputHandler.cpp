#include "InputHandler.h"
#include "Game.h"

using namespace Event;

InputHandler* InputHandler::instance = 0;

void InputHandler::onKeyDown() {}
void InputHandler::onKeyUp() {}

void InputHandler::onMouseMove(SDL_Event& event) {
  mousePosition->setX(event.motion.x);
  mousePosition->setY(event.motion.y);
}
void InputHandler::onMouseButtonDown(SDL_Event& event) {
  switch (event.button.button) {
    case SDL_BUTTON_LEFT:
      mouseButtonState[LEFT] = true;
      std::cout << "mouse left";
      break;
    case SDL_BUTTON_MIDDLE:
      mouseButtonState[MIDDLE] = true;
      break;
    case SDL_BUTTON_RIGHT:
      mouseButtonState[RIGHT] = true;
      break;
  }
}
void InputHandler::onMouseButtonUp(SDL_Event& event) {
  switch (event.button.button) {
    case SDL_BUTTON_LEFT:
      mouseButtonState[LEFT] = false;
      break;
    case SDL_BUTTON_MIDDLE:
      mouseButtonState[MIDDLE] = false;
      break;
    case SDL_BUTTON_RIGHT:
      mouseButtonState[RIGHT] = false;
      break;
  }

}


void InputHandler::update() {
  SDL_Event event;
  while(SDL_PollEvent(&event)) {
    keystate = SDL_GetKeyboardState(0);

    switch (event.type) {
      case SDL_QUIT:
        Application::Game::Instance()->clean();
        break;

      case SDL_MOUSEMOTION:
        onMouseMove(event);
        break;

      case SDL_MOUSEBUTTONDOWN:
        onMouseButtonDown(event);
        break;

      case SDL_MOUSEBUTTONUP:
        onMouseButtonUp(event);
        break;
      case SDL_KEYDOWN:
        onKeyDown();
        break;
      case SDL_KEYUP:
        onKeyUp();
        break;
    }

  }
}

bool InputHandler::getMouseState(int mouseNumber) {
  return mouseButtonState[mouseNumber];
}

bool InputHandler::isKeyDown(SDL_Scancode key) {
  if(keystate != 0)
  {
    if(keystate[key] == 1)
    {
      return true;
    }
  }
  return false;
}

