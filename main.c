#include <stdio.h>
#include "matrix.h"
#include <math.h>
#include <SDL2/SDL.h>
#include "projections.h"

int main() {

  int is_running;
  const int fps = 60;
  const uint32_t max_frame_time = (uint32_t) 1000 / fps;

  uint32_t frame_time;
  uint32_t frame_start;

  SDL_Event event;
  SDL_Window *window;
  SDL_Renderer *renderer;
  SDL_GLContext *ctx;

  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    printf("Failed to init SDL: %s", SDL_GetError());
  }

  window = SDL_CreateWindow("HelloWorld!", 0, 0, 800, 600, SDL_WINDOW_SHOWN);
  if (window == NULL) {
    printf("Failed to init SDL Window: %s", SDL_GetError());
    SDL_Quit();
    return 0;
  }

  ctx = SDL_GL_CreateContext(window);
  if (ctx == NULL) {
    printf("Failed to init SDL GLContext: %s", SDL_GetError());
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
  }

#ifdef __APPLE__
  // MacOSX Mojave hack to display window contents immediately
  SDL_PumpEvents();
#endif

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (renderer == NULL) {
    printf("Failed to init SDL Renderer: %s", SDL_GetError());
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
  }

  is_running = 1;

  double rotated_points[4][2];
  double angle = 90;

  int cx = 400;
  int cy = 300;

  while (is_running != 0) {
    if (SDL_PollEvent(&event) != 0) {
      switch (event.type) {
        case SDL_QUIT:
          printf("Will now quit...\n");
          is_running = 0;
          break;
        default:
          break;
      }
    }

    frame_start = SDL_GetTicks();

    if (++angle > 360) {
      angle = 0;
    }
    rotation(angle, rotated_points);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    SDL_RenderDrawLine(renderer,
                       cx + (int) rotated_points[0][0],
                       cy + (int) rotated_points[0][1],
                       cx + (int) rotated_points[1][0],
                       cy + (int) rotated_points[1][1]);
    SDL_RenderDrawLine(renderer,
                       cx + (int) rotated_points[1][0],
                       cy + (int) rotated_points[1][1],
                       cx + (int) rotated_points[2][0],
                       cy + (int) rotated_points[2][1]);
    SDL_RenderDrawLine(renderer,
                       cx + (int) rotated_points[2][0],
                       cy + (int) rotated_points[2][1],
                       cx + (int) rotated_points[3][0],
                       cy + (int) rotated_points[3][1]);
    SDL_RenderDrawLine(renderer,
                       cx + (int) rotated_points[3][0],
                       cy + (int) rotated_points[3][1],
                       cx + (int) rotated_points[0][0],
                       cy + (int) rotated_points[0][1]);
    SDL_RenderPresent(renderer);

    frame_time = SDL_GetTicks() - frame_start;
    printf("Frame time: %d\n", frame_time);
    if (max_frame_time > frame_time) {
      SDL_Delay(max_frame_time - frame_time);
    }
  }

  return 0;
}

