#pragma once

#include "GameObject.h" 

using namespace Object;

class Enemy : public GameObject {
public:

private:
  float xSpeed;
  float ySpeed;

public:
  void load(int x, int y, int width, int height, std::string textureID);
  void draw(SDL_Renderer *renderer);
  void update();
  void clean();
};

