/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * angle.c
 *
 * Code generation for function 'angle'
 *
 */

/* Include files */
#include "angle.h"
#include "eml_int_forloop_overflow_check.h"
#include "fn_process_rail_data_DLL_data.h"
#include "fn_process_rail_data_DLL_emxutil.h"
#include "fn_process_rail_data_DLL_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include "omp.h"

/* Variable Definitions */
static emlrtRSInfo vg_emlrtRSI = {
    9,       /* lineNo */
    "angle", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\elfun\\angle.m" /* pathName
                                                                        */
};

/* Function Definitions */
void angle(const emlrtStack *sp, const emxArray_creal_T *x, emxArray_real_T *y)
{
  jmp_buf *volatile emlrtJBStack;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  const creal_T *x_data;
  real_T *y_data;
  int32_T angle_numThreads;
  int32_T i;
  int32_T k;
  int32_T nx;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  x_data = x->data;
  st.site = &vg_emlrtRSI;
  nx = x->size[0] * x->size[1];
  i = y->size[0] * y->size[1];
  y->size[0] = x->size[0];
  y->size[1] = x->size[1];
  emxEnsureCapacity_real_T(&st, y, i, &he_emlrtRTEI);
  y_data = y->data;
  b_st.site = &lc_emlrtRSI;
  if (nx > 2147483646) {
    c_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  if (nx < 2000) {
    for (k = 0; k < nx; k++) {
      y_data[k] = muDoubleScalarAtan2(x_data[k].im, x_data[k].re);
    }
  } else {
    emlrtEnterParallelRegion(&st, omp_in_parallel());
    emlrtPushJmpBuf(&st, &emlrtJBStack);
    angle_numThreads = emlrtAllocRegionTLSs(
        st.tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(angle_numThreads)

    for (k = 0; k < nx; k++) {
      y_data[k] = muDoubleScalarAtan2(x_data[k].im, x_data[k].re);
    }
    emlrtPopJmpBuf(&st, &emlrtJBStack);
    emlrtExitParallelRegion(&st, omp_in_parallel());
  }
}

/* End of code generation (angle.c) */
