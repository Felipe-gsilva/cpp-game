#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include "EventHandler.h"
#include "UpdateHandler.h"

#define PROJECT_NAME "cpp-game"
#define WIDTH 640
#define HEIGHT 400
#define u8 Uint8
#define u16 Uint16
#define u32 Uint32
#define u64 Uint64


namespace Application {
class App{
public:
  App() {}
  ~App() {}

  bool init(const char* title, int x, int y, int width, int height, int flags);
  bool runnable();
  void render();
  void clean();
  void setRunnable(bool runnable);

public:
  Event::EventHandler eventHandler;
  Update::UpdateHandler updateHandler;

private:
  SDL_Window *window;
  SDL_Renderer *renderer;
  bool isRunning = false;

};
}
