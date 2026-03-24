/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_fn_process_rail_data_DLL_api.c
 *
 * Code generation for function '_coder_fn_process_rail_data_DLL_api'
 *
 */

/* Include files */
#include "_coder_fn_process_rail_data_DLL_api.h"
#include "fn_process_rail_data_DLL.h"
#include "fn_process_rail_data_DLL_data.h"
#include "fn_process_rail_data_DLL_emxutil.h"
#include "fn_process_rail_data_DLL_types.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRTEInfo qh_emlrtRTEI = {
    1,                                     /* lineNo */
    1,                                     /* colNo */
    "_coder_fn_process_rail_data_DLL_api", /* fName */
    ""                                     /* pName */
};

/* Function Declarations */
static void ab_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                emxArray_real_T *ret);

static const mxArray *b_emlrt_marshallOut(const emlrtStack *sp,
                                          const emxArray_creal_T *u);

static void bb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                emxArray_creal_T *ret);

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier, emxArray_real_T *y);

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y);

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier, emxArray_real_T *y);

static const mxArray *emlrt_marshallOut(emxArray_real_T *u);

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y);

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier, emxArray_int64_T *y);

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_int64_T *y);

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier, emxArray_real_T *y);

static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y);

static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier, emxArray_int64_T *y);

static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_int64_T *y);

static real_T m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                 const char_T *identifier);

static real_T n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId);

static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier, emxArray_real_T *y);

static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y);

static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier, emxArray_creal_T *y);

static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_creal_T *y);

static void t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_real_T *ret);

static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_real_T *ret);

static void v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_int64_T *ret);

static void w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_real_T *ret);

static void x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_int64_T *ret);

static real_T y_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

/* Function Definitions */
static void ab_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                emxArray_real_T *ret)
{
  static const int32_T dims[3] = {-1, 1, -1};
  int32_T iv[3];
  int32_T i;
  boolean_T bv[3] = {true, false, true};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 3U,
                            (const void *)&dims[0], &bv[0], &iv[0]);
  ret->allocatedSize = iv[0] * iv[1] * iv[2];
  i = ret->size[0] * ret->size[1] * ret->size[2];
  ret->size[0] = iv[0];
  ret->size[1] = iv[1];
  ret->size[2] = iv[2];
  emxEnsureCapacity_real_T(sp, ret, i, (emlrtRTEInfo *)NULL);
  ret->data = (real_T *)emlrtMxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static const mxArray *b_emlrt_marshallOut(const emlrtStack *sp,
                                          const emxArray_creal_T *u)
{
  const mxArray *m;
  const mxArray *y;
  const creal_T *u_data;
  int32_T iv[2];
  u_data = u->data;
  y = NULL;
  iv[0] = u->size[0];
  iv[1] = u->size[1];
  m = emlrtCreateNumericArray(2, &iv[0], mxDOUBLE_CLASS, mxCOMPLEX);
  emlrtExportNumericArrayR2013b((emlrtConstCTX)sp, m, (const void *)&u_data[0],
                                8);
  emlrtAssign(&y, m);
  return y;
}

static void bb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                emxArray_creal_T *ret)
{
  static const int32_T dims[3] = {-1, -1, -1};
  creal_T *ret_data;
  int32_T iv[3];
  int32_T i;
  boolean_T bv[3] = {true, true, true};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", true, 3U,
                            (const void *)&dims[0], &bv[0], &iv[0]);
  i = ret->size[0] * ret->size[1] * ret->size[2];
  ret->size[0] = iv[0];
  ret->size[1] = iv[1];
  ret->size[2] = iv[2];
  emxEnsureCapacity_creal_T(sp, ret, i, (emlrtRTEInfo *)NULL);
  ret_data = ret->data;
  emlrtImportArrayR2015b((emlrtConstCTX)sp, src, &ret_data[0], 8, true);
  emlrtDestroyArray(&src);
}

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  d_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId, y);
  emlrtDestroyArray(&nullptr);
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y)
{
  t_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  f_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId, y);
  emlrtDestroyArray(&nullptr);
}

static const mxArray *emlrt_marshallOut(emxArray_real_T *u)
{
  static const int32_T i = 0;
  const mxArray *m;
  const mxArray *y;
  real_T *u_data;
  u_data = u->data;
  y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, &u_data[0]);
  emlrtSetDimensions((mxArray *)m, &u->size[0], 1);
  u->canFreeData = false;
  emlrtAssign(&y, m);
  return y;
}

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y)
{
  u_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier, emxArray_int64_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  h_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId, y);
  emlrtDestroyArray(&nullptr);
}

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_int64_T *y)
{
  v_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  j_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId, y);
  emlrtDestroyArray(&nullptr);
}

static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y)
{
  w_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier, emxArray_int64_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  l_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId, y);
  emlrtDestroyArray(&nullptr);
}

static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_int64_T *y)
{
  x_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                 const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  real_T y;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = n_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId);
  emlrtDestroyArray(&nullptr);
  return y;
}

static real_T n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = y_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  p_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId, y);
  emlrtDestroyArray(&nullptr);
}

static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y)
{
  ab_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier, emxArray_creal_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  r_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId, y);
  emlrtDestroyArray(&nullptr);
}

static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_creal_T *y)
{
  bb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_real_T *ret)
{
  static const int32_T dims = -1;
  int32_T i;
  int32_T i1;
  boolean_T b = true;
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 1U,
                            (const void *)&dims, &b, &i);
  ret->allocatedSize = i;
  i1 = ret->size[0];
  ret->size[0] = i;
  emxEnsureCapacity_real_T(sp, ret, i1, (emlrtRTEInfo *)NULL);
  ret->data = (real_T *)emlrtMxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_real_T *ret)
{
  static const int32_T dims[2] = {-1, -1};
  int32_T iv[2];
  int32_T i;
  boolean_T bv[2] = {true, true};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 2U,
                            (const void *)&dims[0], &bv[0], &iv[0]);
  ret->allocatedSize = iv[0] * iv[1];
  i = ret->size[0] * ret->size[1];
  ret->size[0] = iv[0];
  ret->size[1] = iv[1];
  emxEnsureCapacity_real_T(sp, ret, i, (emlrtRTEInfo *)NULL);
  ret->data = (real_T *)emlrtMxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static void v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_int64_T *ret)
{
  static const int32_T dims = -1;
  int32_T i;
  int32_T i1;
  boolean_T b = true;
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "int64", false, 1U,
                            (const void *)&dims, &b, &i);
  ret->allocatedSize = i;
  i1 = ret->size[0];
  ret->size[0] = i;
  emxEnsureCapacity_int64_T(sp, ret, i1, (emlrtRTEInfo *)NULL);
  ret->data = (int64_T *)emlrtMxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static void w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_real_T *ret)
{
  static const int32_T dims[2] = {1, -1};
  int32_T iv[2];
  int32_T i;
  boolean_T bv[2] = {false, true};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 2U,
                            (const void *)&dims[0], &bv[0], &iv[0]);
  ret->allocatedSize = iv[0] * iv[1];
  i = ret->size[0] * ret->size[1];
  ret->size[0] = iv[0];
  ret->size[1] = iv[1];
  emxEnsureCapacity_real_T(sp, ret, i, (emlrtRTEInfo *)NULL);
  ret->data = (real_T *)emlrtMxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static void x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_int64_T *ret)
{
  static const int32_T dims[2] = {1, -1};
  int32_T iv[2];
  int32_T i;
  boolean_T bv[2] = {false, true};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "int64", false, 2U,
                            (const void *)&dims[0], &bv[0], &iv[0]);
  ret->allocatedSize = iv[0] * iv[1];
  i = ret->size[0] * ret->size[1];
  ret->size[0] = iv[0];
  ret->size[1] = iv[1];
  emxEnsureCapacity_int64_T(sp, ret, i, (emlrtRTEInfo *)NULL);
  ret->data = (int64_T *)emlrtMxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static real_T y_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims = 0;
  real_T ret;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 0U,
                          (const void *)&dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

void fn_process_rail_data_DLL_api(const mxArray *const prhs[30], int32_T nlhs,
                                  const mxArray *plhs[6])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  emxArray_creal_T *disperse_ms_x;
  emxArray_creal_T *disperse_ms_y;
  emxArray_creal_T *disperse_ms_z;
  emxArray_creal_T *proc_dist_data;
  emxArray_int64_T *array_trans_node_list;
  emxArray_int64_T *array_trans_pos;
  emxArray_int64_T *array_trans_row;
  emxArray_int64_T *raw_rx;
  emxArray_int64_T *raw_tx;
  emxArray_real_T *array_row_pos;
  emxArray_real_T *array_trans_pos_orientations;
  emxArray_real_T *disperse_freq;
  emxArray_real_T *disperse_vgr;
  emxArray_real_T *disperse_vph;
  emxArray_real_T *disperse_waveno;
  emxArray_real_T *opts_manual_warps;
  emxArray_real_T *opts_ms_matrix_calc_freqs;
  emxArray_real_T *opts_ms_matrix_modes_to_use;
  emxArray_real_T *proc_dist;
  emxArray_real_T *proc_rx_dir;
  emxArray_real_T *proc_rx_mode;
  emxArray_real_T *proc_tx_dir;
  emxArray_real_T *proc_tx_mode;
  emxArray_real_T *raw_time;
  emxArray_real_T *raw_time_data;
  const mxArray *prhs_copy_idx_1;
  const mxArray *prhs_copy_idx_2;
  const mxArray *prhs_copy_idx_27;
  const mxArray *prhs_copy_idx_3;
  real_T array_delay;
  real_T c_opts_ms_matrix_apply_as_time_;
  real_T opts_dispersion_compensation;
  real_T opts_freq_filter;
  real_T opts_freq_filter_bandwidth;
  real_T opts_freq_filter_on;
  real_T opts_ms_matrix_allow_neg_amps;
  real_T opts_ms_matrix_bidi_calc;
  real_T opts_ms_matrix_time_step_size;
  real_T opts_raw_data_ignore_pulse_echo;
  real_T opts_raw_data_zero_dead_time;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  prhs_copy_idx_1 = emlrtProtectR2012b(prhs[1], 1, false, -1);
  prhs_copy_idx_2 = emlrtProtectR2012b(prhs[2], 2, false, -1);
  prhs_copy_idx_3 = emlrtProtectR2012b(prhs[3], 3, false, -1);
  prhs_copy_idx_27 = emlrtProtectR2012b(prhs[27], 27, false, -1);
  /* Marshall function inputs */
  emxInit_real_T(&st, &raw_time, 1, &qh_emlrtRTEI);
  raw_time->canFreeData = false;
  c_emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "raw_time", raw_time);
  emxInit_real_T(&st, &raw_time_data, 2, &qh_emlrtRTEI);
  raw_time_data->canFreeData = false;
  e_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_1), "raw_time_data",
                     raw_time_data);
  emxInit_int64_T(&st, &raw_tx, 1, &qh_emlrtRTEI);
  raw_tx->canFreeData = false;
  g_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_2), "raw_tx", raw_tx);
  emxInit_int64_T(&st, &raw_rx, 1, &qh_emlrtRTEI);
  raw_rx->canFreeData = false;
  g_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_3), "raw_rx", raw_rx);
  emxInit_real_T(&st, &array_row_pos, 2, &qh_emlrtRTEI);
  array_row_pos->canFreeData = false;
  i_emlrt_marshallIn(&st, emlrtAlias(prhs[4]), "array_row_pos", array_row_pos);
  emxInit_int64_T(&st, &array_trans_pos, 2, &qh_emlrtRTEI);
  array_trans_pos->canFreeData = false;
  k_emlrt_marshallIn(&st, emlrtAlias(prhs[5]), "array_trans_pos",
                     array_trans_pos);
  emxInit_int64_T(&st, &array_trans_row, 2, &qh_emlrtRTEI);
  array_trans_row->canFreeData = false;
  k_emlrt_marshallIn(&st, emlrtAlias(prhs[6]), "array_trans_row",
                     array_trans_row);
  emxInit_real_T(&st, &array_trans_pos_orientations, 2, &qh_emlrtRTEI);
  array_trans_pos_orientations->canFreeData = false;
  e_emlrt_marshallIn(&st, emlrtAlias(prhs[7]), "array_trans_pos_orientations",
                     array_trans_pos_orientations);
  array_delay = m_emlrt_marshallIn(&st, emlrtAliasP(prhs[8]), "array_delay");
  emxInit_int64_T(&st, &array_trans_node_list, 2, &qh_emlrtRTEI);
  array_trans_node_list->canFreeData = false;
  k_emlrt_marshallIn(&st, emlrtAlias(prhs[9]), "array_trans_node_list",
                     array_trans_node_list);
  emxInit_real_T(&st, &disperse_freq, 3, &qh_emlrtRTEI);
  disperse_freq->canFreeData = false;
  o_emlrt_marshallIn(&st, emlrtAlias(prhs[10]), "disperse_freq", disperse_freq);
  emxInit_real_T(&st, &disperse_vph, 3, &qh_emlrtRTEI);
  disperse_vph->canFreeData = false;
  o_emlrt_marshallIn(&st, emlrtAlias(prhs[11]), "disperse_vph", disperse_vph);
  emxInit_real_T(&st, &disperse_vgr, 3, &qh_emlrtRTEI);
  disperse_vgr->canFreeData = false;
  o_emlrt_marshallIn(&st, emlrtAlias(prhs[12]), "disperse_vgr", disperse_vgr);
  emxInit_real_T(&st, &disperse_waveno, 3, &qh_emlrtRTEI);
  disperse_waveno->canFreeData = false;
  o_emlrt_marshallIn(&st, emlrtAlias(prhs[13]), "disperse_waveno",
                     disperse_waveno);
  emxInit_creal_T(&st, &disperse_ms_x, 3, &qh_emlrtRTEI);
  q_emlrt_marshallIn(&st, emlrtAliasP(prhs[14]), "disperse_ms_x",
                     disperse_ms_x);
  emxInit_creal_T(&st, &disperse_ms_y, 3, &qh_emlrtRTEI);
  q_emlrt_marshallIn(&st, emlrtAliasP(prhs[15]), "disperse_ms_y",
                     disperse_ms_y);
  emxInit_creal_T(&st, &disperse_ms_z, 3, &qh_emlrtRTEI);
  q_emlrt_marshallIn(&st, emlrtAliasP(prhs[16]), "disperse_ms_z",
                     disperse_ms_z);
  emxInit_real_T(&st, &opts_ms_matrix_modes_to_use, 2, &qh_emlrtRTEI);
  opts_ms_matrix_modes_to_use->canFreeData = false;
  i_emlrt_marshallIn(&st, emlrtAlias(prhs[17]), "opts_ms_matrix_modes_to_use",
                     opts_ms_matrix_modes_to_use);
  opts_freq_filter_on =
      m_emlrt_marshallIn(&st, emlrtAliasP(prhs[18]), "opts_freq_filter_on");
  opts_freq_filter =
      m_emlrt_marshallIn(&st, emlrtAliasP(prhs[19]), "opts_freq_filter");
  opts_freq_filter_bandwidth = m_emlrt_marshallIn(&st, emlrtAliasP(prhs[20]),
                                                  "opts_freq_filter_bandwidth");
  opts_raw_data_zero_dead_time = m_emlrt_marshallIn(
      &st, emlrtAliasP(prhs[21]), "opts_raw_data_zero_dead_time");
  opts_raw_data_ignore_pulse_echo = m_emlrt_marshallIn(
      &st, emlrtAliasP(prhs[22]), "opts_raw_data_ignore_pulse_echo");
  opts_ms_matrix_bidi_calc = m_emlrt_marshallIn(&st, emlrtAliasP(prhs[23]),
                                                "opts_ms_matrix_bidi_calc");
  c_opts_ms_matrix_apply_as_time_ = m_emlrt_marshallIn(
      &st, emlrtAliasP(prhs[24]), "opts_ms_matrix_apply_as_time_shift");
  opts_ms_matrix_time_step_size = m_emlrt_marshallIn(
      &st, emlrtAliasP(prhs[25]), "opts_ms_matrix_time_step_size");
  opts_ms_matrix_allow_neg_amps = m_emlrt_marshallIn(
      &st, emlrtAliasP(prhs[26]), "opts_ms_matrix_allow_neg_amps");
  emxInit_real_T(&st, &opts_ms_matrix_calc_freqs, 2, &qh_emlrtRTEI);
  opts_ms_matrix_calc_freqs->canFreeData = false;
  i_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_27),
                     "opts_ms_matrix_calc_freqs", opts_ms_matrix_calc_freqs);
  opts_dispersion_compensation = m_emlrt_marshallIn(
      &st, emlrtAliasP(prhs[28]), "opts_dispersion_compensation");
  emxInit_real_T(&st, &opts_manual_warps, 2, &qh_emlrtRTEI);
  opts_manual_warps->canFreeData = false;
  i_emlrt_marshallIn(&st, emlrtAlias(prhs[29]), "opts_manual_warps",
                     opts_manual_warps);
  /* Invoke the target function */
  emxInit_real_T(&st, &proc_tx_mode, 1, &qh_emlrtRTEI);
  emxInit_real_T(&st, &proc_rx_mode, 1, &qh_emlrtRTEI);
  emxInit_real_T(&st, &proc_tx_dir, 1, &qh_emlrtRTEI);
  emxInit_real_T(&st, &proc_rx_dir, 1, &qh_emlrtRTEI);
  emxInit_real_T(&st, &proc_dist, 1, &qh_emlrtRTEI);
  emxInit_creal_T(&st, &proc_dist_data, 2, &qh_emlrtRTEI);
  fn_process_rail_data_DLL(
      &st, raw_time, raw_time_data, raw_tx, raw_rx, array_row_pos,
      array_trans_pos, array_trans_row, array_trans_pos_orientations,
      array_delay, array_trans_node_list, disperse_freq, disperse_vph,
      disperse_vgr, disperse_waveno, disperse_ms_x, disperse_ms_y,
      disperse_ms_z, opts_ms_matrix_modes_to_use, opts_freq_filter_on,
      opts_freq_filter, opts_freq_filter_bandwidth,
      opts_raw_data_zero_dead_time, opts_raw_data_ignore_pulse_echo,
      opts_ms_matrix_bidi_calc, c_opts_ms_matrix_apply_as_time_,
      opts_ms_matrix_time_step_size, opts_ms_matrix_allow_neg_amps,
      opts_ms_matrix_calc_freqs, opts_dispersion_compensation,
      opts_manual_warps, proc_tx_mode, proc_rx_mode, proc_tx_dir, proc_rx_dir,
      proc_dist, proc_dist_data);
  emxFree_real_T(&st, &opts_manual_warps);
  emxFree_real_T(&st, &opts_ms_matrix_calc_freqs);
  emxFree_real_T(&st, &opts_ms_matrix_modes_to_use);
  emxFree_creal_T(&st, &disperse_ms_z);
  emxFree_creal_T(&st, &disperse_ms_y);
  emxFree_creal_T(&st, &disperse_ms_x);
  emxFree_real_T(&st, &disperse_waveno);
  emxFree_real_T(&st, &disperse_vgr);
  emxFree_real_T(&st, &disperse_vph);
  emxFree_real_T(&st, &disperse_freq);
  emxFree_int64_T(&st, &array_trans_node_list);
  emxFree_real_T(&st, &array_trans_pos_orientations);
  emxFree_int64_T(&st, &array_trans_row);
  emxFree_int64_T(&st, &array_trans_pos);
  emxFree_real_T(&st, &array_row_pos);
  emxFree_int64_T(&st, &raw_rx);
  emxFree_int64_T(&st, &raw_tx);
  emxFree_real_T(&st, &raw_time_data);
  emxFree_real_T(&st, &raw_time);
  /* Marshall function outputs */
  proc_tx_mode->canFreeData = false;
  plhs[0] = emlrt_marshallOut(proc_tx_mode);
  emxFree_real_T(&st, &proc_tx_mode);
  if (nlhs > 1) {
    proc_rx_mode->canFreeData = false;
    plhs[1] = emlrt_marshallOut(proc_rx_mode);
  }
  emxFree_real_T(&st, &proc_rx_mode);
  if (nlhs > 2) {
    proc_tx_dir->canFreeData = false;
    plhs[2] = emlrt_marshallOut(proc_tx_dir);
  }
  emxFree_real_T(&st, &proc_tx_dir);
  if (nlhs > 3) {
    proc_rx_dir->canFreeData = false;
    plhs[3] = emlrt_marshallOut(proc_rx_dir);
  }
  emxFree_real_T(&st, &proc_rx_dir);
  if (nlhs > 4) {
    proc_dist->canFreeData = false;
    plhs[4] = emlrt_marshallOut(proc_dist);
  }
  emxFree_real_T(&st, &proc_dist);
  if (nlhs > 5) {
    plhs[5] = b_emlrt_marshallOut(&st, proc_dist_data);
  }
  emxFree_creal_T(&st, &proc_dist_data);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_fn_process_rail_data_DLL_api.c) */
