/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: main.c
 *
 * MATLAB Coder version            : 25.1
 * C/C++ source code generated on  : 12-Mar-2026 17:05:36
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/

/* Include Files */
#include "main.h"
#include "fn_process_rail_data_DLL.h"
#include "fn_process_rail_data_DLL_emxAPI.h"
#include "fn_process_rail_data_DLL_initialize.h"
#include "fn_process_rail_data_DLL_terminate.h"
#include "fn_process_rail_data_DLL_types.h"

/* Function Declarations */
static emxArray_int64_T *argInit_1xUnbounded_int64_T(void);

static emxArray_real_T *argInit_1xUnbounded_real_T(void);

static emxArray_int64_T *argInit_Unboundedx1_int64_T(void);

static emxArray_real_T *argInit_Unboundedx1_real_T(void);

static long long argInit_int64_T(void);

static double argInit_real_T(void);

static emxArray_real_T *c_argInit_UnboundedxUnbounded_r(void);

/* Function Definitions */
/*
 * Arguments    : void
 * Return Type  : emxArray_int64_T *
 */
static emxArray_int64_T *argInit_1xUnbounded_int64_T(void)
{
  emxArray_int64_T *result;
  long long *result_data;
  int idx1;
  /* Set the size of the array.
Change this size to the value that the application requires. */
  result = emxCreate_int64_T(1, 2);
  result_data = result->data;
  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < result->size[1U]; idx1++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result_data[idx1] = argInit_int64_T();
  }
  return result;
}

/*
 * Arguments    : void
 * Return Type  : emxArray_real_T *
 */
static emxArray_real_T *argInit_1xUnbounded_real_T(void)
{
  emxArray_real_T *result;
  double *result_data;
  int idx1;
  /* Set the size of the array.
Change this size to the value that the application requires. */
  result = emxCreate_real_T(1, 2);
  result_data = result->data;
  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < result->size[1U]; idx1++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result_data[idx1] = argInit_real_T();
  }
  return result;
}

/*
 * Arguments    : void
 * Return Type  : emxArray_int64_T *
 */
static emxArray_int64_T *argInit_Unboundedx1_int64_T(void)
{
  emxArray_int64_T *result;
  long long *result_data;
  int i = 2;
  int idx0;
  /* Set the size of the array.
Change this size to the value that the application requires. */
  result = emxCreateND_int64_T(1, &i);
  result_data = result->data;
  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < result->size[0U]; idx0++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result_data[idx0] = argInit_int64_T();
  }
  return result;
}

/*
 * Arguments    : void
 * Return Type  : emxArray_real_T *
 */
static emxArray_real_T *argInit_Unboundedx1_real_T(void)
{
  emxArray_real_T *result;
  double *result_data;
  int i = 2;
  int idx0;
  /* Set the size of the array.
Change this size to the value that the application requires. */
  result = emxCreateND_real_T(1, &i);
  result_data = result->data;
  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < result->size[0U]; idx0++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result_data[idx0] = argInit_real_T();
  }
  return result;
}

/*
 * Arguments    : void
 * Return Type  : long long
 */
static long long argInit_int64_T(void)
{
  return 0LL;
}

/*
 * Arguments    : void
 * Return Type  : double
 */
static double argInit_real_T(void)
{
  return 0.0;
}

/*
 * Arguments    : void
 * Return Type  : emxArray_real_T *
 */
static emxArray_real_T *c_argInit_UnboundedxUnbounded_r(void)
{
  emxArray_real_T *result;
  double *result_data;
  int idx0;
  int idx1;
  /* Set the size of the array.
Change this size to the value that the application requires. */
  result = emxCreate_real_T(2, 2);
  result_data = result->data;
  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < result->size[0U]; idx0++) {
    for (idx1 = 0; idx1 < result->size[1U]; idx1++) {
      /* Set the value of the array element.
Change this value to the value that the application requires. */
      result_data[idx0 + result->size[0] * idx1] = argInit_real_T();
    }
  }
  return result;
}

/*
 * Arguments    : int argc
 *                char **argv
 * Return Type  : int
 */
int main(int argc, char **argv)
{
  (void)argc;
  (void)argv;
  /* Initialize the application.
You do not need to do this more than one time. */
  fn_process_rail_data_DLL_initialize();
  /* Invoke the entry-point functions.
You can call entry-point functions multiple times. */
  main_fn_process_rail_data_DLL();
  /* Terminate the application.
You do not need to do this more than one time. */
  fn_process_rail_data_DLL_terminate();
  return 0;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_fn_process_rail_data_DLL(void)
{
  static double dist_data[101056];
  emxArray_int64_T *rx;
  emxArray_int64_T *trans_node_list;
  emxArray_int64_T *trans_pos;
  emxArray_int64_T *trans_row;
  emxArray_int64_T *tx;
  emxArray_real_T *b_time;
  emxArray_real_T *row_pos;
  emxArray_real_T *time_data;
  emxArray_real_T *trans_pos_orientations;
  double dist[3158];
  double rx_dir[32];
  double rx_mode[32];
  double tx_dir[32];
  double tx_mode[32];
  /* Initialize function 'fn_process_rail_data_DLL' input arguments. */
  /* Initialize function input argument 'time'. */
  b_time = argInit_Unboundedx1_real_T();
  /* Initialize function input argument 'time_data'. */
  time_data = c_argInit_UnboundedxUnbounded_r();
  /* Initialize function input argument 'tx'. */
  tx = argInit_Unboundedx1_int64_T();
  /* Initialize function input argument 'rx'. */
  rx = argInit_Unboundedx1_int64_T();
  /* Initialize function input argument 'row_pos'. */
  row_pos = argInit_1xUnbounded_real_T();
  /* Initialize function input argument 'trans_pos'. */
  trans_pos = argInit_1xUnbounded_int64_T();
  /* Initialize function input argument 'trans_row'. */
  trans_row = argInit_1xUnbounded_int64_T();
  /* Initialize function input argument 'trans_pos_orientations'. */
  trans_pos_orientations = c_argInit_UnboundedxUnbounded_r();
  /* Initialize function input argument 'trans_node_list'. */
  trans_node_list = argInit_1xUnbounded_int64_T();
  /* Call the entry-point 'fn_process_rail_data_DLL'. */
  fn_process_rail_data_DLL(b_time, time_data, tx, rx, row_pos, trans_pos,
                           trans_row, trans_pos_orientations, argInit_real_T(),
                           trans_node_list, tx_mode, rx_mode, tx_dir, rx_dir,
                           dist, dist_data);
  emxDestroyArray_int64_T(trans_node_list);
  emxDestroyArray_real_T(trans_pos_orientations);
  emxDestroyArray_int64_T(trans_row);
  emxDestroyArray_int64_T(trans_pos);
  emxDestroyArray_real_T(row_pos);
  emxDestroyArray_int64_T(rx);
  emxDestroyArray_int64_T(tx);
  emxDestroyArray_real_T(time_data);
  emxDestroyArray_real_T(b_time);
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
