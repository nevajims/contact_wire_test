//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: linspace.cpp
//
// MATLAB Coder version            : 25.1
// C/C++ source code generated on  : 24-Mar-2026 22:30:21
//

// Include Files
#include "linspace.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <emmintrin.h>

// Function Definitions
//
// Arguments    : double N
//                array<double, 2U> &y
// Return Type  : void
//
namespace coder {
void linspace(double N, array<double, 2U> &y)
{
  double dv[2];
  int i;
  i = static_cast<int>(std::floor(N));
  y.set_size(1, i);
  y[i - 1] = 1.0;
  if (y.size(1) >= 2) {
    y[0] = 0.0;
    if (y.size(1) >= 3) {
      double delta1;
      int scalarLB;
      int vectorUB;
      delta1 = 1.0 / (static_cast<double>(y.size(1)) - 1.0);
      scalarLB = ((y.size(1) - 2) / 2) << 1;
      vectorUB = scalarLB - 2;
      for (int k{0}; k <= vectorUB; k += 2) {
        __m128d r;
        dv[0] = k + 1;
        dv[1] = k + 2;
        r = _mm_loadu_pd(&dv[0]);
        _mm_storeu_pd(&y[k + 1], _mm_mul_pd(r, _mm_set1_pd(delta1)));
      }
      for (int k{scalarLB}; k <= i - 3; k++) {
        y[k + 1] = static_cast<double>(k + 1) * delta1;
      }
    }
  }
}

} // namespace coder

//
// File trailer for linspace.cpp
//
// [EOF]
//
