//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: FFTImplementationCallback.cpp
//
// MATLAB Coder version            : 25.1
// C/C++ source code generated on  : 24-Mar-2026 22:30:21
//

// Include Files
#include "FFTImplementationCallback.h"
#include "fn_process_rail_data_DLL_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "omp.h"
#include <cmath>
#include <cstring>

// Function Definitions
//
// Arguments    : const array<double, 2U> &x
//                int xoffInit
//                array<creal_T, 1U> &y
//                int nrowsx
//                int nRows
//                int nfft
//                const array<creal_T, 1U> &wwc
//                const array<double, 2U> &costab
//                const array<double, 2U> &sintab
//                const array<double, 2U> &costabinv
//                const array<double, 2U> &sintabinv
// Return Type  : void
//
namespace coder {
namespace internal {
namespace fft {
void FFTImplementationCallback::doHalfLengthBluestein(
    const array<double, 2U> &x, int xoffInit, array<creal_T, 1U> &y, int nrowsx,
    int nRows, int nfft, const array<creal_T, 1U> &wwc,
    const array<double, 2U> &costab, const array<double, 2U> &sintab,
    const array<double, 2U> &costabinv, const array<double, 2U> &sintabinv)
{
  array<creal_T, 1U> fv;
  array<creal_T, 1U> fy;
  array<creal_T, 1U> reconVar1;
  array<creal_T, 1U> reconVar2;
  array<creal_T, 1U> ytmp;
  array<double, 2U> b_costab;
  array<double, 2U> b_sintab;
  array<double, 2U> costab1q;
  array<double, 2U> hcostabinv;
  array<double, 2U> hsintab;
  array<double, 2U> hsintabinv;
  array<int, 2U> wrapIndex;
  creal_T temp;
  creal_T twid;
  double b_re_tmp;
  double b_ytmp_im;
  double b_ytmp_re;
  double c_re_tmp;
  double c_ytmp_re_tmp;
  double d;
  double d1;
  double d2;
  double d3;
  double d_re_tmp;
  double d_ytmp_re_tmp;
  double e;
  double e_re_tmp;
  double e_ytmp_re_tmp;
  double f_re_tmp;
  double f_ytmp_re_tmp;
  double g_ytmp_re_tmp;
  double h_ytmp_re_tmp;
  double im;
  double re_tmp;
  int b_i;
  int b_nfft;
  int e_k;
  int hnRows;
  int i3;
  int i4;
  int iDelta;
  int iDelta2;
  int iheight;
  int ju;
  int n;
  int n2;
  int nRowsD2;
  int nd2;
  int twid_tmp;
  boolean_T tst;
  hnRows = nRows / 2;
  ytmp.set_size(hnRows);
  if (hnRows > nrowsx) {
    ytmp.set_size(hnRows);
    if (hnRows - 1 >= 0) {
      std::memset(&ytmp[0], 0,
                  static_cast<unsigned int>(hnRows) * sizeof(creal_T));
    }
  }
  if ((static_cast<unsigned int>(x.size(0)) & 1U) == 0U) {
    tst = true;
    ju = x.size(0);
  } else if (x.size(0) >= nRows) {
    tst = true;
    ju = nRows;
  } else {
    tst = false;
    ju = x.size(0) - 1;
  }
  if (ju > nRows) {
    ju = nRows;
  }
  nd2 = nRows << 1;
  e = 6.2831853071795862 / static_cast<double>(nd2);
  n2 = nd2 / 2 / 2;
  costab1q.set_size(1, n2 + 1);
  costab1q[0] = 1.0;
  nd2 = static_cast<int>(static_cast<unsigned int>(n2) >> 1) - 1;
  if (static_cast<int>(nd2 + 1 < 2000)) {
    for (int k{0}; k <= nd2; k++) {
      costab1q[k + 1] = std::cos(e * (static_cast<double>(k) + 1.0));
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int k = 0; k <= nd2; k++) {
      costab1q[k + 1] = std::cos(e * (static_cast<double>(k) + 1.0));
    }
  }
  n = nd2 + 2;
  if (static_cast<int>((n2 - nd2) - 2 < 2000)) {
    for (int b_k{n}; b_k < n2; b_k++) {
      costab1q[b_k] = std::sin(e * static_cast<double>(n2 - b_k));
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int b_k = n; b_k < n2; b_k++) {
      costab1q[b_k] = std::sin(e * static_cast<double>(n2 - b_k));
    }
  }
  costab1q[n2] = 0.0;
  n = costab1q.size(1) - 1;
  n2 = (costab1q.size(1) - 1) << 1;
  b_costab.set_size(1, n2 + 1);
  b_sintab.set_size(1, n2 + 1);
  b_costab[0] = 1.0;
  b_sintab[0] = 0.0;
  if (static_cast<int>(costab1q.size(1) - 1 < 2000)) {
    for (int c_k{0}; c_k < n; c_k++) {
      b_costab[c_k + 1] = costab1q[c_k + 1];
      b_sintab[c_k + 1] = -costab1q[(n - c_k) - 1];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int c_k = 0; c_k < n; c_k++) {
      b_costab[c_k + 1] = costab1q[c_k + 1];
      b_sintab[c_k + 1] = -costab1q[(n - c_k) - 1];
    }
  }
  nd2 = costab1q.size(1);
  if (static_cast<int>((n2 - costab1q.size(1)) + 1 < 2000)) {
    for (int d_k{nd2}; d_k <= n2; d_k++) {
      b_costab[d_k] = -costab1q[n2 - d_k];
      b_sintab[d_k] = -costab1q[d_k - n];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int d_k = nd2; d_k <= n2; d_k++) {
      b_costab[d_k] = -costab1q[n2 - d_k];
      b_sintab[d_k] = -costab1q[d_k - n];
    }
  }
  nd2 = static_cast<int>(static_cast<unsigned int>(costab.size(1)) >> 1);
  costab1q.set_size(1, nd2);
  hsintab.set_size(1, nd2);
  hcostabinv.set_size(1, nd2);
  hsintabinv.set_size(1, nd2);
  if (static_cast<int>(nd2 < 2000)) {
    for (int i{0}; i < nd2; i++) {
      b_i = ((i + 1) << 1) - 2;
      costab1q[i] = costab[b_i];
      hsintab[i] = sintab[b_i];
      hcostabinv[i] = costabinv[b_i];
      hsintabinv[i] = sintabinv[b_i];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(b_i)

    for (int i = 0; i < nd2; i++) {
      b_i = ((i + 1) << 1) - 2;
      costab1q[i] = costab[b_i];
      hsintab[i] = sintab[b_i];
      hcostabinv[i] = costabinv[b_i];
      hsintabinv[i] = sintabinv[b_i];
    }
  }
  reconVar1.set_size(hnRows);
  reconVar2.set_size(hnRows);
  wrapIndex.set_size(1, hnRows);
  for (int c_i{0}; c_i < hnRows; c_i++) {
    nd2 = c_i << 1;
    e = b_sintab[nd2];
    im = b_costab[nd2];
    reconVar1[c_i].re = e + 1.0;
    reconVar1[c_i].im = -im;
    reconVar2[c_i].re = 1.0 - e;
    reconVar2[c_i].im = im;
    if (c_i != 0) {
      wrapIndex[c_i] = (hnRows - c_i) + 1;
    } else {
      wrapIndex[0] = 1;
    }
  }
  n = ju / 2 - 1;
  n2 = xoffInit;
  if (static_cast<int>(n + 1 < 2000)) {
    for (int k1{0}; k1 <= n; k1++) {
      temp = wwc[(hnRows + k1) - 1];
      nd2 = xoffInit + (k1 << 1);
      twid.re = x[nd2];
      twid.im = x[nd2 + 1];
      ytmp[k1].re = temp.re * twid.re + temp.im * twid.im;
      ytmp[k1].im = temp.re * twid.im - temp.im * twid.re;
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
        twid, temp, twid_tmp)

    for (int k1 = 0; k1 <= n; k1++) {
      temp = wwc[(hnRows + k1) - 1];
      twid_tmp = n2 + (k1 << 1);
      twid.re = x[twid_tmp];
      twid.im = x[twid_tmp + 1];
      ytmp[k1].re = temp.re * twid.re + temp.im * twid.im;
      ytmp[k1].im = temp.re * twid.im - temp.im * twid.re;
    }
  }
  if (n >= 0) {
    n2 += (n + 1) << 1;
  }
  if (!tst) {
    temp = wwc[hnRows + n];
    twid.re = x[n2];
    ytmp[n + 1].re = temp.re * twid.re + temp.im * 0.0;
    ytmp[n + 1].im = temp.re * 0.0 - temp.im * twid.re;
    if (n + 3 <= hnRows) {
      nd2 = n + 3;
      if (nd2 <= hnRows) {
        std::memset(&ytmp[nd2 + -1], 0,
                    static_cast<unsigned int>((hnRows - nd2) + 1) *
                        sizeof(creal_T));
      }
    }
  } else if (n + 2 <= hnRows) {
    nd2 = n + 2;
    if (nd2 <= hnRows) {
      std::memset(&ytmp[nd2 + -1], 0,
                  static_cast<unsigned int>((hnRows - nd2) + 1) *
                      sizeof(creal_T));
    }
  }
  b_nfft = nfft / 2;
  fy.set_size(b_nfft);
  if (b_nfft > ytmp.size(0)) {
    fy.set_size(b_nfft);
    std::memset(&fy[0], 0, static_cast<unsigned int>(b_nfft) * sizeof(creal_T));
  }
  n = ytmp.size(0);
  if (n > b_nfft) {
    n = b_nfft;
  }
  iDelta = b_nfft - 2;
  nRowsD2 = b_nfft / 2;
  e_k = nRowsD2 / 2;
  n2 = 0;
  ju = 0;
  for (int c_i{0}; c_i <= n - 2; c_i++) {
    fy[n2] = ytmp[c_i];
    nd2 = b_nfft;
    tst = true;
    while (tst) {
      nd2 >>= 1;
      ju ^= nd2;
      tst = ((ju & nd2) == 0);
    }
    n2 = ju;
  }
  if (n - 2 < 0) {
    nd2 = 0;
  } else {
    nd2 = n - 1;
  }
  fy[n2] = ytmp[nd2];
  if (b_nfft > 1) {
    for (int c_i{0}; c_i <= iDelta; c_i += 2) {
      temp = fy[c_i + 1];
      e = fy[c_i].re;
      im = fy[c_i].im;
      fy[c_i + 1].re = e - fy[c_i + 1].re;
      fy[c_i + 1].im = fy[c_i].im - fy[c_i + 1].im;
      e += temp.re;
      im += temp.im;
      fy[c_i].re = e;
      fy[c_i].im = im;
    }
  }
  iDelta = 2;
  iDelta2 = 4;
  iheight = ((e_k - 1) << 2) + 1;
  while (e_k > 0) {
    int d_i;
    for (d_i = 0; d_i < iheight; d_i += iDelta2) {
      nd2 = d_i + iDelta;
      temp = fy[nd2];
      fy[nd2].re = fy[d_i].re - temp.re;
      fy[nd2].im = fy[d_i].im - temp.im;
      fy[d_i].re = fy[d_i].re + temp.re;
      fy[d_i].im = fy[d_i].im + temp.im;
    }
    nd2 = 1;
    for (n = e_k; n < nRowsD2; n += e_k) {
      twid.re = costab1q[n];
      twid.im = hsintab[n];
      d_i = nd2;
      n2 = nd2 + iheight;
      while (d_i < n2) {
        ju = d_i + iDelta;
        e = fy[ju].im;
        im = fy[ju].re;
        temp.re = twid.re * im - twid.im * e;
        temp.im = twid.re * e + twid.im * im;
        fy[ju].re = fy[d_i].re - temp.re;
        fy[ju].im = fy[d_i].im - temp.im;
        fy[d_i].re = fy[d_i].re + temp.re;
        fy[d_i].im = fy[d_i].im + temp.im;
        d_i += iDelta2;
      }
      nd2++;
    }
    e_k = static_cast<int>(static_cast<unsigned int>(e_k) >> 1);
    iDelta = iDelta2;
    iDelta2 += iDelta2;
    iheight -= iDelta;
  }
  FFTImplementationCallback::r2br_r2dit_trig_impl(wwc, b_nfft, costab1q,
                                                  hsintab, fv);
  nd2 = fy.size(0);
  if (static_cast<int>(fy.size(0) < 2000)) {
    for (int i1{0}; i1 < nd2; i1++) {
      e = fy[i1].re;
      im = fv[i1].im;
      re_tmp = fy[i1].im;
      c_re_tmp = fv[i1].re;
      fy[i1].re = e * c_re_tmp - re_tmp * im;
      fy[i1].im = e * im + re_tmp * c_re_tmp;
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
        b_re_tmp, d_re_tmp, e_re_tmp, f_re_tmp)

    for (int i1 = 0; i1 < nd2; i1++) {
      b_re_tmp = fy[i1].re;
      d_re_tmp = fv[i1].im;
      e_re_tmp = fy[i1].im;
      f_re_tmp = fv[i1].re;
      fy[i1].re = b_re_tmp * f_re_tmp - e_re_tmp * d_re_tmp;
      fy[i1].im = b_re_tmp * d_re_tmp + e_re_tmp * f_re_tmp;
    }
  }
  FFTImplementationCallback::r2br_r2dit_trig_impl(fy, b_nfft, hcostabinv,
                                                  hsintabinv, fv);
  if (fv.size(0) > 1) {
    e = 1.0 / static_cast<double>(fv.size(0));
    nd2 = fv.size(0);
    if (static_cast<int>(fv.size(0) < 2000)) {
      for (int i2{0}; i2 < nd2; i2++) {
        fv[i2].re = e * fv[i2].re;
        fv[i2].im = e * fv[i2].im;
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i2 = 0; i2 < nd2; i2++) {
        fv[i2].re = e * fv[i2].re;
        fv[i2].im = e * fv[i2].im;
      }
    }
  }
  n = wwc.size(0);
  if (static_cast<int>((wwc.size(0) - hnRows) + 1 < 2000)) {
    for (int f_k{hnRows}; f_k <= n; f_k++) {
      e = wwc[f_k - 1].re;
      im = fv[f_k - 1].im;
      re_tmp = wwc[f_k - 1].im;
      c_re_tmp = fv[f_k - 1].re;
      nd2 = f_k - hnRows;
      ytmp[nd2].re = e * c_re_tmp + re_tmp * im;
      ytmp[nd2].im = e * im - re_tmp * c_re_tmp;
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
        d, d1, d2, d3, i4)

    for (int f_k = hnRows; f_k <= n; f_k++) {
      d = wwc[f_k - 1].re;
      d1 = fv[f_k - 1].im;
      d2 = wwc[f_k - 1].im;
      d3 = fv[f_k - 1].re;
      i4 = f_k - hnRows;
      ytmp[i4].re = d * d3 + d2 * d1;
      ytmp[i4].im = d * d1 - d2 * d3;
    }
  }
  if (static_cast<int>(hnRows < 2000)) {
    for (int e_i{0}; e_i < hnRows; e_i++) {
      double b_ytmp_re_tmp;
      double ytmp_im;
      double ytmp_re;
      double ytmp_re_tmp;
      i3 = wrapIndex[e_i];
      e = ytmp[e_i].re;
      im = reconVar1[e_i].im;
      re_tmp = ytmp[e_i].im;
      c_re_tmp = reconVar1[e_i].re;
      ytmp_re = ytmp[i3 - 1].re;
      ytmp_im = -ytmp[i3 - 1].im;
      ytmp_re_tmp = reconVar2[e_i].im;
      b_ytmp_re_tmp = reconVar2[e_i].re;
      y[e_i].re = 0.5 * ((e * c_re_tmp - re_tmp * im) +
                         (ytmp_re * b_ytmp_re_tmp - ytmp_im * ytmp_re_tmp));
      y[e_i].im = 0.5 * ((e * im + re_tmp * c_re_tmp) +
                         (ytmp_re * ytmp_re_tmp + ytmp_im * b_ytmp_re_tmp));
      nd2 = hnRows + e_i;
      y[nd2].re = 0.5 * ((e * b_ytmp_re_tmp - re_tmp * ytmp_re_tmp) +
                         (ytmp_re * c_re_tmp - ytmp_im * im));
      y[nd2].im = 0.5 * ((e * ytmp_re_tmp + re_tmp * b_ytmp_re_tmp) +
                         (ytmp_re * im + ytmp_im * c_re_tmp));
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
        i3, c_ytmp_re_tmp, d_ytmp_re_tmp, e_ytmp_re_tmp, f_ytmp_re_tmp,        \
            b_ytmp_re, b_ytmp_im, g_ytmp_re_tmp, h_ytmp_re_tmp)

    for (int e_i = 0; e_i < hnRows; e_i++) {
      i3 = wrapIndex[e_i];
      c_ytmp_re_tmp = ytmp[e_i].re;
      d_ytmp_re_tmp = reconVar1[e_i].im;
      e_ytmp_re_tmp = ytmp[e_i].im;
      f_ytmp_re_tmp = reconVar1[e_i].re;
      b_ytmp_re = ytmp[i3 - 1].re;
      b_ytmp_im = -ytmp[i3 - 1].im;
      g_ytmp_re_tmp = reconVar2[e_i].im;
      h_ytmp_re_tmp = reconVar2[e_i].re;
      y[e_i].re =
          0.5 *
          ((c_ytmp_re_tmp * f_ytmp_re_tmp - e_ytmp_re_tmp * d_ytmp_re_tmp) +
           (b_ytmp_re * h_ytmp_re_tmp - b_ytmp_im * g_ytmp_re_tmp));
      y[e_i].im =
          0.5 *
          ((c_ytmp_re_tmp * d_ytmp_re_tmp + e_ytmp_re_tmp * f_ytmp_re_tmp) +
           (b_ytmp_re * g_ytmp_re_tmp + b_ytmp_im * h_ytmp_re_tmp));
      i3 = hnRows + e_i;
      y[i3].re =
          0.5 *
          ((c_ytmp_re_tmp * h_ytmp_re_tmp - e_ytmp_re_tmp * g_ytmp_re_tmp) +
           (b_ytmp_re * f_ytmp_re_tmp - b_ytmp_im * d_ytmp_re_tmp));
      y[i3].im =
          0.5 *
          ((c_ytmp_re_tmp * g_ytmp_re_tmp + e_ytmp_re_tmp * h_ytmp_re_tmp) +
           (b_ytmp_re * d_ytmp_re_tmp + b_ytmp_im * f_ytmp_re_tmp));
    }
  }
}

//
// Arguments    : const array<double, 2U> &x
//                int xoffInit
//                array<creal_T, 1U> &y
//                int unsigned_nRows
//                const array<double, 2U> &costab
//                const array<double, 2U> &sintab
// Return Type  : void
//
void FFTImplementationCallback::doHalfLengthRadix2(
    const array<double, 2U> &x, int xoffInit, array<creal_T, 1U> &y,
    int unsigned_nRows, const array<double, 2U> &costab,
    const array<double, 2U> &sintab)
{
  array<creal_T, 1U> reconVar1;
  array<creal_T, 1U> reconVar2;
  array<double, 2U> hcostab;
  array<double, 2U> hsintab;
  array<int, 2U> wrapIndex;
  array<int, 1U> bitrevIndex;
  double b_im;
  double b_re;
  double im;
  double re;
  double temp2_im;
  double temp2_re;
  double temp_im;
  double temp_re;
  int b_i;
  int hszCostab;
  int iDelta;
  int iDelta2;
  int iheight;
  int iy;
  int ju;
  int k;
  int nRows;
  int nRowsD2;
  int u0;
  boolean_T tst;
  nRows = unsigned_nRows / 2;
  u0 = y.size(0);
  if (u0 > nRows) {
    u0 = nRows;
  }
  iDelta = u0 - 2;
  iDelta2 = nRows - 2;
  nRowsD2 = nRows / 2;
  k = nRowsD2 / 2;
  hszCostab = static_cast<int>(static_cast<unsigned int>(costab.size(1)) >> 1);
  hcostab.set_size(1, hszCostab);
  hsintab.set_size(1, hszCostab);
  if (static_cast<int>(hszCostab < 2000)) {
    for (int i{0}; i < hszCostab; i++) {
      b_i = ((i + 1) << 1) - 2;
      hcostab[i] = costab[b_i];
      hsintab[i] = sintab[b_i];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(b_i)

    for (int i = 0; i < hszCostab; i++) {
      b_i = ((i + 1) << 1) - 2;
      hcostab[i] = costab[b_i];
      hsintab[i] = sintab[b_i];
    }
  }
  reconVar1.set_size(nRows);
  reconVar2.set_size(nRows);
  wrapIndex.set_size(1, nRows);
  ju = 0;
  iy = 1;
  bitrevIndex.set_size(nRows);
  for (int c_i{0}; c_i < nRows; c_i++) {
    re = sintab[c_i];
    im = costab[c_i];
    reconVar1[c_i].re = re + 1.0;
    reconVar1[c_i].im = -im;
    reconVar2[c_i].re = 1.0 - re;
    reconVar2[c_i].im = im;
    if (c_i != 0) {
      wrapIndex[c_i] = (nRows - c_i) + 1;
    } else {
      wrapIndex[0] = 1;
    }
    bitrevIndex[c_i] = 0;
  }
  for (int c_i{0}; c_i <= iDelta; c_i++) {
    bitrevIndex[c_i] = iy;
    iy = nRows;
    tst = true;
    while (tst) {
      iy >>= 1;
      ju ^= iy;
      tst = ((ju & iy) == 0);
    }
    iy = ju + 1;
  }
  bitrevIndex[u0 - 1] = iy;
  if ((static_cast<unsigned int>(x.size(0)) & 1U) == 0U) {
    tst = true;
    hszCostab = x.size(0);
  } else if (x.size(0) >= unsigned_nRows) {
    tst = true;
    hszCostab = unsigned_nRows;
  } else {
    tst = false;
    hszCostab = x.size(0) - 1;
  }
  if (hszCostab > unsigned_nRows) {
    hszCostab = unsigned_nRows;
  }
  ju = hszCostab / 2;
  for (int c_i{0}; c_i < ju; c_i++) {
    hszCostab = xoffInit + (c_i << 1);
    y[bitrevIndex[c_i] - 1].re = x[hszCostab];
    y[bitrevIndex[c_i] - 1].im = x[hszCostab + 1];
  }
  if (!tst) {
    if (ju - 1 < 0) {
      hszCostab = xoffInit;
    } else {
      hszCostab = xoffInit + (ju << 1);
    }
    y[bitrevIndex[ju] - 1].re = x[hszCostab];
    y[bitrevIndex[ju] - 1].im = 0.0;
  }
  if (nRows > 1) {
    for (int c_i{0}; c_i <= iDelta2; c_i += 2) {
      re = y[c_i + 1].re;
      im = y[c_i + 1].im;
      temp_re = re;
      temp_im = im;
      b_re = y[c_i].re;
      b_im = y[c_i].im;
      re = b_re - re;
      im = b_im - im;
      y[c_i + 1].re = re;
      y[c_i + 1].im = im;
      b_re += temp_re;
      b_im += temp_im;
      y[c_i].re = b_re;
      y[c_i].im = b_im;
    }
  }
  iDelta = 2;
  iDelta2 = 4;
  iheight = ((k - 1) << 2) + 1;
  while (k > 0) {
    int d_i;
    for (d_i = 0; d_i < iheight; d_i += iDelta2) {
      hszCostab = d_i + iDelta;
      temp_re = y[hszCostab].re;
      temp_im = y[hszCostab].im;
      y[hszCostab].re = y[d_i].re - temp_re;
      y[hszCostab].im = y[d_i].im - temp_im;
      y[d_i].re = y[d_i].re + temp_re;
      y[d_i].im = y[d_i].im + temp_im;
    }
    hszCostab = 1;
    for (iy = k; iy < nRowsD2; iy += k) {
      temp2_re = hcostab[iy];
      temp2_im = hsintab[iy];
      d_i = hszCostab;
      ju = hszCostab + iheight;
      while (d_i < ju) {
        u0 = d_i + iDelta;
        re = y[u0].im;
        im = y[u0].re;
        temp_re = temp2_re * im - temp2_im * re;
        temp_im = temp2_re * re + temp2_im * im;
        y[u0].re = y[d_i].re - temp_re;
        y[u0].im = y[d_i].im - temp_im;
        y[d_i].re = y[d_i].re + temp_re;
        y[d_i].im = y[d_i].im + temp_im;
        d_i += iDelta2;
      }
      hszCostab++;
    }
    k = static_cast<int>(static_cast<unsigned int>(k) >> 1);
    iDelta = iDelta2;
    iDelta2 += iDelta2;
    iheight -= iDelta;
  }
  iy = nRows / 2;
  temp_re = y[0].re;
  temp_im = y[0].im;
  im = y[0].re * reconVar1[0].re;
  b_re = y[0].re * reconVar1[0].im;
  b_im = -y[0].im;
  temp2_re = temp_re * reconVar2[0].re;
  re = temp_re * reconVar2[0].im;
  y[0].re = 0.5 * ((im - y[0].im * reconVar1[0].im) +
                   (temp2_re - b_im * reconVar2[0].im));
  y[0].im = 0.5 * ((b_re + y[0].im * reconVar1[0].re) +
                   (re + b_im * reconVar2[0].re));
  y[nRows].re = 0.5 * ((temp2_re - temp_im * reconVar2[0].im) +
                       (im - b_im * reconVar1[0].im));
  y[nRows].im = 0.5 * ((re + temp_im * reconVar2[0].re) +
                       (b_re + b_im * reconVar1[0].re));
  for (int c_i{2}; c_i <= iy; c_i++) {
    temp_re = y[c_i - 1].re;
    temp_im = y[c_i - 1].im;
    hszCostab = wrapIndex[c_i - 1];
    temp2_re = y[hszCostab - 1].re;
    temp2_im = y[hszCostab - 1].im;
    re = reconVar1[c_i - 1].im;
    im = reconVar1[c_i - 1].re;
    b_re = reconVar2[c_i - 1].im;
    b_im = reconVar2[c_i - 1].re;
    y[c_i - 1].re = 0.5 * ((temp_re * im - temp_im * re) +
                           (temp2_re * b_im - -temp2_im * b_re));
    y[c_i - 1].im = 0.5 * ((temp_re * re + temp_im * im) +
                           (temp2_re * b_re + -temp2_im * b_im));
    ju = (nRows + c_i) - 1;
    y[ju].re = 0.5 * ((temp_re * b_im - temp_im * b_re) +
                      (temp2_re * im - -temp2_im * re));
    y[ju].im = 0.5 * ((temp_re * b_re + temp_im * b_im) +
                      (temp2_re * re + -temp2_im * im));
    re = reconVar1[hszCostab - 1].im;
    im = reconVar1[hszCostab - 1].re;
    b_re = reconVar2[hszCostab - 1].im;
    b_im = reconVar2[hszCostab - 1].re;
    y[hszCostab - 1].re = 0.5 * ((temp2_re * im - temp2_im * re) +
                                 (temp_re * b_im - -temp_im * b_re));
    y[hszCostab - 1].im = 0.5 * ((temp2_re * re + temp2_im * im) +
                                 (temp_re * b_re + -temp_im * b_im));
    hszCostab = (hszCostab + nRows) - 1;
    y[hszCostab].re = 0.5 * ((temp2_re * b_im - temp2_im * b_re) +
                             (temp_re * im - -temp_im * re));
    y[hszCostab].im = 0.5 * ((temp2_re * b_re + temp2_im * b_im) +
                             (temp_re * re + -temp_im * im));
  }
  if (iy != 0) {
    double b_y_re_tmp;
    double y_re_tmp;
    temp_re = y[iy].re;
    temp_im = y[iy].im;
    im = reconVar1[iy].im;
    b_re = reconVar1[iy].re;
    b_im = temp_re * b_re;
    temp2_re = temp_re * im;
    temp2_im = reconVar2[iy].im;
    y_re_tmp = reconVar2[iy].re;
    b_y_re_tmp = temp_re * y_re_tmp;
    re = temp_re * temp2_im;
    y[iy].re =
        0.5 * ((b_im - temp_im * im) + (b_y_re_tmp - -temp_im * temp2_im));
    y[iy].im = 0.5 * ((temp2_re + temp_im * b_re) + (re + -temp_im * y_re_tmp));
    hszCostab = nRows + iy;
    y[hszCostab].re =
        0.5 * ((b_y_re_tmp - temp_im * temp2_im) + (b_im - -temp_im * im));
    y[hszCostab].im =
        0.5 * ((re + temp_im * y_re_tmp) + (temp2_re + -temp_im * b_re));
  }
}

//
// Arguments    : const array<creal_T, 1U> &x
//                int unsigned_nRows
//                const array<double, 2U> &costab
//                const array<double, 2U> &sintab
//                array<creal_T, 1U> &y
// Return Type  : void
//
void FFTImplementationCallback::r2br_r2dit_trig_impl(
    const array<creal_T, 1U> &x, int unsigned_nRows,
    const array<double, 2U> &costab, const array<double, 2U> &sintab,
    array<creal_T, 1U> &y)
{
  double im;
  double re;
  double temp_im;
  double temp_re;
  int iDelta;
  int iDelta2;
  int iheight;
  int istart;
  int iy;
  int j;
  int ju;
  int k;
  int nRowsD2;
  y.set_size(unsigned_nRows);
  if (unsigned_nRows > x.size(0)) {
    y.set_size(unsigned_nRows);
    for (int i{0}; i < unsigned_nRows; i++) {
      y[i].re = 0.0;
      y[i].im = 0.0;
    }
  }
  j = x.size(0);
  if (j > unsigned_nRows) {
    j = unsigned_nRows;
  }
  iDelta = unsigned_nRows - 2;
  nRowsD2 = unsigned_nRows / 2;
  k = nRowsD2 / 2;
  iy = 0;
  ju = 0;
  for (int i{0}; i <= j - 2; i++) {
    boolean_T tst;
    y[iy] = x[i];
    istart = unsigned_nRows;
    tst = true;
    while (tst) {
      istart >>= 1;
      ju ^= istart;
      tst = ((ju & istart) == 0);
    }
    iy = ju;
  }
  if (j - 2 < 0) {
    istart = 0;
  } else {
    istart = j - 1;
  }
  y[iy] = x[istart];
  if (unsigned_nRows > 1) {
    for (int i{0}; i <= iDelta; i += 2) {
      temp_re = y[i + 1].re;
      temp_im = y[i + 1].im;
      re = y[i].re;
      im = y[i].im;
      y[i + 1].re = re - temp_re;
      y[i + 1].im = y[i].im - y[i + 1].im;
      re += temp_re;
      im += temp_im;
      y[i].re = re;
      y[i].im = im;
    }
  }
  iDelta = 2;
  iDelta2 = 4;
  iheight = ((k - 1) << 2) + 1;
  while (k > 0) {
    int b_i;
    for (b_i = 0; b_i < iheight; b_i += iDelta2) {
      istart = b_i + iDelta;
      temp_re = y[istart].re;
      temp_im = y[istart].im;
      y[istart].re = y[b_i].re - temp_re;
      y[istart].im = y[b_i].im - temp_im;
      y[b_i].re = y[b_i].re + temp_re;
      y[b_i].im = y[b_i].im + temp_im;
    }
    istart = 1;
    for (j = k; j < nRowsD2; j += k) {
      double twid_im;
      double twid_re;
      twid_re = costab[j];
      twid_im = sintab[j];
      b_i = istart;
      iy = istart + iheight;
      while (b_i < iy) {
        ju = b_i + iDelta;
        re = y[ju].im;
        im = y[ju].re;
        temp_re = twid_re * im - twid_im * re;
        temp_im = twid_re * re + twid_im * im;
        y[ju].re = y[b_i].re - temp_re;
        y[ju].im = y[b_i].im - temp_im;
        y[b_i].re = y[b_i].re + temp_re;
        y[b_i].im = y[b_i].im + temp_im;
        b_i += iDelta2;
      }
      istart++;
    }
    k = static_cast<int>(static_cast<unsigned int>(k) >> 1);
    iDelta = iDelta2;
    iDelta2 += iDelta2;
    iheight -= iDelta;
  }
}

//
// Arguments    : const array<double, 2U> &x
//                int n2blue
//                int nfft
//                const array<double, 2U> &costab
//                const array<double, 2U> &sintab
//                const array<double, 2U> &sintabinv
//                array<creal_T, 2U> &y
// Return Type  : void
//
void FFTImplementationCallback::dobluesteinfft(
    const array<double, 2U> &x, int n2blue, int nfft,
    const array<double, 2U> &costab, const array<double, 2U> &sintab,
    const array<double, 2U> &sintabinv, array<creal_T, 2U> &y)
{
  array<creal_T, 1U> b_fv;
  array<creal_T, 1U> fv;
  array<creal_T, 1U> r;
  array<creal_T, 1U> wwc;
  double b_re_tmp;
  double c_re_tmp;
  double d_re_tmp;
  double re_tmp;
  int a_re_tmp;
  int b_k;
  int b_y;
  int minNrowsNx;
  int rt;
  int xoff;
  if ((nfft != 1) && ((static_cast<unsigned int>(nfft) & 1U) == 0U)) {
    int b_nInt2m1;
    int nInt2;
    int nInt2m1;
    nInt2m1 = nfft / 2;
    b_nInt2m1 = (nInt2m1 + nInt2m1) - 1;
    wwc.set_size(b_nInt2m1);
    rt = 0;
    wwc[nInt2m1 - 1].re = 1.0;
    wwc[nInt2m1 - 1].im = 0.0;
    nInt2 = nInt2m1 << 1;
    for (int k{0}; k <= nInt2m1 - 2; k++) {
      double nt_im;
      double nt_re;
      b_y = ((k + 1) << 1) - 1;
      if (nInt2 - rt <= b_y) {
        rt += b_y - nInt2;
      } else {
        rt += b_y;
      }
      nt_im = -3.1415926535897931 * static_cast<double>(rt) /
              static_cast<double>(nInt2m1);
      nt_re = std::cos(nt_im);
      nt_im = std::sin(nt_im);
      b_y = (nInt2m1 - k) - 2;
      wwc[b_y].re = nt_re;
      wwc[b_y].im = -nt_im;
    }
    b_y = b_nInt2m1 - 1;
    for (int k{b_y}; k >= nInt2m1; k--) {
      wwc[k] = wwc[(b_nInt2m1 - k) - 1];
    }
  } else {
    int nInt2;
    int nInt2m1;
    nInt2m1 = (nfft + nfft) - 1;
    wwc.set_size(nInt2m1);
    rt = 0;
    wwc[nfft - 1].re = 1.0;
    wwc[nfft - 1].im = 0.0;
    nInt2 = nfft << 1;
    for (int k{0}; k <= nfft - 2; k++) {
      double nt_im;
      double nt_re;
      b_y = ((k + 1) << 1) - 1;
      if (nInt2 - rt <= b_y) {
        rt += b_y - nInt2;
      } else {
        rt += b_y;
      }
      nt_im = -3.1415926535897931 * static_cast<double>(rt) /
              static_cast<double>(nfft);
      nt_re = std::cos(nt_im);
      nt_im = std::sin(nt_im);
      b_y = (nfft - k) - 2;
      wwc[b_y].re = nt_re;
      wwc[b_y].im = -nt_im;
    }
    b_y = nInt2m1 - 1;
    for (int k{b_y}; k >= nfft; k--) {
      wwc[k] = wwc[(nInt2m1 - k) - 1];
    }
  }
  rt = x.size(0);
  y.set_size(nfft, x.size(1));
  if (nfft > x.size(0)) {
    y.set_size(nfft, x.size(1));
    b_y = nfft * x.size(1);
    for (int k{0}; k < b_y; k++) {
      y[k].re = 0.0;
      y[k].im = 0.0;
    }
  }
  b_y = x.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
        fv, b_fv, r, xoff, minNrowsNx, b_k, a_re_tmp, re_tmp, b_re_tmp,        \
            c_re_tmp, d_re_tmp)

  for (int chan = 0; chan < b_y; chan++) {
    xoff = chan * rt;
    r.set_size(nfft);
    if (nfft > x.size(0)) {
      r.set_size(nfft);
      std::memset(&r[0], 0, static_cast<unsigned int>(nfft) * sizeof(creal_T));
    }
    if ((n2blue != 1) && ((static_cast<unsigned int>(nfft) & 1U) == 0U)) {
      FFTImplementationCallback::doHalfLengthBluestein(
          x, xoff, r, x.size(0), nfft, n2blue, wwc, costab, sintab, costab,
          sintabinv);
    } else {
      minNrowsNx = x.size(0);
      if (nfft <= minNrowsNx) {
        minNrowsNx = nfft;
      }
      for (b_k = 0; b_k < minNrowsNx; b_k++) {
        a_re_tmp = (nfft + b_k) - 1;
        re_tmp = x[xoff + b_k];
        r[b_k].re = wwc[a_re_tmp].re * re_tmp;
        r[b_k].im = wwc[a_re_tmp].im * -re_tmp;
      }
      xoff = minNrowsNx + 1;
      if (xoff <= nfft) {
        std::memset(&r[xoff + -1], 0,
                    static_cast<unsigned int>((nfft - xoff) + 1) *
                        sizeof(creal_T));
      }
      FFTImplementationCallback::r2br_r2dit_trig_impl(r, n2blue, costab, sintab,
                                                      b_fv);
      FFTImplementationCallback::r2br_r2dit_trig_impl(wwc, n2blue, costab,
                                                      sintab, fv);
      xoff = b_fv.size(0);
      fv.set_size(b_fv.size(0));
      for (b_k = 0; b_k < xoff; b_k++) {
        re_tmp = b_fv[b_k].re;
        b_re_tmp = fv[b_k].im;
        c_re_tmp = b_fv[b_k].im;
        d_re_tmp = fv[b_k].re;
        fv[b_k].re = re_tmp * d_re_tmp - c_re_tmp * b_re_tmp;
        fv[b_k].im = re_tmp * b_re_tmp + c_re_tmp * d_re_tmp;
      }
      FFTImplementationCallback::r2br_r2dit_trig_impl(fv, n2blue, costab,
                                                      sintabinv, b_fv);
      if (b_fv.size(0) > 1) {
        re_tmp = 1.0 / static_cast<double>(b_fv.size(0));
        xoff = b_fv.size(0);
        for (b_k = 0; b_k < xoff; b_k++) {
          b_fv[b_k].re = re_tmp * b_fv[b_k].re;
          b_fv[b_k].im = re_tmp * b_fv[b_k].im;
        }
      }
      xoff = wwc.size(0);
      for (b_k = nfft; b_k <= xoff; b_k++) {
        re_tmp = wwc[b_k - 1].re;
        b_re_tmp = b_fv[b_k - 1].im;
        c_re_tmp = wwc[b_k - 1].im;
        d_re_tmp = b_fv[b_k - 1].re;
        minNrowsNx = b_k - nfft;
        r[minNrowsNx].re = re_tmp * d_re_tmp + c_re_tmp * b_re_tmp;
        r[minNrowsNx].im = re_tmp * b_re_tmp - c_re_tmp * d_re_tmp;
      }
    }
    xoff = y.size(0);
    for (b_k = 0; b_k < xoff; b_k++) {
      y[b_k + y.size(0) * chan] = r[b_k];
    }
  }
}

//
// Arguments    : const array<creal_T, 2U> &x
//                int n2blue
//                int nfft
//                const array<double, 2U> &costab
//                const array<double, 2U> &sintab
//                const array<double, 2U> &sintabinv
//                array<creal_T, 2U> &y
// Return Type  : void
//
void FFTImplementationCallback::dobluesteinfft(
    const array<creal_T, 2U> &x, int n2blue, int nfft,
    const array<double, 2U> &costab, const array<double, 2U> &sintab,
    const array<double, 2U> &sintabinv, array<creal_T, 2U> &y)
{
  array<creal_T, 1U> b_fv;
  array<creal_T, 1U> fv;
  array<creal_T, 1U> r;
  array<creal_T, 1U> wwc;
  double a_im;
  double a_re;
  double ar;
  double b_re_tmp;
  double re_tmp;
  int a_re_tmp;
  int b_k;
  int b_y;
  int minNrowsNx;
  int nInt2;
  int nInt2m1;
  int rt;
  int xoff;
  nInt2m1 = (nfft + nfft) - 1;
  wwc.set_size(nInt2m1);
  rt = 0;
  wwc[nfft - 1].re = 1.0;
  wwc[nfft - 1].im = 0.0;
  nInt2 = nfft << 1;
  for (int k{0}; k <= nfft - 2; k++) {
    double nt_im;
    double nt_re;
    b_y = ((k + 1) << 1) - 1;
    if (nInt2 - rt <= b_y) {
      rt += b_y - nInt2;
    } else {
      rt += b_y;
    }
    nt_im = 3.1415926535897931 * static_cast<double>(rt) /
            static_cast<double>(nfft);
    nt_re = std::cos(nt_im);
    nt_im = std::sin(nt_im);
    b_y = (nfft - k) - 2;
    wwc[b_y].re = nt_re;
    wwc[b_y].im = -nt_im;
  }
  b_y = nInt2m1 - 1;
  for (int k{b_y}; k >= nfft; k--) {
    wwc[k] = wwc[(nInt2m1 - k) - 1];
  }
  rt = x.size(0);
  y.set_size(nfft, x.size(1));
  if (nfft > x.size(0)) {
    y.set_size(nfft, x.size(1));
    b_y = nfft * x.size(1);
    for (int k{0}; k < b_y; k++) {
      y[k].re = 0.0;
      y[k].im = 0.0;
    }
  }
  b_y = x.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
        fv, b_fv, r, xoff, minNrowsNx, b_k, a_re_tmp, a_re, a_im, re_tmp,      \
            b_re_tmp, ar)

  for (int chan = 0; chan < b_y; chan++) {
    xoff = chan * rt;
    r.set_size(nfft);
    if (nfft > x.size(0)) {
      r.set_size(nfft);
      std::memset(&r[0], 0, static_cast<unsigned int>(nfft) * sizeof(creal_T));
    }
    minNrowsNx = x.size(0);
    if (nfft <= minNrowsNx) {
      minNrowsNx = nfft;
    }
    for (b_k = 0; b_k < minNrowsNx; b_k++) {
      a_re_tmp = (nfft + b_k) - 1;
      a_re = wwc[a_re_tmp].re;
      a_im = wwc[a_re_tmp].im;
      a_re_tmp = xoff + b_k;
      re_tmp = x[a_re_tmp].im;
      b_re_tmp = x[a_re_tmp].re;
      r[b_k].re = a_re * b_re_tmp + a_im * re_tmp;
      r[b_k].im = a_re * re_tmp - a_im * b_re_tmp;
    }
    a_re_tmp = minNrowsNx + 1;
    if (a_re_tmp <= nfft) {
      std::memset(&r[a_re_tmp + -1], 0,
                  static_cast<unsigned int>((nfft - a_re_tmp) + 1) *
                      sizeof(creal_T));
    }
    FFTImplementationCallback::r2br_r2dit_trig_impl(r, n2blue, costab, sintab,
                                                    b_fv);
    FFTImplementationCallback::r2br_r2dit_trig_impl(wwc, n2blue, costab, sintab,
                                                    fv);
    a_re_tmp = b_fv.size(0);
    fv.set_size(b_fv.size(0));
    for (b_k = 0; b_k < a_re_tmp; b_k++) {
      a_re = b_fv[b_k].re;
      a_im = fv[b_k].im;
      re_tmp = b_fv[b_k].im;
      b_re_tmp = fv[b_k].re;
      fv[b_k].re = a_re * b_re_tmp - re_tmp * a_im;
      fv[b_k].im = a_re * a_im + re_tmp * b_re_tmp;
    }
    FFTImplementationCallback::r2br_r2dit_trig_impl(fv, n2blue, costab,
                                                    sintabinv, b_fv);
    if (b_fv.size(0) > 1) {
      a_re = 1.0 / static_cast<double>(b_fv.size(0));
      a_re_tmp = b_fv.size(0);
      for (b_k = 0; b_k < a_re_tmp; b_k++) {
        b_fv[b_k].re = a_re * b_fv[b_k].re;
        b_fv[b_k].im = a_re * b_fv[b_k].im;
      }
    }
    xoff = wwc.size(0);
    for (b_k = nfft; b_k <= xoff; b_k++) {
      a_re = wwc[b_k - 1].re;
      a_im = b_fv[b_k - 1].im;
      re_tmp = wwc[b_k - 1].im;
      b_re_tmp = b_fv[b_k - 1].re;
      ar = a_re * b_re_tmp + re_tmp * a_im;
      a_re = a_re * a_im - re_tmp * b_re_tmp;
      if (a_re == 0.0) {
        a_re_tmp = b_k - nfft;
        r[a_re_tmp].re = ar / static_cast<double>(nfft);
        r[a_re_tmp].im = 0.0;
      } else if (ar == 0.0) {
        a_re_tmp = b_k - nfft;
        r[a_re_tmp].re = 0.0;
        r[a_re_tmp].im = a_re / static_cast<double>(nfft);
      } else {
        a_re_tmp = b_k - nfft;
        r[a_re_tmp].re = ar / static_cast<double>(nfft);
        r[a_re_tmp].im = a_re / static_cast<double>(nfft);
      }
    }
    a_re_tmp = y.size(0);
    for (b_k = 0; b_k < a_re_tmp; b_k++) {
      y[b_k + y.size(0) * chan] = r[b_k];
    }
  }
}

//
// Arguments    : int nfft
//                boolean_T useRadix2
//                int &nRows
// Return Type  : int
//
int FFTImplementationCallback::get_algo_sizes(int nfft, boolean_T useRadix2,
                                              int &nRows)
{
  int n2blue;
  n2blue = 1;
  if (useRadix2) {
    nRows = nfft;
  } else {
    if (nfft > 0) {
      int pmax;
      n2blue = (nfft + nfft) - 1;
      pmax = 31;
      if (n2blue <= 1) {
        pmax = 0;
      } else {
        int pmin;
        boolean_T exitg1;
        pmin = 0;
        exitg1 = false;
        while ((!exitg1) && (pmax - pmin > 1)) {
          int k;
          int pow2p;
          k = (pmin + pmax) >> 1;
          pow2p = 1 << k;
          if (pow2p == n2blue) {
            pmax = k;
            exitg1 = true;
          } else if (pow2p > n2blue) {
            pmax = k;
          } else {
            pmin = k;
          }
        }
      }
      n2blue = 1 << pmax;
    }
    nRows = n2blue;
  }
  return n2blue;
}

//
// Arguments    : const array<double, 2U> &x
//                int n1_unsigned
//                const array<double, 2U> &costab
//                const array<double, 2U> &sintab
//                array<creal_T, 2U> &y
// Return Type  : void
//
void FFTImplementationCallback::r2br_r2dit_trig(const array<double, 2U> &x,
                                                int n1_unsigned,
                                                const array<double, 2U> &costab,
                                                const array<double, 2U> &sintab,
                                                array<creal_T, 2U> &y)
{
  array<creal_T, 1U> r;
  int i1;
  int loop_ub;
  int nrows;
  int xoff;
  nrows = x.size(0);
  y.set_size(n1_unsigned, x.size(1));
  if (n1_unsigned > x.size(0)) {
    y.set_size(n1_unsigned, x.size(1));
    loop_ub = n1_unsigned * x.size(1);
    for (int i{0}; i < loop_ub; i++) {
      y[i].re = 0.0;
      y[i].im = 0.0;
    }
  }
  loop_ub = x.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(r, xoff, i1)

  for (int chan = 0; chan < loop_ub; chan++) {
    xoff = chan * nrows;
    r.set_size(n1_unsigned);
    if (n1_unsigned > x.size(0)) {
      r.set_size(n1_unsigned);
      std::memset(&r[0], 0,
                  static_cast<unsigned int>(n1_unsigned) * sizeof(creal_T));
    }
    if (n1_unsigned != 1) {
      FFTImplementationCallback::doHalfLengthRadix2(x, xoff, r, n1_unsigned,
                                                    costab, sintab);
    } else {
      r[0].re = x[xoff];
      r[0].im = 0.0;
    }
    xoff = y.size(0);
    for (i1 = 0; i1 < xoff; i1++) {
      y[i1 + y.size(0) * chan] = r[i1];
    }
  }
}

//
// Arguments    : const array<creal_T, 2U> &x
//                int n1_unsigned
//                const array<double, 2U> &costab
//                const array<double, 2U> &sintab
//                array<creal_T, 2U> &y
// Return Type  : void
//
void FFTImplementationCallback::r2br_r2dit_trig(const array<creal_T, 2U> &x,
                                                int n1_unsigned,
                                                const array<double, 2U> &costab,
                                                const array<double, 2U> &sintab,
                                                array<creal_T, 2U> &y)
{
  array<creal_T, 1U> r;
  double im;
  double re;
  double temp_im;
  double temp_re;
  double twid_im;
  double twid_re;
  int b_i;
  int c_i;
  int iDelta;
  int iDelta2;
  int iheight;
  int iy;
  int ju;
  int k;
  int loop_ub;
  int nRowsD2;
  int nrows;
  int u1;
  int xoff;
  boolean_T tst;
  nrows = x.size(0);
  y.set_size(n1_unsigned, x.size(1));
  if (n1_unsigned > x.size(0)) {
    y.set_size(n1_unsigned, x.size(1));
    loop_ub = n1_unsigned * x.size(1);
    for (int i{0}; i < loop_ub; i++) {
      y[i].re = 0.0;
      y[i].im = 0.0;
    }
  }
  loop_ub = x.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
        r, xoff, iy, u1, iDelta, nRowsD2, k, ju, b_i, tst, temp_re, temp_im,   \
            re, im, iDelta2, iheight, c_i, twid_re, twid_im)

  for (int chan = 0; chan < loop_ub; chan++) {
    xoff = chan * nrows;
    r.set_size(n1_unsigned);
    if (n1_unsigned > x.size(0)) {
      r.set_size(n1_unsigned);
      std::memset(&r[0], 0,
                  static_cast<unsigned int>(n1_unsigned) * sizeof(creal_T));
    }
    iy = x.size(0);
    u1 = n1_unsigned;
    if (iy <= n1_unsigned) {
      u1 = iy;
    }
    iDelta = n1_unsigned - 2;
    nRowsD2 = n1_unsigned / 2;
    k = nRowsD2 / 2;
    iy = 0;
    ju = 0;
    for (b_i = 0; b_i <= u1 - 2; b_i++) {
      r[iy] = x[xoff + b_i];
      iy = n1_unsigned;
      tst = true;
      while (tst) {
        iy >>= 1;
        ju ^= iy;
        tst = ((ju & iy) == 0);
      }
      iy = ju;
    }
    if (u1 - 2 >= 0) {
      xoff = (xoff + u1) - 1;
    }
    r[iy] = x[xoff];
    if (n1_unsigned > 1) {
      for (b_i = 0; b_i <= iDelta; b_i += 2) {
        temp_re = r[b_i + 1].re;
        temp_im = r[b_i + 1].im;
        re = r[b_i].re;
        im = r[b_i].im;
        r[b_i + 1].re = re - temp_re;
        r[b_i + 1].im = r[b_i].im - r[b_i + 1].im;
        re += temp_re;
        im += temp_im;
        r[b_i].re = re;
        r[b_i].im = im;
      }
    }
    iDelta = 2;
    iDelta2 = 4;
    iheight = ((k - 1) << 2) + 1;
    while (k > 0) {
      for (c_i = 0; c_i < iheight; c_i += iDelta2) {
        iy = c_i + iDelta;
        temp_re = r[iy].re;
        temp_im = r[iy].im;
        r[iy].re = r[c_i].re - temp_re;
        r[iy].im = r[c_i].im - temp_im;
        r[c_i].re = r[c_i].re + temp_re;
        r[c_i].im = r[c_i].im + temp_im;
      }
      iy = 1;
      for (ju = k; ju < nRowsD2; ju += k) {
        twid_re = costab[ju];
        twid_im = sintab[ju];
        c_i = iy;
        xoff = iy + iheight;
        while (c_i < xoff) {
          u1 = c_i + iDelta;
          re = r[u1].im;
          im = r[u1].re;
          temp_re = twid_re * im - twid_im * re;
          temp_im = twid_re * re + twid_im * im;
          r[u1].re = r[c_i].re - temp_re;
          r[u1].im = r[c_i].im - temp_im;
          r[c_i].re = r[c_i].re + temp_re;
          r[c_i].im = r[c_i].im + temp_im;
          c_i += iDelta2;
        }
        iy++;
      }
      k = static_cast<int>(static_cast<unsigned int>(k) >> 1);
      iDelta = iDelta2;
      iDelta2 += iDelta2;
      iheight -= iDelta;
    }
    iy = y.size(0);
    for (b_i = 0; b_i < iy; b_i++) {
      y[b_i + y.size(0) * chan] = r[b_i];
    }
  }
  if (y.size(0) > 1) {
    double b;
    b = 1.0 / static_cast<double>(y.size(0));
    loop_ub = y.size(0) * y.size(1);
    if (static_cast<int>(loop_ub < 2000)) {
      for (int i1{0}; i1 < loop_ub; i1++) {
        y[i1].re = b * y[i1].re;
        y[i1].im = b * y[i1].im;
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i1 = 0; i1 < loop_ub; i1++) {
        y[i1].re = b * y[i1].re;
        y[i1].im = b * y[i1].im;
      }
    }
  }
}

} // namespace fft
} // namespace internal
} // namespace coder

//
// File trailer for FFTImplementationCallback.cpp
//
// [EOF]
//
