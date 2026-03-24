//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: pchip.cpp
//
// MATLAB Coder version            : 25.1
// C/C++ source code generated on  : 24-Mar-2026 22:30:21
//

// Include Files
#include "pchip.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions
//
// Arguments    : double d1
//                double d2
//                double h1
//                double h2
// Return Type  : double
//
namespace coder {
double realExteriorSlope(double d1, double d2, double h1, double h2)
{
  double d;
  double s;
  double signd1;
  s = ((2.0 * h1 + h2) * d1 - h1 * d2) / (h1 + h2);
  if (std::isnan(d1)) {
    signd1 = rtNaN;
  } else if (d1 < 0.0) {
    signd1 = -1.0;
  } else {
    signd1 = (d1 > 0.0);
  }
  if (std::isnan(s)) {
    d = rtNaN;
  } else if (s < 0.0) {
    d = -1.0;
  } else {
    d = (s > 0.0);
  }
  if (d != signd1) {
    s = 0.0;
  } else {
    if (std::isnan(d2)) {
      d = rtNaN;
    } else if (d2 < 0.0) {
      d = -1.0;
    } else {
      d = (d2 > 0.0);
    }
    if (signd1 != d) {
      d = 3.0 * d1;
      if (std::abs(s) > std::abs(d)) {
        s = d;
      }
    }
  }
  return s;
}

} // namespace coder

//
// File trailer for pchip.cpp
//
// [EOF]
//
