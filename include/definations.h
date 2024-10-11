#pragma once

#include <SDL2/SDL_render.h>
#include <bitset>
#include <cstdint>

// The App Struct
struct App {
  SDL_Window *window = nullptr;
  SDL_Renderer *renderer = nullptr;
};

// A vector2 class to store position
struct Vector2 {
  long  x;
  long  y;
  Vector2 ( long x, long y ) {
    this->x = x;
    this->y = y;
  }
  Vector2() {
    this->x = 0.0l;
    this->y = 0.0l;
  }
};


// ComponentType aliases
using ComponentType = std::uint8_t;
const ComponentType MAX_COMPONENTS = 32;

// A std::bitset the size of MAX_COMPONENTS
using Signature = std::bitset<MAX_COMPONENTS>;

// Entity aliases
using Entity = std::uint32_t;
const Entity MAX_ENTITIES = 5000;

// The App that is initilized and then displayed
static App *app = new App;
