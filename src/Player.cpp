#include "Player.h"
#include <SDL2/SDL.h>

Player::Player(const LoaderParams* params) : GameObject(params) {
}

void Player::draw() {
  GameObject::draw();
}

void Player::update() {
  currentFrame = int(((SDL_GetTicks() / 100) % 6));
  acceleration.setX(0);
  GameObject::update();
}

void Player::clean() {
  GameObject::clean();
}
