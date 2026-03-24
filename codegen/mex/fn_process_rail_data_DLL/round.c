/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * round.c
 *
 * Code generation for function 'round'
 *
 */

/* Include files */
#include "round.h"
#include "eml_int_forloop_overflow_check.h"
#include "fn_process_rail_data_DLL_data.h"
#include "fn_process_rail_data_DLL_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include "omp.h"

/* Variable Definitions */
static emlrtRSInfo xh_emlrtRSI = {
    16,      /* lineNo */
    "round", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\elfun\\round.m" /* pathName
                                                                        */
};

/* Function Definitions */
void b_round(const emlrtStack *sp, emxArray_real_T *x)
{
  jmp_buf *volatile emlrtJBStack;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T *x_data;
  int32_T b_round_numThreads;
  int32_T k;
  int32_T nx;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  x_data = x->data;
  st.site = &xh_emlrtRSI;
  nx = x->size[0];
  b_st.site = &lb_emlrtRSI;
  if (x->size[0] > 2147483646) {
    c_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  if (nx < 2000) {
    for (k = 0; k < nx; k++) {
      x_data[k] = muDoubleScalarRound(x_data[k]);
    }
  } else {
    emlrtEnterParallelRegion(&st, omp_in_parallel());
    emlrtPushJmpBuf(&st, &emlrtJBStack);
    b_round_numThreads = emlrtAllocRegionTLSs(
        st.tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(b_round_numThreads)

    for (k = 0; k < nx; k++) {
      x_data[k] = muDoubleScalarRound(x_data[k]);
    }
    emlrtPopJmpBuf(&st, &emlrtJBStack);
    emlrtExitParallelRegion(&st, omp_in_parallel());
  }
}

/* End of code generation (round.c) */
