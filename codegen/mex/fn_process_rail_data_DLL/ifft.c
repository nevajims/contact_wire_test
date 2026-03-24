/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * ifft.c
 *
 * Code generation for function 'ifft'
 *
 */

/* Include files */
#include "ifft.h"
#include "fn_process_rail_data_DLL_data.h"
#include "fn_process_rail_data_DLL_emxutil.h"
#include "fn_process_rail_data_DLL_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo ai_emlrtRSI = {
    83,     /* lineNo */
    "ifft", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\datafun\\ifft.m" /* pathName
                                                                         */
};

static emlrtRTEInfo fb_emlrtRTEI = {
    72,     /* lineNo */
    31,     /* colNo */
    "ifft", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\datafun\\ifft.m" /* pName
                                                                         */
};

static emlrtRTEInfo gb_emlrtRTEI = {
    68,     /* lineNo */
    31,     /* colNo */
    "ifft", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\datafun\\ifft.m" /* pName
                                                                         */
};

static emlrtRTEInfo hb_emlrtRTEI = {
    56,     /* lineNo */
    27,     /* colNo */
    "ifft", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\datafun\\ifft.m" /* pName
                                                                         */
};

static emlrtRTEInfo wg_emlrtRTEI = {
    83,     /* lineNo */
    1,      /* colNo */
    "ifft", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\datafun\\ifft.m" /* pName
                                                                         */
};

static emlrtRTEInfo xg_emlrtRTEI = {
    32,                   /* lineNo */
    44,                   /* colNo */
    "MATLABFFTWCallback", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "fft\\MATLABFFTWCallback.m" /* pName */
};

/* Function Definitions */
void ifft(const emlrtStack *sp, const emxArray_creal_T *x, real_T varargin_1,
          emxArray_creal_T *y)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  const creal_T *x_data;
  creal_T *y_data;
  int32_T i;
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
  x_data = x->data;
  if (x->size[0] == 1) {
    emlrtErrorWithMessageIdR2018a(sp, &hb_emlrtRTEI,
                                  "Coder:toolbox:autoDimIncompatibility",
                                  "Coder:toolbox:autoDimIncompatibility", 0);
  }
  if (!(varargin_1 == muDoubleScalarFloor(varargin_1))) {
    emlrtErrorWithMessageIdR2018a(sp, &gb_emlrtRTEI,
                                  "MATLAB:fftfcn:lengthNotNonNegInt",
                                  "MATLAB:fftfcn:lengthNotNonNegInt", 0);
  }
  if (!(varargin_1 <= 2.147483647E+9)) {
    emlrtErrorWithMessageIdR2018a(sp, &fb_emlrtRTEI, "MATLAB:pmaxsize",
                                  "MATLAB:pmaxsize", 0);
  }
  st.site = &ai_emlrtRSI;
  if ((x->size[0] == 0) || (x->size[1] == 0) || ((int32_T)varargin_1 == 0)) {
    int32_T loop_ub;
    loop_ub = y->size[0] * y->size[1];
    y->size[0] = (int32_T)varargin_1;
    y->size[1] = x->size[1];
    emxEnsureCapacity_creal_T(&st, y, loop_ub, &wg_emlrtRTEI);
    y_data = y->data;
    loop_ub = (int32_T)varargin_1 * x->size[1];
    for (i = 0; i < loop_ub; i++) {
      y_data[i].re = 0.0;
      y_data[i].im = 0.0;
    }
  } else {
    int32_T loop_ub;
    b_st.site = &eb_emlrtRSI;
    c_st.site = &fb_emlrtRSI;
    d_st.site = &gb_emlrtRSI;
    e_st.site = &hb_emlrtRSI;
    emlrtFFTWSetNumThreads(8);
    loop_ub = y->size[0] * y->size[1];
    y->size[0] = (int32_T)varargin_1;
    y->size[1] = x->size[1];
    emxEnsureCapacity_creal_T(&e_st, y, loop_ub, &xg_emlrtRTEI);
    y_data = y->data;
    emlrtFFTW_1D_C2C((real_T *)&x_data[0], (real_T *)&y_data[0], 1,
                     (int32_T)varargin_1, x->size[0], x->size[1], 1);
  }
}

/* End of code generation (ifft.c) */
