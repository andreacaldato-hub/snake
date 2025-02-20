#include <SDL2/SDL.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>
#define WIDTH 900
#define HEIGHT 600

int draw_window() {
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Window *window =
      SDL_CreateWindow("SNAKE", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                       WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
  if (window == NULL) {
    printf("Errore creazione window\n");
    return 1;
  }
  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // window background color
  SDL_RenderPresent(renderer);

  SDL_SetRenderDrawColor(renderer, 0, 255, 0, 0); // rectangle  color
  SDL_Rect rect = {200, 200, 300, 40};
  SDL_RenderFillRect(renderer, &rect);
  SDL_RenderPresent(renderer);

  SDL_RenderDrawRect(renderer, &rect);
  SDL_Delay(5000);
  return 0;
}

// int drwa_grid(SDL_Surface *surface) {}
