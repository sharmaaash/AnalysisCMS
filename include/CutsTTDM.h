#if !defined(MYLIB_CUTSTTDM_H)
#define MYLIB_CUTSTTDM_H 1

#include "TString.h"


enum {
  TTDM_00_Has2Leptons,
  TTDM_01_ZVeto,
  TTDM_02_MET50,
  TTDM_03_Preselection,
  TTDM_04_AN16105,
  ncut  // This line should be always last
};

const TString scut[ncut] = {
  "TTDM/00_Has2Leptons",
  "TTDM/01_ZVeto",
  "TTDM/02_MET50",
  "TTDM/03_Preselection",
  "TTDM/03_AN16105"
};

#endif
