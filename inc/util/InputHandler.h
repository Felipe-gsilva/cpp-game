#pragma once

#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keyboard.h>
#include <vector>
#include "Vector2D.h"

namespace Event {
class InputHandler{
public:
  enum mouse_buttons
  {
    LEFT = 0,
    MIDDLE = 1,
    RIGHT = 2
  };

  static InputHandler* Instance() {
    if(instance == nullptr) {
      instance = new InputHandler();
    }
    return instance;
  }

  void update();
  void clean();
  bool getMouseState(int buttonNumber);
  Vector2D *getMousePosition() {
    return mousePosition;
  }

private:
  InputHandler() : mousePosition(new Vector2D(0,0)) {
    for(int i = 0; i < 3; i++)
    {
      mouseButtonState.push_back(false);
    }
  }
  ~InputHandler() { 
    delete mousePosition;
  }

  static InputHandler* instance;

  std::vector<bool> mouseButtonState;
  Vector2D* mousePosition;
};
}
