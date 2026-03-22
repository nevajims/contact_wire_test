/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * anynan.c
 *
 * Code generation for function 'anynan'
 *
 */

/* Include files */
#include "anynan.h"
#include "eml_int_forloop_overflow_check.h"
#include "fn_process_rail_data_DLL_data.h"
#include "fn_process_rail_data_DLL_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo be_emlrtRSI = {
    16,       /* lineNo */
    "anynan", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\elmat\\anynan.m" /* pathName
                                                                         */
};

/* Function Definitions */
boolean_T anynan(const emlrtStack *sp, const emxArray_real_T *x)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  const real_T *x_data;
  int32_T k;
  int32_T nx;
  boolean_T tf;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  x_data = x->data;
  st.site = &be_emlrtRSI;
  b_st.site = &ce_emlrtRSI;
  nx = x->size[0];
  tf = false;
  c_st.site = &de_emlrtRSI;
  if (x->size[0] > 2147483646) {
    d_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }
  for (k = 0; k < nx; k++) {
    if (tf || muDoubleScalarIsNaN(x_data[k])) {
      tf = true;
    }
  }
  return tf;
}

boolean_T b_anynan(const emlrtStack *sp, const emxArray_real_T *x)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  const real_T *x_data;
  int32_T k;
  int32_T nx;
  boolean_T tf;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  x_data = x->data;
  st.site = &be_emlrtRSI;
  b_st.site = &ce_emlrtRSI;
  nx = x->size[1];
  tf = false;
  c_st.site = &de_emlrtRSI;
  if (x->size[1] > 2147483646) {
    d_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }
  for (k = 0; k < nx; k++) {
    if (tf || muDoubleScalarIsNaN(x_data[k])) {
      tf = true;
    }
  }
  return tf;
}

/* End of code generation (anynan.c) */
