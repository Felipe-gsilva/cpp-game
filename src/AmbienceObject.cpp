#include "AmbienceObject.h"
#include <SDL2/SDL.h>
#include "Game.h"
#include "TextureHandler.h"

AmbienceObject::AmbienceObject(const LoaderParams* params) : GameObject(params) { }

void AmbienceObject::draw() {
  Texture::TextureHandler::Instance()->draw(textureId, rect.getPos().getX(), rect.getPos().getY(), rect.getWidth(), rect.getHeight(), Application::Game::Instance()->getRenderer());
}

void AmbienceObject::update() {
  if(rect.getPos().getY() != 1280)
    acceleration.setY(-1.2f);
  else
    rect.getPos().setY(0);
  GameObject::update();
}

void AmbienceObject::clean() {
  GameObject::clean();
}
