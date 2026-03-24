//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: nextpow2.cpp
//
// MATLAB Coder version            : 25.1
// C/C++ source code generated on  : 24-Mar-2026 22:30:21
//

// Include Files
#include "nextpow2.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions
//
// Arguments    : double n
// Return Type  : double
//
namespace coder {
double nextpow2(double n)
{
  double f;
  double p;
  int eint;
  f = std::frexp(std::abs(n), &eint);
  p = eint;
  if (f == 0.5) {
    p = static_cast<double>(eint) - 1.0;
  }
  return p;
}

} // namespace coder

//
// File trailer for nextpow2.cpp
//
// [EOF]
//
