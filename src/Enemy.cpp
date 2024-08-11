#include "Enemy.h"

void Enemy::load(int x, int y, int width, int height, std::string textureID) {
  GameObject::load(x, y, width, height, textureID);
  xSpeed = ySpeed = 1.2;
}


void Enemy::draw(SDL_Renderer* renderer) {
  GameObject::draw(renderer);
}

void Enemy::update() {
  x = ((int)(x + 0.5f * xSpeed) % 1280);
  y = ((int)(y + 0.5f * ySpeed) % 800);
  currentFrame = int(((SDL_GetTicks() / 100) % 6));

}

void Enemy::clean() {

}
