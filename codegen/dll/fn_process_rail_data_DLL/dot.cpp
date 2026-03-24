//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: dot.cpp
//
// MATLAB Coder version            : 25.1
// C/C++ source code generated on  : 24-Mar-2026 22:30:21
//

// Include Files
#include "dot.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const creal_T a[3]
//                const array<double, 2U> &b
// Return Type  : creal_T
//
namespace coder {
creal_T dot(const creal_T a[3], const array<double, 2U> &b)
{
  creal_T c;
  double d;
  d = b[0];
  c.re = a[0].re * d;
  c.im = a[0].im * -d;
  d = b[1];
  c.re += a[1].re * d;
  c.im += a[1].im * -d;
  d = b[2];
  c.re += a[2].re * d;
  c.im += a[2].im * -d;
  return c;
}

} // namespace coder

//
// File trailer for dot.cpp
//
// [EOF]
//
