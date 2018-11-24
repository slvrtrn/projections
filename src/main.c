#include <stdio.h>
#include <SDL2/SDL.h>
#include "projections.h"
#include "draw.h"
#include "rendering.h"
#include "events.h"
#include "processing.h"


int main() {

  int is_running = 0;

  double pts[8][3] = {
    {-0.5, -0.5, 0.5},
    {0.5,  -0.5, 0.5},
    {0.5,  0.5,  0.5},
    {-0.5, 0.5,  0.5},
    {-0.5, -0.5, -0.5},
    {0.5,  -0.5, -0.5},
    {0.5,  0.5,  -0.5},
    {-0.5, 0.5,  -0.5}
  };

  sdl_rendering_t *sdl = init(800, 600);
  if (sdl != NULL) {
    is_running = 1;
  } else {
    printf("Failed to init SDL, will now quit...\n");
    return 0;
  }

  events_state_t *state = malloc(sizeof(events_state_t));
  rotation_params_t *params = malloc(sizeof(rotation_params_t));
  memcpy(params->init_pts, pts, sizeof(params->init_pts));

  init_params(params);
  init_events_state(state);

  while (is_running != 0) {
    process_frame_logic(sdl, &is_running, state, params);
    delay_frame(sdl);
  }

  shutdown(sdl);
  return 0;
}

