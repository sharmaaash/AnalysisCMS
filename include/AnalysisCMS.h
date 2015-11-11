#ifndef AnalysisCMS_h
#define AnalysisCMS_h

#include "AnalysisBase.h"
#include "Constants.h"

#include <fstream>
#include <iostream>
#include <TH1.h>
#include <TLorentzVector.h>
#include <TString.h>
#include <TStyle.h>
#include <TSystem.h>
#include <TTree.h>


// verbosity = 0 (silent)  doesn't print anything
// verbosity > 0 (default) prints the input values and "." every <interval> events
// verbosity > 1 (debug)
const int verbosity = 1;
const int interval  = 10000;


enum {Loose, Tight};

struct Lepton
{
  int            index;
  int            type;  // Loose, Tight
  int            flavour;
  float          iso;
  float          dxy;   // Tighter IP when requiring fabs(dxy) < 0.02
  float          dz;    // Tighter IP when requiring fabs(dz)  < 0.10
  TLorentzVector v;
};

struct Jet
{
  int            index;
  float          csvv2ivf;
  TLorentzVector v;
};


class AnalysisCMS : public AnalysisBase
{
 public :

 AnalysisCMS(TTree *tree=0) : AnalysisBase(tree) {}

  float   MuonIsolation    (int     k);

  float   ElectronIsolation(int     k);

  bool    IsFiducialLepton (int     k);

  bool    IsTightLepton    (int     k);

  bool    IsIsolatedLepton (int     k);

  void    LevelHistograms  (int     icut,
			    bool    pass);

  void    FillHistograms   (int     ichannel,
			    int     icut,
			    int     ijet);

  void    Loop             (TString sample,
			    TString era,
			    float   luminosity);

  void    Summary          (TString analysis,
			    TString precision,
			    TString title);

  void    GetSampleName    (TString filename);

  void    ApplyWeights     (TString sample,
			    TString era,
			    float   luminosity);

  void    GetLeptons       ();

  void    GetJets          ();

  void    AnalysisWW       ();  // Alberto, Nicolo, Alicia

  void    AnalysisWZ       ();  // Cedric, Jonatan

  void    AnalysisTop      ();  // Barbara, Rocio


  // Data members
  //----------------------------------------------------------------------------
  std::vector<Jet>       AnalysisJets;
  std::vector<Lepton>    AnalysisLeptons;
  Lepton                 Lepton1;   // For WW and Top analyses
  Lepton                 Lepton2;   // For WW and Top analyses
  Lepton                 WLepton;   // For WZ analysis
  Lepton                 ZLepton1;  // For WZ analysis
  Lepton                 ZLepton2;  // For WZ analysis

  TString                _sample;
  bool                   _ismc;
  float                  _event_weight;
  float                  _ht;
  float                  _pt2l;
  float                  _m2l;
  float                  _m3l;
  int                    _channel;
  unsigned int           _nelectron;
  unsigned int           _nlepton;
  unsigned int           _ntight;
  unsigned int           _njet;
  unsigned int           _nbjet;
  unsigned int           _jetbin;
  
  ofstream               txt_summary;
  TFile*                 root_output;


  // Common histograms
  //----------------------------------------------------------------------------
  TH1D*                  h_counterRaw[nchannel][ncut][njetbin+1];
  TH1D*                  h_counterLum[nchannel][ncut][njetbin+1];
  TH1D*                  h_ht        [nchannel][ncut][njetbin+1];
  TH1D*                  h_m2l       [nchannel][ncut][njetbin+1];
  TH1D*                  h_njet      [nchannel][ncut][njetbin+1];
  TH1D*                  h_nbjet     [nchannel][ncut][njetbin+1];
  TH1D*                  h_nvtx      [nchannel][ncut][njetbin+1];
  TH1D*                  h_pfType1Met[nchannel][ncut][njetbin+1];


  // WZ histograms
  //----------------------------------------------------------------------------
  TH1D*                  h_m3l         [nchannel][ncut][njetbin+1];
  TH1D*                  h_zl1pt       [nchannel][ncut][njetbin+1];
  TH1D*                  h_zl2pt       [nchannel][ncut][njetbin+1];
  TH1D*                  h_wlpt        [nchannel][ncut][njetbin+1];
  TH1D*                  h_zl1eta      [nchannel][ncut][njetbin+1];
  TH1D*                  h_zl2eta      [nchannel][ncut][njetbin+1];
  TH1D*                  h_wleta       [nchannel][ncut][njetbin+1];
  TH1D*                  h_wlzl1_deltar[nchannel][ncut][njetbin+1];
  TH1D*                  h_wlzl2_deltar[nchannel][ncut][njetbin+1];
  TH1D*                  h_wlzl_deltar [nchannel][ncut][njetbin+1];
};

#endif