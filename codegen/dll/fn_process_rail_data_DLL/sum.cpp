//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: sum.cpp
//
// MATLAB Coder version            : 25.1
// C/C++ source code generated on  : 24-Mar-2026 22:30:21
//

// Include Files
#include "sum.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const array<double, 2U> &x
//                array<double, 2U> &y
// Return Type  : void
//
namespace coder {
void sum(const array<double, 2U> &x, array<double, 2U> &y)
{
  if ((x.size(0) == 0) || (x.size(1) == 0)) {
    int xblockoffset;
    y.set_size(1, x.size(1));
    xblockoffset = x.size(1);
    for (int k{0}; k < xblockoffset; k++) {
      y[k] = 0.0;
    }
  } else {
    int firstBlockLength;
    int lastBlockLength;
    int nblocks;
    int npages;
    npages = x.size(1);
    y.set_size(1, x.size(1));
    if (x.size(0) <= 1024) {
      firstBlockLength = x.size(0);
      lastBlockLength = 0;
      nblocks = 1;
    } else {
      firstBlockLength = 1024;
      nblocks = static_cast<int>(static_cast<unsigned int>(x.size(0)) >> 10);
      lastBlockLength = x.size(0) - (nblocks << 10);
      if (lastBlockLength > 0) {
        nblocks++;
      } else {
        lastBlockLength = 1024;
      }
    }
    for (int xi{0}; xi < npages; xi++) {
      int xpageoffset;
      xpageoffset = xi * x.size(0);
      y[xi] = x[xpageoffset];
      for (int k{2}; k <= firstBlockLength; k++) {
        y[xi] = y[xi] + x[(xpageoffset + k) - 1];
      }
      for (int k{2}; k <= nblocks; k++) {
        double bsum;
        int hi;
        int xblockoffset;
        xblockoffset = xpageoffset + ((k - 1) << 10);
        bsum = x[xblockoffset];
        if (k == nblocks) {
          hi = lastBlockLength;
        } else {
          hi = 1024;
        }
        for (int b_k{2}; b_k <= hi; b_k++) {
          bsum += x[(xblockoffset + b_k) - 1];
        }
        y[xi] = y[xi] + bsum;
      }
    }
  }
}

} // namespace coder

//
// File trailer for sum.cpp
//
// [EOF]
//
