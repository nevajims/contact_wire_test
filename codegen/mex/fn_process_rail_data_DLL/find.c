/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * find.c
 *
 * Code generation for function 'find'
 *
 */

/* Include files */
#include "find.h"
#include "eml_int_forloop_overflow_check.h"
#include "fn_process_rail_data_DLL_data.h"
#include "fn_process_rail_data_DLL_emxutil.h"
#include "fn_process_rail_data_DLL_types.h"
#include "indexShapeCheck.h"
#include "rt_nonfinite.h"
#include "warning.h"
#include "omp.h"

/* Variable Definitions */
static emlrtRSInfo t_emlrtRSI = {
    138,        /* lineNo */
    "eml_find", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" /* pathName
                                                                       */
};

static emlrtRSInfo u_emlrtRSI = {
    376,                  /* lineNo */
    "find_first_indices", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" /* pathName
                                                                       */
};

static emlrtRSInfo v_emlrtRSI = {
    396,                  /* lineNo */
    "find_first_indices", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" /* pathName
                                                                       */
};

static emlrtRSInfo wg_emlrtRSI = {
    152,        /* lineNo */
    "eml_find", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" /* pathName
                                                                       */
};

static emlrtRTEInfo e_emlrtRTEI = {
    386,                  /* lineNo */
    1,                    /* colNo */
    "find_first_indices", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" /* pName
                                                                       */
};

static emlrtRTEInfo ce_emlrtRTEI = {
    363,    /* lineNo */
    24,     /* colNo */
    "find", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" /* pName
                                                                       */
};

static emlrtRTEInfo de_emlrtRTEI = {
    138,    /* lineNo */
    9,      /* colNo */
    "find", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" /* pName
                                                                       */
};

static emlrtRTEInfo ke_emlrtRTEI = {
    358,    /* lineNo */
    24,     /* colNo */
    "find", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" /* pName
                                                                       */
};

/* Function Definitions */
void b_eml_find(const emlrtStack *sp, const emxArray_boolean_T *x,
                emxArray_int32_T *i)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T idx;
  int32_T ii;
  int32_T nx;
  int32_T *i_data;
  const boolean_T *x_data;
  boolean_T exitg1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  x_data = x->data;
  nx = x->size[1];
  st.site = &t_emlrtRSI;
  idx = 0;
  ii = i->size[0] * i->size[1];
  i->size[0] = 1;
  i->size[1] = x->size[1];
  emxEnsureCapacity_int32_T(&st, i, ii, &ke_emlrtRTEI);
  i_data = i->data;
  b_st.site = &u_emlrtRSI;
  if (x->size[1] > 2147483646) {
    c_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii <= nx - 1)) {
    if (x_data[ii]) {
      idx++;
      i_data[idx - 1] = ii + 1;
      if (idx >= nx) {
        exitg1 = true;
      } else {
        ii++;
      }
    } else {
      ii++;
    }
  }
  if (idx > x->size[1]) {
    emlrtErrorWithMessageIdR2018a(&st, &e_emlrtRTEI,
                                  "Coder:builtins:AssertionFailed",
                                  "Coder:builtins:AssertionFailed", 0);
  }
  if (x->size[1] == 1) {
    if (idx == 0) {
      i->size[0] = 1;
      i->size[1] = 0;
    }
  } else {
    ii = i->size[0] * i->size[1];
    if (idx < 1) {
      i->size[1] = 0;
    } else {
      i->size[1] = idx;
    }
    emxEnsureCapacity_int32_T(&st, i, ii, &de_emlrtRTEI);
  }
}

void binary_expand_op_2(const emlrtStack *sp, emxArray_int32_T *in1,
                        const emlrtRSInfo in2, const emxArray_int64_T *in3,
                        const emxArray_int64_T *in4)
{
  jmp_buf *volatile emlrtJBStack;
  emlrtStack st;
  emxArray_boolean_T *b_in3;
  const int64_T *in3_data;
  const int64_T *in4_data;
  int32_T binary_expand_op_2_numThreads;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  boolean_T *b_in3_data;
  st.prev = sp;
  st.tls = sp->tls;
  in4_data = in4->data;
  in3_data = in3->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_boolean_T(sp, &b_in3, 1, &xb_emlrtRTEI);
  if (in4->size[0] == 1) {
    loop_ub = in3->size[0];
  } else {
    loop_ub = in4->size[0];
  }
  stride_0_0 = b_in3->size[0];
  b_in3->size[0] = loop_ub;
  emxEnsureCapacity_boolean_T(sp, b_in3, stride_0_0, &xb_emlrtRTEI);
  b_in3_data = b_in3->data;
  stride_0_0 = (in3->size[0] != 1);
  stride_1_0 = (in4->size[0] != 1);
  if (loop_ub < 2000) {
    for (i = 0; i < loop_ub; i++) {
      b_in3_data[i] = (in3_data[i * stride_0_0] != in4_data[i * stride_1_0]);
    }
  } else {
    emlrtEnterParallelRegion((emlrtCTX)sp, omp_in_parallel());
    emlrtPushJmpBuf((emlrtCTX)sp, &emlrtJBStack);
    binary_expand_op_2_numThreads = emlrtAllocRegionTLSs(
        sp->tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(binary_expand_op_2_numThreads)

    for (i = 0; i < loop_ub; i++) {
      b_in3_data[i] = (in3_data[i * stride_0_0] != in4_data[i * stride_1_0]);
    }
    emlrtPopJmpBuf((emlrtCTX)sp, &emlrtJBStack);
    emlrtExitParallelRegion((emlrtCTX)sp, omp_in_parallel());
  }
  st.site = (emlrtRSInfo *)&in2;
  eml_find(&st, b_in3, in1);
  emxFree_boolean_T(sp, &b_in3);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

void c_eml_find(const emlrtStack *sp, const emxArray_boolean_T *x,
                emxArray_int32_T *i)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T idx;
  int32_T ii;
  int32_T nx;
  int32_T *i_data;
  const boolean_T *x_data;
  boolean_T exitg1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  x_data = x->data;
  nx = x->size[0] * x->size[1];
  st.site = &t_emlrtRSI;
  idx = 0;
  ii = i->size[0];
  i->size[0] = nx;
  emxEnsureCapacity_int32_T(&st, i, ii, &ce_emlrtRTEI);
  i_data = i->data;
  b_st.site = &u_emlrtRSI;
  if (nx > 2147483646) {
    c_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii <= nx - 1)) {
    if (x_data[ii]) {
      idx++;
      i_data[idx - 1] = ii + 1;
      if (idx >= nx) {
        exitg1 = true;
      } else {
        ii++;
      }
    } else {
      ii++;
    }
  }
  if (idx > nx) {
    emlrtErrorWithMessageIdR2018a(&st, &e_emlrtRTEI,
                                  "Coder:builtins:AssertionFailed",
                                  "Coder:builtins:AssertionFailed", 0);
  }
  if (nx == 1) {
    if (idx == 0) {
      i->size[0] = 0;
    }
  } else {
    int32_T iv[2];
    if (idx < 1) {
      idx = 0;
    }
    iv[0] = 1;
    iv[1] = idx;
    b_st.site = &v_emlrtRSI;
    indexShapeCheck(&b_st, i->size[0], iv);
    ii = i->size[0];
    i->size[0] = idx;
    emxEnsureCapacity_int32_T(&st, i, ii, &de_emlrtRTEI);
  }
  if ((x->size[0] == 1) && (i->size[0] != 1) && (x->size[1] >= 2)) {
    st.site = &wg_emlrtRSI;
    warning(&st);
  }
}

void eml_find(const emlrtStack *sp, const emxArray_boolean_T *x,
              emxArray_int32_T *i)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T idx;
  int32_T ii;
  int32_T nx;
  int32_T *i_data;
  const boolean_T *x_data;
  boolean_T exitg1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  x_data = x->data;
  nx = x->size[0];
  st.site = &t_emlrtRSI;
  idx = 0;
  ii = i->size[0];
  i->size[0] = x->size[0];
  emxEnsureCapacity_int32_T(&st, i, ii, &ce_emlrtRTEI);
  i_data = i->data;
  b_st.site = &u_emlrtRSI;
  if (x->size[0] > 2147483646) {
    c_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii <= nx - 1)) {
    if (x_data[ii]) {
      idx++;
      i_data[idx - 1] = ii + 1;
      if (idx >= nx) {
        exitg1 = true;
      } else {
        ii++;
      }
    } else {
      ii++;
    }
  }
  if (idx > x->size[0]) {
    emlrtErrorWithMessageIdR2018a(&st, &e_emlrtRTEI,
                                  "Coder:builtins:AssertionFailed",
                                  "Coder:builtins:AssertionFailed", 0);
  }
  if (x->size[0] == 1) {
    if (idx == 0) {
      i->size[0] = 0;
    }
  } else {
    int32_T iv[2];
    if (idx < 1) {
      idx = 0;
    }
    iv[0] = 1;
    iv[1] = idx;
    b_st.site = &v_emlrtRSI;
    indexShapeCheck(&b_st, i->size[0], iv);
    ii = i->size[0];
    i->size[0] = idx;
    emxEnsureCapacity_int32_T(&st, i, ii, &de_emlrtRTEI);
  }
}

/* End of code generation (find.c) */
