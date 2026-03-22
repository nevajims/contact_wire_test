/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * fn_process_rail_data_DLL_initialize.c
 *
 * Code generation for function 'fn_process_rail_data_DLL_initialize'
 *
 */

/* Include files */
#include "fn_process_rail_data_DLL_initialize.h"
#include "_coder_fn_process_rail_data_DLL_mex.h"
#include "fn_process_rail_data_DLL_data.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void fn_process_rail_data_DLL_once(void);

/* Function Definitions */
static void fn_process_rail_data_DLL_once(void)
{
  mex_InitInfAndNan();
}

void fn_process_rail_data_DLL_initialize(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2022b(&st);
  emlrtClearAllocCountR2012b(&st, false, 0U, NULL);
  emlrtEnterRtStackR2012b(&st);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    fn_process_rail_data_DLL_once();
  }
}

/* End of code generation (fn_process_rail_data_DLL_initialize.c) */
