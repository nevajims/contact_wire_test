//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xrot.cpp
//
// MATLAB Coder version            : 25.1
// C/C++ source code generated on  : 24-Mar-2026 22:30:21
//

// Include Files
#include "xrot.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : int n
//                array<creal_T, 2U> &x
//                int ix0
//                int iy0
//                double c
//                double s
// Return Type  : void
//
namespace coder {
namespace internal {
namespace blas {
void xrot(int n, array<creal_T, 2U> &x, int ix0, int iy0, double c, double s)
{
  if (n >= 1) {
    for (int k{0}; k < n; k++) {
      double b_s_re_tmp;
      double b_temp_re_tmp;
      double c_s_re_tmp;
      double temp_im_tmp;
      int s_re_tmp;
      int temp_re_tmp;
      s_re_tmp = (iy0 + k) - 1;
      b_s_re_tmp = x[s_re_tmp].im;
      c_s_re_tmp = x[s_re_tmp].re;
      temp_re_tmp = (ix0 + k) - 1;
      b_temp_re_tmp = x[temp_re_tmp].re;
      temp_im_tmp = x[temp_re_tmp].im;
      x[s_re_tmp].re = c * c_s_re_tmp - (s * b_temp_re_tmp - 0.0 * temp_im_tmp);
      x[s_re_tmp].im =
          c * x[s_re_tmp].im - (s * temp_im_tmp + 0.0 * b_temp_re_tmp);
      x[temp_re_tmp].re =
          c * b_temp_re_tmp + (s * c_s_re_tmp - 0.0 * b_s_re_tmp);
      x[temp_re_tmp].im = c * temp_im_tmp + (s * b_s_re_tmp + 0.0 * c_s_re_tmp);
    }
  }
}

} // namespace blas
} // namespace internal
} // namespace coder

//
// File trailer for xrot.cpp
//
// [EOF]
//
