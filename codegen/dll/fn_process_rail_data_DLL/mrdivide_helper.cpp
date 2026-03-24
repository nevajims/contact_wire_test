//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: mrdivide_helper.cpp
//
// MATLAB Coder version            : 25.1
// C/C++ source code generated on  : 24-Mar-2026 22:30:21
//

// Include Files
#include "mrdivide_helper.h"
#include "rt_nonfinite.h"
#include "xnrm2.h"
#include "coder_array.h"
#include "omp.h"
#include <cmath>
#include <cstring>
#include <emmintrin.h>

// Function Definitions
//
// Arguments    : const array<double, 2U> &A
//                const array<double, 2U> &B
//                array<double, 1U> &Y
// Return Type  : void
//
namespace coder {
namespace internal {
void mrdiv(const array<double, 2U> &A, const array<double, 2U> &B,
           array<double, 1U> &Y)
{
  array<double, 2U> b_B;
  array<double, 2U> b_Y;
  array<double, 1U> b_A;
  int j;
  if ((A.size(0) == 0) || (A.size(1) == 0) || (B.size(1) == 0)) {
    int loop_ub;
    loop_ub = A.size(0);
    Y.set_size(A.size(0));
    for (int k{0}; k < loop_ub; k++) {
      Y[k] = 0.0;
    }
  } else if (B.size(1) == 1) {
    double xnorm;
    int knt;
    int loop_ub;
    int scalarLB;
    xnorm = B[0];
    loop_ub = A.size(0);
    Y.set_size(A.size(0));
    scalarLB = (A.size(0) / 2) << 1;
    knt = scalarLB - 2;
    for (int k{0}; k <= knt; k += 2) {
      _mm_storeu_pd(&Y[k], _mm_div_pd(_mm_loadu_pd(&A[k]), _mm_set1_pd(xnorm)));
    }
    for (int k{scalarLB}; k < loop_ub; k++) {
      Y[k] = A[k] / xnorm;
    }
  } else {
    __m128d r;
    double atmp;
    double tau_data;
    double xnorm;
    int knt;
    int loop_ub;
    int m;
    int nb;
    int rankA;
    int scalarLB;
    m = B.size(1);
    b_A.set_size(B.size(1));
    for (int k{0}; k < m; k++) {
      b_A[k] = B[k];
    }
    loop_ub = A.size(1);
    nb = A.size(0);
    b_B.set_size(A.size(1), A.size(0));
    for (int k{0}; k < nb; k++) {
      for (int b_k{0}; b_k < loop_ub; b_k++) {
        b_B[b_k + b_B.size(0) * k] = A[k + A.size(0) * b_k];
      }
    }
    atmp = b_A[0];
    tau_data = 0.0;
    xnorm = blas::xnrm2(b_A.size(0) - 1, b_A);
    if (xnorm != 0.0) {
      double beta1;
      beta1 = std::abs(b_A[0]);
      xnorm = std::abs(xnorm);
      if (beta1 < xnorm) {
        beta1 /= xnorm;
        beta1 = xnorm * std::sqrt(beta1 * beta1 + 1.0);
      } else if (beta1 > xnorm) {
        xnorm /= beta1;
        beta1 *= std::sqrt(xnorm * xnorm + 1.0);
      } else if (std::isnan(xnorm)) {
        beta1 = rtNaN;
      } else {
        beta1 *= 1.4142135623730951;
      }
      if (b_A[0] >= 0.0) {
        beta1 = -beta1;
      }
      if (std::abs(beta1) < 1.0020841800044864E-292) {
        knt = 0;
        loop_ub = (((b_A.size(0) - 1) / 2) << 1) + 2;
        scalarLB = loop_ub - 2;
        do {
          knt++;
          for (int k{2}; k <= scalarLB; k += 2) {
            r = _mm_loadu_pd(&b_A[k - 1]);
            _mm_storeu_pd(&b_A[k - 1],
                          _mm_mul_pd(_mm_set1_pd(9.9792015476736E+291), r));
          }
          for (int k{loop_ub}; k <= m; k++) {
            b_A[k - 1] = 9.9792015476736E+291 * b_A[k - 1];
          }
          beta1 *= 9.9792015476736E+291;
          atmp *= 9.9792015476736E+291;
        } while ((std::abs(beta1) < 1.0020841800044864E-292) && (knt < 20));
        xnorm = std::abs(atmp);
        beta1 = std::abs(blas::xnrm2(b_A.size(0) - 1, b_A));
        if (xnorm < beta1) {
          xnorm /= beta1;
          beta1 *= std::sqrt(xnorm * xnorm + 1.0);
        } else if (xnorm > beta1) {
          beta1 /= xnorm;
          beta1 = xnorm * std::sqrt(beta1 * beta1 + 1.0);
        } else if (std::isnan(beta1)) {
          beta1 = rtNaN;
        } else {
          beta1 = xnorm * 1.4142135623730951;
        }
        if (atmp >= 0.0) {
          beta1 = -beta1;
        }
        tau_data = (beta1 - atmp) / beta1;
        xnorm = 1.0 / (atmp - beta1);
        loop_ub = (((b_A.size(0) - 1) / 2) << 1) + 2;
        scalarLB = loop_ub - 2;
        for (int b_k{2}; b_k <= scalarLB; b_k += 2) {
          r = _mm_loadu_pd(&b_A[b_k - 1]);
          _mm_storeu_pd(&b_A[b_k - 1], _mm_mul_pd(_mm_set1_pd(xnorm), r));
        }
        for (int b_k{loop_ub}; b_k <= m; b_k++) {
          b_A[b_k - 1] = xnorm * b_A[b_k - 1];
        }
        for (int k{0}; k < knt; k++) {
          beta1 *= 1.0020841800044864E-292;
        }
        atmp = beta1;
      } else {
        tau_data = (beta1 - b_A[0]) / beta1;
        xnorm = 1.0 / (b_A[0] - beta1);
        loop_ub = (((b_A.size(0) - 1) / 2) << 1) + 2;
        scalarLB = loop_ub - 2;
        for (int k{2}; k <= scalarLB; k += 2) {
          r = _mm_loadu_pd(&b_A[k - 1]);
          _mm_storeu_pd(&b_A[k - 1], _mm_mul_pd(_mm_set1_pd(xnorm), r));
        }
        for (int k{loop_ub}; k <= m; k++) {
          b_A[k - 1] = xnorm * b_A[k - 1];
        }
        atmp = beta1;
      }
    }
    b_A[0] = atmp;
    rankA = 0;
    xnorm = std::abs(b_A[0]);
    if (!(xnorm <=
          std::fmin(1.4901161193847656E-8,
                    2.2204460492503131E-15 * static_cast<double>(b_A.size(0))) *
              xnorm)) {
      rankA = 1;
    }
    b_Y.set_size(1, A.size(0));
    std::memset(&b_Y[0], 0, static_cast<unsigned int>(nb) * sizeof(double));
    m = b_A.size(0);
    if (tau_data != 0.0) {
      for (int b_k{0}; b_k < nb; b_k++) {
        loop_ub = b_B.size(0) * b_k;
        xnorm = b_B[loop_ub];
        for (int k{2}; k <= m; k++) {
          xnorm += b_A[k - 1] * b_B[(k + loop_ub) - 1];
        }
        xnorm *= tau_data;
        if (xnorm != 0.0) {
          b_B[loop_ub] = b_B[loop_ub] - xnorm;
          knt = (((m - 1) / 2) << 1) + 2;
          loop_ub = knt - 2;
          for (int k{2}; k <= loop_ub; k += 2) {
            __m128d r1;
            r = _mm_loadu_pd(&b_A[k - 1]);
            scalarLB = (k + b_B.size(0) * b_k) - 1;
            r1 = _mm_loadu_pd(&b_B[scalarLB]);
            _mm_storeu_pd(&b_B[scalarLB],
                          _mm_sub_pd(r1, _mm_mul_pd(r, _mm_set1_pd(xnorm))));
          }
          for (int k{knt}; k <= m; k++) {
            loop_ub = (k + b_B.size(0) * b_k) - 1;
            b_B[loop_ub] = b_B[loop_ub] - b_A[k - 1] * xnorm;
          }
        }
      }
    }
    if (static_cast<int>(b_B.size(1) * (rankA - 2) < 2000)) {
      for (int c_k{0}; c_k < nb; c_k++) {
        if (rankA - 1 >= 0) {
          b_Y[c_k] = b_B[b_B.size(0) * c_k];
        }
        for (j = rankA; j >= 1; j--) {
          b_Y[c_k] = b_Y[c_k] / b_A[0];
        }
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(j)

      for (int c_k = 0; c_k < nb; c_k++) {
        if (rankA - 1 >= 0) {
          b_Y[c_k] = b_B[b_B.size(0) * c_k];
        }
        for (j = rankA; j >= 1; j--) {
          b_Y[c_k] = b_Y[c_k] / b_A[0];
        }
      }
    }
    Y.set_size(nb);
    for (int k{0}; k < nb; k++) {
      Y[k] = b_Y[k];
    }
  }
}

} // namespace internal
} // namespace coder

//
// File trailer for mrdivide_helper.cpp
//
// [EOF]
//
