#pragma once

#include "Defines.h"
#include "GameStates.h"

namespace States {
class MenuState : public GameStates {
public:
  MenuState() {}
  ~MenuState() {}

  void update() override;
  void render() override;
  bool onEnter() override;
  bool onExit() override;
  std::string getStateId() const override { return menuId; }
private:
  static const std::string menuId;
  std::vector<Object::GameObject*> gameObjects;
};
}
