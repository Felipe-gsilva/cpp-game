#include "Rectangle2D.h"

Rectangle2D::Rectangle2D(u16 w, u16 h, Vector2D p) : width(w), height(h), pos(p) {}

bool Rectangle2D::intersects(Rectangle2D *other) {
  if (bottom <= other->top) {
    return false;
  }
  if (top >= other->bottom) {
    return false;
  }
  if (right <= other->left) {
    return false;
  }
  if (left >= other->right) {
    return false;
  }
  return true;
}
