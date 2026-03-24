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
#include "fn_process_rail_data_DLL_types.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRTEInfo ab_emlrtRTEI = {
    12,    /* lineNo */
    23,    /* colNo */
    "dot", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\specfun\\dot.m" /* pName
                                                                        */
};

/* Function Definitions */
creal_T dot(const emlrtStack *sp, const creal_T a[3], const emxArray_real_T *b)
{
  creal_T c;
  const real_T *b_data;
  real_T d;
  int32_T k;
  uint32_T varargin_2[2];
  boolean_T exitg1;
  boolean_T p;
  b_data = b->data;
  varargin_2[0] = 1U;
  varargin_2[1] = (uint32_T)b->size[1];
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (-2 * k + 3 != (int32_T)varargin_2[k]) {
      p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }
  if ((!p) && (b->size[1] != 3)) {
    emlrtErrorWithMessageIdR2018a(sp, &ab_emlrtRTEI,
                                  "MATLAB:dot:InputSizeMismatch",
                                  "MATLAB:dot:InputSizeMismatch", 0);
  }
  d = b_data[0];
  c.re = a[0].re * d;
  c.im = a[0].im * -d;
  d = b_data[1];
  c.re += a[1].re * d;
  c.im += a[1].im * -d;
  d = b_data[2];
  c.re += a[2].re * d;
  c.im += a[2].im * -d;
  return c;
}

/* End of code generation (dot.c) */
