#include "Player.h"
#include <SDL2/SDL.h>

Player::Player(const LoaderParams* params) : GameObject(params) { }

void Player::draw() {
  GameObject::draw();
}

void Player::update() {
  coord.setX(((int)(coord.getX() + xSpeed) % 1280));
  coord.setY(((int)(coord.getY() + ySpeed) % 800));
  currentFrame = int(((SDL_GetTicks() / 100) % 6));
}

void Player::clean() {
}
