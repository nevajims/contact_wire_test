//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xnrm2.cpp
//
// MATLAB Coder version            : 25.1
// C/C++ source code generated on  : 24-Mar-2026 22:30:21
//

// Include Files
#include "xnrm2.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Arguments    : int n
//                const array<creal_T, 2U> &x
//                int ix0
// Return Type  : double
//
namespace coder {
namespace internal {
namespace blas {
double xnrm2(int n, const array<creal_T, 2U> &x, int ix0)
{
  double y;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      double scale;
      y = std::abs(x[ix0 - 1].re);
      scale = std::abs(x[ix0 - 1].im);
      if (y < scale) {
        y /= scale;
        y = scale * std::sqrt(y * y + 1.0);
      } else if (y > scale) {
        scale /= y;
        y *= std::sqrt(scale * scale + 1.0);
      } else if (std::isnan(scale)) {
        y = rtNaN;
      } else {
        y *= 1.4142135623730951;
      }
    } else {
      double scale;
      int kend;
      scale = 3.3121686421112381E-170;
      kend = ix0 + n;
      for (int k{ix0}; k < kend; k++) {
        double absxk;
        double t;
        absxk = std::abs(x[k - 1].re);
        if (absxk > scale) {
          t = scale / absxk;
          y = y * t * t + 1.0;
          scale = absxk;
        } else {
          t = absxk / scale;
          y += t * t;
        }
        absxk = std::abs(x[k - 1].im);
        if (absxk > scale) {
          t = scale / absxk;
          y = y * t * t + 1.0;
          scale = absxk;
        } else {
          t = absxk / scale;
          y += t * t;
        }
      }
      y = scale * std::sqrt(y);
    }
  }
  return y;
}

//
// Arguments    : int n
//                const array<creal_T, 1U> &x
//                int ix0
// Return Type  : double
//
double xnrm2(int n, const array<creal_T, 1U> &x, int ix0)
{
  double y;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      double scale;
      y = std::abs(x[ix0 - 1].re);
      scale = std::abs(x[ix0 - 1].im);
      if (y < scale) {
        y /= scale;
        y = scale * std::sqrt(y * y + 1.0);
      } else if (y > scale) {
        scale /= y;
        y *= std::sqrt(scale * scale + 1.0);
      } else if (std::isnan(scale)) {
        y = rtNaN;
      } else {
        y *= 1.4142135623730951;
      }
    } else {
      double scale;
      int kend;
      scale = 3.3121686421112381E-170;
      kend = ix0 + n;
      for (int k{ix0}; k < kend; k++) {
        double absxk;
        double t;
        absxk = std::abs(x[k - 1].re);
        if (absxk > scale) {
          t = scale / absxk;
          y = y * t * t + 1.0;
          scale = absxk;
        } else {
          t = absxk / scale;
          y += t * t;
        }
        absxk = std::abs(x[k - 1].im);
        if (absxk > scale) {
          t = scale / absxk;
          y = y * t * t + 1.0;
          scale = absxk;
        } else {
          t = absxk / scale;
          y += t * t;
        }
      }
      y = scale * std::sqrt(y);
    }
  }
  return y;
}

//
// Arguments    : int n
//                const array<double, 1U> &x
// Return Type  : double
//
double xnrm2(int n, const array<double, 1U> &x)
{
  double y;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = std::abs(x[1]);
    } else {
      double scale;
      int kend;
      scale = 3.3121686421112381E-170;
      kend = n + 1;
      for (int k{2}; k <= kend; k++) {
        double absxk;
        absxk = std::abs(x[k - 1]);
        if (absxk > scale) {
          double t;
          t = scale / absxk;
          y = y * t * t + 1.0;
          scale = absxk;
        } else {
          double t;
          t = absxk / scale;
          y += t * t;
        }
      }
      y = scale * std::sqrt(y);
    }
  }
  return y;
}

} // namespace blas
} // namespace internal
} // namespace coder

//
// File trailer for xnrm2.cpp
//
// [EOF]
//
