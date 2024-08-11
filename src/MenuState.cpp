#include "States/MenuState.h"
#include "Game.h"


using namespace Application;
using namespace States;
using namespace Texture;
using namespace Object;

const std::string MenuState::menuId = "MENU";

void MenuState::update()
{
  for(auto& gameObject : gameObjects){
    gameObject->update();
  }
}

void MenuState::render()
{
  for(auto& gameObject : gameObjects){
    gameObject->draw();
  }
}

bool MenuState::onEnter()
{
  if(!TextureHandler::Instance()->load("assets/playbutton.png","playbutton", Game::Instance()->getRenderer()))
    return false;

  if(!TextureHandler::Instance()->load("assets/exitbutton.png", "exitbutton", Game::Instance()->getRenderer()))
    return false;

  GameObject* button1 = new MenuButton(new LoaderParams(Game::Instance()->ws.width* 0.4 - ((float)SprDefaultSize/2), Game::Instance()->ws.height*0.8f, 32, 16, "playbutton"), MenuButton::menuToPlay);
  GameObject* button2 = new MenuButton(new LoaderParams(Game::Instance()->ws.width* 0.6 - ((float)SprDefaultSize/2), Game::Instance()->ws.height*0.8f, 32, 16, "exitbutton"), MenuButton::exitFromMenu);
  gameObjects.push_back(button1);
  gameObjects.push_back(button2);

  std::cout << "entering MenuState\n";
  return true;
}

bool MenuState::onExit()
{
  for(auto& gameObject : gameObjects){
    gameObject->clean();
  }

  gameObjects.clear();
  TextureHandler::Instance()->clearFromTextureMap("playbutton");
  TextureHandler::Instance()->clearFromTextureMap("playbutton");

  std::cout << "exiting MenuState\n";
  return true;
}
