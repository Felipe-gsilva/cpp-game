#pragma once

#include "Defines.h"
#include "GameObject.h"
#include "TextureHandler.h"
#include "InputHandler.h"

#include "GameStateMachine.h"
#include "States/MenuState.h"
#include "States/PlayState.h"

#include <iostream>
#include <vector>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_render.h>


namespace Application {
class Game{
public:
  ~Game() {} 

  int main();
  void update();
  bool init();
  bool running() const;
  void render();
  void clean();
  void setRunnable(bool runnable);
  void handleEvents(); 
  void loadScene();

  bool Running = false;

  struct WindowSettings {
    const char* projectName = "cpp-game"; 
    u16 width = 1280; 
    u16 height = 800;
    u8 flags = SDL_WINDOW_SHOWN;
    u8 fps = 60;
    u16 frameTargetTime = (1000/fps);
  };

  const WindowSettings ws;

  static Game* Instance () {
    if (instance == 0) {
      instance = new Game();
    }
    return instance;
  }

  SDL_Renderer* getRenderer() const { return renderer; }
  SDL_Window* getWindow() const { return window; }
  States::GameStateMachine *getGameStateMachine() const {return gsm;}
  States::PlayState *getPlayState() const {return play; }

private:
  Game() {}
  
  enum gameStates
  {
    MENU = 0,
    PLAY = 1,
    GAMEOVER = 2
  };

  SDL_Window *window;
  SDL_Renderer *renderer;
  SDL_Texture *texture;

  SDL_Rect srcRect;
  SDL_Rect destRect;

  States::GameStateMachine* gsm;
  States::PlayState *play;
  States::MenuState *menu;
  
  static Game* instance;

  u16 currentFrame;
  u8 currentState = MENU;
};
}
