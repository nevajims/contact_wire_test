//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: interp1.cpp
//
// MATLAB Coder version            : 25.1
// C/C++ source code generated on  : 24-Mar-2026 22:30:21
//

// Include Files
#include "interp1.h"
#include "bsearch.h"
#include "fn_process_rail_data_DLL_data.h"
#include "pchip.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "omp.h"
#include <cmath>
#include <emmintrin.h>

// Function Declarations
namespace coder {
static void interp1Linear(const array<double, 1U> &y,
                          const array<double, 1U> &xi, array<double, 1U> &yi,
                          const array<double, 2U> &varargin_1);

static void interp1Linear(const array<creal_T, 1U> &y,
                          const array<double, 1U> &xi, array<creal_T, 1U> &yi,
                          const array<double, 1U> &varargin_1);

} // namespace coder

// Function Definitions
//
// Arguments    : const array<double, 1U> &y
//                const array<double, 1U> &xi
//                array<double, 1U> &yi
//                const array<double, 2U> &varargin_1
// Return Type  : void
//
namespace coder {
static void interp1Linear(const array<double, 1U> &y,
                          const array<double, 1U> &xi, array<double, 1U> &yi,
                          const array<double, 2U> &varargin_1)
{
  double d;
  double maxx;
  double minx;
  double r;
  int n;
  int ub_loop;
  minx = varargin_1[0];
  maxx = varargin_1[varargin_1.size(1) - 1];
  ub_loop = xi.size(0);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(n, r, d)

  for (int k = 0; k < ub_loop; k++) {
    if (std::isnan(xi[k])) {
      yi[k] = rtNaN;
    } else if ((!(xi[k] > maxx)) && (!(xi[k] < minx))) {
      n = internal::b_bsearch(varargin_1, xi[k]) - 1;
      r = (xi[k] - varargin_1[n]) / (varargin_1[n + 1] - varargin_1[n]);
      if (r == 0.0) {
        yi[k] = y[n];
      } else if (r == 1.0) {
        yi[k] = y[n + 1];
      } else {
        d = y[n + 1];
        if (y[n] == d) {
          yi[k] = y[n];
        } else {
          yi[k] = (1.0 - r) * y[n] + r * d;
        }
      }
    }
  }
}

//
// Arguments    : const array<creal_T, 1U> &y
//                const array<double, 1U> &xi
//                array<creal_T, 1U> &yi
//                const array<double, 1U> &varargin_1
// Return Type  : void
//
static void interp1Linear(const array<creal_T, 1U> &y,
                          const array<double, 1U> &xi, array<creal_T, 1U> &yi,
                          const array<double, 1U> &varargin_1)
{
  double b_y_tmp;
  double maxx;
  double minx;
  double r;
  double y1_im;
  double y1_re;
  double y_tmp;
  int high_i;
  int low_i;
  int low_ip1;
  int mid_i;
  int ub_loop;
  minx = varargin_1[0];
  maxx = varargin_1[varargin_1.size(0) - 1];
  ub_loop = xi.size(0);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
        y1_re, y1_im, high_i, low_i, low_ip1, mid_i, r, y_tmp, b_y_tmp)

  for (int k = 0; k < ub_loop; k++) {
    y1_re = yi[k].re;
    y1_im = yi[k].im;
    if (std::isnan(xi[k])) {
      y1_re = rtNaN;
      y1_im = rtNaN;
    } else if ((!(xi[k] > maxx)) && (!(xi[k] < minx))) {
      high_i = varargin_1.size(0);
      low_i = 1;
      low_ip1 = 2;
      while (high_i > low_ip1) {
        mid_i = (low_i >> 1) + (high_i >> 1);
        if (((static_cast<unsigned int>(low_i) & 1U) == 1U) &&
            ((static_cast<unsigned int>(high_i) & 1U) == 1U)) {
          mid_i++;
        }
        if (xi[k] >= varargin_1[mid_i - 1]) {
          low_i = mid_i;
          low_ip1 = mid_i + 1;
        } else {
          high_i = mid_i;
        }
      }
      y1_re = varargin_1[low_i - 1];
      r = (xi[k] - y1_re) / (varargin_1[low_i] - y1_re);
      if (r == 0.0) {
        y1_re = y[low_i - 1].re;
        y1_im = y[low_i - 1].im;
      } else if (r == 1.0) {
        y1_re = y[low_i].re;
        y1_im = y[low_i].im;
      } else {
        y1_re = y[low_i - 1].re;
        y1_im = y[low_i - 1].im;
        y_tmp = y[low_i].re;
        b_y_tmp = y[low_i].im;
        if ((!(y1_re == y_tmp)) || (!(y1_im == b_y_tmp))) {
          y1_re = (1.0 - r) * y1_re + r * y_tmp;
          y1_im = (1.0 - r) * y1_im + r * b_y_tmp;
        }
      }
    }
    yi[k].re = y1_re;
    yi[k].im = y1_im;
  }
}

//
// Arguments    : const array<double, 1U> &varargin_1
//                const array<creal_T, 2U> &varargin_2
//                double varargin_3
//                array<creal_T, 2U> &Vq
// Return Type  : void
//
void interp1(const array<double, 1U> &varargin_1,
             const array<creal_T, 2U> &varargin_2, double varargin_3,
             array<creal_T, 2U> &Vq)
{
  array<creal_T, 3U> pp_coefs;
  array<creal_T, 2U> del;
  array<creal_T, 2U> slopes;
  array<creal_T, 2U> yp;
  array<creal_T, 1U> yi;
  array<double, 2U> h;
  array<double, 1U> x;
  double ai;
  double dxj;
  double dzzdx_im;
  double dzzdx_re;
  double re;
  double tmp_im;
  double tmp_re;
  double w2;
  double xtmp;
  int b_loop_ub;
  int c0;
  int c1;
  int c2;
  int loop_ub;
  int n;
  int nx;
  int nxm1;
  int nyrows;
  int offset;
  c2 = varargin_2.size(0);
  loop_ub = varargin_2.size(1);
  slopes.set_size(varargin_2.size(0), varargin_2.size(1));
  nx = varargin_2.size(0) * varargin_2.size(1);
  for (int j{0}; j < nx; j++) {
    slopes[j] = varargin_2[j];
  }
  b_loop_ub = varargin_1.size(0);
  x.set_size(varargin_1.size(0));
  for (int j{0}; j < b_loop_ub; j++) {
    x[j] = varargin_1[j];
  }
  nx = varargin_1.size(0) - 1;
  if (varargin_1[1] < varargin_1[0]) {
    n = varargin_1.size(0) >> 1;
    for (int b_j1{0}; b_j1 < n; b_j1++) {
      xtmp = x[b_j1];
      offset = nx - b_j1;
      x[b_j1] = x[offset];
      x[offset] = xtmp;
    }
    if ((varargin_2.size(0) != 0) && (varargin_2.size(1) != 0) &&
        (varargin_2.size(0) > 1)) {
      n = varargin_2.size(0) - 1;
      nx = varargin_2.size(0) >> 1;
      for (int j{0}; j < loop_ub; j++) {
        offset = j * slopes.size(0);
        for (int b_j1{0}; b_j1 < nx; b_j1++) {
          c0 = offset + b_j1;
          tmp_re = slopes[c0].re;
          tmp_im = slopes[c0].im;
          nyrows = (offset + n) - b_j1;
          slopes[c0] = slopes[nyrows];
          slopes[nyrows].re = tmp_re;
          slopes[nyrows].im = tmp_im;
        }
      }
    }
  }
  yp.set_size(varargin_2.size(1), varargin_2.size(0));
  for (int j{0}; j < c2; j++) {
    for (int b_j1{0}; b_j1 < loop_ub; b_j1++) {
      yp[b_j1 + yp.size(0) * j] = slopes[j + slopes.size(0) * b_j1];
    }
  }
  nxm1 = x.size(0) - 2;
  h.set_size(1, varargin_1.size(0) - 1);
  nx = ((x.size(0) - 1) / 2) << 1;
  n = nx - 2;
  for (int j{0}; j <= n; j += 2) {
    __m128d r;
    __m128d r1;
    r = _mm_loadu_pd(&x[j + 1]);
    r1 = _mm_loadu_pd(&x[j]);
    _mm_storeu_pd(&h[j], _mm_sub_pd(r, r1));
  }
  for (int j{nx}; j <= nxm1; j++) {
    h[j] = x[j + 1] - x[j];
  }
  del.set_size(varargin_2.size(1), yp.size(1) - 1);
  for (int j{0}; j <= nxm1; j++) {
    c1 = j * loop_ub - 1;
    c2 = (j + 1) * loop_ub;
    for (int b_j1{0}; b_j1 < loop_ub; b_j1++) {
      n = c2 + b_j1;
      c0 = (c1 + b_j1) + 1;
      xtmp = yp[n].re - yp[c0].re;
      ai = yp[n].im - yp[c0].im;
      w2 = h[j];
      if (ai == 0.0) {
        del[c0].re = xtmp / w2;
        del[c0].im = 0.0;
      } else if (xtmp == 0.0) {
        del[c0].re = 0.0;
        del[c0].im = ai / w2;
      } else {
        del[c0].re = xtmp / w2;
        del[c0].im = ai / w2;
      }
    }
  }
  slopes.set_size(yp.size(0), yp.size(1));
  if (x.size(0) == 2) {
    for (int j{0}; j < 2; j++) {
      c1 = j * loop_ub;
      for (int b_j1{0}; b_j1 < loop_ub; b_j1++) {
        slopes[c1 + b_j1] = del[b_j1];
      }
    }
  } else {
    nyrows = x.size(0) - 3;
    for (int b_j1{0}; b_j1 <= nyrows; b_j1++) {
      xtmp = h[b_j1 + 1];
      ai = h[b_j1];
      dxj = 2.0 * xtmp + ai;
      w2 = xtmp + 2.0 * ai;
      c1 = b_j1 * loop_ub;
      c2 = (b_j1 + 1) * loop_ub - 1;
      for (int j{0}; j < loop_ub; j++) {
        n = c1 + j;
        tmp_re = del[n].re;
        tmp_im = del[n].im;
        n = (c2 + j) + 1;
        dzzdx_re = del[n].re;
        dzzdx_im = del[n].im;
        re = 0.0;
        xtmp = tmp_re * dzzdx_re;
        if (!std::isnan(xtmp)) {
          if (xtmp < 0.0) {
            xtmp = -1.0;
          } else {
            xtmp = (xtmp > 0.0);
          }
        }
        if (xtmp > 0.0) {
          re = (dxj + w2) / (dxj / tmp_re + w2 / dzzdx_re);
        }
        xtmp = 0.0;
        ai = tmp_im * dzzdx_im;
        if (!std::isnan(ai)) {
          if (ai < 0.0) {
            ai = -1.0;
          } else {
            ai = (ai > 0.0);
          }
        }
        if (ai > 0.0) {
          xtmp = (dxj + w2) / (dxj / tmp_im + w2 / dzzdx_im);
        }
        slopes[n].re = re;
        slopes[n].im = xtmp;
      }
    }
    c0 = (x.size(0) - 1) * yp.size(0);
    c1 = (x.size(0) - 2) * yp.size(0);
    c2 = (x.size(0) - 3) * yp.size(0);
    for (int b_j1{0}; b_j1 < loop_ub; b_j1++) {
      n = b_j1 + loop_ub;
      xtmp = h[0];
      ai = h[1];
      slopes[b_j1].re = realExteriorSlope(del[b_j1].re, del[n].re, xtmp, ai);
      slopes[b_j1].im = realExteriorSlope(del[b_j1].im, del[n].im, xtmp, ai);
      nx = b_j1 + c1;
      n = b_j1 + c2;
      offset = b_j1 + c0;
      slopes[offset].re =
          realExteriorSlope(del[nx].re, del[n].re, h[nxm1], h[nyrows]);
      slopes[offset].im =
          realExteriorSlope(del[nx].im, del[n].im, h[nxm1], h[nyrows]);
    }
  }
  nyrows = slopes.size(0);
  c2 = slopes.size(0) * (x.size(0) - 1);
  pp_coefs.set_size(slopes.size(0), varargin_1.size(0) - 1, 4);
  for (int b_j1{0}; b_j1 <= b_loop_ub - 2; b_j1++) {
    dxj = h[b_j1];
    nx = b_j1 * nyrows - 1;
    for (int j{0}; j < nyrows; j++) {
      offset = (nx + j) + 1;
      tmp_re = del[offset].re;
      tmp_im = del[offset].im;
      xtmp = tmp_re - slopes[offset].re;
      ai = tmp_im - slopes[offset].im;
      if (ai == 0.0) {
        dzzdx_re = xtmp / dxj;
        dzzdx_im = 0.0;
      } else if (xtmp == 0.0) {
        dzzdx_re = 0.0;
        dzzdx_im = ai / dxj;
      } else {
        dzzdx_re = xtmp / dxj;
        dzzdx_im = ai / dxj;
      }
      n = ((nx + nyrows) + j) + 1;
      xtmp = slopes[n].re - tmp_re;
      ai = slopes[n].im - tmp_im;
      if (ai == 0.0) {
        re = xtmp / dxj;
        xtmp = 0.0;
      } else if (xtmp == 0.0) {
        re = 0.0;
        xtmp = ai / dxj;
      } else {
        re = xtmp / dxj;
        xtmp = ai / dxj;
      }
      ai = re - dzzdx_re;
      w2 = xtmp - dzzdx_im;
      if (w2 == 0.0) {
        pp_coefs[offset].re = ai / dxj;
        pp_coefs[offset].im = 0.0;
      } else if (ai == 0.0) {
        pp_coefs[offset].re = 0.0;
        pp_coefs[offset].im = w2 / dxj;
      } else {
        pp_coefs[offset].re = ai / dxj;
        pp_coefs[offset].im = w2 / dxj;
      }
      n = ((c2 + nx) + j) + 1;
      pp_coefs[n].re = 2.0 * dzzdx_re - re;
      pp_coefs[n].im = 2.0 * dzzdx_im - xtmp;
      pp_coefs[(((c2 << 1) + nx) + j) + 1] = slopes[offset];
      pp_coefs[((3 * c2 + nx) + j) + 1] = yp[offset];
    }
  }
  yi.set_size(slopes.size(0));
  if (pp_coefs.size(0) == 1) {
    if (std::isnan(varargin_3)) {
      tmp_re = rtNaN;
      tmp_im = 0.0;
    } else {
      h = x.reshape(1, varargin_1.size(0));
      n = internal::b_bsearch(h, varargin_3) - 1;
      xtmp = varargin_3 - x[n];
      offset = n + c2;
      c0 = n + (c2 << 1);
      nx = n + 3 * c2;
      tmp_re = xtmp * (xtmp * (xtmp * pp_coefs[n].re + pp_coefs[offset].re) +
                       pp_coefs[c0].re) +
               pp_coefs[nx].re;
      tmp_im = xtmp * (xtmp * (xtmp * pp_coefs[n].im + pp_coefs[offset].im) +
                       pp_coefs[c0].im) +
               pp_coefs[nx].im;
    }
    yi[0].re = tmp_re;
    yi[0].im = tmp_im;
  } else if (std::isnan(varargin_3)) {
    for (int j{0}; j < nyrows; j++) {
      yi[j].re = rtNaN;
      yi[j].im = 0.0;
    }
  } else {
    h = x.reshape(1, varargin_1.size(0));
    nx = internal::b_bsearch(h, varargin_3) - 1;
    offset = nx * pp_coefs.size(0);
    xtmp = varargin_3 - x[nx];
    for (int j{0}; j < nyrows; j++) {
      yi[j] = pp_coefs[offset + j];
    }
    for (int j{0}; j < 3; j++) {
      n = offset + (j + 1) * c2;
      for (int b_j1{0}; b_j1 < nyrows; b_j1++) {
        c0 = n + b_j1;
        yi[b_j1].re = xtmp * yi[b_j1].re + pp_coefs[c0].re;
        yi[b_j1].im = xtmp * yi[b_j1].im + pp_coefs[c0].im;
      }
    }
  }
  Vq.set_size(1, varargin_2.size(1));
  for (int j{0}; j < loop_ub; j++) {
    Vq[j] = yi[j];
  }
}

//
// Arguments    : const array<double, 2U> &varargin_1
//                const array<creal_T, 2U> &varargin_2
//                double varargin_3
//                array<creal_T, 2U> &Vq
// Return Type  : void
//
void interp1(const array<double, 2U> &varargin_1,
             const array<creal_T, 2U> &varargin_2, double varargin_3,
             array<creal_T, 2U> &Vq)
{
  array<creal_T, 2U> y;
  array<double, 2U> x;
  creal_T tmp;
  creal_T y2;
  double xtmp;
  int b_tmp_tmp;
  int loop_ub;
  int n;
  int nx;
  int nyrows;
  nyrows = varargin_2.size(0);
  loop_ub = varargin_2.size(1);
  y.set_size(varargin_2.size(0), varargin_2.size(1));
  n = varargin_2.size(0) * varargin_2.size(1);
  for (int b_j1{0}; b_j1 < n; b_j1++) {
    y[b_j1] = varargin_2[b_j1];
  }
  n = varargin_1.size(1);
  x.set_size(1, varargin_1.size(1));
  for (int b_j1{0}; b_j1 < n; b_j1++) {
    x[b_j1] = varargin_1[b_j1];
  }
  nx = varargin_1.size(1) - 1;
  Vq.set_size(1, varargin_2.size(1));
  for (int b_j1{0}; b_j1 < loop_ub; b_j1++) {
    Vq[b_j1].re = rtNaN;
    Vq[b_j1].im = rtNaN;
  }
  if (varargin_1[1] < varargin_1[0]) {
    int nd2;
    n = varargin_1.size(1) >> 1;
    for (int b_j1{0}; b_j1 < n; b_j1++) {
      xtmp = x[b_j1];
      nd2 = nx - b_j1;
      x[b_j1] = x[nd2];
      x[nd2] = xtmp;
    }
    if ((varargin_2.size(0) != 0) && (varargin_2.size(1) != 0) &&
        (varargin_2.size(0) > 1)) {
      n = varargin_2.size(0) - 1;
      nd2 = varargin_2.size(0) >> 1;
      for (int b_j1{0}; b_j1 < loop_ub; b_j1++) {
        nx = b_j1 * y.size(0);
        for (int k{0}; k < nd2; k++) {
          int i;
          int tmp_tmp;
          tmp_tmp = nx + k;
          tmp = y[tmp_tmp];
          i = (nx + n) - k;
          y[tmp_tmp] = y[i];
          y[i] = tmp;
        }
      }
    }
  }
  if (std::isnan(varargin_3)) {
    for (int b_j1{0}; b_j1 < loop_ub; b_j1++) {
      Vq[b_j1].re = rtNaN;
      Vq[b_j1].im = rtNaN;
    }
  } else if ((!(varargin_3 > x[varargin_1.size(1) - 1])) &&
             (!(varargin_3 < x[0]))) {
    nx = internal::b_bsearch(x, varargin_3);
    xtmp = x[nx - 1];
    xtmp = (varargin_3 - xtmp) / (x[nx] - xtmp);
    if (xtmp == 0.0) {
      for (int b_j1{0}; b_j1 < loop_ub; b_j1++) {
        Vq[b_j1] = y[(nx + b_j1 * nyrows) - 1];
      }
    } else if (xtmp == 1.0) {
      for (int b_j1{0}; b_j1 < loop_ub; b_j1++) {
        Vq[b_j1] = y[nx + b_j1 * nyrows];
      }
    } else {
      n = varargin_2.size(1);
      if (static_cast<int>(varargin_2.size(1) < 2000)) {
        for (int j{0}; j < loop_ub; j++) {
          n = nx + j * nyrows;
          tmp = y[n - 1];
          y2 = y[n];
          if ((tmp.re == y2.re) && (tmp.im == y2.im)) {
            Vq[j] = tmp;
          } else {
            Vq[j].re = (1.0 - xtmp) * tmp.re + xtmp * y2.re;
            Vq[j].im = (1.0 - xtmp) * tmp.im + xtmp * y2.im;
          }
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
        y2, tmp, b_tmp_tmp)

        for (int j = 0; j < n; j++) {
          b_tmp_tmp = nx + j * nyrows;
          tmp = y[b_tmp_tmp - 1];
          y2 = y[b_tmp_tmp];
          if ((tmp.re == y2.re) && (tmp.im == y2.im)) {
            Vq[j] = tmp;
          } else {
            Vq[j].re = (1.0 - xtmp) * tmp.re + xtmp * y2.re;
            Vq[j].im = (1.0 - xtmp) * tmp.im + xtmp * y2.im;
          }
        }
      }
    }
  }
}

//
// Arguments    : const array<double, 1U> &varargin_1
//                const array<double, 1U> &varargin_2
//                double varargin_3
// Return Type  : double
//
double interp1(const array<double, 1U> &varargin_1,
               const array<double, 1U> &varargin_2, double varargin_3)
{
  array<double, 2U> del;
  array<double, 2U> h;
  array<double, 2U> pp_coefs;
  array<double, 2U> slopes;
  array<double, 1U> x;
  array<double, 1U> y;
  double Vq;
  double b_d1;
  double b_signd1;
  double b_x;
  double d;
  double dzzdx;
  double signd1;
  double w1;
  double w2;
  int i;
  int loop_ub;
  int n;
  int nd2;
  int nx;
  int nxm1;
  n = varargin_2.size(0);
  y.set_size(varargin_2.size(0));
  for (int b_j1{0}; b_j1 < n; b_j1++) {
    y[b_j1] = varargin_2[b_j1];
  }
  loop_ub = varargin_1.size(0);
  x.set_size(varargin_1.size(0));
  for (int b_j1{0}; b_j1 < loop_ub; b_j1++) {
    x[b_j1] = varargin_1[b_j1];
  }
  nx = varargin_1.size(0) - 1;
  if (varargin_1[1] < varargin_1[0]) {
    n = varargin_1.size(0) >> 1;
    for (int b_j1{0}; b_j1 < n; b_j1++) {
      Vq = x[b_j1];
      nd2 = nx - b_j1;
      x[b_j1] = x[nd2];
      x[nd2] = Vq;
    }
    if (varargin_2.size(0) > 1) {
      n = varargin_2.size(0) - 1;
      nd2 = varargin_2.size(0) >> 1;
      for (int b_j1{0}; b_j1 < nd2; b_j1++) {
        Vq = y[b_j1];
        nxm1 = n - b_j1;
        y[b_j1] = y[nxm1];
        y[nxm1] = Vq;
      }
    }
  }
  nxm1 = x.size(0) - 2;
  h.set_size(1, varargin_1.size(0) - 1);
  i = y.size(0) - 1;
  del.set_size(1, y.size(0) - 1);
  n = ((x.size(0) - 1) / 2) << 1;
  nd2 = n - 2;
  for (int b_j1{0}; b_j1 <= nd2; b_j1 += 2) {
    __m128d r;
    __m128d r1;
    __m128d r2;
    r = _mm_loadu_pd(&x[b_j1 + 1]);
    r1 = _mm_loadu_pd(&x[b_j1]);
    r = _mm_sub_pd(r, r1);
    _mm_storeu_pd(&h[b_j1], r);
    r1 = _mm_loadu_pd(&y[b_j1 + 1]);
    r2 = _mm_loadu_pd(&y[b_j1]);
    _mm_storeu_pd(&del[b_j1], _mm_div_pd(_mm_sub_pd(r1, r2), r));
  }
  for (int b_j1{n}; b_j1 <= nxm1; b_j1++) {
    Vq = x[b_j1 + 1] - x[b_j1];
    h[b_j1] = Vq;
    del[b_j1] = (y[b_j1 + 1] - y[b_j1]) / Vq;
  }
  slopes.set_size(1, varargin_2.size(0));
  if (x.size(0) == 2) {
    slopes[0] = del[0];
    slopes[1] = del[0];
  } else {
    double d1;
    n = varargin_1.size(0);
    if (static_cast<int>(x.size(0) - 2 < 2000)) {
      for (int k{0}; k <= loop_ub - 3; k++) {
        w2 = h[k + 1];
        b_d1 = h[k];
        w1 = 2.0 * w2 + b_d1;
        w2 += 2.0 * b_d1;
        slopes[k + 1] = 0.0;
        b_d1 = del[k];
        d = del[k + 1];
        b_x = b_d1 * d;
        if (!std::isnan(b_x)) {
          if (b_x < 0.0) {
            b_x = -1.0;
          } else {
            b_x = (b_x > 0.0);
          }
        }
        if (b_x > 0.0) {
          slopes[k + 1] = (w1 + w2) / (w1 / b_d1 + w2 / d);
        }
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
        b_x, d, b_d1, w2, w1)

      for (int k = 0; k <= n - 3; k++) {
        w2 = h[k + 1];
        b_d1 = h[k];
        w1 = 2.0 * w2 + b_d1;
        w2 += 2.0 * b_d1;
        slopes[k + 1] = 0.0;
        b_d1 = del[k];
        d = del[k + 1];
        b_x = b_d1 * d;
        if (!std::isnan(b_x)) {
          if (b_x < 0.0) {
            b_x = -1.0;
          } else {
            b_x = (b_x > 0.0);
          }
        }
        if (b_x > 0.0) {
          slopes[k + 1] = (w1 + w2) / (w1 / b_d1 + w2 / d);
        }
      }
    }
    d1 = del[0];
    dzzdx = del[1];
    Vq = h[0];
    signd1 = h[1];
    b_signd1 = ((2.0 * Vq + signd1) * d1 - Vq * dzzdx) / (Vq + signd1);
    if (std::isnan(d1)) {
      signd1 = rtNaN;
    } else if (d1 < 0.0) {
      signd1 = -1.0;
    } else {
      signd1 = (d1 > 0.0);
    }
    if (std::isnan(b_signd1)) {
      Vq = rtNaN;
    } else if (b_signd1 < 0.0) {
      Vq = -1.0;
    } else {
      Vq = (b_signd1 > 0.0);
    }
    if (Vq != signd1) {
      b_signd1 = 0.0;
    } else {
      if (std::isnan(dzzdx)) {
        Vq = rtNaN;
      } else if (dzzdx < 0.0) {
        Vq = -1.0;
      } else {
        Vq = (dzzdx > 0.0);
      }
      if (signd1 != Vq) {
        Vq = 3.0 * d1;
        if (std::abs(b_signd1) > std::abs(Vq)) {
          b_signd1 = Vq;
        }
      }
    }
    slopes[0] = b_signd1;
    d1 = del[nxm1];
    dzzdx = del[x.size(0) - 3];
    Vq = h[nxm1];
    signd1 = h[x.size(0) - 3];
    signd1 = ((2.0 * Vq + signd1) * d1 - Vq * dzzdx) / (Vq + signd1);
    if (std::isnan(d1)) {
      b_signd1 = rtNaN;
    } else if (d1 < 0.0) {
      b_signd1 = -1.0;
    } else {
      b_signd1 = (d1 > 0.0);
    }
    if (std::isnan(signd1)) {
      Vq = rtNaN;
    } else if (signd1 < 0.0) {
      Vq = -1.0;
    } else {
      Vq = (signd1 > 0.0);
    }
    if (Vq != b_signd1) {
      signd1 = 0.0;
    } else {
      if (std::isnan(dzzdx)) {
        Vq = rtNaN;
      } else if (dzzdx < 0.0) {
        Vq = -1.0;
      } else {
        Vq = (dzzdx > 0.0);
      }
      if (b_signd1 != Vq) {
        Vq = 3.0 * d1;
        if (std::abs(signd1) > std::abs(Vq)) {
          signd1 = Vq;
        }
      }
    }
    slopes[nx] = signd1;
  }
  pp_coefs.set_size(i, 4);
  for (int b_j1{0}; b_j1 <= loop_ub - 2; b_j1++) {
    Vq = del[b_j1];
    signd1 = slopes[b_j1];
    b_signd1 = h[b_j1];
    dzzdx = (Vq - signd1) / b_signd1;
    Vq = (slopes[b_j1 + 1] - Vq) / b_signd1;
    pp_coefs[b_j1] = (Vq - dzzdx) / b_signd1;
    pp_coefs[i + b_j1] = 2.0 * dzzdx - Vq;
    pp_coefs[(i << 1) + b_j1] = signd1;
    pp_coefs[3 * i + b_j1] = y[b_j1];
  }
  if (std::isnan(varargin_3)) {
    Vq = rtNaN;
  } else {
    h = x.reshape(1, loop_ub);
    n = internal::b_bsearch(h, varargin_3) - 1;
    Vq = varargin_3 - x[n];
    Vq = Vq * (Vq * (Vq * pp_coefs[n] + pp_coefs[(n + x.size(0)) - 1]) +
               pp_coefs[n + ((x.size(0) - 1) << 1)]) +
         pp_coefs[n + 3 * (x.size(0) - 1)];
  }
  return Vq;
}

//
// Arguments    : const array<double, 2U> &varargin_1
//                const array<double, 1U> &varargin_2
//                const array<double, 1U> &varargin_3
//                array<double, 1U> &Vq
// Return Type  : void
//
void interp1(const array<double, 2U> &varargin_1,
             const array<double, 1U> &varargin_2,
             const array<double, 1U> &varargin_3, array<double, 1U> &Vq)
{
  array<double, 2U> x;
  array<double, 1U> y;
  int n;
  int nx;
  n = varargin_2.size(0);
  y.set_size(varargin_2.size(0));
  for (int b_j1{0}; b_j1 < n; b_j1++) {
    y[b_j1] = varargin_2[b_j1];
  }
  n = varargin_1.size(1);
  x.set_size(1, varargin_1.size(1));
  for (int b_j1{0}; b_j1 < n; b_j1++) {
    x[b_j1] = varargin_1[b_j1];
  }
  nx = varargin_1.size(1) - 1;
  n = varargin_3.size(0);
  Vq.set_size(varargin_3.size(0));
  for (int b_j1{0}; b_j1 < n; b_j1++) {
    Vq[b_j1] = 0.0;
  }
  if (varargin_3.size(0) != 0) {
    if (varargin_1[1] < varargin_1[0]) {
      double xtmp;
      int nd2;
      n = varargin_1.size(1) >> 1;
      for (int b_j1{0}; b_j1 < n; b_j1++) {
        xtmp = x[b_j1];
        nd2 = nx - b_j1;
        x[b_j1] = x[nd2];
        x[nd2] = xtmp;
      }
      if (varargin_2.size(0) > 1) {
        n = varargin_2.size(0) - 1;
        nd2 = varargin_2.size(0) >> 1;
        for (int b_j1{0}; b_j1 < nd2; b_j1++) {
          xtmp = y[b_j1];
          nx = n - b_j1;
          y[b_j1] = y[nx];
          y[nx] = xtmp;
        }
      }
    }
    interp1Linear(y, varargin_3, Vq, x);
  }
}

//
// Arguments    : const array<double, 1U> &varargin_1
//                const array<creal_T, 1U> &varargin_2
//                const array<double, 1U> &varargin_3
//                array<creal_T, 1U> &Vq
// Return Type  : void
//
void interp1(const array<double, 1U> &varargin_1,
             const array<creal_T, 1U> &varargin_2,
             const array<double, 1U> &varargin_3, array<creal_T, 1U> &Vq)
{
  array<creal_T, 1U> y;
  array<double, 1U> x;
  int n;
  int nx;
  n = varargin_2.size(0);
  y.set_size(varargin_2.size(0));
  for (int b_j1{0}; b_j1 < n; b_j1++) {
    y[b_j1] = varargin_2[b_j1];
  }
  n = varargin_1.size(0);
  x.set_size(varargin_1.size(0));
  for (int b_j1{0}; b_j1 < n; b_j1++) {
    x[b_j1] = varargin_1[b_j1];
  }
  nx = varargin_1.size(0) - 1;
  n = varargin_3.size(0);
  Vq.set_size(varargin_3.size(0));
  for (int b_j1{0}; b_j1 < n; b_j1++) {
    Vq[b_j1].re = 0.0;
    Vq[b_j1].im = 0.0;
  }
  if (varargin_3.size(0) != 0) {
    if (varargin_1[1] < varargin_1[0]) {
      double xtmp;
      int nd2;
      n = varargin_1.size(0) >> 1;
      for (int b_j1{0}; b_j1 < n; b_j1++) {
        xtmp = x[b_j1];
        nd2 = nx - b_j1;
        x[b_j1] = x[nd2];
        x[nd2] = xtmp;
      }
      if (varargin_2.size(0) > 1) {
        n = varargin_2.size(0) - 1;
        nd2 = varargin_2.size(0) >> 1;
        for (int b_j1{0}; b_j1 < nd2; b_j1++) {
          double tmp_im;
          xtmp = y[b_j1].re;
          tmp_im = y[b_j1].im;
          nx = n - b_j1;
          y[b_j1] = y[nx];
          y[nx].re = xtmp;
          y[nx].im = tmp_im;
        }
      }
    }
    interp1Linear(y, varargin_3, Vq, x);
  }
}

} // namespace coder

//
// File trailer for interp1.cpp
//
// [EOF]
//
