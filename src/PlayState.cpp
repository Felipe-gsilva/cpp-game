#include "PlayState.h"

using namespace States;

const std::string PlayState::playId = "PLAY";

void PlayState::update()
{
  // nothing for now
}
void PlayState::render()
{
  // nothing for now
}
bool PlayState::onEnter()
{
  std::cout << "entering PlayState\n";
  return true;
}
bool PlayState::onExit()
{
  std::cout << "exiting PlayState\n";
  return true;
}
