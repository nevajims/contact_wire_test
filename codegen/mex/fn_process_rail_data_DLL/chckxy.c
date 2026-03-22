/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * chckxy.c
 *
 * Code generation for function 'chckxy'
 *
 */

/* Include files */
#include "chckxy.h"
#include "fn_process_rail_data_DLL_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Function Definitions */
boolean_T isFiniteAndStrictlyIncreasing(const emxArray_real_T *x)
{
  const real_T *x_data;
  boolean_T p;
  x_data = x->data;
  if ((x->size[0] >= 1) && ((!muDoubleScalarIsInf(x_data[0])) &&
                            (!muDoubleScalarIsNaN(x_data[0])))) {
    p = true;
  } else {
    p = false;
  }
  if (p) {
    int32_T k;
    boolean_T exitg1;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= x->size[0] - 2)) {
      if (!(x_data[k] < x_data[k + 1])) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  if ((!p) || muDoubleScalarIsInf(x_data[x->size[0] - 1])) {
    p = false;
  }
  return p;
}

/* End of code generation (chckxy.c) */
