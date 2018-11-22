

#include "matrix.h"
#include <stdio.h>

void multiply(size_t m, size_t n, size_t k,
              double a[m][n], double b[n][k], double res[m][k]) {

  for (size_t mc = 0; mc < m; mc++) {
    for (size_t kc = 0; kc < k; kc++) {
      float r = 0;
      for (size_t nc = 0; nc < n; nc++) {
        r += a[mc][nc] * b[nc][kc];
      }
      res[mc][kc] = r;
    }
  }
}

