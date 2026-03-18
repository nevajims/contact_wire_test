/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: eml_randn.c
 *
 * MATLAB Coder version            : 25.1
 * C/C++ source code generated on  : 12-Mar-2026 17:25:15
 */

/* Include Files */
#include "eml_randn.h"
#include "fn_process_rail_data_DLL_data.h"

/* Function Definitions */
/*
 * Arguments    : void
 * Return Type  : void
 */
void eml_randn_init(void)
{
  method = 0U;
  state[0] = 362436069U;
  state[1] = 521288629U;
}

/*
 * File trailer for eml_randn.c
 *
 * [EOF]
 */
