#include "snake.h"
#include <SDL2/SDL.h>
#include <stdbool.h>

#define CELL 15
#define MAX_SNAKE_LENGTH 100

// Initialize the snake
void init_snake(Snake *snake) {
  snake->length = 5;
  snake->dir = RIGHT; // Start moving to the right
  for (int i = 0; i < snake->length; i++) {
    snake->body[i].x = 450 - i * CELL; // Start at center horizontally
    snake->body[i].y = 300;            // Start at center vertically
    snake->body[i].w = CELL;
    snake->body[i].h = CELL;
  }
}

// Move the snake (update body positions)
void move_snake(Snake *snake) {
  // Move body segments
  for (int i = snake->length - 1; i > 0; i--) {
    snake->body[i] =
        snake->body[i -
                    1]; // Move each segment to the previous segment's position
  }

  // Move head in the current direction
  switch (snake->dir) {
  case UP:
    snake->body[0].y -= CELL;
    break;
  case DOWN:
    snake->body[0].y += CELL;
    break;
  case LEFT:
    snake->body[0].x -= CELL;
    break;
  case RIGHT:
    snake->body[0].x += CELL;
    break;
  }
}

// Draw the snake
void draw_snake(SDL_Renderer *renderer, Snake *snake) {
  SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // Green color for the snake
  for (int i = 0; i < snake->length; i++) {
    SDL_RenderFillRect(renderer, &snake->body[i]); // Draw each segment
  }
}

// Handle key press events to change snake direction
void handle_input(SDL_Event *e, Snake *snake) {
  if (e->type == SDL_KEYDOWN) {
    switch (e->key.keysym.sym) {
    case SDLK_UP:
      if (snake->dir != DOWN)
        snake->dir = UP; // Can't reverse direction
      break;
    case SDLK_DOWN:
      if (snake->dir != UP)
        snake->dir = DOWN;
      break;
    case SDLK_LEFT:
      if (snake->dir != RIGHT)
        snake->dir = LEFT;
      break;
    case SDLK_RIGHT:
      if (snake->dir != LEFT)
        snake->dir = RIGHT;
      break;
    }
  }
}
