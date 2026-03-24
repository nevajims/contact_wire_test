/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * pinv.c
 *
 * Code generation for function 'pinv'
 *
 */

/* Include files */
#include "pinv.h"
#include "eml_int_forloop_overflow_check.h"
#include "fn_process_rail_data_DLL_data.h"
#include "fn_process_rail_data_DLL_emxutil.h"
#include "fn_process_rail_data_DLL_types.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "lapacke.h"
#include "mwmathutil.h"
#include <math.h>
#include <stddef.h>

/* Variable Definitions */
static emlrtRSInfo ff_emlrtRSI = {
    42,         /* lineNo */
    "eml_pinv", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\matfun\\pinv.m" /* pathName
                                                                        */
};

static emlrtRSInfo gf_emlrtRSI = {
    46,         /* lineNo */
    "eml_pinv", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\matfun\\pinv.m" /* pathName
                                                                        */
};

static emlrtRSInfo hf_emlrtRSI = {
    58,         /* lineNo */
    "eml_pinv", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\matfun\\pinv.m" /* pathName
                                                                        */
};

static emlrtRSInfo if_emlrtRSI = {
    69,         /* lineNo */
    "eml_pinv", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\matfun\\pinv.m" /* pathName
                                                                        */
};

static emlrtRSInfo jf_emlrtRSI = {
    70,         /* lineNo */
    "eml_pinv", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\matfun\\pinv.m" /* pathName
                                                                        */
};

static emlrtRSInfo kf_emlrtRSI = {
    73,         /* lineNo */
    "eml_pinv", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\matfun\\pinv.m" /* pathName
                                                                        */
};

static emlrtRSInfo lf_emlrtRSI = {
    29,             /* lineNo */
    "anyNonFinite", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\anyNonFinite."
    "m" /* pathName */
};

static emlrtRSInfo mf_emlrtRSI = {
    52,    /* lineNo */
    "svd", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m" /* pathName
                                                                          */
};

static emlrtRSInfo nf_emlrtRSI = {
    93,           /* lineNo */
    "callLAPACK", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m" /* pathName
                                                                          */
};

static emlrtRSInfo of_emlrtRSI = {
    89,           /* lineNo */
    "callLAPACK", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m" /* pathName
                                                                          */
};

static emlrtRSInfo pf_emlrtRSI = {
    81,           /* lineNo */
    "callLAPACK", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m" /* pathName
                                                                          */
};

static emlrtRSInfo qf_emlrtRSI = {
    209,      /* lineNo */
    "xgesdd", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgesdd.m" /* pathName */
};

static emlrtRSInfo rf_emlrtRSI = {
    31,       /* lineNo */
    "xgesvd", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgesvd.m" /* pathName */
};

static emlrtRSInfo sf_emlrtRSI = {
    205,            /* lineNo */
    "ceval_xgesvd", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgesvd.m" /* pathName */
};

static emlrtRSInfo tf_emlrtRSI = {
    203,            /* lineNo */
    "ceval_xgesvd", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgesvd.m" /* pathName */
};

static emlrtRSInfo uf_emlrtRSI = {
    220,    /* lineNo */
    "getv", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgesvd.m" /* pathName */
};

static emlrtRSInfo vf_emlrtRSI = {
    221,    /* lineNo */
    "getv", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgesvd.m" /* pathName */
};

static emlrtRSInfo wf_emlrtRSI = {
    37,      /* lineNo */
    "xscal", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xscal."
    "m" /* pathName */
};

static emlrtRSInfo xf_emlrtRSI = {
    49,           /* lineNo */
    "xscal_blas", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xscal."
    "m" /* pathName */
};

static emlrtRSInfo yf_emlrtRSI = {
    77,      /* lineNo */
    "xgemm", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xgemm."
    "m" /* pathName */
};

static emlrtRSInfo ag_emlrtRSI = {
    94,           /* lineNo */
    "xgemm_blas", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xgemm."
    "m" /* pathName */
};

static emlrtRTEInfo bb_emlrtRTEI = {
    111,          /* lineNo */
    5,            /* colNo */
    "callLAPACK", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m" /* pName
                                                                          */
};

static emlrtRTEInfo uf_emlrtRTEI = {
    39,     /* lineNo */
    1,      /* colNo */
    "pinv", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\matfun\\pinv.m" /* pName
                                                                        */
};

static emlrtRTEInfo vf_emlrtRTEI = {
    43,     /* lineNo */
    5,      /* colNo */
    "pinv", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\matfun\\pinv.m" /* pName
                                                                        */
};

static emlrtRTEInfo wf_emlrtRTEI = {
    57,    /* lineNo */
    33,    /* colNo */
    "svd", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m" /* pName
                                                                          */
};

static emlrtRTEInfo xf_emlrtRTEI = {
    81,    /* lineNo */
    63,    /* colNo */
    "svd", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m" /* pName
                                                                          */
};

static emlrtRTEInfo yf_emlrtRTEI = {
    45,       /* lineNo */
    24,       /* colNo */
    "xgesdd", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgesdd.m" /* pName */
};

static emlrtRTEInfo ag_emlrtRTEI = {
    47,       /* lineNo */
    25,       /* colNo */
    "xgesdd", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgesdd.m" /* pName */
};

static emlrtRTEInfo bg_emlrtRTEI = {
    57,       /* lineNo */
    20,       /* colNo */
    "xgesdd", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgesdd.m" /* pName */
};

static emlrtRTEInfo cg_emlrtRTEI = {
    219,      /* lineNo */
    24,       /* colNo */
    "xgesvd", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgesvd.m" /* pName */
};

static emlrtRTEInfo dg_emlrtRTEI = {
    83,       /* lineNo */
    24,       /* colNo */
    "xgesvd", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgesvd.m" /* pName */
};

static emlrtRTEInfo eg_emlrtRTEI = {
    90,       /* lineNo */
    25,       /* colNo */
    "xgesvd", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgesvd.m" /* pName */
};

static emlrtRTEInfo fg_emlrtRTEI = {
    98,       /* lineNo */
    20,       /* colNo */
    "xgesvd", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgesvd.m" /* pName */
};

static emlrtRTEInfo gg_emlrtRTEI = {
    131,      /* lineNo */
    9,        /* colNo */
    "xgesvd", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgesvd.m" /* pName */
};

static emlrtRTEInfo hg_emlrtRTEI = {
    129,      /* lineNo */
    33,       /* colNo */
    "xgesvd", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgesvd.m" /* pName */
};

static emlrtRTEInfo ig_emlrtRTEI = {
    46,     /* lineNo */
    6,      /* colNo */
    "pinv", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\matfun\\pinv.m" /* pName
                                                                        */
};

static emlrtRTEInfo jg_emlrtRTEI = {
    33,     /* lineNo */
    14,     /* colNo */
    "pinv", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\matfun\\pinv.m" /* pName
                                                                        */
};

static emlrtRTEInfo kg_emlrtRTEI = {
    90,       /* lineNo */
    5,        /* colNo */
    "xgesvd", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgesvd.m" /* pName */
};

static emlrtRTEInfo lg_emlrtRTEI = {
    129,      /* lineNo */
    9,        /* colNo */
    "xgesvd", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgesvd.m" /* pName */
};

/* Function Definitions */
void eml_pinv(const emlrtStack *sp, const emxArray_creal_T *A,
              emxArray_creal_T *X)
{
  static const char_T b_fname[14] = {'L', 'A', 'P', 'A', 'C', 'K', 'E',
                                     '_', 'z', 'g', 'e', 's', 'v', 'd'};
  static const char_T fname[14] = {'L', 'A', 'P', 'A', 'C', 'K', 'E',
                                   '_', 'z', 'g', 'e', 's', 'd', 'd'};
  ptrdiff_t incx_t;
  ptrdiff_t info_t;
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack st;
  emxArray_creal_T *U;
  emxArray_creal_T *V;
  emxArray_creal_T *Vt;
  emxArray_creal_T *b_A;
  emxArray_real_T *S;
  emxArray_real_T *superb;
  const creal_T *A_data;
  creal_T *U_data;
  creal_T *V_data;
  creal_T *Vt_data;
  creal_T *X_data;
  creal_T *b_A_data;
  real_T *S_data;
  real_T *superb_data;
  int32_T b_i;
  int32_T c_i;
  int32_T exponent;
  int32_T i;
  int32_T k;
  int32_T minnm;
  int32_T n;
  char_T TRANSA1;
  char_T TRANSB1;
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
  A_data = A->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  n = A->size[1];
  i = X->size[0] * X->size[1];
  X->size[0] = A->size[1];
  b_i = A->size[0];
  X->size[1] = A->size[0];
  emxEnsureCapacity_creal_T(sp, X, i, &uf_emlrtRTEI);
  X_data = X->data;
  minnm = A->size[0] * A->size[1];
  for (k = 0; k < minnm; k++) {
    X_data[k] = dc;
  }
  emxInit_creal_T(sp, &V, 2, &ig_emlrtRTEI);
  emxInit_creal_T(sp, &U, 2, &jg_emlrtRTEI);
  emxInit_creal_T(sp, &Vt, 2, &kg_emlrtRTEI);
  emxInit_creal_T(sp, &b_A, 2, &xf_emlrtRTEI);
  emxInit_real_T(sp, &S, 1, &jg_emlrtRTEI);
  emxInit_real_T(sp, &superb, 1, &lg_emlrtRTEI);
  if ((A->size[0] != 0) && (A->size[1] != 0)) {
    boolean_T overflow;
    st.site = &ff_emlrtRSI;
    b_st.site = &lf_emlrtRSI;
    c_st.site = &vd_emlrtRSI;
    overflow = true;
    d_st.site = &wd_emlrtRSI;
    if (minnm > 2147483646) {
      e_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(&e_st);
    }
    for (k = 0; k < minnm; k++) {
      if ((!overflow) || (muDoubleScalarIsInf(A_data[k].re) ||
                          muDoubleScalarIsInf(A_data[k].im) ||
                          (muDoubleScalarIsNaN(A_data[k].re) ||
                           muDoubleScalarIsNaN(A_data[k].im)))) {
        overflow = false;
      }
    }
    if (!overflow) {
      i = X->size[0] * X->size[1];
      X->size[0] = A->size[1];
      X->size[1] = A->size[0];
      emxEnsureCapacity_creal_T(sp, X, i, &vf_emlrtRTEI);
      X_data = X->data;
      for (k = 0; k < minnm; k++) {
        X_data[k].re = rtNaN;
        X_data[k].im = 0.0;
      }
    } else {
      real_T absx;
      int32_T info;
      boolean_T exitg1;
      st.site = &gf_emlrtRSI;
      b_st.site = &mf_emlrtRSI;
      i = V->size[0] * V->size[1];
      V->size[0] = A->size[0];
      V->size[1] = A->size[1];
      emxEnsureCapacity_creal_T(&b_st, V, i, &wf_emlrtRTEI);
      V_data = V->data;
      for (k = 0; k < minnm; k++) {
        V_data[k] = A_data[k];
      }
      c_st.site = &pf_emlrtRSI;
      i = b_A->size[0] * b_A->size[1];
      b_A->size[0] = A->size[0];
      b_A->size[1] = A->size[1];
      emxEnsureCapacity_creal_T(&c_st, b_A, i, &xf_emlrtRTEI);
      b_A_data = b_A->data;
      for (k = 0; k < minnm; k++) {
        b_A_data[k] = A_data[k];
      }
      minnm = muIntScalarMin_sint32(n, b_i);
      i = U->size[0] * U->size[1];
      U->size[0] = A->size[0];
      U->size[1] = minnm;
      emxEnsureCapacity_creal_T(&c_st, U, i, &yf_emlrtRTEI);
      U_data = U->data;
      i = Vt->size[0] * Vt->size[1];
      Vt->size[0] = minnm;
      Vt->size[1] = A->size[1];
      emxEnsureCapacity_creal_T(&c_st, Vt, i, &ag_emlrtRTEI);
      Vt_data = Vt->data;
      i = S->size[0];
      S->size[0] = minnm;
      emxEnsureCapacity_real_T(&c_st, S, i, &bg_emlrtRTEI);
      S_data = S->data;
      info_t = LAPACKE_zgesdd(
          102, 'S', (ptrdiff_t)A->size[0], (ptrdiff_t)A->size[1],
          (lapack_complex_double *)&b_A_data[0], (ptrdiff_t)A->size[0],
          &S_data[0], (lapack_complex_double *)&U_data[0],
          (ptrdiff_t)A->size[0], (lapack_complex_double *)&Vt_data[0],
          (ptrdiff_t)minnm);
      d_st.site = &qf_emlrtRSI;
      if ((int32_T)info_t < 0) {
        if ((int32_T)info_t == -1010) {
          emlrtErrorWithMessageIdR2018a(&d_st, &cb_emlrtRTEI, "MATLAB:nomem",
                                        "MATLAB:nomem", 0);
        } else {
          emlrtErrorWithMessageIdR2018a(&d_st, &db_emlrtRTEI,
                                        "Coder:toolbox:LAPACKCallErrorInfo",
                                        "Coder:toolbox:LAPACKCallErrorInfo", 5,
                                        4, 14, &fname[0], 12, (int32_T)info_t);
        }
      }
      info = (int32_T)info_t;
      if ((int32_T)info_t > 0) {
        c_st.site = &of_emlrtRSI;
        d_st.site = &rf_emlrtRSI;
        i = U->size[0] * U->size[1];
        U->size[0] = A->size[0];
        U->size[1] = minnm;
        emxEnsureCapacity_creal_T(&d_st, U, i, &dg_emlrtRTEI);
        U_data = U->data;
        i = Vt->size[0] * Vt->size[1];
        Vt->size[0] = minnm;
        Vt->size[1] = A->size[1];
        emxEnsureCapacity_creal_T(&d_st, Vt, i, &eg_emlrtRTEI);
        Vt_data = Vt->data;
        i = S->size[0];
        S->size[0] = minnm;
        emxEnsureCapacity_real_T(&d_st, S, i, &fg_emlrtRTEI);
        S_data = S->data;
        if (minnm > 1) {
          i = superb->size[0];
          superb->size[0] = minnm - 1;
          emxEnsureCapacity_real_T(&d_st, superb, i, &hg_emlrtRTEI);
          superb_data = superb->data;
        } else {
          i = superb->size[0];
          superb->size[0] = 1;
          emxEnsureCapacity_real_T(&d_st, superb, i, &gg_emlrtRTEI);
          superb_data = superb->data;
        }
        info_t = LAPACKE_zgesvd(
            102, 'S', 'S', (ptrdiff_t)A->size[0], (ptrdiff_t)A->size[1],
            (lapack_complex_double *)&V_data[0], (ptrdiff_t)A->size[0],
            &S_data[0], (lapack_complex_double *)&U_data[0],
            (ptrdiff_t)A->size[0], (lapack_complex_double *)&Vt_data[0],
            (ptrdiff_t)minnm, &superb_data[0]);
        e_st.site = &tf_emlrtRSI;
        minnm = muIntScalarMin_sint32(b_i, n);
        i = V->size[0] * V->size[1];
        V->size[0] = A->size[1];
        V->size[1] = minnm;
        emxEnsureCapacity_creal_T(&e_st, V, i, &cg_emlrtRTEI);
        V_data = V->data;
        f_st.site = &uf_emlrtRSI;
        if (minnm > 2147483646) {
          g_st.site = &o_emlrtRSI;
          check_forloop_overflow_error(&g_st);
        }
        overflow = (A->size[1] > 2147483646);
        for (k = 0; k < minnm; k++) {
          f_st.site = &vf_emlrtRSI;
          if (overflow) {
            g_st.site = &o_emlrtRSI;
            check_forloop_overflow_error(&g_st);
          }
          for (c_i = 0; c_i < n; c_i++) {
            V_data[c_i + V->size[0] * k].re = Vt_data[k + Vt->size[0] * c_i].re;
            V_data[c_i + V->size[0] * k].im =
                -Vt_data[k + Vt->size[0] * c_i].im;
          }
        }
        e_st.site = &sf_emlrtRSI;
        if ((int32_T)info_t < 0) {
          if ((int32_T)info_t == -1010) {
            emlrtErrorWithMessageIdR2018a(&e_st, &cb_emlrtRTEI, "MATLAB:nomem",
                                          "MATLAB:nomem", 0);
          } else {
            emlrtErrorWithMessageIdR2018a(
                &e_st, &db_emlrtRTEI, "Coder:toolbox:LAPACKCallErrorInfo",
                "Coder:toolbox:LAPACKCallErrorInfo", 5, 4, 14, &b_fname[0], 12,
                (int32_T)info_t);
          }
        }
        info = (int32_T)info_t;
      } else {
        c_st.site = &nf_emlrtRSI;
        minnm = muIntScalarMin_sint32(b_i, n);
        i = V->size[0] * V->size[1];
        V->size[0] = A->size[1];
        V->size[1] = minnm;
        emxEnsureCapacity_creal_T(&c_st, V, i, &cg_emlrtRTEI);
        V_data = V->data;
        d_st.site = &uf_emlrtRSI;
        if (minnm > 2147483646) {
          e_st.site = &o_emlrtRSI;
          check_forloop_overflow_error(&e_st);
        }
        overflow = (A->size[1] > 2147483646);
        for (k = 0; k < minnm; k++) {
          d_st.site = &vf_emlrtRSI;
          if (overflow) {
            e_st.site = &o_emlrtRSI;
            check_forloop_overflow_error(&e_st);
          }
          for (c_i = 0; c_i < n; c_i++) {
            V_data[c_i + V->size[0] * k].re = Vt_data[k + Vt->size[0] * c_i].re;
            V_data[c_i + V->size[0] * k].im =
                -Vt_data[k + Vt->size[0] * c_i].im;
          }
        }
      }
      if (info > 0) {
        emlrtErrorWithMessageIdR2018a(&b_st, &bb_emlrtRTEI,
                                      "Coder:MATLAB:svd_NoConvergence",
                                      "Coder:MATLAB:svd_NoConvergence", 0);
      }
      absx = muDoubleScalarAbs(S_data[0]);
      if (muDoubleScalarIsInf(absx) || muDoubleScalarIsNaN(absx)) {
        absx = rtNaN;
      } else if (absx < 4.4501477170144028E-308) {
        absx = 4.94065645841247E-324;
      } else {
        frexp(absx, &exponent);
        absx = ldexp(1.0, exponent - 53);
      }
      absx *= (real_T)A->size[0];
      i = 0;
      exitg1 = false;
      while ((!exitg1) && (i <= S->size[0] - 1)) {
        if (muDoubleScalarIsInf(S_data[i]) || muDoubleScalarIsNaN(S_data[i])) {
          absx = 1.7976931348623157E+308;
          exitg1 = true;
        } else {
          i++;
        }
      }
      minnm = 0;
      st.site = &hf_emlrtRSI;
      if (A->size[1] > 2147483646) {
        b_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }
      i = 0;
      while ((i <= n - 1) && (S_data[i] > absx)) {
        minnm++;
        i++;
      }
      if (minnm > 0) {
        st.site = &if_emlrtRSI;
        if (minnm > 2147483646) {
          b_st.site = &o_emlrtRSI;
          check_forloop_overflow_error(&b_st);
        }
        for (k = 0; k < minnm; k++) {
          st.site = &jf_emlrtRSI;
          if (n >= 1) {
            creal_T a;
            b_st.site = &wf_emlrtRSI;
            c_st.site = &xf_emlrtRSI;
            a.re = 1.0 / S_data[k];
            a.im = 0.0;
            info_t = (ptrdiff_t)n;
            incx_t = (ptrdiff_t)1;
            zscal(&info_t, (real_T *)&a, (real_T *)&V_data[k * n], &incx_t);
          }
        }
        st.site = &kf_emlrtRSI;
        b_st.site = &yf_emlrtRSI;
        c_st.site = &ag_emlrtRSI;
        TRANSB1 = 'C';
        TRANSA1 = 'N';
        info_t = (ptrdiff_t)A->size[1];
        incx_t = (ptrdiff_t)A->size[0];
        k_t = (ptrdiff_t)minnm;
        lda_t = (ptrdiff_t)A->size[1];
        ldb_t = (ptrdiff_t)A->size[0];
        ldc_t = (ptrdiff_t)A->size[1];
        zgemm(&TRANSA1, &TRANSB1, &info_t, &incx_t, &k_t, (real_T *)&dc1,
              (real_T *)&V_data[0], &lda_t, (real_T *)&U_data[0], &ldb_t,
              (real_T *)&dc, (real_T *)&X_data[0], &ldc_t);
      }
    }
  }
  emxFree_real_T(sp, &superb);
  emxFree_real_T(sp, &S);
  emxFree_creal_T(sp, &b_A);
  emxFree_creal_T(sp, &Vt);
  emxFree_creal_T(sp, &U);
  emxFree_creal_T(sp, &V);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (pinv.c) */
