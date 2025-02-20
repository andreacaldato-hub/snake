#include "dimension.h"
#include <SDL2/SDL.h>

void draw_grid(SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // White grid lines

  for (int x = 0; x <= WIDTH; x += CELL) {
    SDL_RenderDrawLine(renderer, x, 0, x, HEIGHT);
  }
  for (int y = 0; y <= HEIGHT; y += CELL) {
    SDL_RenderDrawLine(renderer, 0, y, WIDTH, y);
  }
}
