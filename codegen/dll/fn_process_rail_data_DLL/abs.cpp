//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: abs.cpp
//
// MATLAB Coder version            : 25.1
// C/C++ source code generated on  : 24-Mar-2026 22:30:21
//

// Include Files
#include "abs.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "omp.h"
#include <cmath>

// Function Definitions
//
// Arguments    : const array<double, 2U> &x
//                array<double, 2U> &y
// Return Type  : void
//
namespace coder {
void b_abs(const array<double, 2U> &x, array<double, 2U> &y)
{
  int nx;
  nx = x.size(1);
  y.set_size(1, x.size(1));
  if (static_cast<int>(x.size(1) < 2000)) {
    for (int k{0}; k < nx; k++) {
      y[k] = std::abs(x[k]);
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int k = 0; k < nx; k++) {
      y[k] = std::abs(x[k]);
    }
  }
}

//
// Arguments    : const array<double, 1U> &x
//                array<double, 1U> &y
// Return Type  : void
//
void b_abs(const array<double, 1U> &x, array<double, 1U> &y)
{
  int nx;
  nx = x.size(0);
  y.set_size(x.size(0));
  if (static_cast<int>(x.size(0) < 2000)) {
    for (int k{0}; k < nx; k++) {
      y[k] = std::abs(x[k]);
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int k = 0; k < nx; k++) {
      y[k] = std::abs(x[k]);
    }
  }
}

//
// Arguments    : const creal_T x
// Return Type  : double
//
double b_abs(const creal_T x)
{
  double b;
  double y;
  y = std::abs(x.re);
  b = std::abs(x.im);
  if (y < b) {
    y /= b;
    y = b * std::sqrt(y * y + 1.0);
  } else if (y > b) {
    b /= y;
    y *= std::sqrt(b * b + 1.0);
  } else if (std::isnan(b)) {
    y = rtNaN;
  } else {
    y *= 1.4142135623730951;
  }
  return y;
}

//
// Arguments    : const array<creal_T, 2U> &x
//                array<double, 2U> &y
// Return Type  : void
//
void b_abs(const array<creal_T, 2U> &x, array<double, 2U> &y)
{
  double a;
  double b;
  int nx;
  nx = x.size(0) * x.size(1);
  y.set_size(x.size(0), x.size(1));
  if (static_cast<int>(nx < 2000)) {
    for (int k{0}; k < nx; k++) {
      a = std::abs(x[k].re);
      b = std::abs(x[k].im);
      if (a < b) {
        a /= b;
        y[k] = b * std::sqrt(a * a + 1.0);
      } else if (a > b) {
        b /= a;
        y[k] = a * std::sqrt(b * b + 1.0);
      } else if (std::isnan(b)) {
        y[k] = rtNaN;
      } else {
        y[k] = a * 1.4142135623730951;
      }
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(b, a)

    for (int k = 0; k < nx; k++) {
      a = std::abs(x[k].re);
      b = std::abs(x[k].im);
      if (a < b) {
        a /= b;
        y[k] = b * std::sqrt(a * a + 1.0);
      } else if (a > b) {
        b /= a;
        y[k] = a * std::sqrt(b * b + 1.0);
      } else if (std::isnan(b)) {
        y[k] = rtNaN;
      } else {
        y[k] = a * 1.4142135623730951;
      }
    }
  }
}

//
// Arguments    : const array<creal_T, 1U> &x
//                array<double, 1U> &y
// Return Type  : void
//
void b_abs(const array<creal_T, 1U> &x, array<double, 1U> &y)
{
  double a;
  double b;
  int nx;
  nx = x.size(0);
  y.set_size(x.size(0));
  if (static_cast<int>(x.size(0) < 2000)) {
    for (int k{0}; k < nx; k++) {
      a = std::abs(x[k].re);
      b = std::abs(x[k].im);
      if (a < b) {
        a /= b;
        y[k] = b * std::sqrt(a * a + 1.0);
      } else if (a > b) {
        b /= a;
        y[k] = a * std::sqrt(b * b + 1.0);
      } else if (std::isnan(b)) {
        y[k] = rtNaN;
      } else {
        y[k] = a * 1.4142135623730951;
      }
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(b, a)

    for (int k = 0; k < nx; k++) {
      a = std::abs(x[k].re);
      b = std::abs(x[k].im);
      if (a < b) {
        a /= b;
        y[k] = b * std::sqrt(a * a + 1.0);
      } else if (a > b) {
        b /= a;
        y[k] = a * std::sqrt(b * b + 1.0);
      } else if (std::isnan(b)) {
        y[k] = rtNaN;
      } else {
        y[k] = a * 1.4142135623730951;
      }
    }
  }
}

} // namespace coder

//
// File trailer for abs.cpp
//
// [EOF]
//
