#include "MenuButton.h"

using namespace Object;
using namespace Event;

MenuButton::MenuButton(const LoaderParams* params) : GameObject(params) {
  currentFrame = MOUSE_OUT;
}

void MenuButton::draw() {
  GameObject::draw();
}

void MenuButton::update() {
  Vector2D* mousePos = InputHandler::Instance()->getMousePosition();
  if(mousePos->getX() < (coord.getX() + width) && mousePos->getX() > coord.getX() && mousePos->getY() < (coord.getY() + height) && mousePos->getY() > coord.getY()) {
    currentFrame = MOUSE_OVER;
    if(InputHandler::Instance()->getMouseState(InputHandler::LEFT)) {
      currentFrame = CLICKED;
    }
  }
  else {
    currentFrame = MOUSE_OUT;
  }
}

void MenuButton::clean() {
  GameObject::clean();
}
