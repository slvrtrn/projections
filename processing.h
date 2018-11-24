

#ifndef PROJECTIONS_ANGLE_H
#define PROJECTIONS_ANGLE_H

#include "rendering.h"
#include "events.h"

void init_params(rotation_params_t *params);

void process_frame_logic(sdl_rendering_t *sdl, int *is_running, events_state_t *state, rotation_params_t *params);

#endif //PROJECTIONS_ANGLE_H
