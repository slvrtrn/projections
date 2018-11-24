

#include "events.h"
#include "processing.h"

void process_events(SDL_Event *event, int *is_running, events_state_t *state) {
  if (SDL_PollEvent(event) != 0) {
    switch (event->type) {
      case SDL_QUIT:
        printf("Received a signal to quit\n");
        *is_running = 0;
        break;
      case SDL_KEYDOWN:
        switch (event->key.keysym.sym) {
          case SDLK_x:
            state->rotate_x = !state->rotate_x;
            break;
          case SDLK_y:
            state->rotate_y = !state->rotate_y;
            break;
          case SDLK_z:
            state->rotate_z = !state->rotate_z;
            break;
          case SDLK_UP:
            state->move = MOVE_IN;
            break;
          case SDLK_DOWN:
            state->move = MOVE_OUT;
            break;
          case SDLK_SPACE:
            state->move = 0;
            break;
          default:
            break;
        }
        break;
      default:
        break;
    }
  }
}

void init_events_state(events_state_t *state) {
  state->rotate_z = 1;
  state->rotate_y = 1;
  state->rotate_x = 1;
  state->move = 0;
}
