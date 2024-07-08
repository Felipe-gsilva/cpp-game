#pragma once

#include "GameObject.h"

using namespace Object;

class Crosshair: public GameObject {
public:
  Crosshair(const LoaderParams* params);
  ~Crosshair() {}

  void draw() override;
  void update() override;
  void clean() override;

};

