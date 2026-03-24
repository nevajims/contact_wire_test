//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ifft.cpp
//
// MATLAB Coder version            : 25.1
// C/C++ source code generated on  : 24-Mar-2026 22:30:21
//

// Include Files
#include "ifft.h"
#include "FFTImplementationCallback.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "omp.h"
#include <algorithm>
#include <cmath>

// Function Definitions
//
// Arguments    : const array<creal_T, 2U> &x
//                double varargin_1
//                array<creal_T, 2U> &y
// Return Type  : void
//
namespace coder {
void ifft(const array<creal_T, 2U> &x, double varargin_1, array<creal_T, 2U> &y)
{
  array<double, 2U> costab;
  array<double, 2U> costab1q;
  array<double, 2U> sintab;
  array<double, 2U> sintabinv;
  int nd2;
  if ((x.size(0) == 0) || (x.size(1) == 0) ||
      (static_cast<int>(varargin_1) == 0)) {
    y.set_size(static_cast<int>(varargin_1), x.size(1));
    nd2 = static_cast<int>(varargin_1) * x.size(1);
    for (int k{0}; k < nd2; k++) {
      y[k].re = 0.0;
      y[k].im = 0.0;
    }
  } else {
    double e;
    int N2blue;
    int b_n;
    int n;
    boolean_T useRadix2;
    useRadix2 = ((static_cast<int>(varargin_1) > 0) &&
                 ((static_cast<int>(varargin_1) &
                   (static_cast<int>(varargin_1) - 1)) == 0));
    N2blue = internal::fft::FFTImplementationCallback::get_algo_sizes(
        static_cast<int>(varargin_1), useRadix2, nd2);
    e = 6.2831853071795862 / static_cast<double>(nd2);
    n = nd2 / 2 / 2;
    costab1q.set_size(1, n + 1);
    costab1q[0] = 1.0;
    nd2 = static_cast<int>(static_cast<unsigned int>(n) >> 1) - 1;
    if (static_cast<int>(nd2 + 1 < 2000)) {
      for (int b_k{0}; b_k <= nd2; b_k++) {
        costab1q[b_k + 1] = std::cos(e * (static_cast<double>(b_k) + 1.0));
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int b_k = 0; b_k <= nd2; b_k++) {
        costab1q[b_k + 1] = std::cos(e * (static_cast<double>(b_k) + 1.0));
      }
    }
    b_n = nd2 + 2;
    if (static_cast<int>((n - nd2) - 2 < 2000)) {
      for (int c_k{b_n}; c_k < n; c_k++) {
        costab1q[c_k] = std::sin(e * static_cast<double>(n - c_k));
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int c_k = b_n; c_k < n; c_k++) {
        costab1q[c_k] = std::sin(e * static_cast<double>(n - c_k));
      }
    }
    costab1q[n] = 0.0;
    if (!useRadix2) {
      int n2;
      n = costab1q.size(1) - 1;
      n2 = (costab1q.size(1) - 1) << 1;
      costab.set_size(1, n2 + 1);
      sintab.set_size(1, n2 + 1);
      costab[0] = 1.0;
      sintab[0] = 0.0;
      sintabinv.set_size(1, n2 + 1);
      nd2 = (costab1q.size(1) - 1 < 2000);
      if (nd2) {
        for (int e_k{0}; e_k < n; e_k++) {
          sintabinv[e_k + 1] = costab1q[(n - e_k) - 1];
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int e_k = 0; e_k < n; e_k++) {
          sintabinv[e_k + 1] = costab1q[(n - e_k) - 1];
        }
      }
      b_n = costab1q.size(1);
      for (int k{b_n}; k <= n2; k++) {
        sintabinv[k] = costab1q[k - n];
      }
      if (nd2) {
        for (int g_k{0}; g_k < n; g_k++) {
          costab[g_k + 1] = costab1q[g_k + 1];
          sintab[g_k + 1] = -costab1q[(n - g_k) - 1];
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int g_k = 0; g_k < n; g_k++) {
          costab[g_k + 1] = costab1q[g_k + 1];
          sintab[g_k + 1] = -costab1q[(n - g_k) - 1];
        }
      }
      if (static_cast<int>((n2 - costab1q.size(1)) + 1 < 2000)) {
        for (int h_k{b_n}; h_k <= n2; h_k++) {
          costab[h_k] = -costab1q[n2 - h_k];
          sintab[h_k] = -costab1q[h_k - n];
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int h_k = b_n; h_k <= n2; h_k++) {
          costab[h_k] = -costab1q[n2 - h_k];
          sintab[h_k] = -costab1q[h_k - n];
        }
      }
      internal::fft::FFTImplementationCallback::dobluesteinfft(
          x, N2blue, static_cast<int>(varargin_1), costab, sintab, sintabinv,
          y);
    } else {
      b_n = costab1q.size(1) - 1;
      n = (costab1q.size(1) - 1) << 1;
      costab.set_size(1, n + 1);
      sintab.set_size(1, n + 1);
      costab[0] = 1.0;
      sintab[0] = 0.0;
      if (static_cast<int>(costab1q.size(1) - 1 < 2000)) {
        if (b_n - 1 >= 0) {
          std::copy(&costab1q[1], &costab1q[1 + b_n], &costab[1]);
        }
        for (int d_k{0}; d_k < b_n; d_k++) {
          sintab[d_k + 1] = costab1q[(b_n - d_k) - 1];
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int d_k = 0; d_k < b_n; d_k++) {
          costab[d_k + 1] = costab1q[d_k + 1];
          sintab[d_k + 1] = costab1q[(b_n - d_k) - 1];
        }
      }
      nd2 = costab1q.size(1);
      if (static_cast<int>((n - costab1q.size(1)) + 1 < 2000)) {
        for (int f_k{nd2}; f_k <= n; f_k++) {
          costab[f_k] = -costab1q[n - f_k];
          sintab[f_k] = costab1q[f_k - b_n];
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int f_k = nd2; f_k <= n; f_k++) {
          costab[f_k] = -costab1q[n - f_k];
          sintab[f_k] = costab1q[f_k - b_n];
        }
      }
      internal::fft::FFTImplementationCallback::r2br_r2dit_trig(
          x, static_cast<int>(varargin_1), costab, sintab, y);
    }
  }
}

} // namespace coder

//
// File trailer for ifft.cpp
//
// [EOF]
//
