//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xaxpy.cpp
//
// MATLAB Coder version            : 25.1
// C/C++ source code generated on  : 24-Mar-2026 22:30:21
//

// Include Files
#include "xaxpy.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "omp.h"

// Function Definitions
//
// Arguments    : int n
//                const creal_T a
//                const array<creal_T, 2U> &x
//                int ix0
//                array<creal_T, 1U> &y
//                int iy0
// Return Type  : void
//
namespace coder {
namespace internal {
namespace blas {
void xaxpy(int n, const creal_T a, const array<creal_T, 2U> &x, int ix0,
           array<creal_T, 1U> &y, int iy0)
{
  double d_a_re_tmp;
  double e_a_re_tmp;
  int c_a_re_tmp;
  if ((n >= 1) && ((!(a.re == 0.0)) || (!(a.im == 0.0)))) {
    int ix;
    int iy;
    ix = ix0 - 1;
    iy = iy0 - 1;
    if (static_cast<int>(n < 2000)) {
      for (int k{0}; k < n; k++) {
        double a_re_tmp;
        double b_a_re_tmp;
        ix = (ix0 + k) - 1;
        a_re_tmp = x[ix].im;
        b_a_re_tmp = x[ix].re;
        ix = (iy0 + k) - 1;
        y[ix].re = y[ix].re + (a.re * b_a_re_tmp - a.im * a_re_tmp);
        y[ix].im = y[ix].im + (a.re * a_re_tmp + a.im * b_a_re_tmp);
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
        c_a_re_tmp, d_a_re_tmp, e_a_re_tmp)

      for (int k = 0; k < n; k++) {
        c_a_re_tmp = ix + k;
        d_a_re_tmp = x[c_a_re_tmp].im;
        e_a_re_tmp = x[c_a_re_tmp].re;
        c_a_re_tmp = iy + k;
        y[c_a_re_tmp].re =
            y[c_a_re_tmp].re + (a.re * e_a_re_tmp - a.im * d_a_re_tmp);
        y[c_a_re_tmp].im =
            y[c_a_re_tmp].im + (a.re * d_a_re_tmp + a.im * e_a_re_tmp);
      }
    }
  }
}

//
// Arguments    : int n
//                const creal_T a
//                const array<creal_T, 1U> &x
//                int ix0
//                array<creal_T, 2U> &y
//                int iy0
// Return Type  : void
//
void xaxpy(int n, const creal_T a, const array<creal_T, 1U> &x, int ix0,
           array<creal_T, 2U> &y, int iy0)
{
  double d_a_re_tmp;
  double e_a_re_tmp;
  int c_a_re_tmp;
  if ((n >= 1) && ((!(a.re == 0.0)) || (!(a.im == 0.0)))) {
    int ix;
    int iy;
    ix = ix0 - 1;
    iy = iy0 - 1;
    if (static_cast<int>(n < 2000)) {
      for (int k{0}; k < n; k++) {
        double a_re_tmp;
        double b_a_re_tmp;
        ix = (ix0 + k) - 1;
        a_re_tmp = x[ix].im;
        b_a_re_tmp = x[ix].re;
        ix = (iy0 + k) - 1;
        y[ix].re = y[ix].re + (a.re * b_a_re_tmp - a.im * a_re_tmp);
        y[ix].im = y[ix].im + (a.re * a_re_tmp + a.im * b_a_re_tmp);
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
        c_a_re_tmp, d_a_re_tmp, e_a_re_tmp)

      for (int k = 0; k < n; k++) {
        c_a_re_tmp = ix + k;
        d_a_re_tmp = x[c_a_re_tmp].im;
        e_a_re_tmp = x[c_a_re_tmp].re;
        c_a_re_tmp = iy + k;
        y[c_a_re_tmp].re =
            y[c_a_re_tmp].re + (a.re * e_a_re_tmp - a.im * d_a_re_tmp);
        y[c_a_re_tmp].im =
            y[c_a_re_tmp].im + (a.re * d_a_re_tmp + a.im * e_a_re_tmp);
      }
    }
  }
}

//
// Arguments    : int n
//                const creal_T a
//                int ix0
//                array<creal_T, 2U> &y
//                int iy0
// Return Type  : void
//
void xaxpy(int n, const creal_T a, int ix0, array<creal_T, 2U> &y, int iy0)
{
  if ((n >= 1) && ((!(a.re == 0.0)) || (!(a.im == 0.0)))) {
    for (int k{0}; k < n; k++) {
      double b_a_re_tmp;
      double c_a_re_tmp;
      int a_re_tmp;
      a_re_tmp = (ix0 + k) - 1;
      b_a_re_tmp = y[a_re_tmp].im;
      c_a_re_tmp = y[a_re_tmp].re;
      a_re_tmp = (iy0 + k) - 1;
      y[a_re_tmp].re = y[a_re_tmp].re + (a.re * c_a_re_tmp - a.im * b_a_re_tmp);
      y[a_re_tmp].im = y[a_re_tmp].im + (a.re * b_a_re_tmp + a.im * c_a_re_tmp);
    }
  }
}

} // namespace blas
} // namespace internal
} // namespace coder

//
// File trailer for xaxpy.cpp
//
// [EOF]
//
