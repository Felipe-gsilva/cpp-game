#pragma once

#include "util/LoaderParams.h"
#include "Vector2D.h"


namespace Object {
class GameObject {
public:
  virtual ~GameObject() {}

  virtual void draw();
  virtual void update();
  virtual void clean();

protected:
  GameObject(const LoaderParams* params);

  Vector2D coord;
  Vector2D velocity;
  Vector2D acceleration;
  int width;
  int height;
  int currentRow;
  int currentFrame;
  std::string textureId;
};
}
