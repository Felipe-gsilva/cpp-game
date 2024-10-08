#include "GameStateMachine.h"

using  namespace States;
void GameStateMachine::update() {
  if(!gameStates.empty()) {
    gameStates.back()->getStateId();
    gameStates.back()->update();
  }
}
void GameStateMachine::render() {
  if(!gameStates.empty()) {
    gameStates.back()->render();
  }
}

void GameStateMachine::pushState(GameStates *state) {
  gameStates.push_back(state);
  gameStates.back()->onEnter();
}

void GameStateMachine::changeState(GameStates *state) {
  if(!gameStates.empty()) {
    if(gameStates.back()->getStateId() == state->getStateId())
      return; 
    

    if(gameStates.back()->onExit()) {
      delete gameStates.back();
      gameStates.pop_back();
    }

    gameStates.push_back(state);
    gameStates.back()->onEnter();
  }
}

void GameStateMachine::popState(GameStates *state) {
  if(!gameStates.empty()) {
    if(gameStates.back()->onExit()) {
      delete gameStates.back();
      gameStates.pop_back();
    }
  }
}
