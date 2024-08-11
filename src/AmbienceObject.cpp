#include "AmbienceObject.h"
#include <SDL2/SDL.h>
#include "Game.h"
#include "TextureHandler.h"

AmbienceObject::AmbienceObject(const LoaderParams* params) : GameObject(params) { }

void AmbienceObject::draw() {
  Texture::TextureHandler::Instance()->draw(textureId, coord.getX(), coord.getY(), width, height, Application::Game::Instance()->getRenderer());
}

void AmbienceObject::update() {
  u8 i = 1;
  acceleration.setY(i++);
  GameObject::update();
}

void AmbienceObject::clean() {
  GameObject::clean();
}
