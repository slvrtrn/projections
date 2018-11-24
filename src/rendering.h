

#ifndef PROJECTIONS_RENDERING_H
#define PROJECTIONS_RENDERING_H

#include <SDL2/SDL.h>

typedef struct {
  SDL_Window *window;
  SDL_Renderer *renderer;
  SDL_GLContext *ctx;
  SDL_Event *event;
  uint32_t frame_start;
  uint32_t frame_time;
  int cx;
  int cy;
} sdl_rendering_t;

sdl_rendering_t *init(int w, int h);

void shutdown(sdl_rendering_t *sdl);

void delay_frame(sdl_rendering_t *sdl);

#endif //PROJECTIONS_RENDERING_H
