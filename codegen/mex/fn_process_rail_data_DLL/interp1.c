/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * interp1.c
 *
 * Code generation for function 'interp1'
 *
 */

/* Include files */
#include "interp1.h"
#include "anynan.h"
#include "bsearch.h"
#include "chckxy.h"
#include "eml_int_forloop_overflow_check.h"
#include "flip.h"
#include "fn_process_rail_data_DLL_data.h"
#include "fn_process_rail_data_DLL_emxutil.h"
#include "fn_process_rail_data_DLL_types.h"
#include "pchip.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include "omp.h"
#include <emmintrin.h>

/* Variable Definitions */
static emlrtRSInfo ud_emlrtRSI = {
    49,        /* lineNo */
    "interp1", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m" /* pathName
                                                                            */
};

static emlrtRSInfo vd_emlrtRSI = {
    165,            /* lineNo */
    "interp1_work", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m" /* pathName
                                                                            */
};

static emlrtRSInfo wd_emlrtRSI = {
    190,            /* lineNo */
    "interp1_work", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m" /* pathName
                                                                            */
};

static emlrtRSInfo xd_emlrtRSI = {
    198,            /* lineNo */
    "interp1_work", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m" /* pathName
                                                                            */
};

static emlrtRSInfo yd_emlrtRSI = {
    202,            /* lineNo */
    "interp1_work", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m" /* pathName
                                                                            */
};

static emlrtRSInfo ae_emlrtRSI = {
    265,            /* lineNo */
    "interp1_work", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m" /* pathName
                                                                            */
};

static emlrtRSInfo ee_emlrtRSI = {
    37,     /* lineNo */
    "flip", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\elmat\\flip.m" /* pathName
                                                                       */
};

static emlrtRSInfo fe_emlrtRSI = {
    453,                          /* lineNo */
    "interp1SplineMakimaOrPCHIP", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m" /* pathName
                                                                            */
};

static emlrtRSInfo ge_emlrtRSI = {
    460,                          /* lineNo */
    "interp1SplineMakimaOrPCHIP", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m" /* pathName
                                                                            */
};

static emlrtRSInfo he_emlrtRSI = {
    25,                                /* lineNo */
    "interp1SplineMakimaOrPCHIPcoefs", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\+"
    "interpolate\\interp1SplineMakimaOrPCHIPcoe"
    "fs.m" /* pathName */
};

static emlrtRSInfo xe_emlrtRSI = {
    100,     /* lineNo */
    "ppval", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\polyfun\\ppval.m" /* pathName
                                                                          */
};

static emlrtRSInfo ye_emlrtRSI = {
    107,     /* lineNo */
    "ppval", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\polyfun\\ppval.m" /* pathName
                                                                          */
};

static emlrtRSInfo af_emlrtRSI = {
    112,     /* lineNo */
    "ppval", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\polyfun\\ppval.m" /* pathName
                                                                          */
};

static emlrtRSInfo bf_emlrtRSI = {
    14,                                /* lineNo */
    "interp1SplineMakimaOrPCHIPcoefs", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\+"
    "interpolate\\interp1SplineMakimaOrPCHIPcoe"
    "fs.m" /* pathName */
};

static emlrtRSInfo ug_emlrtRSI = {
    54,        /* lineNo */
    "interp1", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m" /* pathName
                                                                            */
};

static emlrtRSInfo vg_emlrtRSI = {
    305,            /* lineNo */
    "interp1_work", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m" /* pathName
                                                                            */
};

static emlrtRSInfo wg_emlrtRSI = {
    339,             /* lineNo */
    "interp1Linear", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m" /* pathName
                                                                            */
};

static emlrtRTEInfo q_emlrtRTEI = {
    204,            /* lineNo */
    13,             /* colNo */
    "interp1_work", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m" /* pName
                                                                            */
};

static emlrtRTEInfo r_emlrtRTEI = {
    165,            /* lineNo */
    5,              /* colNo */
    "interp1_work", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m" /* pName
                                                                            */
};

static emlrtRTEInfo s_emlrtRTEI = {
    155,            /* lineNo */
    15,             /* colNo */
    "interp1_work", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m" /* pName
                                                                            */
};

static emlrtRTEInfo t_emlrtRTEI = {
    139,            /* lineNo */
    23,             /* colNo */
    "interp1_work", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m" /* pName
                                                                            */
};

static emlrtRTEInfo u_emlrtRTEI = {
    130,            /* lineNo */
    19,             /* colNo */
    "interp1_work", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m" /* pName
                                                                            */
};

static emlrtRTEInfo re_emlrtRTEI = {
    49,        /* lineNo */
    49,        /* colNo */
    "interp1", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m" /* pName
                                                                            */
};

static emlrtRTEInfo se_emlrtRTEI = {
    50,        /* lineNo */
    25,        /* colNo */
    "interp1", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m" /* pName
                                                                            */
};

static emlrtRTEInfo te_emlrtRTEI = {
    26,        /* lineNo */
    9,         /* colNo */
    "permute", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\elmat\\permute.m" /* pName
                                                                          */
};

static emlrtRTEInfo ue_emlrtRTEI = {
    77,      /* lineNo */
    24,      /* colNo */
    "ppval", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\polyfun\\ppval.m" /* pName
                                                                          */
};

static emlrtRTEInfo ve_emlrtRTEI = {
    49,        /* lineNo */
    9,         /* colNo */
    "interp1", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m" /* pName
                                                                            */
};

static emlrtRTEInfo we_emlrtRTEI = {
    453,       /* lineNo */
    1,         /* colNo */
    "interp1", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m" /* pName
                                                                            */
};

static emlrtRTEInfo xe_emlrtRTEI = {
    460,       /* lineNo */
    5,         /* colNo */
    "interp1", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m" /* pName
                                                                            */
};

static emlrtRTEInfo hf_emlrtRTEI = {
    32,         /* lineNo */
    31,         /* colNo */
    "pwchcore", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\polyfun\\private\\pwchco"
    "re.m" /* pName */
};

static emlrtRTEInfo sg_emlrtRTEI = {
    55,        /* lineNo */
    9,         /* colNo */
    "interp1", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m" /* pName
                                                                            */
};

static emlrtRTEInfo tg_emlrtRTEI = {
    55,        /* lineNo */
    33,        /* colNo */
    "interp1", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m" /* pName
                                                                            */
};

static emlrtRTEInfo ug_emlrtRTEI = {
    54,        /* lineNo */
    5,         /* colNo */
    "interp1", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m" /* pName
                                                                            */
};

/* Function Declarations */
static void b_interp1Linear(const emlrtStack *sp, const emxArray_creal_T *y,
                            const emxArray_real_T *xi, emxArray_creal_T *yi,
                            const emxArray_real_T *varargin_1);

static void interp1Linear(const emlrtStack *sp, const emxArray_real_T *y,
                          const emxArray_real_T *xi, emxArray_real_T *yi,
                          const emxArray_real_T *varargin_1);

/* Function Definitions */
static void b_interp1Linear(const emlrtStack *sp, const emxArray_creal_T *y,
                            const emxArray_real_T *xi, emxArray_creal_T *yi,
                            const emxArray_real_T *varargin_1)
{
  jmp_buf *volatile emlrtJBStack;
  emlrtStack b_st;
  emlrtStack st;
  const creal_T *y_data;
  creal_T *yi_data;
  const real_T *varargin_1_data;
  const real_T *xi_data;
  real_T b_y_tmp;
  real_T maxx;
  real_T minx;
  real_T r;
  real_T y1_im;
  real_T y1_re;
  real_T y_tmp;
  int32_T b_interp1Linear_numThreads;
  int32_T high_i;
  int32_T k;
  int32_T low_i;
  int32_T low_ip1;
  int32_T mid_i;
  int32_T ub_loop;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  varargin_1_data = varargin_1->data;
  yi_data = yi->data;
  xi_data = xi->data;
  y_data = y->data;
  minx = varargin_1_data[0];
  maxx = varargin_1_data[varargin_1->size[0] - 1];
  st.site = &wg_emlrtRSI;
  if (xi->size[0] > 2147483646) {
    b_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  ub_loop = xi->size[0];
  emlrtEnterParallelRegion((emlrtCTX)sp, omp_in_parallel());
  emlrtPushJmpBuf((emlrtCTX)sp, &emlrtJBStack);
  b_interp1Linear_numThreads = emlrtAllocRegionTLSs(
      sp->tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(b_interp1Linear_numThreads) private(      \
        y1_re, y1_im, high_i, low_i, low_ip1, mid_i, r, y_tmp, b_y_tmp)

  for (k = 0; k < ub_loop; k++) {
    y1_re = yi_data[k].re;
    y1_im = yi_data[k].im;
    if (muDoubleScalarIsNaN(xi_data[k])) {
      y1_re = rtNaN;
      y1_im = rtNaN;
    } else if ((!(xi_data[k] > maxx)) && (!(xi_data[k] < minx))) {
      high_i = varargin_1->size[0];
      low_i = 1;
      low_ip1 = 2;
      while (high_i > low_ip1) {
        mid_i = (low_i >> 1) + (high_i >> 1);
        if ((((uint32_T)low_i & 1U) == 1U) && (((uint32_T)high_i & 1U) == 1U)) {
          mid_i++;
        }
        if (xi_data[k] >= varargin_1_data[mid_i - 1]) {
          low_i = mid_i;
          low_ip1 = mid_i + 1;
        } else {
          high_i = mid_i;
        }
      }
      y1_re = varargin_1_data[low_i - 1];
      r = (xi_data[k] - y1_re) / (varargin_1_data[low_i] - y1_re);
      if (r == 0.0) {
        y1_re = y_data[low_i - 1].re;
        y1_im = y_data[low_i - 1].im;
      } else if (r == 1.0) {
        y1_re = y_data[low_i].re;
        y1_im = y_data[low_i].im;
      } else {
        y1_re = y_data[low_i - 1].re;
        y1_im = y_data[low_i - 1].im;
        y_tmp = y_data[low_i].re;
        b_y_tmp = y_data[low_i].im;
        if ((!(y1_re == y_tmp)) || (!(y1_im == b_y_tmp))) {
          y1_re = (1.0 - r) * y1_re + r * y_tmp;
          y1_im = (1.0 - r) * y1_im + r * b_y_tmp;
        }
      }
    }
    yi_data[k].re = y1_re;
    yi_data[k].im = y1_im;
  }
  emlrtPopJmpBuf((emlrtCTX)sp, &emlrtJBStack);
  emlrtExitParallelRegion((emlrtCTX)sp, omp_in_parallel());
}

static void interp1Linear(const emlrtStack *sp, const emxArray_real_T *y,
                          const emxArray_real_T *xi, emxArray_real_T *yi,
                          const emxArray_real_T *varargin_1)
{
  jmp_buf *volatile emlrtJBStack;
  emlrtStack b_st;
  emlrtStack st;
  const real_T *varargin_1_data;
  const real_T *xi_data;
  const real_T *y_data;
  real_T d;
  real_T maxx;
  real_T minx;
  real_T r;
  real_T *yi_data;
  int32_T interp1Linear_numThreads;
  int32_T k;
  int32_T n;
  int32_T ub_loop;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  varargin_1_data = varargin_1->data;
  yi_data = yi->data;
  xi_data = xi->data;
  y_data = y->data;
  minx = varargin_1_data[0];
  maxx = varargin_1_data[varargin_1->size[1] - 1];
  st.site = &wg_emlrtRSI;
  if (xi->size[0] > 2147483646) {
    b_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  ub_loop = xi->size[0];
  emlrtEnterParallelRegion((emlrtCTX)sp, omp_in_parallel());
  emlrtPushJmpBuf((emlrtCTX)sp, &emlrtJBStack);
  interp1Linear_numThreads = emlrtAllocRegionTLSs(
      sp->tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(interp1Linear_numThreads) private(n, r, d)

  for (k = 0; k < ub_loop; k++) {
    if (muDoubleScalarIsNaN(xi_data[k])) {
      yi_data[k] = rtNaN;
    } else if ((!(xi_data[k] > maxx)) && (!(xi_data[k] < minx))) {
      n = b_bsearch(varargin_1, xi_data[k]) - 1;
      r = (xi_data[k] - varargin_1_data[n]) /
          (varargin_1_data[n + 1] - varargin_1_data[n]);
      if (r == 0.0) {
        yi_data[k] = y_data[n];
      } else if (r == 1.0) {
        yi_data[k] = y_data[n + 1];
      } else {
        d = y_data[n + 1];
        if (y_data[n] == d) {
          yi_data[k] = y_data[n];
        } else {
          yi_data[k] = (1.0 - r) * y_data[n] + r * d;
        }
      }
    }
  }
  emlrtPopJmpBuf((emlrtCTX)sp, &emlrtJBStack);
  emlrtExitParallelRegion((emlrtCTX)sp, omp_in_parallel());
}

real_T b_interp1(const emlrtStack *sp, const emxArray_real_T *varargin_1,
                 const emxArray_real_T *varargin_2, real_T varargin_3)
{
  __m128d r;
  __m128d r1;
  jmp_buf *volatile emlrtJBStack;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  emxArray_real_T b_x;
  emxArray_real_T *del;
  emxArray_real_T *h;
  emxArray_real_T *pp_coefs;
  emxArray_real_T *slopes;
  emxArray_real_T *x;
  emxArray_real_T *y;
  const real_T *varargin_1_data;
  const real_T *varargin_2_data;
  real_T Vq;
  real_T d;
  real_T d1;
  real_T dzzdx;
  real_T s;
  real_T s_tmp;
  real_T w1;
  real_T w2;
  real_T *del_data;
  real_T *h_data;
  real_T *pp_coefs_data;
  real_T *slopes_data;
  real_T *x_data;
  real_T *y_data;
  int32_T iv[2];
  int32_T b_interp1_numThreads;
  int32_T b_j1;
  int32_T k;
  int32_T loop_ub;
  int32_T n;
  int32_T nd2;
  int32_T nx;
  int32_T nxm1;
  int32_T y_tmp;
  boolean_T exitg1;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  varargin_2_data = varargin_2->data;
  varargin_1_data = varargin_1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  st.site = &ud_emlrtRSI;
  emxInit_real_T(&st, &y, 1, &re_emlrtRTEI);
  nd2 = varargin_2->size[0];
  n = y->size[0];
  y->size[0] = varargin_2->size[0];
  emxEnsureCapacity_real_T(&st, y, n, &re_emlrtRTEI);
  y_data = y->data;
  for (b_j1 = 0; b_j1 < nd2; b_j1++) {
    y_data[b_j1] = varargin_2_data[b_j1];
  }
  emxInit_real_T(&st, &x, 1, &se_emlrtRTEI);
  loop_ub = varargin_1->size[0];
  n = x->size[0];
  x->size[0] = varargin_1->size[0];
  emxEnsureCapacity_real_T(&st, x, n, &se_emlrtRTEI);
  x_data = x->data;
  for (b_j1 = 0; b_j1 < loop_ub; b_j1++) {
    x_data[b_j1] = varargin_1_data[b_j1];
  }
  nx = varargin_1->size[0] - 1;
  if (varargin_1->size[0] != varargin_2->size[0]) {
    emlrtErrorWithMessageIdR2018a(&st, &t_emlrtRTEI,
                                  "Coder:MATLAB:interp1_YInvalidNumRows",
                                  "Coder:MATLAB:interp1_YInvalidNumRows", 0);
  }
  if (varargin_1->size[0] <= 1) {
    emlrtErrorWithMessageIdR2018a(&st, &s_emlrtRTEI,
                                  "MATLAB:interp1:NotEnoughPts",
                                  "MATLAB:interp1:NotEnoughPts", 0);
  }
  b_st.site = &vd_emlrtRSI;
  if (anynan(&b_st, varargin_1)) {
    emlrtErrorWithMessageIdR2018a(&st, &r_emlrtRTEI, "MATLAB:interp1:NaNinX",
                                  "MATLAB:interp1:NaNinX", 0);
  }
  if (varargin_1_data[1] < varargin_1_data[0]) {
    n = varargin_1->size[0] >> 1;
    b_st.site = &wd_emlrtRSI;
    for (b_j1 = 0; b_j1 < n; b_j1++) {
      Vq = x_data[b_j1];
      nd2 = nx - b_j1;
      x_data[b_j1] = x_data[nd2];
      x_data[nd2] = Vq;
    }
    b_st.site = &xd_emlrtRSI;
    if (varargin_2->size[0] > 1) {
      n = varargin_2->size[0] - 1;
      nd2 = varargin_2->size[0] >> 1;
      c_st.site = &ee_emlrtRSI;
      for (b_j1 = 0; b_j1 < nd2; b_j1++) {
        Vq = y_data[b_j1];
        y_tmp = n - b_j1;
        y_data[b_j1] = y_data[y_tmp];
        y_data[y_tmp] = Vq;
      }
    }
  }
  b_st.site = &yd_emlrtRSI;
  if (varargin_1->size[0] > 2147483646) {
    c_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  for (b_j1 = 2; b_j1 <= nx + 1; b_j1++) {
    if (x_data[b_j1 - 1] <= x_data[b_j1 - 2]) {
      emlrtErrorWithMessageIdR2018a(&st, &q_emlrtRTEI,
                                    "Coder:toolbox:interp1_nonMonotonicX",
                                    "Coder:toolbox:interp1_nonMonotonicX", 0);
    }
  }
  b_st.site = &ae_emlrtRSI;
  c_st.site = &fe_emlrtRSI;
  d_st.site = &bf_emlrtRSI;
  e_st.site = &ie_emlrtRSI;
  if (x->size[0] < 2) {
    emlrtErrorWithMessageIdR2018a(&e_st, &w_emlrtRTEI,
                                  "MATLAB:chckxy:NotEnoughPts",
                                  "MATLAB:chckxy:NotEnoughPts", 0);
  }
  if (!isFiniteAndStrictlyIncreasing(x)) {
    emlrtErrorWithMessageIdR2018a(
        &e_st, &x_emlrtRTEI, "Coder:toolbox:MustBeFiniteAndStrictlyIncreasing",
        "Coder:toolbox:MustBeFiniteAndStrictlyIncreasing", 0);
  }
  p = false;
  n = 0;
  exitg1 = false;
  while ((!exitg1) && (n <= y->size[0] - 1)) {
    if (muDoubleScalarIsNaN(y_data[n])) {
      p = true;
      exitg1 = true;
    } else {
      n++;
    }
  }
  if (p) {
    emlrtErrorWithMessageIdR2018a(&e_st, &y_emlrtRTEI,
                                  "Coder:toolbox:UnsupportedNaN",
                                  "Coder:toolbox:UnsupportedNaN", 0);
  }
  if ((y->size[0] != x->size[0]) && (y->size[0] != x->size[0] + 2)) {
    emlrtErrorWithMessageIdR2018a(&e_st, &ab_emlrtRTEI,
                                  "MATLAB:chckxy:NumSitesMismatchValues",
                                  "MATLAB:chckxy:NumSitesMismatchValues", 4, 12,
                                  x->size[0], 12, y->size[0]);
  }
  if (x->size[0] != y->size[0]) {
    emlrtErrorWithMessageIdR2018a(&d_st, &v_emlrtRTEI,
                                  "MATLAB:chckxy:NumSitesMismatchValues",
                                  "MATLAB:chckxy:NumSitesMismatchValues", 4, 12,
                                  x->size[0], 12, y->size[0]);
  }
  nxm1 = x->size[0] - 2;
  emxInit_real_T(&d_st, &h, 2, &ef_emlrtRTEI);
  n = h->size[0] * h->size[1];
  h->size[0] = 1;
  h->size[1] = varargin_1->size[0] - 1;
  emxEnsureCapacity_real_T(&d_st, h, n, &ye_emlrtRTEI);
  h_data = h->data;
  e_st.site = &je_emlrtRSI;
  nd2 = ((x->size[0] - 1) / 2) << 1;
  n = nd2 - 2;
  for (b_j1 = 0; b_j1 <= n; b_j1 += 2) {
    r = _mm_loadu_pd(&x_data[b_j1 + 1]);
    r1 = _mm_loadu_pd(&x_data[b_j1]);
    _mm_storeu_pd(&h_data[b_j1], _mm_sub_pd(r, r1));
  }
  for (b_j1 = nd2; b_j1 <= nxm1; b_j1++) {
    h_data[b_j1] = x_data[b_j1 + 1] - x_data[b_j1];
  }
  emxInit_real_T(&d_st, &del, 2, &ff_emlrtRTEI);
  n = del->size[0] * del->size[1];
  del->size[0] = 1;
  y_tmp = y->size[0] - 1;
  del->size[1] = y->size[0] - 1;
  emxEnsureCapacity_real_T(&d_st, del, n, &af_emlrtRTEI);
  del_data = del->data;
  e_st.site = &ke_emlrtRSI;
  n = nd2 - 2;
  for (b_j1 = 0; b_j1 <= n; b_j1 += 2) {
    __m128d r2;
    r = _mm_loadu_pd(&y_data[b_j1 + 1]);
    r1 = _mm_loadu_pd(&y_data[b_j1]);
    r2 = _mm_loadu_pd(&h_data[b_j1]);
    _mm_storeu_pd(&del_data[b_j1], _mm_div_pd(_mm_sub_pd(r, r1), r2));
  }
  for (b_j1 = nd2; b_j1 <= nxm1; b_j1++) {
    del_data[b_j1] = (y_data[b_j1 + 1] - y_data[b_j1]) / h_data[b_j1];
  }
  emxInit_real_T(&d_st, &slopes, 2, &gf_emlrtRTEI);
  n = slopes->size[0] * slopes->size[1];
  slopes->size[0] = 1;
  slopes->size[1] = varargin_2->size[0];
  emxEnsureCapacity_real_T(&d_st, slopes, n, &bf_emlrtRTEI);
  slopes_data = slopes->data;
  if (x->size[0] == 2) {
    e_st.site = &me_emlrtRSI;
    slopes_data[0] = del_data[0];
    slopes_data[1] = del_data[0];
  } else {
    n = varargin_1->size[0];
    e_st.site = &oe_emlrtRSI;
    if (x->size[0] - 2 < 2000) {
      for (k = 0; k <= loop_ub - 3; k++) {
        w2 = h_data[k + 1];
        d = h_data[k];
        w1 = 2.0 * w2 + d;
        w2 += 2.0 * d;
        slopes_data[k + 1] = 0.0;
        d = del_data[k];
        d1 = del_data[k + 1];
        if (muDoubleScalarSign(d * d1) > 0.0) {
          slopes_data[k + 1] = (w1 + w2) / (w1 / d + w2 / d1);
        }
      }
    } else {
      emlrtEnterParallelRegion(&d_st, omp_in_parallel());
      emlrtPushJmpBuf(&d_st, &emlrtJBStack);
      b_interp1_numThreads =
          emlrtAllocRegionTLSs(d_st.tls, omp_in_parallel(),
                               omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(b_interp1_numThreads) private(d1, d, w2,  \
                                                                       w1)

      for (k = 0; k <= n - 3; k++) {
        w2 = h_data[k + 1];
        d = h_data[k];
        w1 = 2.0 * w2 + d;
        w2 += 2.0 * d;
        slopes_data[k + 1] = 0.0;
        d = del_data[k];
        d1 = del_data[k + 1];
        if (muDoubleScalarSign(d * d1) > 0.0) {
          slopes_data[k + 1] = (w1 + w2) / (w1 / d + w2 / d1);
        }
      }
      emlrtPopJmpBuf(&d_st, &emlrtJBStack);
      emlrtExitParallelRegion(&d_st, omp_in_parallel());
    }
    s = ((2.0 * h_data[0] + h_data[1]) * del_data[0] -
         h_data[0] * del_data[1]) /
        (h_data[0] + h_data[1]);
    Vq = muDoubleScalarSign(del_data[0]);
    if (muDoubleScalarSign(s) != Vq) {
      s = 0.0;
    } else if (Vq != muDoubleScalarSign(del_data[1])) {
      Vq = 3.0 * del_data[0];
      if (muDoubleScalarAbs(s) > muDoubleScalarAbs(Vq)) {
        s = Vq;
      }
    }
    slopes_data[0] = s;
    Vq = h_data[nxm1];
    s = h_data[x->size[0] - 3];
    s_tmp = del_data[nxm1];
    dzzdx = del_data[x->size[0] - 3];
    s = ((2.0 * Vq + s) * s_tmp - Vq * dzzdx) / (Vq + s);
    Vq = muDoubleScalarSign(s_tmp);
    if (muDoubleScalarSign(s) != Vq) {
      s = 0.0;
    } else if (Vq != muDoubleScalarSign(dzzdx)) {
      Vq = 3.0 * s_tmp;
      if (muDoubleScalarAbs(s) > muDoubleScalarAbs(Vq)) {
        s = Vq;
      }
    }
    slopes_data[nx] = s;
  }
  e_st.site = &re_emlrtRSI;
  f_st.site = &se_emlrtRSI;
  if (x->size[0] > muIntScalarMax_sint32(loop_ub, loop_ub)) {
    emlrtErrorWithMessageIdR2018a(&f_st, &c_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  emxInit_real_T(&e_st, &pp_coefs, 2, &cf_emlrtRTEI);
  n = pp_coefs->size[0] * pp_coefs->size[1];
  pp_coefs->size[0] = y_tmp;
  pp_coefs->size[1] = 4;
  emxEnsureCapacity_real_T(&e_st, pp_coefs, n, &hf_emlrtRTEI);
  pp_coefs_data = pp_coefs->data;
  for (b_j1 = 0; b_j1 <= loop_ub - 2; b_j1++) {
    Vq = del_data[b_j1];
    s = slopes_data[b_j1];
    s_tmp = h_data[b_j1];
    dzzdx = (Vq - s) / s_tmp;
    Vq = (slopes_data[b_j1 + 1] - Vq) / s_tmp;
    pp_coefs_data[b_j1] = (Vq - dzzdx) / s_tmp;
    pp_coefs_data[y_tmp + b_j1] = 2.0 * dzzdx - Vq;
    pp_coefs_data[(y_tmp << 1) + b_j1] = s;
    pp_coefs_data[3 * y_tmp + b_j1] = y_data[b_j1];
  }
  emxFree_real_T(&e_st, &slopes);
  emxFree_real_T(&e_st, &del);
  emxFree_real_T(&e_st, &h);
  emxFree_real_T(&e_st, &y);
  if (muDoubleScalarIsNaN(varargin_3)) {
    Vq = rtNaN;
  } else {
    b_x = *x;
    iv[0] = 1;
    iv[1] = loop_ub;
    b_x.size = &iv[0];
    b_x.numDimensions = 2;
    n = b_bsearch(&b_x, varargin_3) - 1;
    Vq = varargin_3 - x_data[n];
    Vq = Vq * (Vq * (Vq * pp_coefs_data[n] +
                     pp_coefs_data[(n + x->size[0]) - 1]) +
               pp_coefs_data[n + ((x->size[0] - 1) << 1)]) +
         pp_coefs_data[n + 3 * (x->size[0] - 1)];
  }
  emxFree_real_T(&b_st, &pp_coefs);
  emxFree_real_T(&b_st, &x);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
  return Vq;
}

void c_interp1(const emlrtStack *sp, const emxArray_real_T *varargin_1,
               const emxArray_creal_T *varargin_2, real_T varargin_3,
               emxArray_creal_T *Vq)
{
  jmp_buf *volatile emlrtJBStack;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  emxArray_creal_T *y;
  emxArray_real_T *x;
  const creal_T *varargin_2_data;
  creal_T b_y1;
  creal_T y2;
  creal_T *Vq_data;
  creal_T *y_data;
  const real_T *varargin_1_data;
  real_T xtmp;
  real_T *x_data;
  int32_T b_j1;
  int32_T b_loop_ub;
  int32_T c_interp1_numThreads;
  int32_T i;
  int32_T j;
  int32_T loop_ub;
  int32_T n;
  int32_T nx;
  int32_T nyrows;
  int32_T y1_tmp;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  varargin_2_data = varargin_2->data;
  varargin_1_data = varargin_1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  st.site = &ud_emlrtRSI;
  emxInit_creal_T(&st, &y, 2, &re_emlrtRTEI);
  i = varargin_2->size[0];
  loop_ub = y->size[0] * y->size[1];
  y->size[0] = varargin_2->size[0];
  b_loop_ub = varargin_2->size[1];
  y->size[1] = varargin_2->size[1];
  emxEnsureCapacity_creal_T(&st, y, loop_ub, &re_emlrtRTEI);
  y_data = y->data;
  loop_ub = varargin_2->size[0] * varargin_2->size[1];
  for (b_j1 = 0; b_j1 < loop_ub; b_j1++) {
    y_data[b_j1] = varargin_2_data[b_j1];
  }
  emxInit_real_T(&st, &x, 2, &se_emlrtRTEI);
  loop_ub = x->size[0] * x->size[1];
  x->size[0] = 1;
  n = varargin_1->size[1];
  x->size[1] = varargin_1->size[1];
  emxEnsureCapacity_real_T(&st, x, loop_ub, &se_emlrtRTEI);
  x_data = x->data;
  for (b_j1 = 0; b_j1 < n; b_j1++) {
    x_data[b_j1] = varargin_1_data[b_j1];
  }
  if (((varargin_2->size[0] != 1) || (varargin_2->size[1] != 1)) &&
      ((varargin_2->size[0] == 1) || (varargin_2->size[1] == 1)) &&
      (varargin_2->size[0] == 1)) {
    emlrtErrorWithMessageIdR2018a(
        &st, &u_emlrtRTEI, "Coder:toolbox:interp1_vsizeMatrixBecameRowVec",
        "Coder:toolbox:interp1_vsizeMatrixBecameRowVec", 0);
  }
  nyrows = varargin_2->size[0];
  nx = varargin_1->size[1] - 1;
  if (varargin_2->size[0] != varargin_1->size[1]) {
    emlrtErrorWithMessageIdR2018a(&st, &t_emlrtRTEI,
                                  "Coder:MATLAB:interp1_YInvalidNumRows",
                                  "Coder:MATLAB:interp1_YInvalidNumRows", 0);
  }
  if (varargin_1->size[1] <= 1) {
    emlrtErrorWithMessageIdR2018a(&st, &s_emlrtRTEI,
                                  "MATLAB:interp1:NotEnoughPts",
                                  "MATLAB:interp1:NotEnoughPts", 0);
  }
  loop_ub = Vq->size[0] * Vq->size[1];
  Vq->size[0] = 1;
  Vq->size[1] = varargin_2->size[1];
  emxEnsureCapacity_creal_T(&st, Vq, loop_ub, &ve_emlrtRTEI);
  Vq_data = Vq->data;
  for (b_j1 = 0; b_j1 < b_loop_ub; b_j1++) {
    Vq_data[b_j1].re = rtNaN;
    Vq_data[b_j1].im = rtNaN;
  }
  b_st.site = &vd_emlrtRSI;
  if (b_anynan(&b_st, varargin_1)) {
    emlrtErrorWithMessageIdR2018a(&st, &r_emlrtRTEI, "MATLAB:interp1:NaNinX",
                                  "MATLAB:interp1:NaNinX", 0);
  }
  if (varargin_1_data[1] < varargin_1_data[0]) {
    loop_ub = varargin_1->size[1] >> 1;
    b_st.site = &wd_emlrtRSI;
    for (b_j1 = 0; b_j1 < loop_ub; b_j1++) {
      xtmp = x_data[b_j1];
      n = nx - b_j1;
      x_data[b_j1] = x_data[n];
      x_data[n] = xtmp;
    }
    b_st.site = &xd_emlrtRSI;
    flip(y);
    y_data = y->data;
  }
  b_st.site = &yd_emlrtRSI;
  if (varargin_1->size[1] > 2147483646) {
    c_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  for (b_j1 = 2; b_j1 <= nx + 1; b_j1++) {
    if (x_data[b_j1 - 1] <= x_data[b_j1 - 2]) {
      emlrtErrorWithMessageIdR2018a(&st, &q_emlrtRTEI,
                                    "Coder:toolbox:interp1_nonMonotonicX",
                                    "Coder:toolbox:interp1_nonMonotonicX", 0);
    }
  }
  if (muDoubleScalarIsNaN(varargin_3)) {
    for (b_j1 = 0; b_j1 < b_loop_ub; b_j1++) {
      Vq_data[b_j1].re = rtNaN;
      Vq_data[b_j1].im = rtNaN;
    }
  } else if ((!(varargin_3 > x_data[varargin_1->size[1] - 1])) &&
             (!(varargin_3 < x_data[0]))) {
    n = b_bsearch(x, varargin_3);
    xtmp = x_data[n - 1];
    xtmp = (varargin_3 - xtmp) / (x_data[n] - xtmp);
    if (xtmp == 0.0) {
      for (b_j1 = 0; b_j1 < b_loop_ub; b_j1++) {
        Vq_data[b_j1] = y_data[(n + b_j1 * i) - 1];
      }
    } else if (xtmp == 1.0) {
      for (b_j1 = 0; b_j1 < b_loop_ub; b_j1++) {
        Vq_data[b_j1] = y_data[n + b_j1 * i];
      }
    } else {
      loop_ub = varargin_2->size[1];
      if (varargin_2->size[1] < 2000) {
        for (j = 0; j < b_loop_ub; j++) {
          loop_ub = n + j * i;
          b_y1 = y_data[loop_ub - 1];
          y2 = y_data[loop_ub];
          if ((b_y1.re == y2.re) && (b_y1.im == y2.im)) {
            Vq_data[j] = b_y1;
          } else {
            Vq_data[j].re = (1.0 - xtmp) * b_y1.re + xtmp * y2.re;
            Vq_data[j].im = (1.0 - xtmp) * b_y1.im + xtmp * y2.im;
          }
        }
      } else {
        emlrtEnterParallelRegion(&st, omp_in_parallel());
        emlrtPushJmpBuf(&st, &emlrtJBStack);
        c_interp1_numThreads =
            emlrtAllocRegionTLSs(st.tls, omp_in_parallel(),
                                 omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(c_interp1_numThreads) private(y2, b_y1,   \
                                                                       y1_tmp)

        for (j = 0; j < loop_ub; j++) {
          y1_tmp = n + j * nyrows;
          b_y1 = y_data[y1_tmp - 1];
          y2 = y_data[y1_tmp];
          if ((b_y1.re == y2.re) && (b_y1.im == y2.im)) {
            Vq_data[j] = b_y1;
          } else {
            Vq_data[j].re = (1.0 - xtmp) * b_y1.re + xtmp * y2.re;
            Vq_data[j].im = (1.0 - xtmp) * b_y1.im + xtmp * y2.im;
          }
        }
        emlrtPopJmpBuf(&st, &emlrtJBStack);
        emlrtExitParallelRegion(&st, omp_in_parallel());
      }
    }
  }
  emxFree_real_T(&st, &x);
  emxFree_creal_T(&st, &y);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

void d_interp1(const emlrtStack *sp, const emxArray_real_T *varargin_1,
               const emxArray_real_T *varargin_2,
               const emxArray_real_T *varargin_3, emxArray_real_T *Vq)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  emxArray_real_T *x;
  emxArray_real_T *y;
  const real_T *varargin_1_data;
  const real_T *varargin_2_data;
  real_T *Vq_data;
  real_T *x_data;
  real_T *y_data;
  int32_T b_j1;
  int32_T n;
  int32_T nd2;
  int32_T nx;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  varargin_2_data = varargin_2->data;
  varargin_1_data = varargin_1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  st.site = &ug_emlrtRSI;
  emxInit_real_T(&st, &y, 1, &sg_emlrtRTEI);
  nd2 = varargin_2->size[0];
  n = y->size[0];
  y->size[0] = varargin_2->size[0];
  emxEnsureCapacity_real_T(&st, y, n, &sg_emlrtRTEI);
  y_data = y->data;
  for (b_j1 = 0; b_j1 < nd2; b_j1++) {
    y_data[b_j1] = varargin_2_data[b_j1];
  }
  emxInit_real_T(&st, &x, 2, &tg_emlrtRTEI);
  n = x->size[0] * x->size[1];
  x->size[0] = 1;
  nd2 = varargin_1->size[1];
  x->size[1] = varargin_1->size[1];
  emxEnsureCapacity_real_T(&st, x, n, &tg_emlrtRTEI);
  x_data = x->data;
  for (b_j1 = 0; b_j1 < nd2; b_j1++) {
    x_data[b_j1] = varargin_1_data[b_j1];
  }
  nx = varargin_1->size[1] - 1;
  if (varargin_2->size[0] != varargin_1->size[1]) {
    emlrtErrorWithMessageIdR2018a(&st, &t_emlrtRTEI,
                                  "Coder:MATLAB:interp1_YInvalidNumRows",
                                  "Coder:MATLAB:interp1_YInvalidNumRows", 0);
  }
  if (varargin_1->size[1] <= 1) {
    emlrtErrorWithMessageIdR2018a(&st, &s_emlrtRTEI,
                                  "MATLAB:interp1:NotEnoughPts",
                                  "MATLAB:interp1:NotEnoughPts", 0);
  }
  nd2 = varargin_3->size[0];
  n = Vq->size[0];
  Vq->size[0] = varargin_3->size[0];
  emxEnsureCapacity_real_T(&st, Vq, n, &ug_emlrtRTEI);
  Vq_data = Vq->data;
  for (b_j1 = 0; b_j1 < nd2; b_j1++) {
    Vq_data[b_j1] = 0.0;
  }
  if (varargin_3->size[0] != 0) {
    b_st.site = &vd_emlrtRSI;
    if (b_anynan(&b_st, varargin_1)) {
      emlrtErrorWithMessageIdR2018a(&st, &r_emlrtRTEI, "MATLAB:interp1:NaNinX",
                                    "MATLAB:interp1:NaNinX", 0);
    }
    if (varargin_1_data[1] < varargin_1_data[0]) {
      real_T xtmp;
      n = varargin_1->size[1] >> 1;
      b_st.site = &wd_emlrtRSI;
      for (b_j1 = 0; b_j1 < n; b_j1++) {
        xtmp = x_data[b_j1];
        nd2 = nx - b_j1;
        x_data[b_j1] = x_data[nd2];
        x_data[nd2] = xtmp;
      }
      b_st.site = &xd_emlrtRSI;
      if (varargin_2->size[0] > 1) {
        n = varargin_2->size[0] - 1;
        nd2 = varargin_2->size[0] >> 1;
        for (b_j1 = 0; b_j1 < nd2; b_j1++) {
          int32_T y_tmp;
          xtmp = y_data[b_j1];
          y_tmp = n - b_j1;
          y_data[b_j1] = y_data[y_tmp];
          y_data[y_tmp] = xtmp;
        }
      }
    }
    b_st.site = &yd_emlrtRSI;
    if (varargin_1->size[1] > 2147483646) {
      c_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    for (b_j1 = 2; b_j1 <= nx + 1; b_j1++) {
      if (x_data[b_j1 - 1] <= x_data[b_j1 - 2]) {
        emlrtErrorWithMessageIdR2018a(&st, &q_emlrtRTEI,
                                      "Coder:toolbox:interp1_nonMonotonicX",
                                      "Coder:toolbox:interp1_nonMonotonicX", 0);
      }
    }
    b_st.site = &vg_emlrtRSI;
    interp1Linear(&b_st, y, varargin_3, Vq, x);
  }
  emxFree_real_T(&st, &x);
  emxFree_real_T(&st, &y);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

void e_interp1(const emlrtStack *sp, const emxArray_real_T *varargin_1,
               const emxArray_creal_T *varargin_2,
               const emxArray_real_T *varargin_3, emxArray_creal_T *Vq)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  emxArray_creal_T *y;
  emxArray_real_T *x;
  const creal_T *varargin_2_data;
  creal_T *Vq_data;
  creal_T *y_data;
  const real_T *varargin_1_data;
  real_T *x_data;
  int32_T b_j1;
  int32_T n;
  int32_T nd2;
  int32_T nx;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  varargin_2_data = varargin_2->data;
  varargin_1_data = varargin_1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  st.site = &ug_emlrtRSI;
  emxInit_creal_T(&st, &y, 1, &sg_emlrtRTEI);
  nd2 = varargin_2->size[0];
  n = y->size[0];
  y->size[0] = varargin_2->size[0];
  emxEnsureCapacity_creal_T(&st, y, n, &sg_emlrtRTEI);
  y_data = y->data;
  for (b_j1 = 0; b_j1 < nd2; b_j1++) {
    y_data[b_j1] = varargin_2_data[b_j1];
  }
  emxInit_real_T(&st, &x, 1, &tg_emlrtRTEI);
  nd2 = varargin_1->size[0];
  n = x->size[0];
  x->size[0] = varargin_1->size[0];
  emxEnsureCapacity_real_T(&st, x, n, &tg_emlrtRTEI);
  x_data = x->data;
  for (b_j1 = 0; b_j1 < nd2; b_j1++) {
    x_data[b_j1] = varargin_1_data[b_j1];
  }
  nx = varargin_1->size[0] - 1;
  if (varargin_1->size[0] != varargin_2->size[0]) {
    emlrtErrorWithMessageIdR2018a(&st, &t_emlrtRTEI,
                                  "Coder:MATLAB:interp1_YInvalidNumRows",
                                  "Coder:MATLAB:interp1_YInvalidNumRows", 0);
  }
  if (varargin_1->size[0] <= 1) {
    emlrtErrorWithMessageIdR2018a(&st, &s_emlrtRTEI,
                                  "MATLAB:interp1:NotEnoughPts",
                                  "MATLAB:interp1:NotEnoughPts", 0);
  }
  nd2 = varargin_3->size[0];
  n = Vq->size[0];
  Vq->size[0] = varargin_3->size[0];
  emxEnsureCapacity_creal_T(&st, Vq, n, &ug_emlrtRTEI);
  Vq_data = Vq->data;
  for (b_j1 = 0; b_j1 < nd2; b_j1++) {
    Vq_data[b_j1].re = 0.0;
    Vq_data[b_j1].im = 0.0;
  }
  if (varargin_3->size[0] != 0) {
    b_st.site = &vd_emlrtRSI;
    if (anynan(&b_st, varargin_1)) {
      emlrtErrorWithMessageIdR2018a(&st, &r_emlrtRTEI, "MATLAB:interp1:NaNinX",
                                    "MATLAB:interp1:NaNinX", 0);
    }
    if (varargin_1_data[1] < varargin_1_data[0]) {
      real_T xtmp;
      n = varargin_1->size[0] >> 1;
      b_st.site = &wd_emlrtRSI;
      for (b_j1 = 0; b_j1 < n; b_j1++) {
        xtmp = x_data[b_j1];
        nd2 = nx - b_j1;
        x_data[b_j1] = x_data[nd2];
        x_data[nd2] = xtmp;
      }
      b_st.site = &xd_emlrtRSI;
      if (varargin_2->size[0] > 1) {
        n = varargin_2->size[0] - 1;
        nd2 = varargin_2->size[0] >> 1;
        for (b_j1 = 0; b_j1 < nd2; b_j1++) {
          real_T tmp_im;
          int32_T y_tmp;
          xtmp = y_data[b_j1].re;
          tmp_im = y_data[b_j1].im;
          y_tmp = n - b_j1;
          y_data[b_j1] = y_data[y_tmp];
          y_data[y_tmp].re = xtmp;
          y_data[y_tmp].im = tmp_im;
        }
      }
    }
    b_st.site = &yd_emlrtRSI;
    if (varargin_1->size[0] > 2147483646) {
      c_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    for (b_j1 = 2; b_j1 <= nx + 1; b_j1++) {
      if (x_data[b_j1 - 1] <= x_data[b_j1 - 2]) {
        emlrtErrorWithMessageIdR2018a(&st, &q_emlrtRTEI,
                                      "Coder:toolbox:interp1_nonMonotonicX",
                                      "Coder:toolbox:interp1_nonMonotonicX", 0);
      }
    }
    b_st.site = &vg_emlrtRSI;
    b_interp1Linear(&b_st, y, varargin_3, Vq, x);
  }
  emxFree_real_T(&st, &x);
  emxFree_creal_T(&st, &y);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

void interp1(const emlrtStack *sp, const emxArray_real_T *varargin_1,
             const emxArray_creal_T *varargin_2, real_T varargin_3,
             emxArray_creal_T *Vq)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  emxArray_creal_T *b_y;
  emxArray_creal_T *pp_coefs;
  emxArray_creal_T *y;
  emxArray_creal_T *yi;
  emxArray_real_T *pp_breaks;
  emxArray_real_T *x;
  const creal_T *varargin_2_data;
  creal_T *Vq_data;
  creal_T *y_data;
  const real_T *varargin_1_data;
  real_T xtmp;
  real_T *x_data;
  int32_T b_ip;
  int32_T b_j1;
  int32_T coefStride;
  int32_T elementsPerPage;
  int32_T ip;
  int32_T j;
  int32_T loop_ub;
  int32_T nx;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  varargin_2_data = varargin_2->data;
  varargin_1_data = varargin_1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  st.site = &ud_emlrtRSI;
  emxInit_creal_T(&st, &y, 2, &re_emlrtRTEI);
  ip = y->size[0] * y->size[1];
  y->size[0] = varargin_2->size[0];
  loop_ub = varargin_2->size[1];
  y->size[1] = varargin_2->size[1];
  emxEnsureCapacity_creal_T(&st, y, ip, &re_emlrtRTEI);
  Vq_data = y->data;
  ip = varargin_2->size[0] * varargin_2->size[1];
  for (b_j1 = 0; b_j1 < ip; b_j1++) {
    Vq_data[b_j1] = varargin_2_data[b_j1];
  }
  emxInit_real_T(&st, &x, 1, &se_emlrtRTEI);
  b_ip = varargin_1->size[0];
  ip = x->size[0];
  x->size[0] = varargin_1->size[0];
  emxEnsureCapacity_real_T(&st, x, ip, &se_emlrtRTEI);
  x_data = x->data;
  for (b_j1 = 0; b_j1 < b_ip; b_j1++) {
    x_data[b_j1] = varargin_1_data[b_j1];
  }
  if (((varargin_2->size[0] != 1) || (varargin_2->size[1] != 1)) &&
      ((varargin_2->size[0] == 1) || (varargin_2->size[1] == 1)) &&
      (varargin_2->size[0] == 1)) {
    emlrtErrorWithMessageIdR2018a(
        &st, &u_emlrtRTEI, "Coder:toolbox:interp1_vsizeMatrixBecameRowVec",
        "Coder:toolbox:interp1_vsizeMatrixBecameRowVec", 0);
  }
  nx = varargin_1->size[0] - 1;
  if (varargin_1->size[0] != varargin_2->size[0]) {
    emlrtErrorWithMessageIdR2018a(&st, &t_emlrtRTEI,
                                  "Coder:MATLAB:interp1_YInvalidNumRows",
                                  "Coder:MATLAB:interp1_YInvalidNumRows", 0);
  }
  if (varargin_1->size[0] <= 1) {
    emlrtErrorWithMessageIdR2018a(&st, &s_emlrtRTEI,
                                  "MATLAB:interp1:NotEnoughPts",
                                  "MATLAB:interp1:NotEnoughPts", 0);
  }
  b_st.site = &vd_emlrtRSI;
  if (anynan(&b_st, varargin_1)) {
    emlrtErrorWithMessageIdR2018a(&st, &r_emlrtRTEI, "MATLAB:interp1:NaNinX",
                                  "MATLAB:interp1:NaNinX", 0);
  }
  if (varargin_1_data[1] < varargin_1_data[0]) {
    ip = varargin_1->size[0] >> 1;
    b_st.site = &wd_emlrtRSI;
    for (b_j1 = 0; b_j1 < ip; b_j1++) {
      xtmp = x_data[b_j1];
      b_ip = nx - b_j1;
      x_data[b_j1] = x_data[b_ip];
      x_data[b_ip] = xtmp;
    }
    b_st.site = &xd_emlrtRSI;
    flip(y);
    Vq_data = y->data;
  }
  b_st.site = &yd_emlrtRSI;
  if (varargin_1->size[0] > 2147483646) {
    c_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  for (b_j1 = 2; b_j1 <= nx + 1; b_j1++) {
    if (x_data[b_j1 - 1] <= x_data[b_j1 - 2]) {
      emlrtErrorWithMessageIdR2018a(&st, &q_emlrtRTEI,
                                    "Coder:toolbox:interp1_nonMonotonicX",
                                    "Coder:toolbox:interp1_nonMonotonicX", 0);
    }
  }
  b_st.site = &ae_emlrtRSI;
  c_st.site = &fe_emlrtRSI;
  emxInit_creal_T(&c_st, &b_y, 2, &te_emlrtRTEI);
  b_ip = y->size[1];
  ip = b_y->size[0] * b_y->size[1];
  b_y->size[0] = y->size[1];
  nx = y->size[0];
  b_y->size[1] = y->size[0];
  emxEnsureCapacity_creal_T(&c_st, b_y, ip, &te_emlrtRTEI);
  y_data = b_y->data;
  for (b_j1 = 0; b_j1 < nx; b_j1++) {
    for (j = 0; j < b_ip; j++) {
      y_data[j + b_y->size[0] * b_j1] = Vq_data[b_j1 + y->size[0] * j];
    }
  }
  emxFree_creal_T(&c_st, &y);
  emxInit_real_T(&c_st, &pp_breaks, 2, &we_emlrtRTEI);
  emxInit_creal_T(&c_st, &pp_coefs, 3, &we_emlrtRTEI);
  d_st.site = &he_emlrtRSI;
  pchip(&d_st, x, b_y, pp_breaks, pp_coefs);
  Vq_data = pp_coefs->data;
  x_data = pp_breaks->data;
  emxFree_creal_T(&c_st, &b_y);
  emxFree_real_T(&c_st, &x);
  c_st.site = &ge_emlrtRSI;
  elementsPerPage = pp_coefs->size[0];
  coefStride = pp_coefs->size[0] * (pp_breaks->size[1] - 1);
  emxInit_creal_T(&c_st, &yi, 1, &xe_emlrtRTEI);
  ip = yi->size[0];
  yi->size[0] = pp_coefs->size[0];
  emxEnsureCapacity_creal_T(&c_st, yi, ip, &ue_emlrtRTEI);
  y_data = yi->data;
  if (pp_coefs->size[0] == 1) {
    real_T v_re;
    if (muDoubleScalarIsNaN(varargin_3)) {
      v_re = rtNaN;
      xtmp = 0.0;
    } else {
      b_ip = b_bsearch(pp_breaks, varargin_3) - 1;
      xtmp = varargin_3 - x_data[b_ip];
      nx = b_ip + coefStride;
      elementsPerPage = b_ip + (coefStride << 1);
      ip = b_ip + 3 * coefStride;
      v_re = xtmp * (xtmp * (xtmp * Vq_data[b_ip].re + Vq_data[nx].re) +
                     Vq_data[elementsPerPage].re) +
             Vq_data[ip].re;
      xtmp = xtmp * (xtmp * (xtmp * Vq_data[b_ip].im + Vq_data[nx].im) +
                     Vq_data[elementsPerPage].im) +
             Vq_data[ip].im;
    }
    y_data[0].re = v_re;
    y_data[0].im = xtmp;
  } else if (muDoubleScalarIsNaN(varargin_3)) {
    d_st.site = &xe_emlrtRSI;
    if (pp_coefs->size[0] > 2147483646) {
      e_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(&e_st);
    }
    for (b_j1 = 0; b_j1 < elementsPerPage; b_j1++) {
      y_data[b_j1].re = rtNaN;
      y_data[b_j1].im = 0.0;
    }
  } else {
    ip = b_bsearch(pp_breaks, varargin_3) - 1;
    b_ip = ip * pp_coefs->size[0];
    xtmp = varargin_3 - x_data[ip];
    d_st.site = &ye_emlrtRSI;
    if (pp_coefs->size[0] > 2147483646) {
      e_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(&e_st);
    }
    for (b_j1 = 0; b_j1 < elementsPerPage; b_j1++) {
      y_data[b_j1] = Vq_data[b_ip + b_j1];
    }
    for (b_j1 = 0; b_j1 < 3; b_j1++) {
      ip = b_ip + (b_j1 + 1) * coefStride;
      d_st.site = &af_emlrtRSI;
      for (j = 0; j < elementsPerPage; j++) {
        nx = ip + j;
        y_data[j].re = xtmp * y_data[j].re + Vq_data[nx].re;
        y_data[j].im = xtmp * y_data[j].im + Vq_data[nx].im;
      }
    }
  }
  emxFree_creal_T(&c_st, &pp_coefs);
  emxFree_real_T(&c_st, &pp_breaks);
  ip = Vq->size[0] * Vq->size[1];
  Vq->size[0] = 1;
  Vq->size[1] = varargin_2->size[1];
  emxEnsureCapacity_creal_T(&b_st, Vq, ip, &ve_emlrtRTEI);
  Vq_data = Vq->data;
  for (b_j1 = 0; b_j1 < loop_ub; b_j1++) {
    Vq_data[b_j1] = y_data[b_j1];
  }
  emxFree_creal_T(&b_st, &yi);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (interp1.c) */
