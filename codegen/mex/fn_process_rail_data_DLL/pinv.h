/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * pinv.h
 *
 * Code generation for function 'pinv'
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
void eml_pinv(const emlrtStack *sp, const emxArray_creal_T *A,
              emxArray_creal_T *X);

/* End of code generation (pinv.h) */
