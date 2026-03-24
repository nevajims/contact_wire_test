//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: _coder_fn_process_rail_data_DLL_mex.cpp
//
// MATLAB Coder version            : 25.1
// C/C++ source code generated on  : 24-Mar-2026 22:30:21
//

// Include Files
#include "_coder_fn_process_rail_data_DLL_mex.h"
#include "_coder_fn_process_rail_data_DLL_api.h"

// Function Definitions
//
// Arguments    : int32_T nlhs
//                mxArray *plhs[]
//                int32_T nrhs
//                const mxArray *prhs[]
// Return Type  : void
//
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  mexAtExit(&fn_process_rail_data_DLL_atexit);
  fn_process_rail_data_DLL_initialize();
  unsafe_fn_process_rail_data_DLL_mexFunction(nlhs, plhs, nrhs, prhs);
  fn_process_rail_data_DLL_terminate();
}

//
// Arguments    : void
// Return Type  : emlrtCTX
//
emlrtCTX mexFunctionCreateRootTLS()
{
  emlrtCreateRootTLSR2022a(&emlrtRootTLSGlobal, &emlrtContextGlobal, nullptr, 1,
                           nullptr, "windows-1252", true);
  return emlrtRootTLSGlobal;
}

//
// Arguments    : int32_T nlhs
//                mxArray *plhs[6]
//                int32_T nrhs
//                const mxArray *prhs[30]
// Return Type  : void
//
void unsafe_fn_process_rail_data_DLL_mexFunction(int32_T nlhs, mxArray *plhs[6],
                                                 int32_T nrhs,
                                                 const mxArray *prhs[30])
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  const mxArray *b_prhs[30];
  const mxArray *outputs[6];
  int32_T i1;
  st.tls = emlrtRootTLSGlobal;
  // Check for proper number of arguments.
  if (nrhs != 30) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 30, 4,
                        24, "fn_process_rail_data_DLL");
  }
  if (nlhs > 6) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 24,
                        "fn_process_rail_data_DLL");
  }
  // Call the function.
  for (int32_T i{0}; i < 30; i++) {
    b_prhs[i] = prhs[i];
  }
  fn_process_rail_data_DLL_api(b_prhs, nlhs, outputs);
  // Copy over outputs to the caller.
  if (nlhs < 1) {
    i1 = 1;
  } else {
    i1 = nlhs;
  }
  emlrtReturnArrays(i1, &plhs[0], &outputs[0]);
}

//
// File trailer for _coder_fn_process_rail_data_DLL_mex.cpp
//
// [EOF]
//
