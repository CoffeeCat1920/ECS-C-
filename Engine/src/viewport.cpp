#include "./viewport.hpp"

#include <SDL2/SDL_render.h>
#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

Viewport::Viewport(std::string title, int w, int h, bool fullscreen) {

  this->title = title;
  this->w = w;
  this->h = h; 
  this->fullscreen = fullscreen;

}

Viewport::~Viewport() {}

void Viewport::Init() {
  
  //
  // To check if fulllscreem
  //
  int flag;

  fullscreen ? flag = SDL_WINDOW_FULLSCREEN : flag = 0;   

  //
  // Initilie Window and Renderer
  //
  if ( SDL_Init( SDL_INIT_EVERYTHING ) == 0 ) {
    
    std::cout << "DEBUG: SDL INIT EVERYTHING" << std::endl;

    this->window = SDL_CreateWindow( title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, flag);

    if ( window ) std::cout << "DEBUG: WINDOW CREATED" << std::endl;
    else { 

      std::cerr << "ERROR: WINDOW COULD NOT BE INITILIZED" << std::endl;
      return;

    }

    this->renderer = SDL_CreateRenderer( this->window, -1, 0);

    if ( renderer ) std::cout << "DEBUG: RENDERER CREATED" << std::endl;
    else {

      std::cerr << "ERROR: RENDERER COULD NOT ME INITILIZED" << std::endl;       

    }
    

  } 
  else {

    std::cerr << "ERROR: SDL CAN/'T INITILIZE" << std::endl;

  }

}

void Viewport::Update() {

}

void Viewport::Reneder() {

  SDL_RenderClear( this->renderer );
  
  SDL_RenderPresent( this->renderer );

}
