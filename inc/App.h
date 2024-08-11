#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>

#define u8 Uint8
#define u16 Uint16
#define u32 Uint32
#define u64 Uint64


namespace Application {
class App{
private:
  SDL_Window *window;
  SDL_Renderer *renderer;
  bool isRunning = false;

public:
  bool init(const char* title, int x, int y, int width, int height, int flags);
  bool runnable();
  void run();
  void render();
  void update(){}
  void handleEvents(){}
  void clean(){}
};
}
