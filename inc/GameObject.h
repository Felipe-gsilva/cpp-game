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

  GameObject(const LoaderParams* params);
protected:

  Vector2D coord;
  int width;
  int height;
  int currentRow;
  int currentFrame;
  std::string textureId;
};
}
