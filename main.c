#include <SDL2/SDL.h>
#include <stdio.h>

// Function declarations
SDL_Window *draw_window();
void draw_grid(SDL_Renderer *renderer);

int main() {
  SDL_Window *window = draw_window();
  if (!window)
    return 1;

  SDL_Renderer *renderer =
      SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (!renderer) {
    printf("Error creating renderer: %s\n", SDL_GetError());
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 1;
  }

  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);
  draw_grid(renderer); // Call draw_grid function
  SDL_RenderPresent(renderer);

  SDL_Delay(5000);

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}
