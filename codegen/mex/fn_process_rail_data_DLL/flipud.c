/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * flipud.c
 *
 * Code generation for function 'flipud'
 *
 */

/* Include files */
#include "flipud.h"
#include "fn_process_rail_data_DLL_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void flipud(emxArray_real_T *x)
{
  real_T *x_data;
  int32_T i;
  int32_T m;
  int32_T md2;
  x_data = x->data;
  m = x->size[0] - 1;
  md2 = x->size[0] >> 1;
  for (i = 0; i < md2; i++) {
    real_T xtmp;
    int32_T b_i;
    xtmp = x_data[i];
    b_i = m - i;
    x_data[i] = x_data[b_i];
    x_data[b_i] = xtmp;
  }
}

/* End of code generation (flipud.c) */
