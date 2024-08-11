#include "AmbienceObject.h"
#include <SDL2/SDL.h>
#include "Game.h"
#include "util/TextureHandler.h"

AmbienceObject::AmbienceObject(const LoaderParams* params) : GameObject(params) { }

void AmbienceObject::draw() {
  Texture::TextureHandler::Instance()->draw(textureId, coord.getX(), coord.getY(), width, height, Application::Game::Instance()->getRenderer());
}

void AmbienceObject::update() {
  coord.setX(coord.getX() + 1);
  currentFrame = 1; 
}

void AmbienceObject::clean() {
}
