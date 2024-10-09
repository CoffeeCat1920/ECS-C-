#pragma once

#include <string>
#include <SDL2/SDL.h>

// Initilize the SDL engine
bool InitEngine( std::string, int , int  );

// Clear the app->renderer
void ClearScreen( SDL_Renderer* );

// To handle displaying app->render and bool running
void Display();

// Shutdown the SDL engine
void ShutDown();
