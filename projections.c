#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "projections.h"
#include "matrix.h"

void point_to_matrix(const int point[3], double result[3][1]) {
  result[0][0] = point[0];
  result[1][0] = point[1];
  result[3][0] = point[2];
}

void rotation(double angle, double rotated_points[4][2]) {

  int points[4][3] = {
    {-50, -50, 0},
    {50,  -50, 0},
    {50,  50,  0},
    {-50, 50,  0}
  };

  angle = angle * 2 * M_PI / 360;

  double projection[2][3] = {
    {1, 0, 0},
    {0, 1, 0}
  };

  double rotation[2][3] = {
    {cos(angle), -sin(angle), 0},
    {sin(angle), cos(angle),  0}
  };

  for (size_t i = 0; i < 4; i++) {
    double projected[2][1];
    double rotated[2][1];
    double point_matrix[3][1];

    point_to_matrix(points[i], point_matrix);
    multiply(2, 3, 1, projection, point_matrix, projected);
    multiply(2, 3, 1, rotation, point_matrix, rotated);

    printf("Projected: %f %f\n", projected[0][0], projected[1][0]);
    printf("Rotated: %f %f\n", rotated[0][0], rotated[1][0]);
    printf("--------------\n");

    rotated_points[i][0] = rotated[0][0];
    rotated_points[i][1] = rotated[1][0];
  }

}