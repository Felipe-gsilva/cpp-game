#include "Crosshair.h"
#include <SDL2/SDL.h>

#include "InputHandler.h"

Crosshair::Crosshair(const LoaderParams* params) : GameObject(params) {
}

void Crosshair::draw() {
  GameObject::draw();
}

void Crosshair::update() {
  currentFrame = int(((SDL_GetTicks() / 300) % 2));
  Vector2D* mousePos = Event::InputHandler::Instance()->getMousePosition();
  velocity = (*mousePos - rect.getPos()) / 5;
  rect.setPos(rect.getPos() +velocity);
  rect.setPos(rect.getPos() - Vector2D(SprDefaultSize*0.1f, SprDefaultSize*0.1f));
}

void Crosshair::clean() {
  GameObject::clean();
}
