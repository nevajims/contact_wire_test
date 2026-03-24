//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xzlascl.h
//
// MATLAB Coder version            : 25.1
// C/C++ source code generated on  : 24-Mar-2026 22:30:21
//

#ifndef XZLASCL_H
#define XZLASCL_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace internal {
namespace reflapack {
void xzlascl(double cfrom, double cto, int m, int n, array<creal_T, 2U> &A,
             int lda);

void xzlascl(double cfrom, double cto, int m, array<double, 1U> &A);

} // namespace reflapack
} // namespace internal
} // namespace coder

#endif
//
// File trailer for xzlascl.h
//
// [EOF]
//
