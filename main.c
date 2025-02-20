#include "snake.h"
#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdio.h>

// Function declarations
SDL_Window *draw_window();
void draw_grid(SDL_Renderer *renderer);
void init_snake(Snake *snake);
void draw_snake(SDL_Renderer *renderer, Snake *snake);
void move_snake(Snake *snake);
void handle_input(SDL_Event *e, Snake *snake);

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

  // Set the renderer color to black (RGB: 0, 0, 0)
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black background color

  Snake snake;
  init_snake(&snake); // Initialize the snake

  bool running = true;
  SDL_Event e;

  while (running) {
    SDL_RenderClear(renderer); // Clear the screen with black

    // Handle events
    while (SDL_PollEvent(&e)) {
      if (e.type == SDL_QUIT) {
        running = false;
      }
      handle_input(&e, &snake); // Handle user input to change direction
    }

    move_snake(&snake);           // Move the snake forward
    draw_grid(renderer);          // Draw grid
    draw_snake(renderer, &snake); // Draw the snake

    SDL_RenderPresent(renderer); // Present the updated frame

    SDL_Delay(100); // Control the game speed (100 ms between frames)
  }
}
