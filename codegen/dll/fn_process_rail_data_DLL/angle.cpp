//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: angle.cpp
//
// MATLAB Coder version            : 25.1
// C/C++ source code generated on  : 24-Mar-2026 22:30:21
//

// Include Files
#include "angle.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "omp.h"
#include "rt_defines.h"
#include <cmath>

// Function Definitions
//
// Arguments    : const array<creal_T, 2U> &x
//                array<double, 2U> &y
// Return Type  : void
//
namespace coder {
void angle(const array<creal_T, 2U> &x, array<double, 2U> &y)
{
  double u0;
  double u1;
  int i;
  int i1;
  int nx;
  nx = x.size(0) * x.size(1);
  y.set_size(x.size(0), x.size(1));
  if (static_cast<int>(nx < 2000)) {
    for (int k{0}; k < nx; k++) {
      u0 = x[k].im;
      u1 = x[k].re;
      if (std::isnan(u0) || std::isnan(u1)) {
        y[k] = rtNaN;
      } else if (std::isinf(u0) && std::isinf(u1)) {
        int i2;
        int i3;
        if (u0 > 0.0) {
          i2 = 1;
        } else {
          i2 = -1;
        }
        if (u1 > 0.0) {
          i3 = 1;
        } else {
          i3 = -1;
        }
        y[k] = std::atan2(static_cast<double>(i2), static_cast<double>(i3));
      } else if (u1 == 0.0) {
        if (u0 > 0.0) {
          y[k] = RT_PI / 2.0;
        } else if (u0 < 0.0) {
          y[k] = -(RT_PI / 2.0);
        } else {
          y[k] = 0.0;
        }
      } else {
        y[k] = std::atan2(u0, u1);
      }
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i, i1, u1, \
                                                                        u0)

    for (int k = 0; k < nx; k++) {
      u0 = x[k].im;
      u1 = x[k].re;
      if (std::isnan(u0) || std::isnan(u1)) {
        y[k] = rtNaN;
      } else if (std::isinf(u0) && std::isinf(u1)) {
        if (u1 > 0.0) {
          i1 = 1;
        } else {
          i1 = -1;
        }
        if (u0 > 0.0) {
          i = 1;
        } else {
          i = -1;
        }
        y[k] = std::atan2(static_cast<double>(i), static_cast<double>(i1));
      } else if (u1 == 0.0) {
        if (u0 > 0.0) {
          y[k] = RT_PI / 2.0;
        } else if (u0 < 0.0) {
          y[k] = -(RT_PI / 2.0);
        } else {
          y[k] = 0.0;
        }
      } else {
        y[k] = std::atan2(u0, u1);
      }
    }
  }
}

} // namespace coder

//
// File trailer for angle.cpp
//
// [EOF]
//
