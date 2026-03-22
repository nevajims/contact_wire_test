/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * interp1.h
 *
 * Code generation for function 'interp1'
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
real_T b_interp1(const emlrtStack *sp, const emxArray_real_T *varargin_1,
                 const emxArray_real_T *varargin_2, real_T varargin_3);

void c_interp1(const emlrtStack *sp, const emxArray_real_T *varargin_1,
               const emxArray_creal_T *varargin_2, real_T varargin_3,
               emxArray_creal_T *Vq);

void d_interp1(const emlrtStack *sp, const emxArray_real_T *varargin_1,
               const emxArray_real_T *varargin_2,
               const emxArray_real_T *varargin_3, emxArray_real_T *Vq);

void e_interp1(const emlrtStack *sp, const emxArray_real_T *varargin_1,
               const emxArray_creal_T *varargin_2,
               const emxArray_real_T *varargin_3, emxArray_creal_T *Vq);

void interp1(const emlrtStack *sp, const emxArray_real_T *varargin_1,
             const emxArray_creal_T *varargin_2, real_T varargin_3,
             emxArray_creal_T *Vq);

/* End of code generation (interp1.h) */
