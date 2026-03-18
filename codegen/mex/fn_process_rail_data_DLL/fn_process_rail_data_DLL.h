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
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void fn_process_rail_data_DLL(
    const emlrtStack *sp, const real_T b_time[2048],
    const real_T time_data[294912], const int64_T tx[144],
    const int64_T rx[144], const real_T row_pos[3], const int64_T trans_pos[12],
    const int64_T trans_row[12], const real_T trans_pos_orientations[36],
    real_T delay, const int64_T trans_node_list[4], real_T tx_mode[32],
    real_T rx_mode[32], real_T tx_dir[32], real_T rx_dir[32], real_T dist[3158],
    real_T dist_data[101056]);

/* End of code generation (fn_process_rail_data_DLL.h) */
