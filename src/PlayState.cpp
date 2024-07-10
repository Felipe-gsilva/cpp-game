#include "States/PlayState.h"
#include "Game.h"

using namespace States;
using namespace Application;

const std::string PlayState::playId = "PLAY";

void PlayState::update()
{
  for(auto& gameObject : gameObjects) {
    for(auto& test: gameObjects) {
      if(gameObject->isColliding(test)) {
        //do something
      }
    }
    gameObject->update(); 
  }
}

void PlayState::render()
{
  for(auto& gameObject : gameObjects) 
  gameObject->draw();
}

bool PlayState::onEnter()
{
  gameObjects.push_back(new Player(new LoaderParams(Game::Instance()->ws.width/2 - (SprDefaultSize/2),Game::Instance()->ws.height/2 - (SprDefaultSize/2), SprDefaultSize, SprDefaultSize, "animate")));

  gameObjects.push_back(new Enemy(new LoaderParams(Game::Instance()->ws.width * 0.2f, Game::Instance()->ws.height * 0.2f, SprDefaultSize, SprDefaultSize, "animate")));

  gameObjects.push_back(new AmbienceObject(new LoaderParams(50, 50, 32, 32, "fire")));
  gameObjects.push_back(new Crosshair(new LoaderParams(Game::Instance()->ws.width/2 - (SprDefaultSize/2), Game::Instance()->ws.height/2 - (SprDefaultSize/2), SprDefaultSize, SprDefaultSize, "crosshair")));

  std::cout << "entering PlayState\n";
  return true;
}
bool PlayState::onExit()
{
  std::cout << "exiting PlayState\n";
  return true;
}
