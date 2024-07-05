#include "Enemy.h"
#include <SDL2/SDL.h>

Enemy::Enemy(const LoaderParams* params) : GameObject(params) { }

void Enemy::draw() {
  GameObject::draw();
}

void Enemy::update() {
  coord.setX(((int)(coord.getX() + xSpeed) % 1280));
  coord.setY(((int)(coord.getY() + ySpeed) % 800));
  currentFrame = int(((SDL_GetTicks() / 100) % 6));
}

void Enemy::clean() {
}
