//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: squeeze.cpp
//
// MATLAB Coder version            : 25.1
// C/C++ source code generated on  : 24-Mar-2026 22:30:21
//

// Include Files
#include "squeeze.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const array<creal_T, 3U> &a
//                array<creal_T, 2U> &b
// Return Type  : void
//
namespace coder {
void squeeze(const array<creal_T, 3U> &a, array<creal_T, 2U> &b)
{
  int szb[2];
  int j;
  szb[0] = 1;
  szb[1] = a.size(1);
  if (a.size(2) != 1) {
    j = 0;
    if (a.size(1) != 1) {
      j = 1;
      szb[0] = a.size(1);
    }
    if (a.size(2) != 1) {
      szb[j] = a.size(2);
    }
  }
  b.set_size(szb[0], szb[1]);
  j = szb[0] * szb[1];
  for (int i{0}; i < j; i++) {
    b[i] = a[i];
  }
}

} // namespace coder

//
// File trailer for squeeze.cpp
//
// [EOF]
//
