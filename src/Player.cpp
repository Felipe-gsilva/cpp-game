#include "Player.h"
#include <SDL2/SDL.h>

#include "InputHandler.h"

Player::Player(const LoaderParams* params) : GameObject(params) {
}

void Player::draw() {
  GameObject::draw();
}

void Player::update() {
  currentFrame = int(((SDL_GetTicks() / 100) % 6));

  if(velocity.getX() != 0)
    acceleration.setX(velocity.getX() * -0.2);

  if(velocity.getY() != 0) {
    acceleration.setY(velocity.getY() * -0.2);
  }

  if(Event::InputHandler::Instance()->isKeyDown(SDL_SCANCODE_W)) {
    if (velocity.getY() >= -5)
      acceleration.setY(-2);
  }
  if(Event::InputHandler::Instance()->isKeyDown(SDL_SCANCODE_D)) {
    if (velocity.getX() <= 5)
      acceleration.setX(2);
  }
  if(Event::InputHandler::Instance()->isKeyDown(SDL_SCANCODE_S)) {
    if (velocity.getY() <= 5)
      acceleration.setY(2);
  }
  if(Event::InputHandler::Instance()->isKeyDown(SDL_SCANCODE_A)) {
    if (velocity.getX() >= -5)
      acceleration.setX(-2);
  }

  GameObject::update();
}

void Player::clean() {
  GameObject::clean();
}
