//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: find.cpp
//
// MATLAB Coder version            : 25.1
// C/C++ source code generated on  : 24-Mar-2026 22:30:21
//

// Include Files
#include "find.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "omp.h"

// Function Definitions
//
// Arguments    : coder::array<int, 1U> &in1
//                const coder::array<long long, 1U> &in2
//                const coder::array<long long, 1U> &in3
// Return Type  : void
//
void binary_expand_op_6(coder::array<int, 1U> &in1,
                        const coder::array<long long, 1U> &in2,
                        const coder::array<long long, 1U> &in3)
{
  coder::array<boolean_T, 1U> b_in2;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  if (in3.size(0) == 1) {
    loop_ub = in2.size(0);
  } else {
    loop_ub = in3.size(0);
  }
  b_in2.set_size(loop_ub);
  stride_0_0 = (in2.size(0) != 1);
  stride_1_0 = (in3.size(0) != 1);
  if (static_cast<int>(loop_ub < 2000)) {
    for (int i{0}; i < loop_ub; i++) {
      b_in2[i] = (in2[i * stride_0_0] != in3[i * stride_1_0]);
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i = 0; i < loop_ub; i++) {
      b_in2[i] = (in2[i * stride_0_0] != in3[i * stride_1_0]);
    }
  }
  coder::eml_find(b_in2, in1);
}

//
// Arguments    : const array<boolean_T, 2U> &x
//                array<int, 2U> &i
// Return Type  : void
//
namespace coder {
void b_eml_find(const array<boolean_T, 2U> &x, array<int, 2U> &i)
{
  int idx;
  int ii;
  int nx;
  boolean_T exitg1;
  nx = x.size(1);
  idx = 0;
  i.set_size(1, x.size(1));
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii <= nx - 1)) {
    if (x[ii]) {
      idx++;
      i[idx - 1] = ii + 1;
      if (idx >= nx) {
        exitg1 = true;
      } else {
        ii++;
      }
    } else {
      ii++;
    }
  }
  if (x.size(1) == 1) {
    if (idx == 0) {
      i.set_size(1, 0);
    }
  } else {
    if (idx < 1) {
      idx = 0;
    }
    i.set_size(i.size(0), idx);
  }
}

//
// Arguments    : const array<boolean_T, 2U> &x
//                array<int, 1U> &i
// Return Type  : void
//
void c_eml_find(const array<boolean_T, 2U> &x, array<int, 1U> &i)
{
  int idx;
  int ii;
  int nx;
  boolean_T exitg1;
  nx = x.size(0) * x.size(1);
  idx = 0;
  i.set_size(nx);
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii <= nx - 1)) {
    if (x[ii]) {
      idx++;
      i[idx - 1] = ii + 1;
      if (idx >= nx) {
        exitg1 = true;
      } else {
        ii++;
      }
    } else {
      ii++;
    }
  }
  if (nx == 1) {
    if (idx == 0) {
      i.set_size(0);
    }
  } else {
    if (idx < 1) {
      idx = 0;
    }
    i.set_size(idx);
  }
}

//
// Arguments    : const array<boolean_T, 1U> &x
//                array<int, 1U> &i
// Return Type  : void
//
void eml_find(const array<boolean_T, 1U> &x, array<int, 1U> &i)
{
  int idx;
  int ii;
  int nx;
  boolean_T exitg1;
  nx = x.size(0);
  idx = 0;
  i.set_size(x.size(0));
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii <= nx - 1)) {
    if (x[ii]) {
      idx++;
      i[idx - 1] = ii + 1;
      if (idx >= nx) {
        exitg1 = true;
      } else {
        ii++;
      }
    } else {
      ii++;
    }
  }
  if (x.size(0) == 1) {
    if (idx == 0) {
      i.set_size(0);
    }
  } else {
    if (idx < 1) {
      idx = 0;
    }
    i.set_size(idx);
  }
}

} // namespace coder

//
// File trailer for find.cpp
//
// [EOF]
//
