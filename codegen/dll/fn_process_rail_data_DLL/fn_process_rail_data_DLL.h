//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: fn_process_rail_data_DLL.h
//
// MATLAB Coder version            : 25.1
// C/C++ source code generated on  : 24-Mar-2026 22:30:21
//

#ifndef FN_PROCESS_RAIL_DATA_DLL_H
#define FN_PROCESS_RAIL_DATA_DLL_H

// Include Files
#include "fn_process_rail_data_DLL_spec.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
FN_PROCESS_RAIL_DATA_DLL_DLL_EXPORT extern void fn_process_rail_data_DLL(
    const coder::array<double, 1U> &raw_time,
    coder::array<double, 2U> &raw_time_data,
    coder::array<long long, 1U> &raw_tx, coder::array<long long, 1U> &raw_rx,
    const coder::array<double, 2U> &array_row_pos,
    const coder::array<long long, 2U> &array_trans_pos,
    const coder::array<long long, 2U> &array_trans_row,
    const coder::array<double, 2U> &array_trans_pos_orientations,
    double array_delay,
    const coder::array<long long, 2U> &array_trans_node_list,
    const coder::array<double, 3U> &disperse_freq,
    const coder::array<double, 3U> &disperse_vph,
    const coder::array<double, 3U> &disperse_vgr,
    const coder::array<double, 3U> &disperse_waveno,
    const coder::array<creal_T, 3U> &disperse_ms_x,
    const coder::array<creal_T, 3U> &disperse_ms_y,
    const coder::array<creal_T, 3U> &disperse_ms_z,
    const coder::array<double, 2U> &opts_ms_matrix_modes_to_use,
    double opts_freq_filter_on, double opts_freq_filter,
    double opts_freq_filter_bandwidth, double opts_raw_data_zero_dead_time,
    double opts_raw_data_ignore_pulse_echo, double opts_ms_matrix_bidi_calc,
    double opts_ms_matrix_apply_as_time_shift,
    double opts_ms_matrix_time_step_size, double opts_ms_matrix_allow_neg_amps,
    coder::array<double, 2U> &opts_ms_matrix_calc_freqs,
    double opts_dispersion_compensation,
    const coder::array<double, 2U> &opts_manual_warps,
    coder::array<double, 1U> &proc_tx_mode,
    coder::array<double, 1U> &proc_rx_mode,
    coder::array<double, 1U> &proc_tx_dir,
    coder::array<double, 1U> &proc_rx_dir, coder::array<double, 1U> &proc_dist,
    coder::array<creal_T, 2U> &proc_dist_data);

#endif
//
// File trailer for fn_process_rail_data_DLL.h
//
// [EOF]
//
