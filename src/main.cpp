#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <iostream>

class main {
private:
public:
  main(){
    surface();
    window();
  }

  int window() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
      std::cout << "error initializing SDL: %s\n" <<  SDL_GetError() << std::endl;
    }

    SDL_Window* window = SDL_CreateWindow("GAME", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 1000, 0);
    while(1)
      ;
  }
  int surface() {
    return 0;
  }

private:

};
