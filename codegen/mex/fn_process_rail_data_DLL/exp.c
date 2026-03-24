/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * exp.c
 *
 * Code generation for function 'exp'
 *
 */

/* Include files */
#include "exp.h"
#include "eml_int_forloop_overflow_check.h"
#include "fn_process_rail_data_DLL_data.h"
#include "fn_process_rail_data_DLL_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include "omp.h"

/* Variable Definitions */
static emlrtRSInfo kb_emlrtRSI =
    {
        10,    /* lineNo */
        "exp", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\elfun\\exp.m" /* pathName
                                                                          */
};

/* Function Definitions */
void b_exp(const emlrtStack *sp, emxArray_creal_T *x)
{
  jmp_buf *volatile emlrtJBStack;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  creal_T b_dc;
  creal_T *x_data;
  real_T d1;
  real_T r;
  int32_T b_exp_numThreads;
  int32_T k;
  int32_T nx;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  x_data = x->data;
  st.site = &kb_emlrtRSI;
  nx = x->size[0];
  b_st.site = &lb_emlrtRSI;
  if (x->size[0] > 2147483646) {
    c_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  if (nx < 2000) {
    for (k = 0; k < nx; k++) {
      b_dc = x_data[k];
      if (b_dc.re == 0.0) {
        real_T d;
        d = b_dc.im;
        b_dc.re = muDoubleScalarCos(d);
        b_dc.im = muDoubleScalarSin(d);
        x_data[k] = b_dc;
      } else if (b_dc.im == 0.0) {
        real_T d;
        d = b_dc.re;
        b_dc.re = muDoubleScalarExp(d);
        b_dc.im = 0.0;
        x_data[k] = b_dc;
      } else if (muDoubleScalarIsInf(b_dc.im) && muDoubleScalarIsInf(b_dc.re) &&
                 (b_dc.re < 0.0)) {
        x_data[k].re = 0.0;
        x_data[k].im = 0.0;
      } else {
        real_T d;
        r = muDoubleScalarExp(b_dc.re / 2.0);
        d = b_dc.im;
        b_dc.re = r * (r * muDoubleScalarCos(d));
        b_dc.im = r * (r * muDoubleScalarSin(d));
        x_data[k] = b_dc;
      }
    }
  } else {
    emlrtEnterParallelRegion(&st, omp_in_parallel());
    emlrtPushJmpBuf(&st, &emlrtJBStack);
    b_exp_numThreads = emlrtAllocRegionTLSs(
        st.tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(b_exp_numThreads) private(r, b_dc, d1)

    for (k = 0; k < nx; k++) {
      b_dc = x_data[k];
      if (b_dc.re == 0.0) {
        d1 = b_dc.im;
        b_dc.re = muDoubleScalarCos(d1);
        b_dc.im = muDoubleScalarSin(d1);
        x_data[k] = b_dc;
      } else if (b_dc.im == 0.0) {
        d1 = b_dc.re;
        b_dc.re = muDoubleScalarExp(d1);
        b_dc.im = 0.0;
        x_data[k] = b_dc;
      } else if (muDoubleScalarIsInf(b_dc.im) && muDoubleScalarIsInf(b_dc.re) &&
                 (b_dc.re < 0.0)) {
        b_dc.re = 0.0;
        b_dc.im = 0.0;
        x_data[k] = b_dc;
      } else {
        r = muDoubleScalarExp(b_dc.re / 2.0);
        d1 = b_dc.im;
        b_dc.re = r * (r * muDoubleScalarCos(d1));
        b_dc.im = r * (r * muDoubleScalarSin(d1));
        x_data[k] = b_dc;
      }
    }
    emlrtPopJmpBuf(&st, &emlrtJBStack);
    emlrtExitParallelRegion(&st, omp_in_parallel());
  }
}

void c_exp(const emlrtStack *sp, emxArray_real_T *x)
{
  jmp_buf *volatile emlrtJBStack;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T *x_data;
  int32_T c_exp_numThreads;
  int32_T k;
  int32_T nx;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  x_data = x->data;
  st.site = &kb_emlrtRSI;
  nx = x->size[0];
  b_st.site = &lb_emlrtRSI;
  if (x->size[0] > 2147483646) {
    c_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  if (nx < 2000) {
    for (k = 0; k < nx; k++) {
      x_data[k] = muDoubleScalarExp(x_data[k]);
    }
  } else {
    emlrtEnterParallelRegion(&st, omp_in_parallel());
    emlrtPushJmpBuf(&st, &emlrtJBStack);
    c_exp_numThreads = emlrtAllocRegionTLSs(
        st.tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(c_exp_numThreads)

    for (k = 0; k < nx; k++) {
      x_data[k] = muDoubleScalarExp(x_data[k]);
    }
    emlrtPopJmpBuf(&st, &emlrtJBStack);
    emlrtExitParallelRegion(&st, omp_in_parallel());
  }
}

/* End of code generation (exp.c) */
