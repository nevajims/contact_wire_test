/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: fn_process_rail_data_DLL_initialize.c
 *
 * MATLAB Coder version            : 25.1
 * C/C++ source code generated on  : 12-Mar-2026 17:25:15
 */

/* Include Files */
#include "fn_process_rail_data_DLL_initialize.h"
#include "eml_rand.h"
#include "eml_rand_mcg16807_stateful.h"
#include "eml_rand_mt19937ar_stateful.h"
#include "eml_rand_shr3cong_stateful.h"
#include "eml_randn.h"
#include "fn_process_rail_data_DLL_data.h"

/* Function Definitions */
/*
 * Arguments    : void
 * Return Type  : void
 */
void fn_process_rail_data_DLL_initialize(void)
{
  eml_randn_init();
  eml_rand_init();
  eml_rand_mcg16807_stateful_init();
  eml_rand_shr3cong_stateful_init();
  c_eml_rand_mt19937ar_stateful_i();
  isInitialized_fn_process_rail_data_DLL = true;
}

/*
 * File trailer for fn_process_rail_data_DLL_initialize.c
 *
 * [EOF]
 */
