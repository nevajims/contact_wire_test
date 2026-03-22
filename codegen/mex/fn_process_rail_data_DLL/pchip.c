/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * pchip.c
 *
 * Code generation for function 'pchip'
 *
 */

/* Include files */
#include "pchip.h"
#include "chckxy.h"
#include "eml_int_forloop_overflow_check.h"
#include "fn_process_rail_data_DLL_data.h"
#include "fn_process_rail_data_DLL_emxutil.h"
#include "fn_process_rail_data_DLL_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <emmintrin.h>

/* Variable Definitions */
static emlrtRSInfo le_emlrtRSI = {
    51,      /* lineNo */
    "pchip", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\polyfun\\pchip.m" /* pathName
                                                                          */
};

static emlrtRSInfo ne_emlrtRSI = {
    62,      /* lineNo */
    "pchip", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\polyfun\\pchip.m" /* pathName
                                                                          */
};

static emlrtRSInfo pe_emlrtRSI = {
    75,      /* lineNo */
    "pchip", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\polyfun\\pchip.m" /* pathName
                                                                          */
};

static emlrtRSInfo qe_emlrtRSI = {
    84,      /* lineNo */
    "pchip", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\polyfun\\pchip.m" /* pathName
                                                                          */
};

static emlrtRSInfo te_emlrtRSI = {
    44,         /* lineNo */
    "pwchcore", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\polyfun\\private\\pwchco"
    "re.m" /* pathName */
};

static emlrtRSInfo ue_emlrtRSI = {
    51,         /* lineNo */
    "pwchcore", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\polyfun\\private\\pwchco"
    "re.m" /* pathName */
};

static emlrtRTEInfo df_emlrtRTEI = {
    42,         /* lineNo */
    31,         /* colNo */
    "pwchcore", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\polyfun\\private\\pwchco"
    "re.m" /* pName */
};

/* Function Declarations */
static creal_T exteriorSlope(const creal_T d1, const creal_T d2, real_T h1,
                             real_T h2);

/* Function Definitions */
static creal_T exteriorSlope(const creal_T d1, const creal_T d2, real_T h1,
                             real_T h2)
{
  creal_T s;
  real_T b_s;
  real_T b_s_tmp;
  real_T s_tmp;
  real_T signd1;
  s_tmp = 2.0 * h1 + h2;
  b_s_tmp = h1 + h2;
  b_s = (s_tmp * d1.re - h1 * d2.re) / b_s_tmp;
  signd1 = muDoubleScalarSign(d1.re);
  if (muDoubleScalarSign(b_s) != signd1) {
    b_s = 0.0;
  } else if (signd1 != muDoubleScalarSign(d2.re)) {
    signd1 = 3.0 * d1.re;
    if (muDoubleScalarAbs(b_s) > muDoubleScalarAbs(signd1)) {
      b_s = signd1;
    }
  }
  s_tmp = (s_tmp * d1.im - h1 * d2.im) / b_s_tmp;
  signd1 = muDoubleScalarSign(d1.im);
  if (muDoubleScalarSign(s_tmp) != signd1) {
    s_tmp = 0.0;
  } else if (signd1 != muDoubleScalarSign(d2.im)) {
    signd1 = 3.0 * d1.im;
    if (muDoubleScalarAbs(s_tmp) > muDoubleScalarAbs(signd1)) {
      s_tmp = signd1;
    }
  }
  s.re = b_s;
  s.im = s_tmp;
  return s;
}

void pchip(const emlrtStack *sp, const emxArray_real_T *x,
           const emxArray_creal_T *y, emxArray_real_T *v_breaks,
           emxArray_creal_T *v_coefs)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  emxArray_creal_T *del;
  emxArray_creal_T *slopes;
  emxArray_real_T *h;
  const creal_T *y_data;
  creal_T *del_data;
  creal_T *slopes_data;
  creal_T *v_coefs_data;
  const real_T *x_data;
  real_T ar;
  real_T divdifij_im;
  real_T divdifij_re;
  real_T dzdxdx_im;
  real_T dzdxdx_re;
  real_T dzzdx_im;
  real_T dzzdx_re;
  real_T w2;
  real_T *h_data;
  real_T *v_breaks_data;
  int32_T c1;
  int32_T c2;
  int32_T j;
  int32_T joffset;
  int32_T k;
  int32_T m;
  int32_T nx;
  int32_T scalarLB;
  boolean_T exitg1;
  boolean_T overflow;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  y_data = y->data;
  x_data = x->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  st.site = &ie_emlrtRSI;
  if (x->size[0] < 2) {
    emlrtErrorWithMessageIdR2018a(&st, &w_emlrtRTEI,
                                  "MATLAB:chckxy:NotEnoughPts",
                                  "MATLAB:chckxy:NotEnoughPts", 0);
  }
  if (!isFiniteAndStrictlyIncreasing(x)) {
    emlrtErrorWithMessageIdR2018a(
        &st, &x_emlrtRTEI, "Coder:toolbox:MustBeFiniteAndStrictlyIncreasing",
        "Coder:toolbox:MustBeFiniteAndStrictlyIncreasing", 0);
  }
  overflow = false;
  scalarLB = y->size[0] * y->size[1];
  joffset = 0;
  exitg1 = false;
  while ((!exitg1) && (joffset <= scalarLB - 1)) {
    if (muDoubleScalarIsNaN(y_data[joffset].re) ||
        muDoubleScalarIsNaN(y_data[joffset].im)) {
      overflow = true;
      exitg1 = true;
    } else {
      joffset++;
    }
  }
  if (overflow) {
    emlrtErrorWithMessageIdR2018a(&st, &y_emlrtRTEI,
                                  "Coder:toolbox:UnsupportedNaN",
                                  "Coder:toolbox:UnsupportedNaN", 0);
  }
  if ((x->size[0] != y->size[1]) && (y->size[1] != x->size[0] + 2)) {
    emlrtErrorWithMessageIdR2018a(&st, &ab_emlrtRTEI,
                                  "MATLAB:chckxy:NumSitesMismatchValues",
                                  "MATLAB:chckxy:NumSitesMismatchValues", 4, 12,
                                  x->size[0], 12, y->size[1]);
  }
  nx = x->size[0] - 2;
  if (x->size[0] != y->size[1]) {
    emlrtErrorWithMessageIdR2018a(sp, &v_emlrtRTEI,
                                  "MATLAB:chckxy:NumSitesMismatchValues",
                                  "MATLAB:chckxy:NumSitesMismatchValues", 4, 12,
                                  x->size[0], 12, y->size[1]);
  }
  emxInit_real_T(sp, &h, 2, &ef_emlrtRTEI);
  scalarLB = h->size[0] * h->size[1];
  h->size[0] = 1;
  h->size[1] = x->size[0] - 1;
  emxEnsureCapacity_real_T(sp, h, scalarLB, &ye_emlrtRTEI);
  h_data = h->data;
  st.site = &je_emlrtRSI;
  scalarLB = ((x->size[0] - 1) / 2) << 1;
  joffset = scalarLB - 2;
  for (k = 0; k <= joffset; k += 2) {
    _mm_storeu_pd(&h_data[k], _mm_sub_pd(_mm_loadu_pd(&x_data[k + 1]),
                                         _mm_loadu_pd(&x_data[k])));
  }
  for (k = scalarLB; k <= nx; k++) {
    h_data[k] = x_data[k + 1] - x_data[k];
  }
  m = y->size[0];
  emxInit_creal_T(sp, &del, 2, &ff_emlrtRTEI);
  scalarLB = del->size[0] * del->size[1];
  del->size[0] = y->size[0];
  del->size[1] = y->size[1] - 1;
  emxEnsureCapacity_creal_T(sp, del, scalarLB, &af_emlrtRTEI);
  del_data = del->data;
  st.site = &ke_emlrtRSI;
  overflow = (y->size[0] > 2147483646);
  for (k = 0; k <= nx; k++) {
    c1 = k * m - 1;
    c2 = (k + 1) * m;
    st.site = &le_emlrtRSI;
    if (overflow) {
      b_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (j = 0; j < m; j++) {
      scalarLB = c2 + j;
      joffset = (c1 + j) + 1;
      ar = y_data[scalarLB].re - y_data[joffset].re;
      w2 = y_data[scalarLB].im - y_data[joffset].im;
      dzzdx_im = h_data[k];
      if (w2 == 0.0) {
        del_data[joffset].re = ar / dzzdx_im;
        del_data[joffset].im = 0.0;
      } else if (ar == 0.0) {
        del_data[joffset].re = 0.0;
        del_data[joffset].im = w2 / dzzdx_im;
      } else {
        del_data[joffset].re = ar / dzzdx_im;
        del_data[joffset].im = w2 / dzzdx_im;
      }
    }
  }
  emxInit_creal_T(sp, &slopes, 2, &gf_emlrtRTEI);
  scalarLB = slopes->size[0] * slopes->size[1];
  slopes->size[0] = y->size[0];
  slopes->size[1] = y->size[1];
  emxEnsureCapacity_creal_T(sp, slopes, scalarLB, &bf_emlrtRTEI);
  slopes_data = slopes->data;
  if (x->size[0] == 2) {
    st.site = &me_emlrtRSI;
    overflow = (y->size[0] > 2147483646);
    for (k = 0; k < 2; k++) {
      c1 = k * m;
      st.site = &ne_emlrtRSI;
      if (overflow) {
        b_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }
      for (j = 0; j < m; j++) {
        slopes_data[c1 + j] = del_data[j];
      }
    }
  } else {
    joffset = x->size[0];
    st.site = &oe_emlrtRSI;
    overflow = (y->size[0] > 2147483646);
    for (k = 0; k <= joffset - 3; k++) {
      ar = h_data[k + 1];
      w2 = h_data[k];
      dzzdx_re = 2.0 * ar + w2;
      w2 = ar + 2.0 * w2;
      c1 = k * m;
      c2 = (k + 1) * m - 1;
      st.site = &pe_emlrtRSI;
      if (overflow) {
        b_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }
      for (j = 0; j < m; j++) {
        scalarLB = c1 + j;
        divdifij_re = del_data[scalarLB].re;
        divdifij_im = del_data[scalarLB].im;
        scalarLB = (c2 + j) + 1;
        dzdxdx_re = del_data[scalarLB].re;
        dzdxdx_im = del_data[scalarLB].im;
        dzzdx_im = 0.0;
        if (muDoubleScalarSign(divdifij_re * dzdxdx_re) > 0.0) {
          dzzdx_im =
              (dzzdx_re + w2) / (dzzdx_re / divdifij_re + w2 / dzdxdx_re);
        }
        ar = 0.0;
        if (muDoubleScalarSign(divdifij_im * dzdxdx_im) > 0.0) {
          ar = (dzzdx_re + w2) / (dzzdx_re / divdifij_im + w2 / dzdxdx_im);
        }
        slopes_data[scalarLB].re = dzzdx_im;
        slopes_data[scalarLB].im = ar;
      }
    }
    joffset = (x->size[0] - 1) * y->size[0];
    c1 = (x->size[0] - 2) * y->size[0];
    c2 = (x->size[0] - 3) * y->size[0];
    st.site = &qe_emlrtRSI;
    if (y->size[0] > 2147483646) {
      b_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (k = 0; k < m; k++) {
      slopes_data[k] =
          exteriorSlope(del_data[k], del_data[k + m], h_data[0], h_data[1]);
      slopes_data[k + joffset] = exteriorSlope(
          del_data[k + c1], del_data[k + c2], h_data[nx], h_data[nx - 1]);
    }
  }
  st.site = &re_emlrtRSI;
  nx = x->size[0];
  b_st.site = &se_emlrtRSI;
  if (x->size[0] > muIntScalarMax_sint32(nx, nx)) {
    emlrtErrorWithMessageIdR2018a(&b_st, &c_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  scalarLB = v_breaks->size[0] * v_breaks->size[1];
  v_breaks->size[0] = 1;
  v_breaks->size[1] = x->size[0];
  emxEnsureCapacity_real_T(&st, v_breaks, scalarLB, &cf_emlrtRTEI);
  v_breaks_data = v_breaks->data;
  for (k = 0; k < nx; k++) {
    v_breaks_data[k] = x_data[k];
  }
  c1 = slopes->size[0];
  m = slopes->size[0] * (x->size[0] - 1);
  joffset = v_coefs->size[0] * v_coefs->size[1] * v_coefs->size[2];
  v_coefs->size[0] = slopes->size[0];
  v_coefs->size[1] = x->size[0] - 1;
  v_coefs->size[2] = 4;
  emxEnsureCapacity_creal_T(&st, v_coefs, joffset, &df_emlrtRTEI);
  v_coefs_data = v_coefs->data;
  b_st.site = &te_emlrtRSI;
  overflow = (slopes->size[0] > 2147483646);
  for (k = 0; k <= nx - 2; k++) {
    real_T dxj;
    dxj = h_data[k];
    joffset = k * c1 - 1;
    b_st.site = &ue_emlrtRSI;
    if (overflow) {
      c_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    for (j = 0; j < c1; j++) {
      c2 = (joffset + j) + 1;
      divdifij_re = del_data[c2].re;
      divdifij_im = del_data[c2].im;
      ar = divdifij_re - slopes_data[c2].re;
      w2 = divdifij_im - slopes_data[c2].im;
      if (w2 == 0.0) {
        dzzdx_re = ar / dxj;
        dzzdx_im = 0.0;
      } else if (ar == 0.0) {
        dzzdx_re = 0.0;
        dzzdx_im = w2 / dxj;
      } else {
        dzzdx_re = ar / dxj;
        dzzdx_im = w2 / dxj;
      }
      scalarLB = ((joffset + c1) + j) + 1;
      ar = slopes_data[scalarLB].re - divdifij_re;
      w2 = slopes_data[scalarLB].im - divdifij_im;
      if (w2 == 0.0) {
        dzdxdx_re = ar / dxj;
        dzdxdx_im = 0.0;
      } else if (ar == 0.0) {
        dzdxdx_re = 0.0;
        dzdxdx_im = w2 / dxj;
      } else {
        dzdxdx_re = ar / dxj;
        dzdxdx_im = w2 / dxj;
      }
      ar = dzdxdx_re - dzzdx_re;
      w2 = dzdxdx_im - dzzdx_im;
      if (w2 == 0.0) {
        v_coefs_data[c2].re = ar / dxj;
        v_coefs_data[c2].im = 0.0;
      } else if (ar == 0.0) {
        v_coefs_data[c2].re = 0.0;
        v_coefs_data[c2].im = w2 / dxj;
      } else {
        v_coefs_data[c2].re = ar / dxj;
        v_coefs_data[c2].im = w2 / dxj;
      }
      scalarLB = ((m + joffset) + j) + 1;
      v_coefs_data[scalarLB].re = 2.0 * dzzdx_re - dzdxdx_re;
      v_coefs_data[scalarLB].im = 2.0 * dzzdx_im - dzdxdx_im;
      v_coefs_data[(((m << 1) + joffset) + j) + 1] = slopes_data[c2];
      v_coefs_data[((3 * m + joffset) + j) + 1] = y_data[c2];
    }
  }
  emxFree_creal_T(&st, &slopes);
  emxFree_creal_T(&st, &del);
  emxFree_real_T(&st, &h);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (pchip.c) */
