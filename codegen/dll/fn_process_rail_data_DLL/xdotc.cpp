//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xdotc.cpp
//
// MATLAB Coder version            : 25.1
// C/C++ source code generated on  : 24-Mar-2026 22:30:21
//

// Include Files
#include "xdotc.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : int n
//                const array<creal_T, 2U> &x
//                int ix0
//                const array<creal_T, 2U> &y
//                int iy0
// Return Type  : creal_T
//
namespace coder {
namespace internal {
namespace blas {
creal_T xdotc(int n, const array<creal_T, 2U> &x, int ix0,
              const array<creal_T, 2U> &y, int iy0)
{
  creal_T d;
  d.re = 0.0;
  d.im = 0.0;
  if (n >= 1) {
    for (int k{0}; k < n; k++) {
      double b_im;
      double b_re;
      double im;
      double re;
      int re_tmp;
      re_tmp = (ix0 + k) - 1;
      re = x[re_tmp].re;
      im = x[re_tmp].im;
      re_tmp = (iy0 + k) - 1;
      b_re = y[re_tmp].re;
      b_im = y[re_tmp].im;
      d.re += re * b_re + im * b_im;
      d.im += re * b_im - im * b_re;
    }
  }
  return d;
}

} // namespace blas
} // namespace internal
} // namespace coder

//
// File trailer for xdotc.cpp
//
// [EOF]
//
