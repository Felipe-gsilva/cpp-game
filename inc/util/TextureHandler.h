#pragma once

#include <string>
#include <map>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_image.h>



namespace Texture {
class TextureHandler {
private:
  std::map<std::string, SDL_Texture*> textureMap;
  static TextureHandler* instance;

private:
  TextureHandler() {}
  ~TextureHandler() {}

public:
  static Texture::TextureHandler* Instance() {
    if(instance == 0)
    {
      instance = new TextureHandler();
    }
    return instance;
  }

  bool load(std::string fileName, std::string id, SDL_Renderer* renderer);

  void draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

  void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

};
}
