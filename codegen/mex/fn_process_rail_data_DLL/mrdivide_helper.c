/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mrdivide_helper.c
 *
 * Code generation for function 'mrdivide_helper'
 *
 */

/* Include files */
#include "mrdivide_helper.h"
#include "eml_int_forloop_overflow_check.h"
#include "fn_process_rail_data_DLL_data.h"
#include "fn_process_rail_data_DLL_emxutil.h"
#include "fn_process_rail_data_DLL_types.h"
#include "rt_nonfinite.h"
#include "warning.h"
#include "lapacke.h"
#include "mwmathutil.h"
#include "omp.h"
#include <emmintrin.h>
#include <stddef.h>

/* Variable Definitions */
static emlrtRSInfo ah_emlrtRSI = {
    44,      /* lineNo */
    "mrdiv", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\mrdivide_"
    "helper.m" /* pathName */
};

static emlrtRSInfo
    bh_emlrtRSI =
        {
            61,        /* lineNo */
            "qrsolve", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\qrsolve.m" /* pathName */
};

static emlrtRSInfo
    ch_emlrtRSI =
        {
            72,        /* lineNo */
            "qrsolve", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\qrsolve.m" /* pathName */
};

static emlrtRSInfo
    dh_emlrtRSI =
        {
            85,        /* lineNo */
            "qrsolve", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\qrsolve.m" /* pathName */
};

static emlrtRSInfo eh_emlrtRSI = {
    63,       /* lineNo */
    "xgeqp3", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgeqp3.m" /* pathName */
};

static emlrtRSInfo fh_emlrtRSI = {
    138,            /* lineNo */
    "ceval_xgeqp3", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgeqp3.m" /* pathName */
};

static emlrtRSInfo gh_emlrtRSI = {
    143,            /* lineNo */
    "ceval_xgeqp3", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgeqp3.m" /* pathName */
};

static emlrtRSInfo hh_emlrtRSI = {
    148,            /* lineNo */
    "ceval_xgeqp3", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgeqp3.m" /* pathName */
};

static emlrtRSInfo ih_emlrtRSI = {
    151,            /* lineNo */
    "ceval_xgeqp3", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgeqp3.m" /* pathName */
};

static emlrtRSInfo
    jh_emlrtRSI =
        {
            173,          /* lineNo */
            "rankFromQR", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\qrsolve.m" /* pathName */
};

static emlrtRSInfo
    kh_emlrtRSI =
        {
            172,          /* lineNo */
            "rankFromQR", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\qrsolve.m" /* pathName */
};

static emlrtRSInfo
    lh_emlrtRSI =
        {
            119,         /* lineNo */
            "LSQFromQR", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\qrsolve.m" /* pathName */
};

static emlrtRSInfo
    mh_emlrtRSI =
        {
            126,         /* lineNo */
            "LSQFromQR", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\qrsolve.m" /* pathName */
};

static emlrtRSInfo
    nh_emlrtRSI =
        {
            128,         /* lineNo */
            "LSQFromQR", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\qrsolve.m" /* pathName */
};

static emlrtRSInfo
    oh_emlrtRSI =
        {
            138,         /* lineNo */
            "LSQFromQR", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\qrsolve.m" /* pathName */
};

static emlrtRSInfo ph_emlrtRSI = {
    40,         /* lineNo */
    "xunormqr", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xunormqr.m" /* pathName */
};

static emlrtRSInfo qh_emlrtRSI = {
    106,              /* lineNo */
    "ceval_xunormqr", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xunormqr.m" /* pathName */
};

static emlrtRSInfo rh_emlrtRSI = {
    112,              /* lineNo */
    "ceval_xunormqr", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xunormqr.m" /* pathName */
};

static emlrtRSInfo sh_emlrtRSI = {
    23,          /* lineNo */
    "xzunormqr", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzunormqr.m" /* pathName */
};

static emlrtRSInfo th_emlrtRSI = {
    21,          /* lineNo */
    "xzunormqr", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzunormqr.m" /* pathName */
};

static emlrtRSInfo uh_emlrtRSI = {
    38,                    /* lineNo */
    "applyJthHouseHolder", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzunormqr.m" /* pathName */
};

static emlrtRSInfo vh_emlrtRSI = {
    40,                    /* lineNo */
    "applyJthHouseHolder", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzunormqr.m" /* pathName */
};

static emlrtRSInfo wh_emlrtRSI = {
    46,                    /* lineNo */
    "applyJthHouseHolder", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzunormqr.m" /* pathName */
};

static emlrtMCInfo c_emlrtMCI = {
    53,        /* lineNo */
    19,        /* colNo */
    "flt2str", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\flt2str.m" /* pName */
};

static emlrtRTEInfo mg_emlrtRTEI = {
    31,                /* lineNo */
    5,                 /* colNo */
    "mrdivide_helper", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\mrdivide_"
    "helper.m" /* pName */
};

static emlrtRTEInfo ng_emlrtRTEI = {
    42,                /* lineNo */
    5,                 /* colNo */
    "mrdivide_helper", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\mrdivide_"
    "helper.m" /* pName */
};

static emlrtRTEInfo og_emlrtRTEI = {
    44,                /* lineNo */
    32,                /* colNo */
    "mrdivide_helper", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\mrdivide_"
    "helper.m" /* pName */
};

static emlrtRTEInfo pg_emlrtRTEI = {
    44,                /* lineNo */
    35,                /* colNo */
    "mrdivide_helper", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\mrdivide_"
    "helper.m" /* pName */
};

static emlrtRTEInfo
    qg_emlrtRTEI =
        {
            85,        /* lineNo */
            1,         /* colNo */
            "qrsolve", /* fName */
            "C:\\Program "
            "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\qrsolve.m" /* pName */
};

static emlrtRTEInfo
    rg_emlrtRTEI =
        {
            119,       /* lineNo */
            5,         /* colNo */
            "qrsolve", /* fName */
            "C:\\Program "
            "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\qrsolve.m" /* pName */
};

static emlrtRTEInfo sg_emlrtRTEI = {
    44,                /* lineNo */
    5,                 /* colNo */
    "mrdivide_helper", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\mrdivide_"
    "helper.m" /* pName */
};

static emlrtRTEInfo tg_emlrtRTEI = {
    44,                /* lineNo */
    9,                 /* colNo */
    "mrdivide_helper", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\mrdivide_"
    "helper.m" /* pName */
};

static emlrtRTEInfo ug_emlrtRTEI = {
    25,                /* lineNo */
    14,                /* colNo */
    "mrdivide_helper", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\mrdivide_"
    "helper.m" /* pName */
};

static emlrtRSInfo vi_emlrtRSI = {
    53,        /* lineNo */
    "flt2str", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\flt2str.m" /* pathName */
};

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               char_T y[14]);

static const mxArray *b_sprintf(const emlrtStack *sp, const mxArray *m,
                                const mxArray *m1, emlrtMCInfo *location);

static void emlrt_marshallIn(const emlrtStack *sp,
                             const mxArray *a__output_of_sprintf_,
                             const char_T *identifier, char_T y[14]);

static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, char_T ret[14]);

/* Function Definitions */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, char_T y[14])
{
  s_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *b_sprintf(const emlrtStack *sp, const mxArray *m,
                                const mxArray *m1, emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  const mxArray *m2;
  pArrays[0] = m;
  pArrays[1] = m1;
  return emlrtCallMATLABR2012b((emlrtConstCTX)sp, 1, &m2, 2, &pArrays[0],
                               "sprintf", true, location);
}

static void emlrt_marshallIn(const emlrtStack *sp,
                             const mxArray *a__output_of_sprintf_,
                             const char_T *identifier, char_T y[14])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(a__output_of_sprintf_), &thisId, y);
  emlrtDestroyArray(&a__output_of_sprintf_);
}

static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, char_T ret[14])
{
  static const int32_T dims[2] = {1, 14};
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "char", false, 2U,
                          (const void *)&dims[0]);
  emlrtImportCharArrayR2015b((emlrtConstCTX)sp, src, &ret[0], 14);
  emlrtDestroyArray(&src);
}

void mrdiv(const emlrtStack *sp, const emxArray_real_T *A,
           const emxArray_real_T *B, emxArray_real_T *Y)
{
  static const int32_T iv[2] = {1, 6};
  static const char_T b_fname[14] = {'L', 'A', 'P', 'A', 'C', 'K', 'E',
                                     '_', 'd', 'o', 'r', 'm', 'q', 'r'};
  static const char_T fname[14] = {'L', 'A', 'P', 'A', 'C', 'K', 'E',
                                   '_', 'd', 'g', 'e', 'q', 'p', '3'};
  static const char_T rfmt[6] = {'%', '1', '4', '.', '6', 'e'};
  __m128d r;
  __m128d r1;
  jmp_buf emlrtJBEnviron;
  ptrdiff_t jpvt_t;
  jmp_buf *volatile emlrtJBStack;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack i_st;
  emlrtStack st;
  emlrtStack *b_sp;
  emxArray_real_T *b_A;
  emxArray_real_T *b_B;
  emxArray_real_T *b_Y;
  const mxArray *b_y;
  const mxArray *m;
  const mxArray *y;
  const real_T *A_data;
  const real_T *B_data;
  real_T tau_data;
  real_T tol;
  real_T wj;
  real_T *Y_data;
  real_T *b_B_data;
  real_T *b_Y_data;
  int32_T b_k;
  int32_T b_loop_ub;
  int32_T b_m;
  int32_T b_nb;
  int32_T i;
  int32_T j;
  int32_T k;
  int32_T loop_ub;
  int32_T mrdiv_numThreads;
  int32_T nb;
  int32_T rankA;
  int32_T scalarLB;
  char_T str[14];
  boolean_T emlrtHadParallelError = false;
  boolean_T overflow;
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
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  B_data = B->data;
  A_data = A->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_real_T(sp, &b_Y, 2, &tg_emlrtRTEI);
  emxInit_real_T(sp, &b_B, 2, &pg_emlrtRTEI);
  emxInit_real_T(sp, &b_A, 1, &ug_emlrtRTEI);
  if ((A->size[0] == 0) || (A->size[1] == 0) || (B->size[1] == 0)) {
    loop_ub = A->size[0];
    scalarLB = Y->size[0];
    Y->size[0] = A->size[0];
    emxEnsureCapacity_real_T(sp, Y, scalarLB, &mg_emlrtRTEI);
    Y_data = Y->data;
    for (i = 0; i < loop_ub; i++) {
      Y_data[i] = 0.0;
    }
  } else if (B->size[1] == 1) {
    wj = B_data[0];
    nb = A->size[0];
    scalarLB = Y->size[0];
    Y->size[0] = A->size[0];
    emxEnsureCapacity_real_T(sp, Y, scalarLB, &ng_emlrtRTEI);
    Y_data = Y->data;
    scalarLB = (A->size[0] / 2) << 1;
    loop_ub = scalarLB - 2;
    for (i = 0; i <= loop_ub; i += 2) {
      _mm_storeu_pd(&Y_data[i],
                    _mm_div_pd(_mm_loadu_pd(&A_data[i]), _mm_set1_pd(wj)));
    }
    for (i = scalarLB; i < nb; i++) {
      Y_data[i] = A_data[i] / wj;
    }
  } else {
    st.site = &ah_emlrtRSI;
    nb = B->size[1];
    scalarLB = b_A->size[0];
    b_A->size[0] = B->size[1];
    emxEnsureCapacity_real_T(&st, b_A, scalarLB, &og_emlrtRTEI);
    Y_data = b_A->data;
    for (i = 0; i < nb; i++) {
      Y_data[i] = B_data[i];
    }
    scalarLB = A->size[1];
    loop_ub = b_B->size[0] * b_B->size[1];
    b_B->size[0] = A->size[1];
    b_loop_ub = A->size[0];
    b_B->size[1] = A->size[0];
    emxEnsureCapacity_real_T(&st, b_B, loop_ub, &pg_emlrtRTEI);
    b_B_data = b_B->data;
    for (i = 0; i < b_loop_ub; i++) {
      for (k = 0; k < scalarLB; k++) {
        b_B_data[k + b_B->size[0] * i] = A_data[i + A->size[0] * k];
      }
    }
    b_st.site = &bh_emlrtRSI;
    c_st.site = &eh_emlrtRSI;
    jpvt_t = (ptrdiff_t)0;
    jpvt_t =
        LAPACKE_dgeqp3(102, (ptrdiff_t)b_A->size[0], (ptrdiff_t)1, &Y_data[0],
                       (ptrdiff_t)b_A->size[0], &jpvt_t, &tau_data);
    d_st.site = &fh_emlrtRSI;
    if ((int32_T)jpvt_t != 0) {
      overflow = true;
      if ((int32_T)jpvt_t != -4) {
        if ((int32_T)jpvt_t == -1010) {
          emlrtErrorWithMessageIdR2018a(&d_st, &cb_emlrtRTEI, "MATLAB:nomem",
                                        "MATLAB:nomem", 0);
        } else {
          emlrtErrorWithMessageIdR2018a(&d_st, &db_emlrtRTEI,
                                        "Coder:toolbox:LAPACKCallErrorInfo",
                                        "Coder:toolbox:LAPACKCallErrorInfo", 5,
                                        4, 14, &fname[0], 12, (int32_T)jpvt_t);
        }
      }
    } else {
      overflow = false;
    }
    if (overflow) {
      d_st.site = &gh_emlrtRSI;
      if (b_A->size[0] > 2147483646) {
        e_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(&e_st);
      }
      for (i = 0; i < nb; i++) {
        Y_data[i] = rtNaN;
      }
      d_st.site = &hh_emlrtRSI;
      tau_data = rtNaN;
      d_st.site = &ih_emlrtRSI;
    }
    b_st.site = &ch_emlrtRSI;
    rankA = 0;
    wj = muDoubleScalarAbs(Y_data[0]);
    tol = muDoubleScalarMin(1.4901161193847656E-8,
                            2.2204460492503131E-15 * (real_T)b_A->size[0]) *
          wj;
    if (!(wj <= tol)) {
      rankA = 1;
    } else if (!emlrtSetWarningFlag(&b_st)) {
      c_st.site = &jh_emlrtRSI;
      y = NULL;
      m = emlrtCreateCharArray(2, &iv[0]);
      emlrtInitCharArrayR2013a(&c_st, 6, m, &rfmt[0]);
      emlrtAssign(&y, m);
      b_y = NULL;
      m = emlrtCreateDoubleScalar(tol);
      emlrtAssign(&b_y, m);
      d_st.site = &vi_emlrtRSI;
      emlrt_marshallIn(&d_st, b_sprintf(&d_st, y, b_y, &c_emlrtMCI),
                       "<output of sprintf>", str);
      c_st.site = &kh_emlrtRSI;
      b_warning(&c_st, str);
    }
    b_st.site = &dh_emlrtRSI;
    b_nb = A->size[0];
    loop_ub = b_Y->size[0] * b_Y->size[1];
    b_Y->size[0] = 1;
    b_Y->size[1] = A->size[0];
    emxEnsureCapacity_real_T(&b_st, b_Y, loop_ub, &qg_emlrtRTEI);
    b_Y_data = b_Y->data;
    for (i = 0; i < b_loop_ub; i++) {
      b_Y_data[i] = 0.0;
    }
    c_st.site = &lh_emlrtRSI;
    d_st.site = &ph_emlrtRSI;
    jpvt_t = (ptrdiff_t)b_B->size[0];
    jpvt_t = LAPACKE_dormqr(102, 'L', 'T', jpvt_t, (ptrdiff_t)b_B->size[1],
                            (ptrdiff_t)1, &Y_data[0], (ptrdiff_t)b_A->size[0],
                            &tau_data, &b_B_data[0], jpvt_t);
    e_st.site = &qh_emlrtRSI;
    if ((int32_T)jpvt_t != 0) {
      overflow = true;
      p = false;
      if ((int32_T)jpvt_t == -7) {
        p = true;
      } else if ((int32_T)jpvt_t == -9) {
        p = true;
      } else if ((int32_T)jpvt_t == -10) {
        p = true;
      }
      if (!p) {
        if ((int32_T)jpvt_t == -1010) {
          emlrtErrorWithMessageIdR2018a(&e_st, &cb_emlrtRTEI, "MATLAB:nomem",
                                        "MATLAB:nomem", 0);
        } else {
          emlrtErrorWithMessageIdR2018a(
              &e_st, &db_emlrtRTEI, "Coder:toolbox:LAPACKCallErrorInfo",
              "Coder:toolbox:LAPACKCallErrorInfo", 5, 4, 14, &b_fname[0], 12,
              (int32_T)jpvt_t);
        }
      }
    } else {
      overflow = false;
    }
    if (overflow) {
      if (((int32_T)jpvt_t == -10) && (b_B->size[1] > 1)) {
        e_st.site = &rh_emlrtRSI;
        f_st.site = &th_emlrtRSI;
        f_st.site = &sh_emlrtRSI;
        nb = b_B->size[1];
        b_m = b_A->size[0];
        if (tau_data != 0.0) {
          g_st.site = &uh_emlrtRSI;
          if (b_B->size[1] > 2147483646) {
            h_st.site = &o_emlrtRSI;
            check_forloop_overflow_error(&h_st);
          }
          overflow = (b_A->size[0] > 2147483646);
          for (k = 0; k < nb; k++) {
            wj = b_B_data[b_B->size[0] * k];
            g_st.site = &vh_emlrtRSI;
            if (overflow) {
              h_st.site = &o_emlrtRSI;
              check_forloop_overflow_error(&h_st);
            }
            for (i = 2; i <= b_m; i++) {
              wj += Y_data[i - 1] * b_B_data[(i + b_B->size[0] * k) - 1];
            }
            wj *= tau_data;
            if (wj != 0.0) {
              b_B_data[b_B->size[0] * k] -= wj;
              g_st.site = &wh_emlrtRSI;
              if (b_m > 2147483646) {
                h_st.site = &o_emlrtRSI;
                check_forloop_overflow_error(&h_st);
              }
              loop_ub = (((b_m - 1) / 2) << 1) + 2;
              scalarLB = loop_ub - 2;
              for (i = 2; i <= scalarLB; i += 2) {
                r = _mm_loadu_pd(&Y_data[i - 1]);
                r1 = _mm_loadu_pd(&b_B_data[(i + b_B->size[0] * k) - 1]);
                _mm_storeu_pd(&b_B_data[(i + b_B->size[0] * k) - 1],
                              _mm_sub_pd(r1, _mm_mul_pd(r, _mm_set1_pd(wj))));
              }
              for (i = loop_ub; i <= b_m; i++) {
                b_B_data[(i + b_B->size[0] * k) - 1] -= Y_data[i - 1] * wj;
              }
            }
          }
        }
      } else {
        loop_ub = b_B->size[0];
        scalarLB = b_B->size[1];
        nb = b_B->size[0] * b_B->size[1];
        b_B->size[0] = loop_ub;
        b_B->size[1] = scalarLB;
        emxEnsureCapacity_real_T(&d_st, b_B, nb, &rg_emlrtRTEI);
        b_B_data = b_B->data;
        loop_ub *= scalarLB;
        for (i = 0; i < loop_ub; i++) {
          b_B_data[i] = rtNaN;
        }
      }
    }
    c_st.site = &mh_emlrtRSI;
    if (A->size[0] > 2147483646) {
      d_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
    if (A->size[0] * (rankA - 2) < 2000) {
      for (b_k = 0; b_k < b_loop_ub; b_k++) {
        c_st.site = &nh_emlrtRSI;
        if (rankA - 1 >= 0) {
          b_Y_data[b_k] = b_B_data[b_B->size[0] * b_k];
        }
        for (j = rankA; j >= 1; j--) {
          b_Y_data[b_k] /= Y_data[0];
          c_st.site = &oh_emlrtRSI;
        }
      }
    } else {
      emlrtEnterParallelRegion(&b_st, omp_in_parallel());
      emlrtPushJmpBuf(&b_st, &emlrtJBStack);
      mrdiv_numThreads =
          emlrtAllocRegionTLSs(b_st.tls, omp_in_parallel(),
                               omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel num_threads(mrdiv_numThreads) private(                    \
        j, i_st, emlrtJBEnviron) firstprivate(b_st, emlrtHadParallelError)
      {
        if (setjmp(emlrtJBEnviron) == 0) {
          i_st.prev = &b_st;
          i_st.tls = emlrtAllocTLS(&b_st, omp_get_thread_num());
          i_st.site = NULL;
          emlrtSetJmpBuf(&i_st, &emlrtJBEnviron);
        } else {
          emlrtHadParallelError = true;
        }
#pragma omp for nowait
        for (b_k = 0; b_k < b_nb; b_k++) {
          if (emlrtHadParallelError) {
            continue;
          }
          if (setjmp(emlrtJBEnviron) == 0) {
            if (rankA - 1 >= 0) {
              b_Y_data[b_k] = b_B_data[b_B->size[0] * b_k];
            }
            for (j = rankA; j >= 1; j--) {
              b_Y_data[b_k] /= Y_data[0];
            }
          } else {
            emlrtHadParallelError = true;
          }
        }
      }
      emlrtPopJmpBuf(&b_st, &emlrtJBStack);
      emlrtExitParallelRegion(&b_st, omp_in_parallel());
    }
    scalarLB = Y->size[0];
    Y->size[0] = b_loop_ub;
    emxEnsureCapacity_real_T(sp, Y, scalarLB, &sg_emlrtRTEI);
    Y_data = Y->data;
    for (i = 0; i < b_loop_ub; i++) {
      Y_data[i] = b_Y_data[i];
    }
  }
  emxFree_real_T(sp, &b_A);
  emxFree_real_T(sp, &b_B);
  emxFree_real_T(sp, &b_Y);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (mrdivide_helper.c) */
