//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xaxpy.h
//
// MATLAB Coder version            : 25.1
// C/C++ source code generated on  : 24-Mar-2026 22:30:21
//

#ifndef XAXPY_H
#define XAXPY_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace internal {
namespace blas {
void xaxpy(int n, const creal_T a, const array<creal_T, 2U> &x, int ix0,
           array<creal_T, 1U> &y, int iy0);

void xaxpy(int n, const creal_T a, const array<creal_T, 1U> &x, int ix0,
           array<creal_T, 2U> &y, int iy0);

void xaxpy(int n, const creal_T a, int ix0, array<creal_T, 2U> &y, int iy0);

} // namespace blas
} // namespace internal
} // namespace coder

#endif
//
// File trailer for xaxpy.h
//
// [EOF]
//
