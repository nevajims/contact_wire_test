//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: abs.h
//
// MATLAB Coder version            : 25.1
// C/C++ source code generated on  : 24-Mar-2026 22:30:21
//

#ifndef ABS_H
#define ABS_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
void b_abs(const array<double, 2U> &x, array<double, 2U> &y);

void b_abs(const array<double, 1U> &x, array<double, 1U> &y);

double b_abs(const creal_T x);

void b_abs(const array<creal_T, 2U> &x, array<double, 2U> &y);

void b_abs(const array<creal_T, 1U> &x, array<double, 1U> &y);

} // namespace coder

#endif
//
// File trailer for abs.h
//
// [EOF]
//
