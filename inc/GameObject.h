#pragma once

#include "LoaderParams.h"
#include "Vector2D.h"
#include "Rectangle2D.h"
#include "SDL_render.h"


namespace Object {
class GameObject {
public:
  virtual ~GameObject() {}

  virtual void draw();
  virtual void draw(SDL_RendererFlip flip);
  virtual void update();
  virtual void clean();
  bool isColliding(GameObject* obj);

  enum facing {
    LEFT = 0,
    RIGHT = 1,
    DOWN = 0,
    UP = 1
  };

  enum frame {
    IDLE = 1,
    MOVE = 2,
    ATTACK = 4,
    JUMP = 5
  };

protected:
  GameObject(const LoaderParams* params);

  Vector2D velocity;
  Vector2D acceleration;
  Rectangle2D rect;
  Vector2D direction;

  float life; //TODO 

  int currentRow;
  int currentFrame;

  std::string textureId;
};
}
