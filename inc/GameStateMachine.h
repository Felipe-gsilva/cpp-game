#pragma once
#include "Defines.h"
#include "GameStates.h"

#include <vector>

namespace States {
class GameStateMachine {
public:
  GameStateMachine() {}
  ~GameStateMachine() {}

  void update();
  void render();
  void pushState(GameStates* state);
  void changeState(GameStates* state);
  void popState(GameStates* state);

private:
  std::vector<GameStates*> gameStates;
};
}
