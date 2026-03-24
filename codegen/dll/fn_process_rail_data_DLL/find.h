//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: find.h
//
// MATLAB Coder version            : 25.1
// C/C++ source code generated on  : 24-Mar-2026 22:30:21
//

#ifndef FIND_H
#define FIND_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
void binary_expand_op_6(coder::array<int, 1U> &in1,
                        const coder::array<long long, 1U> &in2,
                        const coder::array<long long, 1U> &in3);

namespace coder {
void b_eml_find(const array<boolean_T, 2U> &x, array<int, 2U> &i);

void c_eml_find(const array<boolean_T, 2U> &x, array<int, 1U> &i);

void eml_find(const array<boolean_T, 1U> &x, array<int, 1U> &i);

} // namespace coder

#endif
//
// File trailer for find.h
//
// [EOF]
//
