#include "Player.h"
#include <SDL2/SDL.h>

#include "util/InputHandler.h"

Player::Player(const LoaderParams* params) : GameObject(params) {
}

void Player::draw() {
  GameObject::draw();
}

void Player::update() {
  currentFrame = int(((SDL_GetTicks() / 100) % 6));
  Vector2D* mousePos = Event::InputHandler::Instance()->getMousePosition();
  velocity = (*mousePos - coord) /10;
  GameObject::update();
}

void Player::clean() {
  GameObject::clean();
}
