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

emlrtRSInfo o_emlrtRSI = {
    20,                               /* lineNo */
    "eml_int_forloop_overflow_check", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_"
    "overflow_check.m" /* pathName */
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

emlrtRSInfo lb_emlrtRSI = {
    44,                           /* lineNo */
    "applyScalarFunctionInPlace", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\applyScalarFunctionInPlace.m" /* pathName */
};

emlrtRSInfo lc_emlrtRSI = {
    82,                    /* lineNo */
    "applyScalarFunction", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\applyScalarFunction.m" /* pathName */
};

emlrtRSInfo vd_emlrtRSI =
    {
        45,          /* lineNo */
        "vAllOrAny", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\vAllOrAny.m" /* pathName */
};

emlrtRSInfo wd_emlrtRSI =
    {
        121,                  /* lineNo */
        "flatVectorAllOrAny", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\vAllOrAny.m" /* pathName */
};

emlrtRSInfo ce_emlrtRSI = {
    15,      /* lineNo */
    "pchip", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\polyfun\\pchip.m" /* pathName
                                                                          */
};

emlrtRSInfo de_emlrtRSI = {
    32,      /* lineNo */
    "pchip", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\polyfun\\pchip.m" /* pathName
                                                                          */
};

emlrtRSInfo ee_emlrtRSI = {
    48,      /* lineNo */
    "pchip", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\polyfun\\pchip.m" /* pathName
                                                                          */
};

emlrtRSInfo ge_emlrtRSI = {
    60,      /* lineNo */
    "pchip", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\polyfun\\pchip.m" /* pathName
                                                                          */
};

emlrtRSInfo ie_emlrtRSI = {
    70,      /* lineNo */
    "pchip", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\polyfun\\pchip.m" /* pathName
                                                                          */
};

emlrtRSInfo le_emlrtRSI = {
    90,      /* lineNo */
    "pchip", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\polyfun\\pchip.m" /* pathName
                                                                          */
};

emlrtRSInfo me_emlrtRSI = {
    26,         /* lineNo */
    "pwchcore", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\polyfun\\private\\pwchco"
    "re.m" /* pathName */
};

emlrtRSInfo ve_emlrtRSI = {
    38,        /* lineNo */
    "squeeze", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\elmat\\squeeze.m" /* pathName
                                                                          */
};

omp_lock_t emlrtLockGlobal;

omp_nest_lock_t fn_process_rail_data_DLL_nestLockGlobal;

emlrtRTEInfo m_emlrtRTEI = {
    81,                  /* lineNo */
    13,                  /* colNo */
    "reshapeSizeChecks", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\reshapeSizeChecks.m" /* pName */
};

emlrtRTEInfo u_emlrtRTEI = {
    26,      /* lineNo */
    23,      /* colNo */
    "pchip", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\polyfun\\pchip.m" /* pName
                                                                          */
};

emlrtRTEInfo v_emlrtRTEI = {
    33,       /* lineNo */
    15,       /* colNo */
    "chckxy", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\polyfun\\private\\chckxy"
    ".m" /* pName */
};

emlrtRTEInfo w_emlrtRTEI = {
    37,       /* lineNo */
    15,       /* colNo */
    "chckxy", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\polyfun\\private\\chckxy"
    ".m" /* pName */
};

emlrtRTEInfo x_emlrtRTEI = {
    39,       /* lineNo */
    1,        /* colNo */
    "chckxy", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\polyfun\\private\\chckxy"
    ".m" /* pName */
};

emlrtRTEInfo y_emlrtRTEI = {
    43,       /* lineNo */
    19,       /* colNo */
    "chckxy", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\polyfun\\private\\chckxy"
    ".m" /* pName */
};

emlrtRTEInfo cb_emlrtRTEI = {
    45,          /* lineNo */
    13,          /* colNo */
    "infocheck", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\infocheck.m" /* pName */
};

emlrtRTEInfo db_emlrtRTEI = {
    48,          /* lineNo */
    13,          /* colNo */
    "infocheck", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\infocheck.m" /* pName */
};

emlrtRTEInfo xb_emlrtRTEI = {
    141,                        /* lineNo */
    28,                         /* colNo */
    "fn_process_rail_data_DLL", /* fName */
    "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m" /* pName
                                                                            */
};

emlrtRTEInfo he_emlrtRTEI = {
    30,                    /* lineNo */
    21,                    /* colNo */
    "applyScalarFunction", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\applyScalarFunction.m" /* pName */
};

emlrtRTEInfo lf_emlrtRTEI = {
    31,      /* lineNo */
    20,      /* colNo */
    "pchip", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\polyfun\\pchip.m" /* pName
                                                                          */
};

emlrtRTEInfo mf_emlrtRTEI = {
    46,      /* lineNo */
    22,      /* colNo */
    "pchip", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\polyfun\\pchip.m" /* pName
                                                                          */
};

emlrtRTEInfo nf_emlrtRTEI = {
    55,      /* lineNo */
    25,      /* colNo */
    "pchip", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\polyfun\\pchip.m" /* pName
                                                                          */
};

emlrtRTEInfo of_emlrtRTEI = {
    90,      /* lineNo */
    1,       /* colNo */
    "pchip", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\polyfun\\pchip.m" /* pName
                                                                          */
};

emlrtRTEInfo qf_emlrtRTEI = {
    31,      /* lineNo */
    1,       /* colNo */
    "pchip", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\polyfun\\pchip.m" /* pName
                                                                          */
};

emlrtRTEInfo rf_emlrtRTEI = {
    46,      /* lineNo */
    1,       /* colNo */
    "pchip", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\polyfun\\pchip.m" /* pName
                                                                          */
};

emlrtRTEInfo sf_emlrtRTEI = {
    55,      /* lineNo */
    1,       /* colNo */
    "pchip", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\polyfun\\pchip.m" /* pName
                                                                          */
};

emlrtRTEInfo gh_emlrtRTEI = {
    323,                        /* lineNo */
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
