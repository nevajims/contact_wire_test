/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: linspace.c
 *
 * MATLAB Coder version            : 25.1
 * C/C++ source code generated on  : 12-Mar-2026 17:25:15
 */

/* Include Files */
#include "linspace.h"
#include <emmintrin.h>

/* Function Definitions */
/*
 * Arguments    : double y[3158]
 * Return Type  : void
 */
void linspace(double y[3158])
{
  double dv[2];
  int k;
  y[3157] = 8.0;
  y[0] = 0.0;
  for (k = 0; k <= 3154; k += 2) {
    __m128d r;
    dv[0] = (double)k + 1.0;
    dv[1] = (double)k + 2.0;
    r = _mm_loadu_pd(&dv[0]);
    _mm_storeu_pd(&y[k + 1], _mm_mul_pd(r, _mm_set1_pd(0.0025340513145391194)));
  }
}

/*
 * File trailer for linspace.c
 *
 * [EOF]
 */
