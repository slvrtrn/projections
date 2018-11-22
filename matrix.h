

#ifndef PROJECTIONS_MATRIX_H
#define PROJECTIONS_MATRIX_H

#include <stdlib.h>

void multiply(size_t m, size_t n, size_t k,
              double a[n][m], double b[m][k], double res[n][k]);

#endif //PROJECTIONS_MATRIX_H
