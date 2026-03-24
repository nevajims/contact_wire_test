//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: round.cpp
//
// MATLAB Coder version            : 25.1
// C/C++ source code generated on  : 24-Mar-2026 22:30:21
//

// Include Files
#include "round.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "omp.h"
#include <cmath>

// Function Definitions
//
// Arguments    : array<double, 1U> &x
// Return Type  : void
//
namespace coder {
void b_round(array<double, 1U> &x)
{
  double b_x;
  int nx;
  nx = x.size(0);
  if (static_cast<int>(nx < 2000)) {
    for (int k{0}; k < nx; k++) {
      b_x = x[k];
      if (std::abs(b_x) < 4.503599627370496E+15) {
        if (b_x >= 0.5) {
          b_x = std::floor(b_x + 0.5);
        } else if (b_x > -0.5) {
          b_x *= 0.0;
        } else {
          b_x = std::ceil(b_x - 0.5);
        }
      }
      x[k] = b_x;
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(b_x)

    for (int k = 0; k < nx; k++) {
      b_x = x[k];
      if (std::abs(b_x) < 4.503599627370496E+15) {
        if (b_x >= 0.5) {
          b_x = std::floor(b_x + 0.5);
        } else if (b_x > -0.5) {
          b_x *= 0.0;
        } else {
          b_x = std::ceil(b_x - 0.5);
        }
      }
      x[k] = b_x;
    }
  }
}

} // namespace coder

//
// File trailer for round.cpp
//
// [EOF]
//
