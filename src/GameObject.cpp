#include "GameObject.h"
#include "Game.h"
#include "util/TextureHandler.h"
#include <iostream>

GameObject::GameObject(const LoaderParams* params) : coord(params->getX(), params->getY()), velocity(0,0), acceleration(0, 0) {
  width = params->getWidth();
  height = params->getHeight();
  textureId = params->getTextureId();
  currentRow = 1;
  currentFrame = 1;
}

void GameObject::draw() {
  Texture::TextureHandler::Instance()->drawFrame(textureId, coord.getX(), coord.getY(), width, height, currentRow, currentFrame, Application::Game::Instance()->getRenderer());
}

void GameObject::clean() {}

void GameObject::update() {
  velocity += acceleration;
  coord += velocity;
}

