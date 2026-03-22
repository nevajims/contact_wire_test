/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * pchip.h
 *
 * Code generation for function 'pchip'
 *
 */

#pragma once

/* Include files */
#include "fn_process_rail_data_DLL_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void pchip(const emlrtStack *sp, const emxArray_real_T *x,
           const emxArray_creal_T *y, emxArray_real_T *v_breaks,
           emxArray_creal_T *v_coefs);

/* End of code generation (pchip.h) */
