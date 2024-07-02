#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>

#define u8 Uint8
#define u16 Uint16
#define u32 Uint32
#define u64 Uint64


namespace Application {
class Game{
public:
  Game() {}
  ~Game() {} 

  int main();
  void update();
  bool init();
  bool runnable();
  void render();
  void clean();
  void setRunnable(bool runnable);
  void handleEvents(); 

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

private:
  SDL_Window *window;
  SDL_Renderer *renderer;
  SDL_Event event;
  const WindowSettings windowSettings;
};
}
