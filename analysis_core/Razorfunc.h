// Razor recipe taken from the RazorBoost gurus: N. Strobbe, S. Sekmen
// also info here:
//   https://twiki.cern.ch/twiki/bin/view/CMSPublic/RazorLikelihoodHowTo
#include "TLorentzVector.h"

  // Hemispheres:
std::vector<TLorentzVector> fmegajets(std::vector<TLorentzVector> myjets, int p1);

  // MR
double fMR(std::vector<TLorentzVector> j);

  // MTR
double fMTR(std::vector<TLorentzVector> j, TVector2 amet);
double fMTR2(std::vector<TLorentzVector> j, TLorentzVector amet);
  
  // MT
double fMT(std::vector<TLorentzVector> v);
