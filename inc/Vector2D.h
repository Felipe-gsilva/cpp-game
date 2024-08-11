#pragma once

#include<math.h>

class Vector2D
{
public:
  Vector2D(float x, float y): x(x), y(y) {}
  float getX() { return x; }
  float getY() { return y; }
  void setX(float x) { x = x; }
  void setY(float y) { y = y; }

  float length() { return sqrt ((x*x) + (y*y)); } // inner product from R2

  Vector2D operator+(const Vector2D& v2) const {
    return Vector2D(x + v2.x, y + v2.y); 
  }

  friend Vector2D operator +=(Vector2D& v1, const Vector2D& v2) {
    v1.x += v2.x;
    v1.y += v2.y;
    return v1;
  }

  Vector2D operator*(float a) {
    return Vector2D(x*a, y*a);
  }

  Vector2D& operator*=(float a) {
    x *= a;
    y *= a;
    return *this;
  }

  Vector2D operator-(const Vector2D& v2) const {
    return Vector2D(x - v2.x, y - v2.y); 
  }

  friend Vector2D operator -=(Vector2D& v1, const Vector2D& v2) {
    v1.x -= v2.x;
    v1.y -= v2.y;
    return v1;
  }

  Vector2D operator/(float a)
  {
    return Vector2D(x / a, y / a);
  }

  Vector2D& operator/=(float a)
  {
    x /= a;
    y /= a;
    return *this;
  }

  void normalize(){
    if (length() > 0) 
      (*this) *= 1 / length();
  }


private:
  float x;
  float y;
};
