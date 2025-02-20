#include <SDL2/SDL.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>

int main() {
  // Initialize SDL
  SDL_Init(SDL_INIT_VIDEO);

  // Create a window
  SDL_Window *window =
      SDL_CreateWindow("SNAKE", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                       1200, 900, SDL_WINDOW_SHOWN);
  if (window == NULL) {
    printf("Error creating window\n");
    return 1;
  }

  // Create renderer
  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

  // Set background color (black)
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // window background color
  SDL_RenderClear(renderer); // Clear the window with the background color

  // Set color for the rectangle (green)
  SDL_SetRenderDrawColor(renderer, 0, 255, 0,
                         255); // rectangle color (opaque green)

  // Define a rectangle
  SDL_Rect rect = {200, 200, 300, 40}; // position and size of the rectangle

  // Fill the rectangle with the set color
  SDL_RenderFillRect(renderer, &rect);

  // Optionally, you can draw a border around the rectangle
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

  SDL_RenderDrawRect(renderer, &rect);

  // SDL_RenderDrawRect(renderer, &rect);

  // Update the window (render the content)
  SDL_RenderPresent(renderer);

  // Wait for 5 seconds
  SDL_Delay(5000);

  // Clean up and quit SDL
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
