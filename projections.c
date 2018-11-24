#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include "projections.h"
#include "debug.h"

#define RADS_COEFF 2 * M_PI / 360

void rotate_x(double angle, double pt[3]) {
  double y = pt[1];
  double z = pt[2];
  pt[1] = y * cos(angle) - z * sin(angle);
  pt[2] = y * sin(angle) + z * cos(angle);
}

void rotate_y(double angle, double pt[3]) {
  double x = pt[0];
  double z = pt[2];
  pt[0] = x * cos(angle) + z * sin(angle);
  pt[2] = z * cos(angle) - x * sin(angle);
}

void rotate_z(double angle, double pt[3]) {
  double x = pt[0];
  double y = pt[1];
  pt[0] = x * cos(angle) - y * sin(angle);
  pt[1] = x * sin(angle) + y * cos(angle);
}

void project(double distance, double pt[3]) {
  double z = 1 / (distance - pt[2] / 2);
  pt[0] = pt[0] * z;
  pt[1] = pt[1] * z;
}

void rotation(rotation_params_t *params) {

  memcpy(params->current_pts, params->init_pts, sizeof(params->init_pts));

  double x_angle_rads = params->x_angle * RADS_COEFF;
  double y_angle_rads = params->y_angle * RADS_COEFF;
  double z_angle_rads = params->z_angle * RADS_COEFF;

  for (size_t i = 0; i < 8; i++) {

    rotate_x(x_angle_rads, params->current_pts[i]);
    rotate_y(y_angle_rads, params->current_pts[i]);
    rotate_z(z_angle_rads, params->current_pts[i]);

#if DEBUG
    printf("Angles: %f %f %f, Rotated: %f %f %f\n",
           params->x_angle, params->y_angle, params->z_angle,
           (params->current_pts[i])[0], (params->current_pts[i])[1], (params->current_pts[i])[2]);
#endif

    project(params->distance, params->current_pts[i]);

#if DEBUG
    printf("Angles: %f %f %f, Projected: %f %f %f\n",
           params->x_angle, params->y_angle, params->z_angle,
           (params->current_pts[i])[0], (params->current_pts[i])[1], (params->current_pts[i])[2]);
#endif
  }
}
