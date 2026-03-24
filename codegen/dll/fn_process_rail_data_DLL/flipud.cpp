//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: flipud.cpp
//
// MATLAB Coder version            : 25.1
// C/C++ source code generated on  : 24-Mar-2026 22:30:21
//

// Include Files
#include "flipud.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : array<double, 1U> &x
// Return Type  : void
//
namespace coder {
void flipud(array<double, 1U> &x)
{
  int m;
  int md2;
  m = x.size(0) - 1;
  md2 = x.size(0) >> 1;
  for (int i{0}; i < md2; i++) {
    double xtmp;
    int b_i;
    xtmp = x[i];
    b_i = m - i;
    x[i] = x[b_i];
    x[b_i] = xtmp;
  }
}

} // namespace coder

//
// File trailer for flipud.cpp
//
// [EOF]
//
