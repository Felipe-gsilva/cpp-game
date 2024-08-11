#include "GameObject.h"
#include "TextureHandler.h"

using namespace Object;
using namespace Texture;

void GameObject::load(int x, int y, int width, int height, std::string textureId) {
  this->x = x;
  this->y = y;
  this->width = width;
  this->height = height;
  this->textureId = textureId;

  currentFrame = 1;
  currentRow = 1;
}

void GameObject::draw(SDL_Renderer *renderer) {
  TextureHandler::Instance()->drawFrame(textureId, x, y, width, height, currentRow, currentFrame, renderer, SDL_FLIP_NONE);
}

void GameObject::update() {
  x = (x + 10) % 640;
  
  currentFrame = int(((SDL_GetTicks() / 100) % 6));
}
