//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xzlangeM.cpp
//
// MATLAB Coder version            : 25.1
// C/C++ source code generated on  : 24-Mar-2026 22:30:21
//

// Include Files
#include "xzlangeM.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Arguments    : const array<creal_T, 2U> &x
// Return Type  : double
//
namespace coder {
namespace internal {
namespace reflapack {
double xzlangeM(const array<creal_T, 2U> &x)
{
  double y;
  boolean_T b;
  boolean_T b1;
  y = 0.0;
  b = (x.size(0) == 0);
  b1 = (x.size(1) == 0);
  if ((!b) && (!b1)) {
    int k;
    boolean_T exitg1;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= x.size(0) * x.size(1) - 1)) {
      double absxk;
      double b_b;
      absxk = std::abs(x[k].re);
      b_b = std::abs(x[k].im);
      if (absxk < b_b) {
        absxk /= b_b;
        absxk = b_b * std::sqrt(absxk * absxk + 1.0);
      } else if (absxk > b_b) {
        b_b /= absxk;
        absxk *= std::sqrt(b_b * b_b + 1.0);
      } else if (std::isnan(b_b)) {
        absxk = rtNaN;
      } else {
        absxk *= 1.4142135623730951;
      }
      if (std::isnan(absxk)) {
        y = rtNaN;
        exitg1 = true;
      } else {
        if (absxk > y) {
          y = absxk;
        }
        k++;
      }
    }
  }
  return y;
}

} // namespace reflapack
} // namespace internal
} // namespace coder

//
// File trailer for xzlangeM.cpp
//
// [EOF]
//
