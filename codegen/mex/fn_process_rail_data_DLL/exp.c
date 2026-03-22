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

/* Function Definitions */
void b_exp(creal_T *x)
{
  if (x->re == 0.0) {
    real_T r;
    r = x->im;
    x->re = muDoubleScalarCos(r);
    x->im = muDoubleScalarSin(r);
  } else if (x->im == 0.0) {
    x->re = muDoubleScalarExp(x->re);
    x->im = 0.0;
  } else if (muDoubleScalarIsInf(x->im) && muDoubleScalarIsInf(x->re) &&
             (x->re < 0.0)) {
    x->re = 0.0;
    x->im = 0.0;
  } else {
    real_T d;
    real_T r;
    r = muDoubleScalarExp(x->re / 2.0);
    d = x->im;
    x->re = r * (r * muDoubleScalarCos(d));
    x->im = r * (r * muDoubleScalarSin(d));
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
