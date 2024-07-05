#pragma once

#include "util/Defines.h"
#include "Player.h"
#include "Enemy.h"
#include "AmbienceObject.h"


#include <vector>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_render.h>

using namespace Object;

namespace Application {
class Game{
public:
  ~Game() {} 

  int main();
  void update();
  bool init();
  bool running();
  void render();
  void clean();
  void setRunnable(bool runnable);
  void handleEvents(); 
  void loadScene();
private:

public:
  bool Running = false;

  struct WindowSettings {
    const char* projectName = "cpp-game"; 
    u16 width = 1280; 
    u16 height = 800;
    u8 flags = SDL_WINDOW_SHOWN;
    u8 fps = 60;
    u16 frameTargetTime = (1000/fps);
  };

  const WindowSettings windowSettings;

  static Game* Instance () {
    if (instance == 0) {
      instance = new Game();
    }
    return instance;
  }

  SDL_Renderer* getRenderer() const { return renderer; }

private:
  Game() {}
  
  SDL_Window *window;
  SDL_Renderer *renderer;
  SDL_Texture *texture;

  SDL_Rect srcRect;
  SDL_Rect destRect;

  u16 currentFrame;

  SDL_Event event;

  Player* player;
  GameObject* enemy1;
  GameObject* enemy2;
  GameObject* enemy3;

  std::vector<GameObject*> gameObjects;

  static Game* instance;
};
}
