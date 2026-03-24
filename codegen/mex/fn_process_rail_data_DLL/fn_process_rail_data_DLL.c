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
#include "angle.h"
#include "assertCompatibleDims.h"
#include "div.h"
#include "dot.h"
#include "eml_int_forloop_overflow_check.h"
#include "exp.h"
#include "fft.h"
#include "find.h"
#include "flipud.h"
#include "fn_process_rail_data_DLL_data.h"
#include "fn_process_rail_data_DLL_emxutil.h"
#include "fn_process_rail_data_DLL_types.h"
#include "ifft.h"
#include "indexShapeCheck.h"
#include "interp1.h"
#include "linspace.h"
#include "mrdivide_helper.h"
#include "mtimes.h"
#include "pinv.h"
#include "round.h"
#include "rt_nonfinite.h"
#include "squeeze.h"
#include "sum.h"
#include "mwmathutil.h"
#include "omp.h"
#include <emmintrin.h>
#include <math.h>

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

static emlrtRSInfo hd_emlrtRSI = { 216,/* lineNo */
  "fn_inv_mode_shape_matrices",        /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo id_emlrtRSI = { 220,/* lineNo */
  "fn_inv_mode_shape_matrices",        /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo jd_emlrtRSI = { 224,/* lineNo */
  "fn_inv_mode_shape_matrices",        /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo kd_emlrtRSI = { 228,/* lineNo */
  "fn_inv_mode_shape_matrices",        /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo ld_emlrtRSI = { 238,/* lineNo */
  "fn_inv_mode_shape_matrices",        /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo md_emlrtRSI = { 239,/* lineNo */
  "fn_inv_mode_shape_matrices",        /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo nd_emlrtRSI = { 246,/* lineNo */
  "fn_inv_mode_shape_matrices",        /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo pe_emlrtRSI = { 52, /* lineNo */
  "reshapeSizeChecks",                 /* fcnName */
  "C:\\Program Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\reshapeSizeChecks.m"/* pathName */
};

static emlrtRSInfo qe_emlrtRSI = { 114,/* lineNo */
  "computeDimsData",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\reshapeSizeChecks.m"/* pathName */
};

static emlrtRSInfo df_emlrtRSI = { 19, /* lineNo */
  "pinv",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\matfun\\pinv.m"/* pathName */
};

static emlrtRSInfo ef_emlrtRSI = { 21, /* lineNo */
  "pinv",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\matfun\\pinv.m"/* pathName */
};

static emlrtRSInfo bg_emlrtRSI = { 259,/* lineNo */
  "fn_mode_extract_freq_dom",          /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo cg_emlrtRSI = { 260,/* lineNo */
  "fn_mode_extract_freq_dom",          /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo dg_emlrtRSI = { 262,/* lineNo */
  "fn_mode_extract_freq_dom",          /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo eg_emlrtRSI = { 265,/* lineNo */
  "fn_mode_extract_freq_dom",          /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo fg_emlrtRSI = { 266,/* lineNo */
  "fn_mode_extract_freq_dom",          /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo gg_emlrtRSI = { 267,/* lineNo */
  "fn_mode_extract_freq_dom",          /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo hg_emlrtRSI = { 268,/* lineNo */
  "fn_mode_extract_freq_dom",          /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo ig_emlrtRSI = { 269,/* lineNo */
  "fn_mode_extract_freq_dom",          /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo jg_emlrtRSI = { 270,/* lineNo */
  "fn_mode_extract_freq_dom",          /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo kg_emlrtRSI = { 271,/* lineNo */
  "fn_mode_extract_freq_dom",          /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo lg_emlrtRSI = { 272,/* lineNo */
  "fn_mode_extract_freq_dom",          /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo mg_emlrtRSI = { 273,/* lineNo */
  "fn_mode_extract_freq_dom",          /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo ng_emlrtRSI = { 276,/* lineNo */
  "fn_mode_extract_freq_dom",          /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo og_emlrtRSI = { 278,/* lineNo */
  "fn_mode_extract_freq_dom",          /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo pg_emlrtRSI = { 281,/* lineNo */
  "fn_mode_extract_freq_dom",          /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo qg_emlrtRSI = { 282,/* lineNo */
  "fn_mode_extract_freq_dom",          /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo rg_emlrtRSI = { 289,/* lineNo */
  "fn_mode_extract_freq_dom",          /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo sg_emlrtRSI = { 290,/* lineNo */
  "fn_mode_extract_freq_dom",          /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo tg_emlrtRSI = { 294,/* lineNo */
  "fn_mode_extract_freq_dom",          /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo ug_emlrtRSI = { 69, /* lineNo */
  "eml_mtimes_helper",                 /* fcnName */
  "C:\\Program Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m"/* pathName */
};

static emlrtRSInfo yg_emlrtRSI = { 20, /* lineNo */
  "mrdivide_helper",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\mrdivide_helper.m"/* pathName */
};

static emlrtRSInfo yh_emlrtRSI = { 303,/* lineNo */
  "fn_convert_freq_to_time_dom",       /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo bi_emlrtRSI = { 310,/* lineNo */
  "fn_convert_time_to_dist",           /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo ci_emlrtRSI = { 311,/* lineNo */
  "fn_convert_time_to_dist",           /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo di_emlrtRSI = { 313,/* lineNo */
  "fn_convert_time_to_dist",           /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo ei_emlrtRSI = { 317,/* lineNo */
  "fn_convert_time_to_dist",           /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo fi_emlrtRSI = { 326,/* lineNo */
  "fn_convert_time_to_dist",           /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo gi_emlrtRSI = { 327,/* lineNo */
  "fn_convert_time_to_dist",           /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo hi_emlrtRSI = { 337,/* lineNo */
  "fn_convert_time_to_dist",           /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo li_emlrtRSI = { 343,/* lineNo */
  "fn_apply_dist_warps",               /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo mi_emlrtRSI = { 348,/* lineNo */
  "fn_apply_dist_warps",               /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo ni_emlrtRSI = { 353,/* lineNo */
  "fn_calc_warp_factors",              /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo oi_emlrtRSI = { 354,/* lineNo */
  "fn_calc_warp_factors",              /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo pi_emlrtRSI = { 355,/* lineNo */
  "fn_calc_warp_factors",              /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo qi_emlrtRSI = { 356,/* lineNo */
  "fn_calc_warp_factors",              /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo ri_emlrtRSI = { 357,/* lineNo */
  "fn_calc_warp_factors",              /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

static emlrtRSInfo si_emlrtRSI = { 34, /* lineNo */
  "rdivide_helper",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\rdivide_helper.m"/* pathName */
};

static emlrtRSInfo ti_emlrtRSI = { 53, /* lineNo */
  "div",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\div.m"/* pathName */
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
  259,                                 /* lineNo */
  55,                                  /* colNo */
  "inv_mode_shapes",                   /* aName */
  "fn_mode_extract_freq_dom",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  262,                                 /* lineNo */
  54,                                  /* colNo */
  "raw_freq_data",                     /* aName */
  "fn_mode_extract_freq_dom",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  262,                                 /* lineNo */
  62,                                  /* colNo */
  "raw_freq_data",                     /* aName */
  "fn_mode_extract_freq_dom",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  281,                                 /* lineNo */
  48,                                  /* colNo */
  "freq",                              /* aName */
  "fn_mode_extract_freq_dom",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo c_emlrtECI = { 1,   /* nDims */
  281,                                 /* lineNo */
  11,                                  /* colNo */
  "fn_mode_extract_freq_dom",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtBCInfo j_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  289,                                 /* lineNo */
  33,                                  /* colNo */
  "inv_mode_shapes",                   /* aName */
  "fn_mode_extract_freq_dom",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  291,                                 /* lineNo */
  25,                                  /* colNo */
  "inv_full_mode_shapes",              /* aName */
  "fn_mode_extract_freq_dom",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo d_emlrtECI = { -1,  /* nDims */
  291,                                 /* lineNo */
  4,                                   /* colNo */
  "fn_mode_extract_freq_dom",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtECInfo e_emlrtECI = { -1,  /* nDims */
  262,                                 /* lineNo */
  3,                                   /* colNo */
  "fn_mode_extract_freq_dom",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtBCInfo l_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  282,                                 /* lineNo */
  19,                                  /* colNo */
  "proc_freq_data",                    /* aName */
  "fn_mode_extract_freq_dom",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo f_emlrtECI = { -1,  /* nDims */
  282,                                 /* lineNo */
  4,                                   /* colNo */
  "fn_mode_extract_freq_dom",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtBCInfo m_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  294,                                 /* lineNo */
  18,                                  /* colNo */
  "proc_freq_data",                    /* aName */
  "fn_mode_extract_freq_dom",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo g_emlrtECI = { -1,  /* nDims */
  294,                                 /* lineNo */
  3,                                   /* colNo */
  "fn_mode_extract_freq_dom",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo emlrtRTEI = { 16,  /* lineNo */
  19,                                  /* colNo */
  "mrdivide_helper",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\mrdivide_helper.m"/* pName */
};

static emlrtBCInfo n_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  300,                                 /* lineNo */
  22,                                  /* colNo */
  "freq",                              /* aName */
  "fn_convert_freq_to_time_dom",       /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  347,                                 /* lineNo */
  41,                                  /* colNo */
  "warp_factors",                      /* aName */
  "fn_apply_dist_warps",               /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  348,                                 /* lineNo */
  65,                                  /* colNo */
  "proc_dist_data",                    /* aName */
  "fn_apply_dist_warps",               /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  348,                                 /* lineNo */
  23,                                  /* colNo */
  "proc_dist_data",                    /* aName */
  "fn_apply_dist_warps",               /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo h_emlrtECI = { -1,  /* nDims */
  348,                                 /* lineNo */
  5,                                   /* colNo */
  "fn_apply_dist_warps",               /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtECInfo i_emlrtECI = { 2,   /* nDims */
  357,                                 /* lineNo */
  17,                                  /* colNo */
  "fn_calc_warp_factors",              /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo b_emlrtRTEI = { 13,/* lineNo */
  13,                                  /* colNo */
  "toLogicalCheck",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\toLogicalCheck.m"/* pName */
};

static emlrtRTEInfo c_emlrtRTEI = { 138,/* lineNo */
  23,                                  /* colNo */
  "dynamic_size_checks",               /* fName */
  "C:\\Program Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m"/* pName */
};

static emlrtRTEInfo d_emlrtRTEI = { 133,/* lineNo */
  23,                                  /* colNo */
  "dynamic_size_checks",               /* fName */
  "C:\\Program Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m"/* pName */
};

static emlrtBCInfo r_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  137,                                 /* lineNo */
  1,                                   /* colNo */
  "time_data",                         /* aName */
  "fn_zero_dead_zone",                 /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo s_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  142,                                 /* lineNo */
  9,                                   /* colNo */
  "tx",                                /* aName */
  "fn_remove_pulse_echo_data",         /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo t_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  143,                                 /* lineNo */
  9,                                   /* colNo */
  "rx",                                /* aName */
  "fn_remove_pulse_echo_data",         /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo u_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  144,                                 /* lineNo */
  26,                                  /* colNo */
  "time_data",                         /* aName */
  "fn_remove_pulse_echo_data",         /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo v_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  293,                                 /* lineNo */
  24,                                  /* colNo */
  "inv_full_mode_shapes",              /* aName */
  "fn_mode_extract_freq_dom",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo w_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  290,                                 /* lineNo */
  48,                                  /* colNo */
  "freq",                              /* aName */
  "fn_mode_extract_freq_dom",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo x_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  269,                                 /* lineNo */
  16,                                  /* colNo */
  "phase_angle",                       /* aName */
  "fn_mode_extract_freq_dom",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo y_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  270,                                 /* lineNo */
  15,                                  /* colNo */
  "amplitudes",                        /* aName */
  "fn_mode_extract_freq_dom",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = { 353, /* lineNo */
  17,                                  /* colNo */
  "fn_calc_warp_factors",              /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo ab_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  353,                                 /* lineNo */
  17,                                  /* colNo */
  "modal_vgrs",                        /* aName */
  "fn_calc_warp_factors",              /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = { 354, /* lineNo */
  17,                                  /* colNo */
  "fn_calc_warp_factors",              /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo bb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  354,                                 /* lineNo */
  17,                                  /* colNo */
  "modal_vgrs",                        /* aName */
  "fn_calc_warp_factors",              /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  355,                                 /* lineNo */
  17,                                  /* colNo */
  "modal_vgrs",                        /* aName */
  "fn_calc_warp_factors",              /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo db_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  355,                                 /* lineNo */
  49,                                  /* colNo */
  "modal_warps",                       /* aName */
  "fn_calc_warp_factors",              /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo eb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  356,                                 /* lineNo */
  17,                                  /* colNo */
  "modal_vgrs",                        /* aName */
  "fn_calc_warp_factors",              /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  272,                                 /* lineNo */
  16,                                  /* colNo */
  "phase_angle",                       /* aName */
  "fn_mode_extract_freq_dom",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  356,                                 /* lineNo */
  49,                                  /* colNo */
  "modal_warps",                       /* aName */
  "fn_calc_warp_factors",              /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  273,                                 /* lineNo */
  15,                                  /* colNo */
  "amplitudes",                        /* aName */
  "fn_mode_extract_freq_dom",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo n_emlrtRTEI = { 198,/* lineNo */
  27,                                  /* colNo */
  "unaryMinOrMax",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"/* pName */
};

static emlrtECInfo j_emlrtECI = { -1,  /* nDims */
  246,                                 /* lineNo */
  2,                                   /* colNo */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtBCInfo ib_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  246,                                 /* lineNo */
  24,                                  /* colNo */
  "inv_mode_shapes",                   /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  241,                                 /* lineNo */
  116,                                 /* colNo */
  "proc_rx_dir",                       /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  241,                                 /* lineNo */
  72,                                  /* colNo */
  "array_row_pos",                     /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo lb_emlrtBCI = { -1, /* iFirst */
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

static emlrtBCInfo mb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  240,                                 /* lineNo */
  116,                                 /* colNo */
  "proc_tx_dir",                       /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  240,                                 /* lineNo */
  72,                                  /* colNo */
  "array_row_pos",                     /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ob_emlrtBCI = { -1, /* iFirst */
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

static emlrtBCInfo pb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  239,                                 /* lineNo */
  158,                                 /* colNo */
  "array_trans_pos_orientations",      /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  239,                                 /* lineNo */
  63,                                  /* colNo */
  "temp_mode_shape",                   /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rb_emlrtBCI = { -1, /* iFirst */
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

static emlrtBCInfo sb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  238,                                 /* lineNo */
  158,                                 /* colNo */
  "array_trans_pos_orientations",      /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo tb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  238,                                 /* lineNo */
  63,                                  /* colNo */
  "temp_mode_shape",                   /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ub_emlrtBCI = { -1, /* iFirst */
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

static emlrtECInfo k_emlrtECI = { -1,  /* nDims */
  224,                                 /* lineNo */
  3,                                   /* colNo */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtBCInfo vb_emlrtBCI = { -1, /* iFirst */
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

static emlrtECInfo l_emlrtECI = { -1,  /* nDims */
  220,                                 /* lineNo */
  3,                                   /* colNo */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtBCInfo wb_emlrtBCI = { -1, /* iFirst */
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

static emlrtECInfo m_emlrtECI = { -1,  /* nDims */
  216,                                 /* lineNo */
  3,                                   /* colNo */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtBCInfo xb_emlrtBCI = { -1, /* iFirst */
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

static emlrtBCInfo yb_emlrtBCI = { -1, /* iFirst */
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

static emlrtBCInfo ac_emlrtBCI = { -1, /* iFirst */
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

static emlrtBCInfo bc_emlrtBCI = { -1, /* iFirst */
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

static emlrtBCInfo cc_emlrtBCI = { -1, /* iFirst */
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

static emlrtBCInfo dc_emlrtBCI = { -1, /* iFirst */
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

static emlrtBCInfo ec_emlrtBCI = { -1, /* iFirst */
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

static emlrtBCInfo fc_emlrtBCI = { -1, /* iFirst */
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

static emlrtBCInfo gc_emlrtBCI = { -1, /* iFirst */
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
  34,                                  /* colNo */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo t_emlrtDCI = { 208, /* lineNo */
  34,                                  /* colNo */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo u_emlrtDCI = { 210, /* lineNo */
  2,                                   /* colNo */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo hc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  216,                                 /* lineNo */
  42,                                  /* colNo */
  "ms_matrix_modes_to_use",            /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ic_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  217,                                 /* lineNo */
  47,                                  /* colNo */
  "ms_matrix_modes_to_use",            /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  218,                                 /* lineNo */
  47,                                  /* colNo */
  "ms_matrix_modes_to_use",            /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  219,                                 /* lineNo */
  25,                                  /* colNo */
  "ms_matrix_calc_freqs",              /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo lc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  240,                                 /* lineNo */
  51,                                  /* colNo */
  "proc_tx_mode",                      /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  244,                                 /* lineNo */
  14,                                  /* colNo */
  "mode_shapes",                       /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  240,                                 /* lineNo */
  88,                                  /* colNo */
  "array_trans_row",                   /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo oc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  240,                                 /* lineNo */
  95,                                  /* colNo */
  "raw_tx",                            /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  220,                                 /* lineNo */
  42,                                  /* colNo */
  "ms_matrix_modes_to_use",            /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  245,                                 /* lineNo */
  14,                                  /* colNo */
  "mode_shapes",                       /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  241,                                 /* lineNo */
  51,                                  /* colNo */
  "proc_rx_mode",                      /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  221,                                 /* lineNo */
  47,                                  /* colNo */
  "ms_matrix_modes_to_use",            /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo tc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  241,                                 /* lineNo */
  88,                                  /* colNo */
  "array_trans_row",                   /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo uc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  241,                                 /* lineNo */
  95,                                  /* colNo */
  "raw_rx",                            /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  222,                                 /* lineNo */
  47,                                  /* colNo */
  "ms_matrix_modes_to_use",            /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  238,                                 /* lineNo */
  58,                                  /* colNo */
  "proc_tx_mode",                      /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  223,                                 /* lineNo */
  25,                                  /* colNo */
  "ms_matrix_calc_freqs",              /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  238,                                 /* lineNo */
  85,                                  /* colNo */
  "array_trans_node_list",             /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ad_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  238,                                 /* lineNo */
  101,                                 /* colNo */
  "array_trans_pos",                   /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  238,                                 /* lineNo */
  108,                                 /* colNo */
  "raw_tx",                            /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  239,                                 /* lineNo */
  58,                                  /* colNo */
  "proc_rx_mode",                      /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo dd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  239,                                 /* lineNo */
  85,                                  /* colNo */
  "array_trans_node_list",             /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ed_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  239,                                 /* lineNo */
  101,                                 /* colNo */
  "array_trans_pos",                   /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  239,                                 /* lineNo */
  108,                                 /* colNo */
  "raw_rx",                            /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  224,                                 /* lineNo */
  42,                                  /* colNo */
  "ms_matrix_modes_to_use",            /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  225,                                 /* lineNo */
  47,                                  /* colNo */
  "ms_matrix_modes_to_use",            /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo id_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  226,                                 /* lineNo */
  47,                                  /* colNo */
  "ms_matrix_modes_to_use",            /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  238,                                 /* lineNo */
  165,                                 /* colNo */
  "raw_tx",                            /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  227,                                 /* lineNo */
  25,                                  /* colNo */
  "ms_matrix_calc_freqs",              /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ld_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  229,                                 /* lineNo */
  47,                                  /* colNo */
  "ms_matrix_modes_to_use",            /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo md_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  230,                                 /* lineNo */
  49,                                  /* colNo */
  "ms_matrix_modes_to_use",            /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  231,                                 /* lineNo */
  25,                                  /* colNo */
  "ms_matrix_calc_freqs",              /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo od_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  228,                                 /* lineNo */
  15,                                  /* colNo */
  "temp_waveno",                       /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo v_emlrtDCI = { 228, /* lineNo */
  15,                                  /* colNo */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo pd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  228,                                 /* lineNo */
  38,                                  /* colNo */
  "ms_matrix_modes_to_use",            /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  239,                                 /* lineNo */
  165,                                 /* colNo */
  "raw_rx",                            /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  237,                                 /* lineNo */
  13,                                  /* colNo */
  "mode_shapes",                       /* aName */
  "fn_inv_mode_shape_matrices",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  317,                                 /* lineNo */
  30,                                  /* colNo */
  "ms_matrix_modes_to_use",            /* aName */
  "fn_convert_time_to_dist",           /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo w_emlrtDCI = { 317, /* lineNo */
  7,                                   /* colNo */
  "fn_convert_time_to_dist",           /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo td_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  317,                                 /* lineNo */
  7,                                   /* colNo */
  "k",                                 /* aName */
  "fn_convert_time_to_dist",           /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ud_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  319,                                 /* lineNo */
  49,                                  /* colNo */
  "ms_matrix_modes_to_use",            /* aName */
  "fn_convert_time_to_dist",           /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  318,                                 /* lineNo */
  47,                                  /* colNo */
  "ms_matrix_modes_to_use",            /* aName */
  "fn_convert_time_to_dist",           /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  323,                                 /* lineNo */
  47,                                  /* colNo */
  "vgr",                               /* aName */
  "fn_convert_time_to_dist",           /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo x_emlrtDCI = { 323, /* lineNo */
  47,                                  /* colNo */
  "fn_convert_time_to_dist",           /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo xd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  313,                                 /* lineNo */
  32,                                  /* colNo */
  "ms_matrix_modes_to_use",            /* aName */
  "fn_convert_time_to_dist",           /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo y_emlrtDCI = { 313, /* lineNo */
  9,                                   /* colNo */
  "fn_convert_time_to_dist",           /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo yd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  313,                                 /* lineNo */
  9,                                   /* colNo */
  "vgr",                               /* aName */
  "fn_convert_time_to_dist",           /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ae_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  323,                                 /* lineNo */
  22,                                  /* colNo */
  "vgr",                               /* aName */
  "fn_convert_time_to_dist",           /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo ab_emlrtDCI = { 323,/* lineNo */
  22,                                  /* colNo */
  "fn_convert_time_to_dist",           /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo be_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  315,                                 /* lineNo */
  46,                                  /* colNo */
  "ms_matrix_modes_to_use",            /* aName */
  "fn_convert_time_to_dist",           /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ce_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  314,                                 /* lineNo */
  47,                                  /* colNo */
  "ms_matrix_modes_to_use",            /* aName */
  "fn_convert_time_to_dist",           /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo bb_emlrtDCI = { 311,/* lineNo */
  1,                                   /* colNo */
  "fn_convert_time_to_dist",           /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo cb_emlrtDCI = { 311,/* lineNo */
  1,                                   /* colNo */
  "fn_convert_time_to_dist",           /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  1                                    /* checkKind */
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

static emlrtECInfo n_emlrtECI = { -1,  /* nDims */
  337,                                 /* lineNo */
  2,                                   /* colNo */
  "fn_convert_time_to_dist",           /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtBCInfo de_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  337,                                 /* lineNo */
  20,                                  /* colNo */
  "proc_dist_data",                    /* aName */
  "fn_convert_time_to_dist",           /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ee_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  337,                                 /* lineNo */
  67,                                  /* colNo */
  "proc_time_data",                    /* aName */
  "fn_convert_time_to_dist",           /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fe_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  336,                                 /* lineNo */
  30,                                  /* colNo */
  "vgr",                               /* aName */
  "fn_convert_time_to_dist",           /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo o_emlrtECI = { 1,   /* nDims */
  323,                                 /* lineNo */
  13,                                  /* colNo */
  "fn_convert_time_to_dist",           /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtBCInfo ge_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  319,                                 /* lineNo */
  26,                                  /* colNo */
  "disperse_waveno",                   /* aName */
  "fn_convert_time_to_dist",           /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo fb_emlrtDCI = { 319,/* lineNo */
  26,                                  /* colNo */
  "fn_convert_time_to_dist",           /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo he_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  318,                                 /* lineNo */
  24,                                  /* colNo */
  "disperse_freq",                     /* aName */
  "fn_convert_time_to_dist",           /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo gb_emlrtDCI = { 318,/* lineNo */
  24,                                  /* colNo */
  "fn_convert_time_to_dist",           /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo ie_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  315,                                 /* lineNo */
  23,                                  /* colNo */
  "disperse_vgr",                      /* aName */
  "fn_convert_time_to_dist",           /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo hb_emlrtDCI = { 315,/* lineNo */
  23,                                  /* colNo */
  "fn_convert_time_to_dist",           /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo je_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  314,                                 /* lineNo */
  24,                                  /* colNo */
  "disperse_freq",                     /* aName */
  "fn_convert_time_to_dist",           /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo ib_emlrtDCI = { 314,/* lineNo */
  24,                                  /* colNo */
  "fn_convert_time_to_dist",           /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m",/* pName */
  1                                    /* checkKind */
};

static emlrtECInfo p_emlrtECI = { 1,   /* nDims */
  178,                                 /* lineNo */
  11,                                  /* colNo */
  "fn_filter_freq_domain_data",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtECInfo q_emlrtECI = { 1,   /* nDims */
  185,                                 /* lineNo */
  14,                                  /* colNo */
  "fn_filter_freq_domain_data",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtECInfo r_emlrtECI = { 2,   /* nDims */
  185,                                 /* lineNo */
  14,                                  /* colNo */
  "fn_filter_freq_domain_data",        /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo kb_emlrtRTEI = { 44,/* lineNo */
  16,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo lb_emlrtRTEI = { 45,/* lineNo */
  1,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo mb_emlrtRTEI = { 48,/* lineNo */
  1,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo nb_emlrtRTEI = { 49,/* lineNo */
  1,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo ob_emlrtRTEI = { 56,/* lineNo */
  5,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo pb_emlrtRTEI = { 51,/* lineNo */
  19,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo qb_emlrtRTEI = { 57,/* lineNo */
  5,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo rb_emlrtRTEI = { 51,/* lineNo */
  5,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo sb_emlrtRTEI = { 52,/* lineNo */
  33,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo tb_emlrtRTEI = { 1,/* lineNo */
  94,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo ub_emlrtRTEI = { 53,/* lineNo */
  5,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo vb_emlrtRTEI = { 73,/* lineNo */
  5,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo wb_emlrtRTEI = { 54,/* lineNo */
  5,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo yb_emlrtRTEI = { 141,/* lineNo */
  1,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo ac_emlrtRTEI = { 142,/* lineNo */
  6,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo bc_emlrtRTEI = { 142,/* lineNo */
  1,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo cc_emlrtRTEI = { 143,/* lineNo */
  6,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo dc_emlrtRTEI = { 151,/* lineNo */
  1,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo ec_emlrtRTEI = { 143,/* lineNo */
  1,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo fc_emlrtRTEI = { 154,/* lineNo */
  1,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo gc_emlrtRTEI = { 144,/* lineNo */
  13,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo hc_emlrtRTEI = { 144,/* lineNo */
  1,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo ic_emlrtRTEI = { 156,/* lineNo */
  26,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo jc_emlrtRTEI = { 156,/* lineNo */
  13,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo kc_emlrtRTEI = { 156,/* lineNo */
  1,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo lc_emlrtRTEI = { 95,/* lineNo */
  20,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo mc_emlrtRTEI = { 105,/* lineNo */
  1,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo nc_emlrtRTEI = { 259,/* lineNo */
  2,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo oc_emlrtRTEI = { 287,/* lineNo */
  3,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo pc_emlrtRTEI = { 289,/* lineNo */
  17,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo qc_emlrtRTEI = { 28,/* lineNo */
  9,                                   /* colNo */
  "colon",                             /* fName */
  "C:\\Program Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pName */
};

static emlrtRTEInfo rc_emlrtRTEI = { 289,/* lineNo */
  4,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo sc_emlrtRTEI = { 76,/* lineNo */
  13,                                  /* colNo */
  "eml_mtimes_helper",                 /* fName */
  "C:\\Program Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m"/* pName */
};

static emlrtRTEInfo tc_emlrtRTEI = { 294,/* lineNo */
  31,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo uc_emlrtRTEI = { 268,/* lineNo */
  15,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo vc_emlrtRTEI = { 262,/* lineNo */
  40,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo wc_emlrtRTEI = { 268,/* lineNo */
  4,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo xc_emlrtRTEI = { 269,/* lineNo */
  16,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo yc_emlrtRTEI = { 281,/* lineNo */
  25,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo ad_emlrtRTEI = { 269,/* lineNo */
  23,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo bd_emlrtRTEI = { 281,/* lineNo */
  4,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo cd_emlrtRTEI = { 357,/* lineNo */
  17,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo dd_emlrtRTEI = { 270,/* lineNo */
  15,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo ed_emlrtRTEI = { 282,/* lineNo */
  28,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo fd_emlrtRTEI = { 357,/* lineNo */
  27,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo gd_emlrtRTEI = { 270,/* lineNo */
  22,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo hd_emlrtRTEI = { 357,/* lineNo */
  40,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo id_emlrtRTEI = { 271,/* lineNo */
  15,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo jd_emlrtRTEI = { 357,/* lineNo */
  50,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo kd_emlrtRTEI = { 271,/* lineNo */
  4,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo ld_emlrtRTEI = { 272,/* lineNo */
  16,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo md_emlrtRTEI = { 272,/* lineNo */
  23,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo nd_emlrtRTEI = { 343,/* lineNo */
  1,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo od_emlrtRTEI = { 273,/* lineNo */
  15,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo pd_emlrtRTEI = { 347,/* lineNo */
  16,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo qd_emlrtRTEI = { 273,/* lineNo */
  22,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo rd_emlrtRTEI = { 348,/* lineNo */
  47,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo sd_emlrtRTEI = { 98,/* lineNo */
  1,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo td_emlrtRTEI = { 1,/* lineNo */
  11,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo ud_emlrtRTEI = { 1,/* lineNo */
  25,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo vd_emlrtRTEI = { 31,/* lineNo */
  6,                                   /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo wd_emlrtRTEI = { 290,/* lineNo */
  4,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo xd_emlrtRTEI = { 262,/* lineNo */
  3,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo yd_emlrtRTEI = { 302,/* lineNo */
  13,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo le_emlrtRTEI = { 204,/* lineNo */
  1,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo me_emlrtRTEI = { 205,/* lineNo */
  1,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo ne_emlrtRTEI = { 208,/* lineNo */
  2,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo oe_emlrtRTEI = { 210,/* lineNo */
  2,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo pe_emlrtRTEI = { 19,/* lineNo */
  22,                                  /* colNo */
  "pinv",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\matfun\\pinv.m"/* pName */
};

static emlrtRTEInfo qe_emlrtRTEI = { 217,/* lineNo */
  4,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo re_emlrtRTEI = { 246,/* lineNo */
  30,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo se_emlrtRTEI = { 218,/* lineNo */
  4,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo te_emlrtRTEI = { 221,/* lineNo */
  4,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo ue_emlrtRTEI = { 222,/* lineNo */
  4,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo ve_emlrtRTEI = { 225,/* lineNo */
  4,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo we_emlrtRTEI = { 226,/* lineNo */
  4,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo xe_emlrtRTEI = { 229,/* lineNo */
  4,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo ye_emlrtRTEI = { 230,/* lineNo */
  4,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo af_emlrtRTEI = { 238,/* lineNo */
  129,                                 /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo bf_emlrtRTEI = { 239,/* lineNo */
  129,                                 /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo cf_emlrtRTEI = { 216,/* lineNo */
  3,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo df_emlrtRTEI = { 19,/* lineNo */
  13,                                  /* colNo */
  "pinv",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\matfun\\pinv.m"/* pName */
};

static emlrtRTEInfo yg_emlrtRTEI = { 310,/* lineNo */
  1,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo ah_emlrtRTEI = { 311,/* lineNo */
  1,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo bh_emlrtRTEI = { 322,/* lineNo */
  1,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo ch_emlrtRTEI = { 323,/* lineNo */
  13,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo dh_emlrtRTEI = { 314,/* lineNo */
  4,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo eh_emlrtRTEI = { 315,/* lineNo */
  4,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo fh_emlrtRTEI = { 323,/* lineNo */
  38,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo hh_emlrtRTEI = { 318,/* lineNo */
  4,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo ih_emlrtRTEI = { 319,/* lineNo */
  4,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo jh_emlrtRTEI = { 328,/* lineNo */
  13,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo kh_emlrtRTEI = { 328,/* lineNo */
  1,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo lh_emlrtRTEI = { 332,/* lineNo */
  1,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo mh_emlrtRTEI = { 337,/* lineNo */
  49,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo rh_emlrtRTEI = { 187,/* lineNo */
  13,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo sh_emlrtRTEI = { 188,/* lineNo */
  2,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo th_emlrtRTEI = { 189,/* lineNo */
  21,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo uh_emlrtRTEI = { 40,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo vh_emlrtRTEI = { 45,/* lineNo */
  1,                                   /* colNo */
  "gaussian",                          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\pauls-new-functions\\gaussian.m"/* pName */
};

static emlrtRTEInfo wh_emlrtRTEI = { 178,/* lineNo */
  21,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo xh_emlrtRTEI = { 181,/* lineNo */
  21,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo yh_emlrtRTEI = { 183,/* lineNo */
  20,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo ai_emlrtRTEI = { 162,/* lineNo */
  2,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo bi_emlrtRTEI = { 187,/* lineNo */
  2,                                   /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo ci_emlrtRTEI = { 188,/* lineNo */
  20,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo di_emlrtRTEI = { 183,/* lineNo */
  11,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo fi_emlrtRTEI = { 185,/* lineNo */
  14,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRTEInfo gi_emlrtRTEI = { 178,/* lineNo */
  11,                                  /* colNo */
  "fn_process_rail_data_DLL",          /* fName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pName */
};

static emlrtRSInfo wi_emlrtRSI = { 54, /* lineNo */
  "div",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\div.m"/* pathName */
};

static emlrtRSInfo xi_emlrtRSI = { 185,/* lineNo */
  "fn_filter_freq_domain_data",        /* fcnName */
  "C:\\Users\\mepdw\\Git\\contact_wire_test\\fn_process_rail_data_DLL.m"/* pathName */
};

/* Function Declarations */
static void binary_expand_op(const emlrtStack *sp, emxArray_creal_T *in1, const
  emxArray_real_T *in2, const emxArray_creal_T *in3);
static void binary_expand_op_1(const emlrtStack *sp, emxArray_creal_T *in1,
  const emxArray_creal_T *in2);
static void binary_expand_op_4(const emlrtStack *sp, emxArray_creal_T *in1,
  const emxArray_real_T *in2);
static void binary_expand_op_5(const emlrtStack *sp, emxArray_real_T *in1, const
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
  emxArray_real_T *in2, const emxArray_creal_T *in3)
{
  const creal_T *in3_data;
  creal_T *in1_data;
  const real_T *in2_data;
  int32_T b_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T in3_idx_0;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  in3_data = in3->data;
  in2_data = in2->data;
  in3_idx_0 = in3->size[0];
  if (in3_idx_0 == 1) {
    loop_ub = in2->size[0];
  } else {
    loop_ub = in3_idx_0;
  }

  stride_1_0 = in1->size[0] * in1->size[1];
  in1->size[0] = loop_ub;
  emxEnsureCapacity_creal_T(sp, in1, stride_1_0, &bd_emlrtRTEI);
  b_loop_ub = in2->size[1];
  stride_1_0 = in1->size[0] * in1->size[1];
  in1->size[1] = b_loop_ub;
  emxEnsureCapacity_creal_T(sp, in1, stride_1_0, &bd_emlrtRTEI);
  in1_data = in1->data;
  stride_0_0 = (in2->size[0] != 1);
  stride_1_0 = (in3_idx_0 != 1);
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      real_T d;
      d = in2_data[i1 * stride_0_0 + in2->size[0] * i];
      in3_idx_0 = i1 * stride_1_0;
      in1_data[i1 + in1->size[0] * i].re = d * in3_data[in3_idx_0].re;
      in1_data[i1 + in1->size[0] * i].im = d * in3_data[in3_idx_0].im;
    }
  }
}

static void binary_expand_op_1(const emlrtStack *sp, emxArray_creal_T *in1,
  const emxArray_creal_T *in2)
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
  emxInit_creal_T(sp, &b_in1, 2, &jc_emlrtRTEI);
  loop_ub = in1->size[0];
  stride_0_0 = b_in1->size[0] * b_in1->size[1];
  b_in1->size[0] = loop_ub;
  b_loop_ub = in1->size[1];
  b_in1->size[1] = b_loop_ub;
  emxEnsureCapacity_creal_T(sp, b_in1, stride_0_0, &jc_emlrtRTEI);
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

static void binary_expand_op_4(const emlrtStack *sp, emxArray_creal_T *in1,
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
  emxInit_creal_T(sp, &b_in1, 2, &fi_emlrtRTEI);
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
  emxEnsureCapacity_creal_T(sp, b_in1, stride_0_0, &fi_emlrtRTEI);
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
  emxEnsureCapacity_creal_T(sp, in1, stride_0_0, &fi_emlrtRTEI);
  in1_data = in1->data;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      in1_data[i1 + in1->size[0] * i] = b_in1_data[i1 + b_in1->size[0] * i];
    }
  }

  emxFree_creal_T(sp, &b_in1);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void binary_expand_op_5(const emlrtStack *sp, emxArray_real_T *in1, const
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
  emxInit_real_T(sp, &r, 1, &gi_emlrtRTEI);
  if (in1->size[0] == 1) {
    loop_ub = in2->size[0];
  } else {
    loop_ub = in1->size[0];
  }

  stride_1_0 = r->size[0];
  r->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, r, stride_1_0, &gi_emlrtRTEI);
  r1 = r->data;
  stride_1_0 = (in1->size[0] != 1);
  for (i = 0; i < loop_ub; i++) {
    r1[i] = in1_data[i * stride_1_0];
  }

  stride_1_0 = in1->size[0];
  in1->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, in1, stride_1_0, &gi_emlrtRTEI);
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
  st.site = &bi_emlrtRSI;
  b_st.site = &xb_emlrtRSI;
  c_st.site = &yb_emlrtRSI;
  d_st.site = &ac_emlrtRSI;
  if (ms_matrix_modes_to_use->size[1] < 1) {
    emlrtErrorWithMessageIdR2018a(&d_st, &n_emlrtRTEI,
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

  emxInit_real_T(sp, &vgr, 1, &yg_emlrtRTEI);
  if (!(ex >= 0.0)) {
    emlrtNonNegativeCheckR2012b(ex, &db_emlrtDCI, (emlrtConstCTX)sp);
  }

  loop_ub = (int32_T)muDoubleScalarFloor(ex);
  if (ex != loop_ub) {
    emlrtIntegerCheckR2012b(ex, &eb_emlrtDCI, (emlrtConstCTX)sp);
  }

  b_last = (int32_T)ex;
  idx = vgr->size[0];
  vgr->size[0] = b_last;
  emxEnsureCapacity_real_T(sp, vgr, idx, &yg_emlrtRTEI);
  vgr_data = vgr->data;
  if (b_last != loop_ub) {
    emlrtIntegerCheckR2012b(ex, &eb_emlrtDCI, (emlrtConstCTX)sp);
  }

  for (k = 0; k < b_last; k++) {
    vgr_data[k] = 0.0;
  }

  st.site = &ci_emlrtRSI;
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

  emxInit_real_T(sp, &b_k, 1, &ah_emlrtRTEI);
  if (!(ex >= 0.0)) {
    emlrtNonNegativeCheckR2012b(ex, &bb_emlrtDCI, (emlrtConstCTX)sp);
  }

  loop_ub = (int32_T)muDoubleScalarFloor(ex);
  if (ex != loop_ub) {
    emlrtIntegerCheckR2012b(ex, &cb_emlrtDCI, (emlrtConstCTX)sp);
  }

  b_last = (int32_T)ex;
  idx = b_k->size[0];
  b_k->size[0] = b_last;
  emxEnsureCapacity_real_T(sp, b_k, idx, &ah_emlrtRTEI);
  k_data = b_k->data;
  if (b_last != loop_ub) {
    emlrtIntegerCheckR2012b(ex, &cb_emlrtDCI, (emlrtConstCTX)sp);
  }

  for (k = 0; k < b_last; k++) {
    k_data[k] = 0.0;
  }

  idx = disperse_freq->size[0];
  b_last = disperse_vgr->size[0];
  c_last = disperse_waveno->size[0];
  emxInit_real_T(sp, &b_disperse_freq, 1, &dh_emlrtRTEI);
  emxInit_real_T(sp, &b_disperse_vgr, 1, &eh_emlrtRTEI);
  for (ii = 0; ii < last; ii++) {
    if (ii + 1 > last) {
      emlrtDynamicBoundsCheckR2012b(ii + 1, 1, last, &ce_emlrtBCI,
        (emlrtConstCTX)sp);
    }

    ex = ms_matrix_modes_to_use_data[ii];
    d_last = (int32_T)muDoubleScalarFloor(ex);
    if (ex != d_last) {
      emlrtIntegerCheckR2012b(ex, &ib_emlrtDCI, (emlrtConstCTX)sp);
    }

    b_loop_ub = (int32_T)ex;
    if ((ex < 1.0) || (b_loop_ub > disperse_freq->size[2])) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1, disperse_freq->size[2],
        &je_emlrtBCI, (emlrtConstCTX)sp);
    }

    if (ii + 1 > last) {
      emlrtDynamicBoundsCheckR2012b(ii + 1, 1, last, &be_emlrtBCI,
        (emlrtConstCTX)sp);
    }

    if (b_loop_ub != d_last) {
      emlrtIntegerCheckR2012b(ex, &hb_emlrtDCI, (emlrtConstCTX)sp);
    }

    if ((ex < 1.0) || (b_loop_ub > disperse_vgr->size[2])) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1, disperse_vgr->size[2],
        &ie_emlrtBCI, (emlrtConstCTX)sp);
    }

    loop_ub = b_disperse_freq->size[0];
    b_disperse_freq->size[0] = idx;
    emxEnsureCapacity_real_T(sp, b_disperse_freq, loop_ub, &dh_emlrtRTEI);
    modal_vgrs_data = b_disperse_freq->data;
    for (k = 0; k < idx; k++) {
      modal_vgrs_data[k] = disperse_freq_data[k + disperse_freq->size[0] *
        (b_loop_ub - 1)];
    }

    loop_ub = b_disperse_vgr->size[0];
    b_disperse_vgr->size[0] = b_last;
    emxEnsureCapacity_real_T(sp, b_disperse_vgr, loop_ub, &eh_emlrtRTEI);
    b_proc_dist_data = b_disperse_vgr->data;
    for (k = 0; k < b_last; k++) {
      b_proc_dist_data[k] = disperse_vgr_data[k + disperse_vgr->size[0] *
        (b_loop_ub - 1)];
    }

    if (ii + 1 > last) {
      emlrtDynamicBoundsCheckR2012b(ii + 1, 1, last, &xd_emlrtBCI,
        (emlrtConstCTX)sp);
    }

    if (b_loop_ub != d_last) {
      emlrtIntegerCheckR2012b(ex, &y_emlrtDCI, (emlrtConstCTX)sp);
    }

    if ((ex < 1.0) || (b_loop_ub > vgr->size[0])) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1, vgr->size[0], &yd_emlrtBCI,
        (emlrtConstCTX)sp);
    }

    st.site = &di_emlrtRSI;
    vgr_data[b_loop_ub - 1] = b_interp1(&st, b_disperse_freq, b_disperse_vgr,
      freq_filter);
    if (ii + 1 > last) {
      emlrtDynamicBoundsCheckR2012b(ii + 1, 1, last, &vd_emlrtBCI,
        (emlrtConstCTX)sp);
    }

    if (b_loop_ub != d_last) {
      emlrtIntegerCheckR2012b(ex, &gb_emlrtDCI, (emlrtConstCTX)sp);
    }

    if ((ex < 1.0) || (b_loop_ub > disperse_freq->size[2])) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1, disperse_freq->size[2],
        &he_emlrtBCI, (emlrtConstCTX)sp);
    }

    if (ii + 1 > last) {
      emlrtDynamicBoundsCheckR2012b(ii + 1, 1, last, &ud_emlrtBCI,
        (emlrtConstCTX)sp);
    }

    if (b_loop_ub != d_last) {
      emlrtIntegerCheckR2012b(ex, &fb_emlrtDCI, (emlrtConstCTX)sp);
    }

    if ((ex < 1.0) || (b_loop_ub > disperse_waveno->size[2])) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1, disperse_waveno->size[2],
        &ge_emlrtBCI, (emlrtConstCTX)sp);
    }

    loop_ub = b_disperse_freq->size[0];
    b_disperse_freq->size[0] = idx;
    emxEnsureCapacity_real_T(sp, b_disperse_freq, loop_ub, &hh_emlrtRTEI);
    modal_vgrs_data = b_disperse_freq->data;
    for (k = 0; k < idx; k++) {
      modal_vgrs_data[k] = disperse_freq_data[k + disperse_freq->size[0] *
        (b_loop_ub - 1)];
    }

    loop_ub = b_disperse_vgr->size[0];
    b_disperse_vgr->size[0] = c_last;
    emxEnsureCapacity_real_T(sp, b_disperse_vgr, loop_ub, &ih_emlrtRTEI);
    b_proc_dist_data = b_disperse_vgr->data;
    for (k = 0; k < c_last; k++) {
      b_proc_dist_data[k] = disperse_waveno_data[k + disperse_waveno->size[0] *
        (b_loop_ub - 1)];
    }

    if (ii + 1 > last) {
      emlrtDynamicBoundsCheckR2012b(ii + 1, 1, last, &sd_emlrtBCI,
        (emlrtConstCTX)sp);
    }

    if (b_loop_ub != d_last) {
      emlrtIntegerCheckR2012b(ex, &w_emlrtDCI, (emlrtConstCTX)sp);
    }

    if ((ex < 1.0) || (b_loop_ub > b_k->size[0])) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1, b_k->size[0], &td_emlrtBCI,
        (emlrtConstCTX)sp);
    }

    st.site = &ei_emlrtRSI;
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
  emxEnsureCapacity_real_T(sp, modal_vgrs, loop_ub, &bh_emlrtRTEI);
  modal_vgrs_data = modal_vgrs->data;
  for (k = 0; k < idx; k++) {
    modal_vgrs_data[k] = vgr_data[k];
  }

  b_loop_ub = proc_tx_mode->size[0];
  for (k = 0; k < b_loop_ub; k++) {
    if (proc_tx_mode_data[k] != (int32_T)muDoubleScalarFloor(proc_tx_mode_data[k]))
    {
      emlrtIntegerCheckR2012b(proc_tx_mode_data[k], &ab_emlrtDCI, (emlrtConstCTX)
        sp);
    }

    loop_ub = (int32_T)proc_tx_mode_data[k];
    if ((loop_ub < 1) || (loop_ub > idx)) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, idx, &ae_emlrtBCI,
        (emlrtConstCTX)sp);
    }
  }

  loop_ub = b_disperse_vgr->size[0];
  b_disperse_vgr->size[0] = proc_tx_mode->size[0];
  emxEnsureCapacity_real_T(sp, b_disperse_vgr, loop_ub, &ch_emlrtRTEI);
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
      emlrtIntegerCheckR2012b(proc_rx_mode_data[k], &x_emlrtDCI, (emlrtConstCTX)
        sp);
    }

    loop_ub = (int32_T)proc_rx_mode_data[k];
    if ((loop_ub < 1) || (loop_ub > idx)) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, idx, &wd_emlrtBCI,
        (emlrtConstCTX)sp);
    }
  }

  loop_ub = b_disperse_freq->size[0];
  b_disperse_freq->size[0] = proc_rx_mode->size[0];
  emxEnsureCapacity_real_T(sp, b_disperse_freq, loop_ub, &fh_emlrtRTEI);
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
    emlrtDimSizeImpxCheckR2021b(b_loop_ub, b_last, &o_emlrtECI, (emlrtConstCTX)
      sp);
  }

  if (b_disperse_vgr->size[0] == b_disperse_freq->size[0]) {
    loop_ub = vgr->size[0];
    vgr->size[0] = b_loop_ub;
    emxEnsureCapacity_real_T(sp, vgr, loop_ub, &gh_emlrtRTEI);
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
    st.site = &wi_emlrtRSI;
    binary_expand_op_3(&st, vgr, b_disperse_vgr, b_disperse_freq);
    vgr_data = vgr->data;
  }

  /* set up distance axis */
  st.site = &fi_emlrtRSI;
  b_st.site = &xb_emlrtRSI;
  c_st.site = &yb_emlrtRSI;
  d_st.site = &ac_emlrtRSI;
  if (vgr->size[0] < 1) {
    emlrtErrorWithMessageIdR2018a(&d_st, &n_emlrtRTEI,
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

  st.site = &fi_emlrtRSI;
  b_st.site = &xb_emlrtRSI;
  c_st.site = &yb_emlrtRSI;
  d_st.site = &ac_emlrtRSI;
  if (proc_time->size[1] < 1) {
    emlrtErrorWithMessageIdR2018a(&d_st, &n_emlrtRTEI,
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

  st.site = &gi_emlrtRSI;
  b_st.site = &xb_emlrtRSI;
  c_st.site = &yb_emlrtRSI;
  d_st.site = &ac_emlrtRSI;
  if (b_k->size[0] < 1) {
    emlrtErrorWithMessageIdR2018a(&d_st, &n_emlrtRTEI,
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
  emxInit_real_T(sp, &modal_vgrs, 2, &sc_emlrtRTEI);
  modal_vgrs_data = modal_vgrs->data;
  if (muDoubleScalarIsNaN(ex)) {
    loop_ub = modal_vgrs->size[0] * modal_vgrs->size[1];
    modal_vgrs->size[0] = 1;
    modal_vgrs->size[1] = 1;
    emxEnsureCapacity_real_T(sp, modal_vgrs, loop_ub, &jh_emlrtRTEI);
    modal_vgrs_data = modal_vgrs->data;
    modal_vgrs_data[0] = rtNaN;
  } else if (ex < 0.0) {
    modal_vgrs->size[0] = 1;
    modal_vgrs->size[1] = 0;
  } else {
    loop_ub = modal_vgrs->size[0] * modal_vgrs->size[1];
    modal_vgrs->size[0] = 1;
    modal_vgrs->size[1] = (int32_T)ex + 1;
    emxEnsureCapacity_real_T(sp, modal_vgrs, loop_ub, &jh_emlrtRTEI);
    modal_vgrs_data = modal_vgrs->data;
    loop_ub = (int32_T)ex;
    for (k = 0; k <= loop_ub; k++) {
      modal_vgrs_data[k] = k;
    }
  }

  b_last = modal_vgrs->size[1];
  loop_ub = proc_dist->size[0];
  proc_dist->size[0] = modal_vgrs->size[1];
  emxEnsureCapacity_real_T(sp, proc_dist, loop_ub, &kh_emlrtRTEI);
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
  emxEnsureCapacity_creal_T(sp, proc_dist_data, loop_ub, &lh_emlrtRTEI);
  proc_dist_data_data = proc_dist_data->data;
  loop_ub = proc_dist->size[0] * proc_tx_mode->size[0];
  for (k = 0; k < loop_ub; k++) {
    proc_dist_data_data[k].re = 0.0;
    proc_dist_data_data[k].im = 0.0;
  }

  /* interpolate from time data */
  emxInit_creal_T(sp, &c_proc_time_data, 1, &mh_emlrtRTEI);
  for (ii = 0; ii < b_loop_ub; ii++) {
    if (ii + 1 > d_last) {
      emlrtDynamicBoundsCheckR2012b(ii + 1, 1, d_last, &fe_emlrtBCI,
        (emlrtConstCTX)sp);
    }

    if (ii + 1 > b_loop_ub) {
      emlrtDynamicBoundsCheckR2012b(ii + 1, 1, b_loop_ub, &de_emlrtBCI,
        (emlrtConstCTX)sp);
    }

    if (ii + 1 > proc_time_data->size[1]) {
      emlrtDynamicBoundsCheckR2012b(ii + 1, 1, proc_time_data->size[1],
        &ee_emlrtBCI, (emlrtConstCTX)sp);
    }

    idx = proc_time_data->size[0];
    loop_ub = c_proc_time_data->size[0];
    c_proc_time_data->size[0] = proc_time_data->size[0];
    emxEnsureCapacity_creal_T(sp, c_proc_time_data, loop_ub, &mh_emlrtRTEI);
    b_proc_time_data_data = c_proc_time_data->data;
    for (k = 0; k < idx; k++) {
      b_proc_time_data_data[k] = proc_time_data_data[k + proc_time_data->size[0]
        * ii];
    }

    st.site = &hi_emlrtRSI;
    e_abs(&st, c_proc_time_data, b_disperse_vgr);
    ex = vgr_data[ii];
    loop_ub = modal_vgrs->size[0] * modal_vgrs->size[1];
    modal_vgrs->size[0] = 1;
    modal_vgrs->size[1] = c_last;
    emxEnsureCapacity_real_T(sp, modal_vgrs, loop_ub, &sc_emlrtRTEI);
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

    st.site = &hi_emlrtRSI;
    d_interp1(&st, modal_vgrs, b_disperse_vgr, proc_dist, b_disperse_freq);
    modal_vgrs_data = b_disperse_freq->data;
    emlrtSubAssignSizeCheckR2012b(&b_last, 1, &b_disperse_freq->size[0], 1,
      &n_emlrtECI, (emlrtCTX)sp);
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
  emxArray_real_T b_y;
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
  int32_T size_tmp[2];
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

  emxInit_real_T(sp, &temp, 2, &bi_emlrtRTEI);
  emxInit_real_T(sp, &y, 2, &di_emlrtRTEI);
  if (freq_filter_on != 0.0) {
    __m128d b_r;
    real_T max_freq;
    int32_T b_last;
    int32_T idx;
    int32_T last;
    int32_T scalarLB;
    int32_T size_tmp_idx_1;
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
      emlrtErrorWithMessageIdR2018a(&d_st, &n_emlrtRTEI,
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
    emxInit_real_T(&st, &r, 1, &vh_emlrtRTEI);
    last = temp->size[1];
    scalarLB = r->size[0];
    r->size[0] = temp->size[1];
    emxEnsureCapacity_real_T(&st, r, scalarLB, &vh_emlrtRTEI);
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
    emxInit_real_T(&st, &filter, 1, &ai_emlrtRTEI);
    idx = r->size[0];
    scalarLB = filter->size[0];
    filter->size[0] = r->size[0];
    emxEnsureCapacity_real_T(&st, filter, scalarLB, &wh_emlrtRTEI);
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
      emlrtDimSizeImpxCheckR2021b(b_last, filter->size[0], &p_emlrtECI,
        (emlrtConstCTX)sp);
    }

    if (freq->size[0] != filter->size[0]) {
      st.site = &ob_emlrtRSI;
      binary_expand_op_5(&st, filter, freq);
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
      emlrtErrorWithMessageIdR2018a(&d_st, &n_emlrtRTEI,
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
    emxInit_boolean_T(&st, &x, 1, &xh_emlrtRTEI);
    idx = filter->size[0];
    scalarLB = x->size[0];
    x->size[0] = filter->size[0];
    emxEnsureCapacity_boolean_T(&st, x, scalarLB, &xh_emlrtRTEI);
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

    emxInit_int32_T(&st, &ii, 1, &vd_emlrtRTEI);
    b_st.site = &s_emlrtRSI;
    eml_find(&b_st, x, ii);
    ii_data = ii->data;
    last = ii->size[0];
    scalarLB = r->size[0];
    r->size[0] = ii->size[0];
    emxEnsureCapacity_real_T(&st, r, scalarLB, &uh_emlrtRTEI);
    r_data = r->data;
    for (k = 0; k < last; k++) {
      r_data[k] = ii_data[k];
    }

    st.site = &qb_emlrtRSI;
    b_st.site = &mc_emlrtRSI;
    c_st.site = &nc_emlrtRSI;
    d_st.site = &oc_emlrtRSI;
    if (r->size[0] < 1) {
      emlrtErrorWithMessageIdR2018a(&d_st, &n_emlrtRTEI,
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
    emxEnsureCapacity_real_T(&st, r, scalarLB, &uh_emlrtRTEI);
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
      emlrtErrorWithMessageIdR2018a(&d_st, &n_emlrtRTEI,
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
    st.site = &sb_emlrtRSI;
    size_tmp_idx_1 = freq_data->size[1];
    scalarLB = temp->size[0] * temp->size[1];
    temp->size[0] = 1;
    temp->size[1] = size_tmp_idx_1;
    emxEnsureCapacity_real_T(&st, temp, scalarLB, &yh_emlrtRTEI);
    temp_data = temp->data;
    for (k = 0; k < size_tmp_idx_1; k++) {
      temp_data[k] = 1.0;
    }

    b_st.site = &m_emlrtRSI;
    mtimes(&b_st, filter, temp, y);
    temp_data = y->data;
    emxFree_real_T(&st, &filter);
    scalarLB = freq_data->size[0];
    if ((scalarLB != y->size[0]) && ((scalarLB != 1) && (y->size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(scalarLB, y->size[0], &q_emlrtECI,
        (emlrtConstCTX)sp);
    }

    if ((size_tmp_idx_1 != y->size[1]) && ((size_tmp_idx_1 != 1) && (y->size[1]
          != 1))) {
      emlrtDimSizeImpxCheckR2021b(size_tmp_idx_1, y->size[1], &r_emlrtECI,
        (emlrtConstCTX)sp);
    }

    if ((freq_data->size[0] == y->size[0]) && (freq_data->size[1] == y->size[1]))
    {
      for (k = 0; k < size_tmp_idx_1; k++) {
        for (b_k = 0; b_k < scalarLB; b_k++) {
          freq_data_data[b_k + freq_data->size[0] * k].re *= temp_data[b_k +
            y->size[0] * k];
          freq_data_data[b_k + freq_data->size[0] * k].im *= temp_data[b_k +
            y->size[0] * k];
        }
      }
    } else {
      st.site = &xi_emlrtRSI;
      binary_expand_op_4(&st, freq_data, y);
    }
  } else {
    real_T max_freq;
    int32_T b_last;
    int32_T idx;
    int32_T last;
    int32_T scalarLB;
    int32_T size_tmp_idx_1;
    st.site = &tb_emlrtRSI;
    c_abs(&st, freq_data, y);
    size_tmp_idx_1 = y->size[1];
    st.site = &tb_emlrtRSI;
    c_abs(&st, freq_data, y);
    scalarLB = y->size[0];
    st.site = &tb_emlrtRSI;
    c_abs(&st, freq_data, y);
    temp_data = y->data;
    emxInit_real_T(sp, &r, 2, &rh_emlrtRTEI);
    last = y->size[1];
    idx = r->size[0] * r->size[1];
    r->size[0] = y->size[1];
    b_last = y->size[0];
    r->size[1] = y->size[0];
    emxEnsureCapacity_real_T(sp, r, idx, &rh_emlrtRTEI);
    r_data = r->data;
    for (k = 0; k < b_last; k++) {
      for (b_k = 0; b_k < last; b_k++) {
        r_data[b_k + r->size[0] * k] = temp_data[k + y->size[0] * b_k];
      }
    }

    b_y = *r;
    size_tmp[0] = size_tmp_idx_1;
    size_tmp[1] = scalarLB;
    b_y.size = &size_tmp[0];
    b_y.numDimensions = 2;
    st.site = &tb_emlrtRSI;
    sum(&st, &b_y, temp);
    emxFree_real_T(sp, &r);
    st.site = &ub_emlrtRSI;
    emxInit_real_T(&st, &filter, 2, &ci_emlrtRTEI);
    b_st.site = &ub_emlrtRSI;
    d_abs(&b_st, temp, filter);
    temp_data = filter->data;
    b_st.site = &xb_emlrtRSI;
    c_st.site = &yb_emlrtRSI;
    d_st.site = &ac_emlrtRSI;
    if (filter->size[1] < 1) {
      emlrtErrorWithMessageIdR2018a(&d_st, &n_emlrtRTEI,
        "Coder:toolbox:eml_min_or_max_varDimZero",
        "Coder:toolbox:eml_min_or_max_varDimZero", 0);
    }

    e_st.site = &bc_emlrtRSI;
    f_st.site = &cc_emlrtRSI;
    last = filter->size[1];
    if (filter->size[1] <= 2) {
      if (filter->size[1] == 1) {
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
        if (filter->size[1] > 2147483646) {
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
        if ((idx + 1 <= filter->size[1]) && (filter->size[1] > 2147483646)) {
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

    emxFree_real_T(&f_st, &filter);
    scalarLB = temp->size[0] * temp->size[1];
    temp->size[0] = 1;
    emxEnsureCapacity_real_T(sp, temp, scalarLB, &sh_emlrtRTEI);
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
    emxInit_boolean_T(&st, &x, 2, &th_emlrtRTEI);
    scalarLB = x->size[0] * x->size[1];
    x->size[0] = 1;
    idx = temp->size[1];
    x->size[1] = temp->size[1];
    emxEnsureCapacity_boolean_T(&st, x, scalarLB, &th_emlrtRTEI);
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

    emxInit_int32_T(&st, &ii, 2, &vd_emlrtRTEI);
    b_st.site = &s_emlrtRSI;
    b_eml_find(&b_st, x, ii);
    ii_data = ii->data;
    scalarLB = temp->size[0] * temp->size[1];
    temp->size[0] = 1;
    idx = ii->size[1];
    temp->size[1] = ii->size[1];
    emxEnsureCapacity_real_T(&st, temp, scalarLB, &uh_emlrtRTEI);
    temp_data = temp->data;
    for (k = 0; k < idx; k++) {
      temp_data[k] = ii_data[k];
    }

    st.site = &vb_emlrtRSI;
    b_st.site = &mc_emlrtRSI;
    c_st.site = &nc_emlrtRSI;
    d_st.site = &oc_emlrtRSI;
    if (temp->size[1] < 1) {
      emlrtErrorWithMessageIdR2018a(&d_st, &n_emlrtRTEI,
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
    emxEnsureCapacity_real_T(&st, temp, scalarLB, &uh_emlrtRTEI);
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
      emlrtErrorWithMessageIdR2018a(&d_st, &n_emlrtRTEI,
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

  emxFree_real_T(sp, &y);
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
  emxArray_creal_T *b_disperse_ms_x;
  emxArray_creal_T *mode_shapes;
  emxArray_creal_T *r;
  emxArray_creal_T *r1;
  emxArray_creal_T *temp_mode_shape;
  emxArray_real_T *b_array_trans_pos_orientations;
  emxArray_real_T *b_disperse_freq;
  emxArray_real_T *b_disperse_waveno;
  emxArray_real_T *c_array_trans_pos_orientations;
  emxArray_real_T *temp_waveno;
  const creal_T *disperse_ms_x_data;
  const creal_T *disperse_ms_y_data;
  const creal_T *disperse_ms_z_data;
  creal_T *b_disperse_ms_x_data;
  creal_T *inv_mode_shapes_data;
  creal_T *mode_shapes_data;
  creal_T *r2;
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
  real_T ex;
  real_T im;
  real_T max_mode_index;
  real_T *b_disperse_freq_data;
  real_T *temp_waveno_data;
  int32_T b_inv_mode_shapes[2];
  int32_T b_i;
  int32_T b_jj;
  int32_T b_last;
  int32_T b_n;
  int32_T i;
  int32_T ii;
  int32_T jj;
  int32_T last;
  int32_T loop_ub;
  int32_T loop_ub_tmp;
  int32_T n;
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
    emlrtErrorWithMessageIdR2018a(&d_st, &n_emlrtRTEI,
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
      n = 1;
    } else {
      n = 0;
      h_st.site = &fc_emlrtRSI;
      if (proc_tx_mode->size[0] > 2147483646) {
        i_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }

      b_n = 2;
      exitg1 = false;
      while ((!exitg1) && (b_n <= last)) {
        if (!muDoubleScalarIsNaN(proc_tx_mode_data[b_n - 1])) {
          n = b_n;
          exitg1 = true;
        } else {
          b_n++;
        }
      }
    }

    if (n == 0) {
      ex = proc_tx_mode_data[0];
    } else {
      g_st.site = &dc_emlrtRSI;
      ex = proc_tx_mode_data[n - 1];
      b_n = n + 1;
      h_st.site = &gc_emlrtRSI;
      if ((n + 1 <= proc_tx_mode->size[0]) && (proc_tx_mode->size[0] >
           2147483646)) {
        i_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }

      for (i = b_n; i <= last; i++) {
        im = proc_tx_mode_data[i - 1];
        if (ex < im) {
          ex = im;
        }
      }
    }
  }

  st.site = &gd_emlrtRSI;
  b_st.site = &xb_emlrtRSI;
  c_st.site = &yb_emlrtRSI;
  d_st.site = &ac_emlrtRSI;
  if (proc_rx_mode->size[0] < 1) {
    emlrtErrorWithMessageIdR2018a(&d_st, &n_emlrtRTEI,
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
      n = 1;
    } else {
      n = 0;
      h_st.site = &fc_emlrtRSI;
      if (proc_rx_mode->size[0] > 2147483646) {
        i_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }

      b_n = 2;
      exitg1 = false;
      while ((!exitg1) && (b_n <= b_last)) {
        if (!muDoubleScalarIsNaN(proc_rx_mode_data[b_n - 1])) {
          n = b_n;
          exitg1 = true;
        } else {
          b_n++;
        }
      }
    }

    if (n == 0) {
      max_mode_index = proc_rx_mode_data[0];
    } else {
      g_st.site = &dc_emlrtRSI;
      max_mode_index = proc_rx_mode_data[n - 1];
      b_n = n + 1;
      h_st.site = &gc_emlrtRSI;
      if ((n + 1 <= proc_rx_mode->size[0]) && (proc_rx_mode->size[0] >
           2147483646)) {
        i_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }

      for (i = b_n; i <= b_last; i++) {
        im = proc_rx_mode_data[i - 1];
        if (max_mode_index < im) {
          max_mode_index = im;
        }
      }
    }
  }

  if ((!(ex < max_mode_index)) && ((!muDoubleScalarIsNaN(ex)) ||
       muDoubleScalarIsNaN(max_mode_index))) {
    max_mode_index = ex;
  }

  b_n = inv_mode_shapes->size[0] * inv_mode_shapes->size[1] *
    inv_mode_shapes->size[2];
  inv_mode_shapes->size[0] = proc_tx_mode->size[0];
  loop_ub = raw_freq_data->size[1];
  inv_mode_shapes->size[1] = raw_freq_data->size[1];
  b_i = ms_matrix_calc_freqs->size[1];
  inv_mode_shapes->size[2] = ms_matrix_calc_freqs->size[1];
  emxEnsureCapacity_creal_T(sp, inv_mode_shapes, b_n, &le_emlrtRTEI);
  inv_mode_shapes_data = inv_mode_shapes->data;
  loop_ub_tmp = proc_tx_mode->size[0] * raw_freq_data->size[1];
  n = loop_ub_tmp * ms_matrix_calc_freqs->size[1];
  for (i = 0; i < n; i++) {
    inv_mode_shapes_data[i].re = 0.0;
    inv_mode_shapes_data[i].im = 0.0;
  }

  emxInit_creal_T(sp, &mode_shapes, 2, &me_emlrtRTEI);
  n = mode_shapes->size[0] * mode_shapes->size[1];
  mode_shapes->size[0] = raw_freq_data->size[1];
  mode_shapes->size[1] = proc_tx_mode->size[0];
  emxEnsureCapacity_creal_T(sp, mode_shapes, n, &me_emlrtRTEI);
  mode_shapes_data = mode_shapes->data;
  for (i = 0; i < loop_ub_tmp; i++) {
    mode_shapes_data[i].re = 0.0;
    mode_shapes_data[i].im = 0.0;
  }

  emxInit_creal_T(sp, &temp_mode_shape, 3, &ne_emlrtRTEI);
  emxInit_real_T(sp, &temp_waveno, 1, &oe_emlrtRTEI);
  emxInit_creal_T(sp, &r, 2, &cf_emlrtRTEI);
  emxInit_creal_T(sp, &r1, 2, &df_emlrtRTEI);
  emxInit_real_T(sp, &b_disperse_freq, 1, &qe_emlrtRTEI);
  emxInit_creal_T(sp, &b_disperse_ms_x, 2, &se_emlrtRTEI);
  emxInit_real_T(sp, &b_disperse_waveno, 1, &ye_emlrtRTEI);
  emxInit_real_T(sp, &b_array_trans_pos_orientations, 2, &af_emlrtRTEI);
  emxInit_real_T(sp, &c_array_trans_pos_orientations, 2, &bf_emlrtRTEI);
  for (ii = 0; ii < b_i; ii++) {
    real_T re_tmp;
    int32_T b_loop_ub;
    int32_T b_ms_matrix_modes_to_use;
    int32_T c_loop_ub;
    int32_T d_loop_ub;
    int32_T i1;
    int32_T re_tmp_tmp;

    /* interpolate to get mode shapes and wavenumbers of all the modes at the current frequency */
    if (!(max_mode_index >= 0.0)) {
      emlrtNonNegativeCheckR2012b(max_mode_index, &t_emlrtDCI, (emlrtConstCTX)sp);
    }

    b_loop_ub = (int32_T)muDoubleScalarFloor(max_mode_index);
    if (max_mode_index != b_loop_ub) {
      emlrtIntegerCheckR2012b(max_mode_index, &s_emlrtDCI, (emlrtConstCTX)sp);
    }

    b_n = (int32_T)max_mode_index;
    n = temp_mode_shape->size[0] * temp_mode_shape->size[1] *
      temp_mode_shape->size[2];
    temp_mode_shape->size[0] = (int32_T)max_mode_index;
    c_loop_ub = disperse_ms_x->size[1];
    temp_mode_shape->size[1] = disperse_ms_x->size[1];
    temp_mode_shape->size[2] = 3;
    emxEnsureCapacity_creal_T(sp, temp_mode_shape, n, &ne_emlrtRTEI);
    temp_mode_shape_data = temp_mode_shape->data;
    n = (int32_T)max_mode_index * disperse_ms_x->size[1] * 3;
    for (i = 0; i < n; i++) {
      temp_mode_shape_data[i].re = 0.0;
      temp_mode_shape_data[i].im = 0.0;
    }

    if (max_mode_index != b_loop_ub) {
      emlrtIntegerCheckR2012b(max_mode_index, &u_emlrtDCI, (emlrtConstCTX)sp);
    }

    n = temp_waveno->size[0];
    i1 = (int32_T)max_mode_index;
    temp_waveno->size[0] = i1;
    emxEnsureCapacity_real_T(sp, temp_waveno, n, &oe_emlrtRTEI);
    temp_waveno_data = temp_waveno->data;
    if (i1 != b_loop_ub) {
      emlrtIntegerCheckR2012b(max_mode_index, &u_emlrtDCI, (emlrtConstCTX)sp);
    }

    for (i = 0; i < b_n; i++) {
      temp_waveno_data[i] = 0.0;
    }

    /* Need to make this x, y and z (and perhaps normal and tangential also?) */
    /* so that the necessary direction can be selected when building the */
    /* matrix below. Also, this needs to take into account the phase */
    /* orientation of the transducers which is not currently used?? */
    re_tmp_tmp = ms_matrix_modes_to_use->size[1];
    for (jj = 0; jj < re_tmp_tmp; jj++) {
      boolean_T b;
      if (jj + 1 > re_tmp_tmp) {
        emlrtDynamicBoundsCheckR2012b(jj + 1, 1, re_tmp_tmp, &hc_emlrtBCI,
          (emlrtConstCTX)sp);
      }

      im = ms_matrix_modes_to_use_data[jj];
      ex = (int32_T)muDoubleScalarFloor(im);
      if (im != ex) {
        emlrtIntegerCheckR2012b(im, &j_emlrtDCI, (emlrtConstCTX)sp);
      }

      b = (((int32_T)im < 1) || ((int32_T)im > i1));
      if (b) {
        emlrtDynamicBoundsCheckR2012b((int32_T)im, 1, i1, &xb_emlrtBCI,
          (emlrtConstCTX)sp);
      }

      if (jj + 1 > re_tmp_tmp) {
        emlrtDynamicBoundsCheckR2012b(jj + 1, 1, re_tmp_tmp, &ic_emlrtBCI,
          (emlrtConstCTX)sp);
      }

      if (im != ex) {
        emlrtIntegerCheckR2012b(im, &r_emlrtDCI, (emlrtConstCTX)sp);
      }

      if (((int32_T)im < 1) || ((int32_T)im > disperse_freq->size[2])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)im, 1, disperse_freq->size[2],
          &gc_emlrtBCI, (emlrtConstCTX)sp);
      }

      if (jj + 1 > re_tmp_tmp) {
        emlrtDynamicBoundsCheckR2012b(jj + 1, 1, re_tmp_tmp, &jc_emlrtBCI,
          (emlrtConstCTX)sp);
      }

      if (im != ex) {
        emlrtIntegerCheckR2012b(im, &q_emlrtDCI, (emlrtConstCTX)sp);
      }

      if (((int32_T)im < 1) || ((int32_T)im > disperse_ms_x->size[2])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)im, 1, disperse_ms_x->size[2],
          &fc_emlrtBCI, (emlrtConstCTX)sp);
      }

      d_loop_ub = disperse_freq->size[0];
      n = b_disperse_freq->size[0];
      b_disperse_freq->size[0] = disperse_freq->size[0];
      emxEnsureCapacity_real_T(sp, b_disperse_freq, n, &qe_emlrtRTEI);
      b_disperse_freq_data = b_disperse_freq->data;
      for (i = 0; i < d_loop_ub; i++) {
        b_disperse_freq_data[i] = disperse_freq_data[i + disperse_freq->size[0] *
          ((int32_T)im - 1)];
      }

      b_loop_ub = disperse_ms_x->size[0];
      n = b_disperse_ms_x->size[0] * b_disperse_ms_x->size[1];
      b_disperse_ms_x->size[0] = disperse_ms_x->size[0];
      b_disperse_ms_x->size[1] = c_loop_ub;
      emxEnsureCapacity_creal_T(sp, b_disperse_ms_x, n, &se_emlrtRTEI);
      b_disperse_ms_x_data = b_disperse_ms_x->data;
      for (i = 0; i < c_loop_ub; i++) {
        for (b_jj = 0; b_jj < b_loop_ub; b_jj++) {
          b_disperse_ms_x_data[b_jj + b_disperse_ms_x->size[0] * i] =
            disperse_ms_x_data[(b_jj + disperse_ms_x->size[0] * i) +
            disperse_ms_x->size[0] * disperse_ms_x->size[1] * ((int32_T)im - 1)];
        }
      }

      if (ii + 1 > b_i) {
        emlrtDynamicBoundsCheckR2012b(ii + 1, 1, b_i, &kc_emlrtBCI,
          (emlrtConstCTX)sp);
      }

      re_tmp = ms_matrix_calc_freqs_data[ii];
      st.site = &hd_emlrtRSI;
      interp1(&st, b_disperse_freq, b_disperse_ms_x, re_tmp, r);
      r2 = r->data;
      b_inv_mode_shapes[0] = 1;
      b_inv_mode_shapes[1] = c_loop_ub;
      emlrtSubAssignSizeCheckR2012b(&b_inv_mode_shapes[0], 2, &r->size[0], 2,
        &m_emlrtECI, (emlrtCTX)sp);
      b_ms_matrix_modes_to_use = (int32_T)ms_matrix_modes_to_use_data[jj];
      for (i = 0; i < c_loop_ub; i++) {
        temp_mode_shape_data[(b_ms_matrix_modes_to_use + temp_mode_shape->size[0]
                              * i) - 1] = r2[i];
      }

      if (jj + 1 > re_tmp_tmp) {
        emlrtDynamicBoundsCheckR2012b(jj + 1, 1, re_tmp_tmp, &pc_emlrtBCI,
          (emlrtConstCTX)sp);
      }

      if (im != ex) {
        emlrtIntegerCheckR2012b(im, &i_emlrtDCI, (emlrtConstCTX)sp);
      }

      if (b) {
        emlrtDynamicBoundsCheckR2012b((int32_T)im, 1, i1, &wb_emlrtBCI,
          (emlrtConstCTX)sp);
      }

      if (jj + 1 > re_tmp_tmp) {
        emlrtDynamicBoundsCheckR2012b(jj + 1, 1, re_tmp_tmp, &sc_emlrtBCI,
          (emlrtConstCTX)sp);
      }

      if (im != ex) {
        emlrtIntegerCheckR2012b(im, &p_emlrtDCI, (emlrtConstCTX)sp);
      }

      if (((int32_T)im < 1) || ((int32_T)im > disperse_freq->size[2])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)im, 1, disperse_freq->size[2],
          &ec_emlrtBCI, (emlrtConstCTX)sp);
      }

      if (jj + 1 > re_tmp_tmp) {
        emlrtDynamicBoundsCheckR2012b(jj + 1, 1, re_tmp_tmp, &vc_emlrtBCI,
          (emlrtConstCTX)sp);
      }

      if (im != ex) {
        emlrtIntegerCheckR2012b(im, &o_emlrtDCI, (emlrtConstCTX)sp);
      }

      if (((int32_T)im < 1) || ((int32_T)im > disperse_ms_y->size[2])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)im, 1, disperse_ms_y->size[2],
          &dc_emlrtBCI, (emlrtConstCTX)sp);
      }

      n = b_disperse_freq->size[0];
      b_disperse_freq->size[0] = disperse_freq->size[0];
      emxEnsureCapacity_real_T(sp, b_disperse_freq, n, &te_emlrtRTEI);
      b_disperse_freq_data = b_disperse_freq->data;
      for (i = 0; i < d_loop_ub; i++) {
        b_disperse_freq_data[i] = disperse_freq_data[i + disperse_freq->size[0] *
          ((int32_T)im - 1)];
      }

      b_loop_ub = disperse_ms_y->size[0];
      n = b_disperse_ms_x->size[0] * b_disperse_ms_x->size[1];
      b_disperse_ms_x->size[0] = disperse_ms_y->size[0];
      b_n = disperse_ms_y->size[1];
      b_disperse_ms_x->size[1] = disperse_ms_y->size[1];
      emxEnsureCapacity_creal_T(sp, b_disperse_ms_x, n, &ue_emlrtRTEI);
      b_disperse_ms_x_data = b_disperse_ms_x->data;
      for (i = 0; i < b_n; i++) {
        for (b_jj = 0; b_jj < b_loop_ub; b_jj++) {
          b_disperse_ms_x_data[b_jj + b_disperse_ms_x->size[0] * i] =
            disperse_ms_y_data[(b_jj + disperse_ms_y->size[0] * i) +
            disperse_ms_y->size[0] * disperse_ms_y->size[1] * ((int32_T)im - 1)];
        }
      }

      if (ii + 1 > b_i) {
        emlrtDynamicBoundsCheckR2012b(ii + 1, 1, b_i, &xc_emlrtBCI,
          (emlrtConstCTX)sp);
      }

      st.site = &id_emlrtRSI;
      interp1(&st, b_disperse_freq, b_disperse_ms_x, re_tmp, r);
      r2 = r->data;
      b_inv_mode_shapes[0] = 1;
      b_inv_mode_shapes[1] = c_loop_ub;
      emlrtSubAssignSizeCheckR2012b(&b_inv_mode_shapes[0], 2, &r->size[0], 2,
        &l_emlrtECI, (emlrtCTX)sp);
      for (i = 0; i < c_loop_ub; i++) {
        temp_mode_shape_data[((b_ms_matrix_modes_to_use + temp_mode_shape->size
          [0] * i) + temp_mode_shape->size[0] * temp_mode_shape->size[1]) - 1] =
          r2[i];
      }

      if (jj + 1 > re_tmp_tmp) {
        emlrtDynamicBoundsCheckR2012b(jj + 1, 1, re_tmp_tmp, &gd_emlrtBCI,
          (emlrtConstCTX)sp);
      }

      if (im != ex) {
        emlrtIntegerCheckR2012b(im, &h_emlrtDCI, (emlrtConstCTX)sp);
      }

      if (b) {
        emlrtDynamicBoundsCheckR2012b((int32_T)im, 1, i1, &vb_emlrtBCI,
          (emlrtConstCTX)sp);
      }

      if (jj + 1 > re_tmp_tmp) {
        emlrtDynamicBoundsCheckR2012b(jj + 1, 1, re_tmp_tmp, &hd_emlrtBCI,
          (emlrtConstCTX)sp);
      }

      if (im != ex) {
        emlrtIntegerCheckR2012b(im, &n_emlrtDCI, (emlrtConstCTX)sp);
      }

      if (((int32_T)im < 1) || ((int32_T)im > disperse_freq->size[2])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)im, 1, disperse_freq->size[2],
          &cc_emlrtBCI, (emlrtConstCTX)sp);
      }

      if (jj + 1 > re_tmp_tmp) {
        emlrtDynamicBoundsCheckR2012b(jj + 1, 1, re_tmp_tmp, &id_emlrtBCI,
          (emlrtConstCTX)sp);
      }

      if (im != ex) {
        emlrtIntegerCheckR2012b(im, &m_emlrtDCI, (emlrtConstCTX)sp);
      }

      if (((int32_T)im < 1) || ((int32_T)im > disperse_ms_z->size[2])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)im, 1, disperse_ms_z->size[2],
          &bc_emlrtBCI, (emlrtConstCTX)sp);
      }

      n = b_disperse_freq->size[0];
      b_disperse_freq->size[0] = disperse_freq->size[0];
      emxEnsureCapacity_real_T(sp, b_disperse_freq, n, &ve_emlrtRTEI);
      b_disperse_freq_data = b_disperse_freq->data;
      for (i = 0; i < d_loop_ub; i++) {
        b_disperse_freq_data[i] = disperse_freq_data[i + disperse_freq->size[0] *
          ((int32_T)im - 1)];
      }

      b_loop_ub = disperse_ms_z->size[0];
      n = b_disperse_ms_x->size[0] * b_disperse_ms_x->size[1];
      b_disperse_ms_x->size[0] = disperse_ms_z->size[0];
      b_n = disperse_ms_z->size[1];
      b_disperse_ms_x->size[1] = disperse_ms_z->size[1];
      emxEnsureCapacity_creal_T(sp, b_disperse_ms_x, n, &we_emlrtRTEI);
      b_disperse_ms_x_data = b_disperse_ms_x->data;
      for (i = 0; i < b_n; i++) {
        for (b_jj = 0; b_jj < b_loop_ub; b_jj++) {
          b_disperse_ms_x_data[b_jj + b_disperse_ms_x->size[0] * i] =
            disperse_ms_z_data[(b_jj + disperse_ms_z->size[0] * i) +
            disperse_ms_z->size[0] * disperse_ms_z->size[1] * ((int32_T)im - 1)];
        }
      }

      if (ii + 1 > b_i) {
        emlrtDynamicBoundsCheckR2012b(ii + 1, 1, b_i, &kd_emlrtBCI,
          (emlrtConstCTX)sp);
      }

      st.site = &jd_emlrtRSI;
      interp1(&st, b_disperse_freq, b_disperse_ms_x, re_tmp, r);
      r2 = r->data;
      b_inv_mode_shapes[0] = 1;
      b_inv_mode_shapes[1] = c_loop_ub;
      emlrtSubAssignSizeCheckR2012b(&b_inv_mode_shapes[0], 2, &r->size[0], 2,
        &k_emlrtECI, (emlrtCTX)sp);
      for (i = 0; i < c_loop_ub; i++) {
        temp_mode_shape_data[((b_ms_matrix_modes_to_use + temp_mode_shape->size
          [0] * i) + temp_mode_shape->size[0] * temp_mode_shape->size[1] * 2) -
          1] = r2[i];
      }

      if (jj + 1 > re_tmp_tmp) {
        emlrtDynamicBoundsCheckR2012b(jj + 1, 1, re_tmp_tmp, &ld_emlrtBCI,
          (emlrtConstCTX)sp);
      }

      if (im != ex) {
        emlrtIntegerCheckR2012b(im, &l_emlrtDCI, (emlrtConstCTX)sp);
      }

      if (((int32_T)im < 1) || ((int32_T)im > disperse_freq->size[2])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)im, 1, disperse_freq->size[2],
          &ac_emlrtBCI, (emlrtConstCTX)sp);
      }

      if (jj + 1 > re_tmp_tmp) {
        emlrtDynamicBoundsCheckR2012b(jj + 1, 1, re_tmp_tmp, &md_emlrtBCI,
          (emlrtConstCTX)sp);
      }

      if (im != ex) {
        emlrtIntegerCheckR2012b(im, &k_emlrtDCI, (emlrtConstCTX)sp);
      }

      if (((int32_T)im < 1) || ((int32_T)im > disperse_waveno->size[2])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)im, 1, disperse_waveno->size[2],
          &yb_emlrtBCI, (emlrtConstCTX)sp);
      }

      n = b_disperse_freq->size[0];
      b_disperse_freq->size[0] = disperse_freq->size[0];
      emxEnsureCapacity_real_T(sp, b_disperse_freq, n, &xe_emlrtRTEI);
      b_disperse_freq_data = b_disperse_freq->data;
      for (i = 0; i < d_loop_ub; i++) {
        b_disperse_freq_data[i] = disperse_freq_data[i + disperse_freq->size[0] *
          ((int32_T)im - 1)];
      }

      b_n = disperse_waveno->size[0];
      n = b_disperse_waveno->size[0];
      b_disperse_waveno->size[0] = disperse_waveno->size[0];
      emxEnsureCapacity_real_T(sp, b_disperse_waveno, n, &ye_emlrtRTEI);
      b_disperse_freq_data = b_disperse_waveno->data;
      for (i = 0; i < b_n; i++) {
        b_disperse_freq_data[i] = disperse_waveno_data[i + disperse_waveno->
          size[0] * ((int32_T)im - 1)];
      }

      if (ii + 1 > b_i) {
        emlrtDynamicBoundsCheckR2012b(ii + 1, 1, b_i, &nd_emlrtBCI,
          (emlrtConstCTX)sp);
      }

      if (jj + 1 > re_tmp_tmp) {
        emlrtDynamicBoundsCheckR2012b(jj + 1, 1, re_tmp_tmp, &pd_emlrtBCI,
          (emlrtConstCTX)sp);
      }

      if (im != ex) {
        emlrtIntegerCheckR2012b(im, &v_emlrtDCI, (emlrtConstCTX)sp);
      }

      if (((int32_T)im < 1) || ((int32_T)im > temp_waveno->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)im, 1, temp_waveno->size[0],
          &od_emlrtBCI, (emlrtConstCTX)sp);
      }

      st.site = &kd_emlrtRSI;
      temp_waveno_data[(int32_T)im - 1] = b_interp1(&st, b_disperse_freq,
        b_disperse_waveno, re_tmp);
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtConstCTX)sp);
      }
    }

    /* build the mode shape matrix at this frequency, taking into account the */
    /* orientation of the transducers */
    for (b_jj = 0; b_jj < last; b_jj++) {
      for (jj = 0; jj < loop_ub; jj++) {
        creal_T b_temp_mode_shape[3];
        creal_T c_temp_mode_shape[3];
        int64_T i2;
        int64_T i3;
        int64_T i4;
        real_T b_re_tmp;
        real_T b_y_im;
        real_T c_re_tmp;
        real_T d;
        real_T d_re_tmp;
        real_T y_im;
        real_T y_re;
        int32_T b_re_tmp_tmp;
        int32_T e_loop_ub;
        if (b_jj + 1 > last) {
          emlrtDynamicBoundsCheckR2012b(b_jj + 1, 1, last, &lc_emlrtBCI,
            (emlrtConstCTX)sp);
        }

        ex = proc_tx_mode_data[b_jj];
        im = (int32_T)muDoubleScalarFloor(ex);
        if (ex != im) {
          emlrtIntegerCheckR2012b(ex, &e_emlrtDCI, (emlrtConstCTX)sp);
        }

        if (((int32_T)ex < 1) || ((int32_T)ex > temp_waveno->size[0])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)ex, 1, temp_waveno->size[0],
            &ob_emlrtBCI, (emlrtConstCTX)sp);
        }

        if (jj + 1 > raw_tx->size[0]) {
          emlrtDynamicBoundsCheckR2012b(jj + 1, 1, raw_tx->size[0], &oc_emlrtBCI,
            (emlrtConstCTX)sp);
        }

        i2 = raw_tx_data[jj];
        if ((i2 < 1LL) || (i2 > array_trans_row->size[1])) {
          emlrtDynamicBoundsCheckInt64(i2, 1, array_trans_row->size[1],
            &nc_emlrtBCI, (emlrtCTX)sp);
        }

        i3 = array_trans_row_data[(int32_T)i2 - 1];
        if ((i3 < 1LL) || (i3 > array_row_pos->size[1])) {
          emlrtDynamicBoundsCheckInt64(i3, 1, array_row_pos->size[1],
            &nb_emlrtBCI, (emlrtCTX)sp);
        }

        if (b_jj + 1 > proc_tx_dir->size[0]) {
          emlrtDynamicBoundsCheckR2012b(b_jj + 1, 1, proc_tx_dir->size[0],
            &mb_emlrtBCI, (emlrtConstCTX)sp);
        }

        b_ms_matrix_modes_to_use = (int32_T)proc_tx_mode_data[b_jj] - 1;
        re_tmp = temp_waveno_data[b_ms_matrix_modes_to_use];
        d_loop_ub = (int32_T)raw_tx_data[jj] - 1;
        b_re_tmp = array_row_pos_data[(int32_T)array_trans_row_data[d_loop_ub] -
          1];
        y_im = proc_tx_dir_data[b_jj] * (b_re_tmp * re_tmp);
        if (b_jj + 1 > b_last) {
          emlrtDynamicBoundsCheckR2012b(b_jj + 1, 1, b_last, &rc_emlrtBCI,
            (emlrtConstCTX)sp);
        }

        y_re = proc_rx_mode_data[b_jj];
        d = (int32_T)muDoubleScalarFloor(y_re);
        if (y_re != d) {
          emlrtIntegerCheckR2012b(y_re, &d_emlrtDCI, (emlrtConstCTX)sp);
        }

        if (((int32_T)y_re < 1) || ((int32_T)y_re > temp_waveno->size[0])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)y_re, 1, temp_waveno->size[0],
            &lb_emlrtBCI, (emlrtConstCTX)sp);
        }

        if (jj + 1 > raw_rx->size[0]) {
          emlrtDynamicBoundsCheckR2012b(jj + 1, 1, raw_rx->size[0], &uc_emlrtBCI,
            (emlrtConstCTX)sp);
        }

        i4 = raw_rx_data[jj];
        if ((i4 < 1LL) || (i4 > array_trans_row->size[1])) {
          emlrtDynamicBoundsCheckInt64(i4, 1, array_trans_row->size[1],
            &tc_emlrtBCI, (emlrtCTX)sp);
        }

        i3 = array_trans_row_data[(int32_T)i4 - 1];
        if ((i3 < 1LL) || (i3 > array_row_pos->size[1])) {
          emlrtDynamicBoundsCheckInt64(i3, 1, array_row_pos->size[1],
            &kb_emlrtBCI, (emlrtCTX)sp);
        }

        if (b_jj + 1 > proc_rx_dir->size[0]) {
          emlrtDynamicBoundsCheckR2012b(b_jj + 1, 1, proc_rx_dir->size[0],
            &jb_emlrtBCI, (emlrtConstCTX)sp);
        }

        re_tmp_tmp = (int32_T)proc_rx_mode_data[b_jj] - 1;
        c_re_tmp = temp_waveno_data[re_tmp_tmp];
        b_re_tmp_tmp = (int32_T)raw_rx_data[jj] - 1;
        d_re_tmp = array_row_pos_data[(int32_T)array_trans_row_data[b_re_tmp_tmp]
          - 1];
        b_y_im = proc_rx_dir_data[b_jj] * (d_re_tmp * c_re_tmp);
        if (b_jj + 1 > last) {
          emlrtDynamicBoundsCheckR2012b(b_jj + 1, 1, last, &wc_emlrtBCI,
            (emlrtConstCTX)sp);
        }

        if (ex != im) {
          emlrtIntegerCheckR2012b(ex, &g_emlrtDCI, (emlrtConstCTX)sp);
        }

        if (((int32_T)ex < 1) || ((int32_T)ex > i1)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)ex, 1, i1, &ub_emlrtBCI,
            (emlrtConstCTX)sp);
        }

        if (jj + 1 > raw_tx->size[0]) {
          emlrtDynamicBoundsCheckR2012b(jj + 1, 1, raw_tx->size[0], &bd_emlrtBCI,
            (emlrtConstCTX)sp);
        }

        if ((int32_T)i2 > array_trans_pos->size[1]) {
          emlrtDynamicBoundsCheckInt64(i2, 1, array_trans_pos->size[1],
            &ad_emlrtBCI, (emlrtCTX)sp);
        }

        i3 = array_trans_pos_data[(int32_T)i2 - 1];
        if ((i3 < 1LL) || (i3 > array_trans_node_list->size[1])) {
          emlrtDynamicBoundsCheckInt64(i3, 1, array_trans_node_list->size[1],
            &yc_emlrtBCI, (emlrtCTX)sp);
        }

        i3 = array_trans_node_list_data[(int32_T)i3 - 1];
        if ((i3 < 1LL) || (i3 > c_loop_ub)) {
          emlrtDynamicBoundsCheckInt64(i3, 1, c_loop_ub, &tb_emlrtBCI, (emlrtCTX)
            sp);
        }

        if (b_jj + 1 > b_last) {
          emlrtDynamicBoundsCheckR2012b(b_jj + 1, 1, b_last, &cd_emlrtBCI,
            (emlrtConstCTX)sp);
        }

        if (y_re != d) {
          emlrtIntegerCheckR2012b(y_re, &f_emlrtDCI, (emlrtConstCTX)sp);
        }

        if (((int32_T)y_re < 1) || ((int32_T)y_re > i1)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)y_re, 1, i1, &rb_emlrtBCI,
            (emlrtConstCTX)sp);
        }

        if (jj + 1 > raw_rx->size[0]) {
          emlrtDynamicBoundsCheckR2012b(jj + 1, 1, raw_rx->size[0], &fd_emlrtBCI,
            (emlrtConstCTX)sp);
        }

        if ((int32_T)i4 > array_trans_pos->size[1]) {
          emlrtDynamicBoundsCheckInt64(i4, 1, array_trans_pos->size[1],
            &ed_emlrtBCI, (emlrtCTX)sp);
        }

        i3 = array_trans_pos_data[(int32_T)i4 - 1];
        if ((i3 < 1LL) || (i3 > array_trans_node_list->size[1])) {
          emlrtDynamicBoundsCheckInt64(i3, 1, array_trans_node_list->size[1],
            &dd_emlrtBCI, (emlrtCTX)sp);
        }

        i3 = array_trans_node_list_data[(int32_T)i3 - 1];
        if ((i3 < 1LL) || (i3 > c_loop_ub)) {
          emlrtDynamicBoundsCheckInt64(i3, 1, c_loop_ub, &qb_emlrtBCI, (emlrtCTX)
            sp);
        }

        if (proc_tx_dir_data[b_jj] * (b_re_tmp * (re_tmp * 0.0)) == 0.0) {
          y_re = muDoubleScalarCos(y_im);
          y_im = muDoubleScalarSin(y_im);
        } else if (y_im == 0.0) {
          y_re = rtNaN;
          y_im = 0.0;
        } else {
          y_re = rtNaN;
          y_im = rtNaN;
        }

        if (proc_rx_dir_data[b_jj] * (d_re_tmp * (c_re_tmp * 0.0)) == 0.0) {
          re_tmp = muDoubleScalarCos(b_y_im);
          b_y_im = muDoubleScalarSin(b_y_im);
        } else if (b_y_im == 0.0) {
          re_tmp = rtNaN;
          b_y_im = 0.0;
        } else {
          re_tmp = rtNaN;
          b_y_im = rtNaN;
        }

        st.site = &ld_emlrtRSI;
        if (jj + 1 > raw_tx->size[0]) {
          emlrtDynamicBoundsCheckR2012b(jj + 1, 1, raw_tx->size[0], &jd_emlrtBCI,
            &st);
        }

        if ((int32_T)i2 > array_trans_pos_orientations->size[0]) {
          emlrtDynamicBoundsCheckInt64(i2, 1, array_trans_pos_orientations->
            size[0], &sb_emlrtBCI, &st);
        }

        b_st.site = &ve_emlrtRSI;
        e_loop_ub = array_trans_pos_orientations->size[1];
        c_st.site = &pe_emlrtRSI;
        d_st.site = &qe_emlrtRSI;
        n = 1;
        if (array_trans_pos_orientations->size[1] > 1) {
          n = array_trans_pos_orientations->size[1];
        }

        if (array_trans_pos_orientations->size[1] > muIntScalarMax_sint32
            (e_loop_ub, n)) {
          emlrtErrorWithMessageIdR2018a(&b_st, &m_emlrtRTEI,
            "Coder:toolbox:reshape_emptyReshapeLimit",
            "Coder:toolbox:reshape_emptyReshapeLimit", 0);
        }

        st.site = &md_emlrtRSI;
        if (jj + 1 > raw_rx->size[0]) {
          emlrtDynamicBoundsCheckR2012b(jj + 1, 1, raw_rx->size[0], &qd_emlrtBCI,
            &st);
        }

        if ((int32_T)i4 > array_trans_pos_orientations->size[0]) {
          emlrtDynamicBoundsCheckInt64(i4, 1, array_trans_pos_orientations->
            size[0], &pb_emlrtBCI, &st);
        }

        b_st.site = &ve_emlrtRSI;
        c_st.site = &pe_emlrtRSI;
        d_st.site = &qe_emlrtRSI;
        b_n = 1;
        if (array_trans_pos_orientations->size[1] > 1) {
          b_n = array_trans_pos_orientations->size[1];
        }

        if (array_trans_pos_orientations->size[1] > muIntScalarMax_sint32
            (e_loop_ub, b_n)) {
          emlrtErrorWithMessageIdR2018a(&b_st, &m_emlrtRTEI,
            "Coder:toolbox:reshape_emptyReshapeLimit",
            "Coder:toolbox:reshape_emptyReshapeLimit", 0);
        }

        b_loop_ub = (int32_T)array_trans_node_list_data[(int32_T)
          array_trans_pos_data[d_loop_ub] - 1];
        b_temp_mode_shape[0] = temp_mode_shape_data[b_ms_matrix_modes_to_use +
          temp_mode_shape->size[0] * (b_loop_ub - 1)];
        b_temp_mode_shape[1] = temp_mode_shape_data[(b_ms_matrix_modes_to_use +
          temp_mode_shape->size[0] * (b_loop_ub - 1)) + temp_mode_shape->size[0]
          * temp_mode_shape->size[1]];
        b_temp_mode_shape[2] = temp_mode_shape_data[(b_ms_matrix_modes_to_use +
          temp_mode_shape->size[0] * (b_loop_ub - 1)) + temp_mode_shape->size[0]
          * temp_mode_shape->size[1] * 2];
        n = b_array_trans_pos_orientations->size[0] *
          b_array_trans_pos_orientations->size[1];
        b_array_trans_pos_orientations->size[0] = 1;
        b_array_trans_pos_orientations->size[1] =
          array_trans_pos_orientations->size[1];
        emxEnsureCapacity_real_T(sp, b_array_trans_pos_orientations, n,
          &af_emlrtRTEI);
        b_disperse_freq_data = b_array_trans_pos_orientations->data;
        for (i = 0; i < e_loop_ub; i++) {
          b_disperse_freq_data[i] = c_array_trans_pos_orientations_[d_loop_ub +
            array_trans_pos_orientations->size[0] * i];
        }

        n = (int32_T)array_trans_node_list_data[(int32_T)
          array_trans_pos_data[b_re_tmp_tmp] - 1];
        c_temp_mode_shape[0] = temp_mode_shape_data[re_tmp_tmp +
          temp_mode_shape->size[0] * (n - 1)];
        c_temp_mode_shape[1] = temp_mode_shape_data[(re_tmp_tmp +
          temp_mode_shape->size[0] * (n - 1)) + temp_mode_shape->size[0] *
          temp_mode_shape->size[1]];
        c_temp_mode_shape[2] = temp_mode_shape_data[(re_tmp_tmp +
          temp_mode_shape->size[0] * (n - 1)) + temp_mode_shape->size[0] *
          temp_mode_shape->size[1] * 2];
        n = c_array_trans_pos_orientations->size[0] *
          c_array_trans_pos_orientations->size[1];
        c_array_trans_pos_orientations->size[0] = 1;
        c_array_trans_pos_orientations->size[1] =
          array_trans_pos_orientations->size[1];
        emxEnsureCapacity_real_T(sp, c_array_trans_pos_orientations, n,
          &bf_emlrtRTEI);
        b_disperse_freq_data = c_array_trans_pos_orientations->data;
        for (i = 0; i < e_loop_ub; i++) {
          b_disperse_freq_data[i] = c_array_trans_pos_orientations_[b_re_tmp_tmp
            + array_trans_pos_orientations->size[0] * i];
        }

        creal_T b_dc;
        creal_T b_dc1;
        st.site = &ld_emlrtRSI;
        b_dc = dot(&st, b_temp_mode_shape, b_array_trans_pos_orientations);
        st.site = &md_emlrtRSI;
        b_dc1 = dot(&st, c_temp_mode_shape, c_array_trans_pos_orientations);
        ex = b_dc.re * b_dc1.re - b_dc.im * b_dc1.im;
        im = b_dc.re * b_dc1.im + b_dc.im * b_dc1.re;
        b_re_tmp = ex * y_re - im * y_im;
        ex = ex * y_im + im * y_re;
        if (jj + 1 > loop_ub) {
          emlrtDynamicBoundsCheckR2012b(jj + 1, 1, loop_ub, &rd_emlrtBCI,
            (emlrtConstCTX)sp);
        }

        if (b_jj + 1 > last) {
          emlrtDynamicBoundsCheckR2012b(b_jj + 1, 1, last, &rd_emlrtBCI,
            (emlrtConstCTX)sp);
        }

        mode_shapes_data[jj + mode_shapes->size[0] * b_jj].re = b_re_tmp *
          re_tmp - ex * b_y_im;
        if (jj + 1 > loop_ub) {
          emlrtDynamicBoundsCheckR2012b(jj + 1, 1, loop_ub, &rd_emlrtBCI,
            (emlrtConstCTX)sp);
        }

        if (b_jj + 1 > last) {
          emlrtDynamicBoundsCheckR2012b(b_jj + 1, 1, last, &rd_emlrtBCI,
            (emlrtConstCTX)sp);
        }

        mode_shapes_data[jj + mode_shapes->size[0] * b_jj].im = b_re_tmp *
          b_y_im + ex * re_tmp;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b((emlrtConstCTX)sp);
        }
      }

      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtConstCTX)sp);
      }
    }

    for (i = 0; i < loop_ub_tmp; i++) {
      if (muDoubleScalarIsNaN(mode_shapes_data[i].re) || muDoubleScalarIsNaN
          (mode_shapes_data[i].im)) {
        if (i > loop_ub_tmp - 1) {
          emlrtDynamicBoundsCheckR2012b(i, 0, loop_ub_tmp - 1, &mc_emlrtBCI,
            (emlrtConstCTX)sp);
        }

        mode_shapes_data[i].re = 0.0;
        if (i > loop_ub_tmp - 1) {
          emlrtDynamicBoundsCheckR2012b(i, 0, loop_ub_tmp - 1, &mc_emlrtBCI,
            (emlrtConstCTX)sp);
        }

        mode_shapes_data[i].im = 0.0;
      }
    }

    for (i = 0; i < loop_ub_tmp; i++) {
      if (muDoubleScalarIsInf(mode_shapes_data[i].re) || muDoubleScalarIsInf
          (mode_shapes_data[i].im)) {
        if (i > loop_ub_tmp - 1) {
          emlrtDynamicBoundsCheckR2012b(i, 0, loop_ub_tmp - 1, &qc_emlrtBCI,
            (emlrtConstCTX)sp);
        }

        mode_shapes_data[i].re = 0.0;
        if (i > loop_ub_tmp - 1) {
          emlrtDynamicBoundsCheckR2012b(i, 0, loop_ub_tmp - 1, &qc_emlrtBCI,
            (emlrtConstCTX)sp);
        }

        mode_shapes_data[i].im = 0.0;
      }
    }

    if (ii + 1 > b_i) {
      emlrtDynamicBoundsCheckR2012b(ii + 1, 1, b_i, &ib_emlrtBCI, (emlrtConstCTX)
        sp);
    }

    st.site = &nd_emlrtRSI;
    if (mode_shapes->size[0] < mode_shapes->size[1]) {
      n = b_disperse_ms_x->size[0] * b_disperse_ms_x->size[1];
      b_disperse_ms_x->size[0] = last;
      b_disperse_ms_x->size[1] = loop_ub;
      emxEnsureCapacity_creal_T(&st, b_disperse_ms_x, n, &pe_emlrtRTEI);
      b_disperse_ms_x_data = b_disperse_ms_x->data;
      for (i = 0; i < loop_ub; i++) {
        for (b_jj = 0; b_jj < last; b_jj++) {
          b_disperse_ms_x_data[b_jj + b_disperse_ms_x->size[0] * i].re =
            mode_shapes_data[i + mode_shapes->size[0] * b_jj].re;
          b_disperse_ms_x_data[b_jj + b_disperse_ms_x->size[0] * i].im =
            -mode_shapes_data[i + mode_shapes->size[0] * b_jj].im;
        }
      }

      b_st.site = &df_emlrtRSI;
      eml_pinv(&b_st, b_disperse_ms_x, r1);
      r2 = r1->data;
      b_n = r1->size[1];
      n = b_disperse_ms_x->size[0] * b_disperse_ms_x->size[1];
      b_disperse_ms_x->size[0] = r1->size[1];
      b_loop_ub = r1->size[0];
      b_disperse_ms_x->size[1] = r1->size[0];
      emxEnsureCapacity_creal_T(&st, b_disperse_ms_x, n, &re_emlrtRTEI);
      b_disperse_ms_x_data = b_disperse_ms_x->data;
      for (i = 0; i < b_loop_ub; i++) {
        for (b_jj = 0; b_jj < b_n; b_jj++) {
          b_disperse_ms_x_data[b_jj + b_disperse_ms_x->size[0] * i].re = r2[i +
            r1->size[0] * b_jj].re;
          b_disperse_ms_x_data[b_jj + b_disperse_ms_x->size[0] * i].im = -r2[i +
            r1->size[0] * b_jj].im;
        }
      }
    } else {
      b_st.site = &ef_emlrtRSI;
      eml_pinv(&b_st, mode_shapes, b_disperse_ms_x);
      b_disperse_ms_x_data = b_disperse_ms_x->data;
    }

    b_inv_mode_shapes[0] = last;
    b_inv_mode_shapes[1] = loop_ub;
    emlrtSubAssignSizeCheckR2012b(&b_inv_mode_shapes[0], 2,
      &b_disperse_ms_x->size[0], 2, &j_emlrtECI, (emlrtCTX)sp);
    for (i = 0; i < loop_ub; i++) {
      for (b_jj = 0; b_jj < last; b_jj++) {
        inv_mode_shapes_data[(b_jj + inv_mode_shapes->size[0] * i) +
          inv_mode_shapes->size[0] * inv_mode_shapes->size[1] * ii] =
          b_disperse_ms_x_data[b_jj + last * i];
      }
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }

  emxFree_real_T(sp, &c_array_trans_pos_orientations);
  emxFree_real_T(sp, &b_array_trans_pos_orientations);
  emxFree_real_T(sp, &b_disperse_waveno);
  emxFree_creal_T(sp, &b_disperse_ms_x);
  emxFree_real_T(sp, &b_disperse_freq);
  emxFree_creal_T(sp, &r1);
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
  emxInit_real_T(sp, &b_in1, 2, &hd_emlrtRTEI);
  stride_0_1 = b_in1->size[0] * b_in1->size[1];
  b_in1->size[0] = 1;
  if (in2->size[1] == 1) {
    loop_ub = in1->size[1];
  } else {
    loop_ub = in2->size[1];
  }

  b_in1->size[1] = loop_ub;
  emxEnsureCapacity_real_T(sp, b_in1, stride_0_1, &hd_emlrtRTEI);
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
  emxEnsureCapacity_real_T(sp, in1, stride_0_1, &hd_emlrtRTEI);
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
  __m128d r2;
  jmp_buf emlrtJBEnviron;
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
  emxArray_boolean_T *b_raw_tx;
  emxArray_boolean_T *c_proc_tx_mode;
  emxArray_creal_T *b_inv_full_mode_shapes;
  emxArray_creal_T *b_inv_mode_shapes;
  emxArray_creal_T *b_proc_dist_data;
  emxArray_creal_T *b_raw_freq_data;
  emxArray_creal_T *inv_full_mode_shapes;
  emxArray_creal_T *inv_mode_shapes;
  emxArray_creal_T *proc_freq_data;
  emxArray_creal_T *r1;
  emxArray_creal_T *raw_freq_data;
  emxArray_creal_T *yi;
  emxArray_creal_T *yy;
  emxArray_int32_T *b_ii;
  emxArray_int64_T *c_raw_tx;
  emxArray_real_T *b_proc_rx_mode;
  emxArray_real_T *b_proc_tx_mode;
  emxArray_real_T *b_y;
  emxArray_real_T *d_proc_tx_mode;
  emxArray_real_T *freq;
  emxArray_real_T *pitch_catch_indices;
  creal_T *b_inv_full_mode_shapes_data;
  creal_T *inv_full_mode_shapes_data;
  creal_T *inv_mode_shapes_data;
  creal_T *proc_dist_data_data;
  creal_T *proc_freq_data_data;
  creal_T *raw_freq_data_data;
  creal_T *yi_data;
  int64_T *c_raw_tx_data;
  int64_T *raw_rx_data;
  int64_T *raw_tx_data;
  real_T dv[2];
  const real_T *b_raw_time_data;
  const real_T *opts_manual_warps_data;
  real_T f;
  real_T fft_pts;
  real_T freq_i1;
  real_T y;
  real_T y_re;
  real_T *b_proc_rx_mode_data;
  real_T *b_proc_tx_mode_data;
  real_T *opts_ms_matrix_calc_freqs_data;
  real_T *pitch_catch_indices_data;
  real_T *proc_rx_dir_data;
  real_T *proc_rx_mode_data;
  real_T *proc_tx_dir_data;
  real_T *proc_tx_mode_data;
  real_T *raw_time_data_data;
  int32_T iv[2];
  int32_T b_i;
  int32_T b_loop_ub;
  int32_T c_ii;
  int32_T c_loop_ub;
  int32_T c_proc_rx_mode;
  int32_T d_loop_ub;
  int32_T e_loop_ub;
  int32_T eint;
  int32_T f_loop_ub;
  int32_T fcount;
  int32_T fn_process_rail_data_DLL_numThreads;
  int32_T g_loop_ub;
  int32_T h_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T i10;
  int32_T i11;
  int32_T i12;
  int32_T i13;
  int32_T i14;
  int32_T i15;
  int32_T i16;
  int32_T i17;
  int32_T i18;
  int32_T i19;
  int32_T i2;
  int32_T i20;
  int32_T i21;
  int32_T i22;
  int32_T i3;
  int32_T i4;
  int32_T i5;
  int32_T i6;
  int32_T i7;
  int32_T i8;
  int32_T i9;
  int32_T i_loop_ub;
  int32_T ii;
  int32_T j_loop_ub;
  int32_T loop_ub;
  int32_T y_tmp;
  int32_T *ii_data;
  boolean_T b;
  boolean_T emlrtHadParallelError = false;
  boolean_T *b_raw_tx_data;
  (void)array_delay;
  (void)disperse_vph;
  (void)opts_dispersion_compensation;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  i_st.prev = &d_st;
  i_st.tls = d_st.tls;
  opts_manual_warps_data = opts_manual_warps->data;
  opts_ms_matrix_calc_freqs_data = opts_ms_matrix_calc_freqs->data;
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
  emxInit_real_T(&st, &pitch_catch_indices, 1, &yb_emlrtRTEI);
  loop_ub = opts_ms_matrix_modes_to_use->size[1];
  b_loop_ub = pitch_catch_indices->size[0];
  pitch_catch_indices->size[0] = opts_ms_matrix_modes_to_use->size[1];
  emxEnsureCapacity_real_T(&st, pitch_catch_indices, b_loop_ub, &kb_emlrtRTEI);
  pitch_catch_indices_data = pitch_catch_indices->data;
  for (i = 0; i < loop_ub; i++) {
    pitch_catch_indices_data[i] = 1.0;
  }

  emxInit_real_T(&st, &b_proc_tx_mode, 2, &td_emlrtRTEI);
  b_st.site = &m_emlrtRSI;
  mtimes(&b_st, pitch_catch_indices, opts_ms_matrix_modes_to_use, b_proc_tx_mode);
  proc_tx_mode_data = b_proc_tx_mode->data;
  emxInit_real_T(sp, &b_proc_rx_mode, 2, &ud_emlrtRTEI);
  loop_ub = b_proc_tx_mode->size[1];
  b_loop_ub = b_proc_rx_mode->size[0] * b_proc_rx_mode->size[1];
  b_proc_rx_mode->size[0] = b_proc_tx_mode->size[1];
  c_loop_ub = b_proc_tx_mode->size[0];
  b_proc_rx_mode->size[1] = b_proc_tx_mode->size[0];
  emxEnsureCapacity_real_T(sp, b_proc_rx_mode, b_loop_ub, &lb_emlrtRTEI);
  proc_rx_mode_data = b_proc_rx_mode->data;
  for (i = 0; i < c_loop_ub; i++) {
    for (ii = 0; ii < loop_ub; ii++) {
      proc_rx_mode_data[ii + b_proc_rx_mode->size[0] * i] = proc_tx_mode_data[i
        + b_proc_tx_mode->size[0] * ii];
    }
  }

  c_loop_ub = b_proc_tx_mode->size[0] + b_proc_tx_mode->size[0];
  d_loop_ub = c_loop_ub * b_proc_tx_mode->size[1];
  b_loop_ub = proc_tx_dir->size[0];
  proc_tx_dir->size[0] = d_loop_ub;
  emxEnsureCapacity_real_T(sp, proc_tx_dir, b_loop_ub, &mb_emlrtRTEI);
  proc_tx_dir_data = proc_tx_dir->data;
  e_loop_ub = b_proc_tx_mode->size[0] * b_proc_tx_mode->size[1];
  for (i = 0; i < e_loop_ub; i++) {
    proc_tx_dir_data[i] = 1.0;
  }

  for (i = 0; i < e_loop_ub; i++) {
    proc_tx_dir_data[i + e_loop_ub] = -1.0;
  }

  loop_ub = proc_rx_dir->size[0];
  proc_rx_dir->size[0] = d_loop_ub;
  emxEnsureCapacity_real_T(sp, proc_rx_dir, loop_ub, &nb_emlrtRTEI);
  proc_rx_dir_data = proc_rx_dir->data;
  for (i = 0; i < d_loop_ub; i++) {
    proc_rx_dir_data[i] = proc_tx_dir_data[i];
  }

  st.site = &b_emlrtRSI;
  if (muDoubleScalarIsNaN(opts_ms_matrix_bidi_calc)) {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI, "MATLAB:nologicalnan",
      "MATLAB:nologicalnan", 0);
  }

  if (opts_ms_matrix_bidi_calc != 0.0) {
    b_loop_ub = proc_tx_dir->size[0] + proc_tx_dir->size[0];
    loop_ub = pitch_catch_indices->size[0];
    pitch_catch_indices->size[0] = b_loop_ub;
    emxEnsureCapacity_real_T(sp, pitch_catch_indices, loop_ub, &pb_emlrtRTEI);
    pitch_catch_indices_data = pitch_catch_indices->data;
    for (i = 0; i < d_loop_ub; i++) {
      pitch_catch_indices_data[i] = proc_tx_dir_data[i];
    }

    for (i = 0; i < d_loop_ub; i++) {
      pitch_catch_indices_data[i + proc_tx_dir->size[0]] = proc_tx_dir_data[i];
    }

    loop_ub = proc_tx_dir->size[0];
    proc_tx_dir->size[0] = b_loop_ub;
    emxEnsureCapacity_real_T(sp, proc_tx_dir, loop_ub, &rb_emlrtRTEI);
    proc_tx_dir_data = proc_tx_dir->data;
    for (i = 0; i < b_loop_ub; i++) {
      proc_tx_dir_data[i] = pitch_catch_indices_data[i];
    }

    loop_ub = pitch_catch_indices->size[0];
    pitch_catch_indices->size[0] = d_loop_ub;
    emxEnsureCapacity_real_T(sp, pitch_catch_indices, loop_ub, &sb_emlrtRTEI);
    pitch_catch_indices_data = pitch_catch_indices->data;
    for (i = 0; i < d_loop_ub; i++) {
      pitch_catch_indices_data[i] = proc_rx_dir_data[i];
    }

    st.site = &c_emlrtRSI;
    flipud(pitch_catch_indices);
    pitch_catch_indices_data = pitch_catch_indices->data;
    loop_ub = proc_rx_dir->size[0];
    proc_rx_dir->size[0] += pitch_catch_indices->size[0];
    emxEnsureCapacity_real_T(sp, proc_rx_dir, loop_ub, &tb_emlrtRTEI);
    proc_rx_dir_data = proc_rx_dir->data;
    loop_ub = pitch_catch_indices->size[0];
    for (i = 0; i < loop_ub; i++) {
      proc_rx_dir_data[d_loop_ub + i] = pitch_catch_indices_data[i];
    }

    b_loop_ub = c_loop_ub + b_proc_tx_mode->size[0];
    loop_ub = proc_tx_mode->size[0];
    proc_tx_mode->size[0] = (b_loop_ub + b_proc_tx_mode->size[0]) *
      b_proc_tx_mode->size[1];
    emxEnsureCapacity_real_T(sp, proc_tx_mode, loop_ub, &ub_emlrtRTEI);
    b_proc_tx_mode_data = proc_tx_mode->data;
    for (i = 0; i < e_loop_ub; i++) {
      b_proc_tx_mode_data[i] = proc_tx_mode_data[i];
    }

    for (i = 0; i < e_loop_ub; i++) {
      b_proc_tx_mode_data[i + e_loop_ub] = proc_tx_mode_data[i];
    }

    for (i = 0; i < e_loop_ub; i++) {
      b_proc_tx_mode_data[i + d_loop_ub] = proc_tx_mode_data[i];
    }

    for (i = 0; i < e_loop_ub; i++) {
      b_proc_tx_mode_data[i + b_loop_ub * b_proc_tx_mode->size[1]] =
        proc_tx_mode_data[i];
    }

    b_loop_ub = b_proc_rx_mode->size[0] + b_proc_rx_mode->size[0];
    c_loop_ub = b_loop_ub + b_proc_rx_mode->size[0];
    loop_ub = proc_rx_mode->size[0];
    proc_rx_mode->size[0] = (c_loop_ub + b_proc_rx_mode->size[0]) *
      b_proc_rx_mode->size[1];
    emxEnsureCapacity_real_T(sp, proc_rx_mode, loop_ub, &wb_emlrtRTEI);
    b_proc_rx_mode_data = proc_rx_mode->data;
    for (i = 0; i < e_loop_ub; i++) {
      b_proc_rx_mode_data[i] = proc_rx_mode_data[i];
    }

    for (i = 0; i < e_loop_ub; i++) {
      b_proc_rx_mode_data[i + e_loop_ub] = proc_rx_mode_data[i];
    }

    for (i = 0; i < e_loop_ub; i++) {
      b_proc_rx_mode_data[i + b_loop_ub * b_proc_rx_mode->size[1]] =
        proc_rx_mode_data[i];
    }

    for (i = 0; i < e_loop_ub; i++) {
      b_proc_rx_mode_data[i + c_loop_ub * b_proc_rx_mode->size[1]] =
        proc_rx_mode_data[i];
    }
  } else {
    loop_ub = proc_tx_mode->size[0];
    proc_tx_mode->size[0] = d_loop_ub;
    emxEnsureCapacity_real_T(sp, proc_tx_mode, loop_ub, &ob_emlrtRTEI);
    b_proc_tx_mode_data = proc_tx_mode->data;
    for (i = 0; i < e_loop_ub; i++) {
      b_proc_tx_mode_data[i] = proc_tx_mode_data[i];
    }

    for (i = 0; i < e_loop_ub; i++) {
      b_proc_tx_mode_data[i + e_loop_ub] = proc_tx_mode_data[i];
    }

    b_loop_ub = proc_rx_mode->size[0];
    proc_rx_mode->size[0] = (b_proc_rx_mode->size[0] + b_proc_rx_mode->size[0]) *
      b_proc_rx_mode->size[1];
    emxEnsureCapacity_real_T(sp, proc_rx_mode, b_loop_ub, &qb_emlrtRTEI);
    b_proc_rx_mode_data = proc_rx_mode->data;
    for (i = 0; i < e_loop_ub; i++) {
      b_proc_rx_mode_data[i] = proc_rx_mode_data[i];
    }

    for (i = 0; i < e_loop_ub; i++) {
      b_proc_rx_mode_data[i + e_loop_ub] = proc_rx_mode_data[i];
    }
  }

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
    b_loop_ub = opts_ms_matrix_calc_freqs->size[0] *
      opts_ms_matrix_calc_freqs->size[1];
    opts_ms_matrix_calc_freqs->size[0] = 1;
    opts_ms_matrix_calc_freqs->size[1] = 1;
    emxEnsureCapacity_real_T(sp, opts_ms_matrix_calc_freqs, b_loop_ub,
      &vb_emlrtRTEI);
    opts_ms_matrix_calc_freqs_data = opts_ms_matrix_calc_freqs->data;
    opts_ms_matrix_calc_freqs_data[0] = opts_freq_filter;
  }

  /* zero out dead time if required */
  emxInit_int32_T(sp, &b_ii, 1, &vd_emlrtRTEI);
  if (opts_raw_data_zero_dead_time > 0.0) {
    st.site = &d_emlrtRSI;

    /* -------------------------------------------------------------------------- */
    c_loop_ub = raw_time->size[0];
    loop_ub = 0;
    for (i = 0; i < c_loop_ub; i++) {
      if (b_raw_time_data[i] <= opts_raw_data_zero_dead_time) {
        loop_ub++;
      }
    }

    b_loop_ub = b_ii->size[0];
    b_ii->size[0] = loop_ub;
    emxEnsureCapacity_int32_T(&st, b_ii, b_loop_ub, &tb_emlrtRTEI);
    ii_data = b_ii->data;
    b_loop_ub = 0;
    for (i = 0; i < c_loop_ub; i++) {
      if (b_raw_time_data[i] <= opts_raw_data_zero_dead_time) {
        ii_data[b_loop_ub] = i;
        b_loop_ub++;
      }
    }

    loop_ub = raw_time_data->size[1];
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = b_ii->size[0];
      for (ii = 0; ii < b_loop_ub; ii++) {
        if (ii_data[ii] > raw_time_data->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(ii_data[ii], 0, raw_time_data->size[0] -
            1, &r_emlrtBCI, &st);
        }

        raw_time_data_data[ii_data[ii] + raw_time_data->size[0] * i] = 0.0;
      }
    }
  }

  /* removal of p/e columns if required */
  if (opts_raw_data_ignore_pulse_echo == 1.0) {
    st.site = &e_emlrtRSI;
    loop_ub = raw_tx->size[0];
    if ((raw_tx->size[0] != raw_rx->size[0]) && ((raw_tx->size[0] != 1) &&
         (raw_rx->size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(raw_tx->size[0], raw_rx->size[0], &emlrtECI,
        &st);
    }

    b_st.site = &r_emlrtRSI;
    if (raw_tx->size[0] == raw_rx->size[0]) {
      emxInit_boolean_T(&b_st, &b_raw_tx, 1, &xb_emlrtRTEI);
      b_loop_ub = b_raw_tx->size[0];
      b_raw_tx->size[0] = raw_tx->size[0];
      emxEnsureCapacity_boolean_T(&b_st, b_raw_tx, b_loop_ub, &xb_emlrtRTEI);
      b_raw_tx_data = b_raw_tx->data;
      c_loop_ub = raw_tx->size[0];
      if (raw_tx->size[0] < 2000) {
        for (b_i = 0; b_i < loop_ub; b_i++) {
          b_raw_tx_data[b_i] = (raw_tx_data[b_i] != raw_rx_data[b_i]);
        }
      } else {
        emlrtEnterParallelRegion(&b_st, omp_in_parallel());
        emlrtPushJmpBuf(&b_st, &emlrtJBStack);
        fn_process_rail_data_DLL_numThreads = emlrtAllocRegionTLSs(b_st.tls,
          omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());

#pragma omp parallel for \
 num_threads(fn_process_rail_data_DLL_numThreads)

        for (b_i = 0; b_i < c_loop_ub; b_i++) {
          b_raw_tx_data[b_i] = (raw_tx_data[b_i] != raw_rx_data[b_i]);
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
      binary_expand_op_2(&c_st, b_ii, s_emlrtRSI, raw_tx, raw_rx);
      ii_data = b_ii->data;
    }

    c_loop_ub = b_ii->size[0];
    b_loop_ub = pitch_catch_indices->size[0];
    pitch_catch_indices->size[0] = b_ii->size[0];
    emxEnsureCapacity_real_T(&b_st, pitch_catch_indices, b_loop_ub,
      &yb_emlrtRTEI);
    pitch_catch_indices_data = pitch_catch_indices->data;
    for (i = 0; i < c_loop_ub; i++) {
      pitch_catch_indices_data[i] = ii_data[i];
    }

    emxInit_int64_T(&st, &c_raw_tx, 1, &ac_emlrtRTEI);
    b_loop_ub = c_raw_tx->size[0];
    c_raw_tx->size[0] = b_ii->size[0];
    emxEnsureCapacity_int64_T(&st, c_raw_tx, b_loop_ub, &ac_emlrtRTEI);
    c_raw_tx_data = c_raw_tx->data;
    for (i = 0; i < c_loop_ub; i++) {
      loop_ub = (int32_T)pitch_catch_indices_data[i];
      if ((loop_ub < 1) || (loop_ub > raw_tx->size[0])) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 1, raw_tx->size[0], &s_emlrtBCI,
          &st);
      }

      c_raw_tx_data[i] = raw_tx_data[loop_ub - 1];
    }

    b_loop_ub = c_raw_tx->size[0];
    loop_ub = raw_tx->size[0];
    raw_tx->size[0] = c_raw_tx->size[0];
    emxEnsureCapacity_int64_T(&st, raw_tx, loop_ub, &bc_emlrtRTEI);
    raw_tx_data = raw_tx->data;
    for (i = 0; i < b_loop_ub; i++) {
      raw_tx_data[i] = c_raw_tx_data[i];
    }

    b_loop_ub = c_raw_tx->size[0];
    c_raw_tx->size[0] = b_ii->size[0];
    emxEnsureCapacity_int64_T(&st, c_raw_tx, b_loop_ub, &cc_emlrtRTEI);
    c_raw_tx_data = c_raw_tx->data;
    for (i = 0; i < c_loop_ub; i++) {
      loop_ub = (int32_T)pitch_catch_indices_data[i];
      if ((loop_ub < 1) || (loop_ub > raw_rx->size[0])) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 1, raw_rx->size[0], &t_emlrtBCI,
          &st);
      }

      c_raw_tx_data[i] = raw_rx_data[loop_ub - 1];
    }

    b_loop_ub = c_raw_tx->size[0];
    loop_ub = raw_rx->size[0];
    raw_rx->size[0] = c_raw_tx->size[0];
    emxEnsureCapacity_int64_T(&st, raw_rx, loop_ub, &ec_emlrtRTEI);
    raw_rx_data = raw_rx->data;
    for (i = 0; i < b_loop_ub; i++) {
      raw_rx_data[i] = c_raw_tx_data[i];
    }

    emxFree_int64_T(&st, &c_raw_tx);
    b_loop_ub = raw_time_data->size[0];
    loop_ub = b_proc_tx_mode->size[0] * b_proc_tx_mode->size[1];
    b_proc_tx_mode->size[0] = raw_time_data->size[0];
    b_proc_tx_mode->size[1] = b_ii->size[0];
    emxEnsureCapacity_real_T(&st, b_proc_tx_mode, loop_ub, &gc_emlrtRTEI);
    proc_tx_mode_data = b_proc_tx_mode->data;
    for (i = 0; i < c_loop_ub; i++) {
      for (ii = 0; ii < b_loop_ub; ii++) {
        loop_ub = (int32_T)pitch_catch_indices_data[i];
        if ((loop_ub < 1) || (loop_ub > raw_time_data->size[1])) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, raw_time_data->size[1],
            &u_emlrtBCI, &st);
        }

        proc_tx_mode_data[ii + b_proc_tx_mode->size[0] * i] =
          raw_time_data_data[ii + raw_time_data->size[0] * (loop_ub - 1)];
      }
    }

    b_loop_ub = raw_time_data->size[0] * raw_time_data->size[1];
    raw_time_data->size[0] = b_proc_tx_mode->size[0];
    raw_time_data->size[1] = b_proc_tx_mode->size[1];
    emxEnsureCapacity_real_T(&st, raw_time_data, b_loop_ub, &hc_emlrtRTEI);
    raw_time_data_data = raw_time_data->data;
    b_loop_ub = b_proc_tx_mode->size[0] * b_proc_tx_mode->size[1];
    for (i = 0; i < b_loop_ub; i++) {
      raw_time_data_data[i] = proc_tx_mode_data[i];
    }
  }

  /* convert to frequency domain */
  st.site = &f_emlrtRSI;
  f = frexp(raw_time_data->size[0], &eint);
  if (f == 0.5) {
    eint--;
  }

  b_st.site = &ab_emlrtRSI;
  c_st.site = &bb_emlrtRSI;
  d_st.site = &cb_emlrtRSI;
  fft_pts = muDoubleScalarPower(2.0, eint);
  emxInit_creal_T(&st, &inv_full_mode_shapes, 2, &nc_emlrtRTEI);
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

  loop_ub = (int32_T)(f + 1.0);
  d_loop_ub = (int32_T)(f + 1.0);
  if ((int32_T)(f + 1.0) > inv_full_mode_shapes->size[0]) {
    emlrtDynamicBoundsCheckR2012b((int32_T)(f + 1.0), 1,
      inv_full_mode_shapes->size[0], &d_emlrtBCI, &st);
  }

  e_loop_ub = inv_full_mode_shapes->size[1];
  for (i = 0; i < e_loop_ub; i++) {
    for (ii = 0; ii < loop_ub; ii++) {
      inv_full_mode_shapes_data[ii + (int32_T)(f + 1.0) * i] =
        inv_full_mode_shapes_data[ii + inv_full_mode_shapes->size[0] * i];
    }
  }

  loop_ub = inv_full_mode_shapes->size[0] * inv_full_mode_shapes->size[1];
  inv_full_mode_shapes->size[0] = (int32_T)(f + 1.0);
  emxEnsureCapacity_creal_T(&st, inv_full_mode_shapes, loop_ub, &dc_emlrtRTEI);
  inv_full_mode_shapes_data = inv_full_mode_shapes->data;
  if (raw_time->size[0] < 1) {
    emlrtDynamicBoundsCheckR2012b(1, 1, raw_time->size[0], &c_emlrtBCI, &st);
  }

  if (raw_time->size[0] < 2) {
    emlrtDynamicBoundsCheckR2012b(2, 1, raw_time->size[0], &b_emlrtBCI, &st);
  }

  y = 1.0 / (fft_pts * muDoubleScalarAbs(b_raw_time_data[0] - b_raw_time_data[1]));
  emxInit_real_T(&st, &freq, 1, &tb_emlrtRTEI);
  loop_ub = freq->size[0];
  freq->size[0] = (int32_T)f + 1;
  emxEnsureCapacity_real_T(&st, freq, loop_ub, &fc_emlrtRTEI);
  proc_rx_dir_data = freq->data;
  loop_ub = (int32_T)f;
  b_loop_ub = (((int32_T)f + 1) / 2) << 1;
  c_loop_ub = b_loop_ub - 2;
  for (i = 0; i <= c_loop_ub; i += 2) {
    dv[0] = i;
    dv[1] = i + 1;
    r = _mm_loadu_pd(&dv[0]);
    _mm_storeu_pd(&proc_rx_dir_data[i], _mm_mul_pd(r, _mm_set1_pd(y)));
  }

  for (i = b_loop_ub; i <= loop_ub; i++) {
    proc_rx_dir_data[i] = (real_T)i * y;
  }

  if (raw_time->size[0] < 1) {
    emlrtDynamicBoundsCheckR2012b(1, 1, raw_time->size[0], &emlrtBCI, &st);
  }

  f = b_raw_time_data[0];
  emxInit_creal_T(&st, &r1, 1, &jc_emlrtRTEI);
  f_loop_ub = freq->size[0];
  loop_ub = r1->size[0];
  r1->size[0] = freq->size[0];
  emxEnsureCapacity_creal_T(&st, r1, loop_ub, &ic_emlrtRTEI);
  yi_data = r1->data;
  loop_ub = freq->size[0];
  if (freq->size[0] < 2000) {
    for (i1 = 0; i1 < f_loop_ub; i1++) {
      yi_data[i1].re = f * (proc_rx_dir_data[i1] * -0.0);
      yi_data[i1].im = f * (proc_rx_dir_data[i1] * -6.2831853071795862);
    }
  } else {
    emlrtEnterParallelRegion(&st, omp_in_parallel());
    emlrtPushJmpBuf(&st, &emlrtJBStack);
    fn_process_rail_data_DLL_numThreads = emlrtAllocRegionTLSs(st.tls,
      omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());

#pragma omp parallel for \
 num_threads(fn_process_rail_data_DLL_numThreads)

    for (i1 = 0; i1 < loop_ub; i1++) {
      yi_data[i1].re = f * (proc_rx_dir_data[i1] * -0.0);
      yi_data[i1].im = f * (proc_rx_dir_data[i1] * -6.2831853071795862);
    }

    emlrtPopJmpBuf(&st, &emlrtJBStack);
    emlrtExitParallelRegion(&st, omp_in_parallel());
  }

  b_st.site = &x_emlrtRSI;
  b_exp(&b_st, r1);
  yi_data = r1->data;
  if ((d_loop_ub != r1->size[0]) && ((d_loop_ub != 1) && (r1->size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(d_loop_ub, r1->size[0], &b_emlrtECI, &st);
  }

  emxInit_creal_T(&st, &b_inv_full_mode_shapes, 2, &jc_emlrtRTEI);
  if (inv_full_mode_shapes->size[0] == r1->size[0]) {
    loop_ub = b_inv_full_mode_shapes->size[0] * b_inv_full_mode_shapes->size[1];
    b_inv_full_mode_shapes->size[0] = d_loop_ub;
    b_inv_full_mode_shapes->size[1] = e_loop_ub;
    emxEnsureCapacity_creal_T(&st, b_inv_full_mode_shapes, loop_ub,
      &jc_emlrtRTEI);
    b_inv_full_mode_shapes_data = b_inv_full_mode_shapes->data;
    for (i = 0; i < e_loop_ub; i++) {
      for (ii = 0; ii < d_loop_ub; ii++) {
        f = inv_full_mode_shapes_data[ii + inv_full_mode_shapes->size[0] * i].re;
        y = yi_data[ii].im;
        y_re = inv_full_mode_shapes_data[ii + inv_full_mode_shapes->size[0] * i]
          .im;
        freq_i1 = yi_data[ii].re;
        b_inv_full_mode_shapes_data[ii + b_inv_full_mode_shapes->size[0] * i].re
          = f * freq_i1 - y_re * y;
        b_inv_full_mode_shapes_data[ii + b_inv_full_mode_shapes->size[0] * i].im
          = f * y + y_re * freq_i1;
      }
    }

    loop_ub = inv_full_mode_shapes->size[0] * inv_full_mode_shapes->size[1];
    inv_full_mode_shapes->size[0] = d_loop_ub;
    inv_full_mode_shapes->size[1] = e_loop_ub;
    emxEnsureCapacity_creal_T(&st, inv_full_mode_shapes, loop_ub, &kc_emlrtRTEI);
    inv_full_mode_shapes_data = inv_full_mode_shapes->data;
    loop_ub = b_inv_full_mode_shapes->size[0] * b_inv_full_mode_shapes->size[1];
    for (i = 0; i < loop_ub; i++) {
      inv_full_mode_shapes_data[i] = b_inv_full_mode_shapes_data[i];
    }
  } else {
    b_st.site = &x_emlrtRSI;
    binary_expand_op_1(&b_st, inv_full_mode_shapes, r1);
    inv_full_mode_shapes_data = inv_full_mode_shapes->data;
  }

  /*  %coupling compensation if required */
  /*  if options.raw_data_coupling_comp ~= 0 */
  /*      raw_data = fn_coupling_comp(raw_data, array, options); */
  /*  end */
  /* frequency domain processing */
  emxInit_creal_T(sp, &raw_freq_data, 2, &vc_emlrtRTEI);
  b_loop_ub = raw_freq_data->size[0] * raw_freq_data->size[1];
  raw_freq_data->size[0] = inv_full_mode_shapes->size[0];
  raw_freq_data->size[1] = inv_full_mode_shapes->size[1];
  emxEnsureCapacity_creal_T(sp, raw_freq_data, b_loop_ub, &lc_emlrtRTEI);
  raw_freq_data_data = raw_freq_data->data;
  b_loop_ub = inv_full_mode_shapes->size[0] * inv_full_mode_shapes->size[1];
  for (i = 0; i < b_loop_ub; i++) {
    raw_freq_data_data[i] = inv_full_mode_shapes_data[i];
  }

  st.site = &g_emlrtRSI;
  freq_i1 = fn_filter_freq_domain_data(&st, freq, raw_freq_data,
    opts_freq_filter_on, opts_freq_filter, opts_freq_filter_bandwidth, &f);
  raw_freq_data_data = raw_freq_data->data;

  /* build inverse mode shape matrix at frequency(s) required  */
  emxInit_creal_T(sp, &inv_mode_shapes, 3, &sd_emlrtRTEI);
  st.site = &h_emlrtRSI;
  fn_inv_mode_shape_matrices(&st, raw_tx, raw_rx, raw_freq_data, array_row_pos,
    array_trans_pos, array_trans_row, array_trans_pos_orientations,
    array_trans_node_list, disperse_freq, disperse_waveno, disperse_ms_x,
    disperse_ms_y, disperse_ms_z, proc_tx_mode, proc_rx_mode, proc_tx_dir,
    proc_rx_dir, opts_ms_matrix_calc_freqs, opts_ms_matrix_modes_to_use,
    inv_mode_shapes);
  inv_mode_shapes_data = inv_mode_shapes->data;

  /*  %array */
  /* do the mode extraction */
  st.site = &i_emlrtRSI;

  /* actually do the multiplication to convert the raw freq domain data */
  /* to mode extracted freq domain data by one of two methods (single frequency mode shapes or interpolated frequency) */
  emxInit_creal_T(&st, &proc_freq_data, 2, &mc_emlrtRTEI);
  i2 = raw_freq_data->size[0];
  loop_ub = proc_freq_data->size[0] * proc_freq_data->size[1];
  proc_freq_data->size[0] = raw_freq_data->size[0];
  g_loop_ub = inv_mode_shapes->size[0];
  proc_freq_data->size[1] = inv_mode_shapes->size[0];
  emxEnsureCapacity_creal_T(&st, proc_freq_data, loop_ub, &mc_emlrtRTEI);
  proc_freq_data_data = proc_freq_data->data;
  loop_ub = raw_freq_data->size[0] * inv_mode_shapes->size[0];
  for (i = 0; i < loop_ub; i++) {
    proc_freq_data_data[i].re = 0.0;
    proc_freq_data_data[i].im = 0.0;
  }

  /*  if length(size(inv_mode_shapes)) < 3 */
  emxInit_creal_T(&st, &yi, 2, &wd_emlrtRTEI);
  emxInit_real_T(&st, &b_y, 2, &sc_emlrtRTEI);
  emxInit_creal_T(&st, &b_raw_freq_data, 2, &tc_emlrtRTEI);
  if (opts_ms_matrix_calc_freqs->size[1] == 1) {
    if (inv_mode_shapes->size[2] < 1) {
      emlrtDynamicBoundsCheckR2012b(1, 1, inv_mode_shapes->size[2], &f_emlrtBCI,
        &st);
    }

    loop_ub = inv_full_mode_shapes->size[0] * inv_full_mode_shapes->size[1];
    inv_full_mode_shapes->size[0] = inv_mode_shapes->size[0];
    b_loop_ub = inv_mode_shapes->size[1];
    inv_full_mode_shapes->size[1] = inv_mode_shapes->size[1];
    emxEnsureCapacity_creal_T(&st, inv_full_mode_shapes, loop_ub, &nc_emlrtRTEI);
    inv_full_mode_shapes_data = inv_full_mode_shapes->data;
    for (i = 0; i < b_loop_ub; i++) {
      for (ii = 0; ii < g_loop_ub; ii++) {
        inv_full_mode_shapes_data[ii + inv_full_mode_shapes->size[0] * i] =
          inv_mode_shapes_data[ii + inv_mode_shapes->size[0] * i];
      }
    }

    b_st.site = &bg_emlrtRSI;
    b_squeeze(&b_st, inv_full_mode_shapes);
    b_st.site = &cg_emlrtRSI;
    if (muDoubleScalarIsNaN(c_opts_ms_matrix_apply_as_time_)) {
      emlrtErrorWithMessageIdR2018a(&b_st, &b_emlrtRTEI, "MATLAB:nologicalnan",
        "MATLAB:nologicalnan", 0);
    }

    if (!(c_opts_ms_matrix_apply_as_time_ != 0.0)) {
      /* normal frequency domain processing */
      if (freq_i1 > f) {
        c_loop_ub = 0;
        d_loop_ub = 0;
        eint = 0;
        e_loop_ub = 0;
      } else {
        b = (((int32_T)freq_i1 < 1) || ((int32_T)freq_i1 > raw_freq_data->size[0]));
        if (b) {
          emlrtDynamicBoundsCheckR2012b((int32_T)freq_i1, 1, raw_freq_data->
            size[0], &g_emlrtBCI, &st);
        }

        c_loop_ub = (int32_T)freq_i1 - 1;
        b = (((int32_T)f < 1) || ((int32_T)f > raw_freq_data->size[0]));
        if (b) {
          emlrtDynamicBoundsCheckR2012b((int32_T)f, 1, raw_freq_data->size[0],
            &h_emlrtBCI, &st);
        }

        d_loop_ub = (int32_T)f;
        eint = (int32_T)freq_i1 - 1;
        e_loop_ub = (int32_T)f;
      }

      b_st.site = &dg_emlrtRSI;
      c_st.site = &ug_emlrtRSI;
      if (raw_freq_data->size[1] != inv_full_mode_shapes->size[1]) {
        if (((d_loop_ub - c_loop_ub == 1) && (raw_freq_data->size[1] == 1)) ||
            ((inv_full_mode_shapes->size[0] == 1) && (inv_full_mode_shapes->
              size[1] == 1))) {
          emlrtErrorWithMessageIdR2018a(&c_st, &d_emlrtRTEI,
            "Coder:toolbox:mtimes_noDynamicScalarExpansion",
            "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
        } else {
          emlrtErrorWithMessageIdR2018a(&c_st, &c_emlrtRTEI, "MATLAB:innerdim",
            "MATLAB:innerdim", 0);
        }
      }

      loop_ub = raw_freq_data->size[1];
      for (i = 0; i < loop_ub; i++) {
        b_loop_ub = d_loop_ub - c_loop_ub;
        for (ii = 0; ii < b_loop_ub; ii++) {
          raw_freq_data_data[ii + b_loop_ub * i] = raw_freq_data_data[(c_loop_ub
            + ii) + raw_freq_data->size[0] * i];
        }
      }

      loop_ub = raw_freq_data->size[0] * raw_freq_data->size[1];
      raw_freq_data->size[0] = d_loop_ub - c_loop_ub;
      emxEnsureCapacity_creal_T(&b_st, raw_freq_data, loop_ub, &vc_emlrtRTEI);
      emxInit_creal_T(&b_st, &yy, 2, &xd_emlrtRTEI);
      c_st.site = &m_emlrtRSI;
      b_mtimes(&c_st, raw_freq_data, inv_full_mode_shapes, yy);
      yi_data = yy->data;
      loop_ub = e_loop_ub - eint;
      iv[0] = loop_ub;
      iv[1] = inv_mode_shapes->size[0];
      emlrtSubAssignSizeCheckR2012b(&iv[0], 2, &yy->size[0], 2, &e_emlrtECI, &st);
      for (i = 0; i < g_loop_ub; i++) {
        for (ii = 0; ii < loop_ub; ii++) {
          proc_freq_data_data[(eint + ii) + proc_freq_data->size[0] * i] =
            yi_data[ii + loop_ub * i];
        }
      }

      emxFree_creal_T(&st, &yy);
    } else {
      /* simulated time domain processing */
      b_st.site = &eg_emlrtRSI;
      angle(&b_st, inv_full_mode_shapes, b_proc_tx_mode);
      proc_tx_mode_data = b_proc_tx_mode->data;
      b_st.site = &fg_emlrtRSI;
      c_abs(&b_st, inv_full_mode_shapes, b_proc_rx_mode);
      proc_rx_mode_data = b_proc_rx_mode->data;
      b_st.site = &gg_emlrtRSI;
      if (muDoubleScalarIsNaN(opts_ms_matrix_allow_neg_amps)) {
        emlrtErrorWithMessageIdR2018a(&b_st, &b_emlrtRTEI, "MATLAB:nologicalnan",
          "MATLAB:nologicalnan", 0);
      }

      if (opts_ms_matrix_allow_neg_amps != 0.0) {
        b_st.site = &hg_emlrtRSI;
        emxInit_boolean_T(&b_st, &c_proc_tx_mode, 2, &uc_emlrtRTEI);
        eint = b_proc_tx_mode->size[0];
        loop_ub = c_proc_tx_mode->size[0] * c_proc_tx_mode->size[1];
        c_proc_tx_mode->size[0] = b_proc_tx_mode->size[0];
        i3 = b_proc_tx_mode->size[1];
        c_proc_tx_mode->size[1] = b_proc_tx_mode->size[1];
        emxEnsureCapacity_boolean_T(&b_st, c_proc_tx_mode, loop_ub,
          &uc_emlrtRTEI);
        b_raw_tx_data = c_proc_tx_mode->data;
        h_loop_ub = b_proc_tx_mode->size[0] * b_proc_tx_mode->size[1];
        e_loop_ub = (h_loop_ub < 2000);
        if (e_loop_ub) {
          for (i4 = 0; i4 < h_loop_ub; i4++) {
            b_raw_tx_data[i4] = (proc_tx_mode_data[i4] > 1.5707963267948966);
          }
        } else {
          emlrtEnterParallelRegion(&b_st, omp_in_parallel());
          emlrtPushJmpBuf(&b_st, &emlrtJBStack);
          fn_process_rail_data_DLL_numThreads = emlrtAllocRegionTLSs(b_st.tls,
            omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());

#pragma omp parallel for \
 num_threads(fn_process_rail_data_DLL_numThreads)

          for (i4 = 0; i4 < h_loop_ub; i4++) {
            b_raw_tx_data[i4] = (proc_tx_mode_data[i4] > 1.5707963267948966);
          }

          emlrtPopJmpBuf(&b_st, &emlrtJBStack);
          emlrtExitParallelRegion(&b_st, omp_in_parallel());
        }

        c_st.site = &s_emlrtRSI;
        c_eml_find(&c_st, c_proc_tx_mode, b_ii);
        ii_data = b_ii->data;
        d_loop_ub = b_ii->size[0];
        loop_ub = pitch_catch_indices->size[0];
        pitch_catch_indices->size[0] = b_ii->size[0];
        emxEnsureCapacity_real_T(&b_st, pitch_catch_indices, loop_ub,
          &wc_emlrtRTEI);
        pitch_catch_indices_data = pitch_catch_indices->data;
        for (i = 0; i < d_loop_ub; i++) {
          pitch_catch_indices_data[i] = ii_data[i];
        }

        b_st.site = &ig_emlrtRSI;
        b_indexShapeCheck(&b_st, b_proc_tx_mode->size, pitch_catch_indices->
                          size[0]);
        loop_ub = b_ii->size[0];
        b_ii->size[0] = d_loop_ub;
        emxEnsureCapacity_int32_T(&st, b_ii, loop_ub, &xc_emlrtRTEI);
        ii_data = b_ii->data;
        b_loop_ub = (pitch_catch_indices->size[0] < 2000);
        if (b_loop_ub) {
          for (i5 = 0; i5 < d_loop_ub; i5++) {
            loop_ub = (int32_T)pitch_catch_indices_data[i5];
            if ((loop_ub < 1) || (loop_ub > h_loop_ub)) {
              emlrtDynamicBoundsCheckR2012b(loop_ub, 1, h_loop_ub, &x_emlrtBCI,
                &st);
            }

            ii_data[i5] = loop_ub;
          }
        } else {
          emlrtEnterParallelRegion(&st, omp_in_parallel());
          emlrtPushJmpBuf(&st, &emlrtJBStack);
          fn_process_rail_data_DLL_numThreads = emlrtAllocRegionTLSs(st.tls,
            omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());

#pragma omp parallel \
 num_threads(fn_process_rail_data_DLL_numThreads) \
 private(e_st,emlrtJBEnviron,i6) \
 firstprivate(st,emlrtHadParallelError)

          {
            if (setjmp(emlrtJBEnviron) == 0) {
              e_st.prev = &st;
              e_st.tls = emlrtAllocTLS(&st, omp_get_thread_num());
              e_st.site = NULL;
              emlrtSetJmpBuf(&e_st, &emlrtJBEnviron);
            } else {
              emlrtHadParallelError = true;
            }

#pragma omp for nowait

            for (i5 = 0; i5 < d_loop_ub; i5++) {
              if (emlrtHadParallelError) {
                continue;
              }

              if (setjmp(emlrtJBEnviron) == 0) {
                i6 = (int32_T)pitch_catch_indices_data[i5];
                if ((i6 < 1) || (i6 > h_loop_ub)) {
                  emlrtDynamicBoundsCheckR2012b(i6, 1, h_loop_ub, &x_emlrtBCI,
                    &e_st);
                }

                ii_data[i5] = i6;
              } else {
                emlrtHadParallelError = true;
              }
            }
          }

          emlrtPopJmpBuf(&st, &emlrtJBStack);
          emlrtExitParallelRegion(&st, omp_in_parallel());
        }

        c_loop_ub = b_ii->size[0];
        emxInit_real_T(&st, &d_proc_tx_mode, 1, &ad_emlrtRTEI);
        loop_ub = d_proc_tx_mode->size[0];
        d_proc_tx_mode->size[0] = b_ii->size[0];
        emxEnsureCapacity_real_T(&st, d_proc_tx_mode, loop_ub, &ad_emlrtRTEI);
        proc_tx_dir_data = d_proc_tx_mode->data;
        loop_ub = b_ii->size[0];
        if (b_ii->size[0] < 2000) {
          for (i7 = 0; i7 < c_loop_ub; i7++) {
            proc_tx_dir_data[i7] = proc_tx_mode_data[ii_data[i7] - 1] -
              3.1415926535897931;
          }
        } else {
          emlrtEnterParallelRegion(&st, omp_in_parallel());
          emlrtPushJmpBuf(&st, &emlrtJBStack);
          fn_process_rail_data_DLL_numThreads = emlrtAllocRegionTLSs(st.tls,
            omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());

#pragma omp parallel for \
 num_threads(fn_process_rail_data_DLL_numThreads)

          for (i7 = 0; i7 < loop_ub; i7++) {
            proc_tx_dir_data[i7] = proc_tx_mode_data[ii_data[i7] - 1] -
              3.1415926535897931;
          }

          emlrtPopJmpBuf(&st, &emlrtJBStack);
          emlrtExitParallelRegion(&st, omp_in_parallel());
        }

        for (i = 0; i < c_loop_ub; i++) {
          proc_tx_mode_data[ii_data[i] - 1] = proc_tx_dir_data[i];
        }

        b_st.site = &jg_emlrtRSI;
        b_indexShapeCheck(&b_st, b_proc_rx_mode->size, pitch_catch_indices->
                          size[0]);
        c_proc_rx_mode = b_proc_rx_mode->size[0] * b_proc_rx_mode->size[1];
        loop_ub = b_ii->size[0];
        b_ii->size[0] = d_loop_ub;
        emxEnsureCapacity_int32_T(&st, b_ii, loop_ub, &dd_emlrtRTEI);
        ii_data = b_ii->data;
        if (b_loop_ub) {
          for (i8 = 0; i8 < d_loop_ub; i8++) {
            loop_ub = (int32_T)pitch_catch_indices_data[i8];
            if ((loop_ub < 1) || (loop_ub > c_proc_rx_mode)) {
              emlrtDynamicBoundsCheckR2012b(loop_ub, 1, c_proc_rx_mode,
                &y_emlrtBCI, &st);
            }

            ii_data[i8] = loop_ub;
          }
        } else {
          emlrtEnterParallelRegion(&st, omp_in_parallel());
          emlrtPushJmpBuf(&st, &emlrtJBStack);
          fn_process_rail_data_DLL_numThreads = emlrtAllocRegionTLSs(st.tls,
            omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());

#pragma omp parallel \
 num_threads(fn_process_rail_data_DLL_numThreads) \
 private(emlrtJBEnviron,f_st,i9) \
 firstprivate(emlrtHadParallelError,st)

          {
            if (setjmp(emlrtJBEnviron) == 0) {
              f_st.prev = &st;
              f_st.tls = emlrtAllocTLS(&st, omp_get_thread_num());
              f_st.site = NULL;
              emlrtSetJmpBuf(&f_st, &emlrtJBEnviron);
            } else {
              emlrtHadParallelError = true;
            }

#pragma omp for nowait

            for (i8 = 0; i8 < d_loop_ub; i8++) {
              if (emlrtHadParallelError) {
                continue;
              }

              if (setjmp(emlrtJBEnviron) == 0) {
                i9 = (int32_T)pitch_catch_indices_data[i8];
                if ((i9 < 1) || (i9 > c_proc_rx_mode)) {
                  emlrtDynamicBoundsCheckR2012b(i9, 1, c_proc_rx_mode,
                    &y_emlrtBCI, &f_st);
                }

                ii_data[i8] = i9;
              } else {
                emlrtHadParallelError = true;
              }
            }
          }

          emlrtPopJmpBuf(&st, &emlrtJBStack);
          emlrtExitParallelRegion(&st, omp_in_parallel());
        }

        c_loop_ub = b_ii->size[0];
        loop_ub = pitch_catch_indices->size[0];
        pitch_catch_indices->size[0] = b_ii->size[0];
        emxEnsureCapacity_real_T(&st, pitch_catch_indices, loop_ub,
          &gd_emlrtRTEI);
        pitch_catch_indices_data = pitch_catch_indices->data;
        loop_ub = b_ii->size[0];
        if (b_ii->size[0] < 2000) {
          for (i10 = 0; i10 < c_loop_ub; i10++) {
            pitch_catch_indices_data[i10] = -proc_rx_mode_data[ii_data[i10] - 1];
          }
        } else {
          emlrtEnterParallelRegion(&st, omp_in_parallel());
          emlrtPushJmpBuf(&st, &emlrtJBStack);
          fn_process_rail_data_DLL_numThreads = emlrtAllocRegionTLSs(st.tls,
            omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());

#pragma omp parallel for \
 num_threads(fn_process_rail_data_DLL_numThreads)

          for (i10 = 0; i10 < loop_ub; i10++) {
            pitch_catch_indices_data[i10] = -proc_rx_mode_data[ii_data[i10] - 1];
          }

          emlrtPopJmpBuf(&st, &emlrtJBStack);
          emlrtExitParallelRegion(&st, omp_in_parallel());
        }

        for (i = 0; i < c_loop_ub; i++) {
          proc_rx_mode_data[ii_data[i] - 1] = pitch_catch_indices_data[i];
        }

        b_st.site = &kg_emlrtRSI;
        loop_ub = c_proc_tx_mode->size[0] * c_proc_tx_mode->size[1];
        c_proc_tx_mode->size[0] = eint;
        c_proc_tx_mode->size[1] = i3;
        emxEnsureCapacity_boolean_T(&b_st, c_proc_tx_mode, loop_ub,
          &id_emlrtRTEI);
        b_raw_tx_data = c_proc_tx_mode->data;
        if (e_loop_ub) {
          for (i13 = 0; i13 < h_loop_ub; i13++) {
            b_raw_tx_data[i13] = (proc_tx_mode_data[i13] < -1.5707963267948966);
          }
        } else {
          emlrtEnterParallelRegion(&b_st, omp_in_parallel());
          emlrtPushJmpBuf(&b_st, &emlrtJBStack);
          fn_process_rail_data_DLL_numThreads = emlrtAllocRegionTLSs(b_st.tls,
            omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());

#pragma omp parallel for \
 num_threads(fn_process_rail_data_DLL_numThreads)

          for (i13 = 0; i13 < h_loop_ub; i13++) {
            b_raw_tx_data[i13] = (proc_tx_mode_data[i13] < -1.5707963267948966);
          }

          emlrtPopJmpBuf(&b_st, &emlrtJBStack);
          emlrtExitParallelRegion(&b_st, omp_in_parallel());
        }

        c_st.site = &s_emlrtRSI;
        c_eml_find(&c_st, c_proc_tx_mode, b_ii);
        ii_data = b_ii->data;
        emxFree_boolean_T(&b_st, &c_proc_tx_mode);
        eint = b_ii->size[0];
        loop_ub = pitch_catch_indices->size[0];
        pitch_catch_indices->size[0] = b_ii->size[0];
        emxEnsureCapacity_real_T(&b_st, pitch_catch_indices, loop_ub,
          &kd_emlrtRTEI);
        pitch_catch_indices_data = pitch_catch_indices->data;
        for (i = 0; i < eint; i++) {
          pitch_catch_indices_data[i] = ii_data[i];
        }

        b_st.site = &lg_emlrtRSI;
        b_indexShapeCheck(&b_st, b_proc_tx_mode->size, pitch_catch_indices->
                          size[0]);
        loop_ub = b_ii->size[0];
        b_ii->size[0] = eint;
        emxEnsureCapacity_int32_T(&st, b_ii, loop_ub, &ld_emlrtRTEI);
        ii_data = b_ii->data;
        b_loop_ub = (pitch_catch_indices->size[0] < 2000);
        if (b_loop_ub) {
          for (i16 = 0; i16 < eint; i16++) {
            loop_ub = (int32_T)pitch_catch_indices_data[i16];
            if ((loop_ub < 1) || (loop_ub > h_loop_ub)) {
              emlrtDynamicBoundsCheckR2012b(loop_ub, 1, h_loop_ub, &fb_emlrtBCI,
                &st);
            }

            ii_data[i16] = loop_ub;
          }
        } else {
          emlrtEnterParallelRegion(&st, omp_in_parallel());
          emlrtPushJmpBuf(&st, &emlrtJBStack);
          fn_process_rail_data_DLL_numThreads = emlrtAllocRegionTLSs(st.tls,
            omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());

#pragma omp parallel \
 num_threads(fn_process_rail_data_DLL_numThreads) \
 private(emlrtJBEnviron,g_st,i18) \
 firstprivate(emlrtHadParallelError,st)

          {
            if (setjmp(emlrtJBEnviron) == 0) {
              g_st.prev = &st;
              g_st.tls = emlrtAllocTLS(&st, omp_get_thread_num());
              g_st.site = NULL;
              emlrtSetJmpBuf(&g_st, &emlrtJBEnviron);
            } else {
              emlrtHadParallelError = true;
            }

#pragma omp for nowait

            for (i16 = 0; i16 < eint; i16++) {
              if (emlrtHadParallelError) {
                continue;
              }

              if (setjmp(emlrtJBEnviron) == 0) {
                i18 = (int32_T)pitch_catch_indices_data[i16];
                if ((i18 < 1) || (i18 > h_loop_ub)) {
                  emlrtDynamicBoundsCheckR2012b(i18, 1, h_loop_ub, &fb_emlrtBCI,
                    &g_st);
                }

                ii_data[i16] = i18;
              } else {
                emlrtHadParallelError = true;
              }
            }
          }

          emlrtPopJmpBuf(&st, &emlrtJBStack);
          emlrtExitParallelRegion(&st, omp_in_parallel());
        }

        c_loop_ub = b_ii->size[0];
        loop_ub = d_proc_tx_mode->size[0];
        d_proc_tx_mode->size[0] = b_ii->size[0];
        emxEnsureCapacity_real_T(&st, d_proc_tx_mode, loop_ub, &md_emlrtRTEI);
        proc_tx_dir_data = d_proc_tx_mode->data;
        loop_ub = b_ii->size[0];
        if (b_ii->size[0] < 2000) {
          for (i19 = 0; i19 < c_loop_ub; i19++) {
            proc_tx_dir_data[i19] = proc_tx_mode_data[ii_data[i19] - 1] +
              3.1415926535897931;
          }
        } else {
          emlrtEnterParallelRegion(&st, omp_in_parallel());
          emlrtPushJmpBuf(&st, &emlrtJBStack);
          fn_process_rail_data_DLL_numThreads = emlrtAllocRegionTLSs(st.tls,
            omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());

#pragma omp parallel for \
 num_threads(fn_process_rail_data_DLL_numThreads)

          for (i19 = 0; i19 < loop_ub; i19++) {
            proc_tx_dir_data[i19] = proc_tx_mode_data[ii_data[i19] - 1] +
              3.1415926535897931;
          }

          emlrtPopJmpBuf(&st, &emlrtJBStack);
          emlrtExitParallelRegion(&st, omp_in_parallel());
        }

        for (i = 0; i < c_loop_ub; i++) {
          proc_tx_mode_data[ii_data[i] - 1] = proc_tx_dir_data[i];
        }

        emxFree_real_T(&st, &d_proc_tx_mode);
        b_st.site = &mg_emlrtRSI;
        b_indexShapeCheck(&b_st, b_proc_rx_mode->size, pitch_catch_indices->
                          size[0]);
        loop_ub = b_ii->size[0];
        b_ii->size[0] = eint;
        emxEnsureCapacity_int32_T(&st, b_ii, loop_ub, &od_emlrtRTEI);
        ii_data = b_ii->data;
        if (b_loop_ub) {
          for (i20 = 0; i20 < eint; i20++) {
            loop_ub = (int32_T)pitch_catch_indices_data[i20];
            if ((loop_ub < 1) || (loop_ub > c_proc_rx_mode)) {
              emlrtDynamicBoundsCheckR2012b(loop_ub, 1, c_proc_rx_mode,
                &hb_emlrtBCI, &st);
            }

            ii_data[i20] = loop_ub;
          }
        } else {
          emlrtEnterParallelRegion(&st, omp_in_parallel());
          emlrtPushJmpBuf(&st, &emlrtJBStack);
          fn_process_rail_data_DLL_numThreads = emlrtAllocRegionTLSs(st.tls,
            omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());

#pragma omp parallel \
 num_threads(fn_process_rail_data_DLL_numThreads) \
 private(emlrtJBEnviron,h_st,i21) \
 firstprivate(emlrtHadParallelError,st)

          {
            if (setjmp(emlrtJBEnviron) == 0) {
              h_st.prev = &st;
              h_st.tls = emlrtAllocTLS(&st, omp_get_thread_num());
              h_st.site = NULL;
              emlrtSetJmpBuf(&h_st, &emlrtJBEnviron);
            } else {
              emlrtHadParallelError = true;
            }

#pragma omp for nowait

            for (i20 = 0; i20 < eint; i20++) {
              if (emlrtHadParallelError) {
                continue;
              }

              if (setjmp(emlrtJBEnviron) == 0) {
                i21 = (int32_T)pitch_catch_indices_data[i20];
                if ((i21 < 1) || (i21 > c_proc_rx_mode)) {
                  emlrtDynamicBoundsCheckR2012b(i21, 1, c_proc_rx_mode,
                    &hb_emlrtBCI, &h_st);
                }

                ii_data[i20] = i21;
              } else {
                emlrtHadParallelError = true;
              }
            }
          }

          emlrtPopJmpBuf(&st, &emlrtJBStack);
          emlrtExitParallelRegion(&st, omp_in_parallel());
        }

        b_loop_ub = b_ii->size[0];
        loop_ub = pitch_catch_indices->size[0];
        pitch_catch_indices->size[0] = b_ii->size[0];
        emxEnsureCapacity_real_T(&st, pitch_catch_indices, loop_ub,
          &qd_emlrtRTEI);
        pitch_catch_indices_data = pitch_catch_indices->data;
        loop_ub = b_ii->size[0];
        if (b_ii->size[0] < 2000) {
          for (i22 = 0; i22 < b_loop_ub; i22++) {
            pitch_catch_indices_data[i22] = -proc_rx_mode_data[ii_data[i22] - 1];
          }
        } else {
          emlrtEnterParallelRegion(&st, omp_in_parallel());
          emlrtPushJmpBuf(&st, &emlrtJBStack);
          fn_process_rail_data_DLL_numThreads = emlrtAllocRegionTLSs(st.tls,
            omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());

#pragma omp parallel for \
 num_threads(fn_process_rail_data_DLL_numThreads)

          for (i22 = 0; i22 < loop_ub; i22++) {
            pitch_catch_indices_data[i22] = -proc_rx_mode_data[ii_data[i22] - 1];
          }

          emlrtPopJmpBuf(&st, &emlrtJBStack);
          emlrtExitParallelRegion(&st, omp_in_parallel());
        }

        for (i = 0; i < b_loop_ub; i++) {
          proc_rx_mode_data[ii_data[i] - 1] = pitch_catch_indices_data[i];
        }
      }

      b_st.site = &ng_emlrtRSI;
      if (b_proc_tx_mode->size[1] != 1) {
        emlrtErrorWithMessageIdR2018a(&b_st, &emlrtRTEI, "MATLAB:dimagree",
          "MATLAB:dimagree", 0);
      }

      loop_ub = b_y->size[0] * b_y->size[1];
      b_y->size[0] = 1;
      b_y->size[1] = 1;
      emxEnsureCapacity_real_T(&b_st, b_y, loop_ub, &sc_emlrtRTEI);
      pitch_catch_indices_data = b_y->data;
      pitch_catch_indices_data[0] = 6.2831853071795862 *
        opts_ms_matrix_calc_freqs_data[0];
      c_st.site = &yg_emlrtRSI;
      mrdiv(&c_st, b_proc_tx_mode, b_y, pitch_catch_indices);
      pitch_catch_indices_data = pitch_catch_indices->data;
      if (opts_ms_matrix_time_step_size > 0.0) {
        loop_ub = pitch_catch_indices->size[0];
        b_loop_ub = (pitch_catch_indices->size[0] / 2) << 1;
        c_loop_ub = b_loop_ub - 2;
        for (i = 0; i <= c_loop_ub; i += 2) {
          r = _mm_loadu_pd(&pitch_catch_indices_data[i]);
          _mm_storeu_pd(&pitch_catch_indices_data[i], _mm_div_pd(r, _mm_set1_pd
            (opts_ms_matrix_time_step_size)));
        }

        for (i = b_loop_ub; i < loop_ub; i++) {
          pitch_catch_indices_data[i] /= opts_ms_matrix_time_step_size;
        }

        b_st.site = &og_emlrtRSI;
        b_round(&b_st, pitch_catch_indices);
        pitch_catch_indices_data = pitch_catch_indices->data;
        loop_ub = pitch_catch_indices->size[0];
        b_loop_ub = (pitch_catch_indices->size[0] / 2) << 1;
        c_loop_ub = b_loop_ub - 2;
        for (i = 0; i <= c_loop_ub; i += 2) {
          r = _mm_loadu_pd(&pitch_catch_indices_data[i]);
          _mm_storeu_pd(&pitch_catch_indices_data[i], _mm_mul_pd(r, _mm_set1_pd
            (opts_ms_matrix_time_step_size)));
        }

        for (i = b_loop_ub; i < loop_ub; i++) {
          pitch_catch_indices_data[i] *= opts_ms_matrix_time_step_size;
        }
      }

      b_loop_ub = (int32_T)(f + (1.0 - freq_i1));
      if (b_loop_ub - 1 >= 0) {
        i_loop_ub = pitch_catch_indices->size[0];
        j_loop_ub = raw_freq_data->size[1];
      }

      for (c_ii = 0; c_ii < b_loop_ub; c_ii++) {
        y = freq_i1 + (real_T)c_ii;
        if (((int32_T)y < 1) || ((int32_T)y > f_loop_ub)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)y, 1, f_loop_ub, &i_emlrtBCI,
            &st);
        }

        f = proc_rx_dir_data[(int32_T)y - 1];
        y_re = f * 0.0;
        f *= 6.2831853071795862;
        loop_ub = r1->size[0];
        r1->size[0] = pitch_catch_indices->size[0];
        emxEnsureCapacity_creal_T(&st, r1, loop_ub, &yc_emlrtRTEI);
        yi_data = r1->data;
        for (i = 0; i < i_loop_ub; i++) {
          yi_data[i].re = pitch_catch_indices_data[i] * y_re;
          yi_data[i].im = pitch_catch_indices_data[i] * f;
        }

        b_st.site = &pg_emlrtRSI;
        b_exp(&b_st, r1);
        yi_data = r1->data;
        c_loop_ub = b_proc_rx_mode->size[0];
        if ((b_proc_rx_mode->size[0] != r1->size[0]) && ((b_proc_rx_mode->size[0]
              != 1) && (r1->size[0] != 1))) {
          emlrtDimSizeImpxCheckR2021b(b_proc_rx_mode->size[0], r1->size[0],
            &c_emlrtECI, &st);
        }

        if (b_proc_rx_mode->size[0] == r1->size[0]) {
          loop_ub = inv_full_mode_shapes->size[0] * inv_full_mode_shapes->size[1];
          inv_full_mode_shapes->size[0] = b_proc_rx_mode->size[0];
          d_loop_ub = b_proc_rx_mode->size[1];
          inv_full_mode_shapes->size[1] = b_proc_rx_mode->size[1];
          emxEnsureCapacity_creal_T(&st, inv_full_mode_shapes, loop_ub,
            &bd_emlrtRTEI);
          inv_full_mode_shapes_data = inv_full_mode_shapes->data;
          for (i = 0; i < d_loop_ub; i++) {
            for (ii = 0; ii < c_loop_ub; ii++) {
              inv_full_mode_shapes_data[ii + inv_full_mode_shapes->size[0] * i].
                re = proc_rx_mode_data[ii + b_proc_rx_mode->size[0] * i] *
                yi_data[ii].re;
              inv_full_mode_shapes_data[ii + inv_full_mode_shapes->size[0] * i].
                im = proc_rx_mode_data[ii + b_proc_rx_mode->size[0] * i] *
                yi_data[ii].im;
            }
          }
        } else {
          b_st.site = &pg_emlrtRSI;
          binary_expand_op(&b_st, inv_full_mode_shapes, b_proc_rx_mode, r1);
        }

        if (((int32_T)y < 1) || ((int32_T)y > i2)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)y, 1, i2, &l_emlrtBCI, &st);
        }

        b_st.site = &qg_emlrtRSI;
        c_st.site = &ug_emlrtRSI;
        if (raw_freq_data->size[1] != inv_full_mode_shapes->size[1]) {
          if ((raw_freq_data->size[1] == 1) || ((inv_full_mode_shapes->size[0] ==
                1) && (inv_full_mode_shapes->size[1] == 1))) {
            emlrtErrorWithMessageIdR2018a(&c_st, &d_emlrtRTEI,
              "Coder:toolbox:mtimes_noDynamicScalarExpansion",
              "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
          } else {
            emlrtErrorWithMessageIdR2018a(&c_st, &c_emlrtRTEI, "MATLAB:innerdim",
              "MATLAB:innerdim", 0);
          }
        }

        loop_ub = b_raw_freq_data->size[0] * b_raw_freq_data->size[1];
        b_raw_freq_data->size[0] = 1;
        b_raw_freq_data->size[1] = raw_freq_data->size[1];
        emxEnsureCapacity_creal_T(&b_st, b_raw_freq_data, loop_ub, &ed_emlrtRTEI);
        yi_data = b_raw_freq_data->data;
        for (i = 0; i < j_loop_ub; i++) {
          yi_data[i] = raw_freq_data_data[((int32_T)y + raw_freq_data->size[0] *
            i) - 1];
        }

        c_st.site = &m_emlrtRSI;
        c_mtimes(&c_st, b_raw_freq_data, inv_full_mode_shapes, yi);
        yi_data = yi->data;
        iv[0] = 1;
        iv[1] = g_loop_ub;
        emlrtSubAssignSizeCheckR2012b(&iv[0], 2, &yi->size[0], 2, &f_emlrtECI,
          &st);
        for (i = 0; i < g_loop_ub; i++) {
          proc_freq_data_data[((int32_T)y + proc_freq_data->size[0] * i) - 1] =
            yi_data[i];
        }

        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&st);
        }
      }
    }
  } else {
    eint = (int32_T)(f + (1.0 - freq_i1));
    emxInit_creal_T(&st, &yy, 2, &rc_emlrtRTEI);
    emxInit_creal_T(&st, &b_inv_mode_shapes, 3, &pc_emlrtRTEI);
    for (fcount = 0; fcount < eint; fcount++) {
      f = freq_i1 + (real_T)fcount;
      loop_ub = inv_full_mode_shapes->size[0] * inv_full_mode_shapes->size[1];
      inv_full_mode_shapes->size[0] = g_loop_ub;
      b_loop_ub = inv_mode_shapes->size[1];
      inv_full_mode_shapes->size[1] = inv_mode_shapes->size[1];
      emxEnsureCapacity_creal_T(&st, inv_full_mode_shapes, loop_ub,
        &oc_emlrtRTEI);
      inv_full_mode_shapes_data = inv_full_mode_shapes->data;
      d_loop_ub = inv_mode_shapes->size[0] * inv_mode_shapes->size[1];
      for (i = 0; i < d_loop_ub; i++) {
        inv_full_mode_shapes_data[i].re = 0.0;
        inv_full_mode_shapes_data[i].im = 0.0;
      }

      for (c_ii = 0; c_ii < g_loop_ub; c_ii++) {
        if (c_ii + 1 > g_loop_ub) {
          emlrtDynamicBoundsCheckR2012b(c_ii + 1, 1, g_loop_ub, &j_emlrtBCI, &st);
        }

        loop_ub = b_inv_mode_shapes->size[0] * b_inv_mode_shapes->size[1] *
          b_inv_mode_shapes->size[2];
        b_inv_mode_shapes->size[0] = 1;
        b_inv_mode_shapes->size[1] = b_loop_ub;
        c_loop_ub = inv_mode_shapes->size[2];
        b_inv_mode_shapes->size[2] = inv_mode_shapes->size[2];
        emxEnsureCapacity_creal_T(&st, b_inv_mode_shapes, loop_ub, &pc_emlrtRTEI);
        proc_dist_data_data = b_inv_mode_shapes->data;
        for (i = 0; i < c_loop_ub; i++) {
          for (ii = 0; ii < b_loop_ub; ii++) {
            proc_dist_data_data[ii + b_inv_mode_shapes->size[1] * i] =
              inv_mode_shapes_data[(c_ii + inv_mode_shapes->size[0] * ii) +
              inv_mode_shapes->size[0] * inv_mode_shapes->size[1] * i];
          }
        }

        b_st.site = &rg_emlrtRSI;
        squeeze(&b_st, b_inv_mode_shapes, b_inv_full_mode_shapes);
        b_inv_full_mode_shapes_data = b_inv_full_mode_shapes->data;
        c_loop_ub = b_inv_full_mode_shapes->size[1];
        loop_ub = yy->size[0] * yy->size[1];
        yy->size[0] = b_inv_full_mode_shapes->size[1];
        e_loop_ub = b_inv_full_mode_shapes->size[0];
        yy->size[1] = b_inv_full_mode_shapes->size[0];
        emxEnsureCapacity_creal_T(&st, yy, loop_ub, &rc_emlrtRTEI);
        proc_dist_data_data = yy->data;
        for (i = 0; i < e_loop_ub; i++) {
          for (ii = 0; ii < c_loop_ub; ii++) {
            proc_dist_data_data[ii + yy->size[0] * i] =
              b_inv_full_mode_shapes_data[i + b_inv_full_mode_shapes->size[0] *
              ii];
          }
        }

        if (((int32_T)f < 1) || ((int32_T)f > f_loop_ub)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)f, 1, f_loop_ub, &w_emlrtBCI,
            &st);
        }

        b_st.site = &sg_emlrtRSI;
        c_interp1(&b_st, opts_ms_matrix_calc_freqs, yy, proc_rx_dir_data
                  [(int32_T)f - 1], yi);
        yi_data = yi->data;
        if (c_ii + 1 > g_loop_ub) {
          emlrtDynamicBoundsCheckR2012b(c_ii + 1, 1, g_loop_ub, &k_emlrtBCI, &st);
        }

        iv[0] = 1;
        iv[1] = b_loop_ub;
        emlrtSubAssignSizeCheckR2012b(&iv[0], 2, &yi->size[0], 2, &d_emlrtECI,
          &st);
        for (i = 0; i < b_loop_ub; i++) {
          inv_full_mode_shapes_data[c_ii + inv_full_mode_shapes->size[0] * i] =
            yi_data[i];
        }

        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&st);
        }
      }

      for (i = 0; i < d_loop_ub; i++) {
        if (muDoubleScalarIsNaN(inv_full_mode_shapes_data[i].re) ||
            muDoubleScalarIsNaN(inv_full_mode_shapes_data[i].im)) {
          if (i > d_loop_ub - 1) {
            emlrtDynamicBoundsCheckR2012b(i, 0, d_loop_ub - 1, &v_emlrtBCI, &st);
          }

          inv_full_mode_shapes_data[i].re = 0.0;
          if (i > d_loop_ub - 1) {
            emlrtDynamicBoundsCheckR2012b(i, 0, d_loop_ub - 1, &v_emlrtBCI, &st);
          }

          inv_full_mode_shapes_data[i].im = 0.0;
        }
      }

      if (((int32_T)f < 1) || ((int32_T)f > i2)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)f, 1, i2, &m_emlrtBCI, &st);
      }

      b_st.site = &tg_emlrtRSI;
      c_st.site = &ug_emlrtRSI;
      b_loop_ub = raw_freq_data->size[1];
      if (raw_freq_data->size[1] != inv_full_mode_shapes->size[1]) {
        if ((raw_freq_data->size[1] == 1) || ((inv_full_mode_shapes->size[0] ==
              1) && (inv_full_mode_shapes->size[1] == 1))) {
          emlrtErrorWithMessageIdR2018a(&c_st, &d_emlrtRTEI,
            "Coder:toolbox:mtimes_noDynamicScalarExpansion",
            "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
        } else {
          emlrtErrorWithMessageIdR2018a(&c_st, &c_emlrtRTEI, "MATLAB:innerdim",
            "MATLAB:innerdim", 0);
        }
      }

      loop_ub = b_raw_freq_data->size[0] * b_raw_freq_data->size[1];
      b_raw_freq_data->size[0] = 1;
      b_raw_freq_data->size[1] = raw_freq_data->size[1];
      emxEnsureCapacity_creal_T(&b_st, b_raw_freq_data, loop_ub, &tc_emlrtRTEI);
      yi_data = b_raw_freq_data->data;
      for (i = 0; i < b_loop_ub; i++) {
        yi_data[i] = raw_freq_data_data[((int32_T)f + raw_freq_data->size[0] * i)
          - 1];
      }

      c_st.site = &m_emlrtRSI;
      c_mtimes(&c_st, b_raw_freq_data, inv_full_mode_shapes, yi);
      yi_data = yi->data;
      iv[0] = 1;
      iv[1] = g_loop_ub;
      emlrtSubAssignSizeCheckR2012b(&iv[0], 2, &yi->size[0], 2, &g_emlrtECI, &st);
      for (i = 0; i < g_loop_ub; i++) {
        proc_freq_data_data[((int32_T)f + proc_freq_data->size[0] * i) - 1] =
          yi_data[i];
      }

      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }

    emxFree_creal_T(&st, &b_inv_mode_shapes);
    emxFree_creal_T(&st, &yy);
  }

  emxFree_creal_T(&st, &b_raw_freq_data);
  emxFree_creal_T(&st, &b_inv_full_mode_shapes);
  emxFree_creal_T(&st, &yi);
  emxFree_int32_T(&st, &b_ii);
  emxFree_real_T(&st, &b_proc_rx_mode);
  emxFree_real_T(&st, &b_proc_tx_mode);
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
  if (f_loop_ub < 2) {
    emlrtDynamicBoundsCheckR2012b(2, 1, f_loop_ub, &n_emlrtBCI, &st);
  }

  f = 1.0 / (fft_pts * muDoubleScalarAbs(proc_rx_dir_data[1] - proc_rx_dir_data
              [0]));
  emxFree_real_T(&st, &freq);
  emxInit_real_T(&st, &proc_tx_dir, 2, &yd_emlrtRTEI);
  proc_rx_dir_data = proc_tx_dir->data;
  if (fft_pts - 1.0 < 0.0) {
    proc_tx_dir->size[0] = 1;
    proc_tx_dir->size[1] = 0;
  } else {
    b_loop_ub = proc_tx_dir->size[0] * proc_tx_dir->size[1];
    proc_tx_dir->size[0] = 1;
    proc_tx_dir->size[1] = (int32_T)(fft_pts - 1.0) + 1;
    emxEnsureCapacity_real_T(&st, proc_tx_dir, b_loop_ub, &qc_emlrtRTEI);
    proc_rx_dir_data = proc_tx_dir->data;
    b_loop_ub = (int32_T)(fft_pts - 1.0);
    for (i = 0; i <= b_loop_ub; i++) {
      proc_rx_dir_data[i] = i;
    }
  }

  b_st.site = &yh_emlrtRSI;
  ifft(&b_st, proc_freq_data, fft_pts, inv_full_mode_shapes);
  emxFree_creal_T(&st, &proc_freq_data);

  /* Convert from time to distance */
  b_loop_ub = b_y->size[0] * b_y->size[1];
  b_y->size[0] = 1;
  c_loop_ub = proc_tx_dir->size[1];
  b_y->size[1] = proc_tx_dir->size[1];
  emxEnsureCapacity_real_T(sp, b_y, b_loop_ub, &sc_emlrtRTEI);
  pitch_catch_indices_data = b_y->data;
  b_loop_ub = (proc_tx_dir->size[1] / 2) << 1;
  loop_ub = b_loop_ub - 2;
  for (i = 0; i <= loop_ub; i += 2) {
    r = _mm_loadu_pd(&proc_rx_dir_data[i]);
    _mm_storeu_pd(&pitch_catch_indices_data[i], _mm_mul_pd(r, _mm_set1_pd(f)));
  }

  for (i = b_loop_ub; i < c_loop_ub; i++) {
    pitch_catch_indices_data[i] = proc_rx_dir_data[i] * f;
  }

  emxInit_real_T(sp, &proc_rx_dir, 2, &tb_emlrtRTEI);
  st.site = &k_emlrtRSI;
  fn_convert_time_to_dist(&st, b_y, inv_full_mode_shapes, proc_tx_mode,
    proc_rx_mode, disperse_freq, disperse_vgr, disperse_waveno,
    opts_ms_matrix_modes_to_use, opts_freq_filter, proc_dist, proc_dist_data,
    proc_rx_dir);
  raw_time_data_data = proc_rx_dir->data;
  proc_dist_data_data = proc_dist_data->data;
  proc_tx_mode_data = proc_dist->data;
  emxFree_creal_T(sp, &inv_full_mode_shapes);

  /*  end */
  /* Warp distance axes if desired according to opts_manual_warps (vector of */
  /* warp factors for each mode) */
  if (opts_manual_warps->size[1] != 0) {
    st.site = &l_emlrtRSI;
    b_st.site = &li_emlrtRSI;
    c_st.site = &ni_emlrtRSI;
    c_indexShapeCheck(&c_st, proc_rx_dir->size, proc_tx_mode->size[0]);
    d_loop_ub = proc_tx_mode->size[0];
    for (i = 0; i < d_loop_ub; i++) {
      if (b_proc_tx_mode_data[i] != (int32_T)muDoubleScalarFloor
          (b_proc_tx_mode_data[i])) {
        emlrtIntegerCheckR2012b(b_proc_tx_mode_data[i], &b_emlrtDCI, &b_st);
      }

      b_loop_ub = (int32_T)b_proc_tx_mode_data[i];
      if ((b_loop_ub < 1) || (b_loop_ub > proc_rx_dir->size[1])) {
        emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1, proc_rx_dir->size[1],
          &ab_emlrtBCI, &b_st);
      }
    }

    c_st.site = &oi_emlrtRSI;
    c_indexShapeCheck(&c_st, proc_rx_dir->size, proc_rx_mode->size[0]);
    e_loop_ub = proc_rx_mode->size[0];
    for (i = 0; i < e_loop_ub; i++) {
      if (b_proc_rx_mode_data[i] != (int32_T)muDoubleScalarFloor
          (b_proc_rx_mode_data[i])) {
        emlrtIntegerCheckR2012b(b_proc_rx_mode_data[i], &c_emlrtDCI, &b_st);
      }

      b_loop_ub = (int32_T)b_proc_rx_mode_data[i];
      if ((b_loop_ub < 1) || (b_loop_ub > proc_rx_dir->size[1])) {
        emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1, proc_rx_dir->size[1],
          &bb_emlrtBCI, &b_st);
      }
    }

    c_st.site = &pi_emlrtRSI;
    c_indexShapeCheck(&c_st, proc_rx_dir->size, proc_tx_mode->size[0]);
    c_st.site = &pi_emlrtRSI;
    c_indexShapeCheck(&c_st, opts_manual_warps->size, proc_tx_mode->size[0]);
    for (i = 0; i < d_loop_ub; i++) {
      b_loop_ub = (int32_T)b_proc_tx_mode_data[i];
      if ((b_loop_ub < 1) || (b_loop_ub > proc_rx_dir->size[1])) {
        emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1, proc_rx_dir->size[1],
          &cb_emlrtBCI, &b_st);
      }
    }

    for (i = 0; i < d_loop_ub; i++) {
      b_loop_ub = (int32_T)b_proc_tx_mode_data[i];
      if ((b_loop_ub < 1) || (b_loop_ub > opts_manual_warps->size[1])) {
        emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1, opts_manual_warps->size[1],
          &db_emlrtBCI, &b_st);
      }
    }

    c_st.site = &qi_emlrtRSI;
    c_indexShapeCheck(&c_st, proc_rx_dir->size, proc_rx_mode->size[0]);
    c_st.site = &qi_emlrtRSI;
    c_indexShapeCheck(&c_st, opts_manual_warps->size, proc_rx_mode->size[0]);
    for (i = 0; i < e_loop_ub; i++) {
      b_loop_ub = (int32_T)b_proc_rx_mode_data[i];
      if ((b_loop_ub < 1) || (b_loop_ub > proc_rx_dir->size[1])) {
        emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1, proc_rx_dir->size[1],
          &eb_emlrtBCI, &b_st);
      }
    }

    for (i = 0; i < e_loop_ub; i++) {
      b_loop_ub = (int32_T)b_proc_rx_mode_data[i];
      if ((b_loop_ub < 1) || (b_loop_ub > opts_manual_warps->size[1])) {
        emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1, opts_manual_warps->size[1],
          &gb_emlrtBCI, &b_st);
      }
    }

    emxInit_real_T(&b_st, &opts_ms_matrix_calc_freqs, 2, &nd_emlrtRTEI);
    b_loop_ub = opts_ms_matrix_calc_freqs->size[0] *
      opts_ms_matrix_calc_freqs->size[1];
    opts_ms_matrix_calc_freqs->size[0] = 1;
    opts_ms_matrix_calc_freqs->size[1] = proc_tx_mode->size[0];
    emxEnsureCapacity_real_T(&b_st, opts_ms_matrix_calc_freqs, b_loop_ub,
      &cd_emlrtRTEI);
    opts_ms_matrix_calc_freqs_data = opts_ms_matrix_calc_freqs->data;
    b_loop_ub = proc_tx_mode->size[0];
    loop_ub = (proc_tx_mode->size[0] < 2000);
    if (loop_ub) {
      for (i11 = 0; i11 < d_loop_ub; i11++) {
        opts_ms_matrix_calc_freqs_data[i11] = 1.0 / raw_time_data_data[(int32_T)
          b_proc_tx_mode_data[i11] - 1];
      }
    } else {
      emlrtEnterParallelRegion(&b_st, omp_in_parallel());
      emlrtPushJmpBuf(&b_st, &emlrtJBStack);
      fn_process_rail_data_DLL_numThreads = emlrtAllocRegionTLSs(b_st.tls,
        omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());

#pragma omp parallel for \
 num_threads(fn_process_rail_data_DLL_numThreads)

      for (i11 = 0; i11 < b_loop_ub; i11++) {
        opts_ms_matrix_calc_freqs_data[i11] = 1.0 / raw_time_data_data[(int32_T)
          b_proc_tx_mode_data[i11] - 1];
      }

      emlrtPopJmpBuf(&b_st, &emlrtJBStack);
      emlrtExitParallelRegion(&b_st, omp_in_parallel());
    }

    b_loop_ub = b_y->size[0] * b_y->size[1];
    b_y->size[0] = 1;
    b_y->size[1] = e_loop_ub;
    emxEnsureCapacity_real_T(&b_st, b_y, b_loop_ub, &fd_emlrtRTEI);
    pitch_catch_indices_data = b_y->data;
    c_loop_ub = (proc_rx_mode->size[0] < 2000);
    if (c_loop_ub) {
      for (i12 = 0; i12 < e_loop_ub; i12++) {
        pitch_catch_indices_data[i12] = 1.0 / raw_time_data_data[(int32_T)
          b_proc_rx_mode_data[i12] - 1];
      }
    } else {
      emlrtEnterParallelRegion(&b_st, omp_in_parallel());
      emlrtPushJmpBuf(&b_st, &emlrtJBStack);
      fn_process_rail_data_DLL_numThreads = emlrtAllocRegionTLSs(b_st.tls,
        omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());

#pragma omp parallel for \
 num_threads(fn_process_rail_data_DLL_numThreads)

      for (i12 = 0; i12 < e_loop_ub; i12++) {
        pitch_catch_indices_data[i12] = 1.0 / raw_time_data_data[(int32_T)
          b_proc_rx_mode_data[i12] - 1];
      }

      emlrtPopJmpBuf(&b_st, &emlrtJBStack);
      emlrtExitParallelRegion(&b_st, omp_in_parallel());
    }

    if ((d_loop_ub != e_loop_ub) && ((d_loop_ub != 1) && (e_loop_ub != 1))) {
      emlrtDimSizeImpxCheckR2021b(d_loop_ub, e_loop_ub, &i_emlrtECI, &b_st);
    }

    b_loop_ub = proc_tx_dir->size[0] * proc_tx_dir->size[1];
    proc_tx_dir->size[0] = 1;
    proc_tx_dir->size[1] = d_loop_ub;
    emxEnsureCapacity_real_T(&b_st, proc_tx_dir, b_loop_ub, &hd_emlrtRTEI);
    proc_rx_dir_data = proc_tx_dir->data;
    if (loop_ub) {
      for (i14 = 0; i14 < d_loop_ub; i14++) {
        b_loop_ub = (int32_T)b_proc_tx_mode_data[i14] - 1;
        proc_rx_dir_data[i14] = 1.0 / (raw_time_data_data[b_loop_ub] *
          opts_manual_warps_data[b_loop_ub]);
      }
    } else {
      emlrtEnterParallelRegion(&b_st, omp_in_parallel());
      emlrtPushJmpBuf(&b_st, &emlrtJBStack);
      fn_process_rail_data_DLL_numThreads = emlrtAllocRegionTLSs(b_st.tls,
        omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());

#pragma omp parallel for \
 num_threads(fn_process_rail_data_DLL_numThreads) \
 private(y_tmp)

      for (i14 = 0; i14 < d_loop_ub; i14++) {
        y_tmp = (int32_T)b_proc_tx_mode_data[i14] - 1;
        proc_rx_dir_data[i14] = 1.0 / (raw_time_data_data[y_tmp] *
          opts_manual_warps_data[y_tmp]);
      }

      emlrtPopJmpBuf(&b_st, &emlrtJBStack);
      emlrtExitParallelRegion(&b_st, omp_in_parallel());
    }

    emxInit_real_T(&b_st, &raw_time_data, 2, &hd_emlrtRTEI);
    b_loop_ub = raw_time_data->size[0] * raw_time_data->size[1];
    raw_time_data->size[0] = 1;
    raw_time_data->size[1] = e_loop_ub;
    emxEnsureCapacity_real_T(&b_st, raw_time_data, b_loop_ub, &jd_emlrtRTEI);
    proc_tx_dir_data = raw_time_data->data;
    if (c_loop_ub) {
      for (i15 = 0; i15 < e_loop_ub; i15++) {
        b_loop_ub = (int32_T)b_proc_rx_mode_data[i15] - 1;
        proc_tx_dir_data[i15] = 1.0 / (raw_time_data_data[b_loop_ub] *
          opts_manual_warps_data[b_loop_ub]);
      }
    } else {
      emlrtEnterParallelRegion(&b_st, omp_in_parallel());
      emlrtPushJmpBuf(&b_st, &emlrtJBStack);
      fn_process_rail_data_DLL_numThreads = emlrtAllocRegionTLSs(b_st.tls,
        omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());

#pragma omp parallel for \
 num_threads(fn_process_rail_data_DLL_numThreads) \
 private(i17)

      for (i15 = 0; i15 < e_loop_ub; i15++) {
        i17 = (int32_T)b_proc_rx_mode_data[i15] - 1;
        proc_tx_dir_data[i15] = 1.0 / (raw_time_data_data[i17] *
          opts_manual_warps_data[i17]);
      }

      emlrtPopJmpBuf(&b_st, &emlrtJBStack);
      emlrtExitParallelRegion(&b_st, omp_in_parallel());
    }

    c_st.site = &ri_emlrtRSI;
    if (opts_ms_matrix_calc_freqs->size[1] == b_y->size[1]) {
      c_loop_ub = opts_ms_matrix_calc_freqs->size[1] - 1;
      b_loop_ub = opts_ms_matrix_calc_freqs->size[0] *
        opts_ms_matrix_calc_freqs->size[1];
      opts_ms_matrix_calc_freqs->size[0] = 1;
      emxEnsureCapacity_real_T(&c_st, opts_ms_matrix_calc_freqs, b_loop_ub,
        &cd_emlrtRTEI);
      opts_ms_matrix_calc_freqs_data = opts_ms_matrix_calc_freqs->data;
      b_loop_ub = (opts_ms_matrix_calc_freqs->size[1] / 2) << 1;
      loop_ub = b_loop_ub - 2;
      for (i = 0; i <= loop_ub; i += 2) {
        r = _mm_loadu_pd(&opts_ms_matrix_calc_freqs_data[i]);
        r2 = _mm_loadu_pd(&pitch_catch_indices_data[i]);
        _mm_storeu_pd(&opts_ms_matrix_calc_freqs_data[i], _mm_add_pd(r, r2));
      }

      for (i = b_loop_ub; i <= c_loop_ub; i++) {
        opts_ms_matrix_calc_freqs_data[i] += pitch_catch_indices_data[i];
      }
    } else {
      d_st.site = &ri_emlrtRSI;
      plus(&d_st, opts_ms_matrix_calc_freqs, b_y);
    }

    if (proc_tx_dir->size[1] == raw_time_data->size[1]) {
      c_loop_ub = proc_tx_dir->size[1] - 1;
      b_loop_ub = proc_tx_dir->size[0] * proc_tx_dir->size[1];
      proc_tx_dir->size[0] = 1;
      emxEnsureCapacity_real_T(&c_st, proc_tx_dir, b_loop_ub, &hd_emlrtRTEI);
      proc_rx_dir_data = proc_tx_dir->data;
      b_loop_ub = (proc_tx_dir->size[1] / 2) << 1;
      loop_ub = b_loop_ub - 2;
      for (i = 0; i <= loop_ub; i += 2) {
        r = _mm_loadu_pd(&proc_rx_dir_data[i]);
        r2 = _mm_loadu_pd(&proc_tx_dir_data[i]);
        _mm_storeu_pd(&proc_rx_dir_data[i], _mm_add_pd(r, r2));
      }

      for (i = b_loop_ub; i <= c_loop_ub; i++) {
        proc_rx_dir_data[i] += proc_tx_dir_data[i];
      }
    } else {
      d_st.site = &ri_emlrtRSI;
      plus(&d_st, proc_tx_dir, raw_time_data);
      proc_rx_dir_data = proc_tx_dir->data;
    }

    emxFree_real_T(&c_st, &raw_time_data);
    d_st.site = &si_emlrtRSI;
    i_st.site = &ti_emlrtRSI;
    assertCompatibleDims(&i_st, opts_ms_matrix_calc_freqs, proc_tx_dir);
    if (opts_ms_matrix_calc_freqs->size[1] == proc_tx_dir->size[1]) {
      c_loop_ub = opts_ms_matrix_calc_freqs->size[1] - 1;
      b_loop_ub = opts_ms_matrix_calc_freqs->size[0] *
        opts_ms_matrix_calc_freqs->size[1];
      opts_ms_matrix_calc_freqs->size[0] = 1;
      emxEnsureCapacity_real_T(&d_st, opts_ms_matrix_calc_freqs, b_loop_ub,
        &nd_emlrtRTEI);
      opts_ms_matrix_calc_freqs_data = opts_ms_matrix_calc_freqs->data;
      b_loop_ub = (opts_ms_matrix_calc_freqs->size[1] / 2) << 1;
      loop_ub = b_loop_ub - 2;
      for (i = 0; i <= loop_ub; i += 2) {
        r = _mm_loadu_pd(&opts_ms_matrix_calc_freqs_data[i]);
        r2 = _mm_loadu_pd(&proc_rx_dir_data[i]);
        _mm_storeu_pd(&opts_ms_matrix_calc_freqs_data[i], _mm_div_pd(r, r2));
      }

      for (i = b_loop_ub; i <= c_loop_ub; i++) {
        opts_ms_matrix_calc_freqs_data[i] /= proc_rx_dir_data[i];
      }
    } else {
      i_st.site = &wi_emlrtRSI;
      rdivide(&i_st, opts_ms_matrix_calc_freqs, proc_tx_dir);
      opts_ms_matrix_calc_freqs_data = opts_ms_matrix_calc_freqs->data;
    }

    d_loop_ub = proc_dist_data->size[1];
    emxInit_creal_T(&st, &b_proc_dist_data, 1, &rd_emlrtRTEI);
    for (ii = 0; ii < d_loop_ub; ii++) {
      if (ii + 1 > opts_ms_matrix_calc_freqs->size[1]) {
        emlrtDynamicBoundsCheckR2012b(ii + 1, 1, opts_ms_matrix_calc_freqs->
          size[1], &o_emlrtBCI, &st);
      }

      if (ii + 1 > d_loop_ub) {
        emlrtDynamicBoundsCheckR2012b(ii + 1, 1, d_loop_ub, &q_emlrtBCI, &st);
      }

      f = opts_ms_matrix_calc_freqs_data[ii];
      if (ii + 1 > d_loop_ub) {
        emlrtDynamicBoundsCheckR2012b(ii + 1, 1, d_loop_ub, &p_emlrtBCI, &st);
      }

      c_loop_ub = proc_dist->size[0];
      b_loop_ub = pitch_catch_indices->size[0];
      pitch_catch_indices->size[0] = proc_dist->size[0];
      emxEnsureCapacity_real_T(&st, pitch_catch_indices, b_loop_ub,
        &pd_emlrtRTEI);
      pitch_catch_indices_data = pitch_catch_indices->data;
      loop_ub = (proc_dist->size[0] / 2) << 1;
      b_loop_ub = loop_ub - 2;
      for (i = 0; i <= b_loop_ub; i += 2) {
        r = _mm_loadu_pd(&proc_tx_mode_data[i]);
        _mm_storeu_pd(&pitch_catch_indices_data[i], _mm_div_pd(r, _mm_set1_pd(f)));
      }

      for (i = loop_ub; i < c_loop_ub; i++) {
        pitch_catch_indices_data[i] = proc_tx_mode_data[i] / f;
      }

      loop_ub = proc_dist_data->size[0];
      b_loop_ub = b_proc_dist_data->size[0];
      b_proc_dist_data->size[0] = proc_dist_data->size[0];
      emxEnsureCapacity_creal_T(&st, b_proc_dist_data, b_loop_ub, &rd_emlrtRTEI);
      yi_data = b_proc_dist_data->data;
      for (i = 0; i < loop_ub; i++) {
        yi_data[i] = proc_dist_data_data[i + proc_dist_data->size[0] * ii];
      }

      b_st.site = &mi_emlrtRSI;
      e_interp1(&b_st, pitch_catch_indices, b_proc_dist_data, proc_dist, r1);
      yi_data = r1->data;
      emlrtSubAssignSizeCheckR2012b(&proc_dist_data->size[0], 1, &r1->size[0], 1,
        &h_emlrtECI, &st);
      for (i = 0; i < loop_ub; i++) {
        proc_dist_data_data[i + proc_dist_data->size[0] * ii] = yi_data[i];
      }

      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }

    emxFree_creal_T(&st, &b_proc_dist_data);
    emxFree_real_T(&st, &opts_ms_matrix_calc_freqs);
  }

  emxFree_real_T(sp, &b_y);
  emxFree_real_T(sp, &proc_tx_dir);
  emxFree_creal_T(sp, &r1);
  emxFree_real_T(sp, &pitch_catch_indices);
  emxFree_real_T(sp, &proc_rx_dir);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (fn_process_rail_data_DLL.c) */
