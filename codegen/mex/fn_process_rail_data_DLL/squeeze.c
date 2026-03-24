/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * squeeze.c
 *
 * Code generation for function 'squeeze'
 *
 */

/* Include files */
#include "squeeze.h"
#include "fn_process_rail_data_DLL_data.h"
#include "fn_process_rail_data_DLL_emxutil.h"
#include "fn_process_rail_data_DLL_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRTEInfo eb_emlrtRTEI = {
    88,                  /* lineNo */
    23,                  /* colNo */
    "reshapeSizeChecks", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\reshapeSizeChecks.m" /* pName */
};

static emlrtRTEInfo vg_emlrtRTEI = {
    38,        /* lineNo */
    1,         /* colNo */
    "squeeze", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\elmat\\squeeze.m" /* pName
                                                                          */
};

/* Function Definitions */
void b_squeeze(const emlrtStack *sp, const emxArray_creal_T *a)
{
  emlrtStack st;
  int32_T n;
  int32_T nx;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &ve_emlrtRSI;
  nx = a->size[0] * a->size[1];
  n = a->size[0];
  if (a->size[1] > a->size[0]) {
    n = a->size[1];
  }
  nx = muIntScalarMax_sint32(nx, n);
  if (a->size[0] > nx) {
    emlrtErrorWithMessageIdR2018a(&st, &m_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if (a->size[1] > nx) {
    emlrtErrorWithMessageIdR2018a(&st, &m_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
}

void squeeze(const emlrtStack *sp, const emxArray_creal_T *a,
             emxArray_creal_T *b)
{
  emlrtStack st;
  const creal_T *a_data;
  creal_T *b_data;
  int32_T szb[2];
  int32_T i;
  int32_T j;
  int32_T loop_ub;
  int32_T nx;
  st.prev = sp;
  st.tls = sp->tls;
  a_data = a->data;
  szb[0] = 1;
  szb[1] = a->size[1];
  if (a->size[2] != 1) {
    j = 0;
    if (a->size[1] != 1) {
      j = 1;
      szb[0] = a->size[1];
    }
    if (a->size[2] != 1) {
      szb[j] = a->size[2];
    }
  }
  st.site = &ve_emlrtRSI;
  nx = a->size[1] * a->size[2];
  j = 1;
  if (a->size[1] > 1) {
    j = a->size[1];
  }
  if (a->size[2] > j) {
    j = a->size[2];
  }
  j = muIntScalarMax_sint32(nx, j);
  if (szb[0] > j) {
    emlrtErrorWithMessageIdR2018a(&st, &m_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if (szb[1] > j) {
    emlrtErrorWithMessageIdR2018a(&st, &m_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  loop_ub = szb[0] * szb[1];
  if (loop_ub != nx) {
    emlrtErrorWithMessageIdR2018a(
        &st, &eb_emlrtRTEI, "Coder:MATLAB:getReshapeDims_notSameNumel",
        "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }
  j = b->size[0] * b->size[1];
  b->size[0] = szb[0];
  b->size[1] = szb[1];
  emxEnsureCapacity_creal_T(sp, b, j, &vg_emlrtRTEI);
  b_data = b->data;
  for (i = 0; i < loop_ub; i++) {
    b_data[i] = a_data[i];
  }
}

/* End of code generation (squeeze.c) */
