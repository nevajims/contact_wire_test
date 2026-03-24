//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: fn_process_rail_data_DLL.cpp
//
// MATLAB Coder version            : 25.1
// C/C++ source code generated on  : 24-Mar-2026 22:30:21
//

// Include Files
#include "fn_process_rail_data_DLL.h"
#include "abs.h"
#include "angle.h"
#include "div.h"
#include "dot.h"
#include "exp.h"
#include "fft.h"
#include "find.h"
#include "flipud.h"
#include "fn_process_rail_data_DLL_data.h"
#include "fn_process_rail_data_DLL_initialize.h"
#include "ifft.h"
#include "interp1.h"
#include "linspace.h"
#include "minOrMax.h"
#include "mpower.h"
#include "mrdivide_helper.h"
#include "nextpow2.h"
#include "pinv.h"
#include "round.h"
#include "rt_nonfinite.h"
#include "squeeze.h"
#include "sum.h"
#include "coder_array.h"
#include "omp.h"
#include <algorithm>
#include <cmath>
#include <cstring>
#include <emmintrin.h>

// Function Declarations
static void binary_expand_op_2(coder::array<creal_T, 2U> &in1, double in2,
                               const coder::array<creal_T, 2U> &in3,
                               const coder::array<double, 2U> &in4,
                               const coder::array<creal_T, 1U> &in5);

static void binary_expand_op_3(coder::array<creal_T, 2U> &in1,
                               const coder::array<creal_T, 2U> &in2,
                               const coder::array<double, 1U> &in3);

static void binary_expand_op_4(coder::array<double, 1U> &in1,
                               const coder::array<double, 1U> &in2);

static void binary_expand_op_5(coder::array<creal_T, 2U> &in1,
                               const coder::array<creal_T, 1U> &in2);

// Function Definitions
//
// Arguments    : coder::array<creal_T, 2U> &in1
//                double in2
//                const coder::array<creal_T, 2U> &in3
//                const coder::array<double, 2U> &in4
//                const coder::array<creal_T, 1U> &in5
// Return Type  : void
//
static void binary_expand_op_2(coder::array<creal_T, 2U> &in1, double in2,
                               const coder::array<creal_T, 2U> &in3,
                               const coder::array<double, 2U> &in4,
                               const coder::array<creal_T, 1U> &in5)
{
  coder::array<creal_T, 2U> b_in3;
  coder::array<creal_T, 2U> b_in4;
  double e_in3_re_tmp;
  double f_in3_re_tmp;
  double g_in3_re_tmp;
  double h_in3_re_tmp;
  int aux_0_1;
  int aux_1_1;
  int b_in2;
  int b_in3_re_tmp_tmp;
  int b_loop_ub;
  int i5;
  int in3_re_tmp_tmp;
  int in5_idx_0;
  int loop_ub;
  int stride_0_1;
  b_in2 = static_cast<int>(in2);
  in5_idx_0 = in5.size(0);
  loop_ub = in4.size(1);
  if (in5_idx_0 == 1) {
    b_loop_ub = in4.size(0);
  } else {
    b_loop_ub = in5_idx_0;
  }
  b_in4.set_size(loop_ub, b_loop_ub);
  stride_0_1 = (in4.size(0) != 1);
  in5_idx_0 = (in5_idx_0 != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  for (int i{0}; i < b_loop_ub; i++) {
    for (int i1{0}; i1 < loop_ub; i1++) {
      int i2;
      int i3;
      i2 = aux_0_1 + in4.size(0) * i1;
      i3 = i1 + b_in4.size(0) * i;
      b_in4[i3].re = in4[i2] * in5[aux_1_1].re;
      b_in4[i3].im = in4[i2] * in5[aux_1_1].im;
    }
    aux_1_1 += in5_idx_0;
    aux_0_1 += stride_0_1;
  }
  aux_1_1 = in3.size(1);
  b_in3.set_size(1, b_loop_ub);
  if (static_cast<int>(b_in4.size(1) * aux_1_1 < 2000)) {
    for (int i4{0}; i4 < b_loop_ub; i4++) {
      b_in3[i4].re = 0.0;
      b_in3[i4].im = 0.0;
      for (i5 = 0; i5 < aux_1_1; i5++) {
        double b_in3_re_tmp;
        double c_in3_re_tmp;
        double d_in3_re_tmp;
        double in3_re_tmp;
        in5_idx_0 = (static_cast<int>(in2) + in3.size(0) * i5) - 1;
        in3_re_tmp = in3[in5_idx_0].re;
        aux_0_1 = i5 + b_in4.size(0) * i4;
        b_in3_re_tmp = b_in4[aux_0_1].im;
        c_in3_re_tmp = in3[in5_idx_0].im;
        d_in3_re_tmp = b_in4[aux_0_1].re;
        b_in3[i4].re = b_in3[i4].re + (in3_re_tmp * d_in3_re_tmp -
                                       c_in3_re_tmp * b_in3_re_tmp);
        b_in3[i4].im = b_in3[i4].im + (in3_re_tmp * b_in3_re_tmp +
                                       c_in3_re_tmp * d_in3_re_tmp);
      }
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
        i5, in3_re_tmp_tmp, e_in3_re_tmp, b_in3_re_tmp_tmp, f_in3_re_tmp,      \
            g_in3_re_tmp, h_in3_re_tmp)

    for (int i4 = 0; i4 < b_loop_ub; i4++) {
      b_in3[i4].re = 0.0;
      b_in3[i4].im = 0.0;
      for (i5 = 0; i5 < aux_1_1; i5++) {
        in3_re_tmp_tmp = (b_in2 + in3.size(0) * i5) - 1;
        e_in3_re_tmp = in3[in3_re_tmp_tmp].re;
        b_in3_re_tmp_tmp = i5 + b_in4.size(0) * i4;
        f_in3_re_tmp = b_in4[b_in3_re_tmp_tmp].im;
        g_in3_re_tmp = in3[in3_re_tmp_tmp].im;
        h_in3_re_tmp = b_in4[b_in3_re_tmp_tmp].re;
        b_in3[i4].re = b_in3[i4].re + (e_in3_re_tmp * h_in3_re_tmp -
                                       g_in3_re_tmp * f_in3_re_tmp);
        b_in3[i4].im = b_in3[i4].im + (e_in3_re_tmp * f_in3_re_tmp +
                                       g_in3_re_tmp * h_in3_re_tmp);
      }
    }
  }
  in5_idx_0 = in1.size(1);
  for (int i{0}; i < in5_idx_0; i++) {
    in1[(static_cast<int>(in2) + in1.size(0) * i) - 1] = b_in3[i];
  }
}

//
// Arguments    : coder::array<creal_T, 2U> &in1
//                const coder::array<creal_T, 2U> &in2
//                const coder::array<double, 1U> &in3
// Return Type  : void
//
static void binary_expand_op_3(coder::array<creal_T, 2U> &in1,
                               const coder::array<creal_T, 2U> &in2,
                               const coder::array<double, 1U> &in3)
{
  coder::array<double, 2U> b_in3;
  int aux_0_1;
  int aux_1_1;
  int loop_ub;
  int scalarLB;
  int stride_1_0;
  int stride_1_1;
  int unnamed_idx_1;
  int vectorUB;
  unnamed_idx_1 = in2.size(1);
  loop_ub = in3.size(0);
  b_in3.set_size(loop_ub, unnamed_idx_1);
  for (int i{0}; i < unnamed_idx_1; i++) {
    scalarLB = (loop_ub / 2) << 1;
    vectorUB = scalarLB - 2;
    for (int i1{0}; i1 <= vectorUB; i1 += 2) {
      __m128d r;
      r = _mm_loadu_pd(&in3[i1]);
      _mm_storeu_pd(&b_in3[i1 + b_in3.size(0) * i],
                    _mm_add_pd(_mm_set1_pd(0.0), r));
    }
    for (int i1{scalarLB}; i1 < loop_ub; i1++) {
      b_in3[i1 + b_in3.size(0) * i] = in3[i1];
    }
  }
  if (b_in3.size(0) == 1) {
    unnamed_idx_1 = in2.size(0);
  } else {
    unnamed_idx_1 = b_in3.size(0);
  }
  in1.set_size(unnamed_idx_1, in1.size(1));
  if (b_in3.size(1) == 1) {
    loop_ub = in2.size(1);
  } else {
    loop_ub = b_in3.size(1);
  }
  in1.set_size(in1.size(0), loop_ub);
  scalarLB = (in2.size(0) != 1);
  vectorUB = (in2.size(1) != 1);
  stride_1_0 = (b_in3.size(0) != 1);
  stride_1_1 = (b_in3.size(1) != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  for (int i{0}; i < loop_ub; i++) {
    for (int i1{0}; i1 < unnamed_idx_1; i1++) {
      double d;
      int i2;
      int i3;
      d = b_in3[i1 * stride_1_0 + b_in3.size(0) * aux_1_1];
      i2 = i1 * scalarLB + in2.size(0) * aux_0_1;
      i3 = i1 + in1.size(0) * i;
      in1[i3].re = d * in2[i2].re;
      in1[i3].im = d * in2[i2].im;
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += vectorUB;
  }
}

//
// Arguments    : coder::array<double, 1U> &in1
//                const coder::array<double, 1U> &in2
// Return Type  : void
//
static void binary_expand_op_4(coder::array<double, 1U> &in1,
                               const coder::array<double, 1U> &in2)
{
  coder::array<double, 1U> r;
  int loop_ub;
  int stride_1_0;
  if (in1.size(0) == 1) {
    loop_ub = in2.size(0);
  } else {
    loop_ub = in1.size(0);
  }
  r.set_size(loop_ub);
  stride_1_0 = (in1.size(0) != 1);
  for (int i{0}; i < loop_ub; i++) {
    r[i] = in1[i * stride_1_0];
  }
  in1.set_size(loop_ub);
  for (int i{0}; i < loop_ub; i++) {
    in1[i] = r[i];
  }
}

//
// Arguments    : coder::array<creal_T, 2U> &in1
//                const coder::array<creal_T, 1U> &in2
// Return Type  : void
//
static void binary_expand_op_5(coder::array<creal_T, 2U> &in1,
                               const coder::array<creal_T, 1U> &in2)
{
  coder::array<creal_T, 2U> b_in1;
  int b_loop_ub;
  int loop_ub;
  int stride_0_0;
  loop_ub = in1.size(0);
  b_loop_ub = in1.size(1);
  b_in1.set_size(loop_ub, b_loop_ub);
  stride_0_0 = (in2.size(0) != 1);
  for (int i{0}; i < b_loop_ub; i++) {
    for (int i1{0}; i1 < loop_ub; i1++) {
      double d;
      double d1;
      double d2;
      double d3;
      int i2;
      int i3;
      i2 = i1 * stride_0_0;
      i3 = i1 + in1.size(0) * i;
      d = in1[i3].re;
      d1 = in2[i2].im;
      d2 = in1[i3].im;
      d3 = in2[i2].re;
      i2 = i1 + b_in1.size(0) * i;
      b_in1[i2].re = d * d3 - d2 * d1;
      b_in1[i2].im = d * d1 + d2 * d3;
    }
  }
  for (int i{0}; i < b_loop_ub; i++) {
    for (int i1{0}; i1 < loop_ub; i1++) {
      in1[i1 + in1.size(0) * i] = b_in1[i1 + b_in1.size(0) * i];
    }
  }
}

//
// %raw data
//  %array
//
// Arguments    : const coder::array<double, 1U> &raw_time
//                coder::array<double, 2U> &raw_time_data
//                coder::array<long long, 1U> &raw_tx
//                coder::array<long long, 1U> &raw_rx
//                const coder::array<double, 2U> &array_row_pos
//                const coder::array<long long, 2U> &array_trans_pos
//                const coder::array<long long, 2U> &array_trans_row
//                const coder::array<double, 2U> &array_trans_pos_orientations
//                double array_delay
//                const coder::array<long long, 2U> &array_trans_node_list
//                const coder::array<double, 3U> &disperse_freq
//                const coder::array<double, 3U> &disperse_vph
//                const coder::array<double, 3U> &disperse_vgr
//                const coder::array<double, 3U> &disperse_waveno
//                const coder::array<creal_T, 3U> &disperse_ms_x
//                const coder::array<creal_T, 3U> &disperse_ms_y
//                const coder::array<creal_T, 3U> &disperse_ms_z
//                const coder::array<double, 2U> &opts_ms_matrix_modes_to_use
//                double opts_freq_filter_on
//                double opts_freq_filter
//                double opts_freq_filter_bandwidth
//                double opts_raw_data_zero_dead_time
//                double opts_raw_data_ignore_pulse_echo
//                double opts_ms_matrix_bidi_calc
//                double opts_ms_matrix_apply_as_time_shift
//                double opts_ms_matrix_time_step_size
//                double opts_ms_matrix_allow_neg_amps
//                coder::array<double, 2U> &opts_ms_matrix_calc_freqs
//                double opts_dispersion_compensation
//                const coder::array<double, 2U> &opts_manual_warps
//                coder::array<double, 1U> &proc_tx_mode
//                coder::array<double, 1U> &proc_rx_mode
//                coder::array<double, 1U> &proc_tx_dir
//                coder::array<double, 1U> &proc_rx_dir
//                coder::array<double, 1U> &proc_dist
//                coder::array<creal_T, 2U> &proc_dist_data
// Return Type  : void
//
void fn_process_rail_data_DLL(
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
    coder::array<creal_T, 2U> &proc_dist_data)
{
  __m128d r1;
  coder::array<creal_T, 3U> b_inv_mode_shapes;
  coder::array<creal_T, 3U> inv_mode_shapes;
  coder::array<creal_T, 3U> temp_mode_shape;
  coder::array<creal_T, 2U> b_raw_freq_data;
  coder::array<creal_T, 2U> c_mode_shapes;
  coder::array<creal_T, 2U> c_raw_freq_data;
  coder::array<creal_T, 2U> mode_shapes;
  coder::array<creal_T, 2U> proc_freq_data;
  coder::array<creal_T, 2U> raw_freq_data;
  coder::array<creal_T, 1U> b_mode_shapes;
  coder::array<creal_T, 1U> b_proc_dist_data;
  coder::array<double, 2U> b_array_trans_pos_orientations;
  coder::array<double, 2U> b_filter;
  coder::array<double, 2U> b_proc_rx_mode;
  coder::array<double, 2U> b_proc_tx_mode;
  coder::array<double, 2U> modal_vgrs;
  coder::array<double, 2U> temp;
  coder::array<double, 1U> b_disperse_freq;
  coder::array<double, 1U> b_proc_tx_dir;
  coder::array<double, 1U> filter;
  coder::array<double, 1U> freq;
  coder::array<double, 1U> pitch_catch_indices;
  coder::array<long long, 1U> c_raw_tx;
  coder::array<int, 2U> r2;
  coder::array<int, 1U> r;
  coder::array<boolean_T, 2U> b_temp;
  coder::array<boolean_T, 2U> c_proc_tx_mode;
  coder::array<boolean_T, 1U> b_raw_tx;
  creal_T b_y;
  creal_T dc;
  double dv[2];
  double b_temp_tmp;
  double fft_pts;
  double freq_i1;
  double max_freq;
  double max_mode_index;
  double peak_pos_fract;
  double re;
  double temp_tmp;
  double varargin_1;
  double y;
  int b_loop_ub;
  int b_temp_tmp_tmp;
  int c_loop_ub;
  int d_loop_ub;
  int e_loop_ub;
  int end;
  int f_loop_ub;
  int g_loop_ub;
  int h_loop_ub;
  int i_loop_ub;
  int j_loop_ub;
  int k_loop_ub;
  int l_loop_ub;
  int loop_ub;
  int loop_ub_tmp;
  int m_loop_ub;
  int n_loop_ub;
  int temp_tmp_tmp;
  (void)array_delay;
  (void)disperse_vph;
  (void)opts_dispersion_compensation;
  if (!isInitialized_fn_process_rail_data_DLL) {
    fn_process_rail_data_DLL_initialize();
  }
  //  %although on before, was coded wrong and didn't do anything
  //  %not convinced latter two are useful
  //  freq_comp_for_input_signal = 0; %NOT IMPLEMENTED
  //  raw_data_coupling_comp = 0; %NOT IMPLEMENTED
  //  opts_ms_matrix_calc_method = 1; %DOESN't DO OWT
  // This is a Matlab coder compatible version of fn_process_rail_data which
  // avoids dynamic structures
  // --------------------------------------------------------------------------
  // Following eventually to be options but hardcoded to match benchmark for
  // now
  //  opts_ms_matrix_modes_to_use = 1:4;%temp to get things working
  //  opts_freq_filter = 50000;
  //  opts_freq_filter_bandwidth = 40000;
  //  % freq_comp_for_input_signal = 0; %NOT IMPLEMENTED
  //  opts_raw_data_ignore_pulse_echo = 1;
  //  % raw_data_coupling_comp = 0; %NOT IMPLEMENTED
  //  opts_raw_data_zero_dead_time = 0; %this was coded wrong before and didn't
  //  do anything, even when set to non-zero. It is now correct, and zero is
  //  needed to turn it off. opts_ms_matrix_calc_method = 1;
  //  opts_ms_matrix_calc_freqs = [30000 34000 38000 42000 46000 50000 54000
  //  58000 62000 66000 70000];%temp to get things working
  //
  //  opts_freq_filter_on = 1;
  //  opts_ms_matrix_bidi_calc = 0;
  //  opts_ms_matrix_apply_as_time_shift = 0;
  //  opts_ms_matrix_time_step_size = 0; %if non-zero and doing time shifts,
  //  this sets the smallest integral multiple of time shifts allowed
  //  opts_ms_matrix_allow_neg_amps = 1;
  //  opts_dispersion_compensation = 0;
  //  opts_manual_warps = [1.02,1.02,1.02,0.952];
  // --------------------------------------------------------------------------
  // Sort out the indices of the outputs
  loop_ub = opts_ms_matrix_modes_to_use.size(1);
  b_proc_tx_mode.set_size(opts_ms_matrix_modes_to_use.size(1),
                          opts_ms_matrix_modes_to_use.size(1));
  for (int i{0}; i < loop_ub; i++) {
    for (int b_i{0}; b_i < loop_ub; b_i++) {
      b_proc_tx_mode[b_i + b_proc_tx_mode.size(0) * i] =
          opts_ms_matrix_modes_to_use[i];
    }
  }
  b_proc_rx_mode.set_size(opts_ms_matrix_modes_to_use.size(1),
                          opts_ms_matrix_modes_to_use.size(1));
  for (int i{0}; i < loop_ub; i++) {
    for (int b_i{0}; b_i < loop_ub; b_i++) {
      b_proc_rx_mode[b_i + b_proc_rx_mode.size(0) * i] =
          b_proc_tx_mode[i + b_proc_tx_mode.size(0) * b_i];
    }
  }
  end = b_proc_tx_mode.size(0) + b_proc_tx_mode.size(0);
  b_loop_ub = end * b_proc_tx_mode.size(1);
  proc_tx_dir.set_size(b_loop_ub);
  c_loop_ub = b_proc_tx_mode.size(0) * b_proc_tx_mode.size(1);
  for (int i{0}; i < c_loop_ub; i++) {
    proc_tx_dir[i] = 1.0;
    proc_tx_dir[i + c_loop_ub] = -1.0;
  }
  proc_rx_dir.set_size(b_loop_ub);
  for (int i{0}; i < b_loop_ub; i++) {
    proc_rx_dir[i] = proc_tx_dir[i];
  }
  if (opts_ms_matrix_bidi_calc != 0.0) {
    d_loop_ub = proc_tx_dir.size(0) + proc_tx_dir.size(0);
    b_proc_tx_dir.set_size(d_loop_ub);
    for (int i{0}; i < b_loop_ub; i++) {
      b_proc_tx_dir[i] = proc_tx_dir[i];
    }
    for (int i{0}; i < b_loop_ub; i++) {
      b_proc_tx_dir[i + proc_tx_dir.size(0)] = proc_tx_dir[i];
    }
    proc_tx_dir.set_size(d_loop_ub);
    for (int i{0}; i < d_loop_ub; i++) {
      proc_tx_dir[i] = b_proc_tx_dir[i];
    }
    b_proc_tx_dir.set_size(b_loop_ub);
    for (int i{0}; i < b_loop_ub; i++) {
      b_proc_tx_dir[i] = proc_rx_dir[i];
    }
    coder::flipud(b_proc_tx_dir);
    proc_rx_dir.set_size(proc_rx_dir.size(0) + b_proc_tx_dir.size(0));
    e_loop_ub = b_proc_tx_dir.size(0);
    for (int i{0}; i < e_loop_ub; i++) {
      proc_rx_dir[b_loop_ub + i] = b_proc_tx_dir[i];
    }
    end += b_proc_tx_mode.size(0);
    e_loop_ub = (end + b_proc_tx_mode.size(0)) * b_proc_tx_mode.size(1);
    proc_tx_mode.set_size(e_loop_ub);
    for (int i{0}; i < c_loop_ub; i++) {
      proc_tx_mode[i] = b_proc_tx_mode[i];
      proc_tx_mode[i + c_loop_ub] = b_proc_tx_mode[i];
    }
    for (int i{0}; i < c_loop_ub; i++) {
      proc_tx_mode[i + b_loop_ub] = b_proc_tx_mode[i];
    }
    for (int i{0}; i < c_loop_ub; i++) {
      proc_tx_mode[i + end * b_proc_tx_mode.size(1)] = b_proc_tx_mode[i];
    }
    proc_rx_mode.set_size(e_loop_ub);
    for (int i{0}; i < c_loop_ub; i++) {
      proc_rx_mode[i] = b_proc_rx_mode[i];
      proc_rx_mode[i + c_loop_ub] = b_proc_rx_mode[i];
    }
    for (int i{0}; i < c_loop_ub; i++) {
      proc_rx_mode[i + b_loop_ub] = b_proc_rx_mode[i];
    }
    for (int i{0}; i < c_loop_ub; i++) {
      proc_rx_mode[i + end * b_proc_rx_mode.size(1)] = b_proc_rx_mode[i];
    }
  } else {
    proc_tx_mode.set_size(b_loop_ub);
    for (int i{0}; i < c_loop_ub; i++) {
      proc_tx_mode[i] = b_proc_tx_mode[i];
      proc_tx_mode[i + c_loop_ub] = b_proc_tx_mode[i];
    }
    proc_rx_mode.set_size(b_loop_ub);
    for (int i{0}; i < c_loop_ub; i++) {
      proc_rx_mode[i] = b_proc_rx_mode[i];
      proc_rx_mode[i + c_loop_ub] = b_proc_rx_mode[i];
    }
  }
  //  %force single frequency mode shape matrix processing if simulating working
  //  in time domain opts_ms_matrix_calc_method = 1;
  //  opts_ms_matrix_apply_as_time_shift = 0;
  //  if opts_ms_matrix_apply_as_time_shift
  //      % opts_ms_matrix_calc_freqs = opts_freq_filter;
  //     opts_ms_matrix_calc_method = 1; %to force single mode shape matrix at
  //     filter freq only
  //  end
  //
  //  %set up frequency for mode shape calc if only using single freq
  //  if opts_ms_matrix_calc_method == 1
  //      opts_ms_matrix_calc_freqs = opts_freq_filter;
  //  end
  if (opts_ms_matrix_calc_freqs.size(1) == 0) {
    opts_ms_matrix_calc_freqs.set_size(1, 1);
    opts_ms_matrix_calc_freqs[0] = opts_freq_filter;
  }
  // zero out dead time if required
  if (opts_raw_data_zero_dead_time > 0.0) {
    // --------------------------------------------------------------------------
    end = raw_time.size(0);
    e_loop_ub = 0;
    for (int i{0}; i < end; i++) {
      if (raw_time[i] <= opts_raw_data_zero_dead_time) {
        e_loop_ub++;
      }
    }
    r.set_size(e_loop_ub);
    d_loop_ub = 0;
    for (int b_i{0}; b_i < end; b_i++) {
      if (raw_time[b_i] <= opts_raw_data_zero_dead_time) {
        r[d_loop_ub] = b_i;
        d_loop_ub++;
      }
    }
    end = raw_time_data.size(1);
    for (int i{0}; i < end; i++) {
      e_loop_ub = r.size(0);
      for (int b_i{0}; b_i < e_loop_ub; b_i++) {
        raw_time_data[r[b_i] + raw_time_data.size(0) * i] = 0.0;
      }
    }
  }
  // removal of p/e columns if required
  if (opts_raw_data_ignore_pulse_echo == 1.0) {
    if (raw_tx.size(0) == raw_rx.size(0)) {
      e_loop_ub = raw_tx.size(0);
      b_raw_tx.set_size(raw_tx.size(0));
      if (static_cast<int>(raw_tx.size(0) < 2000)) {
        for (int c_i{0}; c_i < e_loop_ub; c_i++) {
          b_raw_tx[c_i] = (raw_tx[c_i] != raw_rx[c_i]);
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int c_i = 0; c_i < e_loop_ub; c_i++) {
          b_raw_tx[c_i] = (raw_tx[c_i] != raw_rx[c_i]);
        }
      }
      coder::eml_find(b_raw_tx, r);
    } else {
      binary_expand_op_6(r, raw_tx, raw_rx);
    }
    end = r.size(0);
    pitch_catch_indices.set_size(r.size(0));
    for (int i{0}; i < end; i++) {
      pitch_catch_indices[i] = r[i];
    }
    c_raw_tx.set_size(r.size(0));
    for (int i{0}; i < end; i++) {
      c_raw_tx[i] = raw_tx[static_cast<int>(pitch_catch_indices[i]) - 1];
    }
    raw_tx.set_size(r.size(0));
    for (int i{0}; i < end; i++) {
      raw_tx[i] = c_raw_tx[i];
    }
    c_raw_tx.set_size(r.size(0));
    for (int i{0}; i < end; i++) {
      c_raw_tx[i] = raw_rx[static_cast<int>(pitch_catch_indices[i]) - 1];
    }
    raw_rx.set_size(r.size(0));
    e_loop_ub = raw_time_data.size(0);
    b_proc_rx_mode.set_size(raw_time_data.size(0), r.size(0));
    for (int i{0}; i < end; i++) {
      raw_rx[i] = c_raw_tx[i];
      for (int b_i{0}; b_i < e_loop_ub; b_i++) {
        b_proc_rx_mode[b_i + b_proc_rx_mode.size(0) * i] =
            raw_time_data[b_i +
                          raw_time_data.size(0) *
                              (static_cast<int>(pitch_catch_indices[i]) - 1)];
      }
    }
    raw_time_data.set_size(e_loop_ub, r.size(0));
    e_loop_ub = b_proc_rx_mode.size(0) * b_proc_rx_mode.size(1);
    for (int i{0}; i < e_loop_ub; i++) {
      raw_time_data[i] = b_proc_rx_mode[i];
    }
  }
  // convert to frequency domain
  fft_pts = coder::mpower(
      coder::nextpow2(static_cast<double>(raw_time_data.size(0))));
  coder::fft(raw_time_data, fft_pts, mode_shapes);
  b_loop_ub = mode_shapes.size(1);
  max_freq = fft_pts / 2.0;
  c_loop_ub = static_cast<int>(max_freq + 1.0);
  for (int i{0}; i < b_loop_ub; i++) {
    for (int b_i{0}; b_i < c_loop_ub; b_i++) {
      mode_shapes[b_i + static_cast<int>(max_freq + 1.0) * i] =
          mode_shapes[b_i + mode_shapes.size(0) * i];
    }
  }
  mode_shapes.set_size(static_cast<int>(max_freq + 1.0), mode_shapes.size(1));
  y = 1.0 / (fft_pts * std::abs(raw_time[0] - raw_time[1]));
  if (std::isnan(max_freq)) {
    b_array_trans_pos_orientations.set_size(1, 1);
    b_array_trans_pos_orientations[0] = rtNaN;
  } else if (max_freq < 0.0) {
    b_array_trans_pos_orientations.set_size(1, 0);
  } else {
    b_array_trans_pos_orientations.set_size(1, static_cast<int>(max_freq) + 1);
    e_loop_ub = static_cast<int>(max_freq);
    for (int i{0}; i <= e_loop_ub; i++) {
      b_array_trans_pos_orientations[i] = i;
    }
  }
  d_loop_ub = b_array_trans_pos_orientations.size(1);
  freq.set_size(b_array_trans_pos_orientations.size(1));
  e_loop_ub = (b_array_trans_pos_orientations.size(1) / 2) << 1;
  end = e_loop_ub - 2;
  for (int i{0}; i <= end; i += 2) {
    r1 = _mm_loadu_pd(&b_array_trans_pos_orientations[i]);
    _mm_storeu_pd(&freq[i], _mm_mul_pd(r1, _mm_set1_pd(y)));
  }
  for (int i{e_loop_ub}; i < d_loop_ub; i++) {
    freq[i] = b_array_trans_pos_orientations[i] * y;
  }
  max_freq = raw_time[0];
  e_loop_ub = freq.size(0);
  b_mode_shapes.set_size(freq.size(0));
  if (static_cast<int>(freq.size(0) < 2000)) {
    for (int i1{0}; i1 < e_loop_ub; i1++) {
      b_mode_shapes[i1].re = max_freq * (freq[i1] * -0.0);
      b_mode_shapes[i1].im = max_freq * (freq[i1] * -6.2831853071795862);
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i1 = 0; i1 < e_loop_ub; i1++) {
      b_mode_shapes[i1].re = max_freq * (freq[i1] * -0.0);
      b_mode_shapes[i1].im = max_freq * (freq[i1] * -6.2831853071795862);
    }
  }
  coder::b_exp(b_mode_shapes);
  if (mode_shapes.size(0) == b_mode_shapes.size(0)) {
    c_mode_shapes.set_size(c_loop_ub, b_loop_ub);
    for (int i{0}; i < b_loop_ub; i++) {
      for (int b_i{0}; b_i < c_loop_ub; b_i++) {
        d_loop_ub = b_i + mode_shapes.size(0) * i;
        y = mode_shapes[d_loop_ub].re;
        max_freq = b_mode_shapes[b_i].im;
        peak_pos_fract = mode_shapes[d_loop_ub].im;
        re = b_mode_shapes[b_i].re;
        d_loop_ub = b_i + c_mode_shapes.size(0) * i;
        c_mode_shapes[d_loop_ub].re = y * re - peak_pos_fract * max_freq;
        c_mode_shapes[d_loop_ub].im = y * max_freq + peak_pos_fract * re;
      }
    }
    mode_shapes.set_size(c_loop_ub, b_loop_ub);
    e_loop_ub = c_mode_shapes.size(0) * c_mode_shapes.size(1);
    if (e_loop_ub - 1 >= 0) {
      std::copy(&c_mode_shapes[0], &c_mode_shapes[e_loop_ub], &mode_shapes[0]);
    }
  } else {
    binary_expand_op_5(mode_shapes, b_mode_shapes);
  }
  f_loop_ub = mode_shapes.size(0);
  c_loop_ub = mode_shapes.size(1);
  raw_freq_data.set_size(mode_shapes.size(0), mode_shapes.size(1));
  g_loop_ub = mode_shapes.size(0) * mode_shapes.size(1);
  if (g_loop_ub - 1 >= 0) {
    std::copy(&mode_shapes[0], &mode_shapes[g_loop_ub], &raw_freq_data[0]);
  }
  //  %coupling compensation if required
  //  if options.raw_data_coupling_comp ~= 0
  //      raw_data = fn_coupling_comp(raw_data, array, options);
  //  end
  // frequency domain processing
  //  function raw_data = fn_filter_freq_domain_data(raw_data_in, input_signal,
  //  delay, freq_comp_for_input_signal, freq_filter_on, freq_filter,
  //  freq_filter_bandwidth, suppress_display);
  if (opts_freq_filter_on != 0.0) {
    //  if freq_comp_for_input_signal
    //  	%calculate spectrum of input signal
    //  	time_step = abs(raw_data.time(1) - raw_data.time(2));
    //  	in_time = ([1:raw_data.fft_pts]-1) * time_step;
    //  	in_signal = 0.5 * sin(2 * pi * input_signal.freq * in_time) .*
    //  (1 - cos(2 * pi * input_signal.freq * in_time / input_signal.cycles)) .*
    //  (in_time < input_signal.cycles / input_signal.freq); 	in_spec =
    //  fft(in_signal, raw_data.fft_pts); 	in_spec =
    //  abs(in_spec(1:raw_data.fft_pts/2+1))'; 	in_valid = in_spec > 0;
    //  	in_spec(~in_valid) = 1;
    //  	filter = filter ./ in_spec;
    //  	filter(~in_valid) = 1;
    //  end;
    max_freq = coder::internal::maximum(freq);
    peak_pos_fract = opts_freq_filter / max_freq;
    // gaussian(number_of_points, peak_pos_fract, half_width_fract, db_down)
    //
    // creates a gaussian vector with number_of_points elements
    // the peak at the point in the vector specified by peak_pos_fract (as a
    // fraction) and half width specified by half_width_fract, where db_down
    // (defaults to 40) specifies the number of dB below the peak value at the
    // half width point USAGE 	window = gaussian(number_of_points,
    // peak_pos_fract, half_width_fract, db_down, force_zero) AUTHOR 	Paul Wilcox
    // (2003) SUMMARY 	Creates a Gaussian window OUTPUTS 	window - the generated
    // window function, with amplitude ranging from 0 to 1 INPUTS
    // 	number_of_points - how many points are in the window vector
    // 	peak_pos_fract - whereabouts the peak of the window is as a fraction
    // 	of the total length of the window vector
    // 	half_width_fract - how wide the halfwidth of the window is as a fraction
    // of 	the total length of the window vector 	(db_down) - number of dB below
    // peak of window used to define the width. 	Default is 40. 	(force_zero) - if
    // true, points in window outside defined width are 	set to zero. Default is
    // false. NOTES 	output is a column vector 	The function forces window outside
    // half width fraction to be zero
    // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    max_freq = opts_freq_filter_bandwidth / max_freq / 2.1459660262893472;
    coder::linspace(static_cast<double>(freq.size(0)),
                    b_array_trans_pos_orientations);
    d_loop_ub = b_array_trans_pos_orientations.size(1);
    filter.set_size(b_array_trans_pos_orientations.size(1));
    if (static_cast<int>(b_array_trans_pos_orientations.size(1) < 2000)) {
      for (int i3{0}; i3 < d_loop_ub; i3++) {
        y = (b_array_trans_pos_orientations[i3] - peak_pos_fract) / max_freq;
        filter[i3] = -(y * y);
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(varargin_1)

      for (int i3 = 0; i3 < d_loop_ub; i3++) {
        varargin_1 =
            (b_array_trans_pos_orientations[i3] - peak_pos_fract) / max_freq;
        filter[i3] = -(varargin_1 * varargin_1);
      }
    }
    coder::b_exp(filter);
    if (freq.size(0) != filter.size(0)) {
      binary_expand_op_4(filter, freq);
    }
    coder::b_abs(filter, b_disperse_freq);
    max_freq = coder::internal::maximum(b_disperse_freq);
    e_loop_ub = filter.size(0);
    end = (filter.size(0) / 2) << 1;
    d_loop_ub = end - 2;
    for (int i{0}; i <= d_loop_ub; i += 2) {
      r1 = _mm_loadu_pd(&filter[i]);
      _mm_storeu_pd(&filter[i], _mm_div_pd(r1, _mm_set1_pd(max_freq)));
    }
    for (int i{end}; i < e_loop_ub; i++) {
      filter[i] = filter[i] / max_freq;
    }
    b_loop_ub = filter.size(0);
    b_raw_tx.set_size(filter.size(0));
    d_loop_ub = filter.size(0);
    if (static_cast<int>(filter.size(0) < 2000)) {
      for (int i4{0}; i4 < b_loop_ub; i4++) {
        b_raw_tx[i4] = (filter[i4] > 0.01);
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i4 = 0; i4 < d_loop_ub; i4++) {
        b_raw_tx[i4] = (filter[i4] > 0.01);
      }
    }
    coder::eml_find(b_raw_tx, r);
    d_loop_ub = r.size(0);
    pitch_catch_indices.set_size(r.size(0));
    for (int i{0}; i < d_loop_ub; i++) {
      pitch_catch_indices[i] = r[i];
    }
    freq_i1 = coder::internal::minimum(pitch_catch_indices);
    peak_pos_fract = coder::internal::maximum(pitch_catch_indices);
    if (mode_shapes.size(0) == filter.size(0)) {
      b_filter.set_size(b_loop_ub, c_loop_ub);
      for (int i{0}; i < c_loop_ub; i++) {
        e_loop_ub = (filter.size(0) / 2) << 1;
        end = e_loop_ub - 2;
        for (int b_i{0}; b_i <= end; b_i += 2) {
          r1 = _mm_loadu_pd(&filter[b_i]);
          _mm_storeu_pd(&b_filter[b_i + b_filter.size(0) * i],
                        _mm_add_pd(_mm_set1_pd(0.0), r1));
        }
        for (int b_i{e_loop_ub}; b_i < b_loop_ub; b_i++) {
          b_filter[b_i + b_filter.size(0) * i] = filter[b_i];
        }
      }
      raw_freq_data.set_size(f_loop_ub, c_loop_ub);
      if (static_cast<int>(g_loop_ub < 2000)) {
        for (int i5{0}; i5 < g_loop_ub; i5++) {
          raw_freq_data[i5].re = b_filter[i5] * mode_shapes[i5].re;
          raw_freq_data[i5].im = b_filter[i5] * mode_shapes[i5].im;
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i5 = 0; i5 < g_loop_ub; i5++) {
          raw_freq_data[i5].re = b_filter[i5] * mode_shapes[i5].re;
          raw_freq_data[i5].im = b_filter[i5] * mode_shapes[i5].im;
        }
      }
    } else {
      binary_expand_op_3(raw_freq_data, mode_shapes, filter);
    }
  } else {
    coder::b_abs(mode_shapes, b_proc_tx_mode);
    b_loop_ub = b_proc_tx_mode.size(0);
    d_loop_ub = b_proc_tx_mode.size(1);
    coder::b_abs(mode_shapes, b_proc_tx_mode);
    e_loop_ub = b_proc_tx_mode.size(1);
    end = b_proc_tx_mode.size(0);
    b_proc_rx_mode.set_size(b_proc_tx_mode.size(1), b_proc_tx_mode.size(0));
    for (int i{0}; i < end; i++) {
      for (int b_i{0}; b_i < e_loop_ub; b_i++) {
        b_proc_rx_mode[b_i + b_proc_rx_mode.size(0) * i] =
            b_proc_tx_mode[i + b_proc_tx_mode.size(0) * b_i];
      }
    }
    b_filter = b_proc_rx_mode.reshape(d_loop_ub, b_loop_ub);
    coder::sum(b_filter, temp);
    coder::b_abs(temp, b_array_trans_pos_orientations);
    max_freq = coder::internal::maximum(b_array_trans_pos_orientations);
    temp.set_size(1, temp.size(1));
    e_loop_ub = temp.size(1) - 1;
    d_loop_ub = (temp.size(1) / 2) << 1;
    end = d_loop_ub - 2;
    for (int i{0}; i <= end; i += 2) {
      r1 = _mm_loadu_pd(&temp[i]);
      _mm_storeu_pd(&temp[i], _mm_div_pd(r1, _mm_set1_pd(max_freq)));
    }
    for (int i{d_loop_ub}; i <= e_loop_ub; i++) {
      temp[i] = temp[i] / max_freq;
    }
    e_loop_ub = temp.size(1);
    b_temp.set_size(1, temp.size(1));
    if (static_cast<int>(temp.size(1) < 2000)) {
      for (int i2{0}; i2 < e_loop_ub; i2++) {
        b_temp[i2] = (temp[i2] > 0.01);
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i2 = 0; i2 < e_loop_ub; i2++) {
        b_temp[i2] = (temp[i2] > 0.01);
      }
    }
    coder::b_eml_find(b_temp, r2);
    e_loop_ub = r2.size(1);
    temp.set_size(1, r2.size(1));
    for (int i{0}; i < e_loop_ub; i++) {
      temp[i] = r2[i];
    }
    freq_i1 = coder::internal::minimum(temp);
    peak_pos_fract = coder::internal::maximum(temp);
  }
  // build inverse mode shape matrix at frequency(s) required
  //  %array
  dv[0] = coder::internal::maximum(proc_tx_mode);
  dv[1] = coder::internal::maximum(proc_rx_mode);
  max_mode_index = coder::internal::maximum(dv);
  h_loop_ub = proc_tx_mode.size(0);
  i_loop_ub = raw_freq_data.size(1);
  j_loop_ub = opts_ms_matrix_calc_freqs.size(1);
  inv_mode_shapes.set_size(proc_tx_mode.size(0), raw_freq_data.size(1),
                           opts_ms_matrix_calc_freqs.size(1));
  loop_ub_tmp = proc_tx_mode.size(0) * raw_freq_data.size(1);
  d_loop_ub = loop_ub_tmp * opts_ms_matrix_calc_freqs.size(1);
  if (d_loop_ub - 1 >= 0) {
    std::memset(&inv_mode_shapes[0], 0,
                static_cast<unsigned int>(d_loop_ub) * sizeof(creal_T));
  }
  mode_shapes.set_size(raw_freq_data.size(1), proc_tx_mode.size(0));
  if (loop_ub_tmp - 1 >= 0) {
    std::memset(&mode_shapes[0], 0,
                static_cast<unsigned int>(loop_ub_tmp) * sizeof(creal_T));
  }
  k_loop_ub = static_cast<int>(max_mode_index) * disperse_ms_x.size(1) * 3;
  l_loop_ub = static_cast<int>(max_mode_index);
  m_loop_ub = disperse_ms_x.size(1);
  for (int ii{0}; ii < j_loop_ub; ii++) {
    // interpolate to get mode shapes and wavenumbers of all the modes at the
    // current frequency
    temp_mode_shape.set_size(static_cast<int>(max_mode_index),
                             disperse_ms_x.size(1), 3);
    if (k_loop_ub - 1 >= 0) {
      std::memset(&temp_mode_shape[0], 0,
                  static_cast<unsigned int>(k_loop_ub) * sizeof(creal_T));
    }
    pitch_catch_indices.set_size(static_cast<int>(max_mode_index));
    if (l_loop_ub - 1 >= 0) {
      std::memset(&pitch_catch_indices[0], 0,
                  static_cast<unsigned int>(l_loop_ub) * sizeof(double));
    }
    // Need to make this x, y and z (and perhaps normal and tangential also?)
    // so that the necessary direction can be selected when building the
    // matrix below. Also, this needs to take into account the phase
    // orientation of the transducers which is not currently used??
    for (int jj{0}; jj < loop_ub; jj++) {
      y = opts_ms_matrix_modes_to_use[jj];
      b_loop_ub = disperse_freq.size(0);
      b_disperse_freq.set_size(disperse_freq.size(0));
      for (int i{0}; i < b_loop_ub; i++) {
        b_disperse_freq[i] = disperse_freq[i + disperse_freq.size(0) *
                                                   (static_cast<int>(y) - 1)];
      }
      e_loop_ub = disperse_ms_x.size(0);
      c_mode_shapes.set_size(disperse_ms_x.size(0), m_loop_ub);
      for (int i{0}; i < m_loop_ub; i++) {
        for (int b_i{0}; b_i < e_loop_ub; b_i++) {
          c_mode_shapes[b_i + c_mode_shapes.size(0) * i] =
              disperse_ms_x[(b_i + disperse_ms_x.size(0) * i) +
                            disperse_ms_x.size(0) * disperse_ms_x.size(1) *
                                (static_cast<int>(y) - 1)];
        }
      }
      coder::interp1(b_disperse_freq, c_mode_shapes,
                     opts_ms_matrix_calc_freqs[ii], b_raw_freq_data);
      d_loop_ub = static_cast<int>(opts_ms_matrix_modes_to_use[jj]);
      for (int i{0}; i < m_loop_ub; i++) {
        temp_mode_shape[(d_loop_ub + temp_mode_shape.size(0) * i) - 1] =
            b_raw_freq_data[i];
      }
      y = opts_ms_matrix_modes_to_use[jj];
      b_disperse_freq.set_size(disperse_freq.size(0));
      for (int i{0}; i < b_loop_ub; i++) {
        b_disperse_freq[i] = disperse_freq[i + disperse_freq.size(0) *
                                                   (static_cast<int>(y) - 1)];
      }
      e_loop_ub = disperse_ms_y.size(0);
      end = disperse_ms_y.size(1);
      c_mode_shapes.set_size(disperse_ms_y.size(0), disperse_ms_y.size(1));
      for (int i{0}; i < end; i++) {
        for (int b_i{0}; b_i < e_loop_ub; b_i++) {
          c_mode_shapes[b_i + c_mode_shapes.size(0) * i] =
              disperse_ms_y[(b_i + disperse_ms_y.size(0) * i) +
                            disperse_ms_y.size(0) * disperse_ms_y.size(1) *
                                (static_cast<int>(y) - 1)];
        }
      }
      coder::interp1(b_disperse_freq, c_mode_shapes,
                     opts_ms_matrix_calc_freqs[ii], b_raw_freq_data);
      for (int i{0}; i < m_loop_ub; i++) {
        temp_mode_shape[((d_loop_ub + temp_mode_shape.size(0) * i) +
                         temp_mode_shape.size(0) * temp_mode_shape.size(1)) -
                        1] = b_raw_freq_data[i];
      }
      y = opts_ms_matrix_modes_to_use[jj];
      b_disperse_freq.set_size(disperse_freq.size(0));
      for (int i{0}; i < b_loop_ub; i++) {
        b_disperse_freq[i] = disperse_freq[i + disperse_freq.size(0) *
                                                   (static_cast<int>(y) - 1)];
      }
      e_loop_ub = disperse_ms_z.size(0);
      end = disperse_ms_z.size(1);
      c_mode_shapes.set_size(disperse_ms_z.size(0), disperse_ms_z.size(1));
      for (int i{0}; i < end; i++) {
        for (int b_i{0}; b_i < e_loop_ub; b_i++) {
          c_mode_shapes[b_i + c_mode_shapes.size(0) * i] =
              disperse_ms_z[(b_i + disperse_ms_z.size(0) * i) +
                            disperse_ms_z.size(0) * disperse_ms_z.size(1) *
                                (static_cast<int>(y) - 1)];
        }
      }
      coder::interp1(b_disperse_freq, c_mode_shapes,
                     opts_ms_matrix_calc_freqs[ii], b_raw_freq_data);
      for (int i{0}; i < m_loop_ub; i++) {
        temp_mode_shape[((d_loop_ub + temp_mode_shape.size(0) * i) +
                         temp_mode_shape.size(0) * temp_mode_shape.size(1) *
                             2) -
                        1] = b_raw_freq_data[i];
      }
      y = opts_ms_matrix_modes_to_use[jj];
      b_disperse_freq.set_size(disperse_freq.size(0));
      for (int i{0}; i < b_loop_ub; i++) {
        b_disperse_freq[i] = disperse_freq[i + disperse_freq.size(0) *
                                                   (static_cast<int>(y) - 1)];
      }
      e_loop_ub = disperse_waveno.size(0);
      b_proc_tx_dir.set_size(disperse_waveno.size(0));
      for (int i{0}; i < e_loop_ub; i++) {
        b_proc_tx_dir[i] = disperse_waveno[i + disperse_waveno.size(0) *
                                                   (static_cast<int>(y) - 1)];
      }
      pitch_catch_indices[d_loop_ub - 1] = coder::interp1(
          b_disperse_freq, b_proc_tx_dir, opts_ms_matrix_calc_freqs[ii]);
    }
    // build the mode shape matrix at this frequency, taking into account the
    // orientation of the transducers
    for (int b_i{0}; b_i < h_loop_ub; b_i++) {
      for (int iii{0}; iii < i_loop_ub; iii++) {
        creal_T b_temp_mode_shape[3];
        creal_T c_temp_mode_shape[3];
        e_loop_ub = static_cast<int>(proc_tx_mode[b_i]) - 1;
        y = pitch_catch_indices[e_loop_ub];
        d_loop_ub = static_cast<int>(raw_tx[iii]) - 1;
        max_freq =
            array_row_pos[static_cast<int>(array_trans_row[d_loop_ub]) - 1];
        b_y.re = proc_tx_dir[b_i] * (max_freq * (y * 0.0));
        b_y.im = proc_tx_dir[b_i] * (max_freq * y);
        coder::b_exp(b_y);
        b_loop_ub = static_cast<int>(proc_rx_mode[b_i]) - 1;
        y = pitch_catch_indices[b_loop_ub];
        g_loop_ub = static_cast<int>(raw_rx[iii]) - 1;
        max_freq =
            array_row_pos[static_cast<int>(array_trans_row[g_loop_ub]) - 1];
        dc.re = proc_rx_dir[b_i] * (max_freq * (y * 0.0));
        dc.im = proc_rx_dir[b_i] * (max_freq * y);
        coder::b_exp(dc);
        end = static_cast<int>(
            array_trans_node_list[static_cast<int>(array_trans_pos[d_loop_ub]) -
                                  1]);
        e_loop_ub += temp_mode_shape.size(0) * (end - 1);
        b_temp_mode_shape[0] = temp_mode_shape[e_loop_ub];
        end = temp_mode_shape.size(0) * temp_mode_shape.size(1);
        b_temp_mode_shape[1] = temp_mode_shape[e_loop_ub + end];
        c_loop_ub = end * 2;
        b_temp_mode_shape[2] = temp_mode_shape[e_loop_ub + c_loop_ub];
        f_loop_ub = array_trans_pos_orientations.size(1);
        b_array_trans_pos_orientations.set_size(
            1, array_trans_pos_orientations.size(1));
        for (int i{0}; i < f_loop_ub; i++) {
          b_array_trans_pos_orientations[i] = array_trans_pos_orientations
              [d_loop_ub + array_trans_pos_orientations.size(0) * i];
        }
        e_loop_ub = static_cast<int>(
            array_trans_node_list[static_cast<int>(array_trans_pos[g_loop_ub]) -
                                  1]);
        e_loop_ub = b_loop_ub + temp_mode_shape.size(0) * (e_loop_ub - 1);
        c_temp_mode_shape[0] = temp_mode_shape[e_loop_ub];
        c_temp_mode_shape[1] = temp_mode_shape[e_loop_ub + end];
        c_temp_mode_shape[2] = temp_mode_shape[e_loop_ub + c_loop_ub];
        temp.set_size(1, array_trans_pos_orientations.size(1));
        for (int i{0}; i < f_loop_ub; i++) {
          temp[i] = array_trans_pos_orientations
              [g_loop_ub + array_trans_pos_orientations.size(0) * i];
        }
        creal_T dc1;
        creal_T dc2;
        dc1 = coder::dot(b_temp_mode_shape, b_array_trans_pos_orientations);
        dc2 = coder::dot(c_temp_mode_shape, temp);
        y = dc1.re * dc2.re - dc1.im * dc2.im;
        max_freq = dc1.re * dc2.im + dc1.im * dc2.re;
        re = y * b_y.re - max_freq * b_y.im;
        y = y * b_y.im + max_freq * b_y.re;
        e_loop_ub = iii + mode_shapes.size(0) * b_i;
        mode_shapes[e_loop_ub].re = re * dc.re - y * dc.im;
        mode_shapes[e_loop_ub].im = re * dc.im + y * dc.re;
      }
    }
    for (int i{0}; i < loop_ub_tmp; i++) {
      if (std::isnan(mode_shapes[i].re) || std::isnan(mode_shapes[i].im)) {
        mode_shapes[i].re = 0.0;
        mode_shapes[i].im = 0.0;
      }
      if (std::isinf(mode_shapes[i].re) || std::isinf(mode_shapes[i].im)) {
        mode_shapes[i].re = 0.0;
        mode_shapes[i].im = 0.0;
      }
    }
    coder::pinv(mode_shapes, c_mode_shapes);
    for (int i{0}; i < i_loop_ub; i++) {
      for (int b_i{0}; b_i < h_loop_ub; b_i++) {
        inv_mode_shapes[(b_i + inv_mode_shapes.size(0) * i) +
                        inv_mode_shapes.size(0) * inv_mode_shapes.size(1) *
                            ii] = c_mode_shapes[b_i + h_loop_ub * i];
      }
    }
  }
  //  %array
  // do the mode extraction
  // actually do the multiplication to convert the raw freq domain data
  // to mode extracted freq domain data by one of two methods (single frequency
  // mode shapes or interpolated frequency)
  proc_freq_data.set_size(raw_freq_data.size(0), proc_tx_mode.size(0));
  d_loop_ub = raw_freq_data.size(0) * inv_mode_shapes.size(0);
  if (d_loop_ub - 1 >= 0) {
    std::memset(&proc_freq_data[0], 0,
                static_cast<unsigned int>(d_loop_ub) * sizeof(creal_T));
  }
  //  if length(size(inv_mode_shapes)) < 3
  if (opts_ms_matrix_calc_freqs.size(1) == 1) {
    mode_shapes.set_size(proc_tx_mode.size(0), raw_freq_data.size(1));
    for (int i{0}; i < i_loop_ub; i++) {
      for (int b_i{0}; b_i < h_loop_ub; b_i++) {
        mode_shapes[b_i + mode_shapes.size(0) * i] =
            inv_mode_shapes[b_i + inv_mode_shapes.size(0) * i];
      }
    }
    if (!(opts_ms_matrix_apply_as_time_shift != 0.0)) {
      // normal frequency domain processing
      if (freq_i1 > peak_pos_fract) {
        b_loop_ub = -1;
        d_loop_ub = -1;
        f_loop_ub = 0;
        c_loop_ub = 0;
      } else {
        b_loop_ub = static_cast<int>(freq_i1) - 2;
        d_loop_ub = static_cast<int>(peak_pos_fract) - 1;
        f_loop_ub = static_cast<int>(freq_i1) - 1;
        c_loop_ub = static_cast<int>(peak_pos_fract);
      }
      d_loop_ub -= b_loop_ub;
      c_raw_freq_data.set_size(d_loop_ub, proc_tx_mode.size(0));
      for (int iii{0}; iii < h_loop_ub; iii++) {
        for (int i{0}; i < d_loop_ub; i++) {
          e_loop_ub = i + c_raw_freq_data.size(0) * iii;
          c_raw_freq_data[e_loop_ub].re = 0.0;
          c_raw_freq_data[e_loop_ub].im = 0.0;
        }
        for (int i{0}; i < i_loop_ub; i++) {
          for (int b_i{0}; b_i < d_loop_ub; b_i++) {
            e_loop_ub = ((b_loop_ub + b_i) + raw_freq_data.size(0) * i) + 1;
            y = raw_freq_data[e_loop_ub].re;
            end = iii + inv_mode_shapes.size(0) * i;
            max_freq = inv_mode_shapes[end].im;
            peak_pos_fract = raw_freq_data[e_loop_ub].im;
            re = inv_mode_shapes[end].re;
            e_loop_ub = b_i + c_raw_freq_data.size(0) * iii;
            c_raw_freq_data[e_loop_ub].re =
                c_raw_freq_data[e_loop_ub].re +
                (y * re - peak_pos_fract * max_freq);
            c_raw_freq_data[e_loop_ub].im =
                c_raw_freq_data[e_loop_ub].im +
                (y * max_freq + peak_pos_fract * re);
          }
        }
      }
      b_loop_ub = c_loop_ub - f_loop_ub;
      for (int i{0}; i < h_loop_ub; i++) {
        for (int b_i{0}; b_i < b_loop_ub; b_i++) {
          proc_freq_data[(f_loop_ub + b_i) + proc_freq_data.size(0) * i] =
              c_raw_freq_data[b_i + b_loop_ub * i];
        }
      }
    } else {
      // simulated time domain processing
      coder::angle(mode_shapes, b_proc_tx_mode);
      coder::b_abs(mode_shapes, b_proc_rx_mode);
      if (opts_ms_matrix_allow_neg_amps != 0.0) {
        d_loop_ub = b_proc_tx_mode.size(0);
        b_loop_ub = b_proc_tx_mode.size(1);
        c_proc_tx_mode.set_size(b_proc_tx_mode.size(0), b_proc_tx_mode.size(1));
        f_loop_ub = b_proc_tx_mode.size(0) * b_proc_tx_mode.size(1);
        c_loop_ub = (f_loop_ub < 2000);
        if (c_loop_ub) {
          for (int i6{0}; i6 < f_loop_ub; i6++) {
            c_proc_tx_mode[i6] = (b_proc_tx_mode[i6] > 1.5707963267948966);
          }
        } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

          for (int i6 = 0; i6 < f_loop_ub; i6++) {
            c_proc_tx_mode[i6] = (b_proc_tx_mode[i6] > 1.5707963267948966);
          }
        }
        coder::c_eml_find(c_proc_tx_mode, r);
        end = r.size(0);
        pitch_catch_indices.set_size(r.size(0));
        for (int i{0}; i < end; i++) {
          pitch_catch_indices[i] = r[i];
        }
        r.set_size(r.size(0));
        for (int i{0}; i < end; i++) {
          r[i] = static_cast<int>(pitch_catch_indices[i]);
        }
        b_proc_tx_dir.set_size(end);
        e_loop_ub = (r.size(0) < 2000);
        if (e_loop_ub) {
          for (int i7{0}; i7 < end; i7++) {
            b_proc_tx_dir[i7] = b_proc_tx_mode[r[i7] - 1] - 3.1415926535897931;
          }
        } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

          for (int i7 = 0; i7 < end; i7++) {
            b_proc_tx_dir[i7] = b_proc_tx_mode[r[i7] - 1] - 3.1415926535897931;
          }
        }
        for (int i{0}; i < end; i++) {
          b_proc_tx_mode[r[i] - 1] = b_proc_tx_dir[i];
        }
        r.set_size(end);
        for (int i{0}; i < end; i++) {
          r[i] = static_cast<int>(pitch_catch_indices[i]);
        }
        b_proc_tx_dir.set_size(end);
        if (e_loop_ub) {
          for (int i8{0}; i8 < end; i8++) {
            b_proc_tx_dir[i8] = -b_proc_rx_mode[r[i8] - 1];
          }
        } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

          for (int i8 = 0; i8 < end; i8++) {
            b_proc_tx_dir[i8] = -b_proc_rx_mode[r[i8] - 1];
          }
        }
        for (int i{0}; i < end; i++) {
          b_proc_rx_mode[r[i] - 1] = b_proc_tx_dir[i];
        }
        c_proc_tx_mode.set_size(d_loop_ub, b_loop_ub);
        if (c_loop_ub) {
          for (int i9{0}; i9 < f_loop_ub; i9++) {
            c_proc_tx_mode[i9] = (b_proc_tx_mode[i9] < -1.5707963267948966);
          }
        } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

          for (int i9 = 0; i9 < f_loop_ub; i9++) {
            c_proc_tx_mode[i9] = (b_proc_tx_mode[i9] < -1.5707963267948966);
          }
        }
        coder::c_eml_find(c_proc_tx_mode, r);
        e_loop_ub = r.size(0);
        pitch_catch_indices.set_size(r.size(0));
        for (int i{0}; i < e_loop_ub; i++) {
          pitch_catch_indices[i] = r[i];
        }
        r.set_size(r.size(0));
        for (int i{0}; i < e_loop_ub; i++) {
          r[i] = static_cast<int>(pitch_catch_indices[i]);
        }
        b_proc_tx_dir.set_size(e_loop_ub);
        d_loop_ub = (r.size(0) < 2000);
        if (d_loop_ub) {
          for (int i11{0}; i11 < e_loop_ub; i11++) {
            b_proc_tx_dir[i11] =
                b_proc_tx_mode[r[i11] - 1] + 3.1415926535897931;
          }
        } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

          for (int i11 = 0; i11 < e_loop_ub; i11++) {
            b_proc_tx_dir[i11] =
                b_proc_tx_mode[r[i11] - 1] + 3.1415926535897931;
          }
        }
        for (int i{0}; i < e_loop_ub; i++) {
          b_proc_tx_mode[r[i] - 1] = b_proc_tx_dir[i];
        }
        r.set_size(e_loop_ub);
        for (int i{0}; i < e_loop_ub; i++) {
          r[i] = static_cast<int>(pitch_catch_indices[i]);
        }
        b_proc_tx_dir.set_size(e_loop_ub);
        if (d_loop_ub) {
          for (int i12{0}; i12 < e_loop_ub; i12++) {
            b_proc_tx_dir[i12] = -b_proc_rx_mode[r[i12] - 1];
          }
        } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

          for (int i12 = 0; i12 < e_loop_ub; i12++) {
            b_proc_tx_dir[i12] = -b_proc_rx_mode[r[i12] - 1];
          }
        }
        for (int i{0}; i < e_loop_ub; i++) {
          b_proc_rx_mode[r[i] - 1] = b_proc_tx_dir[i];
        }
      }
      b_array_trans_pos_orientations.set_size(1, 1);
      b_array_trans_pos_orientations[0] =
          6.2831853071795862 * opts_ms_matrix_calc_freqs[0];
      coder::internal::mrdiv(b_proc_tx_mode, b_array_trans_pos_orientations,
                             pitch_catch_indices);
      if (opts_ms_matrix_time_step_size > 0.0) {
        d_loop_ub = pitch_catch_indices.size(0);
        e_loop_ub = (pitch_catch_indices.size(0) / 2) << 1;
        end = e_loop_ub - 2;
        for (int i{0}; i <= end; i += 2) {
          r1 = _mm_loadu_pd(&pitch_catch_indices[i]);
          _mm_storeu_pd(
              &pitch_catch_indices[i],
              _mm_div_pd(r1, _mm_set1_pd(opts_ms_matrix_time_step_size)));
        }
        for (int i{e_loop_ub}; i < d_loop_ub; i++) {
          pitch_catch_indices[i] =
              pitch_catch_indices[i] / opts_ms_matrix_time_step_size;
        }
        coder::b_round(pitch_catch_indices);
        d_loop_ub = pitch_catch_indices.size(0);
        e_loop_ub = (pitch_catch_indices.size(0) / 2) << 1;
        end = e_loop_ub - 2;
        for (int i{0}; i <= end; i += 2) {
          r1 = _mm_loadu_pd(&pitch_catch_indices[i]);
          _mm_storeu_pd(
              &pitch_catch_indices[i],
              _mm_mul_pd(r1, _mm_set1_pd(opts_ms_matrix_time_step_size)));
        }
        for (int i{e_loop_ub}; i < d_loop_ub; i++) {
          pitch_catch_indices[i] =
              pitch_catch_indices[i] * opts_ms_matrix_time_step_size;
        }
      }
      c_loop_ub = static_cast<int>(peak_pos_fract + (1.0 - freq_i1));
      if (c_loop_ub - 1 >= 0) {
        n_loop_ub = pitch_catch_indices.size(0);
      }
      for (int iii{0}; iii < c_loop_ub; iii++) {
        max_mode_index = freq_i1 + static_cast<double>(iii);
        y = freq[static_cast<int>(max_mode_index) - 1];
        b_y.re = y * 0.0;
        b_y.im = y * 6.2831853071795862;
        b_mode_shapes.set_size(pitch_catch_indices.size(0));
        for (int i{0}; i < n_loop_ub; i++) {
          b_mode_shapes[i].re = pitch_catch_indices[i] * b_y.re;
          b_mode_shapes[i].im = pitch_catch_indices[i] * b_y.im;
        }
        coder::b_exp(b_mode_shapes);
        b_loop_ub = b_proc_rx_mode.size(0);
        if (b_proc_rx_mode.size(0) == b_mode_shapes.size(0)) {
          e_loop_ub = b_proc_rx_mode.size(1);
          c_mode_shapes.set_size(b_proc_rx_mode.size(1),
                                 b_proc_rx_mode.size(0));
          for (int i{0}; i < b_loop_ub; i++) {
            for (int b_i{0}; b_i < e_loop_ub; b_i++) {
              end = b_i + c_mode_shapes.size(0) * i;
              c_mode_shapes[end].re =
                  b_proc_rx_mode[i + b_proc_rx_mode.size(0) * b_i] *
                  b_mode_shapes[i].re;
              c_mode_shapes[end].im =
                  b_proc_rx_mode[i + b_proc_rx_mode.size(0) * b_i] *
                  b_mode_shapes[i].im;
            }
          }
          e_loop_ub = raw_freq_data.size(1);
          b_raw_freq_data.set_size(1, b_proc_rx_mode.size(0));
          for (int i{0}; i < b_loop_ub; i++) {
            b_raw_freq_data[i].re = 0.0;
            b_raw_freq_data[i].im = 0.0;
            for (int b_i{0}; b_i < e_loop_ub; b_i++) {
              end = (static_cast<int>(max_mode_index) +
                     raw_freq_data.size(0) * b_i) -
                    1;
              y = raw_freq_data[end].re;
              d_loop_ub = b_i + c_mode_shapes.size(0) * i;
              max_freq = c_mode_shapes[d_loop_ub].im;
              re = raw_freq_data[end].im;
              peak_pos_fract = c_mode_shapes[d_loop_ub].re;
              b_raw_freq_data[i].re =
                  b_raw_freq_data[i].re + (y * peak_pos_fract - re * max_freq);
              b_raw_freq_data[i].im =
                  b_raw_freq_data[i].im + (y * max_freq + re * peak_pos_fract);
            }
          }
          d_loop_ub = proc_freq_data.size(1);
          for (int i{0}; i < d_loop_ub; i++) {
            proc_freq_data[(static_cast<int>(max_mode_index) +
                            proc_freq_data.size(0) * i) -
                           1] = b_raw_freq_data[i];
          }
        } else {
          binary_expand_op_2(proc_freq_data, max_mode_index, raw_freq_data,
                             b_proc_rx_mode, b_mode_shapes);
        }
      }
    }
  } else {
    d_loop_ub = static_cast<int>(peak_pos_fract + (1.0 - freq_i1));
    for (int jj{0}; jj < d_loop_ub; jj++) {
      y = freq_i1 + static_cast<double>(jj);
      mode_shapes.set_size(h_loop_ub, i_loop_ub);
      if (loop_ub_tmp - 1 >= 0) {
        std::memset(&mode_shapes[0], 0,
                    static_cast<unsigned int>(loop_ub_tmp) * sizeof(creal_T));
      }
      for (int iii{0}; iii < h_loop_ub; iii++) {
        b_inv_mode_shapes.set_size(1, i_loop_ub, j_loop_ub);
        for (int i{0}; i < j_loop_ub; i++) {
          for (int b_i{0}; b_i < i_loop_ub; b_i++) {
            b_inv_mode_shapes[b_i + b_inv_mode_shapes.size(1) * i] =
                inv_mode_shapes[(iii + inv_mode_shapes.size(0) * b_i) +
                                inv_mode_shapes.size(0) *
                                    inv_mode_shapes.size(1) * i];
          }
        }
        coder::squeeze(b_inv_mode_shapes, c_mode_shapes);
        e_loop_ub = c_mode_shapes.size(1);
        end = c_mode_shapes.size(0);
        c_raw_freq_data.set_size(c_mode_shapes.size(1), c_mode_shapes.size(0));
        for (int i{0}; i < end; i++) {
          for (int b_i{0}; b_i < e_loop_ub; b_i++) {
            c_raw_freq_data[b_i + c_raw_freq_data.size(0) * i] =
                c_mode_shapes[i + c_mode_shapes.size(0) * b_i];
          }
        }
        coder::interp1(opts_ms_matrix_calc_freqs, c_raw_freq_data,
                       freq[static_cast<int>(y) - 1], b_raw_freq_data);
        for (int i{0}; i < i_loop_ub; i++) {
          mode_shapes[iii + mode_shapes.size(0) * i] = b_raw_freq_data[i];
        }
      }
      for (int i{0}; i < loop_ub_tmp; i++) {
        if (std::isnan(mode_shapes[i].re) || std::isnan(mode_shapes[i].im)) {
          mode_shapes[i].re = 0.0;
          mode_shapes[i].im = 0.0;
        }
      }
      b_raw_freq_data.set_size(1, h_loop_ub);
      for (int i{0}; i < h_loop_ub; i++) {
        b_raw_freq_data[i].re = 0.0;
        b_raw_freq_data[i].im = 0.0;
        for (int b_i{0}; b_i < i_loop_ub; b_i++) {
          e_loop_ub = (static_cast<int>(y) + raw_freq_data.size(0) * b_i) - 1;
          max_freq = raw_freq_data[e_loop_ub].re;
          end = i + mode_shapes.size(0) * b_i;
          re = mode_shapes[end].im;
          peak_pos_fract = raw_freq_data[e_loop_ub].im;
          max_mode_index = mode_shapes[end].re;
          b_raw_freq_data[i].re =
              b_raw_freq_data[i].re +
              (max_freq * max_mode_index - peak_pos_fract * re);
          b_raw_freq_data[i].im =
              b_raw_freq_data[i].im +
              (max_freq * re + peak_pos_fract * max_mode_index);
        }
        proc_freq_data[(static_cast<int>(y) + proc_freq_data.size(0) * i) - 1] =
            b_raw_freq_data[i];
      }
    }
  }
  // Convert from freq to distance
  //  if opts_dispersion_compensation
  //      %TODO - will go directly from freq to dist
  //      %must remember to make sure modal_vgrs is generated in proc_data
  //      %for use with warping
  //  else
  // Convert from freq to time
  max_freq = 1.0 / (fft_pts * std::abs(freq[1] - freq[0]));
  if (std::isnan(fft_pts - 1.0)) {
    temp.set_size(1, 1);
    temp[0] = rtNaN;
  } else if (fft_pts - 1.0 < 0.0) {
    temp.set_size(temp.size(0), 0);
  } else {
    temp.set_size(1, static_cast<int>(fft_pts - 1.0) + 1);
    e_loop_ub = static_cast<int>(fft_pts - 1.0);
    for (int i{0}; i <= e_loop_ub; i++) {
      temp[i] = i;
    }
  }
  temp.set_size(1, temp.size(1));
  e_loop_ub = temp.size(1) - 1;
  d_loop_ub = (temp.size(1) / 2) << 1;
  end = d_loop_ub - 2;
  for (int i{0}; i <= end; i += 2) {
    r1 = _mm_loadu_pd(&temp[i]);
    _mm_storeu_pd(&temp[i], _mm_mul_pd(r1, _mm_set1_pd(max_freq)));
  }
  for (int i{d_loop_ub}; i <= e_loop_ub; i++) {
    temp[i] = temp[i] * max_freq;
  }
  coder::ifft(proc_freq_data, fft_pts, mode_shapes);
  // Convert from time to distance
  y = coder::internal::maximum(opts_ms_matrix_modes_to_use);
  end = static_cast<int>(coder::internal::maximum(opts_ms_matrix_modes_to_use));
  filter.set_size(static_cast<int>(y));
  if (end - 1 >= 0) {
    std::memset(&filter[0], 0, static_cast<unsigned int>(end) * sizeof(double));
  }
  pitch_catch_indices.set_size(static_cast<int>(y));
  if (end - 1 >= 0) {
    std::memset(&pitch_catch_indices[0], 0,
                static_cast<unsigned int>(end) * sizeof(double));
  }
  for (int b_i{0}; b_i < loop_ub; b_i++) {
    max_freq = opts_ms_matrix_modes_to_use[b_i];
    e_loop_ub = disperse_freq.size(0);
    b_disperse_freq.set_size(disperse_freq.size(0));
    for (int i{0}; i < e_loop_ub; i++) {
      b_disperse_freq[i] =
          disperse_freq[i + disperse_freq.size(0) *
                                (static_cast<int>(max_freq) - 1)];
    }
    d_loop_ub = disperse_vgr.size(0);
    b_proc_tx_dir.set_size(disperse_vgr.size(0));
    for (int i{0}; i < d_loop_ub; i++) {
      b_proc_tx_dir[i] = disperse_vgr[i + disperse_vgr.size(0) *
                                              (static_cast<int>(max_freq) - 1)];
    }
    max_freq = opts_ms_matrix_modes_to_use[b_i];
    filter[static_cast<int>(max_freq) - 1] =
        coder::interp1(b_disperse_freq, b_proc_tx_dir, opts_freq_filter);
    b_disperse_freq.set_size(disperse_freq.size(0));
    for (int i{0}; i < e_loop_ub; i++) {
      b_disperse_freq[i] =
          disperse_freq[i + disperse_freq.size(0) *
                                (static_cast<int>(max_freq) - 1)];
    }
    e_loop_ub = disperse_waveno.size(0);
    b_proc_tx_dir.set_size(disperse_waveno.size(0));
    for (int i{0}; i < e_loop_ub; i++) {
      b_proc_tx_dir[i] =
          disperse_waveno[i + disperse_waveno.size(0) *
                                  (static_cast<int>(max_freq) - 1)];
    }
    pitch_catch_indices[static_cast<int>(max_freq) - 1] =
        coder::interp1(b_disperse_freq, b_proc_tx_dir, opts_freq_filter);
  }
  modal_vgrs.set_size(1, static_cast<int>(y));
  if (end - 1 >= 0) {
    std::copy(&filter[0], &filter[end], &modal_vgrs[0]);
  }
  if (proc_tx_mode.size(0) == proc_rx_mode.size(0)) {
    b_proc_tx_dir.set_size(h_loop_ub);
    if (static_cast<int>(proc_tx_mode.size(0) < 2000)) {
      for (int i10{0}; i10 < h_loop_ub; i10++) {
        b_proc_tx_dir[i10] =
            1.0 / (1.0 / filter[static_cast<int>(proc_tx_mode[i10]) - 1] +
                   1.0 / filter[static_cast<int>(proc_rx_mode[i10]) - 1]);
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i10 = 0; i10 < h_loop_ub; i10++) {
        b_proc_tx_dir[i10] =
            1.0 / (1.0 / filter[static_cast<int>(proc_tx_mode[i10]) - 1] +
                   1.0 / filter[static_cast<int>(proc_rx_mode[i10]) - 1]);
      }
    }
    filter.set_size(h_loop_ub);
    if (h_loop_ub - 1 >= 0) {
      std::copy(&b_proc_tx_dir[0], &b_proc_tx_dir[h_loop_ub], &filter[0]);
    }
  } else {
    binary_expand_op_1(filter, proc_tx_mode, proc_rx_mode);
  }
  // set up distance axis
  max_freq = 1.0 / (2.0 * coder::internal::maximum(pitch_catch_indices));
  y = coder::internal::maximum(filter) * coder::internal::maximum(temp) /
      max_freq;
  if (std::abs(y) < 4.503599627370496E+15) {
    if (y >= 0.5) {
      y = std::floor(y + 0.5);
    } else if (y > -0.5) {
      y *= 0.0;
    } else {
      y = std::ceil(y - 0.5);
    }
  }
  if (std::isnan(y)) {
    b_array_trans_pos_orientations.set_size(1, 1);
    b_array_trans_pos_orientations[0] = rtNaN;
  } else if (y < 0.0) {
    b_array_trans_pos_orientations.set_size(1, 0);
  } else {
    b_array_trans_pos_orientations.set_size(1, static_cast<int>(y) + 1);
    e_loop_ub = static_cast<int>(y);
    for (int i{0}; i <= e_loop_ub; i++) {
      b_array_trans_pos_orientations[i] = i;
    }
  }
  e_loop_ub = b_array_trans_pos_orientations.size(1);
  proc_dist.set_size(b_array_trans_pos_orientations.size(1));
  d_loop_ub = (b_array_trans_pos_orientations.size(1) / 2) << 1;
  end = d_loop_ub - 2;
  for (int i{0}; i <= end; i += 2) {
    r1 = _mm_loadu_pd(&b_array_trans_pos_orientations[i]);
    _mm_storeu_pd(&proc_dist[i], _mm_mul_pd(r1, _mm_set1_pd(max_freq)));
  }
  for (int i{d_loop_ub}; i < e_loop_ub; i++) {
    proc_dist[i] = b_array_trans_pos_orientations[i] * max_freq;
  }
  //  disp(num2str(length(proc_data_out.dist)))
  c_loop_ub = proc_dist.size(0);
  f_loop_ub = proc_tx_mode.size(0);
  proc_dist_data.set_size(proc_dist.size(0), proc_tx_mode.size(0));
  e_loop_ub = proc_dist.size(0) * proc_tx_mode.size(0);
  for (int i{0}; i < e_loop_ub; i++) {
    proc_dist_data[i].re = 0.0;
    proc_dist_data[i].im = 0.0;
  }
  // interpolate from time data
  for (int b_i{0}; b_i < f_loop_ub; b_i++) {
    end = mode_shapes.size(0);
    b_mode_shapes.set_size(mode_shapes.size(0));
    for (int i{0}; i < end; i++) {
      b_mode_shapes[i] = mode_shapes[i + mode_shapes.size(0) * b_i];
    }
    max_freq = filter[b_i];
    d_loop_ub = temp.size(1);
    b_array_trans_pos_orientations.set_size(1, temp.size(1));
    e_loop_ub = (temp.size(1) / 2) << 1;
    end = e_loop_ub - 2;
    for (int i{0}; i <= end; i += 2) {
      r1 = _mm_loadu_pd(&temp[i]);
      _mm_storeu_pd(&b_array_trans_pos_orientations[i],
                    _mm_mul_pd(r1, _mm_set1_pd(max_freq)));
    }
    for (int i{e_loop_ub}; i < d_loop_ub; i++) {
      b_array_trans_pos_orientations[i] = temp[i] * max_freq;
    }
    coder::b_abs(b_mode_shapes, b_disperse_freq);
    coder::interp1(b_array_trans_pos_orientations, b_disperse_freq, proc_dist,
                   pitch_catch_indices);
    for (int i{0}; i < c_loop_ub; i++) {
      end = i + proc_dist_data.size(0) * b_i;
      proc_dist_data[end].re = pitch_catch_indices[i];
      proc_dist_data[end].im = 0.0;
    }
  }
  //  end
  // Warp distance axes if desired according to opts_manual_warps (vector of
  // warp factors for each mode)
  if (opts_manual_warps.size(1) != 0) {
    if (proc_tx_mode.size(0) == proc_rx_mode.size(0)) {
      temp.set_size(1, proc_tx_mode.size(0));
      end = proc_tx_mode.size(0);
      if (static_cast<int>(proc_tx_mode.size(0) < 2000)) {
        for (int i13{0}; i13 < f_loop_ub; i13++) {
          end = static_cast<int>(proc_tx_mode[i13]) - 1;
          max_freq = modal_vgrs[end];
          e_loop_ub = static_cast<int>(proc_rx_mode[i13]) - 1;
          y = modal_vgrs[e_loop_ub];
          temp[i13] = (1.0 / max_freq + 1.0 / y) /
                      (1.0 / (max_freq * opts_manual_warps[end]) +
                       1.0 / (y * opts_manual_warps[e_loop_ub]));
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
        temp_tmp_tmp, temp_tmp, b_temp_tmp_tmp, b_temp_tmp)

        for (int i13 = 0; i13 < end; i13++) {
          temp_tmp_tmp = static_cast<int>(proc_tx_mode[i13]) - 1;
          temp_tmp = modal_vgrs[temp_tmp_tmp];
          b_temp_tmp_tmp = static_cast<int>(proc_rx_mode[i13]) - 1;
          b_temp_tmp = modal_vgrs[b_temp_tmp_tmp];
          temp[i13] = (1.0 / temp_tmp + 1.0 / b_temp_tmp) /
                      (1.0 / (temp_tmp * opts_manual_warps[temp_tmp_tmp]) +
                       1.0 / (b_temp_tmp * opts_manual_warps[b_temp_tmp_tmp]));
        }
      }
    } else {
      binary_expand_op(temp, modal_vgrs, proc_tx_mode, proc_rx_mode,
                       opts_manual_warps);
    }
    for (int b_i{0}; b_i < f_loop_ub; b_i++) {
      max_freq = temp[b_i];
      b_proc_tx_dir.set_size(c_loop_ub);
      b_proc_dist_data.set_size(c_loop_ub);
      for (int i{0}; i < c_loop_ub; i++) {
        b_proc_tx_dir[i] = proc_dist[i] / max_freq;
        b_proc_dist_data[i] = proc_dist_data[i + proc_dist_data.size(0) * b_i];
      }
      coder::interp1(b_proc_tx_dir, b_proc_dist_data, proc_dist, b_mode_shapes);
      for (int i{0}; i < c_loop_ub; i++) {
        proc_dist_data[i + proc_dist_data.size(0) * b_i] = b_mode_shapes[i];
      }
    }
  }
}

//
// File trailer for fn_process_rail_data_DLL.cpp
//
// [EOF]
//
