//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: pinv.cpp
//
// MATLAB Coder version            : 25.1
// C/C++ source code generated on  : 24-Mar-2026 22:30:21
//

// Include Files
#include "pinv.h"
#include "rt_nonfinite.h"
#include "xzsvdc.h"
#include "coder_array.h"
#include <cmath>

// Function Declarations
namespace coder {
static void eml_pinv(const array<creal_T, 2U> &A, array<creal_T, 2U> &X);

}

// Function Definitions
//
// Arguments    : const array<creal_T, 2U> &A
//                array<creal_T, 2U> &X
// Return Type  : void
//
namespace coder {
static void eml_pinv(const array<creal_T, 2U> &A, array<creal_T, 2U> &X)
{
  array<creal_T, 2U> U;
  array<creal_T, 2U> V;
  array<creal_T, 2U> b_A;
  array<double, 1U> S;
  int ar;
  int m;
  int n;
  int vcol;
  m = A.size(0);
  n = A.size(1);
  X.set_size(A.size(1), A.size(0));
  vcol = A.size(0) * A.size(1);
  for (int k{0}; k < vcol; k++) {
    X[k].re = 0.0;
    X[k].im = 0.0;
  }
  if ((A.size(0) != 0) && (A.size(1) != 0)) {
    boolean_T p;
    p = true;
    for (int k{0}; k < vcol; k++) {
      if ((!p) || (std::isinf(A[k].re) || std::isinf(A[k].im) ||
                   (std::isnan(A[k].re) || std::isnan(A[k].im)))) {
        p = false;
      }
    }
    if (!p) {
      X.set_size(A.size(1), A.size(0));
      for (int k{0}; k < vcol; k++) {
        X[k].re = rtNaN;
        X[k].im = 0.0;
      }
    } else {
      double tol;
      int r;
      b_A.set_size(A.size(0), A.size(1));
      vcol--;
      for (int k{0}; k <= vcol; k++) {
        b_A[k] = A[k];
      }
      internal::reflapack::xzsvdc(b_A, U, S, V);
      if (S.size(0) == 0) {
        tol = 0.0;
      } else {
        boolean_T exitg1;
        tol = std::abs(S[0]);
        if (std::isinf(tol) || std::isnan(tol)) {
          tol = rtNaN;
        } else if (tol < 4.4501477170144028E-308) {
          tol = 4.94065645841247E-324;
        } else {
          std::frexp(tol, &ar);
          tol = std::ldexp(1.0, ar - 53);
        }
        tol *= static_cast<double>(m);
        vcol = 0;
        exitg1 = false;
        while ((!exitg1) && (vcol <= S.size(0) - 1)) {
          if (std::isinf(S[vcol]) || std::isnan(S[vcol])) {
            tol = 1.7976931348623157E+308;
            exitg1 = true;
          } else {
            vcol++;
          }
        }
      }
      r = -1;
      vcol = 0;
      while ((vcol <= n - 1) && (S[vcol] > tol)) {
        r++;
        vcol++;
      }
      if (r + 1 > 0) {
        double re_tmp;
        double temp_re;
        int lastColC;
        vcol = 1;
        for (int k{0}; k <= r; k++) {
          temp_re = 1.0 / S[k];
          ar = vcol + n;
          for (int b_k{vcol}; b_k < ar; b_k++) {
            tol = V[b_k - 1].im;
            re_tmp = V[b_k - 1].re;
            V[b_k - 1].re = temp_re * re_tmp - 0.0 * tol;
            V[b_k - 1].im = temp_re * tol + 0.0 * re_tmp;
          }
          vcol = ar;
        }
        lastColC = A.size(1) * (A.size(0) - 1);
        for (int k{0}; n < 0 ? k >= lastColC : k <= lastColC; k += n) {
          vcol = k + 1;
          ar = k + n;
          for (int b_k{vcol}; b_k <= ar; b_k++) {
            X[b_k - 1].re = 0.0;
            X[b_k - 1].im = 0.0;
          }
        }
        vcol = 0;
        for (int k{0}; n < 0 ? k >= lastColC : k <= lastColC; k += n) {
          int i;
          ar = -1;
          vcol++;
          i = vcol + m * r;
          for (int b_k{vcol}; m < 0 ? b_k >= i : b_k <= i; b_k += m) {
            int i1;
            int i2;
            tol = U[b_k - 1].re;
            re_tmp = -U[b_k - 1].im;
            temp_re = tol - 0.0 * re_tmp;
            tol = re_tmp + 0.0 * tol;
            i1 = k + 1;
            i2 = k + n;
            for (int ic{i1}; ic <= i2; ic++) {
              double b_temp_re_tmp;
              int temp_re_tmp;
              temp_re_tmp = (ar + ic) - k;
              re_tmp = V[temp_re_tmp].im;
              b_temp_re_tmp = V[temp_re_tmp].re;
              X[ic - 1].re =
                  X[ic - 1].re + (temp_re * b_temp_re_tmp - tol * re_tmp);
              X[ic - 1].im =
                  X[ic - 1].im + (temp_re * re_tmp + tol * b_temp_re_tmp);
            }
            ar += n;
          }
        }
      }
    }
  }
}

//
// Arguments    : const array<creal_T, 2U> &A
//                array<creal_T, 2U> &X
// Return Type  : void
//
void pinv(const array<creal_T, 2U> &A, array<creal_T, 2U> &X)
{
  array<creal_T, 2U> b_A;
  array<creal_T, 2U> r;
  if (A.size(0) < A.size(1)) {
    int b_loop_ub;
    int i2;
    int i3;
    int loop_ub;
    loop_ub = A.size(1);
    b_loop_ub = A.size(0);
    b_A.set_size(A.size(1), A.size(0));
    for (int i{0}; i < b_loop_ub; i++) {
      for (int i1{0}; i1 < loop_ub; i1++) {
        i2 = i + A.size(0) * i1;
        i3 = i1 + b_A.size(0) * i;
        b_A[i3].re = A[i2].re;
        b_A[i3].im = -A[i2].im;
      }
    }
    eml_pinv(b_A, r);
    loop_ub = r.size(1);
    b_loop_ub = r.size(0);
    X.set_size(r.size(1), r.size(0));
    for (int i{0}; i < b_loop_ub; i++) {
      for (int i1{0}; i1 < loop_ub; i1++) {
        i2 = i + r.size(0) * i1;
        i3 = i1 + X.size(0) * i;
        X[i3].re = r[i2].re;
        X[i3].im = -r[i2].im;
      }
    }
  } else {
    eml_pinv(A, X);
  }
}

} // namespace coder

//
// File trailer for pinv.cpp
//
// [EOF]
//
