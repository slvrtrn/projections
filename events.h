

#ifndef PROJECTIONS_EVENTS_H
#define PROJECTIONS_EVENTS_H

#include <SDL2/SDL_events.h>
#include "projections.h"

typedef struct {
  int rotate_x;
  int rotate_y;
  int rotate_z;
  int8_t move;
} events_state_t;

typedef enum MOVE {
  MOVE_IN = (1 << 0),
  MOVE_OUT = (1 << 1)
} MOVE;

void init_events_state(events_state_t *state);

void process_events(SDL_Event *event, int *is_running, events_state_t *state);

#endif //PROJECTIONS_EVENTS_H
