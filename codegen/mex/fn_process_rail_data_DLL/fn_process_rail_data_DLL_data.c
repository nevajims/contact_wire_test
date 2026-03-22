/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * fn_process_rail_data_DLL_data.c
 *
 * Code generation for function 'fn_process_rail_data_DLL_data'
 *
 */

/* Include files */
#include "fn_process_rail_data_DLL_data.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;

const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;

emlrtContext emlrtContextGlobal = {
    true,                                                 /* bFirstTime */
    false,                                                /* bInitialized */
    131674U,                                              /* fVersionInfo */
    NULL,                                                 /* fErrorFunction */
    "fn_process_rail_data_DLL",                           /* fFunctionName */
    NULL,                                                 /* fRTCallStack */
    false,                                                /* bDebugMode */
    {2045744189U, 2170104910U, 2743257031U, 4284093946U}, /* fSigWrd */
    NULL                                                  /* fSigMem */
};

emlrtRSInfo n_emlrtRSI = {
    142,      /* lineNo */
    "mtimes", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "blas\\mtimes.m" /* pathName */
};

emlrtRSInfo o_emlrtRSI = {
    20,                               /* lineNo */
    "eml_int_forloop_overflow_check", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_"
    "overflow_check.m" /* pathName */
};

emlrtRSInfo p_emlrtRSI = {
    177,           /* lineNo */
    "mtimes_blas", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "blas\\mtimes.m" /* pathName */
};

emlrtRSInfo eb_emlrtRSI =
    {
        42,    /* lineNo */
        "fft", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
        "fft\\fft.m" /* pathName */
};

emlrtRSInfo fb_emlrtRSI =
    {
        73,                /* lineNo */
        "executeCallback", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
        "fft\\fft.m" /* pathName */
};

emlrtRSInfo gb_emlrtRSI = {
    44,                        /* lineNo */
    "Custom1DFFTCallback/fft", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\Custom1DFFTCallback.m" /* pathName */
};

emlrtRSInfo hb_emlrtRSI = {
    54,                            /* lineNo */
    "Custom1DFFTCallback/fftLoop", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\Custom1DFFTCallback.m" /* pathName */
};

emlrtRSInfo kb_emlrtRSI =
    {
        10,    /* lineNo */
        "exp", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\elfun\\exp.m" /* pathName
                                                                          */
};

emlrtRSInfo lb_emlrtRSI = {
    44,                           /* lineNo */
    "applyScalarFunctionInPlace", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\applyScalarFunctionInPlace.m" /* pathName */
};

emlrtRSInfo ce_emlrtRSI =
    {
        45,          /* lineNo */
        "vAllOrAny", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\vAllOrAny.m" /* pathName */
};

emlrtRSInfo de_emlrtRSI =
    {
        121,                  /* lineNo */
        "flatVectorAllOrAny", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\vAllOrAny.m" /* pathName */
};

emlrtRSInfo ie_emlrtRSI = {
    15,      /* lineNo */
    "pchip", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\polyfun\\pchip.m" /* pathName
                                                                          */
};

emlrtRSInfo je_emlrtRSI = {
    32,      /* lineNo */
    "pchip", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\polyfun\\pchip.m" /* pathName
                                                                          */
};

emlrtRSInfo ke_emlrtRSI = {
    48,      /* lineNo */
    "pchip", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\polyfun\\pchip.m" /* pathName
                                                                          */
};

emlrtRSInfo me_emlrtRSI = {
    60,      /* lineNo */
    "pchip", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\polyfun\\pchip.m" /* pathName
                                                                          */
};

emlrtRSInfo oe_emlrtRSI = {
    70,      /* lineNo */
    "pchip", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\polyfun\\pchip.m" /* pathName
                                                                          */
};

emlrtRSInfo re_emlrtRSI = {
    90,      /* lineNo */
    "pchip", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\polyfun\\pchip.m" /* pathName
                                                                          */
};

emlrtRSInfo se_emlrtRSI = {
    26,         /* lineNo */
    "pwchcore", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\polyfun\\private\\pwchco"
    "re.m" /* pathName */
};

emlrtRSInfo cf_emlrtRSI = {
    38,        /* lineNo */
    "squeeze", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\elmat\\squeeze.m" /* pathName
                                                                          */
};

omp_lock_t emlrtLockGlobal;

omp_nest_lock_t fn_process_rail_data_DLL_nestLockGlobal;

emlrtRTEInfo c_emlrtRTEI = {
    81,                  /* lineNo */
    13,                  /* colNo */
    "reshapeSizeChecks", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\reshapeSizeChecks.m" /* pName */
};

emlrtRTEInfo d_emlrtRTEI = {
    88,                  /* lineNo */
    23,                  /* colNo */
    "reshapeSizeChecks", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\reshapeSizeChecks.m" /* pName */
};

emlrtRTEInfo v_emlrtRTEI = {
    26,      /* lineNo */
    23,      /* colNo */
    "pchip", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\polyfun\\pchip.m" /* pName
                                                                          */
};

emlrtRTEInfo w_emlrtRTEI = {
    33,       /* lineNo */
    15,       /* colNo */
    "chckxy", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\polyfun\\private\\chckxy"
    ".m" /* pName */
};

emlrtRTEInfo x_emlrtRTEI = {
    37,       /* lineNo */
    15,       /* colNo */
    "chckxy", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\polyfun\\private\\chckxy"
    ".m" /* pName */
};

emlrtRTEInfo y_emlrtRTEI = {
    39,       /* lineNo */
    1,        /* colNo */
    "chckxy", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\polyfun\\private\\chckxy"
    ".m" /* pName */
};

emlrtRTEInfo ab_emlrtRTEI = {
    43,       /* lineNo */
    19,       /* colNo */
    "chckxy", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\polyfun\\private\\chckxy"
    ".m" /* pName */
};

emlrtRTEInfo vb_emlrtRTEI = {
    141,                        /* lineNo */
    28,                         /* colNo */
    "fn_process_rail_data_DLL", /* fName */
    "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m" /* pName
                                                                            */
};

emlrtRTEInfo pc_emlrtRTEI = {
    218,      /* lineNo */
    20,       /* colNo */
    "mtimes", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "blas\\mtimes.m" /* pName */
};

emlrtRTEInfo ye_emlrtRTEI = {
    31,      /* lineNo */
    20,      /* colNo */
    "pchip", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\polyfun\\pchip.m" /* pName
                                                                          */
};

emlrtRTEInfo af_emlrtRTEI = {
    46,      /* lineNo */
    22,      /* colNo */
    "pchip", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\polyfun\\pchip.m" /* pName
                                                                          */
};

emlrtRTEInfo bf_emlrtRTEI = {
    55,      /* lineNo */
    25,      /* colNo */
    "pchip", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\polyfun\\pchip.m" /* pName
                                                                          */
};

emlrtRTEInfo cf_emlrtRTEI = {
    90,      /* lineNo */
    1,       /* colNo */
    "pchip", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\polyfun\\pchip.m" /* pName
                                                                          */
};

emlrtRTEInfo ef_emlrtRTEI = {
    31,      /* lineNo */
    1,       /* colNo */
    "pchip", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\polyfun\\pchip.m" /* pName
                                                                          */
};

emlrtRTEInfo ff_emlrtRTEI = {
    46,      /* lineNo */
    1,       /* colNo */
    "pchip", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\polyfun\\pchip.m" /* pName
                                                                          */
};

emlrtRTEInfo gf_emlrtRTEI = {
    55,      /* lineNo */
    1,       /* colNo */
    "pchip", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\polyfun\\pchip.m" /* pName
                                                                          */
};

emlrtRTEInfo lg_emlrtRTEI = {
    322,                        /* lineNo */
    1,                          /* colNo */
    "fn_process_rail_data_DLL", /* fName */
    "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m" /* pName
                                                                            */
};

const creal_T dc = {
    0.0, /* re */
    0.0  /* im */
};

const creal_T dc1 = {
    1.0, /* re */
    0.0  /* im */
};

/* End of code generation (fn_process_rail_data_DLL_data.c) */
