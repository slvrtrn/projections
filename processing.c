

#include "processing.h"
#include "events.h"
#include "rendering.h"
#include "draw.h"

static const float ANGLE_STEP = 0.5;
static const float DISTANCE_STEP = 0.005;

static const int MAX_ANGLE = 360;
static const int INIT_ANGLE = 0;
static const int INIT_DISTANCE = 1;

void incr_angle(double *angle) {
  *angle = *angle + ANGLE_STEP;
  if (*angle > MAX_ANGLE) {
    *angle = INIT_ANGLE;
  }
}

void incr_distance(double *distance) {
  *distance += DISTANCE_STEP;
}

void decr_distance(double *distance) {
  *distance -= DISTANCE_STEP;
}

void process_frame_logic(sdl_rendering_t *sdl, int *is_running, events_state_t *state, rotation_params_t *params) {

  process_events(sdl->event, is_running, state);

  if (state->rotate_x) {
    incr_angle(&params->x_angle);
  }
  if (state->rotate_y) {
    incr_angle(&params->y_angle);
  }
  if (state->rotate_z) {
    incr_angle(&params->z_angle);
  }

  if (state->move & MOVE_IN) {
    decr_distance(&params->distance);
  }
  if (state->move & MOVE_OUT) {
    incr_distance(&params->distance);
  }

  rotation(params);

  draw_cube(sdl->renderer, params->current_pts, sdl->cx, sdl->cy);
  draw_info(sdl->renderer, state);
}

void init_params(rotation_params_t *params) {
  params->x_angle = INIT_ANGLE;
  params->y_angle = INIT_ANGLE;
  params->z_angle = INIT_ANGLE;
  params->distance = INIT_DISTANCE;
}
