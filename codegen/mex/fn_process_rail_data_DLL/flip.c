/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * flip.c
 *
 * Code generation for function 'flip'
 *
 */

/* Include files */
#include "flip.h"
#include "fn_process_rail_data_DLL_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void flip(emxArray_creal_T *x)
{
  creal_T *x_data;
  int32_T j;
  int32_T k;
  x_data = x->data;
  if ((x->size[0] != 0) && (x->size[1] != 0) && (x->size[0] > 1)) {
    int32_T i;
    int32_T n;
    int32_T nd2;
    n = x->size[0] - 1;
    nd2 = x->size[0] >> 1;
    i = x->size[1];
    for (j = 0; j < i; j++) {
      int32_T offset;
      offset = j * x->size[0];
      for (k = 0; k < nd2; k++) {
        real_T tmp_im;
        real_T tmp_re;
        int32_T i1;
        int32_T tmp_re_tmp;
        tmp_re_tmp = offset + k;
        tmp_re = x_data[tmp_re_tmp].re;
        tmp_im = x_data[tmp_re_tmp].im;
        i1 = (offset + n) - k;
        x_data[tmp_re_tmp] = x_data[i1];
        x_data[i1].re = tmp_re;
        x_data[i1].im = tmp_im;
      }
    }
  }
}

/* End of code generation (flip.c) */
