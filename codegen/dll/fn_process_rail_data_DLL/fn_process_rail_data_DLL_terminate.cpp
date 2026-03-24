//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: fn_process_rail_data_DLL_terminate.cpp
//
// MATLAB Coder version            : 25.1
// C/C++ source code generated on  : 24-Mar-2026 22:30:21
//

// Include Files
#include "fn_process_rail_data_DLL_terminate.h"
#include "fn_process_rail_data_DLL_data.h"
#include "rt_nonfinite.h"
#include "omp.h"

// Function Definitions
//
// Arguments    : void
// Return Type  : void
//
void fn_process_rail_data_DLL_terminate()
{
  omp_destroy_nest_lock(&fn_process_rail_data_DLL_nestLockGlobal);
  isInitialized_fn_process_rail_data_DLL = false;
}

//
// File trailer for fn_process_rail_data_DLL_terminate.cpp
//
// [EOF]
//
