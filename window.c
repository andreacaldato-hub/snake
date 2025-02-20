#include "dimension.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_surface.h>
#include <stdio.h>

SDL_Window *draw_window() {
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    printf("SDL Init failed: %s\n", SDL_GetError());
    return NULL; // Return NULL if initialization fails
  }

  SDL_Window *window =
      SDL_CreateWindow("SNAKE", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                       WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
  if (!window) {
    printf("Error creating window: %s\n", SDL_GetError());
    SDL_Quit();
    return NULL;
  }

  return window; // Return the created window
}
