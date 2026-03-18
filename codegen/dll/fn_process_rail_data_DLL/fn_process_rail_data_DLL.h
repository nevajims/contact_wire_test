/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: fn_process_rail_data_DLL.h
 *
 * MATLAB Coder version            : 25.1
 * C/C++ source code generated on  : 12-Mar-2026 17:25:15
 */

#ifndef FN_PROCESS_RAIL_DATA_DLL_H
#define FN_PROCESS_RAIL_DATA_DLL_H

/* Include Files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void fn_process_rail_data_DLL(
    const double b_time[2048], const double time_data[294912],
    const long long tx[144], const long long rx[144], const double row_pos[3],
    const long long trans_pos[12], const long long trans_row[12],
    const double trans_pos_orientations[36], double delay,
    const long long trans_node_list[4], double tx_mode[32], double rx_mode[32],
    double tx_dir[32], double rx_dir[32], double dist[3158],
    double dist_data[101056]);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for fn_process_rail_data_DLL.h
 *
 * [EOF]
 */
