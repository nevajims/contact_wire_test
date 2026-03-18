/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * randn.c
 *
 * Code generation for function 'randn'
 *
 */

/* Include files */
#include "randn.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void randn(real_T r[101056])
{
  emlrtRandn(&r[0], 101056);
}

/* End of code generation (randn.c) */
