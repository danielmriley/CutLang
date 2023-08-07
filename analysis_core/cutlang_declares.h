#ifndef CUTLANGDEC_H
#define CUTLANGDEC_H

#include <vector>
#include <list>
#include <map>
#include <utility>
#include <string>

#include "myParticle.h"
#include "Node.h"
#include "ValueNode.h"
#include "BinaryNode.hpp"
#include "TableNode.h"
#include "UnaryAONode.h"
#include "FuncNode.h"
#include "LFuncNode.h"
#include "SFuncNode.h"
#include "HistoNode.h"
#include "SearchNode.h"
#include "SortNode.h"
#include "IfNode.h"
#include "LoopNode.h"
#include "ObjectNode.hpp"
#include "SaveNode.h"
#include "Razorfunc.h"

// namespace adl {
  // class TLorentzVector;
  // class AnalysisObjects;
  // class TVector2;
  // class dbxParticle;

  typedef double (*UnFunction)(double);
  typedef double (*LFunction)(dbxParticle*,dbxParticle*);
  typedef double (*PropFunction)(dbxParticle*);
  typedef double (*SFunction)(AnalysisObjects*, std::string, float);

  // struct myParticle;
  // class Node;
  // class BinaryNode;
  // class UnaryAONode;
  // class FuncNode;
  // class LoopNode;
  // class LFuncNode;
  // class SFuncNode;
  // class ObjectNode;
  // class ValueNode;
  // class IfNode ;
  // struct cntHisto;

  // enum particleType{
  //  none_t=0,
  //  electron_t=1,
  //  jet_t=2,
  //  bjet_t=3,
  //  lightjet_t=4,
  //  muonlikeV_t=5,
  //  electronlikeV_t=6,
  //  pureV_t=7,
  //  photon_t=8,
  //  fjet_t=9,
  //  truth_t=10,
  //  tau_t=11,
  //  muon_t=12,
  //  track_t=19,
  //  combo_t=20,
  //  consti_t=21
  // };

  // extern int cutcount;
  // extern int bincount;
  // static std::string tmp;
  // static int pnum;
  // static int dnum;
  // static int objIndex = 6213;
  // static std::vector<float> tmpBinlist;
  // static std::vector<float> tmpBoxlist;
  // static std::vector<myParticle*> CombiParticle;
  // static std::vector<myParticle*> TmpParticle;
  // static std::vector<myParticle*> AliasList;
  // static std::vector<myParticle*> TmpParticle1;//to be used for list of 2 particles
  // static std::vector<myParticle*> TmpParticle2;//to be used for list of 3 particles
  // static std::vector<Node*> TmpCriteria;
  // static std::vector<Node*> TmpIDList;
  // static std::vector<Node*> VariableList;
  // static std::vector<float> chist_a, chist_stat_p, chist_stat_n, chist_syst_p, chist_syst_n;


  // static std::list<std::string> parts; //for def of particles as given by user
  // static std::map<std::string,Node*> NodeVars;//for variable defintion
  // static std::map<std::string,std::vector<myParticle*> > ListParts;//for particle definition
  // static std::map<std::string,std::pair<std::vector<float>,bool> > ListTables;//for table definition
  // static std::map<std::string, std::vector<cntHisto> > cntHistos;
  // static std::map<int, std::vector<std::string> > systmap;
  // static std::map<int,Node*> NodeCuts;//cuts and histos
  // static std::map<int,Node*> BinCuts;//binning
  // static std::map<std::string,Node*> ObjectCuts;//cuts for user defined objects
  // static std::vector<std::string> NameInitializations;
  // static std::vector<int> TRGValues;
  // static std::vector<double> bincounts;
  // Funcs
  double      specialf( dbxParticle* apart);
  double      Qof( dbxParticle* apart);
  double      Mof( dbxParticle* apart);
  double      Eof( dbxParticle* apart);
  double      Pof( dbxParticle* apart);
  double     Pzof( dbxParticle* apart);
  double     Ptof( dbxParticle* apart);
  double PtConeof( dbxParticle* apart);
  double EtConeof( dbxParticle* apart);
  double AbsEtaof( dbxParticle* apart);
  double    Etaof( dbxParticle* apart);
  double    Rapof( dbxParticle* apart);
  double    Phiof( dbxParticle* apart);
  double 	pdgIDof( dbxParticle* apart);
  double flavorof( dbxParticle* apart);
  double MsoftDof( dbxParticle* apart);
  double  DeepBof( dbxParticle* apart);
  double   isBTag( dbxParticle* apart);
  double isTauTag( dbxParticle* apart);
  double isTight ( dbxParticle* apart);
  double isMedium( dbxParticle* apart);
  double isLoose ( dbxParticle* apart);
  double   tau1of( dbxParticle* apart);
  double   tau2of( dbxParticle* apart);
  double   tau3of( dbxParticle* apart);
  double    dxyof( dbxParticle* apart);
  double   edxyof( dbxParticle* apart);
  double     dzof( dbxParticle* apart);
  double    edzof( dbxParticle* apart);
  double     vxof( dbxParticle* apart);
  double     vyof( dbxParticle* apart);
  double     vzof( dbxParticle* apart);
  double     vtof( dbxParticle* apart);
  double    vtrof( dbxParticle* apart);
  double  sieieof( dbxParticle* apart);
  double sub1btagof( dbxParticle* apart);
  double sub2btagof( dbxParticle* apart);
  double mvalooseof( dbxParticle* apart);
  double mvatightof( dbxParticle* apart);
  double relisoof( dbxParticle* apart);
  double isZcandid ( dbxParticle* apart);
  double relisoallof( dbxParticle* apart);
  double pfreliso03allof( dbxParticle* apart);
  double iddecaymodeof( dbxParticle* apart);
  double idisotightof( dbxParticle* apart);
  double idantieletightof( dbxParticle* apart);
  double idantimutightof( dbxParticle* apart);
  double tightidof( dbxParticle* apart);
  double    puidof( dbxParticle* apart);
  double genpartidxof( dbxParticle* apart);
  double decaymodeof( dbxParticle* apart);
  double tauisoof( dbxParticle* apart);
  double softIdof( dbxParticle* apart);
  double CCountof( dbxParticle* apart);
  double    nbfof( dbxParticle* apart);
  double IsoVarof( dbxParticle* apart);
  double MiniIsoVarof( dbxParticle* apart);
  double averageMuof( dbxParticle* apart);
  double truthMatchProbof( dbxParticle* apart);
  double truthIDof( dbxParticle* apart);
  double truthParentIDof( dbxParticle* apart);
  double IDXof( dbxParticle* apart);

  // LFuncs
  double dR  (dbxParticle* apart,dbxParticle* apart2);
  double dPhi(dbxParticle* apart,dbxParticle* apart2);
  double dEta(dbxParticle* apart,dbxParticle* apart2);

  // SFuncs
  double none(AnalysisObjects* ao, std::string s, float id);
  double all(AnalysisObjects* ao, std::string s, float id);
  double uweight(AnalysisObjects* ao, std::string s, float value);
  double lepsf(AnalysisObjects* ao, std::string s, float value);
  double btagsf(AnalysisObjects* ao, std::string s, float value);
  double xslumicorrsf(AnalysisObjects* ao, std::string s, float value);
  double count(AnalysisObjects* ao, std::string s, float id);
  double getIndex(AnalysisObjects* ao, std::string s, float id); // new internal function
  double met   (AnalysisObjects* ao, std::string s, float id);
  double metsig(AnalysisObjects* ao, std::string s, float id);
  double hlt_iso_mu(AnalysisObjects* ao, std::string s, float id);
  double hlt_trg(AnalysisObjects* ao, std::string s, float id);
  double ht(AnalysisObjects* ao, std::string s, float id);


  // Unary
  double hstep(double x);
  double delta(double x);
  // double abs(double x);
  // double sqrt(double x);
  // double sin(double x);
  // double cos(double x);
  // double tan(double x);
  // double sinh(double x);
  // double cosh(double x);
  // double tanh(double x);
  // double exp(double x);
  // double log(double x);

  double unaryMinu(double left);
  double LogicalNot(double condition);


  // BinaryNode functions
  double add(double left, double right);
  double mult(double left, double right);
  double sub(double left, double right);
  double div(double left, double right);

  //double power ALREADY EXIST
  double lt(double left, double right);
  double le(double left, double right);
  double ge(double left, double right);
  double gt(double left, double right);
  double eq(double left, double right);
  double ne(double left, double right);
  double LogicalAnd(double left, double right);
  double LogicalOr(double left, double right);
  double mnof(double left, double right);
  double mxof(double left, double right);

  // Object creation functions
  void updateParticles( Node* cutIt, std::vector<myParticle *>* particles, int ipart, std::string name);
  int getCollectionSize(int t2, std::string base_collection2, AnalysisObjects *ao );
  void createNewJet   (AnalysisObjects* ao,std::vector<Node*> *criteria,std::vector<myParticle *>* particles, std::string name, std::string basename);
  void createNewFJet  (AnalysisObjects* ao,std::vector<Node*> *criteria,std::vector<myParticle *>* particles, std::string name, std::string basename);
  void createNewEle   (AnalysisObjects* ao,std::vector<Node*> *criteria,std::vector<myParticle *>* particles, std::string name, std::string basename);
  void createNewMuo   (AnalysisObjects* ao,std::vector<Node*> *criteria,std::vector<myParticle *>* particles, std::string name, std::string basename);
  void createNewTau   (AnalysisObjects* ao,std::vector<Node*> *criteria,std::vector<myParticle *>* particles, std::string name, std::string basename);
  void createNewPho   (AnalysisObjects* ao,std::vector<Node*> *criteria,std::vector<myParticle *>* particles, std::string name, std::string basename);
  void createNewCombo (AnalysisObjects* ao,std::vector<Node*> *criteria,std::vector<myParticle *>* particles, std::string name, std::string basename);
  void createNewParti (AnalysisObjects* ao,std::vector<Node*> *criteria,std::vector<myParticle *>* particles, std::string name, std::string basename);
  void createNewTruth (AnalysisObjects* ao,std::vector<Node*> *criteria,std::vector<myParticle *>* particles, std::string name, std::string basename);
  void createNewTrack (AnalysisObjects* ao,std::vector<Node*> *criteria,std::vector<myParticle *>* particles, std::string name, std::string basename);

  std::vector<TLorentzVector> fmegajets(std::vector<TLorentzVector> myjets, int p1);
  // MR
  double fMR(std::vector<TLorentzVector> j);
  // MTR
  double fMTR(std::vector<TLorentzVector> j, TVector2 amet);
  double fMTR2(std::vector<TLorentzVector> j, TLorentzVector amet);
  // MT
  double fMT(std::vector<TLorentzVector> v);

  //User Funcs
  double userfuncA(AnalysisObjects* ao, std::string s, int id, std::vector<TLorentzVector> (*func)(std::vector<TLorentzVector> jets, int p1) );
  double userfuncB(AnalysisObjects* ao, std::string s, int id, double (*func)(std::vector<TLorentzVector> jets ) );
  double userfuncC(AnalysisObjects* ao, std::string s, int id, double (*func)(std::vector<TLorentzVector> jets, TVector2 amet ) );
  double userfuncD(AnalysisObjects* ao, std::string s, int id, TLorentzVector alv, double (*func)(std::vector<TLorentzVector> jets, TLorentzVector amet ));
  double userfuncE(AnalysisObjects* ao, std::string s, int id, TLorentzVector l1, TLorentzVector l2,  TLorentzVector m1,
                                                              double (*func)(TLorentzVector la, TLorentzVector lb, TLorentzVector amet ) );
  double userfuncF(AnalysisObjects* ao, std::string s, int id, double l1, double l2,  double m1, double l3,
                                                              double (*func)(double la, double lb, double amet, double lab ) );



// }

#endif
