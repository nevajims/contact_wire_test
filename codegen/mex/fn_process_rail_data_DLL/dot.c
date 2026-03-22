/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * dot.c
 *
 * Code generation for function 'dot'
 *
 */

/* Include files */
#include "dot.h"
#include "eml_int_forloop_overflow_check.h"
#include "fn_process_rail_data_DLL_data.h"
#include "fn_process_rail_data_DLL_emxutil.h"
#include "fn_process_rail_data_DLL_types.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo df_emlrtRSI = {
    25,    /* lineNo */
    "dot", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\specfun\\dot.m" /* pathName
                                                                        */
};

static emlrtRSInfo ef_emlrtRSI = {
    104,     /* lineNo */
    "vdotp", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\specfun\\dot.m" /* pathName
                                                                        */
};

static emlrtRSInfo ff_emlrtRSI = {
    89,     /* lineNo */
    "vdot", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\specfun\\dot.m" /* pathName
                                                                        */
};

static emlrtRSInfo gf_emlrtRSI = {
    40,      /* lineNo */
    "xdotc", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xdotc."
    "m" /* pathName */
};

static emlrtRSInfo hf_emlrtRSI = {
    15,      /* lineNo */
    "xdotc", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xdotc.m" /* pathName */
};

static emlrtRSInfo if_emlrtRSI = {
    32,      /* lineNo */
    "xdotx", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xdotx.m" /* pathName */
};

static emlrtRTEInfo bb_emlrtRTEI = {
    12,    /* lineNo */
    23,    /* colNo */
    "dot", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\specfun\\dot.m" /* pName
                                                                        */
};

static emlrtRTEInfo jf_emlrtRTEI = {
    23,    /* lineNo */
    13,    /* colNo */
    "dot", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\specfun\\dot.m" /* pName
                                                                        */
};

/* Function Definitions */
void dot(const emlrtStack *sp, const emxArray_creal_T *a,
         const emxArray_real_T *b, emxArray_creal_T *c)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack st;
  const creal_T *a_data;
  creal_T *c_data;
  const real_T *b_data;
  real_T c_im;
  real_T c_re;
  int32_T ixlast;
  int32_T k;
  uint32_T varargin_1[2];
  uint32_T varargin_2[2];
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
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  b_data = b->data;
  a_data = a->data;
  varargin_1[0] = (uint32_T)a->size[0];
  varargin_2[0] = 1U;
  varargin_1[1] = 1U;
  varargin_2[1] = (uint32_T)b->size[1];
  p = true;
  ixlast = 0;
  exitg1 = false;
  while ((!exitg1) && (ixlast < 2)) {
    if ((int32_T)varargin_1[ixlast] != (int32_T)varargin_2[ixlast]) {
      p = false;
      exitg1 = true;
    } else {
      ixlast++;
    }
  }
  if ((!p) && (a->size[0] != b->size[1])) {
    emlrtErrorWithMessageIdR2018a(sp, &bb_emlrtRTEI,
                                  "MATLAB:dot:InputSizeMismatch",
                                  "MATLAB:dot:InputSizeMismatch", 0);
  }
  st.site = &df_emlrtRSI;
  b_st.site = &ef_emlrtRSI;
  c_st.site = &ff_emlrtRSI;
  d_st.site = &gf_emlrtRSI;
  e_st.site = &hf_emlrtRSI;
  c_re = 0.0;
  c_im = 0.0;
  if (a->size[0] >= 1) {
    ixlast = a->size[0];
    f_st.site = &if_emlrtRSI;
    if (a->size[0] > 2147483646) {
      g_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(&g_st);
    }
    for (k = 0; k < ixlast; k++) {
      real_T d;
      d = b_data[k];
      c_re += a_data[k].re * d;
      c_im += a_data[k].im * -d;
    }
  }
  ixlast = c->size[0] * c->size[1];
  c->size[0] = 1;
  c->size[1] = 1;
  emxEnsureCapacity_creal_T(sp, c, ixlast, &jf_emlrtRTEI);
  c_data = c->data;
  c_data[0].re = c_re;
  c_data[0].im = c_im;
}

/* End of code generation (dot.c) */
