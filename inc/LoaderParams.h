#pragma once

#include <string>
#include "Defines.h"

class LoaderParams {
public :
  LoaderParams(int x, int y, int width, int height, std::string textureId) {
    this->x=x ;
    this->y = y;
    this->width = width;
    this->height = height;
    this->textureId = textureId;
  };


  int getX() const { return x; }
  int getY() const { return y; }
  int getWidth() const { return width; }
  int getHeight() const { return height; }
  std::string getTextureId() const { return textureId; }

private:
  int x;
  int y;
  int width;
  int height;
  std::string textureId;
};
