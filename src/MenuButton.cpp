#include "MenuButton.h"
#include "Game.h"

using namespace Object;
using namespace Event;

MenuButton::MenuButton(const LoaderParams* params, void (*callback)()) : GameObject(params), callback (*callback) {
  currentFrame = MOUSE_OUT;
}

void MenuButton::draw() {
  GameObject::draw();
}

void MenuButton::update() {
  Vector2D* mousePos = InputHandler::Instance()->getMousePosition();
  if(mousePos->getX() < (coord.getX() + width) && mousePos->getX() > coord.getX() && mousePos->getY() < (coord.getY() + height) && mousePos->getY() > coord.getY()) {
    currentFrame = MOUSE_OVER;
    if(InputHandler::Instance()->getMouseState(InputHandler::LEFT) && released) {
      currentFrame = CLICKED;

      callback();

      released = false;
    }

    else if(!InputHandler::Instance()->getMouseState(InputHandler::LEFT)) {
      released = true;
      currentFrame = MOUSE_OVER;
    }
  }
  else {
    currentFrame = MOUSE_OUT;
  }
}

void MenuButton::clean() {
  GameObject::clean();
}

void MenuButton::menuToPlay() {
  std::cout << "Play button clicked\n";
}
void MenuButton::exitFromMenu() {
  Application::Game::Instance()->clean();
}
