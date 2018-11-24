

#ifndef PROJECTIONS_PROJECTIONS_H
#define PROJECTIONS_PROJECTIONS_H

#include <stdbool.h>

typedef struct {
  double x_angle;
  double y_angle;
  double z_angle;
  double init_pts[8][3];
  double current_pts[8][3];
  double distance;
} rotation_params_t;

void rotation(rotation_params_t *params);

#endif //PROJECTIONS_PROJECTIONS_H
