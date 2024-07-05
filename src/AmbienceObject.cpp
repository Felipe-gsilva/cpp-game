#include "AmbienceObject.h"
#include <SDL2/SDL.h>

AmbienceObject::AmbienceObject(const LoaderParams* params) : GameObject(params) { }

void AmbienceObject::draw() {
  GameObject::draw();
}

void AmbienceObject::update() {
  coord.setX(coord.getX() + 1);
}

void AmbienceObject::clean() {
}
