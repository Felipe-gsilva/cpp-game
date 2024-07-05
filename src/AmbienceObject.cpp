#include "AmbienceObject.h"
#include <SDL2/SDL.h>
#include "Game.h"
#include "util/TextureHandler.h"

AmbienceObject::AmbienceObject(const LoaderParams* params) : GameObject(params) { }

void AmbienceObject::draw() {
  Texture::TextureHandler::Instance()->draw(textureId, coord.getX(), coord.getY(), width, height, Application::Game::Instance()->getRenderer());
}

void AmbienceObject::update() {
  velocity.setY(1);
  GameObject::update();
}

void AmbienceObject::clean() {
  GameObject::clean();
}
