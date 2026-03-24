//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: _coder_fn_process_rail_data_DLL_api.cpp
//
// MATLAB Coder version            : 25.1
// C/C++ source code generated on  : 24-Mar-2026 22:30:21
//

// Include Files
#include "_coder_fn_process_rail_data_DLL_api.h"
#include "_coder_fn_process_rail_data_DLL_mex.h"
#include "coder_array_mex.h"

// Variable Definitions
emlrtCTX emlrtRootTLSGlobal{nullptr};

emlrtContext emlrtContextGlobal{
    true,                                                 // bFirstTime
    false,                                                // bInitialized
    131674U,                                              // fVersionInfo
    nullptr,                                              // fErrorFunction
    "fn_process_rail_data_DLL",                           // fFunctionName
    nullptr,                                              // fRTCallStack
    false,                                                // bDebugMode
    {2045744189U, 2170104910U, 2743257031U, 4284093946U}, // fSigWrd
    nullptr                                               // fSigMem
};

// Function Declarations
static void b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<real_T, 1U> &ret);

static void b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<int64_T, 1U> &ret);

static void b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                               const char_T *identifier,
                               coder::array<real_T, 2U> &y);

static void b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               coder::array<real_T, 2U> &y);

static void b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<int64_T, 2U> &ret);

static real_T b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

static void b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<real_T, 3U> &ret);

static void b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<creal_T, 3U> &ret);

static void c_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<real_T, 2U> &ret);

static void d_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<real_T, 2U> &ret);

static void emlrtExitTimeCleanupDtorFcn(const void *r);

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                             const char_T *identifier,
                             coder::array<real_T, 1U> &y);

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<real_T, 1U> &y);

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                             const char_T *identifier,
                             coder::array<real_T, 2U> &y);

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<real_T, 2U> &y);

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                             const char_T *identifier,
                             coder::array<int64_T, 1U> &y);

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<int64_T, 1U> &y);

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                             const char_T *identifier,
                             coder::array<int64_T, 2U> &y);

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<int64_T, 2U> &y);

static real_T emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                               const char_T *identifier);

static real_T emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId);

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                             const char_T *identifier,
                             coder::array<real_T, 3U> &y);

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<real_T, 3U> &y);

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                             const char_T *identifier,
                             coder::array<creal_T, 3U> &y);

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<creal_T, 3U> &y);

static const mxArray *emlrt_marshallOut(coder::array<real_T, 1U> &u);

static const mxArray *emlrt_marshallOut(const emlrtStack &sp,
                                        const coder::array<creal_T, 2U> &u);

// Function Definitions
//
// Arguments    : const emlrtStack &sp
//                const mxArray *b_nullptr
//                const char_T *identifier
//                coder::array<real_T, 2U> &y
// Return Type  : void
//
static void b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                               const char_T *identifier,
                               coder::array<real_T, 2U> &y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(b_nullptr), &thisId, y);
  emlrtDestroyArray(&b_nullptr);
}

//
// Arguments    : const emlrtStack &sp
//                const mxArray *src
//                const emlrtMsgIdentifier *msgId
//                coder::array<real_T, 1U> &ret
// Return Type  : void
//
static void b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<real_T, 1U> &ret)
{
  static const int32_T dims{-1};
  int32_T i;
  boolean_T b{true};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)&sp, msgId, src, "double", false, 1U,
                            (const void *)&dims, &b, &i);
  ret.prealloc(i);
  ret.set_size(i);
  ret.set(static_cast<real_T *>(emlrtMxGetData(src)), ret.size(0));
  emlrtDestroyArray(&src);
}

//
// Arguments    : const emlrtStack &sp
//                const mxArray *src
//                const emlrtMsgIdentifier *msgId
// Return Type  : real_T
//
static real_T b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims{0};
  real_T ret;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)&sp, msgId, src, "double", false, 0U,
                          (const void *)&dims);
  ret = *static_cast<real_T *>(emlrtMxGetData(src));
  emlrtDestroyArray(&src);
  return ret;
}

//
// Arguments    : const emlrtStack &sp
//                const mxArray *src
//                const emlrtMsgIdentifier *msgId
//                coder::array<int64_T, 2U> &ret
// Return Type  : void
//
static void b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<int64_T, 2U> &ret)
{
  static const int32_T dims[2]{1, -1};
  int32_T iv[2];
  boolean_T bv[2]{false, true};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)&sp, msgId, src, "int64", false, 2U,
                            (const void *)&dims[0], &bv[0], &iv[0]);
  ret.prealloc(iv[0] * iv[1]);
  ret.set_size(iv[0], iv[1]);
  ret.set(static_cast<int64_T *>(emlrtMxGetData(src)), ret.size(0),
          ret.size(1));
  emlrtDestroyArray(&src);
}

//
// Arguments    : const emlrtStack &sp
//                const mxArray *u
//                const emlrtMsgIdentifier *parentId
//                coder::array<real_T, 2U> &y
// Return Type  : void
//
static void b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               coder::array<real_T, 2U> &y)
{
  d_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

//
// Arguments    : const emlrtStack &sp
//                const mxArray *src
//                const emlrtMsgIdentifier *msgId
//                coder::array<int64_T, 1U> &ret
// Return Type  : void
//
static void b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<int64_T, 1U> &ret)
{
  static const int32_T dims{-1};
  int32_T i;
  boolean_T b{true};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)&sp, msgId, src, "int64", false, 1U,
                            (const void *)&dims, &b, &i);
  ret.prealloc(i);
  ret.set_size(i);
  ret.set(static_cast<int64_T *>(emlrtMxGetData(src)), ret.size(0));
  emlrtDestroyArray(&src);
}

//
// Arguments    : const emlrtStack &sp
//                const mxArray *src
//                const emlrtMsgIdentifier *msgId
//                coder::array<creal_T, 3U> &ret
// Return Type  : void
//
static void b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<creal_T, 3U> &ret)
{
  static const int32_T dims[3]{-1, -1, -1};
  int32_T iv[3];
  boolean_T bv[3]{true, true, true};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)&sp, msgId, src, "double", true, 3U,
                            (const void *)&dims[0], &bv[0], &iv[0]);
  ret.set_size(iv[0], iv[1], iv[2]);
  emlrtImportArrayR2015b((emlrtConstCTX)&sp, src, &ret[0], 8, true);
  emlrtDestroyArray(&src);
}

//
// Arguments    : const emlrtStack &sp
//                const mxArray *src
//                const emlrtMsgIdentifier *msgId
//                coder::array<real_T, 3U> &ret
// Return Type  : void
//
static void b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<real_T, 3U> &ret)
{
  static const int32_T dims[3]{-1, 1, -1};
  int32_T iv[3];
  boolean_T bv[3]{true, false, true};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)&sp, msgId, src, "double", false, 3U,
                            (const void *)&dims[0], &bv[0], &iv[0]);
  ret.prealloc(iv[0] * iv[1] * iv[2]);
  ret.set_size(iv[0], iv[1], iv[2]);
  ret.set(static_cast<real_T *>(emlrtMxGetData(src)), ret.size(0), ret.size(1),
          ret.size(2));
  emlrtDestroyArray(&src);
}

//
// Arguments    : const emlrtStack &sp
//                const mxArray *src
//                const emlrtMsgIdentifier *msgId
//                coder::array<real_T, 2U> &ret
// Return Type  : void
//
static void c_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<real_T, 2U> &ret)
{
  static const int32_T dims[2]{-1, -1};
  int32_T iv[2];
  boolean_T bv[2]{true, true};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)&sp, msgId, src, "double", false, 2U,
                            (const void *)&dims[0], &bv[0], &iv[0]);
  ret.prealloc(iv[0] * iv[1]);
  ret.set_size(iv[0], iv[1]);
  ret.set(static_cast<real_T *>(emlrtMxGetData(src)), ret.size(0), ret.size(1));
  emlrtDestroyArray(&src);
}

//
// Arguments    : const emlrtStack &sp
//                const mxArray *src
//                const emlrtMsgIdentifier *msgId
//                coder::array<real_T, 2U> &ret
// Return Type  : void
//
static void d_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<real_T, 2U> &ret)
{
  static const int32_T dims[2]{1, -1};
  int32_T iv[2];
  boolean_T bv[2]{false, true};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)&sp, msgId, src, "double", false, 2U,
                            (const void *)&dims[0], &bv[0], &iv[0]);
  ret.prealloc(iv[0] * iv[1]);
  ret.set_size(iv[0], iv[1]);
  ret.set(static_cast<real_T *>(emlrtMxGetData(src)), ret.size(0), ret.size(1));
  emlrtDestroyArray(&src);
}

//
// Arguments    : const void *r
// Return Type  : void
//
static void emlrtExitTimeCleanupDtorFcn(const void *r)
{
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

//
// Arguments    : const emlrtStack &sp
//                const mxArray *u
//                const emlrtMsgIdentifier *parentId
//                coder::array<int64_T, 1U> &y
// Return Type  : void
//
static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<int64_T, 1U> &y)
{
  b_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

//
// Arguments    : const emlrtStack &sp
//                const mxArray *b_nullptr
//                const char_T *identifier
//                coder::array<int64_T, 1U> &y
// Return Type  : void
//
static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                             const char_T *identifier,
                             coder::array<int64_T, 1U> &y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  emlrt_marshallIn(sp, emlrtAlias(b_nullptr), &thisId, y);
  emlrtDestroyArray(&b_nullptr);
}

//
// Arguments    : const emlrtStack &sp
//                const mxArray *b_nullptr
//                const char_T *identifier
//                coder::array<int64_T, 2U> &y
// Return Type  : void
//
static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                             const char_T *identifier,
                             coder::array<int64_T, 2U> &y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  emlrt_marshallIn(sp, emlrtAlias(b_nullptr), &thisId, y);
  emlrtDestroyArray(&b_nullptr);
}

//
// Arguments    : const emlrtStack &sp
//                const mxArray *u
//                const emlrtMsgIdentifier *parentId
//                coder::array<int64_T, 2U> &y
// Return Type  : void
//
static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<int64_T, 2U> &y)
{
  b_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

//
// Arguments    : const emlrtStack &sp
//                const mxArray *u
//                const emlrtMsgIdentifier *parentId
//                coder::array<real_T, 2U> &y
// Return Type  : void
//
static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<real_T, 2U> &y)
{
  c_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

//
// Arguments    : const emlrtStack &sp
//                const mxArray *b_nullptr
//                const char_T *identifier
// Return Type  : real_T
//
static real_T emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                               const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  real_T y;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y = emlrt_marshallIn(sp, emlrtAlias(b_nullptr), &thisId);
  emlrtDestroyArray(&b_nullptr);
  return y;
}

//
// Arguments    : const emlrtStack &sp
//                const mxArray *u
//                const emlrtMsgIdentifier *parentId
// Return Type  : real_T
//
static real_T emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = b_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

//
// Arguments    : const emlrtStack &sp
//                const mxArray *b_nullptr
//                const char_T *identifier
//                coder::array<real_T, 2U> &y
// Return Type  : void
//
static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                             const char_T *identifier,
                             coder::array<real_T, 2U> &y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  emlrt_marshallIn(sp, emlrtAlias(b_nullptr), &thisId, y);
  emlrtDestroyArray(&b_nullptr);
}

//
// Arguments    : const emlrtStack &sp
//                const mxArray *b_nullptr
//                const char_T *identifier
//                coder::array<real_T, 3U> &y
// Return Type  : void
//
static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                             const char_T *identifier,
                             coder::array<real_T, 3U> &y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  emlrt_marshallIn(sp, emlrtAlias(b_nullptr), &thisId, y);
  emlrtDestroyArray(&b_nullptr);
}

//
// Arguments    : const emlrtStack &sp
//                const mxArray *u
//                const emlrtMsgIdentifier *parentId
//                coder::array<real_T, 3U> &y
// Return Type  : void
//
static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<real_T, 3U> &y)
{
  b_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

//
// Arguments    : const emlrtStack &sp
//                const mxArray *u
//                const emlrtMsgIdentifier *parentId
//                coder::array<real_T, 1U> &y
// Return Type  : void
//
static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<real_T, 1U> &y)
{
  b_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

//
// Arguments    : const emlrtStack &sp
//                const mxArray *b_nullptr
//                const char_T *identifier
//                coder::array<creal_T, 3U> &y
// Return Type  : void
//
static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                             const char_T *identifier,
                             coder::array<creal_T, 3U> &y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  emlrt_marshallIn(sp, emlrtAlias(b_nullptr), &thisId, y);
  emlrtDestroyArray(&b_nullptr);
}

//
// Arguments    : const emlrtStack &sp
//                const mxArray *u
//                const emlrtMsgIdentifier *parentId
//                coder::array<creal_T, 3U> &y
// Return Type  : void
//
static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<creal_T, 3U> &y)
{
  b_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

//
// Arguments    : const emlrtStack &sp
//                const mxArray *b_nullptr
//                const char_T *identifier
//                coder::array<real_T, 1U> &y
// Return Type  : void
//
static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                             const char_T *identifier,
                             coder::array<real_T, 1U> &y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  emlrt_marshallIn(sp, emlrtAlias(b_nullptr), &thisId, y);
  emlrtDestroyArray(&b_nullptr);
}

//
// Arguments    : coder::array<real_T, 1U> &u
// Return Type  : const mxArray *
//
static const mxArray *emlrt_marshallOut(coder::array<real_T, 1U> &u)
{
  static const int32_T i{0};
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateNumericArray(1, (const void *)&i, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, &u[0]);
  emlrtSetDimensions((mxArray *)m, u.size(), 1);
  u.set_owner(false);
  emlrtAssign(&y, m);
  return y;
}

//
// Arguments    : const emlrtStack &sp
//                const coder::array<creal_T, 2U> &u
// Return Type  : const mxArray *
//
static const mxArray *emlrt_marshallOut(const emlrtStack &sp,
                                        const coder::array<creal_T, 2U> &u)
{
  const mxArray *m;
  const mxArray *y;
  int32_T iv[2];
  y = nullptr;
  iv[0] = u.size(0);
  iv[1] = u.size(1);
  m = emlrtCreateNumericArray(2, &iv[0], mxDOUBLE_CLASS, mxCOMPLEX);
  emlrtExportNumericArrayR2013b((emlrtConstCTX)&sp, m, (const void *)&u[0], 8);
  emlrtAssign(&y, m);
  return y;
}

//
// Arguments    : const mxArray * const prhs[30]
//                int32_T nlhs
//                const mxArray *plhs[6]
// Return Type  : void
//
void fn_process_rail_data_DLL_api(const mxArray *const prhs[30], int32_T nlhs,
                                  const mxArray *plhs[6])
{
  coder::array<creal_T, 3U> disperse_ms_x;
  coder::array<creal_T, 3U> disperse_ms_y;
  coder::array<creal_T, 3U> disperse_ms_z;
  coder::array<creal_T, 2U> proc_dist_data;
  coder::array<int64_T, 2U> array_trans_node_list;
  coder::array<int64_T, 2U> array_trans_pos;
  coder::array<int64_T, 2U> array_trans_row;
  coder::array<int64_T, 1U> raw_rx;
  coder::array<int64_T, 1U> raw_tx;
  coder::array<real_T, 3U> disperse_freq;
  coder::array<real_T, 3U> disperse_vgr;
  coder::array<real_T, 3U> disperse_vph;
  coder::array<real_T, 3U> disperse_waveno;
  coder::array<real_T, 2U> array_row_pos;
  coder::array<real_T, 2U> array_trans_pos_orientations;
  coder::array<real_T, 2U> opts_manual_warps;
  coder::array<real_T, 2U> opts_ms_matrix_calc_freqs;
  coder::array<real_T, 2U> opts_ms_matrix_modes_to_use;
  coder::array<real_T, 2U> raw_time_data;
  coder::array<real_T, 1U> proc_dist;
  coder::array<real_T, 1U> proc_rx_dir;
  coder::array<real_T, 1U> proc_rx_mode;
  coder::array<real_T, 1U> proc_tx_dir;
  coder::array<real_T, 1U> proc_tx_mode;
  coder::array<real_T, 1U> raw_time;
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  const mxArray *prhs_copy_idx_1;
  const mxArray *prhs_copy_idx_2;
  const mxArray *prhs_copy_idx_27;
  const mxArray *prhs_copy_idx_3;
  real_T array_delay;
  real_T opts_dispersion_compensation;
  real_T opts_freq_filter;
  real_T opts_freq_filter_bandwidth;
  real_T opts_freq_filter_on;
  real_T opts_ms_matrix_allow_neg_amps;
  real_T opts_ms_matrix_apply_as_time_shift;
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
  // Marshall function inputs
  raw_time.set_owner(false);
  emlrt_marshallIn(st, emlrtAlias(prhs[0]), "raw_time", raw_time);
  raw_time_data.set_owner(false);
  emlrt_marshallIn(st, emlrtAlias(prhs_copy_idx_1), "raw_time_data",
                   raw_time_data);
  raw_tx.set_owner(false);
  emlrt_marshallIn(st, emlrtAlias(prhs_copy_idx_2), "raw_tx", raw_tx);
  raw_rx.set_owner(false);
  emlrt_marshallIn(st, emlrtAlias(prhs_copy_idx_3), "raw_rx", raw_rx);
  array_row_pos.set_owner(false);
  b_emlrt_marshallIn(st, emlrtAlias(prhs[4]), "array_row_pos", array_row_pos);
  array_trans_pos.set_owner(false);
  emlrt_marshallIn(st, emlrtAlias(prhs[5]), "array_trans_pos", array_trans_pos);
  array_trans_row.set_owner(false);
  emlrt_marshallIn(st, emlrtAlias(prhs[6]), "array_trans_row", array_trans_row);
  array_trans_pos_orientations.set_owner(false);
  emlrt_marshallIn(st, emlrtAlias(prhs[7]), "array_trans_pos_orientations",
                   array_trans_pos_orientations);
  array_delay = emlrt_marshallIn(st, emlrtAliasP(prhs[8]), "array_delay");
  array_trans_node_list.set_owner(false);
  emlrt_marshallIn(st, emlrtAlias(prhs[9]), "array_trans_node_list",
                   array_trans_node_list);
  disperse_freq.set_owner(false);
  emlrt_marshallIn(st, emlrtAlias(prhs[10]), "disperse_freq", disperse_freq);
  disperse_vph.set_owner(false);
  emlrt_marshallIn(st, emlrtAlias(prhs[11]), "disperse_vph", disperse_vph);
  disperse_vgr.set_owner(false);
  emlrt_marshallIn(st, emlrtAlias(prhs[12]), "disperse_vgr", disperse_vgr);
  disperse_waveno.set_owner(false);
  emlrt_marshallIn(st, emlrtAlias(prhs[13]), "disperse_waveno",
                   disperse_waveno);
  emlrt_marshallIn(st, emlrtAliasP(prhs[14]), "disperse_ms_x", disperse_ms_x);
  emlrt_marshallIn(st, emlrtAliasP(prhs[15]), "disperse_ms_y", disperse_ms_y);
  emlrt_marshallIn(st, emlrtAliasP(prhs[16]), "disperse_ms_z", disperse_ms_z);
  opts_ms_matrix_modes_to_use.set_owner(false);
  b_emlrt_marshallIn(st, emlrtAlias(prhs[17]), "opts_ms_matrix_modes_to_use",
                     opts_ms_matrix_modes_to_use);
  opts_freq_filter_on =
      emlrt_marshallIn(st, emlrtAliasP(prhs[18]), "opts_freq_filter_on");
  opts_freq_filter =
      emlrt_marshallIn(st, emlrtAliasP(prhs[19]), "opts_freq_filter");
  opts_freq_filter_bandwidth =
      emlrt_marshallIn(st, emlrtAliasP(prhs[20]), "opts_freq_filter_bandwidth");
  opts_raw_data_zero_dead_time = emlrt_marshallIn(
      st, emlrtAliasP(prhs[21]), "opts_raw_data_zero_dead_time");
  opts_raw_data_ignore_pulse_echo = emlrt_marshallIn(
      st, emlrtAliasP(prhs[22]), "opts_raw_data_ignore_pulse_echo");
  opts_ms_matrix_bidi_calc =
      emlrt_marshallIn(st, emlrtAliasP(prhs[23]), "opts_ms_matrix_bidi_calc");
  opts_ms_matrix_apply_as_time_shift = emlrt_marshallIn(
      st, emlrtAliasP(prhs[24]), "opts_ms_matrix_apply_as_time_shift");
  opts_ms_matrix_time_step_size = emlrt_marshallIn(
      st, emlrtAliasP(prhs[25]), "opts_ms_matrix_time_step_size");
  opts_ms_matrix_allow_neg_amps = emlrt_marshallIn(
      st, emlrtAliasP(prhs[26]), "opts_ms_matrix_allow_neg_amps");
  opts_ms_matrix_calc_freqs.set_owner(false);
  b_emlrt_marshallIn(st, emlrtAlias(prhs_copy_idx_27),
                     "opts_ms_matrix_calc_freqs", opts_ms_matrix_calc_freqs);
  opts_dispersion_compensation = emlrt_marshallIn(
      st, emlrtAliasP(prhs[28]), "opts_dispersion_compensation");
  opts_manual_warps.set_owner(false);
  b_emlrt_marshallIn(st, emlrtAlias(prhs[29]), "opts_manual_warps",
                     opts_manual_warps);
  // Invoke the target function
  fn_process_rail_data_DLL(
      raw_time, raw_time_data, raw_tx, raw_rx, array_row_pos, array_trans_pos,
      array_trans_row, array_trans_pos_orientations, array_delay,
      array_trans_node_list, disperse_freq, disperse_vph, disperse_vgr,
      disperse_waveno, disperse_ms_x, disperse_ms_y, disperse_ms_z,
      opts_ms_matrix_modes_to_use, opts_freq_filter_on, opts_freq_filter,
      opts_freq_filter_bandwidth, opts_raw_data_zero_dead_time,
      opts_raw_data_ignore_pulse_echo, opts_ms_matrix_bidi_calc,
      opts_ms_matrix_apply_as_time_shift, opts_ms_matrix_time_step_size,
      opts_ms_matrix_allow_neg_amps, opts_ms_matrix_calc_freqs,
      opts_dispersion_compensation, opts_manual_warps, proc_tx_mode,
      proc_rx_mode, proc_tx_dir, proc_rx_dir, proc_dist, proc_dist_data);
  // Marshall function outputs
  proc_tx_mode.set_owner(false);
  plhs[0] = emlrt_marshallOut(proc_tx_mode);
  if (nlhs > 1) {
    proc_rx_mode.set_owner(false);
    plhs[1] = emlrt_marshallOut(proc_rx_mode);
  }
  if (nlhs > 2) {
    proc_tx_dir.set_owner(false);
    plhs[2] = emlrt_marshallOut(proc_tx_dir);
  }
  if (nlhs > 3) {
    proc_rx_dir.set_owner(false);
    plhs[3] = emlrt_marshallOut(proc_rx_dir);
  }
  if (nlhs > 4) {
    proc_dist.set_owner(false);
    plhs[4] = emlrt_marshallOut(proc_dist);
  }
  if (nlhs > 5) {
    plhs[5] = emlrt_marshallOut(st, proc_dist_data);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

//
// Arguments    : void
// Return Type  : void
//
void fn_process_rail_data_DLL_atexit()
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtPushHeapReferenceStackR2021a(&st, false, nullptr,
                                    (void *)&emlrtExitTimeCleanupDtorFcn,
                                    nullptr, nullptr, nullptr);
  emlrtEnterRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  fn_process_rail_data_DLL_xil_terminate();
  fn_process_rail_data_DLL_xil_shutdown();
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

//
// Arguments    : void
// Return Type  : void
//
void fn_process_rail_data_DLL_initialize()
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, nullptr);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

//
// Arguments    : void
// Return Type  : void
//
void fn_process_rail_data_DLL_terminate()
{
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

//
// File trailer for _coder_fn_process_rail_data_DLL_api.cpp
//
// [EOF]
//
