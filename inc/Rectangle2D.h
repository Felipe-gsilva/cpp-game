#pragma once

#include "Defines.h"
#include "Vector2D.h"

class Rectangle2D {
private:
  Vector2D pos;
  u16 width;
  u16 height;

public:
  Rectangle2D(u16 w, u16 h, Vector2D p);

  u16 getWidth() const { return width;}
  u16 getHeight() const { return height;}
  Vector2D getPos() const { return pos;}

  const u16 left = getWidth();
  const u16 right = getWidth() + getPos().getX();
  const u16 top = getHeight();
  const u16 bottom = getHeight() + getPos().getY();

  void setPos(Vector2D p) {pos = p;}
  void setWidth(u16 w) {width = w;}
  void setHeight(u16 h) {height = h;}

  bool intersects(Rectangle2D *other);
};
