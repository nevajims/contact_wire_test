//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: minOrMax.cpp
//
// MATLAB Coder version            : 25.1
// C/C++ source code generated on  : 24-Mar-2026 22:30:21
//

// Include Files
#include "minOrMax.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Arguments    : const double x[2]
// Return Type  : double
//
namespace coder {
namespace internal {
double maximum(const double x[2])
{
  double ex;
  if ((x[0] < x[1]) || (std::isnan(x[0]) && (!std::isnan(x[1])))) {
    ex = x[1];
  } else {
    ex = x[0];
  }
  return ex;
}

//
// Arguments    : const array<double, 1U> &x
// Return Type  : double
//
double maximum(const array<double, 1U> &x)
{
  double ex;
  int last;
  last = x.size(0);
  if (x.size(0) <= 2) {
    if (x.size(0) == 1) {
      ex = x[0];
    } else {
      ex = x[x.size(0) - 1];
      if ((!(x[0] < ex)) && ((!std::isnan(x[0])) || std::isnan(ex))) {
        ex = x[0];
      }
    }
  } else {
    int idx;
    if (!std::isnan(x[0])) {
      idx = 1;
    } else {
      int k;
      boolean_T exitg1;
      idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= last)) {
        if (!std::isnan(x[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (idx == 0) {
      ex = x[0];
    } else {
      ex = x[idx - 1];
      idx++;
      for (int b_k{idx}; b_k <= last; b_k++) {
        double d;
        d = x[b_k - 1];
        if (ex < d) {
          ex = d;
        }
      }
    }
  }
  return ex;
}

//
// Arguments    : const array<double, 2U> &x
// Return Type  : double
//
double maximum(const array<double, 2U> &x)
{
  double ex;
  int last;
  last = x.size(1);
  if (x.size(1) <= 2) {
    if (x.size(1) == 1) {
      ex = x[0];
    } else {
      ex = x[x.size(1) - 1];
      if ((!(x[0] < ex)) && ((!std::isnan(x[0])) || std::isnan(ex))) {
        ex = x[0];
      }
    }
  } else {
    int idx;
    if (!std::isnan(x[0])) {
      idx = 1;
    } else {
      int k;
      boolean_T exitg1;
      idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= last)) {
        if (!std::isnan(x[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (idx == 0) {
      ex = x[0];
    } else {
      ex = x[idx - 1];
      idx++;
      for (int b_k{idx}; b_k <= last; b_k++) {
        double d;
        d = x[b_k - 1];
        if (ex < d) {
          ex = d;
        }
      }
    }
  }
  return ex;
}

//
// Arguments    : const array<double, 2U> &x
// Return Type  : double
//
double minimum(const array<double, 2U> &x)
{
  double ex;
  int last;
  last = x.size(1);
  if (x.size(1) <= 2) {
    if (x.size(1) == 1) {
      ex = x[0];
    } else {
      ex = x[x.size(1) - 1];
      if ((!(x[0] > ex)) && ((!std::isnan(x[0])) || std::isnan(ex))) {
        ex = x[0];
      }
    }
  } else {
    int idx;
    if (!std::isnan(x[0])) {
      idx = 1;
    } else {
      int k;
      boolean_T exitg1;
      idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= last)) {
        if (!std::isnan(x[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (idx == 0) {
      ex = x[0];
    } else {
      ex = x[idx - 1];
      idx++;
      for (int b_k{idx}; b_k <= last; b_k++) {
        double d;
        d = x[b_k - 1];
        if (ex > d) {
          ex = d;
        }
      }
    }
  }
  return ex;
}

//
// Arguments    : const array<double, 1U> &x
// Return Type  : double
//
double minimum(const array<double, 1U> &x)
{
  double ex;
  int last;
  last = x.size(0);
  if (x.size(0) <= 2) {
    if (x.size(0) == 1) {
      ex = x[0];
    } else {
      ex = x[x.size(0) - 1];
      if ((!(x[0] > ex)) && ((!std::isnan(x[0])) || std::isnan(ex))) {
        ex = x[0];
      }
    }
  } else {
    int idx;
    if (!std::isnan(x[0])) {
      idx = 1;
    } else {
      int k;
      boolean_T exitg1;
      idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= last)) {
        if (!std::isnan(x[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (idx == 0) {
      ex = x[0];
    } else {
      ex = x[idx - 1];
      idx++;
      for (int b_k{idx}; b_k <= last; b_k++) {
        double d;
        d = x[b_k - 1];
        if (ex > d) {
          ex = d;
        }
      }
    }
  }
  return ex;
}

} // namespace internal
} // namespace coder

//
// File trailer for minOrMax.cpp
//
// [EOF]
//
