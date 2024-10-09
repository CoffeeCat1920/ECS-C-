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

// To keep track of Entities and Components
using Signature = std::bitset<MAX_COMPONENTS>;

// Entity aliases
using Entity = std::uint32_t;
const Entity MAX_ENTITIES = 5000;

static App *app = new App;
