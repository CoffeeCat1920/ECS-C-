#include "include/draw.h"
#include <SDL2/SDL_keycode.h>
#include <cstdlib>

int main (int argc, char *argv[]) {
  
  if ( !InitEngine("Test", 500, 500) ) {
    ShutDown();
    return EXIT_FAILURE;
  }
  
  Display();

  ShutDown();

  return EXIT_SUCCESS;

}
