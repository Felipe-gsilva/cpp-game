#pragma once

#include "Defines.h"
#include <string>
#include "GameObject.h"
#include "MenuButton.h"
#include "TextureHandler.h"
#include <vector>

namespace States {
class GameStates {
public:
  virtual ~GameStates(){}

  virtual void update() = 0;
  virtual void render() = 0;
  virtual bool onEnter() = 0;
  virtual bool onExit() = 0;
  virtual std::string getStateId() const = 0;
};
}
