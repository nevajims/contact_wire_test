/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * fn_process_rail_data_DLL.c
 *
 * Code generation for function 'fn_process_rail_data_DLL'
 *
 */

/* Include files */
#include "fn_process_rail_data_DLL.h"
#include "abs.h"
#include "div.h"
#include "dot.h"
#include "eml_int_forloop_overflow_check.h"
#include "exp.h"
#include "fft.h"
#include "find.h"
#include "fn_process_rail_data_DLL_data.h"
#include "fn_process_rail_data_DLL_emxutil.h"
#include "fn_process_rail_data_DLL_types.h"
#include "ifft.h"
#include "indexShapeCheck.h"
#include "interp1.h"
#include "linspace.h"
#include "mtimes.h"
#include "pinv.h"
#include "rt_nonfinite.h"
#include "squeeze.h"
#include "sum.h"
#include "blas.h"
#include "mwmathutil.h"
#include "omp.h"
#include <emmintrin.h>
#include <math.h>
#include <stddef.h>

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 44,    /* lineNo */
  "fn_process_rail_data_DLL",          /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 50,  /* lineNo */
  "fn_process_rail_data_DLL",          /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 52,  /* lineNo */
  "fn_process_rail_data_DLL",          /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 78,  /* lineNo */
  "fn_process_rail_data_DLL",          /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 83,  /* lineNo */
  "fn_process_rail_data_DLL",          /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 87,  /* lineNo */
  "fn_process_rail_data_DLL",          /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 95,  /* lineNo */
  "fn_process_rail_data_DLL",          /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 98,  /* lineNo */
  "fn_process_rail_data_DLL",          /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 105, /* lineNo */
  "fn_process_rail_data_DLL",          /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 118, /* lineNo */
  "fn_process_rail_data_DLL",          /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 120, /* lineNo */
  "fn_process_rail_data_DLL",          /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 129, /* lineNo */
  "fn_process_rail_data_DLL",          /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 94,  /* lineNo */
  "eml_mtimes_helper",                 /* fcnName */
  "C:\\Program Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m"/* pathName */
};

static emlrtRSInfo q_emlrtRSI = { 23,  /* lineNo */
  "flipud",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\elmat\\flipud.m"/* pathName */
};

static emlrtRSInfo r_emlrtRSI = { 141, /* lineNo */
  "fn_remove_pulse_echo_data",         /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo s_emlrtRSI = { 39,  /* lineNo */
  "find",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo x_emlrtRSI = { 156, /* lineNo */
  "fn_convert_to_freq_domain",         /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo y_emlrtRSI = { 150, /* lineNo */
  "fn_convert_to_freq_domain",         /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo ab_emlrtRSI = { 149,/* lineNo */
  "fn_convert_to_freq_domain",         /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo bb_emlrtRSI = { 44, /* lineNo */
  "mpower",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\matfun\\mpower.m"/* pathName */
};

static emlrtRSInfo cb_emlrtRSI = { 71, /* lineNo */
  "power",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pathName */
};

static emlrtRSInfo mb_emlrtRSI = { 161,/* lineNo */
  "fn_filter_freq_domain_data",        /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo nb_emlrtRSI = { 177,/* lineNo */
  "fn_filter_freq_domain_data",        /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo ob_emlrtRSI = { 178,/* lineNo */
  "fn_filter_freq_domain_data",        /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo pb_emlrtRSI = { 180,/* lineNo */
  "fn_filter_freq_domain_data",        /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo qb_emlrtRSI = { 181,/* lineNo */
  "fn_filter_freq_domain_data",        /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo rb_emlrtRSI = { 182,/* lineNo */
  "fn_filter_freq_domain_data",        /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo sb_emlrtRSI = { 183,/* lineNo */
  "fn_filter_freq_domain_data",        /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo tb_emlrtRSI = { 187,/* lineNo */
  "fn_filter_freq_domain_data",        /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo ub_emlrtRSI = { 188,/* lineNo */
  "fn_filter_freq_domain_data",        /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo vb_emlrtRSI = { 189,/* lineNo */
  "fn_filter_freq_domain_data",        /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo wb_emlrtRSI = { 190,/* lineNo */
  "fn_filter_freq_domain_data",        /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo xb_emlrtRSI = { 15, /* lineNo */
  "max",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\datafun\\max.m"/* pathName */
};

static emlrtRSInfo yb_emlrtRSI = { 73, /* lineNo */
  "minOrMax",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pathName */
};

static emlrtRSInfo ac_emlrtRSI = { 108,/* lineNo */
  "maximum",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pathName */
};

static emlrtRSInfo bc_emlrtRSI = { 255,/* lineNo */
  "unaryMinOrMax",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo cc_emlrtRSI = { 966,/* lineNo */
  "maxRealVectorOmitNaN",              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo dc_emlrtRSI = { 73, /* lineNo */
  "vectorMinOrMaxInPlace",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\vectorMinOrMaxInPlace.m"/* pathName */
};

static emlrtRSInfo ec_emlrtRSI = { 65, /* lineNo */
  "vectorMinOrMaxInPlace",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\vectorMinOrMaxInPlace.m"/* pathName */
};

static emlrtRSInfo fc_emlrtRSI = { 114,/* lineNo */
  "findFirst",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\vectorMinOrMaxInPlace.m"/* pathName */
};

static emlrtRSInfo gc_emlrtRSI = { 131,/* lineNo */
  "minOrMaxRealVectorKernel",          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\vectorMinOrMaxInPlace.m"/* pathName */
};

static emlrtRSInfo hc_emlrtRSI = { 45, /* lineNo */
  "gaussian",                          /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\pauls-new-functions\\gaussian.m"/* pathName */
};

static emlrtRSInfo ic_emlrtRSI = { 47, /* lineNo */
  "gaussian",                          /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\pauls-new-functions\\gaussian.m"/* pathName */
};

static emlrtRSInfo mc_emlrtRSI = { 15, /* lineNo */
  "min",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\datafun\\min.m"/* pathName */
};

static emlrtRSInfo nc_emlrtRSI = { 75, /* lineNo */
  "minOrMax",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pathName */
};

static emlrtRSInfo oc_emlrtRSI = { 121,/* lineNo */
  "minimum",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pathName */
};

static emlrtRSInfo pc_emlrtRSI = { 273,/* lineNo */
  "unaryMinOrMax",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo qc_emlrtRSI = { 962,/* lineNo */
  "minRealVectorOmitNaN",              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo gd_emlrtRSI = { 202,/* lineNo */
  "fn_inv_mode_shape_matrices",        /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo hd_emlrtRSI = { 208,/* lineNo */
  "fn_inv_mode_shape_matrices",        /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo id_emlrtRSI = { 216,/* lineNo */
  "fn_inv_mode_shape_matrices",        /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo jd_emlrtRSI = { 220,/* lineNo */
  "fn_inv_mode_shape_matrices",        /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo kd_emlrtRSI = { 224,/* lineNo */
  "fn_inv_mode_shape_matrices",        /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo ld_emlrtRSI = { 228,/* lineNo */
  "fn_inv_mode_shape_matrices",        /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo md_emlrtRSI = { 238,/* lineNo */
  "fn_inv_mode_shape_matrices",        /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo nd_emlrtRSI = { 239,/* lineNo */
  "fn_inv_mode_shape_matrices",        /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo od_emlrtRSI = { 246,/* lineNo */
  "fn_inv_mode_shape_matrices",        /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo pd_emlrtRSI = { 290,/* lineNo */
  "unaryMinOrMax",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo qd_emlrtRSI = { 383,/* lineNo */
  "unaryMinOrMaxDispatch",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo rd_emlrtRSI = { 451,/* lineNo */
  "minOrMax2D",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo sd_emlrtRSI = { 533,/* lineNo */
  "minOrMax2DColumnMajorDim1",         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo td_emlrtRSI = { 531,/* lineNo */
  "minOrMax2DColumnMajorDim1",         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo ve_emlrtRSI = { 52, /* lineNo */
  "reshapeSizeChecks",                 /* fcnName */
  "C:\\Program Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\reshapeSizeChecks.m"/* pathName */
};

static emlrtRSInfo jf_emlrtRSI = { 69, /* lineNo */
  "eml_mtimes_helper",                 /* fcnName */
  "C:\\Program Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m"/* pathName */
};

static emlrtRSInfo kf_emlrtRSI = { 19, /* lineNo */
  "pinv",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\matfun\\pinv.m"/* pathName */
};

static emlrtRSInfo lf_emlrtRSI = { 21, /* lineNo */
  "pinv",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\matfun\\pinv.m"/* pathName */
};

static emlrtRSInfo ig_emlrtRSI = { 288,/* lineNo */
  "fn_mode_extract_freq_dom",          /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo jg_emlrtRSI = { 289,/* lineNo */
  "fn_mode_extract_freq_dom",          /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo kg_emlrtRSI = { 293,/* lineNo */
  "fn_mode_extract_freq_dom",          /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo lg_emlrtRSI = { 302,/* lineNo */
  "fn_convert_freq_to_time_dom",       /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo ng_emlrtRSI = { 309,/* lineNo */
  "fn_convert_time_to_dist",           /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo og_emlrtRSI = { 310,/* lineNo */
  "fn_convert_time_to_dist",           /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo pg_emlrtRSI = { 312,/* lineNo */
  "fn_convert_time_to_dist",           /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo qg_emlrtRSI = { 316,/* lineNo */
  "fn_convert_time_to_dist",           /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo rg_emlrtRSI = { 325,/* lineNo */
  "fn_convert_time_to_dist",           /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo sg_emlrtRSI = { 326,/* lineNo */
  "fn_convert_time_to_dist",           /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo tg_emlrtRSI = { 336,/* lineNo */
  "fn_convert_time_to_dist",           /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo xg_emlrtRSI = { 342,/* lineNo */
  "fn_apply_dist_warps",               /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo yg_emlrtRSI = { 347,/* lineNo */
  "fn_apply_dist_warps",               /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo ah_emlrtRSI = { 352,/* lineNo */
  "fn_calc_warp_factors",              /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo bh_emlrtRSI = { 353,/* lineNo */
  "fn_calc_warp_factors",              /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo ch_emlrtRSI = { 354,/* lineNo */
  "fn_calc_warp_factors",              /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo dh_emlrtRSI = { 355,/* lineNo */
  "fn_calc_warp_factors",              /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo eh_emlrtRSI = { 356,/* lineNo */
  "fn_calc_warp_factors",              /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo fh_emlrtRSI = { 34, /* lineNo */
  "rdivide_helper",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\rdivide_helper.m"/* pathName */
};

static emlrtRSInfo gh_emlrtRSI = { 53, /* lineNo */
  "div",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\div.m"/* pathName */
};

static emlrtRTEInfo emlrtRTEI = { 13,  /* lineNo */
  27,                                  /* colNo */
  "assertCompatibleDims",              /* fName */
  "C:\\Program Files\\MATLAB\\R2025a\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\assertCompatibleDims.m"/* pName */
};

static emlrtECInfo emlrtECI = { 1,     /* nDims */
  141,                                 /* lineNo */
  28,                                  /* colNo */
  "fn_remove_pulse_echo_data",         /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtECInfo b_emlrtECI = { 1,   /* nDims */
  156,                                 /* lineNo */
  13,                                  /* colNo */
  "fn_convert_to_freq_domain",         /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtBCInfo emlrtBCI = { -1,    /* iFirst */
  -1,                                  /* iLast */
  155,                                 /* lineNo */
  12,                                  /* colNo */
  "time",                              /* aName */
  "fn_convert_to_freq_domain",         /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  152,                                 /* lineNo */
  32,                                  /* colNo */
  "time",                              /* aName */
  "fn_convert_to_freq_domain",         /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  152,                                 /* lineNo */
  22,                                  /* colNo */
  "time",                              /* aName */
  "fn_convert_to_freq_domain",         /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  151,                                 /* lineNo */
  25,                                  /* colNo */
  "freq_data",                         /* aName */
  "fn_convert_to_freq_domain",         /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo emlrtDCI = { 151,   /* lineNo */
  25,                                  /* colNo */
  "fn_convert_to_freq_domain",         /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  151,                                 /* lineNo */
  23,                                  /* colNo */
  "freq_data",                         /* aName */
  "fn_convert_to_freq_domain",         /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  288,                                 /* lineNo */
  33,                                  /* colNo */
  "inv_mode_shapes",                   /* aName */
  "fn_mode_extract_freq_dom",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  290,                                 /* lineNo */
  25,                                  /* colNo */
  "inv_full_mode_shapes",              /* aName */
  "fn_mode_extract_freq_dom",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo c_emlrtECI = { -1,  /* nDims */
  290,                                 /* lineNo */
  4,                                   /* colNo */
  "fn_mode_extract_freq_dom",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtBCInfo h_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  293,                                 /* lineNo */
  18,                                  /* colNo */
  "proc_freq_data",                    /* aName */
  "fn_mode_extract_freq_dom",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo d_emlrtECI = { -1,  /* nDims */
  293,                                 /* lineNo */
  3,                                   /* colNo */
  "fn_mode_extract_freq_dom",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtBCInfo i_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  299,                                 /* lineNo */
  22,                                  /* colNo */
  "freq",                              /* aName */
  "fn_convert_freq_to_time_dom",       /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  346,                                 /* lineNo */
  41,                                  /* colNo */
  "warp_factors",                      /* aName */
  "fn_apply_dist_warps",               /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  347,                                 /* lineNo */
  65,                                  /* colNo */
  "proc_dist_data",                    /* aName */
  "fn_apply_dist_warps",               /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  347,                                 /* lineNo */
  23,                                  /* colNo */
  "proc_dist_data",                    /* aName */
  "fn_apply_dist_warps",               /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo e_emlrtECI = { -1,  /* nDims */
  347,                                 /* lineNo */
  5,                                   /* colNo */
  "fn_apply_dist_warps",               /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtECInfo f_emlrtECI = { 2,   /* nDims */
  356,                                 /* lineNo */
  17,                                  /* colNo */
  "fn_calc_warp_factors",              /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo b_emlrtRTEI = { 13,/* lineNo */
  13,                                  /* colNo */
  "toLogicalCheck",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\toLogicalCheck.m"/* pName */
};

static emlrtRTEInfo e_emlrtRTEI = { 138,/* lineNo */
  23,                                  /* colNo */
  "dynamic_size_checks",               /* fName */
  "C:\\Program Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m"/* pName */
};

static emlrtRTEInfo f_emlrtRTEI = { 133,/* lineNo */
  23,                                  /* colNo */
  "dynamic_size_checks",               /* fName */
  "C:\\Program Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m"/* pName */
};

static emlrtBCInfo m_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  137,                                 /* lineNo */
  1,                                   /* colNo */
  "time_data",                         /* aName */
  "fn_zero_dead_zone",                 /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  142,                                 /* lineNo */
  9,                                   /* colNo */
  "tx",                                /* aName */
  "fn_remove_pulse_echo_data",         /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  143,                                 /* lineNo */
  9,                                   /* colNo */
  "rx",                                /* aName */
  "fn_remove_pulse_echo_data",         /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  144,                                 /* lineNo */
  26,                                  /* colNo */
  "time_data",                         /* aName */
  "fn_remove_pulse_echo_data",         /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  292,                                 /* lineNo */
  24,                                  /* colNo */
  "inv_full_mode_shapes",              /* aName */
  "fn_mode_extract_freq_dom",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = { 352, /* lineNo */
  17,                                  /* colNo */
  "fn_calc_warp_factors",              /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  352,                                 /* lineNo */
  17,                                  /* colNo */
  "modal_vgrs",                        /* aName */
  "fn_calc_warp_factors",              /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = { 353, /* lineNo */
  17,                                  /* colNo */
  "fn_calc_warp_factors",              /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo s_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  353,                                 /* lineNo */
  17,                                  /* colNo */
  "modal_vgrs",                        /* aName */
  "fn_calc_warp_factors",              /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo t_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  354,                                 /* lineNo */
  17,                                  /* colNo */
  "modal_vgrs",                        /* aName */
  "fn_calc_warp_factors",              /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo u_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  354,                                 /* lineNo */
  49,                                  /* colNo */
  "modal_warps",                       /* aName */
  "fn_calc_warp_factors",              /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo v_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  355,                                 /* lineNo */
  17,                                  /* colNo */
  "modal_vgrs",                        /* aName */
  "fn_calc_warp_factors",              /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo w_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  289,                                 /* lineNo */
  48,                                  /* colNo */
  "freq",                              /* aName */
  "fn_mode_extract_freq_dom",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo x_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  355,                                 /* lineNo */
  49,                                  /* colNo */
  "modal_warps",                       /* aName */
  "fn_calc_warp_factors",              /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo y_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  239,                                 /* lineNo */
  158,                                 /* colNo */
  "array_trans_pos_orientations",      /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ab_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  238,                                 /* lineNo */
  158,                                 /* colNo */
  "array_trans_pos_orientations",      /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo o_emlrtRTEI = { 198,/* lineNo */
  27,                                  /* colNo */
  "unaryMinOrMax",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"/* pName */
};

static emlrtRTEInfo p_emlrtRTEI = { 90,/* lineNo */
  27,                                  /* colNo */
  "unaryMinOrMax",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"/* pName */
};

static emlrtECInfo g_emlrtECI = { -1,  /* nDims */
  246,                                 /* lineNo */
  2,                                   /* colNo */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtBCInfo bb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  246,                                 /* lineNo */
  24,                                  /* colNo */
  "inv_mode_shapes",                   /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  237,                                 /* lineNo */
  13,                                  /* colNo */
  "dot(squeeze(temp_mode_shape(proc_tx_mode(jj), array_trans_node_list(array_trans_pos(raw_tx(iii))), :)), squeeze(array_trans_pos_"
  "orientations(raw_tx(iii), :))) * ...\n                dot(squeeze(temp_mode_shape(proc_rx_mode(jj), array_trans_node_list(array_"
  "trans_pos(raw_rx(iii))), :)), squeeze(array_trans_pos_orientations(raw_rx(iii), :))) * ...\n                exp(1i * temp_waveno"
  "(proc_tx_mode(jj)) * array_row_pos(array_trans_row(raw_tx(iii))) * proc_tx_dir(jj)) * ...\n                exp(1i * temp_waveno("
  "proc_rx_mode(jj)) * array_row_pos(array_trans_row(raw_rx(iii))) * proc_rx_dir(jj))",/* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo h_emlrtECI = { -1,  /* nDims */
  237,                                 /* lineNo */
  13,                                  /* colNo */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtBCInfo db_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  237,                                 /* lineNo */
  30,                                  /* colNo */
  "mode_shapes",                       /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo eb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  237,                                 /* lineNo */
  25,                                  /* colNo */
  "mode_shapes",                       /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  241,                                 /* lineNo */
  116,                                 /* colNo */
  "proc_rx_dir",                       /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  241,                                 /* lineNo */
  72,                                  /* colNo */
  "array_row_pos",                     /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  241,                                 /* lineNo */
  38,                                  /* colNo */
  "temp_waveno",                       /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo d_emlrtDCI = { 241, /* lineNo */
  38,                                  /* colNo */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo ib_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  240,                                 /* lineNo */
  116,                                 /* colNo */
  "proc_tx_dir",                       /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  240,                                 /* lineNo */
  72,                                  /* colNo */
  "array_row_pos",                     /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  240,                                 /* lineNo */
  38,                                  /* colNo */
  "temp_waveno",                       /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo e_emlrtDCI = { 240, /* lineNo */
  38,                                  /* colNo */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo lb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  239,                                 /* lineNo */
  63,                                  /* colNo */
  "temp_mode_shape",                   /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  239,                                 /* lineNo */
  45,                                  /* colNo */
  "temp_mode_shape",                   /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo f_emlrtDCI = { 239, /* lineNo */
  45,                                  /* colNo */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo nb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  238,                                 /* lineNo */
  63,                                  /* colNo */
  "temp_mode_shape",                   /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ob_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  238,                                 /* lineNo */
  45,                                  /* colNo */
  "temp_mode_shape",                   /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo g_emlrtDCI = { 238, /* lineNo */
  45,                                  /* colNo */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  1                                    /* checkKind */
};

static emlrtECInfo i_emlrtECI = { -1,  /* nDims */
  224,                                 /* lineNo */
  3,                                   /* colNo */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtBCInfo pb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  224,                                 /* lineNo */
  48,                                  /* colNo */
  "temp_mode_shape",                   /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  224,                                 /* lineNo */
  19,                                  /* colNo */
  "temp_mode_shape",                   /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo h_emlrtDCI = { 224, /* lineNo */
  19,                                  /* colNo */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  1                                    /* checkKind */
};

static emlrtECInfo j_emlrtECI = { -1,  /* nDims */
  220,                                 /* lineNo */
  3,                                   /* colNo */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtBCInfo rb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  220,                                 /* lineNo */
  48,                                  /* colNo */
  "temp_mode_shape",                   /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  220,                                 /* lineNo */
  19,                                  /* colNo */
  "temp_mode_shape",                   /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo i_emlrtDCI = { 220, /* lineNo */
  19,                                  /* colNo */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  1                                    /* checkKind */
};

static emlrtECInfo k_emlrtECI = { -1,  /* nDims */
  216,                                 /* lineNo */
  3,                                   /* colNo */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtBCInfo tb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  216,                                 /* lineNo */
  48,                                  /* colNo */
  "temp_mode_shape",                   /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ub_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  216,                                 /* lineNo */
  19,                                  /* colNo */
  "temp_mode_shape",                   /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo j_emlrtDCI = { 216, /* lineNo */
  19,                                  /* colNo */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo vb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  230,                                 /* lineNo */
  26,                                  /* colNo */
  "disperse_waveno",                   /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo k_emlrtDCI = { 230, /* lineNo */
  26,                                  /* colNo */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo wb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  229,                                 /* lineNo */
  24,                                  /* colNo */
  "disperse_freq",                     /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo l_emlrtDCI = { 229, /* lineNo */
  24,                                  /* colNo */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo xb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  226,                                 /* lineNo */
  24,                                  /* colNo */
  "disperse_ms_z",                     /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo m_emlrtDCI = { 226, /* lineNo */
  24,                                  /* colNo */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo yb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  225,                                 /* lineNo */
  24,                                  /* colNo */
  "disperse_freq",                     /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo n_emlrtDCI = { 225, /* lineNo */
  24,                                  /* colNo */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo ac_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  222,                                 /* lineNo */
  24,                                  /* colNo */
  "disperse_ms_y",                     /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo o_emlrtDCI = { 222, /* lineNo */
  24,                                  /* colNo */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo bc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  221,                                 /* lineNo */
  24,                                  /* colNo */
  "disperse_freq",                     /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo p_emlrtDCI = { 221, /* lineNo */
  24,                                  /* colNo */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo cc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  218,                                 /* lineNo */
  24,                                  /* colNo */
  "disperse_ms_x",                     /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo q_emlrtDCI = { 218, /* lineNo */
  24,                                  /* colNo */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo dc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  217,                                 /* lineNo */
  24,                                  /* colNo */
  "disperse_freq",                     /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo r_emlrtDCI = { 217, /* lineNo */
  24,                                  /* colNo */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo s_emlrtDCI = { 208, /* lineNo */
  60,                                  /* colNo */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo t_emlrtDCI = { 208, /* lineNo */
  60,                                  /* colNo */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo u_emlrtDCI = { 208, /* lineNo */
  34,                                  /* colNo */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo v_emlrtDCI = { 208, /* lineNo */
  34,                                  /* colNo */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo w_emlrtDCI = { 210, /* lineNo */
  2,                                   /* colNo */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo ec_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  216,                                 /* lineNo */
  42,                                  /* colNo */
  "ms_matrix_modes_to_use",            /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  217,                                 /* lineNo */
  47,                                  /* colNo */
  "ms_matrix_modes_to_use",            /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  218,                                 /* lineNo */
  47,                                  /* colNo */
  "ms_matrix_modes_to_use",            /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  219,                                 /* lineNo */
  25,                                  /* colNo */
  "ms_matrix_calc_freqs",              /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ic_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  244,                                 /* lineNo */
  14,                                  /* colNo */
  "mode_shapes",                       /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  245,                                 /* lineNo */
  14,                                  /* colNo */
  "mode_shapes",                       /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  238,                                 /* lineNo */
  58,                                  /* colNo */
  "proc_tx_mode",                      /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo lc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  220,                                 /* lineNo */
  42,                                  /* colNo */
  "ms_matrix_modes_to_use",            /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  238,                                 /* lineNo */
  85,                                  /* colNo */
  "array_trans_node_list",             /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  238,                                 /* lineNo */
  101,                                 /* colNo */
  "array_trans_pos",                   /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo oc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  238,                                 /* lineNo */
  108,                                 /* colNo */
  "raw_tx",                            /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  221,                                 /* lineNo */
  47,                                  /* colNo */
  "ms_matrix_modes_to_use",            /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  222,                                 /* lineNo */
  47,                                  /* colNo */
  "ms_matrix_modes_to_use",            /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  238,                                 /* lineNo */
  165,                                 /* colNo */
  "raw_tx",                            /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  223,                                 /* lineNo */
  25,                                  /* colNo */
  "ms_matrix_calc_freqs",              /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo tc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  239,                                 /* lineNo */
  58,                                  /* colNo */
  "proc_rx_mode",                      /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo uc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  239,                                 /* lineNo */
  85,                                  /* colNo */
  "array_trans_node_list",             /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  239,                                 /* lineNo */
  101,                                 /* colNo */
  "array_trans_pos",                   /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  239,                                 /* lineNo */
  108,                                 /* colNo */
  "raw_rx",                            /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  239,                                 /* lineNo */
  165,                                 /* colNo */
  "raw_rx",                            /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  224,                                 /* lineNo */
  42,                                  /* colNo */
  "ms_matrix_modes_to_use",            /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ad_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  225,                                 /* lineNo */
  47,                                  /* colNo */
  "ms_matrix_modes_to_use",            /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  226,                                 /* lineNo */
  47,                                  /* colNo */
  "ms_matrix_modes_to_use",            /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  227,                                 /* lineNo */
  25,                                  /* colNo */
  "ms_matrix_calc_freqs",              /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo dd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  240,                                 /* lineNo */
  51,                                  /* colNo */
  "proc_tx_mode",                      /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ed_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  229,                                 /* lineNo */
  47,                                  /* colNo */
  "ms_matrix_modes_to_use",            /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  240,                                 /* lineNo */
  88,                                  /* colNo */
  "array_trans_row",                   /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  240,                                 /* lineNo */
  95,                                  /* colNo */
  "raw_tx",                            /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  230,                                 /* lineNo */
  49,                                  /* colNo */
  "ms_matrix_modes_to_use",            /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo id_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  231,                                 /* lineNo */
  25,                                  /* colNo */
  "ms_matrix_calc_freqs",              /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  228,                                 /* lineNo */
  15,                                  /* colNo */
  "temp_waveno",                       /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo x_emlrtDCI = { 228, /* lineNo */
  15,                                  /* colNo */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo kd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  228,                                 /* lineNo */
  38,                                  /* colNo */
  "ms_matrix_modes_to_use",            /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ld_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  241,                                 /* lineNo */
  51,                                  /* colNo */
  "proc_rx_mode",                      /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo md_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  241,                                 /* lineNo */
  88,                                  /* colNo */
  "array_trans_row",                   /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  241,                                 /* lineNo */
  95,                                  /* colNo */
  "raw_rx",                            /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo od_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  316,                                 /* lineNo */
  30,                                  /* colNo */
  "ms_matrix_modes_to_use",            /* aName */
  "fn_convert_time_to_dist",           /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo y_emlrtDCI = { 316, /* lineNo */
  7,                                   /* colNo */
  "fn_convert_time_to_dist",           /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo pd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  316,                                 /* lineNo */
  7,                                   /* colNo */
  "k",                                 /* aName */
  "fn_convert_time_to_dist",           /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  318,                                 /* lineNo */
  49,                                  /* colNo */
  "ms_matrix_modes_to_use",            /* aName */
  "fn_convert_time_to_dist",           /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  317,                                 /* lineNo */
  47,                                  /* colNo */
  "ms_matrix_modes_to_use",            /* aName */
  "fn_convert_time_to_dist",           /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  322,                                 /* lineNo */
  47,                                  /* colNo */
  "vgr",                               /* aName */
  "fn_convert_time_to_dist",           /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo ab_emlrtDCI = { 322,/* lineNo */
  47,                                  /* colNo */
  "fn_convert_time_to_dist",           /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo td_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  312,                                 /* lineNo */
  32,                                  /* colNo */
  "ms_matrix_modes_to_use",            /* aName */
  "fn_convert_time_to_dist",           /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo bb_emlrtDCI = { 312,/* lineNo */
  9,                                   /* colNo */
  "fn_convert_time_to_dist",           /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo ud_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  312,                                 /* lineNo */
  9,                                   /* colNo */
  "vgr",                               /* aName */
  "fn_convert_time_to_dist",           /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  322,                                 /* lineNo */
  22,                                  /* colNo */
  "vgr",                               /* aName */
  "fn_convert_time_to_dist",           /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo cb_emlrtDCI = { 322,/* lineNo */
  22,                                  /* colNo */
  "fn_convert_time_to_dist",           /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo wd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  314,                                 /* lineNo */
  46,                                  /* colNo */
  "ms_matrix_modes_to_use",            /* aName */
  "fn_convert_time_to_dist",           /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  313,                                 /* lineNo */
  47,                                  /* colNo */
  "ms_matrix_modes_to_use",            /* aName */
  "fn_convert_time_to_dist",           /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo db_emlrtDCI = { 310,/* lineNo */
  1,                                   /* colNo */
  "fn_convert_time_to_dist",           /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo eb_emlrtDCI = { 310,/* lineNo */
  1,                                   /* colNo */
  "fn_convert_time_to_dist",           /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo fb_emlrtDCI = { 309,/* lineNo */
  1,                                   /* colNo */
  "fn_convert_time_to_dist",           /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo gb_emlrtDCI = { 309,/* lineNo */
  1,                                   /* colNo */
  "fn_convert_time_to_dist",           /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  1                                    /* checkKind */
};

static emlrtECInfo l_emlrtECI = { -1,  /* nDims */
  336,                                 /* lineNo */
  2,                                   /* colNo */
  "fn_convert_time_to_dist",           /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtBCInfo yd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  336,                                 /* lineNo */
  20,                                  /* colNo */
  "proc_dist_data",                    /* aName */
  "fn_convert_time_to_dist",           /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ae_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  336,                                 /* lineNo */
  67,                                  /* colNo */
  "proc_time_data",                    /* aName */
  "fn_convert_time_to_dist",           /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo be_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  335,                                 /* lineNo */
  30,                                  /* colNo */
  "vgr",                               /* aName */
  "fn_convert_time_to_dist",           /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo m_emlrtECI = { 1,   /* nDims */
  322,                                 /* lineNo */
  13,                                  /* colNo */
  "fn_convert_time_to_dist",           /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtBCInfo ce_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  318,                                 /* lineNo */
  26,                                  /* colNo */
  "disperse_waveno",                   /* aName */
  "fn_convert_time_to_dist",           /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo hb_emlrtDCI = { 318,/* lineNo */
  26,                                  /* colNo */
  "fn_convert_time_to_dist",           /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo de_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  317,                                 /* lineNo */
  24,                                  /* colNo */
  "disperse_freq",                     /* aName */
  "fn_convert_time_to_dist",           /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo ib_emlrtDCI = { 317,/* lineNo */
  24,                                  /* colNo */
  "fn_convert_time_to_dist",           /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo ee_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  314,                                 /* lineNo */
  23,                                  /* colNo */
  "disperse_vgr",                      /* aName */
  "fn_convert_time_to_dist",           /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo jb_emlrtDCI = { 314,/* lineNo */
  23,                                  /* colNo */
  "fn_convert_time_to_dist",           /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo fe_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  313,                                 /* lineNo */
  24,                                  /* colNo */
  "disperse_freq",                     /* aName */
  "fn_convert_time_to_dist",           /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo kb_emlrtDCI = { 313,/* lineNo */
  24,                                  /* colNo */
  "fn_convert_time_to_dist",           /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  1                                    /* checkKind */
};

static emlrtECInfo n_emlrtECI = { 1,   /* nDims */
  178,                                 /* lineNo */
  11,                                  /* colNo */
  "fn_filter_freq_domain_data",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtECInfo o_emlrtECI = { 1,   /* nDims */
  185,                                 /* lineNo */
  14,                                  /* colNo */
  "fn_filter_freq_domain_data",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtECInfo p_emlrtECI = { 2,   /* nDims */
  185,                                 /* lineNo */
  14,                                  /* colNo */
  "fn_filter_freq_domain_data",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo jb_emlrtRTEI = { 44,/* lineNo */
  16,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo kb_emlrtRTEI = { 45,/* lineNo */
  1,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo lb_emlrtRTEI = { 48,/* lineNo */
  1,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo mb_emlrtRTEI = { 49,/* lineNo */
  1,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo nb_emlrtRTEI = { 56,/* lineNo */
  5,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo ob_emlrtRTEI = { 51,/* lineNo */
  19,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo pb_emlrtRTEI = { 57,/* lineNo */
  5,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo qb_emlrtRTEI = { 51,/* lineNo */
  5,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo rb_emlrtRTEI = { 1,/* lineNo */
  21,                                  /* colNo */
  "flipud",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\elmat\\flipud.m"/* pName */
};

static emlrtRTEInfo sb_emlrtRTEI = { 1,/* lineNo */
  94,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo tb_emlrtRTEI = { 73,/* lineNo */
  5,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo ub_emlrtRTEI = { 53,/* lineNo */
  5,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo wb_emlrtRTEI = { 54,/* lineNo */
  5,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo xb_emlrtRTEI = { 141,/* lineNo */
  1,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo yb_emlrtRTEI = { 142,/* lineNo */
  6,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo ac_emlrtRTEI = { 142,/* lineNo */
  1,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo bc_emlrtRTEI = { 143,/* lineNo */
  6,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo cc_emlrtRTEI = { 151,/* lineNo */
  1,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo dc_emlrtRTEI = { 143,/* lineNo */
  1,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo ec_emlrtRTEI = { 154,/* lineNo */
  1,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo fc_emlrtRTEI = { 144,/* lineNo */
  13,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo gc_emlrtRTEI = { 144,/* lineNo */
  1,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo hc_emlrtRTEI = { 76,/* lineNo */
  13,                                  /* colNo */
  "eml_mtimes_helper",                 /* fName */
  "C:\\Program Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m"/* pName */
};

static emlrtRTEInfo ic_emlrtRTEI = { 156,/* lineNo */
  13,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo jc_emlrtRTEI = { 156,/* lineNo */
  1,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo kc_emlrtRTEI = { 95,/* lineNo */
  20,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo lc_emlrtRTEI = { 105,/* lineNo */
  1,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo mc_emlrtRTEI = { 286,/* lineNo */
  3,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo nc_emlrtRTEI = { 28,/* lineNo */
  9,                                   /* colNo */
  "colon",                             /* fName */
  "C:\\Program Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pName */
};

static emlrtRTEInfo oc_emlrtRTEI = { 293,/* lineNo */
  31,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo qc_emlrtRTEI = { 288,/* lineNo */
  17,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo rc_emlrtRTEI = { 288,/* lineNo */
  9,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo sc_emlrtRTEI = { 356,/* lineNo */
  17,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo tc_emlrtRTEI = { 356,/* lineNo */
  27,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo uc_emlrtRTEI = { 356,/* lineNo */
  40,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo vc_emlrtRTEI = { 356,/* lineNo */
  50,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo wc_emlrtRTEI = { 342,/* lineNo */
  1,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo xc_emlrtRTEI = { 346,/* lineNo */
  16,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo yc_emlrtRTEI = { 347,/* lineNo */
  47,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo ad_emlrtRTEI = { 98,/* lineNo */
  1,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo bd_emlrtRTEI = { 1,/* lineNo */
  11,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo cd_emlrtRTEI = { 1,/* lineNo */
  25,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo dd_emlrtRTEI = { 31,/* lineNo */
  6,                                   /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo ed_emlrtRTEI = { 258,/* lineNo */
  2,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo fd_emlrtRTEI = { 289,/* lineNo */
  4,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo gd_emlrtRTEI = { 293,/* lineNo */
  3,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo hd_emlrtRTEI = { 301,/* lineNo */
  13,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo sd_emlrtRTEI = { 204,/* lineNo */
  1,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo td_emlrtRTEI = { 205,/* lineNo */
  1,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo ud_emlrtRTEI = { 523,/* lineNo */
  21,                                  /* colNo */
  "unaryMinOrMax",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"/* pName */
};

static emlrtRTEInfo vd_emlrtRTEI = { 208,/* lineNo */
  2,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo wd_emlrtRTEI = { 210,/* lineNo */
  2,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo xd_emlrtRTEI = { 19,/* lineNo */
  22,                                  /* colNo */
  "pinv",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\matfun\\pinv.m"/* pName */
};

static emlrtRTEInfo yd_emlrtRTEI = { 217,/* lineNo */
  4,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo ae_emlrtRTEI = { 246,/* lineNo */
  30,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo be_emlrtRTEI = { 218,/* lineNo */
  4,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo ce_emlrtRTEI = { 238,/* lineNo */
  29,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo de_emlrtRTEI = { 238,/* lineNo */
  121,                                 /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo ee_emlrtRTEI = { 221,/* lineNo */
  4,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo fe_emlrtRTEI = { 239,/* lineNo */
  29,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo ge_emlrtRTEI = { 222,/* lineNo */
  4,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo he_emlrtRTEI = { 239,/* lineNo */
  121,                                 /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo ie_emlrtRTEI = { 225,/* lineNo */
  4,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo je_emlrtRTEI = { 226,/* lineNo */
  4,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo ke_emlrtRTEI = { 238,/* lineNo */
  17,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo le_emlrtRTEI = { 229,/* lineNo */
  4,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo me_emlrtRTEI = { 230,/* lineNo */
  4,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo ne_emlrtRTEI = { 216,/* lineNo */
  3,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo oe_emlrtRTEI = { 208,/* lineNo */
  64,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo pe_emlrtRTEI = { 239,/* lineNo */
  17,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo qe_emlrtRTEI = { 19,/* lineNo */
  13,                                  /* colNo */
  "pinv",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\matfun\\pinv.m"/* pName */
};

static emlrtRTEInfo eg_emlrtRTEI = { 309,/* lineNo */
  1,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo fg_emlrtRTEI = { 310,/* lineNo */
  1,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo gg_emlrtRTEI = { 321,/* lineNo */
  1,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo hg_emlrtRTEI = { 322,/* lineNo */
  13,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo ig_emlrtRTEI = { 313,/* lineNo */
  4,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo jg_emlrtRTEI = { 314,/* lineNo */
  4,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo kg_emlrtRTEI = { 322,/* lineNo */
  38,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo mg_emlrtRTEI = { 317,/* lineNo */
  4,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo ng_emlrtRTEI = { 318,/* lineNo */
  4,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo og_emlrtRTEI = { 327,/* lineNo */
  13,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo pg_emlrtRTEI = { 327,/* lineNo */
  1,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo qg_emlrtRTEI = { 331,/* lineNo */
  1,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo rg_emlrtRTEI = { 336,/* lineNo */
  49,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo wg_emlrtRTEI = { 187,/* lineNo */
  13,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo xg_emlrtRTEI = { 188,/* lineNo */
  2,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo yg_emlrtRTEI = { 189,/* lineNo */
  21,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo ah_emlrtRTEI = { 40,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo bh_emlrtRTEI = { 45,/* lineNo */
  1,                                   /* colNo */
  "gaussian",                          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\pauls-new-functions\\gaussian.m"/* pName */
};

static emlrtRTEInfo ch_emlrtRTEI = { 178,/* lineNo */
  21,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo dh_emlrtRTEI = { 181,/* lineNo */
  21,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo eh_emlrtRTEI = { 183,/* lineNo */
  20,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo fh_emlrtRTEI = { 162,/* lineNo */
  2,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo gh_emlrtRTEI = { 187,/* lineNo */
  2,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo hh_emlrtRTEI = { 188,/* lineNo */
  20,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo ih_emlrtRTEI = { 183,/* lineNo */
  11,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo kh_emlrtRTEI = { 185,/* lineNo */
  14,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo lh_emlrtRTEI = { 178,/* lineNo */
  11,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRSInfo hh_emlrtRSI = { 54, /* lineNo */
  "div",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\div.m"/* pathName */
};

static emlrtRSInfo ih_emlrtRSI = { 185,/* lineNo */
  "fn_filter_freq_domain_data",        /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

/* Function Declarations */
static void binary_expand_op(const emlrtStack *sp, emxArray_creal_T *in1, const
  emxArray_creal_T *in2);
static void binary_expand_op_3(const emlrtStack *sp, emxArray_creal_T *in1,
  const emxArray_real_T *in2);
static void binary_expand_op_4(const emlrtStack *sp, emxArray_real_T *in1, const
  emxArray_real_T *in2);
static void fn_convert_time_to_dist(const emlrtStack *sp, const emxArray_real_T *
  proc_time, const emxArray_creal_T *proc_time_data, const emxArray_real_T
  *proc_tx_mode, const emxArray_real_T *proc_rx_mode, const emxArray_real_T
  *disperse_freq, const emxArray_real_T *disperse_vgr, const emxArray_real_T
  *disperse_waveno, const emxArray_real_T *ms_matrix_modes_to_use, real_T
  freq_filter, emxArray_real_T *proc_dist, emxArray_creal_T *proc_dist_data,
  emxArray_real_T *modal_vgrs);
static real_T fn_filter_freq_domain_data(const emlrtStack *sp, const
  emxArray_real_T *freq, emxArray_creal_T *freq_data, real_T freq_filter_on,
  real_T freq_filter, real_T freq_filter_bandwidth, real_T *freq_i2);
static void fn_inv_mode_shape_matrices(const emlrtStack *sp, const
  emxArray_int64_T *raw_tx, const emxArray_int64_T *raw_rx, const
  emxArray_creal_T *raw_freq_data, const emxArray_real_T *array_row_pos, const
  emxArray_int64_T *array_trans_pos, const emxArray_int64_T *array_trans_row,
  const emxArray_real_T *array_trans_pos_orientations, const emxArray_int64_T
  *array_trans_node_list, const emxArray_real_T *disperse_freq, const
  emxArray_real_T *disperse_waveno, const emxArray_creal_T *disperse_ms_x, const
  emxArray_creal_T *disperse_ms_y, const emxArray_creal_T *disperse_ms_z, const
  emxArray_real_T *proc_tx_mode, const emxArray_real_T *proc_rx_mode, const
  emxArray_real_T *proc_tx_dir, const emxArray_real_T *proc_rx_dir, const
  emxArray_real_T *ms_matrix_calc_freqs, const emxArray_real_T
  *ms_matrix_modes_to_use, emxArray_creal_T *inv_mode_shapes);
static void plus(const emlrtStack *sp, emxArray_real_T *in1, const
                 emxArray_real_T *in2);

/* Function Definitions */
static void binary_expand_op(const emlrtStack *sp, emxArray_creal_T *in1, const
  emxArray_creal_T *in2)
{
  emxArray_creal_T *b_in1;
  const creal_T *in2_data;
  creal_T *b_in1_data;
  creal_T *in1_data;
  int32_T b_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int32_T stride_0_0;
  in2_data = in2->data;
  in1_data = in1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_creal_T(sp, &b_in1, 2, &ic_emlrtRTEI);
  loop_ub = in1->size[0];
  stride_0_0 = b_in1->size[0] * b_in1->size[1];
  b_in1->size[0] = loop_ub;
  b_loop_ub = in1->size[1];
  b_in1->size[1] = b_loop_ub;
  emxEnsureCapacity_creal_T(sp, b_in1, stride_0_0, &ic_emlrtRTEI);
  b_in1_data = b_in1->data;
  stride_0_0 = (in2->size[0] != 1);
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      real_T d;
      real_T d1;
      real_T d2;
      real_T d3;
      int32_T i2;
      i2 = i1 * stride_0_0;
      d = in1_data[i1 + in1->size[0] * i].re;
      d1 = in2_data[i2].im;
      d2 = in1_data[i1 + in1->size[0] * i].im;
      d3 = in2_data[i2].re;
      b_in1_data[i1 + b_in1->size[0] * i].re = d * d3 - d2 * d1;
      b_in1_data[i1 + b_in1->size[0] * i].im = d * d1 + d2 * d3;
    }
  }

  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      in1_data[i1 + in1->size[0] * i] = b_in1_data[i1 + b_in1->size[0] * i];
    }
  }

  emxFree_creal_T(sp, &b_in1);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void binary_expand_op_3(const emlrtStack *sp, emxArray_creal_T *in1,
  const emxArray_real_T *in2)
{
  emxArray_creal_T *b_in1;
  creal_T *b_in1_data;
  creal_T *in1_data;
  const real_T *in2_data;
  int32_T aux_0_1;
  int32_T aux_1_1;
  int32_T b_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_0_1;
  int32_T stride_1_0;
  int32_T stride_1_1;
  in2_data = in2->data;
  in1_data = in1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_creal_T(sp, &b_in1, 2, &kh_emlrtRTEI);
  if (in2->size[0] == 1) {
    loop_ub = in1->size[0];
  } else {
    loop_ub = in2->size[0];
  }

  stride_0_0 = b_in1->size[0] * b_in1->size[1];
  b_in1->size[0] = loop_ub;
  if (in2->size[1] == 1) {
    b_loop_ub = in1->size[1];
  } else {
    b_loop_ub = in2->size[1];
  }

  b_in1->size[1] = b_loop_ub;
  emxEnsureCapacity_creal_T(sp, b_in1, stride_0_0, &kh_emlrtRTEI);
  b_in1_data = b_in1->data;
  stride_0_0 = (in1->size[0] != 1);
  stride_0_1 = (in1->size[1] != 1);
  stride_1_0 = (in2->size[0] != 1);
  stride_1_1 = (in2->size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      real_T d;
      int32_T i2;
      d = in2_data[i1 * stride_1_0 + in2->size[0] * aux_1_1];
      i2 = i1 * stride_0_0;
      b_in1_data[i1 + b_in1->size[0] * i].re = d * in1_data[i2 + in1->size[0] *
        aux_0_1].re;
      b_in1_data[i1 + b_in1->size[0] * i].im = d * in1_data[i2 + in1->size[0] *
        aux_0_1].im;
    }

    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }

  stride_0_0 = in1->size[0] * in1->size[1];
  in1->size[0] = loop_ub;
  in1->size[1] = b_loop_ub;
  emxEnsureCapacity_creal_T(sp, in1, stride_0_0, &kh_emlrtRTEI);
  in1_data = in1->data;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      in1_data[i1 + in1->size[0] * i] = b_in1_data[i1 + b_in1->size[0] * i];
    }
  }

  emxFree_creal_T(sp, &b_in1);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void binary_expand_op_4(const emlrtStack *sp, emxArray_real_T *in1, const
  emxArray_real_T *in2)
{
  emxArray_real_T *r;
  real_T *in1_data;
  real_T *r1;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_1_0;
  in1_data = in1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_real_T(sp, &r, 1, &lh_emlrtRTEI);
  if (in1->size[0] == 1) {
    loop_ub = in2->size[0];
  } else {
    loop_ub = in1->size[0];
  }

  stride_1_0 = r->size[0];
  r->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, r, stride_1_0, &lh_emlrtRTEI);
  r1 = r->data;
  stride_1_0 = (in1->size[0] != 1);
  for (i = 0; i < loop_ub; i++) {
    r1[i] = in1_data[i * stride_1_0];
  }

  stride_1_0 = in1->size[0];
  in1->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, in1, stride_1_0, &lh_emlrtRTEI);
  in1_data = in1->data;
  for (i = 0; i < loop_ub; i++) {
    in1_data[i] = r1[i];
  }

  emxFree_real_T(sp, &r);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void fn_convert_time_to_dist(const emlrtStack *sp, const emxArray_real_T *
  proc_time, const emxArray_creal_T *proc_time_data, const emxArray_real_T
  *proc_tx_mode, const emxArray_real_T *proc_rx_mode, const emxArray_real_T
  *disperse_freq, const emxArray_real_T *disperse_vgr, const emxArray_real_T
  *disperse_waveno, const emxArray_real_T *ms_matrix_modes_to_use, real_T
  freq_filter, emxArray_real_T *proc_dist, emxArray_creal_T *proc_dist_data,
  emxArray_real_T *modal_vgrs)
{
  __m128d r;
  jmp_buf * volatile emlrtJBStack;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack i_st;
  emlrtStack st;
  emxArray_creal_T *c_proc_time_data;
  emxArray_real_T *b_disperse_freq;
  emxArray_real_T *b_disperse_vgr;
  emxArray_real_T *b_k;
  emxArray_real_T *vgr;
  const creal_T *proc_time_data_data;
  creal_T *b_proc_time_data_data;
  creal_T *proc_dist_data_data;
  const real_T *b_proc_time_data;
  const real_T *disperse_freq_data;
  const real_T *disperse_vgr_data;
  const real_T *disperse_waveno_data;
  const real_T *ms_matrix_modes_to_use_data;
  const real_T *proc_rx_mode_data;
  const real_T *proc_tx_mode_data;
  real_T b_ex;
  real_T c_ex;
  real_T dist_step;
  real_T ex;
  real_T *b_proc_dist_data;
  real_T *k_data;
  real_T *modal_vgrs_data;
  real_T *vgr_data;
  int32_T b_last;
  int32_T b_loop_ub;
  int32_T c_last;
  int32_T d_last;
  int32_T fn_convert_time_to_dist_numThreads;
  int32_T i;
  int32_T i1;
  int32_T idx;
  int32_T ii;
  int32_T k;
  int32_T last;
  int32_T loop_ub;
  boolean_T exitg1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  i_st.prev = &h_st;
  i_st.tls = h_st.tls;
  ms_matrix_modes_to_use_data = ms_matrix_modes_to_use->data;
  disperse_waveno_data = disperse_waveno->data;
  disperse_vgr_data = disperse_vgr->data;
  disperse_freq_data = disperse_freq->data;
  proc_rx_mode_data = proc_rx_mode->data;
  proc_tx_mode_data = proc_tx_mode->data;
  proc_time_data_data = proc_time_data->data;
  b_proc_time_data = proc_time->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  st.site = &ng_emlrtRSI;
  b_st.site = &xb_emlrtRSI;
  c_st.site = &yb_emlrtRSI;
  d_st.site = &ac_emlrtRSI;
  if (ms_matrix_modes_to_use->size[1] < 1) {
    emlrtErrorWithMessageIdR2018a(&d_st, &o_emlrtRTEI,
      "Coder:toolbox:eml_min_or_max_varDimZero",
      "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }

  e_st.site = &bc_emlrtRSI;
  f_st.site = &cc_emlrtRSI;
  last = ms_matrix_modes_to_use->size[1];
  if (ms_matrix_modes_to_use->size[1] <= 2) {
    if (ms_matrix_modes_to_use->size[1] == 1) {
      ex = ms_matrix_modes_to_use_data[0];
    } else if ((ms_matrix_modes_to_use_data[0] < ms_matrix_modes_to_use_data[1])
               || (muDoubleScalarIsNaN(ms_matrix_modes_to_use_data[0]) &&
                   (!muDoubleScalarIsNaN(ms_matrix_modes_to_use_data[1])))) {
      ex = ms_matrix_modes_to_use_data[1];
    } else {
      ex = ms_matrix_modes_to_use_data[0];
    }
  } else {
    g_st.site = &ec_emlrtRSI;
    if (!muDoubleScalarIsNaN(ms_matrix_modes_to_use_data[0])) {
      idx = 1;
    } else {
      idx = 0;
      h_st.site = &fc_emlrtRSI;
      if (ms_matrix_modes_to_use->size[1] > 2147483646) {
        i_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }

      loop_ub = 2;
      exitg1 = false;
      while ((!exitg1) && (loop_ub <= last)) {
        if (!muDoubleScalarIsNaN(ms_matrix_modes_to_use_data[loop_ub - 1])) {
          idx = loop_ub;
          exitg1 = true;
        } else {
          loop_ub++;
        }
      }
    }

    if (idx == 0) {
      ex = ms_matrix_modes_to_use_data[0];
    } else {
      g_st.site = &dc_emlrtRSI;
      ex = ms_matrix_modes_to_use_data[idx - 1];
      loop_ub = idx + 1;
      h_st.site = &gc_emlrtRSI;
      if ((idx + 1 <= ms_matrix_modes_to_use->size[1]) &&
          (ms_matrix_modes_to_use->size[1] > 2147483646)) {
        i_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }

      for (k = loop_ub; k <= last; k++) {
        dist_step = ms_matrix_modes_to_use_data[k - 1];
        if (ex < dist_step) {
          ex = dist_step;
        }
      }
    }
  }

  emxInit_real_T(sp, &vgr, 1, &eg_emlrtRTEI);
  if (!(ex >= 0.0)) {
    emlrtNonNegativeCheckR2012b(ex, &fb_emlrtDCI, (emlrtConstCTX)sp);
  }

  loop_ub = (int32_T)muDoubleScalarFloor(ex);
  if (ex != loop_ub) {
    emlrtIntegerCheckR2012b(ex, &gb_emlrtDCI, (emlrtConstCTX)sp);
  }

  b_last = (int32_T)ex;
  idx = vgr->size[0];
  vgr->size[0] = b_last;
  emxEnsureCapacity_real_T(sp, vgr, idx, &eg_emlrtRTEI);
  vgr_data = vgr->data;
  if (b_last != loop_ub) {
    emlrtIntegerCheckR2012b(ex, &gb_emlrtDCI, (emlrtConstCTX)sp);
  }

  for (k = 0; k < b_last; k++) {
    vgr_data[k] = 0.0;
  }

  st.site = &og_emlrtRSI;
  b_st.site = &xb_emlrtRSI;
  c_st.site = &yb_emlrtRSI;
  d_st.site = &ac_emlrtRSI;
  e_st.site = &bc_emlrtRSI;
  f_st.site = &cc_emlrtRSI;
  if (ms_matrix_modes_to_use->size[1] <= 2) {
    if (ms_matrix_modes_to_use->size[1] == 1) {
      ex = ms_matrix_modes_to_use_data[0];
    } else if ((ms_matrix_modes_to_use_data[0] < ms_matrix_modes_to_use_data[1])
               || (muDoubleScalarIsNaN(ms_matrix_modes_to_use_data[0]) &&
                   (!muDoubleScalarIsNaN(ms_matrix_modes_to_use_data[1])))) {
      ex = ms_matrix_modes_to_use_data[1];
    } else {
      ex = ms_matrix_modes_to_use_data[0];
    }
  } else {
    g_st.site = &ec_emlrtRSI;
    if (!muDoubleScalarIsNaN(ms_matrix_modes_to_use_data[0])) {
      idx = 1;
    } else {
      idx = 0;
      h_st.site = &fc_emlrtRSI;
      if (ms_matrix_modes_to_use->size[1] > 2147483646) {
        i_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }

      loop_ub = 2;
      exitg1 = false;
      while ((!exitg1) && (loop_ub <= last)) {
        if (!muDoubleScalarIsNaN(ms_matrix_modes_to_use_data[loop_ub - 1])) {
          idx = loop_ub;
          exitg1 = true;
        } else {
          loop_ub++;
        }
      }
    }

    if (idx == 0) {
      ex = ms_matrix_modes_to_use_data[0];
    } else {
      g_st.site = &dc_emlrtRSI;
      ex = ms_matrix_modes_to_use_data[idx - 1];
      loop_ub = idx + 1;
      h_st.site = &gc_emlrtRSI;
      if ((idx + 1 <= ms_matrix_modes_to_use->size[1]) &&
          (ms_matrix_modes_to_use->size[1] > 2147483646)) {
        i_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }

      for (k = loop_ub; k <= last; k++) {
        dist_step = ms_matrix_modes_to_use_data[k - 1];
        if (ex < dist_step) {
          ex = dist_step;
        }
      }
    }
  }

  emxInit_real_T(sp, &b_k, 1, &fg_emlrtRTEI);
  if (!(ex >= 0.0)) {
    emlrtNonNegativeCheckR2012b(ex, &db_emlrtDCI, (emlrtConstCTX)sp);
  }

  loop_ub = (int32_T)muDoubleScalarFloor(ex);
  if (ex != loop_ub) {
    emlrtIntegerCheckR2012b(ex, &eb_emlrtDCI, (emlrtConstCTX)sp);
  }

  b_last = (int32_T)ex;
  idx = b_k->size[0];
  b_k->size[0] = b_last;
  emxEnsureCapacity_real_T(sp, b_k, idx, &fg_emlrtRTEI);
  k_data = b_k->data;
  if (b_last != loop_ub) {
    emlrtIntegerCheckR2012b(ex, &eb_emlrtDCI, (emlrtConstCTX)sp);
  }

  for (k = 0; k < b_last; k++) {
    k_data[k] = 0.0;
  }

  idx = disperse_freq->size[0];
  b_last = disperse_vgr->size[0];
  c_last = disperse_waveno->size[0];
  emxInit_real_T(sp, &b_disperse_freq, 1, &ig_emlrtRTEI);
  emxInit_real_T(sp, &b_disperse_vgr, 1, &jg_emlrtRTEI);
  for (ii = 0; ii < last; ii++) {
    if (ii + 1 > last) {
      emlrtDynamicBoundsCheckR2012b(ii + 1, 1, last, &xd_emlrtBCI,
        (emlrtConstCTX)sp);
    }

    ex = ms_matrix_modes_to_use_data[ii];
    d_last = (int32_T)muDoubleScalarFloor(ex);
    if (ex != d_last) {
      emlrtIntegerCheckR2012b(ex, &kb_emlrtDCI, (emlrtConstCTX)sp);
    }

    b_loop_ub = (int32_T)ex;
    if ((ex < 1.0) || (b_loop_ub > disperse_freq->size[2])) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1, disperse_freq->size[2],
        &fe_emlrtBCI, (emlrtConstCTX)sp);
    }

    if (ii + 1 > last) {
      emlrtDynamicBoundsCheckR2012b(ii + 1, 1, last, &wd_emlrtBCI,
        (emlrtConstCTX)sp);
    }

    if (b_loop_ub != d_last) {
      emlrtIntegerCheckR2012b(ex, &jb_emlrtDCI, (emlrtConstCTX)sp);
    }

    if ((ex < 1.0) || (b_loop_ub > disperse_vgr->size[2])) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1, disperse_vgr->size[2],
        &ee_emlrtBCI, (emlrtConstCTX)sp);
    }

    loop_ub = b_disperse_freq->size[0];
    b_disperse_freq->size[0] = idx;
    emxEnsureCapacity_real_T(sp, b_disperse_freq, loop_ub, &ig_emlrtRTEI);
    modal_vgrs_data = b_disperse_freq->data;
    for (k = 0; k < idx; k++) {
      modal_vgrs_data[k] = disperse_freq_data[k + disperse_freq->size[0] *
        (b_loop_ub - 1)];
    }

    loop_ub = b_disperse_vgr->size[0];
    b_disperse_vgr->size[0] = b_last;
    emxEnsureCapacity_real_T(sp, b_disperse_vgr, loop_ub, &jg_emlrtRTEI);
    b_proc_dist_data = b_disperse_vgr->data;
    for (k = 0; k < b_last; k++) {
      b_proc_dist_data[k] = disperse_vgr_data[k + disperse_vgr->size[0] *
        (b_loop_ub - 1)];
    }

    if (ii + 1 > last) {
      emlrtDynamicBoundsCheckR2012b(ii + 1, 1, last, &td_emlrtBCI,
        (emlrtConstCTX)sp);
    }

    if (b_loop_ub != d_last) {
      emlrtIntegerCheckR2012b(ex, &bb_emlrtDCI, (emlrtConstCTX)sp);
    }

    if ((ex < 1.0) || (b_loop_ub > vgr->size[0])) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1, vgr->size[0], &ud_emlrtBCI,
        (emlrtConstCTX)sp);
    }

    st.site = &pg_emlrtRSI;
    vgr_data[b_loop_ub - 1] = b_interp1(&st, b_disperse_freq, b_disperse_vgr,
      freq_filter);
    if (ii + 1 > last) {
      emlrtDynamicBoundsCheckR2012b(ii + 1, 1, last, &rd_emlrtBCI,
        (emlrtConstCTX)sp);
    }

    if (b_loop_ub != d_last) {
      emlrtIntegerCheckR2012b(ex, &ib_emlrtDCI, (emlrtConstCTX)sp);
    }

    if ((ex < 1.0) || (b_loop_ub > disperse_freq->size[2])) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1, disperse_freq->size[2],
        &de_emlrtBCI, (emlrtConstCTX)sp);
    }

    if (ii + 1 > last) {
      emlrtDynamicBoundsCheckR2012b(ii + 1, 1, last, &qd_emlrtBCI,
        (emlrtConstCTX)sp);
    }

    if (b_loop_ub != d_last) {
      emlrtIntegerCheckR2012b(ex, &hb_emlrtDCI, (emlrtConstCTX)sp);
    }

    if ((ex < 1.0) || (b_loop_ub > disperse_waveno->size[2])) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1, disperse_waveno->size[2],
        &ce_emlrtBCI, (emlrtConstCTX)sp);
    }

    loop_ub = b_disperse_freq->size[0];
    b_disperse_freq->size[0] = idx;
    emxEnsureCapacity_real_T(sp, b_disperse_freq, loop_ub, &mg_emlrtRTEI);
    modal_vgrs_data = b_disperse_freq->data;
    for (k = 0; k < idx; k++) {
      modal_vgrs_data[k] = disperse_freq_data[k + disperse_freq->size[0] *
        (b_loop_ub - 1)];
    }

    loop_ub = b_disperse_vgr->size[0];
    b_disperse_vgr->size[0] = c_last;
    emxEnsureCapacity_real_T(sp, b_disperse_vgr, loop_ub, &ng_emlrtRTEI);
    b_proc_dist_data = b_disperse_vgr->data;
    for (k = 0; k < c_last; k++) {
      b_proc_dist_data[k] = disperse_waveno_data[k + disperse_waveno->size[0] *
        (b_loop_ub - 1)];
    }

    if (ii + 1 > last) {
      emlrtDynamicBoundsCheckR2012b(ii + 1, 1, last, &od_emlrtBCI,
        (emlrtConstCTX)sp);
    }

    if (b_loop_ub != d_last) {
      emlrtIntegerCheckR2012b(ex, &y_emlrtDCI, (emlrtConstCTX)sp);
    }

    if ((ex < 1.0) || (b_loop_ub > b_k->size[0])) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1, b_k->size[0], &pd_emlrtBCI,
        (emlrtConstCTX)sp);
    }

    st.site = &qg_emlrtRSI;
    k_data[b_loop_ub - 1] = b_interp1(&st, b_disperse_freq, b_disperse_vgr,
      freq_filter);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }

  loop_ub = modal_vgrs->size[0] * modal_vgrs->size[1];
  modal_vgrs->size[0] = 1;
  idx = vgr->size[0];
  modal_vgrs->size[1] = vgr->size[0];
  emxEnsureCapacity_real_T(sp, modal_vgrs, loop_ub, &gg_emlrtRTEI);
  modal_vgrs_data = modal_vgrs->data;
  for (k = 0; k < idx; k++) {
    modal_vgrs_data[k] = vgr_data[k];
  }

  b_loop_ub = proc_tx_mode->size[0];
  for (k = 0; k < b_loop_ub; k++) {
    if (proc_tx_mode_data[k] != (int32_T)muDoubleScalarFloor(proc_tx_mode_data[k]))
    {
      emlrtIntegerCheckR2012b(proc_tx_mode_data[k], &cb_emlrtDCI, (emlrtConstCTX)
        sp);
    }

    loop_ub = (int32_T)proc_tx_mode_data[k];
    if ((loop_ub < 1) || (loop_ub > idx)) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, idx, &vd_emlrtBCI,
        (emlrtConstCTX)sp);
    }
  }

  loop_ub = b_disperse_vgr->size[0];
  b_disperse_vgr->size[0] = proc_tx_mode->size[0];
  emxEnsureCapacity_real_T(sp, b_disperse_vgr, loop_ub, &hg_emlrtRTEI);
  b_proc_dist_data = b_disperse_vgr->data;
  loop_ub = proc_tx_mode->size[0];
  if (proc_tx_mode->size[0] < 2000) {
    for (i = 0; i < b_loop_ub; i++) {
      b_proc_dist_data[i] = 1.0 / vgr_data[(int32_T)proc_tx_mode_data[i] - 1];
    }
  } else {
    emlrtEnterParallelRegion((emlrtCTX)sp, omp_in_parallel());
    emlrtPushJmpBuf((emlrtCTX)sp, &emlrtJBStack);
    fn_convert_time_to_dist_numThreads = emlrtAllocRegionTLSs(sp->tls,
      omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());

#pragma omp parallel for \
 num_threads(fn_convert_time_to_dist_numThreads)

    for (i = 0; i < loop_ub; i++) {
      b_proc_dist_data[i] = 1.0 / vgr_data[(int32_T)proc_tx_mode_data[i] - 1];
    }

    emlrtPopJmpBuf((emlrtCTX)sp, &emlrtJBStack);
    emlrtExitParallelRegion((emlrtCTX)sp, omp_in_parallel());
  }

  b_last = proc_rx_mode->size[0];
  for (k = 0; k < b_last; k++) {
    if (proc_rx_mode_data[k] != (int32_T)muDoubleScalarFloor(proc_rx_mode_data[k]))
    {
      emlrtIntegerCheckR2012b(proc_rx_mode_data[k], &ab_emlrtDCI, (emlrtConstCTX)
        sp);
    }

    loop_ub = (int32_T)proc_rx_mode_data[k];
    if ((loop_ub < 1) || (loop_ub > idx)) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, idx, &sd_emlrtBCI,
        (emlrtConstCTX)sp);
    }
  }

  loop_ub = b_disperse_freq->size[0];
  b_disperse_freq->size[0] = proc_rx_mode->size[0];
  emxEnsureCapacity_real_T(sp, b_disperse_freq, loop_ub, &kg_emlrtRTEI);
  modal_vgrs_data = b_disperse_freq->data;
  idx = proc_rx_mode->size[0];
  if (proc_rx_mode->size[0] < 2000) {
    for (i1 = 0; i1 < b_last; i1++) {
      modal_vgrs_data[i1] = 1.0 / vgr_data[(int32_T)proc_rx_mode_data[i1] - 1];
    }
  } else {
    emlrtEnterParallelRegion((emlrtCTX)sp, omp_in_parallel());
    emlrtPushJmpBuf((emlrtCTX)sp, &emlrtJBStack);
    fn_convert_time_to_dist_numThreads = emlrtAllocRegionTLSs(sp->tls,
      omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());

#pragma omp parallel for \
 num_threads(fn_convert_time_to_dist_numThreads)

    for (i1 = 0; i1 < idx; i1++) {
      modal_vgrs_data[i1] = 1.0 / vgr_data[(int32_T)proc_rx_mode_data[i1] - 1];
    }

    emlrtPopJmpBuf((emlrtCTX)sp, &emlrtJBStack);
    emlrtExitParallelRegion((emlrtCTX)sp, omp_in_parallel());
  }

  if ((b_loop_ub != b_last) && ((b_loop_ub != 1) && (b_last != 1))) {
    emlrtDimSizeImpxCheckR2021b(b_loop_ub, b_last, &m_emlrtECI, (emlrtConstCTX)
      sp);
  }

  if (b_disperse_vgr->size[0] == b_disperse_freq->size[0]) {
    loop_ub = vgr->size[0];
    vgr->size[0] = b_loop_ub;
    emxEnsureCapacity_real_T(sp, vgr, loop_ub, &lg_emlrtRTEI);
    vgr_data = vgr->data;
    loop_ub = (b_disperse_vgr->size[0] / 2) << 1;
    idx = loop_ub - 2;
    for (k = 0; k <= idx; k += 2) {
      __m128d r1;
      r = _mm_loadu_pd(&b_proc_dist_data[k]);
      r1 = _mm_loadu_pd(&modal_vgrs_data[k]);
      _mm_storeu_pd(&vgr_data[k], _mm_div_pd(_mm_set1_pd(1.0), _mm_add_pd(r, r1)));
    }

    for (k = loop_ub; k < b_loop_ub; k++) {
      vgr_data[k] = 1.0 / (b_proc_dist_data[k] + modal_vgrs_data[k]);
    }
  } else {
    st.site = &hh_emlrtRSI;
    binary_expand_op_2(&st, vgr, b_disperse_vgr, b_disperse_freq);
    vgr_data = vgr->data;
  }

  /* set up distance axis */
  st.site = &rg_emlrtRSI;
  b_st.site = &xb_emlrtRSI;
  c_st.site = &yb_emlrtRSI;
  d_st.site = &ac_emlrtRSI;
  if (vgr->size[0] < 1) {
    emlrtErrorWithMessageIdR2018a(&d_st, &o_emlrtRTEI,
      "Coder:toolbox:eml_min_or_max_varDimZero",
      "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }

  e_st.site = &bc_emlrtRSI;
  f_st.site = &cc_emlrtRSI;
  d_last = vgr->size[0];
  if (vgr->size[0] <= 2) {
    if (vgr->size[0] == 1) {
      b_ex = vgr_data[0];
    } else if ((vgr_data[0] < vgr_data[1]) || (muDoubleScalarIsNaN(vgr_data[0]) &&
                (!muDoubleScalarIsNaN(vgr_data[1])))) {
      b_ex = vgr_data[1];
    } else {
      b_ex = vgr_data[0];
    }
  } else {
    g_st.site = &ec_emlrtRSI;
    if (!muDoubleScalarIsNaN(vgr_data[0])) {
      idx = 1;
    } else {
      idx = 0;
      h_st.site = &fc_emlrtRSI;
      if (vgr->size[0] > 2147483646) {
        i_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }

      loop_ub = 2;
      exitg1 = false;
      while ((!exitg1) && (loop_ub <= d_last)) {
        if (!muDoubleScalarIsNaN(vgr_data[loop_ub - 1])) {
          idx = loop_ub;
          exitg1 = true;
        } else {
          loop_ub++;
        }
      }
    }

    if (idx == 0) {
      b_ex = vgr_data[0];
    } else {
      g_st.site = &dc_emlrtRSI;
      b_ex = vgr_data[idx - 1];
      loop_ub = idx + 1;
      h_st.site = &gc_emlrtRSI;
      if ((idx + 1 <= vgr->size[0]) && (vgr->size[0] > 2147483646)) {
        i_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }

      for (k = loop_ub; k <= d_last; k++) {
        ex = vgr_data[k - 1];
        if (b_ex < ex) {
          b_ex = ex;
        }
      }
    }
  }

  st.site = &rg_emlrtRSI;
  b_st.site = &xb_emlrtRSI;
  c_st.site = &yb_emlrtRSI;
  d_st.site = &ac_emlrtRSI;
  if (proc_time->size[1] < 1) {
    emlrtErrorWithMessageIdR2018a(&d_st, &o_emlrtRTEI,
      "Coder:toolbox:eml_min_or_max_varDimZero",
      "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }

  e_st.site = &bc_emlrtRSI;
  f_st.site = &cc_emlrtRSI;
  c_last = proc_time->size[1];
  if (proc_time->size[1] <= 2) {
    if (proc_time->size[1] == 1) {
      c_ex = b_proc_time_data[0];
    } else if ((b_proc_time_data[0] < b_proc_time_data[1]) ||
               (muDoubleScalarIsNaN(b_proc_time_data[0]) &&
                (!muDoubleScalarIsNaN(b_proc_time_data[1])))) {
      c_ex = b_proc_time_data[1];
    } else {
      c_ex = b_proc_time_data[0];
    }
  } else {
    g_st.site = &ec_emlrtRSI;
    if (!muDoubleScalarIsNaN(b_proc_time_data[0])) {
      b_last = 1;
    } else {
      b_last = 0;
      h_st.site = &fc_emlrtRSI;
      if (proc_time->size[1] > 2147483646) {
        i_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }

      loop_ub = 2;
      exitg1 = false;
      while ((!exitg1) && (loop_ub <= c_last)) {
        if (!muDoubleScalarIsNaN(b_proc_time_data[loop_ub - 1])) {
          b_last = loop_ub;
          exitg1 = true;
        } else {
          loop_ub++;
        }
      }
    }

    if (b_last == 0) {
      c_ex = b_proc_time_data[0];
    } else {
      g_st.site = &dc_emlrtRSI;
      c_ex = b_proc_time_data[b_last - 1];
      loop_ub = b_last + 1;
      h_st.site = &gc_emlrtRSI;
      if ((b_last + 1 <= proc_time->size[1]) && (proc_time->size[1] > 2147483646))
      {
        i_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }

      for (k = loop_ub; k <= c_last; k++) {
        ex = b_proc_time_data[k - 1];
        if (c_ex < ex) {
          c_ex = ex;
        }
      }
    }
  }

  st.site = &sg_emlrtRSI;
  b_st.site = &xb_emlrtRSI;
  c_st.site = &yb_emlrtRSI;
  d_st.site = &ac_emlrtRSI;
  if (b_k->size[0] < 1) {
    emlrtErrorWithMessageIdR2018a(&d_st, &o_emlrtRTEI,
      "Coder:toolbox:eml_min_or_max_varDimZero",
      "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }

  e_st.site = &bc_emlrtRSI;
  f_st.site = &cc_emlrtRSI;
  b_last = b_k->size[0];
  if (b_k->size[0] <= 2) {
    if (b_k->size[0] == 1) {
      ex = k_data[0];
    } else if ((k_data[0] < k_data[1]) || (muDoubleScalarIsNaN(k_data[0]) &&
                (!muDoubleScalarIsNaN(k_data[1])))) {
      ex = k_data[1];
    } else {
      ex = k_data[0];
    }
  } else {
    g_st.site = &ec_emlrtRSI;
    if (!muDoubleScalarIsNaN(k_data[0])) {
      idx = 1;
    } else {
      idx = 0;
      h_st.site = &fc_emlrtRSI;
      if (b_k->size[0] > 2147483646) {
        i_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }

      loop_ub = 2;
      exitg1 = false;
      while ((!exitg1) && (loop_ub <= b_last)) {
        if (!muDoubleScalarIsNaN(k_data[loop_ub - 1])) {
          idx = loop_ub;
          exitg1 = true;
        } else {
          loop_ub++;
        }
      }
    }

    if (idx == 0) {
      ex = k_data[0];
    } else {
      g_st.site = &dc_emlrtRSI;
      ex = k_data[idx - 1];
      loop_ub = idx + 1;
      h_st.site = &gc_emlrtRSI;
      if ((idx + 1 <= b_k->size[0]) && (b_k->size[0] > 2147483646)) {
        i_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }

      for (k = loop_ub; k <= b_last; k++) {
        dist_step = k_data[k - 1];
        if (ex < dist_step) {
          ex = dist_step;
        }
      }
    }
  }

  emxFree_real_T(&f_st, &b_k);
  dist_step = 1.0 / (2.0 * ex);
  ex = muDoubleScalarRound(b_ex * c_ex / dist_step);
  emxInit_real_T(sp, &modal_vgrs, 2, &hc_emlrtRTEI);
  modal_vgrs_data = modal_vgrs->data;
  if (muDoubleScalarIsNaN(ex)) {
    loop_ub = modal_vgrs->size[0] * modal_vgrs->size[1];
    modal_vgrs->size[0] = 1;
    modal_vgrs->size[1] = 1;
    emxEnsureCapacity_real_T(sp, modal_vgrs, loop_ub, &og_emlrtRTEI);
    modal_vgrs_data = modal_vgrs->data;
    modal_vgrs_data[0] = rtNaN;
  } else if (ex < 0.0) {
    modal_vgrs->size[0] = 1;
    modal_vgrs->size[1] = 0;
  } else {
    loop_ub = modal_vgrs->size[0] * modal_vgrs->size[1];
    modal_vgrs->size[0] = 1;
    modal_vgrs->size[1] = (int32_T)ex + 1;
    emxEnsureCapacity_real_T(sp, modal_vgrs, loop_ub, &og_emlrtRTEI);
    modal_vgrs_data = modal_vgrs->data;
    loop_ub = (int32_T)ex;
    for (k = 0; k <= loop_ub; k++) {
      modal_vgrs_data[k] = k;
    }
  }

  b_last = modal_vgrs->size[1];
  loop_ub = proc_dist->size[0];
  proc_dist->size[0] = modal_vgrs->size[1];
  emxEnsureCapacity_real_T(sp, proc_dist, loop_ub, &pg_emlrtRTEI);
  b_proc_dist_data = proc_dist->data;
  loop_ub = (modal_vgrs->size[1] / 2) << 1;
  idx = loop_ub - 2;
  for (k = 0; k <= idx; k += 2) {
    r = _mm_loadu_pd(&modal_vgrs_data[k]);
    _mm_storeu_pd(&b_proc_dist_data[k], _mm_mul_pd(r, _mm_set1_pd(dist_step)));
  }

  for (k = loop_ub; k < b_last; k++) {
    b_proc_dist_data[k] = modal_vgrs_data[k] * dist_step;
  }

  /*  disp(num2str(length(proc_data_out.dist))) */
  b_last = proc_dist->size[0];
  loop_ub = proc_dist_data->size[0] * proc_dist_data->size[1];
  proc_dist_data->size[0] = proc_dist->size[0];
  proc_dist_data->size[1] = b_loop_ub;
  emxEnsureCapacity_creal_T(sp, proc_dist_data, loop_ub, &qg_emlrtRTEI);
  proc_dist_data_data = proc_dist_data->data;
  loop_ub = proc_dist->size[0] * proc_tx_mode->size[0];
  for (k = 0; k < loop_ub; k++) {
    proc_dist_data_data[k].re = 0.0;
    proc_dist_data_data[k].im = 0.0;
  }

  /* interpolate from time data */
  emxInit_creal_T(sp, &c_proc_time_data, 1, &rg_emlrtRTEI);
  for (ii = 0; ii < b_loop_ub; ii++) {
    if (ii + 1 > d_last) {
      emlrtDynamicBoundsCheckR2012b(ii + 1, 1, d_last, &be_emlrtBCI,
        (emlrtConstCTX)sp);
    }

    if (ii + 1 > b_loop_ub) {
      emlrtDynamicBoundsCheckR2012b(ii + 1, 1, b_loop_ub, &yd_emlrtBCI,
        (emlrtConstCTX)sp);
    }

    if (ii + 1 > proc_time_data->size[1]) {
      emlrtDynamicBoundsCheckR2012b(ii + 1, 1, proc_time_data->size[1],
        &ae_emlrtBCI, (emlrtConstCTX)sp);
    }

    idx = proc_time_data->size[0];
    loop_ub = c_proc_time_data->size[0];
    c_proc_time_data->size[0] = proc_time_data->size[0];
    emxEnsureCapacity_creal_T(sp, c_proc_time_data, loop_ub, &rg_emlrtRTEI);
    b_proc_time_data_data = c_proc_time_data->data;
    for (k = 0; k < idx; k++) {
      b_proc_time_data_data[k] = proc_time_data_data[k + proc_time_data->size[0]
        * ii];
    }

    st.site = &tg_emlrtRSI;
    e_abs(&st, c_proc_time_data, b_disperse_vgr);
    ex = vgr_data[ii];
    loop_ub = modal_vgrs->size[0] * modal_vgrs->size[1];
    modal_vgrs->size[0] = 1;
    modal_vgrs->size[1] = c_last;
    emxEnsureCapacity_real_T(sp, modal_vgrs, loop_ub, &hc_emlrtRTEI);
    modal_vgrs_data = modal_vgrs->data;
    loop_ub = (proc_time->size[1] / 2) << 1;
    idx = loop_ub - 2;
    for (k = 0; k <= idx; k += 2) {
      _mm_storeu_pd(&modal_vgrs_data[k], _mm_mul_pd(_mm_loadu_pd
        (&b_proc_time_data[k]), _mm_set1_pd(ex)));
    }

    for (k = loop_ub; k < c_last; k++) {
      modal_vgrs_data[k] = b_proc_time_data[k] * ex;
    }

    st.site = &tg_emlrtRSI;
    d_interp1(&st, modal_vgrs, b_disperse_vgr, proc_dist, b_disperse_freq);
    modal_vgrs_data = b_disperse_freq->data;
    emlrtSubAssignSizeCheckR2012b(&b_last, 1, &b_disperse_freq->size[0], 1,
      &l_emlrtECI, (emlrtCTX)sp);
    for (k = 0; k < b_last; k++) {
      proc_dist_data_data[k + proc_dist_data->size[0] * ii].re =
        modal_vgrs_data[k];
      proc_dist_data_data[k + proc_dist_data->size[0] * ii].im = 0.0;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }

  emxFree_real_T(sp, &modal_vgrs);
  emxFree_creal_T(sp, &c_proc_time_data);
  emxFree_real_T(sp, &b_disperse_vgr);
  emxFree_real_T(sp, &b_disperse_freq);
  emxFree_real_T(sp, &vgr);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static real_T fn_filter_freq_domain_data(const emlrtStack *sp, const
  emxArray_real_T *freq, emxArray_creal_T *freq_data, real_T freq_filter_on,
  real_T freq_filter, real_T freq_filter_bandwidth, real_T *freq_i2)
{
  jmp_buf * volatile emlrtJBStack;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack i_st;
  emlrtStack st;
  emxArray_boolean_T *x;
  emxArray_int32_T *ii;
  emxArray_real_T *filter;
  emxArray_real_T *r;
  emxArray_real_T *temp;
  emxArray_real_T *y;
  creal_T *freq_data_data;
  const real_T *b_freq_data;
  real_T freq_i1;
  real_T varargin_1;
  real_T *r_data;
  real_T *temp_data;
  int32_T b_k;
  int32_T fn_filter_freq_domain_data_numThreads;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T k;
  int32_T *ii_data;
  boolean_T *x_data;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  i_st.prev = &h_st;
  i_st.tls = h_st.tls;
  freq_data_data = freq_data->data;
  b_freq_data = freq->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);

  /*  function raw_data = fn_filter_freq_domain_data(raw_data_in, input_signal, delay, freq_comp_for_input_signal, freq_filter_on, freq_filter, freq_filter_bandwidth, suppress_display); */
  st.site = &mb_emlrtRSI;
  if (muDoubleScalarIsNaN(freq_filter_on)) {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI, "MATLAB:nologicalnan",
      "MATLAB:nologicalnan", 0);
  }

  emxInit_real_T(sp, &temp, 2, &gh_emlrtRTEI);
  if (freq_filter_on != 0.0) {
    __m128d b_r;
    real_T max_freq;
    int32_T b_last;
    int32_T idx;
    int32_T last;
    int32_T scalarLB;
    boolean_T exitg1;

    /*  if freq_comp_for_input_signal */
    /*  	%calculate spectrum of input signal */
    /*  	time_step = abs(raw_data.time(1) - raw_data.time(2)); */
    /*  	in_time = ([1:raw_data.fft_pts]-1) * time_step; */
    /*  	in_signal = 0.5 * sin(2 * pi * input_signal.freq * in_time) .* (1 - cos(2 * pi * input_signal.freq * in_time / input_signal.cycles)) .* (in_time < input_signal.cycles / input_signal.freq); */
    /*  	in_spec = fft(in_signal, raw_data.fft_pts); */
    /*  	in_spec = abs(in_spec(1:raw_data.fft_pts/2+1))'; */
    /*  	in_valid = in_spec > 0; */
    /*  	in_spec(~in_valid) = 1; */
    /*  	filter = filter ./ in_spec; */
    /*  	filter(~in_valid) = 1; */
    /*  end; */
    st.site = &nb_emlrtRSI;
    b_st.site = &xb_emlrtRSI;
    c_st.site = &yb_emlrtRSI;
    d_st.site = &ac_emlrtRSI;
    if (freq->size[0] < 1) {
      emlrtErrorWithMessageIdR2018a(&d_st, &o_emlrtRTEI,
        "Coder:toolbox:eml_min_or_max_varDimZero",
        "Coder:toolbox:eml_min_or_max_varDimZero", 0);
    }

    e_st.site = &bc_emlrtRSI;
    f_st.site = &cc_emlrtRSI;
    b_last = freq->size[0];
    if (freq->size[0] <= 2) {
      if (freq->size[0] == 1) {
        max_freq = b_freq_data[0];
      } else if ((b_freq_data[0] < b_freq_data[1]) || (muDoubleScalarIsNaN
                  (b_freq_data[0]) && (!muDoubleScalarIsNaN(b_freq_data[1])))) {
        max_freq = b_freq_data[1];
      } else {
        max_freq = b_freq_data[0];
      }
    } else {
      g_st.site = &ec_emlrtRSI;
      if (!muDoubleScalarIsNaN(b_freq_data[0])) {
        last = 1;
      } else {
        last = 0;
        h_st.site = &fc_emlrtRSI;
        if (freq->size[0] > 2147483646) {
          i_st.site = &o_emlrtRSI;
          check_forloop_overflow_error(&i_st);
        }

        scalarLB = 2;
        exitg1 = false;
        while ((!exitg1) && (scalarLB <= b_last)) {
          if (!muDoubleScalarIsNaN(b_freq_data[scalarLB - 1])) {
            last = scalarLB;
            exitg1 = true;
          } else {
            scalarLB++;
          }
        }
      }

      if (last == 0) {
        max_freq = b_freq_data[0];
      } else {
        g_st.site = &dc_emlrtRSI;
        max_freq = b_freq_data[last - 1];
        scalarLB = last + 1;
        h_st.site = &gc_emlrtRSI;
        if ((last + 1 <= freq->size[0]) && (freq->size[0] > 2147483646)) {
          i_st.site = &o_emlrtRSI;
          check_forloop_overflow_error(&i_st);
        }

        for (k = scalarLB; k <= b_last; k++) {
          freq_i1 = b_freq_data[k - 1];
          if (max_freq < freq_i1) {
            max_freq = freq_i1;
          }
        }
      }
    }

    st.site = &ob_emlrtRSI;
    freq_i1 = freq_filter / max_freq;

    /* gaussian(number_of_points, peak_pos_fract, half_width_fract, db_down) */
    /*  */
    /* creates a gaussian vector with number_of_points elements */
    /* the peak at the point in the vector specified by peak_pos_fract (as a fraction) */
    /* and half width specified by half_width_fract, */
    /* where db_down (defaults to 40) specifies the number of dB below the peak value at the half width point */
    /* USAGE */
    /* 	window = gaussian(number_of_points, peak_pos_fract, half_width_fract, db_down, force_zero) */
    /* AUTHOR */
    /* 	Paul Wilcox (2003) */
    /* SUMMARY */
    /* 	Creates a Gaussian window */
    /* OUTPUTS */
    /* 	window - the generated window function, with amplitude ranging from 0 to 1 */
    /* INPUTS */
    /* 	number_of_points - how many points are in the window vector */
    /* 	peak_pos_fract - whereabouts the peak of the window is as a fraction */
    /* 	of the total length of the window vector */
    /* 	half_width_fract - how wide the halfwidth of the window is as a fraction of */
    /* 	the total length of the window vector */
    /* 	(db_down) - number of dB below peak of window used to define the width. */
    /* 	Default is 40. */
    /* 	(force_zero) - if true, points in window outside defined width are */
    /* 	set to zero. Default is false. */
    /* NOTES */
    /* 	output is a column vector */
    /* 	The function forces window outside half width fraction to be zero */
    /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
    b_st.site = &hc_emlrtRSI;
    linspace(&b_st, freq->size[0], temp);
    temp_data = temp->data;
    emxInit_real_T(&st, &r, 1, &bh_emlrtRTEI);
    last = temp->size[1];
    scalarLB = r->size[0];
    r->size[0] = temp->size[1];
    emxEnsureCapacity_real_T(&st, r, scalarLB, &bh_emlrtRTEI);
    r_data = r->data;
    scalarLB = (temp->size[1] / 2) << 1;
    idx = scalarLB - 2;
    for (k = 0; k <= idx; k += 2) {
      b_r = _mm_loadu_pd(&temp_data[k]);
      _mm_storeu_pd(&r_data[k], _mm_sub_pd(b_r, _mm_set1_pd(freq_i1)));
    }

    for (k = scalarLB; k < last; k++) {
      r_data[k] = temp_data[k] - freq_i1;
    }

    max_freq = freq_filter_bandwidth / max_freq / 2.1459660262893472;
    b_st.site = &ic_emlrtRSI;
    c_st.site = &cb_emlrtRSI;
    emxInit_real_T(&st, &filter, 1, &fh_emlrtRTEI);
    idx = r->size[0];
    scalarLB = filter->size[0];
    filter->size[0] = r->size[0];
    emxEnsureCapacity_real_T(&st, filter, scalarLB, &ch_emlrtRTEI);
    temp_data = filter->data;
    scalarLB = r->size[0];
    if (r->size[0] < 2000) {
      for (i1 = 0; i1 < idx; i1++) {
        freq_i1 = r_data[i1] / max_freq;
        temp_data[i1] = -(freq_i1 * freq_i1);
      }
    } else {
      emlrtEnterParallelRegion(&st, omp_in_parallel());
      emlrtPushJmpBuf(&st, &emlrtJBStack);
      fn_filter_freq_domain_data_numThreads = emlrtAllocRegionTLSs(st.tls,
        omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());

#pragma omp parallel for \
 num_threads(fn_filter_freq_domain_data_numThreads) \
 private(varargin_1)

      for (i1 = 0; i1 < scalarLB; i1++) {
        varargin_1 = r_data[i1] / max_freq;
        temp_data[i1] = -(varargin_1 * varargin_1);
      }

      emlrtPopJmpBuf(&st, &emlrtJBStack);
      emlrtExitParallelRegion(&st, omp_in_parallel());
    }

    b_st.site = &ic_emlrtRSI;
    c_exp(&b_st, filter);
    temp_data = filter->data;
    if ((b_last != filter->size[0]) && ((b_last != 1) && (filter->size[0] != 1)))
    {
      emlrtDimSizeImpxCheckR2021b(b_last, filter->size[0], &n_emlrtECI,
        (emlrtConstCTX)sp);
    }

    if (freq->size[0] != filter->size[0]) {
      st.site = &ob_emlrtRSI;
      binary_expand_op_4(&st, filter, freq);
      temp_data = filter->data;
    }

    st.site = &pb_emlrtRSI;
    b_st.site = &pb_emlrtRSI;
    b_abs(&b_st, filter, r);
    r_data = r->data;
    b_st.site = &xb_emlrtRSI;
    c_st.site = &yb_emlrtRSI;
    d_st.site = &ac_emlrtRSI;
    if (r->size[0] < 1) {
      emlrtErrorWithMessageIdR2018a(&d_st, &o_emlrtRTEI,
        "Coder:toolbox:eml_min_or_max_varDimZero",
        "Coder:toolbox:eml_min_or_max_varDimZero", 0);
    }

    e_st.site = &bc_emlrtRSI;
    f_st.site = &cc_emlrtRSI;
    last = r->size[0];
    if (r->size[0] <= 2) {
      if (r->size[0] == 1) {
        freq_i1 = r_data[0];
      } else if ((r_data[0] < r_data[1]) || (muDoubleScalarIsNaN(r_data[0]) && (
                   !muDoubleScalarIsNaN(r_data[1])))) {
        freq_i1 = r_data[1];
      } else {
        freq_i1 = r_data[0];
      }
    } else {
      g_st.site = &ec_emlrtRSI;
      if (!muDoubleScalarIsNaN(r_data[0])) {
        idx = 1;
      } else {
        idx = 0;
        h_st.site = &fc_emlrtRSI;
        if (r->size[0] > 2147483646) {
          i_st.site = &o_emlrtRSI;
          check_forloop_overflow_error(&i_st);
        }

        scalarLB = 2;
        exitg1 = false;
        while ((!exitg1) && (scalarLB <= last)) {
          if (!muDoubleScalarIsNaN(r_data[scalarLB - 1])) {
            idx = scalarLB;
            exitg1 = true;
          } else {
            scalarLB++;
          }
        }
      }

      if (idx == 0) {
        freq_i1 = r_data[0];
      } else {
        g_st.site = &dc_emlrtRSI;
        freq_i1 = r_data[idx - 1];
        scalarLB = idx + 1;
        h_st.site = &gc_emlrtRSI;
        if ((idx + 1 <= r->size[0]) && (r->size[0] > 2147483646)) {
          i_st.site = &o_emlrtRSI;
          check_forloop_overflow_error(&i_st);
        }

        for (k = scalarLB; k <= last; k++) {
          max_freq = r_data[k - 1];
          if (freq_i1 < max_freq) {
            freq_i1 = max_freq;
          }
        }
      }
    }

    scalarLB = filter->size[0];
    idx = (filter->size[0] / 2) << 1;
    last = idx - 2;
    for (k = 0; k <= last; k += 2) {
      b_r = _mm_loadu_pd(&temp_data[k]);
      _mm_storeu_pd(&temp_data[k], _mm_div_pd(b_r, _mm_set1_pd(freq_i1)));
    }

    for (k = idx; k < scalarLB; k++) {
      temp_data[k] /= freq_i1;
    }

    st.site = &qb_emlrtRSI;
    emxInit_boolean_T(&st, &x, 1, &dh_emlrtRTEI);
    idx = filter->size[0];
    scalarLB = x->size[0];
    x->size[0] = filter->size[0];
    emxEnsureCapacity_boolean_T(&st, x, scalarLB, &dh_emlrtRTEI);
    x_data = x->data;
    scalarLB = filter->size[0];
    if (filter->size[0] < 2000) {
      for (i2 = 0; i2 < idx; i2++) {
        x_data[i2] = (temp_data[i2] > 0.01);
      }
    } else {
      emlrtEnterParallelRegion(&st, omp_in_parallel());
      emlrtPushJmpBuf(&st, &emlrtJBStack);
      fn_filter_freq_domain_data_numThreads = emlrtAllocRegionTLSs(st.tls,
        omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());

#pragma omp parallel for \
 num_threads(fn_filter_freq_domain_data_numThreads)

      for (i2 = 0; i2 < scalarLB; i2++) {
        x_data[i2] = (temp_data[i2] > 0.01);
      }

      emlrtPopJmpBuf(&st, &emlrtJBStack);
      emlrtExitParallelRegion(&st, omp_in_parallel());
    }

    emxInit_int32_T(&st, &ii, 1, &dd_emlrtRTEI);
    b_st.site = &s_emlrtRSI;
    eml_find(&b_st, x, ii);
    ii_data = ii->data;
    last = ii->size[0];
    scalarLB = r->size[0];
    r->size[0] = ii->size[0];
    emxEnsureCapacity_real_T(&st, r, scalarLB, &ah_emlrtRTEI);
    r_data = r->data;
    for (k = 0; k < last; k++) {
      r_data[k] = ii_data[k];
    }

    st.site = &qb_emlrtRSI;
    b_st.site = &mc_emlrtRSI;
    c_st.site = &nc_emlrtRSI;
    d_st.site = &oc_emlrtRSI;
    if (r->size[0] < 1) {
      emlrtErrorWithMessageIdR2018a(&d_st, &o_emlrtRTEI,
        "Coder:toolbox:eml_min_or_max_varDimZero",
        "Coder:toolbox:eml_min_or_max_varDimZero", 0);
    }

    e_st.site = &pc_emlrtRSI;
    f_st.site = &qc_emlrtRSI;
    if (r->size[0] <= 2) {
      if (r->size[0] == 1) {
        freq_i1 = r_data[0];
      } else if (r_data[0] > r_data[1]) {
        freq_i1 = r_data[1];
      } else {
        freq_i1 = r_data[0];
      }
    } else {
      g_st.site = &ec_emlrtRSI;
      g_st.site = &dc_emlrtRSI;
      scalarLB = (int32_T)r_data[0];
      h_st.site = &gc_emlrtRSI;
      if (r->size[0] > 2147483646) {
        i_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }

      for (b_k = 2; b_k <= last; b_k++) {
        idx = (int32_T)r_data[b_k - 1];
        if (scalarLB > idx) {
          scalarLB = idx;
        }
      }

      freq_i1 = scalarLB;
    }

    st.site = &rb_emlrtRSI;
    b_st.site = &s_emlrtRSI;
    eml_find(&b_st, x, ii);
    ii_data = ii->data;
    emxFree_boolean_T(&st, &x);
    last = ii->size[0];
    scalarLB = r->size[0];
    r->size[0] = ii->size[0];
    emxEnsureCapacity_real_T(&st, r, scalarLB, &ah_emlrtRTEI);
    r_data = r->data;
    for (k = 0; k < last; k++) {
      r_data[k] = ii_data[k];
    }

    emxFree_int32_T(&st, &ii);
    st.site = &rb_emlrtRSI;
    b_st.site = &xb_emlrtRSI;
    c_st.site = &yb_emlrtRSI;
    d_st.site = &ac_emlrtRSI;
    if (r->size[0] < 1) {
      emlrtErrorWithMessageIdR2018a(&d_st, &o_emlrtRTEI,
        "Coder:toolbox:eml_min_or_max_varDimZero",
        "Coder:toolbox:eml_min_or_max_varDimZero", 0);
    }

    e_st.site = &bc_emlrtRSI;
    f_st.site = &cc_emlrtRSI;
    if (r->size[0] <= 2) {
      if (r->size[0] == 1) {
        *freq_i2 = r_data[0];
      } else if (r_data[0] < r_data[1]) {
        *freq_i2 = r_data[1];
      } else {
        *freq_i2 = r_data[0];
      }
    } else {
      g_st.site = &ec_emlrtRSI;
      g_st.site = &dc_emlrtRSI;
      scalarLB = (int32_T)r_data[0];
      h_st.site = &gc_emlrtRSI;
      if (r->size[0] > 2147483646) {
        i_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }

      for (k = 2; k <= last; k++) {
        idx = (int32_T)r_data[k - 1];
        if (scalarLB < idx) {
          scalarLB = idx;
        }
      }

      *freq_i2 = scalarLB;
    }

    emxFree_real_T(&f_st, &r);
    emxInit_real_T(sp, &y, 2, &ih_emlrtRTEI);
    st.site = &sb_emlrtRSI;
    idx = freq_data->size[1];
    scalarLB = temp->size[0] * temp->size[1];
    temp->size[0] = 1;
    temp->size[1] = idx;
    emxEnsureCapacity_real_T(&st, temp, scalarLB, &eh_emlrtRTEI);
    temp_data = temp->data;
    for (k = 0; k < idx; k++) {
      temp_data[k] = 1.0;
    }

    b_st.site = &m_emlrtRSI;
    mtimes(&b_st, filter, temp, y);
    temp_data = y->data;
    emxFree_real_T(&st, &filter);
    scalarLB = freq_data->size[0];
    if ((scalarLB != y->size[0]) && ((scalarLB != 1) && (y->size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(scalarLB, y->size[0], &o_emlrtECI,
        (emlrtConstCTX)sp);
    }

    if ((idx != y->size[1]) && ((idx != 1) && (y->size[1] != 1))) {
      emlrtDimSizeImpxCheckR2021b(idx, y->size[1], &p_emlrtECI, (emlrtConstCTX)
        sp);
    }

    if ((freq_data->size[0] == y->size[0]) && (freq_data->size[1] == y->size[1]))
    {
      for (k = 0; k < idx; k++) {
        for (b_k = 0; b_k < scalarLB; b_k++) {
          freq_data_data[b_k + freq_data->size[0] * k].re *= temp_data[b_k +
            y->size[0] * k];
          freq_data_data[b_k + freq_data->size[0] * k].im *= temp_data[b_k +
            y->size[0] * k];
        }
      }
    } else {
      st.site = &ih_emlrtRSI;
      binary_expand_op_3(&st, freq_data, y);
    }

    emxFree_real_T(sp, &y);
  } else {
    real_T max_freq;
    int32_T idx;
    int32_T last;
    int32_T scalarLB;
    emxInit_real_T(sp, &r, 2, &wg_emlrtRTEI);
    st.site = &tb_emlrtRSI;
    c_abs(&st, freq_data, r);
    temp_data = r->data;
    emxInit_real_T(sp, &filter, 2, &wg_emlrtRTEI);
    idx = r->size[1];
    scalarLB = filter->size[0] * filter->size[1];
    filter->size[0] = r->size[1];
    last = r->size[0];
    filter->size[1] = r->size[0];
    emxEnsureCapacity_real_T(sp, filter, scalarLB, &wg_emlrtRTEI);
    r_data = filter->data;
    for (k = 0; k < last; k++) {
      for (b_k = 0; b_k < idx; b_k++) {
        r_data[b_k + filter->size[0] * k] = temp_data[k + r->size[0] * b_k];
      }
    }

    emxFree_real_T(sp, &r);
    st.site = &tb_emlrtRSI;
    sum(&st, filter, temp);
    emxFree_real_T(sp, &filter);
    st.site = &ub_emlrtRSI;
    emxInit_real_T(&st, &y, 2, &hh_emlrtRTEI);
    b_st.site = &ub_emlrtRSI;
    d_abs(&b_st, temp, y);
    temp_data = y->data;
    b_st.site = &xb_emlrtRSI;
    c_st.site = &yb_emlrtRSI;
    d_st.site = &ac_emlrtRSI;
    if (y->size[1] < 1) {
      emlrtErrorWithMessageIdR2018a(&d_st, &o_emlrtRTEI,
        "Coder:toolbox:eml_min_or_max_varDimZero",
        "Coder:toolbox:eml_min_or_max_varDimZero", 0);
    }

    e_st.site = &bc_emlrtRSI;
    f_st.site = &cc_emlrtRSI;
    last = y->size[1];
    if (y->size[1] <= 2) {
      if (y->size[1] == 1) {
        freq_i1 = temp_data[0];
      } else if ((temp_data[0] < temp_data[1]) || (muDoubleScalarIsNaN
                  (temp_data[0]) && (!muDoubleScalarIsNaN(temp_data[1])))) {
        freq_i1 = temp_data[1];
      } else {
        freq_i1 = temp_data[0];
      }
    } else {
      g_st.site = &ec_emlrtRSI;
      if (!muDoubleScalarIsNaN(temp_data[0])) {
        idx = 1;
      } else {
        boolean_T exitg1;
        idx = 0;
        h_st.site = &fc_emlrtRSI;
        if (y->size[1] > 2147483646) {
          i_st.site = &o_emlrtRSI;
          check_forloop_overflow_error(&i_st);
        }

        scalarLB = 2;
        exitg1 = false;
        while ((!exitg1) && (scalarLB <= last)) {
          if (!muDoubleScalarIsNaN(temp_data[scalarLB - 1])) {
            idx = scalarLB;
            exitg1 = true;
          } else {
            scalarLB++;
          }
        }
      }

      if (idx == 0) {
        freq_i1 = temp_data[0];
      } else {
        g_st.site = &dc_emlrtRSI;
        freq_i1 = temp_data[idx - 1];
        scalarLB = idx + 1;
        h_st.site = &gc_emlrtRSI;
        if ((idx + 1 <= y->size[1]) && (y->size[1] > 2147483646)) {
          i_st.site = &o_emlrtRSI;
          check_forloop_overflow_error(&i_st);
        }

        for (k = scalarLB; k <= last; k++) {
          max_freq = temp_data[k - 1];
          if (freq_i1 < max_freq) {
            freq_i1 = max_freq;
          }
        }
      }
    }

    emxFree_real_T(&f_st, &y);
    scalarLB = temp->size[0] * temp->size[1];
    temp->size[0] = 1;
    emxEnsureCapacity_real_T(sp, temp, scalarLB, &xg_emlrtRTEI);
    temp_data = temp->data;
    scalarLB = temp->size[1] - 1;
    idx = (temp->size[1] / 2) << 1;
    last = idx - 2;
    for (k = 0; k <= last; k += 2) {
      __m128d b_r;
      b_r = _mm_loadu_pd(&temp_data[k]);
      _mm_storeu_pd(&temp_data[k], _mm_div_pd(b_r, _mm_set1_pd(freq_i1)));
    }

    for (k = idx; k <= scalarLB; k++) {
      temp_data[k] /= freq_i1;
    }

    st.site = &vb_emlrtRSI;
    emxInit_boolean_T(&st, &x, 2, &yg_emlrtRTEI);
    scalarLB = x->size[0] * x->size[1];
    x->size[0] = 1;
    idx = temp->size[1];
    x->size[1] = temp->size[1];
    emxEnsureCapacity_boolean_T(&st, x, scalarLB, &yg_emlrtRTEI);
    x_data = x->data;
    scalarLB = temp->size[1];
    if (temp->size[1] < 2000) {
      for (i = 0; i < idx; i++) {
        x_data[i] = (temp_data[i] > 0.01);
      }
    } else {
      emlrtEnterParallelRegion(&st, omp_in_parallel());
      emlrtPushJmpBuf(&st, &emlrtJBStack);
      fn_filter_freq_domain_data_numThreads = emlrtAllocRegionTLSs(st.tls,
        omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());

#pragma omp parallel for \
 num_threads(fn_filter_freq_domain_data_numThreads)

      for (i = 0; i < scalarLB; i++) {
        x_data[i] = (temp_data[i] > 0.01);
      }

      emlrtPopJmpBuf(&st, &emlrtJBStack);
      emlrtExitParallelRegion(&st, omp_in_parallel());
    }

    emxInit_int32_T(&st, &ii, 2, &dd_emlrtRTEI);
    b_st.site = &s_emlrtRSI;
    b_eml_find(&b_st, x, ii);
    ii_data = ii->data;
    scalarLB = temp->size[0] * temp->size[1];
    temp->size[0] = 1;
    idx = ii->size[1];
    temp->size[1] = ii->size[1];
    emxEnsureCapacity_real_T(&st, temp, scalarLB, &ah_emlrtRTEI);
    temp_data = temp->data;
    for (k = 0; k < idx; k++) {
      temp_data[k] = ii_data[k];
    }

    st.site = &vb_emlrtRSI;
    b_st.site = &mc_emlrtRSI;
    c_st.site = &nc_emlrtRSI;
    d_st.site = &oc_emlrtRSI;
    if (temp->size[1] < 1) {
      emlrtErrorWithMessageIdR2018a(&d_st, &o_emlrtRTEI,
        "Coder:toolbox:eml_min_or_max_varDimZero",
        "Coder:toolbox:eml_min_or_max_varDimZero", 0);
    }

    e_st.site = &pc_emlrtRSI;
    f_st.site = &qc_emlrtRSI;
    if (temp->size[1] <= 2) {
      if (temp->size[1] == 1) {
        freq_i1 = temp_data[0];
      } else if ((int32_T)temp_data[0] > (int32_T)temp_data[1]) {
        freq_i1 = temp_data[1];
      } else {
        freq_i1 = temp_data[0];
      }
    } else {
      g_st.site = &ec_emlrtRSI;
      g_st.site = &dc_emlrtRSI;
      scalarLB = (int32_T)temp_data[0];
      h_st.site = &gc_emlrtRSI;
      if (temp->size[1] > 2147483646) {
        i_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }

      for (k = 2; k <= idx; k++) {
        freq_i1 = temp_data[k - 1];
        if (scalarLB > (int32_T)freq_i1) {
          scalarLB = (int32_T)freq_i1;
        }
      }

      freq_i1 = scalarLB;
    }

    st.site = &wb_emlrtRSI;
    b_st.site = &s_emlrtRSI;
    b_eml_find(&b_st, x, ii);
    ii_data = ii->data;
    emxFree_boolean_T(&st, &x);
    scalarLB = temp->size[0] * temp->size[1];
    temp->size[0] = 1;
    idx = ii->size[1];
    temp->size[1] = ii->size[1];
    emxEnsureCapacity_real_T(&st, temp, scalarLB, &ah_emlrtRTEI);
    temp_data = temp->data;
    for (k = 0; k < idx; k++) {
      temp_data[k] = ii_data[k];
    }

    emxFree_int32_T(&st, &ii);
    st.site = &wb_emlrtRSI;
    b_st.site = &xb_emlrtRSI;
    c_st.site = &yb_emlrtRSI;
    d_st.site = &ac_emlrtRSI;
    if (temp->size[1] < 1) {
      emlrtErrorWithMessageIdR2018a(&d_st, &o_emlrtRTEI,
        "Coder:toolbox:eml_min_or_max_varDimZero",
        "Coder:toolbox:eml_min_or_max_varDimZero", 0);
    }

    e_st.site = &bc_emlrtRSI;
    f_st.site = &cc_emlrtRSI;
    if (temp->size[1] <= 2) {
      if (temp->size[1] == 1) {
        *freq_i2 = temp_data[0];
      } else if ((int32_T)temp_data[0] < (int32_T)temp_data[1]) {
        *freq_i2 = temp_data[1];
      } else {
        *freq_i2 = temp_data[0];
      }
    } else {
      g_st.site = &ec_emlrtRSI;
      g_st.site = &dc_emlrtRSI;
      scalarLB = (int32_T)temp_data[0];
      h_st.site = &gc_emlrtRSI;
      if (temp->size[1] > 2147483646) {
        i_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }

      for (k = 2; k <= idx; k++) {
        max_freq = temp_data[k - 1];
        if (scalarLB < (int32_T)max_freq) {
          scalarLB = (int32_T)max_freq;
        }
      }

      *freq_i2 = scalarLB;
    }
  }

  emxFree_real_T(sp, &temp);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
  return freq_i1;
}

static void fn_inv_mode_shape_matrices(const emlrtStack *sp, const
  emxArray_int64_T *raw_tx, const emxArray_int64_T *raw_rx, const
  emxArray_creal_T *raw_freq_data, const emxArray_real_T *array_row_pos, const
  emxArray_int64_T *array_trans_pos, const emxArray_int64_T *array_trans_row,
  const emxArray_real_T *array_trans_pos_orientations, const emxArray_int64_T
  *array_trans_node_list, const emxArray_real_T *disperse_freq, const
  emxArray_real_T *disperse_waveno, const emxArray_creal_T *disperse_ms_x, const
  emxArray_creal_T *disperse_ms_y, const emxArray_creal_T *disperse_ms_z, const
  emxArray_real_T *proc_tx_mode, const emxArray_real_T *proc_rx_mode, const
  emxArray_real_T *proc_tx_dir, const emxArray_real_T *proc_rx_dir, const
  emxArray_real_T *ms_matrix_calc_freqs, const emxArray_real_T
  *ms_matrix_modes_to_use, emxArray_creal_T *inv_mode_shapes)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack i_st;
  emlrtStack st;
  emxArray_creal_T *b_a;
  emxArray_creal_T *b_b;
  emxArray_creal_T *b_disperse_ms_x;
  emxArray_creal_T *b_temp_mode_shape;
  emxArray_creal_T *mode_shapes;
  emxArray_creal_T *r;
  emxArray_creal_T *r1;
  emxArray_creal_T *temp_mode_shape;
  emxArray_creal_T *y;
  emxArray_real_T *b_disperse_freq;
  emxArray_real_T *b_disperse_waveno;
  emxArray_real_T *maxval;
  emxArray_real_T *temp_waveno;
  const creal_T *disperse_ms_x_data;
  const creal_T *disperse_ms_y_data;
  const creal_T *disperse_ms_z_data;
  creal_T c_b;
  creal_T d_b;
  creal_T *b_disperse_ms_x_data;
  creal_T *b_temp_mode_shape_data;
  creal_T *inv_mode_shapes_data;
  creal_T *mode_shapes_data;
  creal_T *temp_mode_shape_data;
  const int64_T *array_trans_node_list_data;
  const int64_T *array_trans_pos_data;
  const int64_T *array_trans_row_data;
  const int64_T *raw_rx_data;
  const int64_T *raw_tx_data;
  const real_T *array_row_pos_data;
  const real_T *c_array_trans_pos_orientations_;
  const real_T *disperse_freq_data;
  const real_T *disperse_waveno_data;
  const real_T *ms_matrix_calc_freqs_data;
  const real_T *ms_matrix_modes_to_use_data;
  const real_T *proc_rx_dir_data;
  const real_T *proc_rx_mode_data;
  const real_T *proc_tx_dir_data;
  const real_T *proc_tx_mode_data;
  real_T a;
  real_T ex;
  real_T max_mode_index;
  real_T *maxval_data;
  real_T *temp_waveno_data;
  int32_T b_inv_mode_shapes[2];
  int32_T b_i;
  int32_T b_idx;
  int32_T b_last;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T i4 = 0;
  int32_T i5 = 0;
  int32_T idx;
  int32_T ii;
  int32_T j;
  int32_T jj;
  int32_T last;
  int32_T loop_ub;
  int32_T loop_ub_tmp;
  int32_T m = 0;
  int32_T n;
  boolean_T b;
  boolean_T exitg1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  i_st.prev = &h_st;
  i_st.tls = h_st.tls;
  ms_matrix_modes_to_use_data = ms_matrix_modes_to_use->data;
  ms_matrix_calc_freqs_data = ms_matrix_calc_freqs->data;
  proc_rx_dir_data = proc_rx_dir->data;
  proc_tx_dir_data = proc_tx_dir->data;
  proc_rx_mode_data = proc_rx_mode->data;
  proc_tx_mode_data = proc_tx_mode->data;
  disperse_ms_z_data = disperse_ms_z->data;
  disperse_ms_y_data = disperse_ms_y->data;
  disperse_ms_x_data = disperse_ms_x->data;
  disperse_waveno_data = disperse_waveno->data;
  disperse_freq_data = disperse_freq->data;
  array_trans_node_list_data = array_trans_node_list->data;
  c_array_trans_pos_orientations_ = array_trans_pos_orientations->data;
  array_trans_row_data = array_trans_row->data;
  array_trans_pos_data = array_trans_pos->data;
  array_row_pos_data = array_row_pos->data;
  raw_rx_data = raw_rx->data;
  raw_tx_data = raw_tx->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);

  /*  %array */
  st.site = &gd_emlrtRSI;
  b_st.site = &xb_emlrtRSI;
  c_st.site = &yb_emlrtRSI;
  d_st.site = &ac_emlrtRSI;
  if (proc_tx_mode->size[0] < 1) {
    emlrtErrorWithMessageIdR2018a(&d_st, &o_emlrtRTEI,
      "Coder:toolbox:eml_min_or_max_varDimZero",
      "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }

  e_st.site = &bc_emlrtRSI;
  f_st.site = &cc_emlrtRSI;
  last = proc_tx_mode->size[0];
  if (proc_tx_mode->size[0] <= 2) {
    if (proc_tx_mode->size[0] == 1) {
      ex = proc_tx_mode_data[0];
    } else if ((proc_tx_mode_data[0] < proc_tx_mode_data[1]) ||
               (muDoubleScalarIsNaN(proc_tx_mode_data[0]) &&
                (!muDoubleScalarIsNaN(proc_tx_mode_data[1])))) {
      ex = proc_tx_mode_data[1];
    } else {
      ex = proc_tx_mode_data[0];
    }
  } else {
    g_st.site = &ec_emlrtRSI;
    if (!muDoubleScalarIsNaN(proc_tx_mode_data[0])) {
      idx = 1;
    } else {
      idx = 0;
      h_st.site = &fc_emlrtRSI;
      if (proc_tx_mode->size[0] > 2147483646) {
        i_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }

      b_idx = 2;
      exitg1 = false;
      while ((!exitg1) && (b_idx <= last)) {
        if (!muDoubleScalarIsNaN(proc_tx_mode_data[b_idx - 1])) {
          idx = b_idx;
          exitg1 = true;
        } else {
          b_idx++;
        }
      }
    }

    if (idx == 0) {
      ex = proc_tx_mode_data[0];
    } else {
      g_st.site = &dc_emlrtRSI;
      ex = proc_tx_mode_data[idx - 1];
      b_idx = idx + 1;
      h_st.site = &gc_emlrtRSI;
      if ((idx + 1 <= proc_tx_mode->size[0]) && (proc_tx_mode->size[0] >
           2147483646)) {
        i_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }

      for (j = b_idx; j <= last; j++) {
        a = proc_tx_mode_data[j - 1];
        if (ex < a) {
          ex = a;
        }
      }
    }
  }

  st.site = &gd_emlrtRSI;
  b_st.site = &xb_emlrtRSI;
  c_st.site = &yb_emlrtRSI;
  d_st.site = &ac_emlrtRSI;
  if (proc_rx_mode->size[0] < 1) {
    emlrtErrorWithMessageIdR2018a(&d_st, &o_emlrtRTEI,
      "Coder:toolbox:eml_min_or_max_varDimZero",
      "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }

  e_st.site = &bc_emlrtRSI;
  f_st.site = &cc_emlrtRSI;
  b_last = proc_rx_mode->size[0];
  if (proc_rx_mode->size[0] <= 2) {
    if (proc_rx_mode->size[0] == 1) {
      max_mode_index = proc_rx_mode_data[0];
    } else if ((proc_rx_mode_data[0] < proc_rx_mode_data[1]) ||
               (muDoubleScalarIsNaN(proc_rx_mode_data[0]) &&
                (!muDoubleScalarIsNaN(proc_rx_mode_data[1])))) {
      max_mode_index = proc_rx_mode_data[1];
    } else {
      max_mode_index = proc_rx_mode_data[0];
    }
  } else {
    g_st.site = &ec_emlrtRSI;
    if (!muDoubleScalarIsNaN(proc_rx_mode_data[0])) {
      idx = 1;
    } else {
      idx = 0;
      h_st.site = &fc_emlrtRSI;
      if (proc_rx_mode->size[0] > 2147483646) {
        i_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }

      b_idx = 2;
      exitg1 = false;
      while ((!exitg1) && (b_idx <= b_last)) {
        if (!muDoubleScalarIsNaN(proc_rx_mode_data[b_idx - 1])) {
          idx = b_idx;
          exitg1 = true;
        } else {
          b_idx++;
        }
      }
    }

    if (idx == 0) {
      max_mode_index = proc_rx_mode_data[0];
    } else {
      g_st.site = &dc_emlrtRSI;
      max_mode_index = proc_rx_mode_data[idx - 1];
      b_idx = idx + 1;
      h_st.site = &gc_emlrtRSI;
      if ((idx + 1 <= proc_rx_mode->size[0]) && (proc_rx_mode->size[0] >
           2147483646)) {
        i_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }

      for (j = b_idx; j <= b_last; j++) {
        a = proc_rx_mode_data[j - 1];
        if (max_mode_index < a) {
          max_mode_index = a;
        }
      }
    }
  }

  if ((!(ex < max_mode_index)) && ((!muDoubleScalarIsNaN(ex)) ||
       muDoubleScalarIsNaN(max_mode_index))) {
    max_mode_index = ex;
  }

  b_idx = inv_mode_shapes->size[0] * inv_mode_shapes->size[1] *
    inv_mode_shapes->size[2];
  inv_mode_shapes->size[0] = proc_tx_mode->size[0];
  loop_ub = raw_freq_data->size[1];
  inv_mode_shapes->size[1] = raw_freq_data->size[1];
  i = ms_matrix_calc_freqs->size[1];
  inv_mode_shapes->size[2] = ms_matrix_calc_freqs->size[1];
  emxEnsureCapacity_creal_T(sp, inv_mode_shapes, b_idx, &sd_emlrtRTEI);
  inv_mode_shapes_data = inv_mode_shapes->data;
  b_idx = proc_tx_mode->size[0] * raw_freq_data->size[1];
  idx = b_idx * ms_matrix_calc_freqs->size[1];
  for (j = 0; j < idx; j++) {
    inv_mode_shapes_data[j].re = 0.0;
    inv_mode_shapes_data[j].im = 0.0;
  }

  emxInit_creal_T(sp, &mode_shapes, 2, &td_emlrtRTEI);
  idx = mode_shapes->size[0] * mode_shapes->size[1];
  mode_shapes->size[0] = raw_freq_data->size[1];
  mode_shapes->size[1] = proc_tx_mode->size[0];
  emxEnsureCapacity_creal_T(sp, mode_shapes, idx, &td_emlrtRTEI);
  mode_shapes_data = mode_shapes->data;
  for (j = 0; j < b_idx; j++) {
    mode_shapes_data[j].re = 0.0;
    mode_shapes_data[j].im = 0.0;
  }

  if (ms_matrix_calc_freqs->size[1] - 1 >= 0) {
    if (((array_trans_pos_orientations->size[0] == 1) &&
         (array_trans_pos_orientations->size[1] == 1)) ||
        (array_trans_pos_orientations->size[0] != 1)) {
      b = true;
    } else {
      b = false;
    }

    m = array_trans_pos_orientations->size[0];
    n = array_trans_pos_orientations->size[1];
    i1 = ms_matrix_modes_to_use->size[1];
    i2 = proc_tx_mode->size[0];
    i3 = raw_freq_data->size[1];
  }

  emxInit_creal_T(sp, &temp_mode_shape, 3, &vd_emlrtRTEI);
  emxInit_real_T(sp, &temp_waveno, 1, &wd_emlrtRTEI);
  emxInit_creal_T(sp, &r, 2, &ne_emlrtRTEI);
  emxInit_real_T(sp, &maxval, 2, &oe_emlrtRTEI);
  emxInit_creal_T(sp, &y, 2, &ke_emlrtRTEI);
  emxInit_creal_T(sp, &b_a, 2, &ke_emlrtRTEI);
  emxInit_creal_T(sp, &b_b, 2, &pe_emlrtRTEI);
  emxInit_creal_T(sp, &r1, 2, &qe_emlrtRTEI);
  emxInit_real_T(sp, &b_disperse_freq, 1, &yd_emlrtRTEI);
  emxInit_creal_T(sp, &b_disperse_ms_x, 2, &be_emlrtRTEI);
  emxInit_creal_T(sp, &b_temp_mode_shape, 3, &ce_emlrtRTEI);
  emxInit_real_T(sp, &b_disperse_waveno, 1, &me_emlrtRTEI);
  if (i - 1 >= 0) {
    i4 = (int32_T)muDoubleScalarFloor(max_mode_index);
    loop_ub_tmp = (int32_T)max_mode_index;
    i5 = (int32_T)max_mode_index;
    if (i1 - 1 >= 0) {
    }
  }

  for (ii = 0; ii < i; ii++) {
    real_T b_ex;
    real_T y_re;
    int32_T b_loop_ub;
    int32_T c_last;
    int32_T c_loop_ub;
    int32_T d_loop_ub;
    boolean_T overflow;

    /* interpolate to get mode shapes and wavenumbers of all the modes at the current frequency */
    st.site = &hd_emlrtRSI;
    b_st.site = &xb_emlrtRSI;
    c_st.site = &yb_emlrtRSI;
    d_st.site = &ac_emlrtRSI;
    if (!b) {
      emlrtErrorWithMessageIdR2018a(&d_st, &p_emlrtRTEI,
        "Coder:toolbox:autoDimIncompatibility",
        "Coder:toolbox:autoDimIncompatibility", 0);
    }

    if (array_trans_pos_orientations->size[0] < 1) {
      emlrtErrorWithMessageIdR2018a(&d_st, &o_emlrtRTEI,
        "Coder:toolbox:eml_min_or_max_varDimZero",
        "Coder:toolbox:eml_min_or_max_varDimZero", 0);
    }

    e_st.site = &pd_emlrtRSI;
    f_st.site = &qd_emlrtRSI;
    g_st.site = &rd_emlrtRSI;
    idx = maxval->size[0] * maxval->size[1];
    maxval->size[0] = 1;
    c_last = array_trans_pos_orientations->size[1];
    maxval->size[1] = array_trans_pos_orientations->size[1];
    emxEnsureCapacity_real_T(&g_st, maxval, idx, &ud_emlrtRTEI);
    maxval_data = maxval->data;
    if (array_trans_pos_orientations->size[1] >= 1) {
      h_st.site = &td_emlrtRSI;
      if (array_trans_pos_orientations->size[1] > 2147483646) {
        i_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }

      overflow = (m > 2147483646);
      for (j = 0; j < n; j++) {
        maxval_data[j] =
          c_array_trans_pos_orientations_[array_trans_pos_orientations->size[0] *
          j];
        h_st.site = &sd_emlrtRSI;
        if (overflow) {
          i_st.site = &o_emlrtRSI;
          check_forloop_overflow_error(&i_st);
        }

        for (b_i = 2; b_i <= m; b_i++) {
          boolean_T p;
          a = maxval_data[j];
          ex = c_array_trans_pos_orientations_[(b_i +
            array_trans_pos_orientations->size[0] * j) - 1];
          if (muDoubleScalarIsNaN(ex)) {
            p = false;
          } else if (muDoubleScalarIsNaN(a)) {
            p = true;
          } else {
            p = (a < ex);
          }

          if (p) {
            maxval_data[j] = ex;
          }
        }
      }
    }

    st.site = &hd_emlrtRSI;
    b_st.site = &xb_emlrtRSI;
    c_st.site = &yb_emlrtRSI;
    d_st.site = &ac_emlrtRSI;
    if (maxval->size[1] < 1) {
      emlrtErrorWithMessageIdR2018a(&d_st, &o_emlrtRTEI,
        "Coder:toolbox:eml_min_or_max_varDimZero",
        "Coder:toolbox:eml_min_or_max_varDimZero", 0);
    }

    e_st.site = &bc_emlrtRSI;
    f_st.site = &cc_emlrtRSI;
    if (maxval->size[1] <= 2) {
      if (maxval->size[1] == 1) {
        b_ex = maxval_data[0];
      } else if ((maxval_data[0] < maxval_data[1]) || (muDoubleScalarIsNaN
                  (maxval_data[0]) && (!muDoubleScalarIsNaN(maxval_data[1])))) {
        b_ex = maxval_data[1];
      } else {
        b_ex = maxval_data[0];
      }
    } else {
      g_st.site = &ec_emlrtRSI;
      if (!muDoubleScalarIsNaN(maxval_data[0])) {
        b_idx = 1;
      } else {
        b_idx = 0;
        h_st.site = &fc_emlrtRSI;
        if (maxval->size[1] > 2147483646) {
          i_st.site = &o_emlrtRSI;
          check_forloop_overflow_error(&i_st);
        }

        idx = 2;
        exitg1 = false;
        while ((!exitg1) && (idx <= c_last)) {
          if (!muDoubleScalarIsNaN(maxval_data[idx - 1])) {
            b_idx = idx;
            exitg1 = true;
          } else {
            idx++;
          }
        }
      }

      if (b_idx == 0) {
        b_ex = maxval_data[0];
      } else {
        g_st.site = &dc_emlrtRSI;
        b_ex = maxval_data[b_idx - 1];
        idx = b_idx + 1;
        h_st.site = &gc_emlrtRSI;
        if ((b_idx + 1 <= maxval->size[1]) && (maxval->size[1] > 2147483646)) {
          i_st.site = &o_emlrtRSI;
          check_forloop_overflow_error(&i_st);
        }

        for (j = idx; j <= c_last; j++) {
          a = maxval_data[j - 1];
          if (b_ex < a) {
            b_ex = a;
          }
        }
      }
    }

    if (!(max_mode_index >= 0.0)) {
      emlrtNonNegativeCheckR2012b(max_mode_index, &v_emlrtDCI, (emlrtConstCTX)sp);
    }

    if (max_mode_index != i4) {
      emlrtIntegerCheckR2012b(max_mode_index, &u_emlrtDCI, (emlrtConstCTX)sp);
    }

    if (!(b_ex >= 0.0)) {
      emlrtNonNegativeCheckR2012b(b_ex, &t_emlrtDCI, (emlrtConstCTX)sp);
    }

    if (b_ex != (int32_T)muDoubleScalarFloor(b_ex)) {
      emlrtIntegerCheckR2012b(b_ex, &s_emlrtDCI, (emlrtConstCTX)sp);
    }

    idx = temp_mode_shape->size[0] * temp_mode_shape->size[1] *
      temp_mode_shape->size[2];
    temp_mode_shape->size[0] = (int32_T)max_mode_index;
    b_loop_ub = disperse_ms_x->size[1];
    temp_mode_shape->size[1] = disperse_ms_x->size[1];
    c_loop_ub = (int32_T)b_ex;
    temp_mode_shape->size[2] = (int32_T)b_ex;
    emxEnsureCapacity_creal_T(sp, temp_mode_shape, idx, &vd_emlrtRTEI);
    temp_mode_shape_data = temp_mode_shape->data;
    idx = (int32_T)max_mode_index * disperse_ms_x->size[1] * (int32_T)b_ex;
    for (j = 0; j < idx; j++) {
      temp_mode_shape_data[j].re = 0.0;
      temp_mode_shape_data[j].im = 0.0;
    }

    if (max_mode_index != i4) {
      emlrtIntegerCheckR2012b(max_mode_index, &w_emlrtDCI, (emlrtConstCTX)sp);
    }

    idx = temp_waveno->size[0];
    temp_waveno->size[0] = i5;
    emxEnsureCapacity_real_T(sp, temp_waveno, idx, &wd_emlrtRTEI);
    temp_waveno_data = temp_waveno->data;
    if (i5 != i4) {
      emlrtIntegerCheckR2012b(max_mode_index, &w_emlrtDCI, (emlrtConstCTX)sp);
    }

    for (j = 0; j < loop_ub_tmp; j++) {
      temp_waveno_data[j] = 0.0;
    }

    /* Need to make this x, y and z (and perhaps normal and tangential also?) */
    /* so that the necessary direction can be selected when building the */
    /* matrix below. Also, this needs to take into account the phase */
    /* orientation of the transducers which is not currently used?? */
    for (jj = 0; jj < i1; jj++) {
      int32_T b_ms_matrix_modes_to_use;
      int32_T e_loop_ub;
      if (jj + 1 > ms_matrix_modes_to_use->size[1]) {
        emlrtDynamicBoundsCheckR2012b(jj + 1, 1, ms_matrix_modes_to_use->size[1],
          &ec_emlrtBCI, (emlrtConstCTX)sp);
      }

      a = ms_matrix_modes_to_use_data[jj];
      ex = (int32_T)muDoubleScalarFloor(a);
      if (a != ex) {
        emlrtIntegerCheckR2012b(a, &j_emlrtDCI, (emlrtConstCTX)sp);
      }

      overflow = (((int32_T)a < 1) || ((int32_T)a > i5));
      if (overflow) {
        emlrtDynamicBoundsCheckR2012b((int32_T)a, 1, i5, &ub_emlrtBCI,
          (emlrtConstCTX)sp);
      }

      if ((int32_T)b_ex < 1) {
        emlrtDynamicBoundsCheckR2012b(1, 1, (int32_T)b_ex, &tb_emlrtBCI,
          (emlrtConstCTX)sp);
      }

      if (jj + 1 > ms_matrix_modes_to_use->size[1]) {
        emlrtDynamicBoundsCheckR2012b(jj + 1, 1, ms_matrix_modes_to_use->size[1],
          &fc_emlrtBCI, (emlrtConstCTX)sp);
      }

      if (a != ex) {
        emlrtIntegerCheckR2012b(a, &r_emlrtDCI, (emlrtConstCTX)sp);
      }

      if (((int32_T)a < 1) || ((int32_T)a > disperse_freq->size[2])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)a, 1, disperse_freq->size[2],
          &dc_emlrtBCI, (emlrtConstCTX)sp);
      }

      if (jj + 1 > ms_matrix_modes_to_use->size[1]) {
        emlrtDynamicBoundsCheckR2012b(jj + 1, 1, ms_matrix_modes_to_use->size[1],
          &gc_emlrtBCI, (emlrtConstCTX)sp);
      }

      if (a != ex) {
        emlrtIntegerCheckR2012b(a, &q_emlrtDCI, (emlrtConstCTX)sp);
      }

      if (((int32_T)a < 1) || ((int32_T)a > disperse_ms_x->size[2])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)a, 1, disperse_ms_x->size[2],
          &cc_emlrtBCI, (emlrtConstCTX)sp);
      }

      e_loop_ub = disperse_freq->size[0];
      idx = b_disperse_freq->size[0];
      b_disperse_freq->size[0] = disperse_freq->size[0];
      emxEnsureCapacity_real_T(sp, b_disperse_freq, idx, &yd_emlrtRTEI);
      maxval_data = b_disperse_freq->data;
      for (j = 0; j < e_loop_ub; j++) {
        maxval_data[j] = disperse_freq_data[j + disperse_freq->size[0] *
          ((int32_T)a - 1)];
      }

      b_idx = disperse_ms_x->size[0];
      idx = b_disperse_ms_x->size[0] * b_disperse_ms_x->size[1];
      b_disperse_ms_x->size[0] = disperse_ms_x->size[0];
      b_disperse_ms_x->size[1] = b_loop_ub;
      emxEnsureCapacity_creal_T(sp, b_disperse_ms_x, idx, &be_emlrtRTEI);
      b_disperse_ms_x_data = b_disperse_ms_x->data;
      for (j = 0; j < b_loop_ub; j++) {
        for (b_i = 0; b_i < b_idx; b_i++) {
          b_disperse_ms_x_data[b_i + b_disperse_ms_x->size[0] * j] =
            disperse_ms_x_data[(b_i + disperse_ms_x->size[0] * j) +
            disperse_ms_x->size[0] * disperse_ms_x->size[1] * ((int32_T)a - 1)];
        }
      }

      if (ii + 1 > i) {
        emlrtDynamicBoundsCheckR2012b(ii + 1, 1, i, &hc_emlrtBCI, (emlrtConstCTX)
          sp);
      }

      y_re = ms_matrix_calc_freqs_data[ii];
      st.site = &id_emlrtRSI;
      interp1(&st, b_disperse_freq, b_disperse_ms_x, y_re, r);
      b_temp_mode_shape_data = r->data;
      b_inv_mode_shapes[0] = 1;
      b_inv_mode_shapes[1] = b_loop_ub;
      emlrtSubAssignSizeCheckR2012b(&b_inv_mode_shapes[0], 2, &r->size[0], 2,
        &k_emlrtECI, (emlrtCTX)sp);
      b_ms_matrix_modes_to_use = (int32_T)ms_matrix_modes_to_use_data[jj];
      for (j = 0; j < b_loop_ub; j++) {
        temp_mode_shape_data[(b_ms_matrix_modes_to_use + temp_mode_shape->size[0]
                              * j) - 1] = b_temp_mode_shape_data[j];
      }

      if (jj + 1 > ms_matrix_modes_to_use->size[1]) {
        emlrtDynamicBoundsCheckR2012b(jj + 1, 1, ms_matrix_modes_to_use->size[1],
          &lc_emlrtBCI, (emlrtConstCTX)sp);
      }

      if (a != ex) {
        emlrtIntegerCheckR2012b(a, &i_emlrtDCI, (emlrtConstCTX)sp);
      }

      if (overflow) {
        emlrtDynamicBoundsCheckR2012b((int32_T)a, 1, i5, &sb_emlrtBCI,
          (emlrtConstCTX)sp);
      }

      if ((int32_T)b_ex < 2) {
        emlrtDynamicBoundsCheckR2012b(2, 1, (int32_T)b_ex, &rb_emlrtBCI,
          (emlrtConstCTX)sp);
      }

      if (jj + 1 > ms_matrix_modes_to_use->size[1]) {
        emlrtDynamicBoundsCheckR2012b(jj + 1, 1, ms_matrix_modes_to_use->size[1],
          &pc_emlrtBCI, (emlrtConstCTX)sp);
      }

      if (a != ex) {
        emlrtIntegerCheckR2012b(a, &p_emlrtDCI, (emlrtConstCTX)sp);
      }

      if (((int32_T)a < 1) || ((int32_T)a > disperse_freq->size[2])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)a, 1, disperse_freq->size[2],
          &bc_emlrtBCI, (emlrtConstCTX)sp);
      }

      if (jj + 1 > ms_matrix_modes_to_use->size[1]) {
        emlrtDynamicBoundsCheckR2012b(jj + 1, 1, ms_matrix_modes_to_use->size[1],
          &qc_emlrtBCI, (emlrtConstCTX)sp);
      }

      if (a != ex) {
        emlrtIntegerCheckR2012b(a, &o_emlrtDCI, (emlrtConstCTX)sp);
      }

      if (((int32_T)a < 1) || ((int32_T)a > disperse_ms_y->size[2])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)a, 1, disperse_ms_y->size[2],
          &ac_emlrtBCI, (emlrtConstCTX)sp);
      }

      idx = b_disperse_freq->size[0];
      b_disperse_freq->size[0] = disperse_freq->size[0];
      emxEnsureCapacity_real_T(sp, b_disperse_freq, idx, &ee_emlrtRTEI);
      maxval_data = b_disperse_freq->data;
      for (j = 0; j < e_loop_ub; j++) {
        maxval_data[j] = disperse_freq_data[j + disperse_freq->size[0] *
          ((int32_T)a - 1)];
      }

      b_idx = disperse_ms_y->size[0];
      idx = b_disperse_ms_x->size[0] * b_disperse_ms_x->size[1];
      b_disperse_ms_x->size[0] = disperse_ms_y->size[0];
      d_loop_ub = disperse_ms_y->size[1];
      b_disperse_ms_x->size[1] = disperse_ms_y->size[1];
      emxEnsureCapacity_creal_T(sp, b_disperse_ms_x, idx, &ge_emlrtRTEI);
      b_disperse_ms_x_data = b_disperse_ms_x->data;
      for (j = 0; j < d_loop_ub; j++) {
        for (b_i = 0; b_i < b_idx; b_i++) {
          b_disperse_ms_x_data[b_i + b_disperse_ms_x->size[0] * j] =
            disperse_ms_y_data[(b_i + disperse_ms_y->size[0] * j) +
            disperse_ms_y->size[0] * disperse_ms_y->size[1] * ((int32_T)a - 1)];
        }
      }

      if (ii + 1 > i) {
        emlrtDynamicBoundsCheckR2012b(ii + 1, 1, i, &sc_emlrtBCI, (emlrtConstCTX)
          sp);
      }

      st.site = &jd_emlrtRSI;
      interp1(&st, b_disperse_freq, b_disperse_ms_x, y_re, r);
      b_temp_mode_shape_data = r->data;
      b_inv_mode_shapes[0] = 1;
      b_inv_mode_shapes[1] = b_loop_ub;
      emlrtSubAssignSizeCheckR2012b(&b_inv_mode_shapes[0], 2, &r->size[0], 2,
        &j_emlrtECI, (emlrtCTX)sp);
      for (j = 0; j < b_loop_ub; j++) {
        temp_mode_shape_data[((b_ms_matrix_modes_to_use + temp_mode_shape->size
          [0] * j) + temp_mode_shape->size[0] * temp_mode_shape->size[1]) - 1] =
          b_temp_mode_shape_data[j];
      }

      if (jj + 1 > ms_matrix_modes_to_use->size[1]) {
        emlrtDynamicBoundsCheckR2012b(jj + 1, 1, ms_matrix_modes_to_use->size[1],
          &yc_emlrtBCI, (emlrtConstCTX)sp);
      }

      if (a != ex) {
        emlrtIntegerCheckR2012b(a, &h_emlrtDCI, (emlrtConstCTX)sp);
      }

      if (overflow) {
        emlrtDynamicBoundsCheckR2012b((int32_T)a, 1, i5, &qb_emlrtBCI,
          (emlrtConstCTX)sp);
      }

      if ((int32_T)b_ex < 3) {
        emlrtDynamicBoundsCheckR2012b(3, 1, (int32_T)b_ex, &pb_emlrtBCI,
          (emlrtConstCTX)sp);
      }

      if (jj + 1 > ms_matrix_modes_to_use->size[1]) {
        emlrtDynamicBoundsCheckR2012b(jj + 1, 1, ms_matrix_modes_to_use->size[1],
          &ad_emlrtBCI, (emlrtConstCTX)sp);
      }

      if (a != ex) {
        emlrtIntegerCheckR2012b(a, &n_emlrtDCI, (emlrtConstCTX)sp);
      }

      if (((int32_T)a < 1) || ((int32_T)a > disperse_freq->size[2])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)a, 1, disperse_freq->size[2],
          &yb_emlrtBCI, (emlrtConstCTX)sp);
      }

      if (jj + 1 > ms_matrix_modes_to_use->size[1]) {
        emlrtDynamicBoundsCheckR2012b(jj + 1, 1, ms_matrix_modes_to_use->size[1],
          &bd_emlrtBCI, (emlrtConstCTX)sp);
      }

      if (a != ex) {
        emlrtIntegerCheckR2012b(a, &m_emlrtDCI, (emlrtConstCTX)sp);
      }

      if (((int32_T)a < 1) || ((int32_T)a > disperse_ms_z->size[2])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)a, 1, disperse_ms_z->size[2],
          &xb_emlrtBCI, (emlrtConstCTX)sp);
      }

      idx = b_disperse_freq->size[0];
      b_disperse_freq->size[0] = disperse_freq->size[0];
      emxEnsureCapacity_real_T(sp, b_disperse_freq, idx, &ie_emlrtRTEI);
      maxval_data = b_disperse_freq->data;
      for (j = 0; j < e_loop_ub; j++) {
        maxval_data[j] = disperse_freq_data[j + disperse_freq->size[0] *
          ((int32_T)a - 1)];
      }

      b_idx = disperse_ms_z->size[0];
      idx = b_disperse_ms_x->size[0] * b_disperse_ms_x->size[1];
      b_disperse_ms_x->size[0] = disperse_ms_z->size[0];
      d_loop_ub = disperse_ms_z->size[1];
      b_disperse_ms_x->size[1] = disperse_ms_z->size[1];
      emxEnsureCapacity_creal_T(sp, b_disperse_ms_x, idx, &je_emlrtRTEI);
      b_disperse_ms_x_data = b_disperse_ms_x->data;
      for (j = 0; j < d_loop_ub; j++) {
        for (b_i = 0; b_i < b_idx; b_i++) {
          b_disperse_ms_x_data[b_i + b_disperse_ms_x->size[0] * j] =
            disperse_ms_z_data[(b_i + disperse_ms_z->size[0] * j) +
            disperse_ms_z->size[0] * disperse_ms_z->size[1] * ((int32_T)a - 1)];
        }
      }

      if (ii + 1 > i) {
        emlrtDynamicBoundsCheckR2012b(ii + 1, 1, i, &cd_emlrtBCI, (emlrtConstCTX)
          sp);
      }

      st.site = &kd_emlrtRSI;
      interp1(&st, b_disperse_freq, b_disperse_ms_x, y_re, r);
      b_temp_mode_shape_data = r->data;
      b_inv_mode_shapes[0] = 1;
      b_inv_mode_shapes[1] = b_loop_ub;
      emlrtSubAssignSizeCheckR2012b(&b_inv_mode_shapes[0], 2, &r->size[0], 2,
        &i_emlrtECI, (emlrtCTX)sp);
      b_inv_mode_shapes[1] = b_loop_ub;
      for (j = 0; j < b_loop_ub; j++) {
        temp_mode_shape_data[((b_ms_matrix_modes_to_use + temp_mode_shape->size
          [0] * j) + temp_mode_shape->size[0] * temp_mode_shape->size[1] * 2) -
          1] = b_temp_mode_shape_data[j];
      }

      if (jj + 1 > ms_matrix_modes_to_use->size[1]) {
        emlrtDynamicBoundsCheckR2012b(jj + 1, 1, ms_matrix_modes_to_use->size[1],
          &ed_emlrtBCI, (emlrtConstCTX)sp);
      }

      if (a != ex) {
        emlrtIntegerCheckR2012b(a, &l_emlrtDCI, (emlrtConstCTX)sp);
      }

      if (((int32_T)a < 1) || ((int32_T)a > disperse_freq->size[2])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)a, 1, disperse_freq->size[2],
          &wb_emlrtBCI, (emlrtConstCTX)sp);
      }

      if (jj + 1 > ms_matrix_modes_to_use->size[1]) {
        emlrtDynamicBoundsCheckR2012b(jj + 1, 1, ms_matrix_modes_to_use->size[1],
          &hd_emlrtBCI, (emlrtConstCTX)sp);
      }

      if (a != ex) {
        emlrtIntegerCheckR2012b(a, &k_emlrtDCI, (emlrtConstCTX)sp);
      }

      if (((int32_T)a < 1) || ((int32_T)a > disperse_waveno->size[2])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)a, 1, disperse_waveno->size[2],
          &vb_emlrtBCI, (emlrtConstCTX)sp);
      }

      idx = b_disperse_freq->size[0];
      b_disperse_freq->size[0] = disperse_freq->size[0];
      emxEnsureCapacity_real_T(sp, b_disperse_freq, idx, &le_emlrtRTEI);
      maxval_data = b_disperse_freq->data;
      for (j = 0; j < e_loop_ub; j++) {
        maxval_data[j] = disperse_freq_data[j + disperse_freq->size[0] *
          ((int32_T)a - 1)];
      }

      b_idx = disperse_waveno->size[0];
      idx = b_disperse_waveno->size[0];
      b_disperse_waveno->size[0] = disperse_waveno->size[0];
      emxEnsureCapacity_real_T(sp, b_disperse_waveno, idx, &me_emlrtRTEI);
      maxval_data = b_disperse_waveno->data;
      for (j = 0; j < b_idx; j++) {
        maxval_data[j] = disperse_waveno_data[j + disperse_waveno->size[0] *
          ((int32_T)a - 1)];
      }

      if (ii + 1 > i) {
        emlrtDynamicBoundsCheckR2012b(ii + 1, 1, i, &id_emlrtBCI, (emlrtConstCTX)
          sp);
      }

      if (jj + 1 > ms_matrix_modes_to_use->size[1]) {
        emlrtDynamicBoundsCheckR2012b(jj + 1, 1, ms_matrix_modes_to_use->size[1],
          &kd_emlrtBCI, (emlrtConstCTX)sp);
      }

      if (a != ex) {
        emlrtIntegerCheckR2012b(a, &x_emlrtDCI, (emlrtConstCTX)sp);
      }

      if (((int32_T)a < 1) || ((int32_T)a > temp_waveno->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)a, 1, temp_waveno->size[0],
          &jd_emlrtBCI, (emlrtConstCTX)sp);
      }

      st.site = &ld_emlrtRSI;
      temp_waveno_data[(int32_T)a - 1] = b_interp1(&st, b_disperse_freq,
        b_disperse_waveno, y_re);
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtConstCTX)sp);
      }
    }

    /* build the mode shape matrix at this frequency, taking into account the */
    /* orientation of the transducers */
    if (i3 - 1 >= 0) {
      b_inv_mode_shapes[0] = 1;
      b_inv_mode_shapes[1] = 1;
    }

    for (b_i = 0; b_i < i2; b_i++) {
      for (jj = 0; jj < i3; jj++) {
        int64_T i6;
        int64_T i7;
        int64_T i8;
        real_T d;
        if (jj + 1 > mode_shapes->size[0]) {
          emlrtDynamicBoundsCheckR2012b(jj + 1, 1, mode_shapes->size[0],
            &eb_emlrtBCI, (emlrtConstCTX)sp);
        }

        if (b_i + 1 > mode_shapes->size[1]) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, mode_shapes->size[1],
            &db_emlrtBCI, (emlrtConstCTX)sp);
        }

        st.site = &md_emlrtRSI;
        if (b_i + 1 > last) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, last, &kc_emlrtBCI, &st);
        }

        a = proc_tx_mode_data[b_i];
        ex = (int32_T)muDoubleScalarFloor(a);
        if (a != ex) {
          emlrtIntegerCheckR2012b(a, &g_emlrtDCI, &st);
        }

        if (((int32_T)a < 1) || ((int32_T)a > i5)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)a, 1, i5, &ob_emlrtBCI, &st);
        }

        if (jj + 1 > raw_tx->size[0]) {
          emlrtDynamicBoundsCheckR2012b(jj + 1, 1, raw_tx->size[0], &oc_emlrtBCI,
            &st);
        }

        i6 = raw_tx_data[jj];
        if ((i6 < 1LL) || (i6 > array_trans_pos->size[1])) {
          emlrtDynamicBoundsCheckInt64(i6, 1, array_trans_pos->size[1],
            &nc_emlrtBCI, &st);
        }

        i7 = array_trans_pos_data[(int32_T)i6 - 1];
        if ((i7 < 1LL) || (i7 > array_trans_node_list->size[1])) {
          emlrtDynamicBoundsCheckInt64(i7, 1, array_trans_node_list->size[1],
            &mc_emlrtBCI, &st);
        }

        i7 = array_trans_node_list_data[(int32_T)i7 - 1];
        if ((i7 < 1LL) || (i7 > b_loop_ub)) {
          emlrtDynamicBoundsCheckInt64(i7, 1, b_loop_ub, &nb_emlrtBCI, &st);
        }

        idx = b_temp_mode_shape->size[0] * b_temp_mode_shape->size[1] *
          b_temp_mode_shape->size[2];
        b_temp_mode_shape->size[0] = 1;
        b_temp_mode_shape->size[1] = 1;
        b_temp_mode_shape->size[2] = (int32_T)b_ex;
        emxEnsureCapacity_creal_T(&st, b_temp_mode_shape, idx, &ce_emlrtRTEI);
        b_temp_mode_shape_data = b_temp_mode_shape->data;
        for (j = 0; j < c_loop_ub; j++) {
          b_temp_mode_shape_data[j] = temp_mode_shape_data[(((int32_T)
            proc_tx_mode_data[b_i] + temp_mode_shape->size[0] * ((int32_T)i7 - 1))
            + temp_mode_shape->size[0] * temp_mode_shape->size[1] * j) - 1];
        }

        b_st.site = &md_emlrtRSI;
        squeeze(&b_st, b_temp_mode_shape, y);
        if (jj + 1 > raw_tx->size[0]) {
          emlrtDynamicBoundsCheckR2012b(jj + 1, 1, raw_tx->size[0], &rc_emlrtBCI,
            &st);
        }

        if ((int32_T)i6 > array_trans_pos_orientations->size[0]) {
          emlrtDynamicBoundsCheckInt64(i6, 1, array_trans_pos_orientations->
            size[0], &ab_emlrtBCI, &st);
        }

        idx = maxval->size[0] * maxval->size[1];
        maxval->size[0] = 1;
        maxval->size[1] = c_last;
        emxEnsureCapacity_real_T(&st, maxval, idx, &de_emlrtRTEI);
        maxval_data = maxval->data;
        for (j = 0; j < c_last; j++) {
          maxval_data[j] = c_array_trans_pos_orientations_[((int32_T)
            raw_tx_data[jj] + array_trans_pos_orientations->size[0] * j) - 1];
        }

        b_st.site = &md_emlrtRSI;
        b_squeeze(&b_st, maxval);
        b_st.site = &md_emlrtRSI;
        dot(&b_st, y, maxval, b_a);
        if (b_i + 1 > b_last) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, b_last, &tc_emlrtBCI, &st);
        }

        y_re = proc_rx_mode_data[b_i];
        d = (int32_T)muDoubleScalarFloor(y_re);
        if (y_re != d) {
          emlrtIntegerCheckR2012b(y_re, &f_emlrtDCI, &st);
        }

        if (((int32_T)y_re < 1) || ((int32_T)y_re > i5)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)y_re, 1, i5, &mb_emlrtBCI, &st);
        }

        if (jj + 1 > raw_rx->size[0]) {
          emlrtDynamicBoundsCheckR2012b(jj + 1, 1, raw_rx->size[0], &wc_emlrtBCI,
            &st);
        }

        i8 = raw_rx_data[jj];
        if ((i8 < 1LL) || (i8 > array_trans_pos->size[1])) {
          emlrtDynamicBoundsCheckInt64(i8, 1, array_trans_pos->size[1],
            &vc_emlrtBCI, &st);
        }

        i7 = array_trans_pos_data[(int32_T)i8 - 1];
        if ((i7 < 1LL) || (i7 > array_trans_node_list->size[1])) {
          emlrtDynamicBoundsCheckInt64(i7, 1, array_trans_node_list->size[1],
            &uc_emlrtBCI, &st);
        }

        i7 = array_trans_node_list_data[(int32_T)i7 - 1];
        if ((i7 < 1LL) || (i7 > b_loop_ub)) {
          emlrtDynamicBoundsCheckInt64(i7, 1, b_loop_ub, &lb_emlrtBCI, &st);
        }

        idx = b_temp_mode_shape->size[0] * b_temp_mode_shape->size[1] *
          b_temp_mode_shape->size[2];
        b_temp_mode_shape->size[0] = 1;
        b_temp_mode_shape->size[1] = 1;
        b_temp_mode_shape->size[2] = (int32_T)b_ex;
        emxEnsureCapacity_creal_T(&st, b_temp_mode_shape, idx, &fe_emlrtRTEI);
        b_temp_mode_shape_data = b_temp_mode_shape->data;
        for (j = 0; j < c_loop_ub; j++) {
          b_temp_mode_shape_data[j] = temp_mode_shape_data[(((int32_T)
            proc_rx_mode_data[b_i] + temp_mode_shape->size[0] * ((int32_T)i7 - 1))
            + temp_mode_shape->size[0] * temp_mode_shape->size[1] * j) - 1];
        }

        b_st.site = &nd_emlrtRSI;
        squeeze(&b_st, b_temp_mode_shape, y);
        if (jj + 1 > raw_rx->size[0]) {
          emlrtDynamicBoundsCheckR2012b(jj + 1, 1, raw_rx->size[0], &xc_emlrtBCI,
            &st);
        }

        if ((int32_T)i8 > array_trans_pos_orientations->size[0]) {
          emlrtDynamicBoundsCheckInt64(i8, 1, array_trans_pos_orientations->
            size[0], &y_emlrtBCI, &st);
        }

        idx = maxval->size[0] * maxval->size[1];
        maxval->size[0] = 1;
        maxval->size[1] = c_last;
        emxEnsureCapacity_real_T(&st, maxval, idx, &he_emlrtRTEI);
        maxval_data = maxval->data;
        for (j = 0; j < c_last; j++) {
          maxval_data[j] = c_array_trans_pos_orientations_[((int32_T)
            raw_rx_data[jj] + array_trans_pos_orientations->size[0] * j) - 1];
        }

        b_st.site = &nd_emlrtRSI;
        b_squeeze(&b_st, maxval);
        b_st.site = &nd_emlrtRSI;
        dot(&b_st, y, maxval, b_b);
        b_st.site = &jf_emlrtRSI;
        if (b_b->size[0] != 1) {
          if ((b_a->size[0] == 1) || (b_b->size[0] == 1)) {
            emlrtErrorWithMessageIdR2018a(&b_st, &f_emlrtRTEI,
              "Coder:toolbox:mtimes_noDynamicScalarExpansion",
              "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
          } else {
            emlrtErrorWithMessageIdR2018a(&b_st, &e_emlrtRTEI, "MATLAB:innerdim",
              "MATLAB:innerdim", 0);
          }
        }

        b_st.site = &m_emlrtRSI;
        b_mtimes(&b_st, b_a, b_b, y);
        if (b_i + 1 > last) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, last, &dd_emlrtBCI,
            (emlrtConstCTX)sp);
        }

        if (a != ex) {
          emlrtIntegerCheckR2012b(a, &e_emlrtDCI, (emlrtConstCTX)sp);
        }

        if (((int32_T)a < 1) || ((int32_T)a > temp_waveno->size[0])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)a, 1, temp_waveno->size[0],
            &kb_emlrtBCI, (emlrtConstCTX)sp);
        }

        if (jj + 1 > raw_tx->size[0]) {
          emlrtDynamicBoundsCheckR2012b(jj + 1, 1, raw_tx->size[0], &gd_emlrtBCI,
            (emlrtConstCTX)sp);
        }

        if ((int32_T)i6 > array_trans_row->size[1]) {
          emlrtDynamicBoundsCheckInt64(i6, 1, array_trans_row->size[1],
            &fd_emlrtBCI, (emlrtCTX)sp);
        }

        i7 = array_trans_row_data[(int32_T)i6 - 1];
        if ((i7 < 1LL) || (i7 > array_row_pos->size[1])) {
          emlrtDynamicBoundsCheckInt64(i7, 1, array_row_pos->size[1],
            &jb_emlrtBCI, (emlrtCTX)sp);
        }

        if (b_i + 1 > proc_tx_dir->size[0]) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, proc_tx_dir->size[0],
            &ib_emlrtBCI, (emlrtConstCTX)sp);
        }

        a = temp_waveno_data[(int32_T)proc_tx_mode_data[b_i] - 1];
        ex = array_row_pos_data[(int32_T)array_trans_row_data[(int32_T)
          raw_tx_data[jj] - 1] - 1];
        c_b.re = proc_tx_dir_data[b_i] * (ex * (a * 0.0));
        c_b.im = proc_tx_dir_data[b_i] * (ex * a);
        b_exp(&c_b);
        if (b_i + 1 > b_last) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, b_last, &ld_emlrtBCI,
            (emlrtConstCTX)sp);
        }

        if (y_re != d) {
          emlrtIntegerCheckR2012b(y_re, &d_emlrtDCI, (emlrtConstCTX)sp);
        }

        if (((int32_T)y_re < 1) || ((int32_T)y_re > temp_waveno->size[0])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)y_re, 1, temp_waveno->size[0],
            &hb_emlrtBCI, (emlrtConstCTX)sp);
        }

        if (jj + 1 > raw_rx->size[0]) {
          emlrtDynamicBoundsCheckR2012b(jj + 1, 1, raw_rx->size[0], &nd_emlrtBCI,
            (emlrtConstCTX)sp);
        }

        if ((int32_T)i8 > array_trans_row->size[1]) {
          emlrtDynamicBoundsCheckInt64(i8, 1, array_trans_row->size[1],
            &md_emlrtBCI, (emlrtCTX)sp);
        }

        i7 = array_trans_row_data[(int32_T)i8 - 1];
        if ((i7 < 1LL) || (i7 > array_row_pos->size[1])) {
          emlrtDynamicBoundsCheckInt64(i7, 1, array_row_pos->size[1],
            &gb_emlrtBCI, (emlrtCTX)sp);
        }

        if (b_i + 1 > proc_rx_dir->size[0]) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, proc_rx_dir->size[0],
            &fb_emlrtBCI, (emlrtConstCTX)sp);
        }

        a = temp_waveno_data[(int32_T)proc_rx_mode_data[b_i] - 1];
        ex = array_row_pos_data[(int32_T)array_trans_row_data[(int32_T)
          raw_rx_data[jj] - 1] - 1];
        d_b.re = proc_rx_dir_data[b_i] * (ex * (a * 0.0));
        d_b.im = proc_rx_dir_data[b_i] * (ex * a);
        b_exp(&d_b);
        idx = y->size[0] * y->size[1];
        y->size[1] = 1;
        emxEnsureCapacity_creal_T(sp, y, idx, &ke_emlrtRTEI);
        b_temp_mode_shape_data = y->data;
        idx = y->size[0] - 1;
        for (j = 0; j <= idx; j++) {
          a = b_temp_mode_shape_data[j].re;
          ex = b_temp_mode_shape_data[j].im;
          y_re = a * c_b.re - ex * c_b.im;
          a = a * c_b.im + ex * c_b.re;
          b_temp_mode_shape_data[j].re = y_re * d_b.re - a * d_b.im;
          b_temp_mode_shape_data[j].im = y_re * d_b.im + a * d_b.re;
        }

        emlrtSubAssignSizeCheckR2012b(&b_inv_mode_shapes[0], 2, &y->size[0], 2,
          &h_emlrtECI, (emlrtCTX)sp);
        if (y->size[0] < 1) {
          emlrtDynamicBoundsCheckR2012b(1, 1, y->size[0], &cb_emlrtBCI,
            (emlrtConstCTX)sp);
        }

        mode_shapes_data[jj + mode_shapes->size[0] * b_i] =
          b_temp_mode_shape_data[0];
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b((emlrtConstCTX)sp);
        }
      }

      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtConstCTX)sp);
      }
    }

    idx = mode_shapes->size[0] * mode_shapes->size[1];
    for (j = 0; j < idx; j++) {
      if (muDoubleScalarIsNaN(mode_shapes_data[j].re) || muDoubleScalarIsNaN
          (mode_shapes_data[j].im)) {
        if (j > idx - 1) {
          emlrtDynamicBoundsCheckR2012b(j, 0, idx - 1, &ic_emlrtBCI,
            (emlrtConstCTX)sp);
        }

        mode_shapes_data[j].re = 0.0;
        if (j > idx - 1) {
          emlrtDynamicBoundsCheckR2012b(j, 0, idx - 1, &ic_emlrtBCI,
            (emlrtConstCTX)sp);
        }

        mode_shapes_data[j].im = 0.0;
      }
    }

    for (j = 0; j < idx; j++) {
      if (muDoubleScalarIsInf(mode_shapes_data[j].re) || muDoubleScalarIsInf
          (mode_shapes_data[j].im)) {
        if (j > idx - 1) {
          emlrtDynamicBoundsCheckR2012b(j, 0, idx - 1, &jc_emlrtBCI,
            (emlrtConstCTX)sp);
        }

        mode_shapes_data[j].re = 0.0;
        if (j > idx - 1) {
          emlrtDynamicBoundsCheckR2012b(j, 0, idx - 1, &jc_emlrtBCI,
            (emlrtConstCTX)sp);
        }

        mode_shapes_data[j].im = 0.0;
      }
    }

    if (ii + 1 > i) {
      emlrtDynamicBoundsCheckR2012b(ii + 1, 1, i, &bb_emlrtBCI, (emlrtConstCTX)
        sp);
    }

    st.site = &od_emlrtRSI;
    b_idx = mode_shapes->size[0];
    if (mode_shapes->size[0] < mode_shapes->size[1]) {
      d_loop_ub = mode_shapes->size[1];
      idx = b_disperse_ms_x->size[0] * b_disperse_ms_x->size[1];
      b_disperse_ms_x->size[0] = mode_shapes->size[1];
      b_disperse_ms_x->size[1] = mode_shapes->size[0];
      emxEnsureCapacity_creal_T(&st, b_disperse_ms_x, idx, &xd_emlrtRTEI);
      b_disperse_ms_x_data = b_disperse_ms_x->data;
      for (j = 0; j < b_idx; j++) {
        for (b_i = 0; b_i < d_loop_ub; b_i++) {
          b_disperse_ms_x_data[b_i + b_disperse_ms_x->size[0] * j].re =
            mode_shapes_data[j + mode_shapes->size[0] * b_i].re;
          b_disperse_ms_x_data[b_i + b_disperse_ms_x->size[0] * j].im =
            -mode_shapes_data[j + mode_shapes->size[0] * b_i].im;
        }
      }

      b_st.site = &kf_emlrtRSI;
      eml_pinv(&b_st, b_disperse_ms_x, r1);
      b_temp_mode_shape_data = r1->data;
      b_idx = r1->size[1];
      idx = b_disperse_ms_x->size[0] * b_disperse_ms_x->size[1];
      b_disperse_ms_x->size[0] = r1->size[1];
      d_loop_ub = r1->size[0];
      b_disperse_ms_x->size[1] = r1->size[0];
      emxEnsureCapacity_creal_T(&st, b_disperse_ms_x, idx, &ae_emlrtRTEI);
      b_disperse_ms_x_data = b_disperse_ms_x->data;
      for (j = 0; j < d_loop_ub; j++) {
        for (b_i = 0; b_i < b_idx; b_i++) {
          b_disperse_ms_x_data[b_i + b_disperse_ms_x->size[0] * j].re =
            b_temp_mode_shape_data[j + r1->size[0] * b_i].re;
          b_disperse_ms_x_data[b_i + b_disperse_ms_x->size[0] * j].im =
            -b_temp_mode_shape_data[j + r1->size[0] * b_i].im;
        }
      }
    } else {
      b_st.site = &lf_emlrtRSI;
      eml_pinv(&b_st, mode_shapes, b_disperse_ms_x);
      b_disperse_ms_x_data = b_disperse_ms_x->data;
    }

    b_inv_mode_shapes[0] = last;
    b_inv_mode_shapes[1] = loop_ub;
    emlrtSubAssignSizeCheckR2012b(&b_inv_mode_shapes[0], 2,
      &b_disperse_ms_x->size[0], 2, &g_emlrtECI, (emlrtCTX)sp);
    b_inv_mode_shapes[0] = last;
    b_inv_mode_shapes[1] = loop_ub;
    for (j = 0; j < loop_ub; j++) {
      for (b_i = 0; b_i < last; b_i++) {
        inv_mode_shapes_data[(b_i + inv_mode_shapes->size[0] * j) +
          inv_mode_shapes->size[0] * inv_mode_shapes->size[1] * ii] =
          b_disperse_ms_x_data[b_i + last * j];
      }
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }

  emxFree_real_T(sp, &b_disperse_waveno);
  emxFree_creal_T(sp, &b_temp_mode_shape);
  emxFree_creal_T(sp, &b_disperse_ms_x);
  emxFree_real_T(sp, &b_disperse_freq);
  emxFree_creal_T(sp, &r1);
  emxFree_creal_T(sp, &b_b);
  emxFree_creal_T(sp, &b_a);
  emxFree_creal_T(sp, &y);
  emxFree_real_T(sp, &maxval);
  emxFree_creal_T(sp, &r);
  emxFree_real_T(sp, &temp_waveno);
  emxFree_creal_T(sp, &temp_mode_shape);
  emxFree_creal_T(sp, &mode_shapes);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void plus(const emlrtStack *sp, emxArray_real_T *in1, const
                 emxArray_real_T *in2)
{
  jmp_buf * volatile emlrtJBStack;
  emxArray_real_T *b_in1;
  const real_T *in2_data;
  real_T *b_in1_data;
  real_T *in1_data;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int32_T plus_numThreads;
  int32_T stride_0_1;
  int32_T stride_1_1;
  in2_data = in2->data;
  in1_data = in1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_real_T(sp, &b_in1, 2, &uc_emlrtRTEI);
  stride_0_1 = b_in1->size[0] * b_in1->size[1];
  b_in1->size[0] = 1;
  if (in2->size[1] == 1) {
    loop_ub = in1->size[1];
  } else {
    loop_ub = in2->size[1];
  }

  b_in1->size[1] = loop_ub;
  emxEnsureCapacity_real_T(sp, b_in1, stride_0_1, &uc_emlrtRTEI);
  b_in1_data = b_in1->data;
  stride_0_1 = (in1->size[1] != 1);
  stride_1_1 = (in2->size[1] != 1);
  if (loop_ub < 2000) {
    for (i = 0; i < loop_ub; i++) {
      b_in1_data[i] = in1_data[i * stride_0_1] + in2_data[i * stride_1_1];
    }
  } else {
    emlrtEnterParallelRegion((emlrtCTX)sp, omp_in_parallel());
    emlrtPushJmpBuf((emlrtCTX)sp, &emlrtJBStack);
    plus_numThreads = emlrtAllocRegionTLSs(sp->tls, omp_in_parallel(),
      omp_get_max_threads(), omp_get_num_procs());

#pragma omp parallel for \
 num_threads(plus_numThreads)

    for (i = 0; i < loop_ub; i++) {
      b_in1_data[i] = in1_data[i * stride_0_1] + in2_data[i * stride_1_1];
    }

    emlrtPopJmpBuf((emlrtCTX)sp, &emlrtJBStack);
    emlrtExitParallelRegion((emlrtCTX)sp, omp_in_parallel());
  }

  stride_0_1 = in1->size[0] * in1->size[1];
  in1->size[0] = 1;
  in1->size[1] = loop_ub;
  emxEnsureCapacity_real_T(sp, in1, stride_0_1, &uc_emlrtRTEI);
  in1_data = in1->data;
  for (i1 = 0; i1 < loop_ub; i1++) {
    in1_data[i1] = b_in1_data[i1];
  }

  emxFree_real_T(sp, &b_in1);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

emlrtCTX emlrtGetRootTLSGlobal(void)
{
  return emlrtRootTLSGlobal;
}

void emlrtLockerFunction(EmlrtLockeeFunction aLockee, emlrtConstCTX aTLS, void
  *aData)
{
  omp_set_lock(&emlrtLockGlobal);
  emlrtCallLockeeFunction(aLockee, aTLS, aData);
  omp_unset_lock(&emlrtLockGlobal);
}

void fn_process_rail_data_DLL(const emlrtStack *sp, const emxArray_real_T
  *raw_time, emxArray_real_T *raw_time_data, emxArray_int64_T *raw_tx,
  emxArray_int64_T *raw_rx, const emxArray_real_T *array_row_pos, const
  emxArray_int64_T *array_trans_pos, const emxArray_int64_T *array_trans_row,
  const emxArray_real_T *array_trans_pos_orientations, real_T array_delay, const
  emxArray_int64_T *array_trans_node_list, const emxArray_real_T *disperse_freq,
  const emxArray_real_T *disperse_vph, const emxArray_real_T *disperse_vgr,
  const emxArray_real_T *disperse_waveno, const emxArray_creal_T *disperse_ms_x,
  const emxArray_creal_T *disperse_ms_y, const emxArray_creal_T *disperse_ms_z,
  const emxArray_real_T *opts_ms_matrix_modes_to_use, real_T opts_freq_filter_on,
  real_T opts_freq_filter, real_T opts_freq_filter_bandwidth, real_T
  opts_raw_data_zero_dead_time, real_T opts_raw_data_ignore_pulse_echo, real_T
  opts_ms_matrix_bidi_calc, real_T c_opts_ms_matrix_apply_as_time_, real_T
  opts_ms_matrix_time_step_size, real_T opts_ms_matrix_allow_neg_amps,
  emxArray_real_T *opts_ms_matrix_calc_freqs, real_T
  opts_dispersion_compensation, const emxArray_real_T *opts_manual_warps,
  emxArray_real_T *proc_tx_mode, emxArray_real_T *proc_rx_mode, emxArray_real_T *
  proc_tx_dir, emxArray_real_T *proc_rx_dir, emxArray_real_T *proc_dist,
  emxArray_creal_T *proc_dist_data)
{
  __m128d r;
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  jmp_buf * volatile emlrtJBStack;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  emxArray_boolean_T *b_raw_tx;
  emxArray_creal_T *b_inv_full_mode_shapes;
  emxArray_creal_T *b_inv_mode_shapes;
  emxArray_creal_T *c_proc_dist_data;
  emxArray_creal_T *inv_full_mode_shapes;
  emxArray_creal_T *inv_mode_shapes;
  emxArray_creal_T *proc_freq_data;
  emxArray_creal_T *r1;
  emxArray_creal_T *r2;
  emxArray_creal_T *raw_freq_data;
  emxArray_creal_T *yi;
  emxArray_int32_T *b_ii;
  emxArray_int64_T *c_raw_tx;
  emxArray_real_T *b_proc_rx_mode;
  emxArray_real_T *b_proc_tx_mode;
  emxArray_real_T *modal_vgrs;
  emxArray_real_T *pitch_catch_indices;
  creal_T b_dc;
  creal_T *b_inv_mode_shapes_data;
  creal_T *inv_full_mode_shapes_data;
  creal_T *inv_mode_shapes_data;
  creal_T *proc_freq_data_data;
  creal_T *raw_freq_data_data;
  creal_T *yi_data;
  int64_T *c_raw_tx_data;
  int64_T *raw_rx_data;
  int64_T *raw_tx_data;
  real_T dv[2];
  const real_T *b_raw_time_data;
  const real_T *opts_manual_warps_data;
  real_T b_r;
  real_T d;
  real_T f;
  real_T fft_pts;
  real_T y;
  real_T *b_proc_dist_data;
  real_T *b_proc_rx_mode_data;
  real_T *b_proc_tx_mode_data;
  real_T *pitch_catch_indices_data;
  real_T *proc_rx_dir_data;
  real_T *proc_rx_mode_data;
  real_T *proc_tx_dir_data;
  real_T *proc_tx_mode_data;
  real_T *raw_time_data_data;
  int32_T szb[2];
  int32_T b_i;
  int32_T b_loop_ub;
  int32_T c_ii;
  int32_T c_loop_ub;
  int32_T fcount;
  int32_T fn_process_rail_data_DLL_numThreads;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T i4;
  int32_T i5;
  int32_T i6;
  int32_T i7;
  int32_T ii;
  int32_T k;
  int32_T loop_ub;
  int32_T m;
  int32_T md2;
  int32_T nx;
  int32_T pitch_catch_indices_tmp;
  int32_T xtmp;
  int32_T y_tmp;
  int32_T *ii_data;
  char_T TRANSA1;
  char_T TRANSB1;
  boolean_T *b_raw_tx_data;
  (void)array_delay;
  (void)disperse_vph;
  (void)c_opts_ms_matrix_apply_as_time_;
  (void)opts_ms_matrix_time_step_size;
  (void)opts_ms_matrix_allow_neg_amps;
  (void)opts_dispersion_compensation;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  opts_manual_warps_data = opts_manual_warps->data;
  raw_rx_data = raw_rx->data;
  raw_tx_data = raw_tx->data;
  raw_time_data_data = raw_time_data->data;
  b_raw_time_data = raw_time->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);

  /* %raw data */
  /*  %array */
  /*  %although on before, was coded wrong and didn't do anything */
  /*  %not convinced latter two are useful */
  /*  freq_comp_for_input_signal = 0; %NOT IMPLEMENTED */
  /*  raw_data_coupling_comp = 0; %NOT IMPLEMENTED */
  /*  opts_ms_matrix_calc_method = 1; %DOESN't DO OWT */
  /* This is a Matlab coder compatible version of fn_process_rail_data which */
  /* avoids dynamic structures */
  /* -------------------------------------------------------------------------- */
  /* Following eventually to be options but hardcoded to match benchmark for */
  /* now */
  /*  opts_ms_matrix_modes_to_use = 1:4;%temp to get things working */
  /*  opts_freq_filter = 50000; */
  /*  opts_freq_filter_bandwidth = 40000; */
  /*  % freq_comp_for_input_signal = 0; %NOT IMPLEMENTED */
  /*  opts_raw_data_ignore_pulse_echo = 1; */
  /*  % raw_data_coupling_comp = 0; %NOT IMPLEMENTED */
  /*  opts_raw_data_zero_dead_time = 0; %this was coded wrong before and didn't do anything, even when set to non-zero. It is now correct, and zero is needed to turn it off. */
  /*  opts_ms_matrix_calc_method = 1;  */
  /*  opts_ms_matrix_calc_freqs = [30000 34000 38000 42000 46000 50000 54000 58000 62000 66000 70000];%temp to get things working */
  /*   */
  /*  opts_freq_filter_on = 1; */
  /*  opts_ms_matrix_bidi_calc = 0;  */
  /*  opts_ms_matrix_apply_as_time_shift = 0;  */
  /*  opts_ms_matrix_time_step_size = 0; %if non-zero and doing time shifts, this sets the smallest integral multiple of time shifts allowed */
  /*  opts_ms_matrix_allow_neg_amps = 1; */
  /*  opts_dispersion_compensation = 0; */
  /*  opts_manual_warps = [1.02,1.02,1.02,0.952]; */
  /* -------------------------------------------------------------------------- */
  /* Sort out the indices of the outputs */
  st.site = &emlrtRSI;
  emxInit_real_T(&st, &pitch_catch_indices, 1, &xb_emlrtRTEI);
  m = opts_ms_matrix_modes_to_use->size[1];
  md2 = pitch_catch_indices->size[0];
  pitch_catch_indices->size[0] = opts_ms_matrix_modes_to_use->size[1];
  emxEnsureCapacity_real_T(&st, pitch_catch_indices, md2, &jb_emlrtRTEI);
  pitch_catch_indices_data = pitch_catch_indices->data;
  for (i = 0; i < m; i++) {
    pitch_catch_indices_data[i] = 1.0;
  }

  emxInit_real_T(&st, &b_proc_tx_mode, 2, &bd_emlrtRTEI);
  b_st.site = &m_emlrtRSI;
  mtimes(&b_st, pitch_catch_indices, opts_ms_matrix_modes_to_use, b_proc_tx_mode);
  proc_tx_mode_data = b_proc_tx_mode->data;
  emxInit_real_T(sp, &b_proc_rx_mode, 2, &cd_emlrtRTEI);
  m = b_proc_tx_mode->size[1];
  md2 = b_proc_rx_mode->size[0] * b_proc_rx_mode->size[1];
  b_proc_rx_mode->size[0] = b_proc_tx_mode->size[1];
  xtmp = b_proc_tx_mode->size[0];
  b_proc_rx_mode->size[1] = b_proc_tx_mode->size[0];
  emxEnsureCapacity_real_T(sp, b_proc_rx_mode, md2, &kb_emlrtRTEI);
  proc_rx_mode_data = b_proc_rx_mode->data;
  for (i = 0; i < xtmp; i++) {
    for (ii = 0; ii < m; ii++) {
      proc_rx_mode_data[ii + b_proc_rx_mode->size[0] * i] = proc_tx_mode_data[i
        + b_proc_tx_mode->size[0] * ii];
    }
  }

  b_i = b_proc_tx_mode->size[0] + b_proc_tx_mode->size[0];
  loop_ub = b_i * b_proc_tx_mode->size[1];
  md2 = proc_tx_dir->size[0];
  proc_tx_dir->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, proc_tx_dir, md2, &lb_emlrtRTEI);
  proc_tx_dir_data = proc_tx_dir->data;
  b_loop_ub = b_proc_tx_mode->size[0] * b_proc_tx_mode->size[1];
  for (i = 0; i < b_loop_ub; i++) {
    proc_tx_dir_data[i] = 1.0;
  }

  for (i = 0; i < b_loop_ub; i++) {
    proc_tx_dir_data[i + b_loop_ub] = -1.0;
  }

  m = proc_rx_dir->size[0];
  proc_rx_dir->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, proc_rx_dir, m, &mb_emlrtRTEI);
  proc_rx_dir_data = proc_rx_dir->data;
  for (i = 0; i < loop_ub; i++) {
    proc_rx_dir_data[i] = proc_tx_dir_data[i];
  }

  st.site = &b_emlrtRSI;
  if (muDoubleScalarIsNaN(opts_ms_matrix_bidi_calc)) {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI, "MATLAB:nologicalnan",
      "MATLAB:nologicalnan", 0);
  }

  if (opts_ms_matrix_bidi_calc != 0.0) {
    c_loop_ub = proc_tx_dir->size[0] + proc_tx_dir->size[0];
    m = pitch_catch_indices->size[0];
    pitch_catch_indices->size[0] = c_loop_ub;
    emxEnsureCapacity_real_T(sp, pitch_catch_indices, m, &ob_emlrtRTEI);
    pitch_catch_indices_data = pitch_catch_indices->data;
    for (i = 0; i < loop_ub; i++) {
      pitch_catch_indices_data[i] = proc_tx_dir_data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      pitch_catch_indices_data[i + proc_tx_dir->size[0]] = proc_tx_dir_data[i];
    }

    m = proc_tx_dir->size[0];
    proc_tx_dir->size[0] = c_loop_ub;
    emxEnsureCapacity_real_T(sp, proc_tx_dir, m, &qb_emlrtRTEI);
    proc_tx_dir_data = proc_tx_dir->data;
    for (i = 0; i < c_loop_ub; i++) {
      proc_tx_dir_data[i] = pitch_catch_indices_data[i];
    }

    st.site = &c_emlrtRSI;
    m = pitch_catch_indices->size[0];
    pitch_catch_indices->size[0] = loop_ub;
    emxEnsureCapacity_real_T(&st, pitch_catch_indices, m, &rb_emlrtRTEI);
    pitch_catch_indices_data = pitch_catch_indices->data;
    for (i = 0; i < loop_ub; i++) {
      pitch_catch_indices_data[i] = proc_rx_dir_data[i];
    }

    m = proc_rx_dir->size[0] - 1;
    md2 = proc_rx_dir->size[0] >> 1;
    b_st.site = &q_emlrtRSI;
    for (i = 0; i < md2; i++) {
      xtmp = (int32_T)pitch_catch_indices_data[i];
      pitch_catch_indices_tmp = m - i;
      pitch_catch_indices_data[i] =
        pitch_catch_indices_data[pitch_catch_indices_tmp];
      pitch_catch_indices_data[pitch_catch_indices_tmp] = xtmp;
    }

    m = proc_rx_dir->size[0];
    proc_rx_dir->size[0] = c_loop_ub;
    emxEnsureCapacity_real_T(sp, proc_rx_dir, m, &sb_emlrtRTEI);
    proc_rx_dir_data = proc_rx_dir->data;
    for (i = 0; i < loop_ub; i++) {
      proc_rx_dir_data[loop_ub + i] = pitch_catch_indices_data[i];
    }

    md2 = b_i + b_proc_tx_mode->size[0];
    m = proc_tx_mode->size[0];
    proc_tx_mode->size[0] = (md2 + b_proc_tx_mode->size[0]) *
      b_proc_tx_mode->size[1];
    emxEnsureCapacity_real_T(sp, proc_tx_mode, m, &ub_emlrtRTEI);
    b_proc_tx_mode_data = proc_tx_mode->data;
    for (i = 0; i < b_loop_ub; i++) {
      b_proc_tx_mode_data[i] = proc_tx_mode_data[i];
    }

    for (i = 0; i < b_loop_ub; i++) {
      b_proc_tx_mode_data[i + b_loop_ub] = proc_tx_mode_data[i];
    }

    for (i = 0; i < b_loop_ub; i++) {
      b_proc_tx_mode_data[i + loop_ub] = proc_tx_mode_data[i];
    }

    for (i = 0; i < b_loop_ub; i++) {
      b_proc_tx_mode_data[i + md2 * b_proc_tx_mode->size[1]] =
        proc_tx_mode_data[i];
    }

    md2 = b_proc_rx_mode->size[0] + b_proc_rx_mode->size[0];
    xtmp = md2 + b_proc_rx_mode->size[0];
    m = proc_rx_mode->size[0];
    proc_rx_mode->size[0] = (xtmp + b_proc_rx_mode->size[0]) *
      b_proc_rx_mode->size[1];
    emxEnsureCapacity_real_T(sp, proc_rx_mode, m, &wb_emlrtRTEI);
    b_proc_rx_mode_data = proc_rx_mode->data;
    for (i = 0; i < b_loop_ub; i++) {
      b_proc_rx_mode_data[i] = proc_rx_mode_data[i];
    }

    for (i = 0; i < b_loop_ub; i++) {
      b_proc_rx_mode_data[i + b_loop_ub] = proc_rx_mode_data[i];
    }

    for (i = 0; i < b_loop_ub; i++) {
      b_proc_rx_mode_data[i + md2 * b_proc_rx_mode->size[1]] =
        proc_rx_mode_data[i];
    }

    for (i = 0; i < b_loop_ub; i++) {
      b_proc_rx_mode_data[i + xtmp * b_proc_rx_mode->size[1]] =
        proc_rx_mode_data[i];
    }
  } else {
    m = proc_tx_mode->size[0];
    proc_tx_mode->size[0] = loop_ub;
    emxEnsureCapacity_real_T(sp, proc_tx_mode, m, &nb_emlrtRTEI);
    b_proc_tx_mode_data = proc_tx_mode->data;
    for (i = 0; i < b_loop_ub; i++) {
      b_proc_tx_mode_data[i] = proc_tx_mode_data[i];
    }

    for (i = 0; i < b_loop_ub; i++) {
      b_proc_tx_mode_data[i + b_loop_ub] = proc_tx_mode_data[i];
    }

    md2 = proc_rx_mode->size[0];
    proc_rx_mode->size[0] = (b_proc_rx_mode->size[0] + b_proc_rx_mode->size[0]) *
      b_proc_rx_mode->size[1];
    emxEnsureCapacity_real_T(sp, proc_rx_mode, md2, &pb_emlrtRTEI);
    b_proc_rx_mode_data = proc_rx_mode->data;
    for (i = 0; i < b_loop_ub; i++) {
      b_proc_rx_mode_data[i] = proc_rx_mode_data[i];
    }

    for (i = 0; i < b_loop_ub; i++) {
      b_proc_rx_mode_data[i + b_loop_ub] = proc_rx_mode_data[i];
    }
  }

  emxFree_real_T(sp, &b_proc_rx_mode);

  /*  %force single frequency mode shape matrix processing if simulating working in time domain */
  /*  opts_ms_matrix_calc_method = 1; */
  /*  opts_ms_matrix_apply_as_time_shift = 0; */
  /*  if opts_ms_matrix_apply_as_time_shift */
  /*      % opts_ms_matrix_calc_freqs = opts_freq_filter; */
  /*     opts_ms_matrix_calc_method = 1; %to force single mode shape matrix at filter freq only */
  /*  end */
  /*   */
  /*  %set up frequency for mode shape calc if only using single freq */
  /*  if opts_ms_matrix_calc_method == 1 */
  /*      opts_ms_matrix_calc_freqs = opts_freq_filter; */
  /*  end */
  if (opts_ms_matrix_calc_freqs->size[1] == 0) {
    md2 = opts_ms_matrix_calc_freqs->size[0] * opts_ms_matrix_calc_freqs->size[1];
    opts_ms_matrix_calc_freqs->size[0] = 1;
    opts_ms_matrix_calc_freqs->size[1] = 1;
    emxEnsureCapacity_real_T(sp, opts_ms_matrix_calc_freqs, md2, &tb_emlrtRTEI);
    proc_tx_dir_data = opts_ms_matrix_calc_freqs->data;
    proc_tx_dir_data[0] = opts_freq_filter;
  }

  /* zero out dead time if required */
  emxInit_int32_T(sp, &b_ii, 1, &dd_emlrtRTEI);
  if (opts_raw_data_zero_dead_time > 0.0) {
    st.site = &d_emlrtRSI;

    /* -------------------------------------------------------------------------- */
    xtmp = raw_time->size[0];
    m = 0;
    for (i = 0; i < xtmp; i++) {
      if (b_raw_time_data[i] <= opts_raw_data_zero_dead_time) {
        m++;
      }
    }

    md2 = b_ii->size[0];
    b_ii->size[0] = m;
    emxEnsureCapacity_int32_T(&st, b_ii, md2, &sb_emlrtRTEI);
    ii_data = b_ii->data;
    md2 = 0;
    for (i = 0; i < xtmp; i++) {
      if (b_raw_time_data[i] <= opts_raw_data_zero_dead_time) {
        ii_data[md2] = i;
        md2++;
      }
    }

    m = raw_time_data->size[1];
    for (i = 0; i < m; i++) {
      md2 = b_ii->size[0];
      for (ii = 0; ii < md2; ii++) {
        if (ii_data[ii] > raw_time_data->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(ii_data[ii], 0, raw_time_data->size[0] -
            1, &m_emlrtBCI, &st);
        }

        raw_time_data_data[ii_data[ii] + raw_time_data->size[0] * i] = 0.0;
      }
    }
  }

  /* removal of p/e columns if required */
  if (opts_raw_data_ignore_pulse_echo == 1.0) {
    st.site = &e_emlrtRSI;
    xtmp = raw_tx->size[0];
    if ((raw_tx->size[0] != raw_rx->size[0]) && ((raw_tx->size[0] != 1) &&
         (raw_rx->size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(raw_tx->size[0], raw_rx->size[0], &emlrtECI,
        &st);
    }

    b_st.site = &r_emlrtRSI;
    if (raw_tx->size[0] == raw_rx->size[0]) {
      emxInit_boolean_T(&b_st, &b_raw_tx, 1, &vb_emlrtRTEI);
      md2 = b_raw_tx->size[0];
      b_raw_tx->size[0] = raw_tx->size[0];
      emxEnsureCapacity_boolean_T(&b_st, b_raw_tx, md2, &vb_emlrtRTEI);
      b_raw_tx_data = b_raw_tx->data;
      m = raw_tx->size[0];
      if (raw_tx->size[0] < 2000) {
        for (i1 = 0; i1 < xtmp; i1++) {
          b_raw_tx_data[i1] = (raw_tx_data[i1] != raw_rx_data[i1]);
        }
      } else {
        emlrtEnterParallelRegion(&b_st, omp_in_parallel());
        emlrtPushJmpBuf(&b_st, &emlrtJBStack);
        fn_process_rail_data_DLL_numThreads = emlrtAllocRegionTLSs(b_st.tls,
          omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());

#pragma omp parallel for \
 num_threads(fn_process_rail_data_DLL_numThreads)

        for (i1 = 0; i1 < m; i1++) {
          b_raw_tx_data[i1] = (raw_tx_data[i1] != raw_rx_data[i1]);
        }

        emlrtPopJmpBuf(&b_st, &emlrtJBStack);
        emlrtExitParallelRegion(&b_st, omp_in_parallel());
      }

      c_st.site = &s_emlrtRSI;
      eml_find(&c_st, b_raw_tx, b_ii);
      ii_data = b_ii->data;
      emxFree_boolean_T(&b_st, &b_raw_tx);
    } else {
      c_st.site = &s_emlrtRSI;
      binary_expand_op_1(&c_st, b_ii, s_emlrtRSI, raw_tx, raw_rx);
      ii_data = b_ii->data;
    }

    xtmp = b_ii->size[0];
    md2 = pitch_catch_indices->size[0];
    pitch_catch_indices->size[0] = b_ii->size[0];
    emxEnsureCapacity_real_T(&b_st, pitch_catch_indices, md2, &xb_emlrtRTEI);
    pitch_catch_indices_data = pitch_catch_indices->data;
    for (i = 0; i < xtmp; i++) {
      pitch_catch_indices_data[i] = ii_data[i];
    }

    emxInit_int64_T(&st, &c_raw_tx, 1, &yb_emlrtRTEI);
    md2 = c_raw_tx->size[0];
    c_raw_tx->size[0] = b_ii->size[0];
    emxEnsureCapacity_int64_T(&st, c_raw_tx, md2, &yb_emlrtRTEI);
    c_raw_tx_data = c_raw_tx->data;
    for (i = 0; i < xtmp; i++) {
      m = (int32_T)pitch_catch_indices_data[i];
      if ((m < 1) || (m > raw_tx->size[0])) {
        emlrtDynamicBoundsCheckR2012b(m, 1, raw_tx->size[0], &n_emlrtBCI, &st);
      }

      c_raw_tx_data[i] = raw_tx_data[m - 1];
    }

    md2 = c_raw_tx->size[0];
    m = raw_tx->size[0];
    raw_tx->size[0] = c_raw_tx->size[0];
    emxEnsureCapacity_int64_T(&st, raw_tx, m, &ac_emlrtRTEI);
    raw_tx_data = raw_tx->data;
    for (i = 0; i < md2; i++) {
      raw_tx_data[i] = c_raw_tx_data[i];
    }

    md2 = c_raw_tx->size[0];
    c_raw_tx->size[0] = b_ii->size[0];
    emxEnsureCapacity_int64_T(&st, c_raw_tx, md2, &bc_emlrtRTEI);
    c_raw_tx_data = c_raw_tx->data;
    for (i = 0; i < xtmp; i++) {
      m = (int32_T)pitch_catch_indices_data[i];
      if ((m < 1) || (m > raw_rx->size[0])) {
        emlrtDynamicBoundsCheckR2012b(m, 1, raw_rx->size[0], &o_emlrtBCI, &st);
      }

      c_raw_tx_data[i] = raw_rx_data[m - 1];
    }

    md2 = c_raw_tx->size[0];
    m = raw_rx->size[0];
    raw_rx->size[0] = c_raw_tx->size[0];
    emxEnsureCapacity_int64_T(&st, raw_rx, m, &dc_emlrtRTEI);
    raw_rx_data = raw_rx->data;
    for (i = 0; i < md2; i++) {
      raw_rx_data[i] = c_raw_tx_data[i];
    }

    emxFree_int64_T(&st, &c_raw_tx);
    md2 = raw_time_data->size[0];
    m = b_proc_tx_mode->size[0] * b_proc_tx_mode->size[1];
    b_proc_tx_mode->size[0] = raw_time_data->size[0];
    b_proc_tx_mode->size[1] = b_ii->size[0];
    emxEnsureCapacity_real_T(&st, b_proc_tx_mode, m, &fc_emlrtRTEI);
    proc_tx_mode_data = b_proc_tx_mode->data;
    for (i = 0; i < xtmp; i++) {
      for (ii = 0; ii < md2; ii++) {
        m = (int32_T)pitch_catch_indices_data[i];
        if ((m < 1) || (m > raw_time_data->size[1])) {
          emlrtDynamicBoundsCheckR2012b(m, 1, raw_time_data->size[1],
            &p_emlrtBCI, &st);
        }

        proc_tx_mode_data[ii + b_proc_tx_mode->size[0] * i] =
          raw_time_data_data[ii + raw_time_data->size[0] * (m - 1)];
      }
    }

    md2 = raw_time_data->size[0] * raw_time_data->size[1];
    raw_time_data->size[0] = b_proc_tx_mode->size[0];
    raw_time_data->size[1] = b_proc_tx_mode->size[1];
    emxEnsureCapacity_real_T(&st, raw_time_data, md2, &gc_emlrtRTEI);
    raw_time_data_data = raw_time_data->data;
    md2 = b_proc_tx_mode->size[0] * b_proc_tx_mode->size[1];
    for (i = 0; i < md2; i++) {
      raw_time_data_data[i] = proc_tx_mode_data[i];
    }
  }

  emxFree_int32_T(sp, &b_ii);
  emxFree_real_T(sp, &b_proc_tx_mode);

  /* convert to frequency domain */
  st.site = &f_emlrtRSI;
  f = frexp(raw_time_data->size[0], &nx);
  if (f == 0.5) {
    nx--;
  }

  b_st.site = &ab_emlrtRSI;
  c_st.site = &bb_emlrtRSI;
  d_st.site = &cb_emlrtRSI;
  fft_pts = muDoubleScalarPower(2.0, nx);
  emxInit_creal_T(&st, &inv_full_mode_shapes, 2, &ed_emlrtRTEI);
  b_st.site = &y_emlrtRSI;
  fft(&b_st, raw_time_data, fft_pts, inv_full_mode_shapes);
  inv_full_mode_shapes_data = inv_full_mode_shapes->data;
  if (inv_full_mode_shapes->size[0] < 1) {
    emlrtDynamicBoundsCheckR2012b(1, 1, inv_full_mode_shapes->size[0],
      &e_emlrtBCI, &st);
  }

  f = fft_pts / 2.0;
  if (f + 1.0 != muDoubleScalarFloor(f + 1.0)) {
    emlrtIntegerCheckR2012b(f + 1.0, &emlrtDCI, &st);
  }

  m = (int32_T)(f + 1.0);
  pitch_catch_indices_tmp = (int32_T)(f + 1.0);
  if ((int32_T)(f + 1.0) > inv_full_mode_shapes->size[0]) {
    emlrtDynamicBoundsCheckR2012b((int32_T)(f + 1.0), 1,
      inv_full_mode_shapes->size[0], &d_emlrtBCI, &st);
  }

  c_loop_ub = inv_full_mode_shapes->size[1];
  for (i = 0; i < c_loop_ub; i++) {
    for (ii = 0; ii < m; ii++) {
      inv_full_mode_shapes_data[ii + (int32_T)(f + 1.0) * i] =
        inv_full_mode_shapes_data[ii + inv_full_mode_shapes->size[0] * i];
    }
  }

  md2 = inv_full_mode_shapes->size[0] * inv_full_mode_shapes->size[1];
  inv_full_mode_shapes->size[0] = (int32_T)(f + 1.0);
  emxEnsureCapacity_creal_T(&st, inv_full_mode_shapes, md2, &cc_emlrtRTEI);
  inv_full_mode_shapes_data = inv_full_mode_shapes->data;
  if (raw_time->size[0] < 1) {
    emlrtDynamicBoundsCheckR2012b(1, 1, raw_time->size[0], &c_emlrtBCI, &st);
  }

  if (raw_time->size[0] < 2) {
    emlrtDynamicBoundsCheckR2012b(2, 1, raw_time->size[0], &b_emlrtBCI, &st);
  }

  y = 1.0 / (fft_pts * muDoubleScalarAbs(b_raw_time_data[0] - b_raw_time_data[1]));
  md2 = pitch_catch_indices->size[0];
  pitch_catch_indices->size[0] = (int32_T)f + 1;
  emxEnsureCapacity_real_T(&st, pitch_catch_indices, md2, &ec_emlrtRTEI);
  pitch_catch_indices_data = pitch_catch_indices->data;
  m = (int32_T)f;
  md2 = (((int32_T)f + 1) / 2) << 1;
  xtmp = md2 - 2;
  for (i = 0; i <= xtmp; i += 2) {
    dv[0] = i;
    dv[1] = i + 1;
    r = _mm_loadu_pd(&dv[0]);
    _mm_storeu_pd(&pitch_catch_indices_data[i], _mm_mul_pd(r, _mm_set1_pd(y)));
  }

  for (i = md2; i <= m; i++) {
    pitch_catch_indices_data[i] = (real_T)i * y;
  }

  if (raw_time->size[0] < 1) {
    emlrtDynamicBoundsCheckR2012b(1, 1, raw_time->size[0], &emlrtBCI, &st);
  }

  b_st.site = &x_emlrtRSI;
  f = b_raw_time_data[0];
  emxInit_creal_T(&b_st, &r1, 1, &ic_emlrtRTEI);
  nx = pitch_catch_indices->size[0];
  m = r1->size[0];
  r1->size[0] = pitch_catch_indices->size[0];
  emxEnsureCapacity_creal_T(&b_st, r1, m, &hc_emlrtRTEI);
  inv_mode_shapes_data = r1->data;
  m = pitch_catch_indices->size[0];
  md2 = (pitch_catch_indices->size[0] < 2000);
  if (md2) {
    for (i2 = 0; i2 < nx; i2++) {
      inv_mode_shapes_data[i2].re = f * (pitch_catch_indices_data[i2] * -0.0);
      inv_mode_shapes_data[i2].im = f * (pitch_catch_indices_data[i2] *
        -6.2831853071795862);
    }
  } else {
    emlrtEnterParallelRegion(&b_st, omp_in_parallel());
    emlrtPushJmpBuf(&b_st, &emlrtJBStack);
    fn_process_rail_data_DLL_numThreads = emlrtAllocRegionTLSs(b_st.tls,
      omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());

#pragma omp parallel for \
 num_threads(fn_process_rail_data_DLL_numThreads)

    for (i2 = 0; i2 < m; i2++) {
      inv_mode_shapes_data[i2].re = f * (pitch_catch_indices_data[i2] * -0.0);
      inv_mode_shapes_data[i2].im = f * (pitch_catch_indices_data[i2] *
        -6.2831853071795862);
    }

    emlrtPopJmpBuf(&b_st, &emlrtJBStack);
    emlrtExitParallelRegion(&b_st, omp_in_parallel());
  }

  c_st.site = &kb_emlrtRSI;
  d_st.site = &lb_emlrtRSI;
  if (md2) {
    for (k = 0; k < nx; k++) {
      if (inv_mode_shapes_data[k].re == 0.0) {
        f = inv_mode_shapes_data[k].im;
        inv_mode_shapes_data[k].re = muDoubleScalarCos(f);
        inv_mode_shapes_data[k].im = muDoubleScalarSin(f);
      } else if (inv_mode_shapes_data[k].im == 0.0) {
        inv_mode_shapes_data[k].re = muDoubleScalarExp(inv_mode_shapes_data[k].
          re);
        inv_mode_shapes_data[k].im = 0.0;
      } else if (muDoubleScalarIsInf(inv_mode_shapes_data[k].im) &&
                 muDoubleScalarIsInf(inv_mode_shapes_data[k].re) &&
                 (inv_mode_shapes_data[k].re < 0.0)) {
        inv_mode_shapes_data[k] = dc;
      } else {
        b_r = muDoubleScalarExp(inv_mode_shapes_data[k].re / 2.0);
        f = inv_mode_shapes_data[k].im;
        inv_mode_shapes_data[k].re = b_r * (b_r * muDoubleScalarCos(f));
        inv_mode_shapes_data[k].im = b_r * (b_r * muDoubleScalarSin(f));
      }
    }
  } else {
    emlrtEnterParallelRegion(&c_st, omp_in_parallel());
    emlrtPushJmpBuf(&c_st, &emlrtJBStack);
    fn_process_rail_data_DLL_numThreads = emlrtAllocRegionTLSs(c_st.tls,
      omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());

#pragma omp parallel for \
 num_threads(fn_process_rail_data_DLL_numThreads) \
 private(b_r,b_dc,d)

    for (k = 0; k < nx; k++) {
      if (inv_mode_shapes_data[k].re == 0.0) {
        d = inv_mode_shapes_data[k].im;
        b_dc.re = muDoubleScalarCos(d);
        b_dc.im = muDoubleScalarSin(d);
        inv_mode_shapes_data[k] = b_dc;
      } else if (inv_mode_shapes_data[k].im == 0.0) {
        b_dc.re = muDoubleScalarExp(inv_mode_shapes_data[k].re);
        b_dc.im = 0.0;
        inv_mode_shapes_data[k] = b_dc;
      } else if (muDoubleScalarIsInf(inv_mode_shapes_data[k].im) &&
                 muDoubleScalarIsInf(inv_mode_shapes_data[k].re) &&
                 (inv_mode_shapes_data[k].re < 0.0)) {
        inv_mode_shapes_data[k] = dc;
      } else {
        b_r = muDoubleScalarExp(inv_mode_shapes_data[k].re / 2.0);
        d = inv_mode_shapes_data[k].im;
        b_dc.re = b_r * (b_r * muDoubleScalarCos(d));
        b_dc.im = b_r * (b_r * muDoubleScalarSin(d));
        inv_mode_shapes_data[k] = b_dc;
      }
    }

    emlrtPopJmpBuf(&c_st, &emlrtJBStack);
    emlrtExitParallelRegion(&c_st, omp_in_parallel());
  }

  if ((pitch_catch_indices_tmp != nx) && ((pitch_catch_indices_tmp != 1) && (nx
        != 1))) {
    emlrtDimSizeImpxCheckR2021b(pitch_catch_indices_tmp, nx, &b_emlrtECI, &st);
  }

  emxInit_creal_T(&st, &b_inv_full_mode_shapes, 2, &ic_emlrtRTEI);
  if (inv_full_mode_shapes->size[0] == r1->size[0]) {
    m = b_inv_full_mode_shapes->size[0] * b_inv_full_mode_shapes->size[1];
    b_inv_full_mode_shapes->size[0] = pitch_catch_indices_tmp;
    b_inv_full_mode_shapes->size[1] = c_loop_ub;
    emxEnsureCapacity_creal_T(&st, b_inv_full_mode_shapes, m, &ic_emlrtRTEI);
    yi_data = b_inv_full_mode_shapes->data;
    for (i = 0; i < c_loop_ub; i++) {
      for (ii = 0; ii < pitch_catch_indices_tmp; ii++) {
        real_T d1;
        real_T d2;
        f = inv_full_mode_shapes_data[ii + inv_full_mode_shapes->size[0] * i].re;
        y = inv_mode_shapes_data[ii].im;
        d1 = inv_full_mode_shapes_data[ii + inv_full_mode_shapes->size[0] * i].
          im;
        d2 = inv_mode_shapes_data[ii].re;
        yi_data[ii + b_inv_full_mode_shapes->size[0] * i].re = f * d2 - d1 * y;
        yi_data[ii + b_inv_full_mode_shapes->size[0] * i].im = f * y + d1 * d2;
      }
    }

    m = inv_full_mode_shapes->size[0] * inv_full_mode_shapes->size[1];
    inv_full_mode_shapes->size[0] = pitch_catch_indices_tmp;
    inv_full_mode_shapes->size[1] = c_loop_ub;
    emxEnsureCapacity_creal_T(&st, inv_full_mode_shapes, m, &jc_emlrtRTEI);
    inv_full_mode_shapes_data = inv_full_mode_shapes->data;
    md2 = b_inv_full_mode_shapes->size[0] * b_inv_full_mode_shapes->size[1];
    for (i = 0; i < md2; i++) {
      inv_full_mode_shapes_data[i] = yi_data[i];
    }
  } else {
    b_st.site = &x_emlrtRSI;
    binary_expand_op(&b_st, inv_full_mode_shapes, r1);
    inv_full_mode_shapes_data = inv_full_mode_shapes->data;
  }

  /*  %coupling compensation if required */
  /*  if options.raw_data_coupling_comp ~= 0 */
  /*      raw_data = fn_coupling_comp(raw_data, array, options); */
  /*  end */
  /* frequency domain processing */
  emxInit_creal_T(sp, &raw_freq_data, 2, &sb_emlrtRTEI);
  md2 = raw_freq_data->size[0] * raw_freq_data->size[1];
  raw_freq_data->size[0] = inv_full_mode_shapes->size[0];
  raw_freq_data->size[1] = inv_full_mode_shapes->size[1];
  emxEnsureCapacity_creal_T(sp, raw_freq_data, md2, &kc_emlrtRTEI);
  raw_freq_data_data = raw_freq_data->data;
  md2 = inv_full_mode_shapes->size[0] * inv_full_mode_shapes->size[1];
  for (i = 0; i < md2; i++) {
    raw_freq_data_data[i] = inv_full_mode_shapes_data[i];
  }

  st.site = &g_emlrtRSI;
  y = fn_filter_freq_domain_data(&st, pitch_catch_indices, raw_freq_data,
    opts_freq_filter_on, opts_freq_filter, opts_freq_filter_bandwidth, &f);
  raw_freq_data_data = raw_freq_data->data;

  /* build inverse mode shape matrix at frequency(s) required  */
  emxInit_creal_T(sp, &inv_mode_shapes, 3, &ad_emlrtRTEI);
  st.site = &h_emlrtRSI;
  fn_inv_mode_shape_matrices(&st, raw_tx, raw_rx, raw_freq_data, array_row_pos,
    array_trans_pos, array_trans_row, array_trans_pos_orientations,
    array_trans_node_list, disperse_freq, disperse_waveno, disperse_ms_x,
    disperse_ms_y, disperse_ms_z, proc_tx_mode, proc_rx_mode, proc_tx_dir,
    proc_rx_dir, opts_ms_matrix_calc_freqs, opts_ms_matrix_modes_to_use,
    inv_mode_shapes);
  b_inv_mode_shapes_data = inv_mode_shapes->data;

  /*  %array */
  /* do the mode extraction */
  st.site = &i_emlrtRSI;

  /* actually do the multiplication to convert the raw freq domain data */
  /* to mode extracted freq domain data by one of two methods (single frequency mode shapes or interpolated frequency) */
  emxInit_creal_T(&st, &proc_freq_data, 2, &lc_emlrtRTEI);
  loop_ub = raw_freq_data->size[0];
  m = proc_freq_data->size[0] * proc_freq_data->size[1];
  proc_freq_data->size[0] = raw_freq_data->size[0];
  b_loop_ub = inv_mode_shapes->size[0];
  proc_freq_data->size[1] = inv_mode_shapes->size[0];
  emxEnsureCapacity_creal_T(&st, proc_freq_data, m, &lc_emlrtRTEI);
  proc_freq_data_data = proc_freq_data->data;
  m = raw_freq_data->size[0] * inv_mode_shapes->size[0];
  for (i = 0; i < m; i++) {
    proc_freq_data_data[i].re = 0.0;
    proc_freq_data_data[i].im = 0.0;
  }

  b_i = (int32_T)(f + (1.0 - y));
  emxInit_creal_T(&st, &yi, 2, &fd_emlrtRTEI);
  emxInit_creal_T(&st, &r2, 2, &gd_emlrtRTEI);
  emxInit_creal_T(&st, &b_inv_mode_shapes, 3, &qc_emlrtRTEI);
  for (fcount = 0; fcount < b_i; fcount++) {
    f = y + (real_T)fcount;
    m = inv_full_mode_shapes->size[0] * inv_full_mode_shapes->size[1];
    inv_full_mode_shapes->size[0] = b_loop_ub;
    pitch_catch_indices_tmp = inv_mode_shapes->size[1];
    inv_full_mode_shapes->size[1] = inv_mode_shapes->size[1];
    emxEnsureCapacity_creal_T(&st, inv_full_mode_shapes, m, &mc_emlrtRTEI);
    inv_full_mode_shapes_data = inv_full_mode_shapes->data;
    c_loop_ub = inv_mode_shapes->size[0] * inv_mode_shapes->size[1];
    for (i = 0; i < c_loop_ub; i++) {
      inv_full_mode_shapes_data[i].re = 0.0;
      inv_full_mode_shapes_data[i].im = 0.0;
    }

    for (c_ii = 0; c_ii < b_loop_ub; c_ii++) {
      b_st.site = &ig_emlrtRSI;
      if (c_ii + 1 > b_loop_ub) {
        emlrtDynamicBoundsCheckR2012b(c_ii + 1, 1, b_loop_ub, &f_emlrtBCI, &b_st);
      }

      szb[0] = 1;
      szb[1] = pitch_catch_indices_tmp;
      xtmp = inv_mode_shapes->size[2];
      if (inv_mode_shapes->size[2] != 1) {
        m = 0;
        if (inv_mode_shapes->size[1] != 1) {
          m = 1;
          szb[0] = inv_mode_shapes->size[1];
        }

        if (inv_mode_shapes->size[2] != 1) {
          szb[m] = inv_mode_shapes->size[2];
        }
      }

      c_st.site = &cf_emlrtRSI;
      md2 = inv_mode_shapes->size[1] * inv_mode_shapes->size[2];
      d_st.site = &ve_emlrtRSI;
      m = 1;
      if (inv_mode_shapes->size[1] > 1) {
        m = inv_mode_shapes->size[1];
      }

      if (inv_mode_shapes->size[2] > m) {
        m = inv_mode_shapes->size[2];
      }

      m = muIntScalarMax_sint32(md2, m);
      if (szb[0] > m) {
        emlrtErrorWithMessageIdR2018a(&c_st, &c_emlrtRTEI,
          "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
      }

      if (szb[1] > m) {
        emlrtErrorWithMessageIdR2018a(&c_st, &c_emlrtRTEI,
          "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
      }

      if (szb[0] * szb[1] != md2) {
        emlrtErrorWithMessageIdR2018a(&c_st, &d_emlrtRTEI,
          "Coder:MATLAB:getReshapeDims_notSameNumel",
          "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
      }

      m = b_inv_mode_shapes->size[0] * b_inv_mode_shapes->size[1] *
        b_inv_mode_shapes->size[2];
      b_inv_mode_shapes->size[0] = 1;
      b_inv_mode_shapes->size[1] = pitch_catch_indices_tmp;
      b_inv_mode_shapes->size[2] = inv_mode_shapes->size[2];
      emxEnsureCapacity_creal_T(&st, b_inv_mode_shapes, m, &qc_emlrtRTEI);
      inv_mode_shapes_data = b_inv_mode_shapes->data;
      for (ii = 0; ii < xtmp; ii++) {
        for (i = 0; i < pitch_catch_indices_tmp; i++) {
          inv_mode_shapes_data[i + b_inv_mode_shapes->size[1] * ii] =
            b_inv_mode_shapes_data[(c_ii + inv_mode_shapes->size[0] * i) +
            inv_mode_shapes->size[0] * inv_mode_shapes->size[1] * ii];
        }
      }

      m = b_inv_full_mode_shapes->size[0] * b_inv_full_mode_shapes->size[1];
      b_inv_full_mode_shapes->size[0] = szb[1];
      b_inv_full_mode_shapes->size[1] = szb[0];
      emxEnsureCapacity_creal_T(&st, b_inv_full_mode_shapes, m, &rc_emlrtRTEI);
      yi_data = b_inv_full_mode_shapes->data;
      m = szb[0];
      for (i = 0; i < m; i++) {
        md2 = szb[1];
        for (ii = 0; ii < md2; ii++) {
          yi_data[ii + b_inv_full_mode_shapes->size[0] * i] =
            inv_mode_shapes_data[i + szb[0] * ii];
        }
      }

      if (((int32_T)f < 1) || ((int32_T)f > nx)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)f, 1, nx, &w_emlrtBCI, &st);
      }

      b_st.site = &jg_emlrtRSI;
      c_interp1(&b_st, opts_ms_matrix_calc_freqs, b_inv_full_mode_shapes,
                pitch_catch_indices_data[(int32_T)f - 1], yi);
      yi_data = yi->data;
      if (c_ii + 1 > b_loop_ub) {
        emlrtDynamicBoundsCheckR2012b(c_ii + 1, 1, b_loop_ub, &g_emlrtBCI, &st);
      }

      szb[0] = 1;
      szb[1] = pitch_catch_indices_tmp;
      emlrtSubAssignSizeCheckR2012b(&szb[0], 2, &yi->size[0], 2, &c_emlrtECI,
        &st);
      for (i = 0; i < pitch_catch_indices_tmp; i++) {
        inv_full_mode_shapes_data[c_ii + inv_full_mode_shapes->size[0] * i] =
          yi_data[i];
      }

      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }

    for (i = 0; i < c_loop_ub; i++) {
      if (muDoubleScalarIsNaN(inv_full_mode_shapes_data[i].re) ||
          muDoubleScalarIsNaN(inv_full_mode_shapes_data[i].im)) {
        if (i > c_loop_ub - 1) {
          emlrtDynamicBoundsCheckR2012b(i, 0, c_loop_ub - 1, &q_emlrtBCI, &st);
        }

        inv_full_mode_shapes_data[i].re = 0.0;
        if (i > c_loop_ub - 1) {
          emlrtDynamicBoundsCheckR2012b(i, 0, c_loop_ub - 1, &q_emlrtBCI, &st);
        }

        inv_full_mode_shapes_data[i].im = 0.0;
      }
    }

    if (((int32_T)f < 1) || ((int32_T)f > loop_ub)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)f, 1, loop_ub, &h_emlrtBCI, &st);
    }

    b_st.site = &kg_emlrtRSI;
    m = yi->size[0] * yi->size[1];
    yi->size[0] = 1;
    md2 = raw_freq_data->size[1];
    yi->size[1] = raw_freq_data->size[1];
    emxEnsureCapacity_creal_T(&b_st, yi, m, &oc_emlrtRTEI);
    yi_data = yi->data;
    for (i = 0; i < md2; i++) {
      yi_data[i] = raw_freq_data_data[((int32_T)f + raw_freq_data->size[0] * i)
        - 1];
    }

    c_st.site = &jf_emlrtRSI;
    if (raw_freq_data->size[1] != inv_full_mode_shapes->size[1]) {
      if ((raw_freq_data->size[1] == 1) || ((inv_full_mode_shapes->size[0] == 1)
           && (inv_full_mode_shapes->size[1] == 1))) {
        emlrtErrorWithMessageIdR2018a(&c_st, &f_emlrtRTEI,
          "Coder:toolbox:mtimes_noDynamicScalarExpansion",
          "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&c_st, &e_emlrtRTEI, "MATLAB:innerdim",
          "MATLAB:innerdim", 0);
      }
    }

    c_st.site = &m_emlrtRSI;
    if ((raw_freq_data->size[1] == 0) || (inv_full_mode_shapes->size[0] == 0) ||
        (inv_full_mode_shapes->size[1] == 0)) {
      m = r2->size[0] * r2->size[1];
      r2->size[0] = 1;
      r2->size[1] = b_loop_ub;
      emxEnsureCapacity_creal_T(&c_st, r2, m, &oc_emlrtRTEI);
      inv_mode_shapes_data = r2->data;
      for (i = 0; i < b_loop_ub; i++) {
        inv_mode_shapes_data[i] = dc;
      }
    } else {
      d_st.site = &n_emlrtRSI;
      e_st.site = &p_emlrtRSI;
      TRANSB1 = 'T';
      TRANSA1 = 'N';
      m_t = (ptrdiff_t)1;
      n_t = (ptrdiff_t)inv_full_mode_shapes->size[0];
      k_t = (ptrdiff_t)raw_freq_data->size[1];
      lda_t = (ptrdiff_t)1;
      ldb_t = (ptrdiff_t)inv_full_mode_shapes->size[0];
      ldc_t = (ptrdiff_t)1;
      m = r2->size[0] * r2->size[1];
      r2->size[0] = 1;
      r2->size[1] = b_loop_ub;
      emxEnsureCapacity_creal_T(&e_st, r2, m, &pc_emlrtRTEI);
      inv_mode_shapes_data = r2->data;
      zgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, (real_T *)&dc1, (real_T *)
            &yi_data[0], &lda_t, (real_T *)&inv_full_mode_shapes_data[0], &ldb_t,
            (real_T *)&dc, (real_T *)&inv_mode_shapes_data[0], &ldc_t);
    }

    szb[0] = 1;
    szb[1] = b_loop_ub;
    emlrtSubAssignSizeCheckR2012b(&szb[0], 2, &r2->size[0], 2, &d_emlrtECI, &st);
    for (i = 0; i < b_loop_ub; i++) {
      proc_freq_data_data[((int32_T)f + proc_freq_data->size[0] * i) - 1] =
        inv_mode_shapes_data[i];
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }

  emxFree_creal_T(&st, &b_inv_mode_shapes);
  emxFree_creal_T(&st, &b_inv_full_mode_shapes);
  emxFree_creal_T(&st, &r2);
  emxFree_creal_T(&st, &yi);
  emxFree_creal_T(&st, &raw_freq_data);
  emxFree_creal_T(&st, &inv_mode_shapes);

  /* Convert from freq to distance */
  /*  if opts_dispersion_compensation */
  /*      %TODO - will go directly from freq to dist */
  /*      %must remember to make sure modal_vgrs is generated in proc_data */
  /*      %for use with warping */
  /*  else */
  /* Convert from freq to time */
  st.site = &j_emlrtRSI;
  if (nx < 2) {
    emlrtDynamicBoundsCheckR2012b(2, 1, nx, &i_emlrtBCI, &st);
  }

  f = 1.0 / (fft_pts * muDoubleScalarAbs(pitch_catch_indices_data[1] -
              pitch_catch_indices_data[0]));
  emxInit_real_T(&st, &proc_rx_dir, 2, &hd_emlrtRTEI);
  proc_rx_dir_data = proc_rx_dir->data;
  if (fft_pts - 1.0 < 0.0) {
    proc_rx_dir->size[0] = 1;
    proc_rx_dir->size[1] = 0;
  } else {
    md2 = proc_rx_dir->size[0] * proc_rx_dir->size[1];
    proc_rx_dir->size[0] = 1;
    proc_rx_dir->size[1] = (int32_T)(fft_pts - 1.0) + 1;
    emxEnsureCapacity_real_T(&st, proc_rx_dir, md2, &nc_emlrtRTEI);
    proc_rx_dir_data = proc_rx_dir->data;
    md2 = (int32_T)(fft_pts - 1.0);
    for (i = 0; i <= md2; i++) {
      proc_rx_dir_data[i] = i;
    }
  }

  b_st.site = &lg_emlrtRSI;
  ifft(&b_st, proc_freq_data, fft_pts, inv_full_mode_shapes);
  emxFree_creal_T(&st, &proc_freq_data);

  /* Convert from time to distance */
  emxInit_real_T(sp, &opts_ms_matrix_calc_freqs, 2, &wc_emlrtRTEI);
  md2 = opts_ms_matrix_calc_freqs->size[0] * opts_ms_matrix_calc_freqs->size[1];
  opts_ms_matrix_calc_freqs->size[0] = 1;
  xtmp = proc_rx_dir->size[1];
  opts_ms_matrix_calc_freqs->size[1] = proc_rx_dir->size[1];
  emxEnsureCapacity_real_T(sp, opts_ms_matrix_calc_freqs, md2, &hc_emlrtRTEI);
  raw_time_data_data = opts_ms_matrix_calc_freqs->data;
  m = (proc_rx_dir->size[1] / 2) << 1;
  md2 = m - 2;
  for (i = 0; i <= md2; i += 2) {
    r = _mm_loadu_pd(&proc_rx_dir_data[i]);
    _mm_storeu_pd(&raw_time_data_data[i], _mm_mul_pd(r, _mm_set1_pd(f)));
  }

  for (i = m; i < xtmp; i++) {
    raw_time_data_data[i] = proc_rx_dir_data[i] * f;
  }

  emxInit_real_T(sp, &modal_vgrs, 2, &sb_emlrtRTEI);
  st.site = &k_emlrtRSI;
  fn_convert_time_to_dist(&st, opts_ms_matrix_calc_freqs, inv_full_mode_shapes,
    proc_tx_mode, proc_rx_mode, disperse_freq, disperse_vgr, disperse_waveno,
    opts_ms_matrix_modes_to_use, opts_freq_filter, proc_dist, proc_dist_data,
    modal_vgrs);
  proc_tx_mode_data = modal_vgrs->data;
  yi_data = proc_dist_data->data;
  b_proc_dist_data = proc_dist->data;
  emxFree_creal_T(sp, &inv_full_mode_shapes);

  /*  end */
  /* Warp distance axes if desired according to opts_manual_warps (vector of */
  /* warp factors for each mode) */
  if (opts_manual_warps->size[1] != 0) {
    __m128d r3;
    st.site = &l_emlrtRSI;
    b_st.site = &xg_emlrtRSI;
    c_st.site = &ah_emlrtRSI;
    b_indexShapeCheck(&c_st, modal_vgrs->size, proc_tx_mode->size[0]);
    pitch_catch_indices_tmp = proc_tx_mode->size[0];
    for (i = 0; i < pitch_catch_indices_tmp; i++) {
      if (b_proc_tx_mode_data[i] != (int32_T)muDoubleScalarFloor
          (b_proc_tx_mode_data[i])) {
        emlrtIntegerCheckR2012b(b_proc_tx_mode_data[i], &b_emlrtDCI, &b_st);
      }

      md2 = (int32_T)b_proc_tx_mode_data[i];
      if ((md2 < 1) || (md2 > modal_vgrs->size[1])) {
        emlrtDynamicBoundsCheckR2012b(md2, 1, modal_vgrs->size[1], &r_emlrtBCI,
          &b_st);
      }
    }

    c_st.site = &bh_emlrtRSI;
    b_indexShapeCheck(&c_st, modal_vgrs->size, proc_rx_mode->size[0]);
    c_loop_ub = proc_rx_mode->size[0];
    for (i = 0; i < c_loop_ub; i++) {
      if (b_proc_rx_mode_data[i] != (int32_T)muDoubleScalarFloor
          (b_proc_rx_mode_data[i])) {
        emlrtIntegerCheckR2012b(b_proc_rx_mode_data[i], &c_emlrtDCI, &b_st);
      }

      m = (int32_T)b_proc_rx_mode_data[i];
      if ((m < 1) || (m > modal_vgrs->size[1])) {
        emlrtDynamicBoundsCheckR2012b(m, 1, modal_vgrs->size[1], &s_emlrtBCI,
          &b_st);
      }
    }

    c_st.site = &ch_emlrtRSI;
    b_indexShapeCheck(&c_st, modal_vgrs->size, proc_tx_mode->size[0]);
    c_st.site = &ch_emlrtRSI;
    b_indexShapeCheck(&c_st, opts_manual_warps->size, proc_tx_mode->size[0]);
    for (i = 0; i < pitch_catch_indices_tmp; i++) {
      m = (int32_T)b_proc_tx_mode_data[i];
      if ((m < 1) || (m > modal_vgrs->size[1])) {
        emlrtDynamicBoundsCheckR2012b(m, 1, modal_vgrs->size[1], &t_emlrtBCI,
          &b_st);
      }
    }

    for (i = 0; i < pitch_catch_indices_tmp; i++) {
      m = (int32_T)b_proc_tx_mode_data[i];
      if ((m < 1) || (m > opts_manual_warps->size[1])) {
        emlrtDynamicBoundsCheckR2012b(m, 1, opts_manual_warps->size[1],
          &u_emlrtBCI, &b_st);
      }
    }

    c_st.site = &dh_emlrtRSI;
    b_indexShapeCheck(&c_st, modal_vgrs->size, proc_rx_mode->size[0]);
    c_st.site = &dh_emlrtRSI;
    b_indexShapeCheck(&c_st, opts_manual_warps->size, proc_rx_mode->size[0]);
    for (i = 0; i < c_loop_ub; i++) {
      m = (int32_T)b_proc_rx_mode_data[i];
      if ((m < 1) || (m > modal_vgrs->size[1])) {
        emlrtDynamicBoundsCheckR2012b(m, 1, modal_vgrs->size[1], &v_emlrtBCI,
          &b_st);
      }
    }

    for (i = 0; i < c_loop_ub; i++) {
      m = (int32_T)b_proc_rx_mode_data[i];
      if ((m < 1) || (m > opts_manual_warps->size[1])) {
        emlrtDynamicBoundsCheckR2012b(m, 1, opts_manual_warps->size[1],
          &x_emlrtBCI, &b_st);
      }
    }

    md2 = opts_ms_matrix_calc_freqs->size[0] * opts_ms_matrix_calc_freqs->size[1];
    opts_ms_matrix_calc_freqs->size[0] = 1;
    opts_ms_matrix_calc_freqs->size[1] = proc_tx_mode->size[0];
    emxEnsureCapacity_real_T(&b_st, opts_ms_matrix_calc_freqs, md2,
      &sc_emlrtRTEI);
    raw_time_data_data = opts_ms_matrix_calc_freqs->data;
    m = proc_tx_mode->size[0];
    md2 = (proc_tx_mode->size[0] < 2000);
    if (md2) {
      for (i3 = 0; i3 < pitch_catch_indices_tmp; i3++) {
        raw_time_data_data[i3] = 1.0 / proc_tx_mode_data[(int32_T)
          b_proc_tx_mode_data[i3] - 1];
      }
    } else {
      emlrtEnterParallelRegion(&b_st, omp_in_parallel());
      emlrtPushJmpBuf(&b_st, &emlrtJBStack);
      fn_process_rail_data_DLL_numThreads = emlrtAllocRegionTLSs(b_st.tls,
        omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());

#pragma omp parallel for \
 num_threads(fn_process_rail_data_DLL_numThreads)

      for (i3 = 0; i3 < m; i3++) {
        raw_time_data_data[i3] = 1.0 / proc_tx_mode_data[(int32_T)
          b_proc_tx_mode_data[i3] - 1];
      }

      emlrtPopJmpBuf(&b_st, &emlrtJBStack);
      emlrtExitParallelRegion(&b_st, omp_in_parallel());
    }

    emxInit_real_T(&b_st, &proc_tx_dir, 2, &sc_emlrtRTEI);
    m = proc_tx_dir->size[0] * proc_tx_dir->size[1];
    proc_tx_dir->size[0] = 1;
    proc_tx_dir->size[1] = c_loop_ub;
    emxEnsureCapacity_real_T(&b_st, proc_tx_dir, m, &tc_emlrtRTEI);
    proc_rx_mode_data = proc_tx_dir->data;
    xtmp = (proc_rx_mode->size[0] < 2000);
    if (xtmp) {
      for (i4 = 0; i4 < c_loop_ub; i4++) {
        proc_rx_mode_data[i4] = 1.0 / proc_tx_mode_data[(int32_T)
          b_proc_rx_mode_data[i4] - 1];
      }
    } else {
      emlrtEnterParallelRegion(&b_st, omp_in_parallel());
      emlrtPushJmpBuf(&b_st, &emlrtJBStack);
      fn_process_rail_data_DLL_numThreads = emlrtAllocRegionTLSs(b_st.tls,
        omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());

#pragma omp parallel for \
 num_threads(fn_process_rail_data_DLL_numThreads)

      for (i4 = 0; i4 < c_loop_ub; i4++) {
        proc_rx_mode_data[i4] = 1.0 / proc_tx_mode_data[(int32_T)
          b_proc_rx_mode_data[i4] - 1];
      }

      emlrtPopJmpBuf(&b_st, &emlrtJBStack);
      emlrtExitParallelRegion(&b_st, omp_in_parallel());
    }

    if ((pitch_catch_indices_tmp != c_loop_ub) && ((pitch_catch_indices_tmp != 1)
         && (c_loop_ub != 1))) {
      emlrtDimSizeImpxCheckR2021b(pitch_catch_indices_tmp, c_loop_ub,
        &f_emlrtECI, &b_st);
    }

    m = proc_rx_dir->size[0] * proc_rx_dir->size[1];
    proc_rx_dir->size[0] = 1;
    proc_rx_dir->size[1] = pitch_catch_indices_tmp;
    emxEnsureCapacity_real_T(&b_st, proc_rx_dir, m, &uc_emlrtRTEI);
    proc_rx_dir_data = proc_rx_dir->data;
    if (md2) {
      for (i5 = 0; i5 < pitch_catch_indices_tmp; i5++) {
        m = (int32_T)b_proc_tx_mode_data[i5] - 1;
        proc_rx_dir_data[i5] = 1.0 / (proc_tx_mode_data[m] *
          opts_manual_warps_data[m]);
      }
    } else {
      emlrtEnterParallelRegion(&b_st, omp_in_parallel());
      emlrtPushJmpBuf(&b_st, &emlrtJBStack);
      fn_process_rail_data_DLL_numThreads = emlrtAllocRegionTLSs(b_st.tls,
        omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());

#pragma omp parallel for \
 num_threads(fn_process_rail_data_DLL_numThreads) \
 private(y_tmp)

      for (i5 = 0; i5 < pitch_catch_indices_tmp; i5++) {
        y_tmp = (int32_T)b_proc_tx_mode_data[i5] - 1;
        proc_rx_dir_data[i5] = 1.0 / (proc_tx_mode_data[y_tmp] *
          opts_manual_warps_data[y_tmp]);
      }

      emlrtPopJmpBuf(&b_st, &emlrtJBStack);
      emlrtExitParallelRegion(&b_st, omp_in_parallel());
    }

    emxInit_real_T(&b_st, &raw_time_data, 2, &uc_emlrtRTEI);
    md2 = raw_time_data->size[0] * raw_time_data->size[1];
    raw_time_data->size[0] = 1;
    raw_time_data->size[1] = c_loop_ub;
    emxEnsureCapacity_real_T(&b_st, raw_time_data, md2, &vc_emlrtRTEI);
    proc_tx_dir_data = raw_time_data->data;
    if (xtmp) {
      for (i6 = 0; i6 < c_loop_ub; i6++) {
        md2 = (int32_T)b_proc_rx_mode_data[i6] - 1;
        proc_tx_dir_data[i6] = 1.0 / (proc_tx_mode_data[md2] *
          opts_manual_warps_data[md2]);
      }
    } else {
      emlrtEnterParallelRegion(&b_st, omp_in_parallel());
      emlrtPushJmpBuf(&b_st, &emlrtJBStack);
      fn_process_rail_data_DLL_numThreads = emlrtAllocRegionTLSs(b_st.tls,
        omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());

#pragma omp parallel for \
 num_threads(fn_process_rail_data_DLL_numThreads) \
 private(i7)

      for (i6 = 0; i6 < c_loop_ub; i6++) {
        i7 = (int32_T)b_proc_rx_mode_data[i6] - 1;
        proc_tx_dir_data[i6] = 1.0 / (proc_tx_mode_data[i7] *
          opts_manual_warps_data[i7]);
      }

      emlrtPopJmpBuf(&b_st, &emlrtJBStack);
      emlrtExitParallelRegion(&b_st, omp_in_parallel());
    }

    c_st.site = &eh_emlrtRSI;
    if (opts_ms_matrix_calc_freqs->size[1] == proc_tx_dir->size[1]) {
      xtmp = opts_ms_matrix_calc_freqs->size[1] - 1;
      md2 = opts_ms_matrix_calc_freqs->size[0] * opts_ms_matrix_calc_freqs->
        size[1];
      opts_ms_matrix_calc_freqs->size[0] = 1;
      emxEnsureCapacity_real_T(&c_st, opts_ms_matrix_calc_freqs, md2,
        &sc_emlrtRTEI);
      raw_time_data_data = opts_ms_matrix_calc_freqs->data;
      m = (opts_ms_matrix_calc_freqs->size[1] / 2) << 1;
      md2 = m - 2;
      for (i = 0; i <= md2; i += 2) {
        r = _mm_loadu_pd(&raw_time_data_data[i]);
        r3 = _mm_loadu_pd(&proc_rx_mode_data[i]);
        _mm_storeu_pd(&raw_time_data_data[i], _mm_add_pd(r, r3));
      }

      for (i = m; i <= xtmp; i++) {
        raw_time_data_data[i] += proc_rx_mode_data[i];
      }
    } else {
      d_st.site = &eh_emlrtRSI;
      plus(&d_st, opts_ms_matrix_calc_freqs, proc_tx_dir);
    }

    emxFree_real_T(&c_st, &proc_tx_dir);
    if (proc_rx_dir->size[1] == raw_time_data->size[1]) {
      xtmp = proc_rx_dir->size[1] - 1;
      md2 = proc_rx_dir->size[0] * proc_rx_dir->size[1];
      proc_rx_dir->size[0] = 1;
      emxEnsureCapacity_real_T(&c_st, proc_rx_dir, md2, &uc_emlrtRTEI);
      proc_rx_dir_data = proc_rx_dir->data;
      m = (proc_rx_dir->size[1] / 2) << 1;
      md2 = m - 2;
      for (i = 0; i <= md2; i += 2) {
        r = _mm_loadu_pd(&proc_rx_dir_data[i]);
        r3 = _mm_loadu_pd(&proc_tx_dir_data[i]);
        _mm_storeu_pd(&proc_rx_dir_data[i], _mm_add_pd(r, r3));
      }

      for (i = m; i <= xtmp; i++) {
        proc_rx_dir_data[i] += proc_tx_dir_data[i];
      }
    } else {
      d_st.site = &eh_emlrtRSI;
      plus(&d_st, proc_rx_dir, raw_time_data);
      proc_rx_dir_data = proc_rx_dir->data;
    }

    emxFree_real_T(&c_st, &raw_time_data);
    d_st.site = &fh_emlrtRSI;
    e_st.site = &gh_emlrtRSI;
    if ((opts_ms_matrix_calc_freqs->size[1] != 1) && (proc_rx_dir->size[1] != 1)
        && (opts_ms_matrix_calc_freqs->size[1] != proc_rx_dir->size[1])) {
      emlrtErrorWithMessageIdR2018a(&e_st, &emlrtRTEI,
        "MATLAB:sizeDimensionsMustMatch", "MATLAB:sizeDimensionsMustMatch", 0);
    }

    if (opts_ms_matrix_calc_freqs->size[1] == proc_rx_dir->size[1]) {
      xtmp = opts_ms_matrix_calc_freqs->size[1] - 1;
      md2 = opts_ms_matrix_calc_freqs->size[0] * opts_ms_matrix_calc_freqs->
        size[1];
      opts_ms_matrix_calc_freqs->size[0] = 1;
      emxEnsureCapacity_real_T(&d_st, opts_ms_matrix_calc_freqs, md2,
        &wc_emlrtRTEI);
      raw_time_data_data = opts_ms_matrix_calc_freqs->data;
      m = (opts_ms_matrix_calc_freqs->size[1] / 2) << 1;
      md2 = m - 2;
      for (i = 0; i <= md2; i += 2) {
        r = _mm_loadu_pd(&raw_time_data_data[i]);
        r3 = _mm_loadu_pd(&proc_rx_dir_data[i]);
        _mm_storeu_pd(&raw_time_data_data[i], _mm_div_pd(r, r3));
      }

      for (i = m; i <= xtmp; i++) {
        raw_time_data_data[i] /= proc_rx_dir_data[i];
      }
    } else {
      e_st.site = &hh_emlrtRSI;
      rdivide(&e_st, opts_ms_matrix_calc_freqs, proc_rx_dir);
      raw_time_data_data = opts_ms_matrix_calc_freqs->data;
    }

    pitch_catch_indices_tmp = proc_dist_data->size[1];
    emxInit_creal_T(&st, &c_proc_dist_data, 1, &yc_emlrtRTEI);
    for (ii = 0; ii < pitch_catch_indices_tmp; ii++) {
      if (ii + 1 > opts_ms_matrix_calc_freqs->size[1]) {
        emlrtDynamicBoundsCheckR2012b(ii + 1, 1, opts_ms_matrix_calc_freqs->
          size[1], &j_emlrtBCI, &st);
      }

      if (ii + 1 > pitch_catch_indices_tmp) {
        emlrtDynamicBoundsCheckR2012b(ii + 1, 1, pitch_catch_indices_tmp,
          &l_emlrtBCI, &st);
      }

      f = raw_time_data_data[ii];
      if (ii + 1 > pitch_catch_indices_tmp) {
        emlrtDynamicBoundsCheckR2012b(ii + 1, 1, pitch_catch_indices_tmp,
          &k_emlrtBCI, &st);
      }

      xtmp = proc_dist->size[0];
      m = pitch_catch_indices->size[0];
      pitch_catch_indices->size[0] = proc_dist->size[0];
      emxEnsureCapacity_real_T(&st, pitch_catch_indices, m, &xc_emlrtRTEI);
      pitch_catch_indices_data = pitch_catch_indices->data;
      m = (proc_dist->size[0] / 2) << 1;
      md2 = m - 2;
      for (i = 0; i <= md2; i += 2) {
        r = _mm_loadu_pd(&b_proc_dist_data[i]);
        _mm_storeu_pd(&pitch_catch_indices_data[i], _mm_div_pd(r, _mm_set1_pd(f)));
      }

      for (i = m; i < xtmp; i++) {
        pitch_catch_indices_data[i] = b_proc_dist_data[i] / f;
      }

      md2 = proc_dist_data->size[0];
      m = c_proc_dist_data->size[0];
      c_proc_dist_data->size[0] = proc_dist_data->size[0];
      emxEnsureCapacity_creal_T(&st, c_proc_dist_data, m, &yc_emlrtRTEI);
      inv_mode_shapes_data = c_proc_dist_data->data;
      for (i = 0; i < md2; i++) {
        inv_mode_shapes_data[i] = yi_data[i + proc_dist_data->size[0] * ii];
      }

      b_st.site = &yg_emlrtRSI;
      e_interp1(&b_st, pitch_catch_indices, c_proc_dist_data, proc_dist, r1);
      inv_mode_shapes_data = r1->data;
      emlrtSubAssignSizeCheckR2012b(&proc_dist_data->size[0], 1, &r1->size[0], 1,
        &e_emlrtECI, &st);
      for (i = 0; i < md2; i++) {
        yi_data[i + proc_dist_data->size[0] * ii] = inv_mode_shapes_data[i];
      }

      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }

    emxFree_creal_T(&st, &c_proc_dist_data);
  }

  emxFree_real_T(sp, &opts_ms_matrix_calc_freqs);
  emxFree_real_T(sp, &proc_rx_dir);
  emxFree_creal_T(sp, &r1);
  emxFree_real_T(sp, &pitch_catch_indices);
  emxFree_real_T(sp, &modal_vgrs);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (fn_process_rail_data_DLL.c) */
