#include "GameObject.h"
#include "Game.h"
#include "TextureHandler.h"
#include <iostream>

GameObject::GameObject(const LoaderParams* params) : rect(Rectangle2D((u16)params->getWidth(), (u16)params->getHeight(), Vector2D(params->getX(), params->getY()))), velocity(0,0), acceleration(0, 0), direction(LEFT, DOWN) {
  textureId = params->getTextureId();
  currentRow = 1;
  currentFrame = 1;
}

void GameObject::draw() {
  Texture::TextureHandler::Instance()->drawFrame(textureId, rect.getPos().getX(), rect.getPos().getY(), rect.getWidth(), rect.getHeight(), currentRow, currentFrame, Application::Game::Instance()->getRenderer());
}

bool GameObject::isColliding(GameObject *obj) {
  return rect.intersects(&obj->rect);
}

void GameObject::clean() {}

void GameObject::update() {
  velocity += acceleration;
  rect.setPos(rect.getPos() + velocity);
}

