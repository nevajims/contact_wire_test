//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: _coder_fn_process_rail_data_DLL_api.h
//
// MATLAB Coder version            : 25.1
// C/C++ source code generated on  : 24-Mar-2026 22:30:21
//

#ifndef _CODER_FN_PROCESS_RAIL_DATA_DLL_API_H
#define _CODER_FN_PROCESS_RAIL_DATA_DLL_API_H

// Include Files
#include "fn_process_rail_data_DLL_spec.h"
#include "coder_array_mex.h"
#include "emlrt.h"
#include "mex.h"
#include "tmwtypes.h"
#include <algorithm>
#include <cstring>

// Variable Declarations
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

// Function Declarations
void fn_process_rail_data_DLL(
    coder::array<real_T, 1U> *raw_time, coder::array<real_T, 2U> *raw_time_data,
    coder::array<int64_T, 1U> *raw_tx, coder::array<int64_T, 1U> *raw_rx,
    coder::array<real_T, 2U> *array_row_pos,
    coder::array<int64_T, 2U> *array_trans_pos,
    coder::array<int64_T, 2U> *array_trans_row,
    coder::array<real_T, 2U> *array_trans_pos_orientations, real_T array_delay,
    coder::array<int64_T, 2U> *array_trans_node_list,
    coder::array<real_T, 3U> *disperse_freq,
    coder::array<real_T, 3U> *disperse_vph,
    coder::array<real_T, 3U> *disperse_vgr,
    coder::array<real_T, 3U> *disperse_waveno,
    coder::array<creal_T, 3U> *disperse_ms_x,
    coder::array<creal_T, 3U> *disperse_ms_y,
    coder::array<creal_T, 3U> *disperse_ms_z,
    coder::array<real_T, 2U> *opts_ms_matrix_modes_to_use,
    real_T opts_freq_filter_on, real_T opts_freq_filter,
    real_T opts_freq_filter_bandwidth, real_T opts_raw_data_zero_dead_time,
    real_T opts_raw_data_ignore_pulse_echo, real_T opts_ms_matrix_bidi_calc,
    real_T opts_ms_matrix_apply_as_time_shift,
    real_T opts_ms_matrix_time_step_size, real_T opts_ms_matrix_allow_neg_amps,
    coder::array<real_T, 2U> *opts_ms_matrix_calc_freqs,
    real_T opts_dispersion_compensation,
    coder::array<real_T, 2U> *opts_manual_warps,
    coder::array<real_T, 1U> *proc_tx_mode,
    coder::array<real_T, 1U> *proc_rx_mode,
    coder::array<real_T, 1U> *proc_tx_dir,
    coder::array<real_T, 1U> *proc_rx_dir, coder::array<real_T, 1U> *proc_dist,
    coder::array<creal_T, 2U> *proc_dist_data);

void fn_process_rail_data_DLL_api(const mxArray *const prhs[30], int32_T nlhs,
                                  const mxArray *plhs[6]);

void fn_process_rail_data_DLL_atexit();

void fn_process_rail_data_DLL_initialize();

void fn_process_rail_data_DLL_terminate();

void fn_process_rail_data_DLL_xil_shutdown();

void fn_process_rail_data_DLL_xil_terminate();

#endif
//
// File trailer for _coder_fn_process_rail_data_DLL_api.h
//
// [EOF]
//
