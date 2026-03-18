/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: eml_rand_mt19937ar.c
 *
 * MATLAB Coder version            : 25.1
 * C/C++ source code generated on  : 12-Mar-2026 17:25:15
 */

/* Include Files */
#include "eml_rand_mt19937ar.h"

/* Function Definitions */
/*
 * Arguments    : unsigned int e_state[625]
 * Return Type  : void
 */
void eml_rand_mt19937ar(unsigned int e_state[625])
{
  int mti;
  unsigned int r;
  r = 5489U;
  e_state[0] = 5489U;
  for (mti = 0; mti < 623; mti++) {
    r = ((r ^ r >> 30U) * 1812433253U + (unsigned int)mti) + 1U;
    e_state[mti + 1] = r;
  }
  e_state[624] = 624U;
}

/*
 * Arguments    : unsigned int mt[625]
 *                unsigned int u[2]
 * Return Type  : void
 */
void genrand_uint32_vector(unsigned int mt[625], unsigned int u[2])
{
  int j;
  int kk;
  for (j = 0; j < 2; j++) {
    unsigned int mti;
    unsigned int y;
    mti = mt[624] + 1U;
    if (mti >= 625U) {
      for (kk = 0; kk < 227; kk++) {
        mti = (mt[kk] & 2147483648U) | (mt[kk + 1] & 2147483647U);
        if ((mti & 1U) == 0U) {
          mti >>= 1U;
        } else {
          mti = mti >> 1U ^ 2567483615U;
        }
        mt[kk] = mt[kk + 397] ^ mti;
      }
      for (kk = 0; kk < 396; kk++) {
        mti = (mt[kk + 227] & 2147483648U) | (mt[kk + 228] & 2147483647U);
        if ((mti & 1U) == 0U) {
          mti >>= 1U;
        } else {
          mti = mti >> 1U ^ 2567483615U;
        }
        mt[kk + 227] = mt[kk] ^ mti;
      }
      mti = (mt[623] & 2147483648U) | (mt[0] & 2147483647U);
      if ((mti & 1U) == 0U) {
        mti >>= 1U;
      } else {
        mti = mti >> 1U ^ 2567483615U;
      }
      mt[623] = mt[396] ^ mti;
      mti = 1U;
    }
    y = mt[(int)mti - 1];
    mt[624] = mti;
    y ^= y >> 11U;
    y ^= y << 7U & 2636928640U;
    y ^= y << 15U & 4022730752U;
    u[j] = y ^ y >> 18U;
  }
}

/*
 * File trailer for eml_rand_mt19937ar.c
 *
 * [EOF]
 */
