#include "Player.h"

void Player::load(int x, int y, int width, int height, std::string textureID) {
  GameObject::load(x, y, width, height, textureID);
  xSpeed = ySpeed = 1.2;
}


void Player::draw(SDL_Renderer* renderer) {
  GameObject::draw(renderer);
}

void Player::update() {
  x = ((int)(x + xSpeed) % 1280);
  y = ((int)(y + ySpeed) % 800);
  currentFrame = int(((SDL_GetTicks() / 100) % 6));

}

void Player::clean() {

}
