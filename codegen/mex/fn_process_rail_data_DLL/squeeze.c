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
static emlrtRTEInfo if_emlrtRTEI = {
    38,        /* lineNo */
    1,         /* colNo */
    "squeeze", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\elmat\\squeeze.m" /* pName
                                                                          */
};

/* Function Definitions */
void b_squeeze(const emlrtStack *sp, const emxArray_real_T *a)
{
  emlrtStack st;
  int32_T n;
  int32_T nx;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &cf_emlrtRSI;
  nx = a->size[1];
  n = 1;
  if (a->size[1] > 1) {
    n = a->size[1];
  }
  if (a->size[1] > muIntScalarMax_sint32(nx, n)) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
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
  int32_T i;
  int32_T n;
  int32_T nx;
  int32_T szb_idx_0;
  st.prev = sp;
  st.tls = sp->tls;
  a_data = a->data;
  szb_idx_0 = 1;
  if (a->size[2] != 1) {
    szb_idx_0 = a->size[2];
  }
  st.site = &cf_emlrtRSI;
  nx = a->size[2];
  n = 1;
  if (a->size[2] > 1) {
    n = a->size[2];
  }
  if (szb_idx_0 > muIntScalarMax_sint32(nx, n)) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if (szb_idx_0 != a->size[2]) {
    emlrtErrorWithMessageIdR2018a(
        &st, &d_emlrtRTEI, "Coder:MATLAB:getReshapeDims_notSameNumel",
        "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }
  nx = b->size[0] * b->size[1];
  b->size[0] = szb_idx_0;
  b->size[1] = 1;
  emxEnsureCapacity_creal_T(sp, b, nx, &if_emlrtRTEI);
  b_data = b->data;
  for (i = 0; i < szb_idx_0; i++) {
    b_data[i] = a_data[i];
  }
}

/* End of code generation (squeeze.c) */
