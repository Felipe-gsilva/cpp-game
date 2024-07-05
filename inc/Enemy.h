#pragma once

#include "GameObject.h" 

using namespace Object;
class Enemy : public GameObject {
public:

private:
  float xSpeed;
  float ySpeed;

public:
  Enemy(const LoaderParams* params);
  ~Enemy() {}

  void draw() override;
  void update() override;
  void clean() override;
};

