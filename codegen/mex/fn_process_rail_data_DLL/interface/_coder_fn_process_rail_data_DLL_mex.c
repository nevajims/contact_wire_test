/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_fn_process_rail_data_DLL_mex.c
 *
 * Code generation for function '_coder_fn_process_rail_data_DLL_mex'
 *
 */

/* Include files */
#include "_coder_fn_process_rail_data_DLL_mex.h"
#include "_coder_fn_process_rail_data_DLL_api.h"
#include "fn_process_rail_data_DLL_data.h"
#include "fn_process_rail_data_DLL_initialize.h"
#include "fn_process_rail_data_DLL_terminate.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void fn_process_rail_data_DLL_mexFunction(int32_T nlhs, mxArray *plhs[6],
                                          int32_T nrhs, const mxArray *prhs[10])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *outputs[6];
  int32_T i;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 10) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 10, 4,
                        24, "fn_process_rail_data_DLL");
  }
  if (nlhs > 6) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 24,
                        "fn_process_rail_data_DLL");
  }
  /* Call the function. */
  fn_process_rail_data_DLL_api(prhs, nlhs, outputs);
  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    i = 1;
  } else {
    i = nlhs;
  }
  emlrtReturnArrays(i, &plhs[0], &outputs[0]);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  mexAtExit(&fn_process_rail_data_DLL_atexit);
  fn_process_rail_data_DLL_initialize();
  fn_process_rail_data_DLL_mexFunction(nlhs, plhs, nrhs, prhs);
  fn_process_rail_data_DLL_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2022a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL, "windows-1252", true);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_fn_process_rail_data_DLL_mex.c) */
