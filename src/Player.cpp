#include "Player.h"
#include <SDL2/SDL.h>

#include "InputHandler.h"

Player::Player(const LoaderParams* params) : GameObject(params) {
}

void Player::draw() {
  if(direction.getX() == 0) {
    GameObject::draw(SDL_FLIP_HORIZONTAL); 
    return;
  }
  GameObject::draw(); 
}

void Player::update() {
  if(velocity.getX() != 0)
    acceleration.setX(velocity.getX() * -0.2);

  if(velocity.getY() != 0) {
    acceleration.setY(velocity.getY() * -0.2);
  }

  if(Event::InputHandler::Instance()->isKeyDown(SDL_SCANCODE_W)) {
    direction.setY(UP);
    if (velocity.getY() >= -5)
      acceleration.setY(-2);
  }
  if(Event::InputHandler::Instance()->isKeyDown(SDL_SCANCODE_D)) {
    direction.setX(RIGHT);
    if (velocity.getX() <= 5)
      acceleration.setX(2);
  }
  if(Event::InputHandler::Instance()->isKeyDown(SDL_SCANCODE_S)) {
    direction.setY(DOWN);
    if (velocity.getY() <= 5)
      acceleration.setY(2);
  }
  if(Event::InputHandler::Instance()->isKeyDown(SDL_SCANCODE_A)) {
    direction.setX(LEFT);
    if (velocity.getX() >= -5)
      acceleration.setX(-2);
  }

  if(velocity != Vector2D(0, 0)) {
    currentRow = 1;
    currentFrame = int(((SDL_GetTicks() / 100) % 6));
  }

  if(velocity == Vector2D(0, 0)) {
    currentRow = 1;
    currentFrame = int(((SDL_GetTicks() / 300) % 5));
  }

  GameObject::update();
}

void Player::clean() {
  GameObject::clean();
}
