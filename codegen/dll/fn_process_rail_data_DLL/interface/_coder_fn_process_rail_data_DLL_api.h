/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_fn_process_rail_data_DLL_api.h
 *
 * MATLAB Coder version            : 25.1
 * C/C++ source code generated on  : 12-Mar-2026 17:25:15
 */

#ifndef _CODER_FN_PROCESS_RAIL_DATA_DLL_API_H
#define _CODER_FN_PROCESS_RAIL_DATA_DLL_API_H

/* Include Files */
#include "emlrt.h"
#include "mex.h"
#include "tmwtypes.h"
#include <string.h>

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void fn_process_rail_data_DLL(real_T b_time[2048], real_T time_data[294912],
                              int64_T tx[144], int64_T rx[144],
                              real_T row_pos[3], int64_T trans_pos[12],
                              int64_T trans_row[12],
                              real_T trans_pos_orientations[36], real_T delay,
                              int64_T trans_node_list[4], real_T tx_mode[32],
                              real_T rx_mode[32], real_T tx_dir[32],
                              real_T rx_dir[32], real_T dist[3158],
                              real_T dist_data[101056]);

void fn_process_rail_data_DLL_api(const mxArray *const prhs[10], int32_T nlhs,
                                  const mxArray *plhs[6]);

void fn_process_rail_data_DLL_atexit(void);

void fn_process_rail_data_DLL_initialize(void);

void fn_process_rail_data_DLL_terminate(void);

void fn_process_rail_data_DLL_xil_shutdown(void);

void fn_process_rail_data_DLL_xil_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for _coder_fn_process_rail_data_DLL_api.h
 *
 * [EOF]
 */
