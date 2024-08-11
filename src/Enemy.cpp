#include "Enemy.h"
#include <SDL2/SDL.h>
#include "Game.h"

Enemy::Enemy(const LoaderParams* params) : GameObject(params) { }

void Enemy::draw() {
  GameObject::draw();
}

void Enemy::update() {
  rect.getPos().setX(((int)(rect.getPos().getX() + xSpeed) % 1280));
  rect.getPos().setY(((int)(rect.getPos().getY() + ySpeed) % 800));
}

void Enemy::clean() {
  GameObject::clean();
}
