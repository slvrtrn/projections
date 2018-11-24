
#include <SDL2/SDL.h>
#include "draw.h"

void align_pt(int cx, int cy, const double pt[3], int aligned_pt[2]) {
  aligned_pt[0] = cx + (int) floor(pt[0] * 200);
  aligned_pt[1] = cy + (int) floor(pt[1] * 200);
}

void draw_cube(SDL_Renderer *renderer, double pts[8][3], int cx, int cy) {

  int aligned_pt1[2];
  int aligned_pt2[2];

  // BG
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
  SDL_RenderClear(renderer);

  // Edges
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

  for (size_t i = 0; i < 4; ++i) {
    size_t mod = (i + 1) % 4;

    align_pt(cx, cy, pts[i], aligned_pt1);
    align_pt(cx, cy, pts[mod], aligned_pt2);
    SDL_RenderDrawLine(renderer,
                       aligned_pt1[0],
                       aligned_pt1[1],
                       aligned_pt2[0],
                       aligned_pt2[1]);

    align_pt(cx, cy, pts[i + 4], aligned_pt1);
    align_pt(cx, cy, pts[mod + 4], aligned_pt2);
    SDL_RenderDrawLine(renderer,
                       aligned_pt1[0],
                       aligned_pt1[1],
                       aligned_pt2[0],
                       aligned_pt2[1]);

    align_pt(cx, cy, pts[i], aligned_pt1);
    align_pt(cx, cy, pts[i + 4], aligned_pt2);
    SDL_RenderDrawLine(renderer,
                       aligned_pt1[0],
                       aligned_pt1[1],
                       aligned_pt2[0],
                       aligned_pt2[1]);
  }

  SDL_RenderPresent(renderer);
}

void draw_info(SDL_Renderer *renderer, events_state_t *state) {

}
