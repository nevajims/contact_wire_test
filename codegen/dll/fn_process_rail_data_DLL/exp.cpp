//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: exp.cpp
//
// MATLAB Coder version            : 25.1
// C/C++ source code generated on  : 24-Mar-2026 22:30:21
//

// Include Files
#include "exp.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "omp.h"
#include <cmath>

// Function Definitions
//
// Arguments    : array<double, 1U> &x
// Return Type  : void
//
namespace coder {
void b_exp(array<double, 1U> &x)
{
  int nx;
  nx = x.size(0);
  if (static_cast<int>(nx < 2000)) {
    for (int k{0}; k < nx; k++) {
      x[k] = std::exp(x[k]);
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int k = 0; k < nx; k++) {
      x[k] = std::exp(x[k]);
    }
  }
}

//
// Arguments    : creal_T &x
// Return Type  : void
//
void b_exp(creal_T &x)
{
  if (x.re == 0.0) {
    double r;
    r = x.im;
    x.re = std::cos(r);
    x.im = std::sin(r);
  } else if (x.im == 0.0) {
    x.re = std::exp(x.re);
    x.im = 0.0;
  } else if (std::isinf(x.im) && std::isinf(x.re) && (x.re < 0.0)) {
    x.re = 0.0;
    x.im = 0.0;
  } else {
    double d;
    double r;
    r = std::exp(x.re / 2.0);
    d = x.im;
    x.re = r * (r * std::cos(d));
    x.im = r * (r * std::sin(d));
  }
}

//
// Arguments    : array<creal_T, 1U> &x
// Return Type  : void
//
void b_exp(array<creal_T, 1U> &x)
{
  creal_T dc;
  double d1;
  double r;
  int nx;
  nx = x.size(0);
  if (static_cast<int>(nx < 2000)) {
    for (int k{0}; k < nx; k++) {
      dc = x[k];
      if (dc.re == 0.0) {
        double d;
        d = dc.im;
        dc.re = std::cos(d);
        dc.im = std::sin(d);
        x[k] = dc;
      } else if (dc.im == 0.0) {
        double d;
        d = dc.re;
        dc.re = std::exp(d);
        dc.im = 0.0;
        x[k] = dc;
      } else if (std::isinf(dc.im) && std::isinf(dc.re) && (dc.re < 0.0)) {
        x[k].re = 0.0;
        x[k].im = 0.0;
      } else {
        double d;
        r = std::exp(dc.re / 2.0);
        d = dc.im;
        dc.re = r * (r * std::cos(d));
        dc.im = r * (r * std::sin(d));
        x[k] = dc;
      }
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(r, dc, d1)

    for (int k = 0; k < nx; k++) {
      dc = x[k];
      if (dc.re == 0.0) {
        d1 = dc.im;
        dc.re = std::cos(d1);
        dc.im = std::sin(d1);
        x[k] = dc;
      } else if (dc.im == 0.0) {
        d1 = dc.re;
        dc.re = std::exp(d1);
        dc.im = 0.0;
        x[k] = dc;
      } else if (std::isinf(dc.im) && std::isinf(dc.re) && (dc.re < 0.0)) {
        dc.re = 0.0;
        dc.im = 0.0;
        x[k] = dc;
      } else {
        r = std::exp(dc.re / 2.0);
        d1 = dc.im;
        dc.re = r * (r * std::cos(d1));
        dc.im = r * (r * std::sin(d1));
        x[k] = dc;
      }
    }
  }
}

} // namespace coder

//
// File trailer for exp.cpp
//
// [EOF]
//
