#include "Rectangle2D.h"

Rectangle2D::Rectangle2D(u16 w, u16 h, Vector2D p) : width(w), height(h), pos(p) {}

bool Rectangle2D::intersects(Rectangle2D *other) {
  if (bottom <= other->top || top >= other->bottom|| right <= other->left|| left >= other->right) {
    return true;
  }
  return false;
}
