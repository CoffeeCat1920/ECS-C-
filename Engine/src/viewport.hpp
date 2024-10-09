#pragma once

#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Viewport {

private:

  std::string title;
  int w;
  int h;
  bool fullscreen;

  SDL_Window *window;
  SDL_Renderer *renderer;

public:

  Viewport( std::string title, int w, int h, bool fullscreen  );
  ~Viewport();

  void Init();
  void Update();
  void Reneder();

};
