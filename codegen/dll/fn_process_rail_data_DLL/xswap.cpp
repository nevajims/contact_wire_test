//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xswap.cpp
//
// MATLAB Coder version            : 25.1
// C/C++ source code generated on  : 24-Mar-2026 22:30:21
//

// Include Files
#include "xswap.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : int n
//                array<creal_T, 2U> &x
//                int ix0
//                int iy0
// Return Type  : void
//
namespace coder {
namespace internal {
namespace blas {
void xswap(int n, array<creal_T, 2U> &x, int ix0, int iy0)
{
  for (int k{0}; k < n; k++) {
    double temp_im;
    double temp_re;
    int i;
    int temp_re_tmp;
    temp_re_tmp = (ix0 + k) - 1;
    temp_re = x[temp_re_tmp].re;
    temp_im = x[temp_re_tmp].im;
    i = (iy0 + k) - 1;
    x[temp_re_tmp] = x[i];
    x[i].re = temp_re;
    x[i].im = temp_im;
  }
}

} // namespace blas
} // namespace internal
} // namespace coder

//
// File trailer for xswap.cpp
//
// [EOF]
//
