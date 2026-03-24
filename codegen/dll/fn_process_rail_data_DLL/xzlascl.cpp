//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xzlascl.cpp
//
// MATLAB Coder version            : 25.1
// C/C++ source code generated on  : 24-Mar-2026 22:30:21
//

// Include Files
#include "xzlascl.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <emmintrin.h>

// Function Definitions
//
// Arguments    : double cfrom
//                double cto
//                int m
//                int n
//                array<creal_T, 2U> &A
//                int lda
// Return Type  : void
//
namespace coder {
namespace internal {
namespace reflapack {
void xzlascl(double cfrom, double cto, int m, int n, array<creal_T, 2U> &A,
             int lda)
{
  double cfromc;
  double ctoc;
  boolean_T notdone;
  cfromc = cfrom;
  ctoc = cto;
  notdone = true;
  while (notdone) {
    double cfrom1;
    double cto1;
    double mul;
    cfrom1 = cfromc * 2.0041683600089728E-292;
    cto1 = ctoc / 4.9896007738368E+291;
    if ((std::abs(cfrom1) > std::abs(ctoc)) && (ctoc != 0.0)) {
      mul = 2.0041683600089728E-292;
      cfromc = cfrom1;
    } else if (std::abs(cto1) > std::abs(cfromc)) {
      mul = 4.9896007738368E+291;
      ctoc = cto1;
    } else {
      mul = ctoc / cfromc;
      notdone = false;
    }
    for (int j{0}; j < n; j++) {
      int offset;
      offset = j * lda - 1;
      for (int i{0}; i < m; i++) {
        int b_i;
        b_i = (offset + i) + 1;
        A[b_i].re = mul * A[b_i].re;
        A[b_i].im = mul * A[b_i].im;
      }
    }
  }
}

//
// Arguments    : double cfrom
//                double cto
//                int m
//                array<double, 1U> &A
// Return Type  : void
//
void xzlascl(double cfrom, double cto, int m, array<double, 1U> &A)
{
  double cfromc;
  double ctoc;
  boolean_T notdone;
  cfromc = cfrom;
  ctoc = cto;
  notdone = true;
  while (notdone) {
    double cfrom1;
    double cto1;
    double mul;
    int scalarLB;
    int vectorUB;
    cfrom1 = cfromc * 2.0041683600089728E-292;
    cto1 = ctoc / 4.9896007738368E+291;
    if ((std::abs(cfrom1) > std::abs(ctoc)) && (ctoc != 0.0)) {
      mul = 2.0041683600089728E-292;
      cfromc = cfrom1;
    } else if (std::abs(cto1) > std::abs(cfromc)) {
      mul = 4.9896007738368E+291;
      ctoc = cto1;
    } else {
      mul = ctoc / cfromc;
      notdone = false;
    }
    scalarLB = (m / 2) << 1;
    vectorUB = scalarLB - 2;
    for (int i{0}; i <= vectorUB; i += 2) {
      __m128d r;
      r = _mm_loadu_pd(&A[i]);
      _mm_storeu_pd(&A[i], _mm_mul_pd(r, _mm_set1_pd(mul)));
    }
    for (int i{scalarLB}; i < m; i++) {
      A[i] = A[i] * mul;
    }
  }
}

} // namespace reflapack
} // namespace internal
} // namespace coder

//
// File trailer for xzlascl.cpp
//
// [EOF]
//
