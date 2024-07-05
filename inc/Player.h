#pragma once

#include "GameObject.h"

using namespace Object;

class Player : public GameObject {
public:
  Player(const LoaderParams* params);
  ~Player() {}

  void draw() override;
  void update() override;
  void clean() override;

};

