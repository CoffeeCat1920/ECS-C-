#include "../include/commons.h"
#include "../include/inputs.h"

std::map<int, bool> GetInput() {
  
  std::map<int, bool> keyboard;

  SDL_Event event;

  while ( SDL_PollEvent(&event) ) {

    switch(event.type) {
      case SDL_KEYDOWN:
        keyboard[event.key.keysym.sym] = false;  
        break;
      case SDL_KEYUP:
        keyboard[event.key.keysym.sym] = true;  
        break;
    }

  }

  return keyboard;

}

bool IsKeyPressed(int key) {
  
  std::map<int, bool> keyboard = GetInput(); 

  if ( keyboard[key] ) return true;

  return false;

}
