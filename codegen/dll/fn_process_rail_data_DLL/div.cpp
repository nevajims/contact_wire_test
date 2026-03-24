//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: div.cpp
//
// MATLAB Coder version            : 25.1
// C/C++ source code generated on  : 24-Mar-2026 22:30:21
//

// Include Files
#include "div.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "omp.h"

// Function Definitions
//
// Arguments    : coder::array<double, 2U> &in1
//                const coder::array<double, 2U> &in2
//                const coder::array<double, 1U> &in3
//                const coder::array<double, 1U> &in4
//                const coder::array<double, 2U> &in5
// Return Type  : void
//
void binary_expand_op(coder::array<double, 2U> &in1,
                      const coder::array<double, 2U> &in2,
                      const coder::array<double, 1U> &in3,
                      const coder::array<double, 1U> &in4,
                      const coder::array<double, 2U> &in5)
{
  double d2;
  double d3;
  int i3;
  int i4;
  int loop_ub;
  int stride_0_1;
  int stride_1_1;
  in1.set_size(1, in1.size(1));
  if (in4.size(0) == 1) {
    loop_ub = in3.size(0);
  } else {
    loop_ub = in4.size(0);
  }
  in1.set_size(in1.size(0), loop_ub);
  stride_0_1 = (in3.size(0) != 1);
  stride_1_1 = (in4.size(0) != 1);
  if (static_cast<int>(loop_ub < 2000)) {
    for (int i{0}; i < loop_ub; i++) {
      double d;
      double d1;
      int i1;
      int i2;
      i1 = static_cast<int>(in3[i * stride_0_1]) - 1;
      d = in2[i1];
      i2 = static_cast<int>(in4[i * stride_1_1]) - 1;
      d1 = in2[i2];
      in1[i] =
          (1.0 / d + 1.0 / d1) / (1.0 / (d * in5[i1]) + 1.0 / (d1 * in5[i2]));
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
        i3, d2, i4, d3)

    for (int i = 0; i < loop_ub; i++) {
      i3 = static_cast<int>(in3[i * stride_0_1]) - 1;
      d2 = in2[i3];
      i4 = static_cast<int>(in4[i * stride_1_1]) - 1;
      d3 = in2[i4];
      in1[i] =
          (1.0 / d2 + 1.0 / d3) / (1.0 / (d2 * in5[i3]) + 1.0 / (d3 * in5[i4]));
    }
  }
}

//
// Arguments    : coder::array<double, 1U> &in1
//                const coder::array<double, 1U> &in2
//                const coder::array<double, 1U> &in3
// Return Type  : void
//
void binary_expand_op_1(coder::array<double, 1U> &in1,
                        const coder::array<double, 1U> &in2,
                        const coder::array<double, 1U> &in3)
{
  coder::array<double, 1U> r;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  if (in3.size(0) == 1) {
    loop_ub = in2.size(0);
  } else {
    loop_ub = in3.size(0);
  }
  r.set_size(loop_ub);
  stride_0_0 = (in2.size(0) != 1);
  stride_1_0 = (in3.size(0) != 1);
  if (static_cast<int>(loop_ub < 2000)) {
    for (int i{0}; i < loop_ub; i++) {
      r[i] = 1.0 / (1.0 / in1[static_cast<int>(in2[i * stride_0_0]) - 1] +
                    1.0 / in1[static_cast<int>(in3[i * stride_1_0]) - 1]);
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i = 0; i < loop_ub; i++) {
      r[i] = 1.0 / (1.0 / in1[static_cast<int>(in2[i * stride_0_0]) - 1] +
                    1.0 / in1[static_cast<int>(in3[i * stride_1_0]) - 1]);
    }
  }
  in1.set_size(loop_ub);
  for (int i1{0}; i1 < loop_ub; i1++) {
    in1[i1] = r[i1];
  }
}

//
// File trailer for div.cpp
//
// [EOF]
//
