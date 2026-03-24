//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: mpower.cpp
//
// MATLAB Coder version            : 25.1
// C/C++ source code generated on  : 24-Mar-2026 22:30:21
//

// Include Files
#include "mpower.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions
//
// Arguments    : double b
// Return Type  : double
//
namespace coder {
double mpower(double b)
{
  double c;
  if (std::isnan(b)) {
    c = rtNaN;
  } else {
    c = std::abs(b);
    if (std::isinf(b)) {
      if (b > 0.0) {
        c = rtInf;
      } else {
        c = 0.0;
      }
    } else if (c == 0.0) {
      c = 1.0;
    } else if (c == 1.0) {
      if (b > 0.0) {
        c = 2.0;
      } else {
        c = 0.5;
      }
    } else if (b == 2.0) {
      c = 4.0;
    } else if (b == 0.5) {
      c = 1.4142135623730951;
    } else {
      c = std::pow(2.0, b);
    }
  }
  return c;
}

} // namespace coder

//
// File trailer for mpower.cpp
//
// [EOF]
//
