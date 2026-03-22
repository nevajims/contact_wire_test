/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * fn_process_rail_data_DLL.h
 *
 * Code generation for function 'fn_process_rail_data_DLL'
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
emlrtCTX emlrtGetRootTLSGlobal(void);

void emlrtLockerFunction(EmlrtLockeeFunction aLockee, emlrtConstCTX aTLS,
                         void *aData);

void fn_process_rail_data_DLL(
    const emlrtStack *sp, const emxArray_real_T *raw_time,
    emxArray_real_T *raw_time_data, emxArray_int64_T *raw_tx,
    emxArray_int64_T *raw_rx, const emxArray_real_T *array_row_pos,
    const emxArray_int64_T *array_trans_pos,
    const emxArray_int64_T *array_trans_row,
    const emxArray_real_T *array_trans_pos_orientations, real_T array_delay,
    const emxArray_int64_T *array_trans_node_list,
    const emxArray_real_T *disperse_freq, const emxArray_real_T *disperse_vph,
    const emxArray_real_T *disperse_vgr, const emxArray_real_T *disperse_waveno,
    const emxArray_creal_T *disperse_ms_x,
    const emxArray_creal_T *disperse_ms_y,
    const emxArray_creal_T *disperse_ms_z,
    const emxArray_real_T *opts_ms_matrix_modes_to_use,
    real_T opts_freq_filter_on, real_T opts_freq_filter,
    real_T opts_freq_filter_bandwidth, real_T opts_raw_data_zero_dead_time,
    real_T opts_raw_data_ignore_pulse_echo, real_T opts_ms_matrix_bidi_calc,
    real_T c_opts_ms_matrix_apply_as_time_,
    real_T opts_ms_matrix_time_step_size, real_T opts_ms_matrix_allow_neg_amps,
    emxArray_real_T *opts_ms_matrix_calc_freqs,
    real_T opts_dispersion_compensation,
    const emxArray_real_T *opts_manual_warps, emxArray_real_T *proc_tx_mode,
    emxArray_real_T *proc_rx_mode, emxArray_real_T *proc_tx_dir,
    emxArray_real_T *proc_rx_dir, emxArray_real_T *proc_dist,
    emxArray_creal_T *proc_dist_data);

/* End of code generation (fn_process_rail_data_DLL.h) */
