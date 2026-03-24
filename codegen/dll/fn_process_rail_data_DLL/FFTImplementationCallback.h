//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: FFTImplementationCallback.h
//
// MATLAB Coder version            : 25.1
// C/C++ source code generated on  : 24-Mar-2026 22:30:21
//

#ifndef FFTIMPLEMENTATIONCALLBACK_H
#define FFTIMPLEMENTATIONCALLBACK_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Definitions
namespace coder {
namespace internal {
namespace fft {
class FFTImplementationCallback {
public:
  static int get_algo_sizes(int nfft, boolean_T useRadix2, int &nRows);
  static void r2br_r2dit_trig(const array<double, 2U> &x, int n1_unsigned,
                              const array<double, 2U> &costab,
                              const array<double, 2U> &sintab,
                              array<creal_T, 2U> &y);
  static void dobluesteinfft(const array<double, 2U> &x, int n2blue, int nfft,
                             const array<double, 2U> &costab,
                             const array<double, 2U> &sintab,
                             const array<double, 2U> &sintabinv,
                             array<creal_T, 2U> &y);
  static void r2br_r2dit_trig(const array<creal_T, 2U> &x, int n1_unsigned,
                              const array<double, 2U> &costab,
                              const array<double, 2U> &sintab,
                              array<creal_T, 2U> &y);
  static void dobluesteinfft(const array<creal_T, 2U> &x, int n2blue, int nfft,
                             const array<double, 2U> &costab,
                             const array<double, 2U> &sintab,
                             const array<double, 2U> &sintabinv,
                             array<creal_T, 2U> &y);

protected:
  static void r2br_r2dit_trig_impl(const array<creal_T, 1U> &x,
                                   int unsigned_nRows,
                                   const array<double, 2U> &costab,
                                   const array<double, 2U> &sintab,
                                   array<creal_T, 1U> &y);
  static void doHalfLengthRadix2(const array<double, 2U> &x, int xoffInit,
                                 array<creal_T, 1U> &y, int unsigned_nRows,
                                 const array<double, 2U> &costab,
                                 const array<double, 2U> &sintab);
  static void doHalfLengthBluestein(
      const array<double, 2U> &x, int xoffInit, array<creal_T, 1U> &y,
      int nrowsx, int nRows, int nfft, const array<creal_T, 1U> &wwc,
      const array<double, 2U> &costab, const array<double, 2U> &sintab,
      const array<double, 2U> &costabinv, const array<double, 2U> &sintabinv);
};

} // namespace fft
} // namespace internal
} // namespace coder

#endif
//
// File trailer for FFTImplementationCallback.h
//
// [EOF]
//
