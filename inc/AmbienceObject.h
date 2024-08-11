#pragma once

#include "GameObject.h" 

using namespace Object;
class AmbienceObject : public GameObject {
public:

private:
  float xSpeed;
  float ySpeed;

public:
  AmbienceObject(const LoaderParams* params);
  ~AmbienceObject() {}

  void draw() override;
  void update() override;
  void clean() override;
};

