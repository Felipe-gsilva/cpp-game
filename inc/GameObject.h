#pragma once

#include <string>
#include <SDL2/SDL_render.h>


namespace Object {
class GameObject {
public:
  void load(int x, int y, int width, int height, std::string textureID);
  void draw(SDL_Renderer* renderer);
  void update();
  void clean();

protected:
  std::string textureId;
  int currentFrame;
  int currentRow;
  int x;
  int y;
  int width;
  int height;
};
}
