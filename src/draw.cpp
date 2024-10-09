#include "../include/draw.h"
#include "../include/commons.h"
#include "../include/colors.h"
#include "../include/inputs.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_render.h>


bool InitEngine( std::string title, int w, int h ) {
   
  if ( SDL_Init(SDL_INIT_VIDEO) ) {

    std::cerr << "ERROR: Can't Init SDL" << std::endl; 
    return EXIT_FAILURE;

  }
  else {
    std::cout << "DEBUG: INIT SDL" << std::endl;
  }

  app->window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, 0);

  if (!app->window) {

    std::cerr << "ERROR: Can't Init SDL WINDOW " << std::endl; 
    return EXIT_FAILURE;

  }
  else {
    std::cout << "DEBUG: INIT SDL WINDOW" << std::endl;
  }

  app->renderer = SDL_CreateRenderer(app->window, -1, SDL_RENDERER_PRESENTVSYNC);

  if (!app->renderer) {

    std::cerr << "ERROR: Can't Init SDL RENDERER" << std::endl; 
    return EXIT_FAILURE;

  }
  else {
    std::cout << "DEBUG: INIT SDL RENDERER" << std::endl;
  }

  SDL_UpdateWindowSurface(app->window);

  return true;
  
}

void ClearScreen( SDL_Renderer *renderer ) {

  SDL_SetRenderDrawColor(renderer, Colors::LAVENDER.r, Colors::LAVENDER.g, Colors::LAVENDER.b, Colors::LAVENDER.a);

  SDL_RenderClear(renderer);

}

void Display() {

  bool isRunning = true;

  while ( isRunning ) {
     
    if ( IsKeyPressed(SDLK_ESCAPE) || IsKeyPressed(SDL_QUIT) ) {
      isRunning = false;
    }

    ClearScreen(app->renderer);

    SDL_RenderPresent(app->renderer);

  }

}

void ShutDown() {

  if ( app->window != nullptr ) {

    SDL_DestroyWindow(app->window);
    app->window = nullptr;

    std::cout << "DEBUG: DESTROYED SDL WINDOW" << std::endl;

  }
  if ( app->renderer != nullptr ) {
    
    SDL_DestroyRenderer(app->renderer);
    app->renderer = nullptr;

    std::cout << "DEBUG: DESTROYED SDL RENDERER" << std::endl;

  }
  
  std::cout << "DEBUG: QUITTING SDL" << std::endl;

  SDL_Quit();

}
