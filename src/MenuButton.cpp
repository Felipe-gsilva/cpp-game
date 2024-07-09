#include "MenuButton.h"
#include "Game.h"
#include "States/PlayState.h"

using namespace Object;
using namespace Event;
using namespace States;


MenuButton::MenuButton(const LoaderParams* params, void (*callback)()) : GameObject(params), callback (*callback) {
  currentFrame = MOUSE_OUT;
}

void MenuButton::draw() {
  GameObject::draw();
}

void MenuButton::update() {
  Vector2D* mousePos = InputHandler::Instance()->getMousePosition();
  if(mousePos->getX() < (rect.getPos().getX() + rect.getWidth()) && mousePos->getX() > rect.getPos().getX() && mousePos->getY() < (rect.getPos().getY() + rect.getHeight()) && mousePos->getY() > rect.getPos().getY()) {
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
  Application::Game::Instance()->getGameStateMachine()->changeState(new PlayState());
}
void MenuButton::exitFromMenu() {
  Application::Game::Instance()->clean();
}
