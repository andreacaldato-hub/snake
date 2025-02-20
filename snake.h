#include <SDL2/SDL.h>
#define MAX_SNAKE_LENGTH 100

typedef enum { UP, DOWN, LEFT, RIGHT } Direction;
typedef struct {
  int length;
  SDL_Rect body[MAX_SNAKE_LENGTH];
  Direction dir;
} Snake;
