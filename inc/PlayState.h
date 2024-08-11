#pragma once

#include "AmbienceObject.h"
#include "Crosshair.h"
#include "Enemy.h"
#include "GameStates.h"
#include "Player.h"

namespace States {
class PlayState : public GameStates {
public:
  PlayState() {}
  virtual ~PlayState() {}

  void update() override;
  void render() override;
  bool onEnter() override;
  bool onExit() override;
  std::string getStateId() const override { return playId; }
private:
  static const std::string playId;
  std::vector<Object::GameObject*> gameObjects;
};
}
