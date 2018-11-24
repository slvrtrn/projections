

#include "events.h"

#ifndef PROJECTIONS_DRAW_H
#define PROJECTIONS_DRAW_H

void draw_cube(SDL_Renderer *renderer, double pts[8][3], int center_x, int center_y);

void draw_info(SDL_Renderer *renderer, events_state_t *state);

#endif //PROJECTIONS_DRAW_H
