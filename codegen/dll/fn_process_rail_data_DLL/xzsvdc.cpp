//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xzsvdc.cpp
//
// MATLAB Coder version            : 25.1
// C/C++ source code generated on  : 24-Mar-2026 22:30:21
//

// Include Files
#include "xzsvdc.h"
#include "abs.h"
#include "fn_process_rail_data_DLL_data.h"
#include "rt_nonfinite.h"
#include "xaxpy.h"
#include "xdotc.h"
#include "xnrm2.h"
#include "xrot.h"
#include "xrotg.h"
#include "xswap.h"
#include "xzlangeM.h"
#include "xzlascl.h"
#include "coder_array.h"
#include <cmath>
#include <cstring>

// Function Definitions
//
// Arguments    : array<creal_T, 2U> &A
//                array<creal_T, 2U> &U
//                array<double, 1U> &S
//                array<creal_T, 2U> &V
// Return Type  : void
//
namespace coder {
namespace internal {
namespace reflapack {
void xzsvdc(array<creal_T, 2U> &A, array<creal_T, 2U> &U, array<double, 1U> &S,
            array<creal_T, 2U> &V)
{
  array<creal_T, 2U> Vf;
  array<creal_T, 1U> e;
  array<creal_T, 1U> s;
  array<creal_T, 1U> work;
  double anrm;
  double c;
  double cscale;
  double emm1;
  double nrm;
  double r_im;
  double r_re;
  double rt;
  int minnp;
  int n;
  int ns;
  int p;
  int qjj;
  boolean_T doscale;
  n = A.size(0);
  p = A.size(1);
  qjj = A.size(0) + 1;
  ns = A.size(1);
  if (qjj <= ns) {
    ns = qjj;
  }
  qjj = A.size(0);
  minnp = A.size(1);
  if (qjj <= minnp) {
    minnp = qjj;
  }
  s.set_size(ns);
  if (ns - 1 >= 0) {
    std::memset(&s[0], 0, static_cast<unsigned int>(ns) * sizeof(creal_T));
  }
  e.set_size(A.size(1));
  if (p - 1 >= 0) {
    std::memset(&e[0], 0, static_cast<unsigned int>(p) * sizeof(creal_T));
  }
  work.set_size(A.size(0));
  if (n - 1 >= 0) {
    std::memset(&work[0], 0, static_cast<unsigned int>(n) * sizeof(creal_T));
  }
  U.set_size(A.size(0), minnp);
  qjj = A.size(0) * minnp;
  for (int ii{0}; ii < qjj; ii++) {
    U[ii].re = 0.0;
    U[ii].im = 0.0;
  }
  Vf.set_size(A.size(1), A.size(1));
  qjj = A.size(1) * A.size(1);
  if (qjj - 1 >= 0) {
    std::memset(&Vf[0], 0, static_cast<unsigned int>(qjj) * sizeof(creal_T));
  }
  doscale = false;
  cscale = 0.0;
  anrm = xzlangeM(A);
  if ((A.size(0) == 0) || (A.size(1) == 0)) {
    qjj = A.size(0);
    if (qjj > minnp) {
      qjj = minnp;
    }
    for (int ii{0}; ii < qjj; ii++) {
      ns = ii + U.size(0) * ii;
      U[ns].re = 1.0;
      U[ns].im = 0.0;
    }
    for (int ii{0}; ii < p; ii++) {
      qjj = ii + Vf.size(0) * ii;
      Vf[qjj].re = 1.0;
      Vf[qjj].im = 0.0;
    }
  } else {
    creal_T b_e;
    double b;
    double sm;
    double snorm;
    double sqds;
    int b_ii;
    int m;
    int nct;
    int nctp1;
    int nmq;
    int nrt;
    int qp1;
    int qq;
    cscale = anrm;
    if ((anrm > 0.0) && (anrm < 6.7178761075670888E-139)) {
      doscale = true;
      cscale = 6.7178761075670888E-139;
      xzlascl(anrm, cscale, A.size(0), A.size(1), A, A.size(0));
    } else if (anrm > 1.4885657073574029E+138) {
      doscale = true;
      cscale = 1.4885657073574029E+138;
      xzlascl(anrm, cscale, A.size(0), A.size(1), A, A.size(0));
    }
    if (A.size(1) >= 2) {
      qjj = A.size(1) - 2;
    } else {
      qjj = 0;
    }
    nrt = A.size(0);
    if (qjj <= nrt) {
      nrt = qjj;
    }
    if (A.size(0) >= 1) {
      qjj = A.size(0) - 1;
    } else {
      qjj = 0;
    }
    nct = A.size(1);
    if (qjj <= nct) {
      nct = qjj;
    }
    nctp1 = nct + 1;
    if (nct >= nrt) {
      b_ii = nct;
    } else {
      b_ii = nrt;
    }
    for (int ii{0}; ii < b_ii; ii++) {
      boolean_T apply_transform;
      qp1 = ii + 2;
      qq = (ii + n * ii) + 1;
      nmq = n - ii;
      apply_transform = false;
      if (ii + 1 <= nct) {
        nrm = blas::xnrm2(nmq, A, qq);
        if (nrm > 0.0) {
          apply_transform = true;
          c = A[qq - 1].re;
          emm1 = A[qq - 1].im;
          if ((c == 0.0) && (emm1 == 0.0)) {
            b_e.re = nrm;
            b_e.im = 0.0;
            s[ii] = b_e;
          } else {
            nrm /= b_abs(A[qq - 1]);
            b_e.re = nrm * c;
            b_e.im = nrm * emm1;
            s[ii] = b_e;
          }
          if (b_abs(b_e) >= 1.0020841800044864E-292) {
            if (b_e.im == 0.0) {
              r_re = 1.0 / b_e.re;
              r_im = 0.0;
            } else if (b_e.re == 0.0) {
              r_re = 0.0;
              r_im = -(1.0 / b_e.im);
            } else {
              emm1 = std::abs(b_e.re);
              nrm = std::abs(b_e.im);
              if (emm1 > nrm) {
                nrm = b_e.im / b_e.re;
                c = b_e.re + nrm * b_e.im;
                r_re = (nrm * 0.0 + 1.0) / c;
                r_im = (0.0 - nrm) / c;
              } else if (nrm == emm1) {
                if (b_e.re > 0.0) {
                  c = 0.5;
                } else {
                  c = -0.5;
                }
                r_re = c / emm1;
                if (b_e.im > 0.0) {
                  nrm = 0.5;
                } else {
                  nrm = -0.5;
                }
                r_im = (0.0 * c - nrm) / emm1;
              } else {
                nrm = b_e.re / b_e.im;
                c = b_e.im + nrm * b_e.re;
                r_re = nrm / c;
                r_im = (nrm * 0.0 - 1.0) / c;
              }
            }
            ns = qq + nmq;
            for (int i{qq}; i < ns; i++) {
              c = A[i - 1].im;
              nrm = A[i - 1].re;
              A[i - 1].re = r_re * nrm - r_im * c;
              A[i - 1].im = r_re * c + r_im * nrm;
            }
          } else {
            ns = qq + nmq;
            for (int i{qq}; i < ns; i++) {
              rt = A[i - 1].re;
              r_im = A[i - 1].im;
              emm1 = s[ii].re;
              b = s[ii].im;
              if (b == 0.0) {
                if (r_im == 0.0) {
                  sm = rt / emm1;
                  nrm = 0.0;
                } else if (rt == 0.0) {
                  sm = 0.0;
                  nrm = r_im / emm1;
                } else {
                  sm = rt / emm1;
                  nrm = r_im / emm1;
                }
              } else if (emm1 == 0.0) {
                if (rt == 0.0) {
                  sm = r_im / b;
                  nrm = 0.0;
                } else if (r_im == 0.0) {
                  sm = 0.0;
                  nrm = -(rt / b);
                } else {
                  sm = r_im / b;
                  nrm = -(rt / b);
                }
              } else {
                sqds = std::abs(emm1);
                c = std::abs(b);
                if (sqds > c) {
                  nrm = b / emm1;
                  c = emm1 + nrm * b;
                  sm = (rt + nrm * r_im) / c;
                  nrm = (r_im - nrm * rt) / c;
                } else if (c == sqds) {
                  if (emm1 > 0.0) {
                    nrm = 0.5;
                  } else {
                    nrm = -0.5;
                  }
                  if (b > 0.0) {
                    c = 0.5;
                  } else {
                    c = -0.5;
                  }
                  sm = (rt * nrm + r_im * c) / sqds;
                  nrm = (r_im * nrm - rt * c) / sqds;
                } else {
                  nrm = emm1 / b;
                  c = b + nrm * emm1;
                  sm = (nrm * rt + r_im) / c;
                  nrm = (nrm * r_im - rt) / c;
                }
              }
              A[i - 1].re = sm;
              A[i - 1].im = nrm;
            }
          }
          A[qq - 1].re = A[qq - 1].re + 1.0;
          s[ii].re = -s[ii].re;
          s[ii].im = -s[ii].im;
        } else {
          s[ii].re = 0.0;
          s[ii].im = 0.0;
        }
      }
      for (int i{qp1}; i <= p; i++) {
        qjj = ii + n * (i - 1);
        if (apply_transform) {
          b_e = blas::xdotc(nmq, A, qq, A, qjj + 1);
          ns = ii + A.size(0) * ii;
          nrm = A[ns].re;
          emm1 = A[ns].im;
          if (emm1 == 0.0) {
            if (b_e.im == 0.0) {
              sqds = b_e.re / nrm;
              nrm = 0.0;
            } else if (b_e.re == 0.0) {
              sqds = 0.0;
              nrm = b_e.im / nrm;
            } else {
              sqds = b_e.re / nrm;
              nrm = b_e.im / nrm;
            }
          } else if (nrm == 0.0) {
            if (b_e.re == 0.0) {
              sqds = b_e.im / emm1;
              nrm = 0.0;
            } else if (b_e.im == 0.0) {
              sqds = 0.0;
              nrm = -(b_e.re / emm1);
            } else {
              sqds = b_e.im / emm1;
              nrm = -(b_e.re / emm1);
            }
          } else {
            b = std::abs(nrm);
            c = std::abs(emm1);
            if (b > c) {
              c = emm1 / nrm;
              nrm += c * emm1;
              sqds = (b_e.re + c * b_e.im) / nrm;
              nrm = (b_e.im - c * b_e.re) / nrm;
            } else if (c == b) {
              if (nrm > 0.0) {
                nrm = 0.5;
              } else {
                nrm = -0.5;
              }
              if (emm1 > 0.0) {
                c = 0.5;
              } else {
                c = -0.5;
              }
              sqds = (b_e.re * nrm + b_e.im * c) / b;
              nrm = (b_e.im * nrm - b_e.re * c) / b;
            } else {
              c = nrm / emm1;
              nrm = emm1 + c * nrm;
              sqds = (c * b_e.re + b_e.im) / nrm;
              nrm = (c * b_e.im - b_e.re) / nrm;
            }
          }
          b_e.re = -sqds;
          b_e.im = -nrm;
          blas::xaxpy(nmq, b_e, qq, A, qjj + 1);
        }
        e[i - 1].re = A[qjj].re;
        e[i - 1].im = -A[qjj].im;
      }
      if (ii + 1 <= nct) {
        for (int i{ii + 1}; i <= n; i++) {
          U[(i + U.size(0) * ii) - 1] = A[(i + A.size(0) * ii) - 1];
        }
      }
      if (ii + 1 <= nrt) {
        qq = p - ii;
        nrm = blas::xnrm2(qq - 1, e, ii + 2);
        if (nrm == 0.0) {
          e[ii].re = 0.0;
          e[ii].im = 0.0;
        } else {
          c = e[ii + 1].re;
          if ((c == 0.0) && (e[ii + 1].im == 0.0)) {
            e[ii].re = nrm;
            e[ii].im = 0.0;
          } else {
            nrm /= b_abs(e[ii + 1]);
            e[ii].re = nrm * c;
            e[ii].im = nrm * e[ii + 1].im;
          }
          r_im = e[ii].re;
          rt = e[ii].im;
          if (b_abs(e[ii]) >= 1.0020841800044864E-292) {
            if (rt == 0.0) {
              r_re = 1.0 / r_im;
              r_im = 0.0;
            } else if (r_im == 0.0) {
              r_re = 0.0;
              r_im = -(1.0 / rt);
            } else {
              emm1 = std::abs(r_im);
              c = std::abs(rt);
              if (emm1 > c) {
                c = rt / r_im;
                nrm = r_im + c * rt;
                r_re = (c * 0.0 + 1.0) / nrm;
                r_im = (0.0 - c) / nrm;
              } else if (c == emm1) {
                if (r_im > 0.0) {
                  nrm = 0.5;
                } else {
                  nrm = -0.5;
                }
                r_re = nrm / emm1;
                if (rt > 0.0) {
                  c = 0.5;
                } else {
                  c = -0.5;
                }
                r_im = (0.0 * nrm - c) / emm1;
              } else {
                c = r_im / rt;
                nrm = rt + c * r_im;
                r_re = c / nrm;
                r_im = (c * 0.0 - 1.0) / nrm;
              }
            }
            ns = ii + qq;
            for (int i{qp1}; i <= ns; i++) {
              c = e[i - 1].im;
              nrm = e[i - 1].re;
              e[i - 1].re = r_re * nrm - r_im * c;
              e[i - 1].im = r_re * c + r_im * nrm;
            }
          } else {
            ns = ii + qq;
            for (int i{qp1}; i <= ns; i++) {
              b = e[i - 1].re;
              sm = e[i - 1].im;
              if (rt == 0.0) {
                if (sm == 0.0) {
                  sqds = b / r_im;
                  c = 0.0;
                } else if (b == 0.0) {
                  sqds = 0.0;
                  c = sm / r_im;
                } else {
                  sqds = b / r_im;
                  c = sm / r_im;
                }
              } else if (r_im == 0.0) {
                if (b == 0.0) {
                  sqds = sm / rt;
                  c = 0.0;
                } else if (sm == 0.0) {
                  sqds = 0.0;
                  c = -(b / rt);
                } else {
                  sqds = sm / rt;
                  c = -(b / rt);
                }
              } else {
                emm1 = std::abs(r_im);
                c = std::abs(rt);
                if (emm1 > c) {
                  c = rt / r_im;
                  nrm = r_im + c * rt;
                  sqds = (b + c * sm) / nrm;
                  c = (sm - c * b) / nrm;
                } else if (c == emm1) {
                  if (r_im > 0.0) {
                    c = 0.5;
                  } else {
                    c = -0.5;
                  }
                  if (rt > 0.0) {
                    nrm = 0.5;
                  } else {
                    nrm = -0.5;
                  }
                  sqds = (b * c + sm * nrm) / emm1;
                  c = (sm * c - b * nrm) / emm1;
                } else {
                  c = r_im / rt;
                  nrm = rt + c * r_im;
                  sqds = (c * b + sm) / nrm;
                  c = (c * sm - b) / nrm;
                }
              }
              e[i - 1].re = sqds;
              e[i - 1].im = c;
            }
          }
          e[ii + 1].re = e[ii + 1].re + 1.0;
          e[ii].re = -e[ii].re;
          if (ii + 2 <= n) {
            if (qp1 <= n) {
              std::memset(&work[qp1 + -1], 0,
                          static_cast<unsigned int>((n - qp1) + 1) *
                              sizeof(creal_T));
            }
            for (int i{qp1}; i <= p; i++) {
              blas::xaxpy(nmq - 1, e[i - 1], A, (ii + n * (i - 1)) + 2, work,
                          ii + 2);
            }
            for (int i{qp1}; i <= p; i++) {
              rt = -e[i - 1].re;
              r_im = -e[i - 1].im;
              emm1 = e[ii + 1].re;
              b = e[ii + 1].im;
              if (b == 0.0) {
                if (r_im == 0.0) {
                  sm = rt / emm1;
                  nrm = 0.0;
                } else if (rt == 0.0) {
                  sm = 0.0;
                  nrm = r_im / emm1;
                } else {
                  sm = rt / emm1;
                  nrm = r_im / emm1;
                }
              } else if (emm1 == 0.0) {
                if (rt == 0.0) {
                  sm = r_im / b;
                  nrm = 0.0;
                } else if (r_im == 0.0) {
                  sm = 0.0;
                  nrm = -(rt / b);
                } else {
                  sm = r_im / b;
                  nrm = -(rt / b);
                }
              } else {
                sqds = std::abs(emm1);
                c = std::abs(b);
                if (sqds > c) {
                  nrm = b / emm1;
                  c = emm1 + nrm * b;
                  sm = (rt + nrm * r_im) / c;
                  nrm = (r_im - nrm * rt) / c;
                } else if (c == sqds) {
                  if (emm1 > 0.0) {
                    nrm = 0.5;
                  } else {
                    nrm = -0.5;
                  }
                  if (b > 0.0) {
                    c = 0.5;
                  } else {
                    c = -0.5;
                  }
                  sm = (rt * nrm + r_im * c) / sqds;
                  nrm = (r_im * nrm - rt * c) / sqds;
                } else {
                  nrm = emm1 / b;
                  c = b + nrm * emm1;
                  sm = (nrm * rt + r_im) / c;
                  nrm = (nrm * r_im - rt) / c;
                }
              }
              b_e.re = sm;
              b_e.im = -nrm;
              blas::xaxpy(nmq - 1, b_e, work, ii + 2, A,
                          (ii + n * (i - 1)) + 2);
            }
          }
        }
        for (int i{qp1}; i <= p; i++) {
          Vf[(i + Vf.size(0) * ii) - 1] = e[i - 1];
        }
      }
    }
    if (A.size(1) <= A.size(0) + 1) {
      m = A.size(1) - 1;
    } else {
      m = A.size(0);
    }
    if (nct < A.size(1)) {
      s[nct] = A[nct + A.size(0) * nct];
    }
    if (A.size(0) < m + 1) {
      s[m].re = 0.0;
      s[m].im = 0.0;
    }
    if (nrt + 1 < m + 1) {
      e[nrt] = A[nrt + A.size(0) * m];
    }
    e[m].re = 0.0;
    e[m].im = 0.0;
    if (nct + 1 <= minnp) {
      for (int ii{nctp1}; ii <= minnp; ii++) {
        for (int i{0}; i < n; i++) {
          ns = i + U.size(0) * (ii - 1);
          U[ns].re = 0.0;
          U[ns].im = 0.0;
        }
        qjj = (ii + U.size(0) * (ii - 1)) - 1;
        U[qjj].re = 1.0;
        U[qjj].im = 0.0;
      }
    }
    for (int ii{nct}; ii >= 1; ii--) {
      qp1 = ii + 1;
      nmq = n - ii;
      qq = (ii + n * (ii - 1)) - 1;
      if ((s[ii - 1].re != 0.0) || (s[ii - 1].im != 0.0)) {
        for (int i{qp1}; i <= minnp; i++) {
          qjj = ii + n * (i - 1);
          b_e = blas::xdotc(nmq + 1, U, qq + 1, U, qjj);
          nrm = U[qq].re;
          emm1 = U[qq].im;
          if (emm1 == 0.0) {
            if (b_e.im == 0.0) {
              sqds = b_e.re / nrm;
              nrm = 0.0;
            } else if (b_e.re == 0.0) {
              sqds = 0.0;
              nrm = b_e.im / nrm;
            } else {
              sqds = b_e.re / nrm;
              nrm = b_e.im / nrm;
            }
          } else if (nrm == 0.0) {
            if (b_e.re == 0.0) {
              sqds = b_e.im / emm1;
              nrm = 0.0;
            } else if (b_e.im == 0.0) {
              sqds = 0.0;
              nrm = -(b_e.re / emm1);
            } else {
              sqds = b_e.im / emm1;
              nrm = -(b_e.re / emm1);
            }
          } else {
            b = std::abs(nrm);
            c = std::abs(emm1);
            if (b > c) {
              c = emm1 / nrm;
              nrm += c * emm1;
              sqds = (b_e.re + c * b_e.im) / nrm;
              nrm = (b_e.im - c * b_e.re) / nrm;
            } else if (c == b) {
              if (nrm > 0.0) {
                nrm = 0.5;
              } else {
                nrm = -0.5;
              }
              if (emm1 > 0.0) {
                c = 0.5;
              } else {
                c = -0.5;
              }
              sqds = (b_e.re * nrm + b_e.im * c) / b;
              nrm = (b_e.im * nrm - b_e.re * c) / b;
            } else {
              c = nrm / emm1;
              nrm = emm1 + c * nrm;
              sqds = (c * b_e.re + b_e.im) / nrm;
              nrm = (c * b_e.im - b_e.re) / nrm;
            }
          }
          b_e.re = -sqds;
          b_e.im = -nrm;
          blas::xaxpy(nmq + 1, b_e, qq + 1, U, qjj);
        }
        for (int i{ii}; i <= n; i++) {
          ns = (i + U.size(0) * (ii - 1)) - 1;
          U[ns].re = -U[ns].re;
          U[ns].im = -U[ns].im;
        }
        U[qq].re = U[qq].re + 1.0;
        for (int i{0}; i <= ii - 2; i++) {
          qjj = i + U.size(0) * (ii - 1);
          U[qjj].re = 0.0;
          U[qjj].im = 0.0;
        }
      } else {
        for (int i{0}; i < n; i++) {
          ns = i + U.size(0) * (ii - 1);
          U[ns].re = 0.0;
          U[ns].im = 0.0;
        }
        U[qq].re = 1.0;
        U[qq].im = 0.0;
      }
    }
    for (int ii{p}; ii >= 1; ii--) {
      if ((ii <= nrt) && ((e[ii - 1].re != 0.0) || (e[ii - 1].im != 0.0))) {
        qp1 = ii + 1;
        qq = p - ii;
        ns = (ii + p * (ii - 1)) + 1;
        for (int i{qp1}; i <= p; i++) {
          qjj = (ii + p * (i - 1)) + 1;
          b_e = blas::xdotc(qq, Vf, ns, Vf, qjj);
          nrm = Vf[ns - 1].re;
          emm1 = Vf[ns - 1].im;
          if (emm1 == 0.0) {
            if (b_e.im == 0.0) {
              sqds = b_e.re / nrm;
              nrm = 0.0;
            } else if (b_e.re == 0.0) {
              sqds = 0.0;
              nrm = b_e.im / nrm;
            } else {
              sqds = b_e.re / nrm;
              nrm = b_e.im / nrm;
            }
          } else if (nrm == 0.0) {
            if (b_e.re == 0.0) {
              sqds = b_e.im / emm1;
              nrm = 0.0;
            } else if (b_e.im == 0.0) {
              sqds = 0.0;
              nrm = -(b_e.re / emm1);
            } else {
              sqds = b_e.im / emm1;
              nrm = -(b_e.re / emm1);
            }
          } else {
            b = std::abs(nrm);
            c = std::abs(emm1);
            if (b > c) {
              c = emm1 / nrm;
              nrm += c * emm1;
              sqds = (b_e.re + c * b_e.im) / nrm;
              nrm = (b_e.im - c * b_e.re) / nrm;
            } else if (c == b) {
              if (nrm > 0.0) {
                nrm = 0.5;
              } else {
                nrm = -0.5;
              }
              if (emm1 > 0.0) {
                c = 0.5;
              } else {
                c = -0.5;
              }
              sqds = (b_e.re * nrm + b_e.im * c) / b;
              nrm = (b_e.im * nrm - b_e.re * c) / b;
            } else {
              c = nrm / emm1;
              nrm = emm1 + c * nrm;
              sqds = (c * b_e.re + b_e.im) / nrm;
              nrm = (c * b_e.im - b_e.re) / nrm;
            }
          }
          b_e.re = -sqds;
          b_e.im = -nrm;
          blas::xaxpy(qq, b_e, ns, Vf, qjj);
        }
      }
      for (int i{0}; i < p; i++) {
        qjj = i + Vf.size(0) * (ii - 1);
        Vf[qjj].re = 0.0;
        Vf[qjj].im = 0.0;
      }
      qjj = (ii + Vf.size(0) * (ii - 1)) - 1;
      Vf[qjj].re = 1.0;
      Vf[qjj].im = 0.0;
    }
    nctp1 = m;
    nmq = 0;
    snorm = 0.0;
    for (int ii{0}; ii <= m; ii++) {
      c = s[ii].re;
      nrm = s[ii].im;
      if ((c != 0.0) || (nrm != 0.0)) {
        rt = b_abs(s[ii]);
        if (nrm == 0.0) {
          r_re = c / rt;
          r_im = 0.0;
        } else if (c == 0.0) {
          r_re = 0.0;
          r_im = nrm / rt;
        } else {
          r_re = c / rt;
          r_im = nrm / rt;
        }
        s[ii].re = rt;
        s[ii].im = 0.0;
        if (ii + 1 < m + 1) {
          sm = e[ii].re;
          rt = e[ii].im;
          if (r_im == 0.0) {
            if (rt == 0.0) {
              b = sm / r_re;
              c = 0.0;
            } else if (sm == 0.0) {
              b = 0.0;
              c = rt / r_re;
            } else {
              b = sm / r_re;
              c = rt / r_re;
            }
          } else if (r_re == 0.0) {
            if (sm == 0.0) {
              b = rt / r_im;
              c = 0.0;
            } else if (rt == 0.0) {
              b = 0.0;
              c = -(sm / r_im);
            } else {
              b = rt / r_im;
              c = -(sm / r_im);
            }
          } else {
            sqds = std::abs(r_re);
            c = std::abs(r_im);
            if (sqds > c) {
              c = r_im / r_re;
              nrm = r_re + c * r_im;
              b = (sm + c * rt) / nrm;
              c = (rt - c * sm) / nrm;
            } else if (c == sqds) {
              if (r_re > 0.0) {
                nrm = 0.5;
              } else {
                nrm = -0.5;
              }
              if (r_im > 0.0) {
                emm1 = 0.5;
              } else {
                emm1 = -0.5;
              }
              b = (sm * nrm + rt * emm1) / sqds;
              c = (rt * nrm - sm * emm1) / sqds;
            } else {
              c = r_re / r_im;
              nrm = r_im + c * r_re;
              b = (c * sm + rt) / nrm;
              c = (c * rt - sm) / nrm;
            }
          }
          e[ii].re = b;
          e[ii].im = c;
        }
        if (ii + 1 <= n) {
          ns = n * ii;
          qjj = ns + n;
          for (int i{ns + 1}; i <= qjj; i++) {
            c = U[i - 1].im;
            nrm = U[i - 1].re;
            U[i - 1].re = r_re * nrm - r_im * c;
            U[i - 1].im = r_re * c + r_im * nrm;
          }
        }
      }
      if (ii + 1 < m + 1) {
        nrm = e[ii].re;
        b = e[ii].im;
        if ((nrm != 0.0) || (b != 0.0)) {
          rt = b_abs(e[ii]);
          if (b == 0.0) {
            r_re = rt / nrm;
            r_im = 0.0;
          } else if (nrm == 0.0) {
            if (rt == 0.0) {
              r_re = 0.0 / b;
              r_im = 0.0;
            } else {
              r_re = 0.0;
              r_im = -(rt / b);
            }
          } else {
            emm1 = std::abs(nrm);
            c = std::abs(b);
            if (emm1 > c) {
              emm1 = b / nrm;
              c = nrm + emm1 * b;
              r_re = (rt + emm1 * 0.0) / c;
              r_im = (0.0 - emm1 * rt) / c;
            } else if (c == emm1) {
              if (nrm > 0.0) {
                nrm = 0.5;
              } else {
                nrm = -0.5;
              }
              r_re = rt * nrm / emm1;
              if (b > 0.0) {
                c = 0.5;
              } else {
                c = -0.5;
              }
              r_im = (0.0 * nrm - rt * c) / emm1;
            } else {
              emm1 = nrm / b;
              c = b + emm1 * nrm;
              r_re = emm1 * rt / c;
              r_im = (emm1 * 0.0 - rt) / c;
            }
          }
          e[ii].re = rt;
          e[ii].im = 0.0;
          c = s[ii + 1].re;
          nrm = s[ii + 1].im;
          s[ii + 1].re = c * r_re - nrm * r_im;
          s[ii + 1].im = c * r_im + nrm * r_re;
          ns = p * (ii + 1);
          qjj = ns + p;
          for (int i{ns + 1}; i <= qjj; i++) {
            c = Vf[i - 1].im;
            nrm = Vf[i - 1].re;
            Vf[i - 1].re = r_re * nrm - r_im * c;
            Vf[i - 1].im = r_re * c + r_im * nrm;
          }
        }
      }
      snorm =
          std::fmax(snorm, std::fmax(std::abs(s[ii].re), std::abs(e[ii].re)));
    }
    while ((m + 1 > 0) && (nmq < 75)) {
      boolean_T exitg1;
      b_ii = m;
      exitg1 = false;
      while (!(exitg1 || (b_ii == 0))) {
        nrm = std::abs(e[b_ii - 1].re);
        if ((nrm <= 2.2204460492503131E-16 *
                        (std::abs(s[b_ii - 1].re) + std::abs(s[b_ii].re))) ||
            (nrm <= 1.0020841800044864E-292) ||
            ((nmq > 20) && (nrm <= 2.2204460492503131E-16 * snorm))) {
          e[b_ii - 1].re = 0.0;
          e[b_ii - 1].im = 0.0;
          exitg1 = true;
        } else {
          b_ii--;
        }
      }
      if (b_ii == m) {
        qjj = 4;
      } else {
        qq = m + 1;
        ns = m + 1;
        exitg1 = false;
        while ((!exitg1) && (ns >= b_ii)) {
          qq = ns;
          if (ns == b_ii) {
            exitg1 = true;
          } else {
            nrm = 0.0;
            if (ns < m + 1) {
              nrm = std::abs(e[ns - 1].re);
            }
            if (ns > b_ii + 1) {
              nrm += std::abs(e[ns - 2].re);
            }
            c = std::abs(s[ns - 1].re);
            if ((c <= 2.2204460492503131E-16 * nrm) ||
                (c <= 1.0020841800044864E-292)) {
              s[ns - 1].re = 0.0;
              s[ns - 1].im = 0.0;
              exitg1 = true;
            } else {
              ns--;
            }
          }
        }
        if (qq == b_ii) {
          qjj = 3;
        } else if (qq == m + 1) {
          qjj = 1;
        } else {
          qjj = 2;
          b_ii = qq;
        }
      }
      switch (qjj) {
      case 1:
        r_re = e[m - 1].re;
        e[m - 1].re = 0.0;
        e[m - 1].im = 0.0;
        for (int i{m}; i >= b_ii + 1; i--) {
          c = s[i - 1].re;
          emm1 = blas::xrotg(c, r_re, nrm);
          s[i - 1].re = c;
          s[i - 1].im = 0.0;
          if (i > b_ii + 1) {
            c = e[i - 2].re;
            r_re = -nrm * c;
            e[i - 2].re = emm1 * c;
            e[i - 2].im = emm1 * e[i - 2].im;
          }
          blas::xrot(p, Vf, p * (i - 1) + 1, p * m + 1, emm1, nrm);
        }
        break;
      case 2:
        r_re = e[b_ii - 1].re;
        e[b_ii - 1].re = 0.0;
        e[b_ii - 1].im = 0.0;
        for (int i{b_ii + 1}; i <= m + 1; i++) {
          c = s[i - 1].re;
          emm1 = blas::xrotg(c, r_re, nrm);
          s[i - 1].re = c;
          s[i - 1].im = 0.0;
          c = e[i - 1].re;
          r_re = -nrm * c;
          e[i - 1].re = emm1 * c;
          e[i - 1].im = emm1 * e[i - 1].im;
          blas::xrot(n, U, n * (i - 1) + 1, n * (b_ii - 1) + 1, emm1, nrm);
        }
        break;
      case 3:
        c = s[m].re;
        nrm = s[m - 1].re;
        emm1 = e[m - 1].re;
        sqds = s[b_ii].re;
        rt = e[b_ii].re;
        r_im =
            std::fmax(std::fmax(std::fmax(std::fmax(std::abs(c), std::abs(nrm)),
                                          std::abs(emm1)),
                                std::abs(sqds)),
                      std::abs(rt));
        sm = c / r_im;
        nrm /= r_im;
        emm1 /= r_im;
        sqds /= r_im;
        b = ((nrm + sm) * (nrm - sm) + emm1 * emm1) / 2.0;
        c = sm * emm1;
        c *= c;
        if ((b != 0.0) || (c != 0.0)) {
          nrm = std::sqrt(b * b + c);
          if (b < 0.0) {
            nrm = -nrm;
          }
          nrm = c / (b + nrm);
        } else {
          nrm = 0.0;
        }
        r_re = (sqds + sm) * (sqds - sm) + nrm;
        nrm = sqds * (rt / r_im);
        for (int i{b_ii + 1}; i <= m; i++) {
          emm1 = blas::xrotg(r_re, nrm, rt);
          if (i > b_ii + 1) {
            e[i - 2].re = r_re;
            e[i - 2].im = 0.0;
          }
          c = e[i - 1].re;
          nrm = s[i - 1].re;
          r_im = emm1 * nrm + rt * c;
          e[i - 1].re = emm1 * c - rt * nrm;
          e[i - 1].im = emm1 * e[i - 1].im - rt * s[i - 1].im;
          c = s[i].re;
          nrm = rt * c;
          b = emm1 * c;
          sm = emm1 * s[i].im;
          blas::xrot(p, Vf, p * (i - 1) + 1, p * i + 1, emm1, rt);
          sqds = blas::xrotg(r_im, nrm, emm1);
          s[i - 1].re = r_im;
          s[i - 1].im = 0.0;
          c = e[i - 1].re;
          r_re = sqds * c + emm1 * b;
          b = -emm1 * c + sqds * b;
          sm = -emm1 * e[i - 1].im + sqds * sm;
          s[i].re = b;
          s[i].im = sm;
          c = e[i].re;
          nrm = emm1 * c;
          e[i].re = sqds * c;
          e[i].im = sqds * e[i].im;
          if (i < n) {
            blas::xrot(n, U, n * (i - 1) + 1, n * i + 1, sqds, emm1);
          }
        }
        e[m - 1].re = r_re;
        e[m - 1].im = 0.0;
        nmq++;
        break;
      default:
        if (s[b_ii].re < 0.0) {
          s[b_ii].re = -s[b_ii].re;
          s[b_ii].im = 0.0;
          ns = p * b_ii;
          qjj = ns + p;
          for (int i{ns + 1}; i <= qjj; i++) {
            nrm = Vf[i - 1].im;
            c = Vf[i - 1].re;
            Vf[i - 1].re = -c - 0.0 * nrm;
            Vf[i - 1].im = -nrm + 0.0 * c;
          }
        }
        qp1 = b_ii + 1;
        while ((b_ii + 1 < nctp1 + 1) && (s[b_ii].re < s[qp1].re)) {
          rt = s[b_ii].re;
          s[b_ii].re = s[qp1].re;
          s[b_ii].im = 0.0;
          s[qp1].re = rt;
          s[qp1].im = 0.0;
          if (b_ii + 1 < p) {
            blas::xswap(p, Vf, p * b_ii + 1, p * (b_ii + 1) + 1);
          }
          if (b_ii + 1 < n) {
            blas::xswap(n, U, n * b_ii + 1, n * (b_ii + 1) + 1);
          }
          b_ii = qp1;
          qp1++;
        }
        nmq = 0;
        m--;
        break;
      }
    }
  }
  S.set_size(minnp);
  for (int ii{0}; ii < minnp; ii++) {
    S[ii] = s[ii].re;
  }
  if (doscale) {
    xzlascl(cscale, anrm, minnp, S);
  }
  V.set_size(A.size(1), minnp);
  for (int ii{0}; ii < minnp; ii++) {
    for (int i{0}; i < p; i++) {
      V[i + V.size(0) * ii] = Vf[i + Vf.size(0) * ii];
    }
  }
}

} // namespace reflapack
} // namespace internal
} // namespace coder

//
// File trailer for xzsvdc.cpp
//
// [EOF]
//
