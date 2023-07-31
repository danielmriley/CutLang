#include "HistoNode.h"
#include "FuncNode.h"

//#define _CLV_

#ifdef _CLV_
#define DEBUG(a) std::cout<<a
#else
#define DEBUG(a)
#endif

using namespace std;

HistoNode1D::HistoNode1D( std::string id,std::string desc,int n, float l1, float l2,Node* l){
    this->id=id;
    Desciption=desc;
    lowerLimitx=l1;
    upperLimitx=l2;
    binsx=n;
    symbol="histo "+id+","+Desciption+","+std::to_string(l1)+","+std::to_string(l2)+","+std::to_string(n);
    ahisto1 = new TH1D(id.data(), Desciption.data(), binsx, lowerLimitx, upperLimitx);
    left=l;
    right=NULL;
}
HistoNode1D::HistoNode1D( std::string id,std::string desc, vector<float> ls, Node* l){
    this->id=id;
    Desciption=desc;
    lowerLimitx=ls[0];
    upperLimitx=ls[0];
    binsx=ls.size();
    double *xvals=(double *)malloc(binsx*sizeof(double) );
//      cout <<"~~~~~~~~~~~~~~~VARIABLE BINS~~~~~~~~~~~~\n";
    for (int jj=0; jj<binsx; jj++) {xvals[jj]=(double)ls[jj]; //cout << xvals[jj] << "\n";
                                   }
    symbol="histo "+id+","+Desciption+",variable bins";
    ahisto1 = new TH1D(id.data(), Desciption.data(), binsx-1, xvals);
    left=l;
    right=NULL;
    free(xvals);
}
void HistoNode1D::Reset() { left->Reset(); }

void HistoNode1D::getParticles(std::vector<myParticle *>* particles) {
     left->getParticles(particles);
}
void HistoNode1D::getParticlesAt(std::vector<myParticle *>* particles, int index) {}
HistoNode1D::~HistoNode1D(){
if (left!=NULL) delete left;
if (right!=NULL) delete right;
}

double HistoNode1D::evaluate(AnalysisObjects* ao) {
                  this->getParticles(&inputParticles);
                  for (int ii=0; ii<inputParticles.size(); ii++){
                      DEBUG("1DHisto particle ID:"<<ii<<" Type:"<<inputParticles[ii]->type<<" collection:"
                        << inputParticles[ii]->collection << " index:"<<inputParticles[ii]->index<<"\n");
                  }
                  if (inputParticles.size()>0 ) {
                  if (inputParticles[0]->index == 6213){
                      std::string bcol2=inputParticles[0]->collection;
                      bool constiloop=false;
                      std::string consname;
                      int ipartMax=0;
                      try {
                                   switch(inputParticles[0]->type){
                                   case muon_t: ipartMax=(ao->muos).at(bcol2).size(); break;
                                  case truth_t: ipartMax=(ao->truth).at(bcol2).size(); break;
                                  case track_t: ipartMax=(ao->track).at(bcol2).size(); break;
                               case electron_t: ipartMax=(ao->eles).at(bcol2).size(); break;
                                    case jet_t: ipartMax=(ao->jets).at(bcol2).size(); break;
                                  case pureV_t: ipartMax=1; break;
                                 case photon_t: ipartMax=(ao->gams).at(bcol2).size(); break;
                                   case fjet_t: ipartMax=(ao->ljets).at(bcol2).size(); break;
                                    case tau_t: ipartMax=(ao->taus).at(bcol2).size(); break;
                                  case combo_t: ipartMax=(ao->combos)[bcol2].size(); break;
                                 case consti_t: {constiloop=true;
                                               TString konsname=bcol2;
                                                      konsname+="_";
                                                      konsname+=inputParticles[0]->index;
                                                      konsname+="c";
                                                      consname=(std::string)konsname;
                                                      ipartMax =(ao->constits).find(consname)->second.size();
                                                      DEBUG(consname<<" has "<<ipartMax<<" constituents\n");
                                               break;}


                                      default:
                                          std::cerr << "HN WRONG PARTICLE TYPE:"<<inputParticles[0]->type << std::endl; break;
                                   }
                           } catch(...) {
                                               std::cerr << "YOU WANT TO histo A PARTICLE TYPE YOU DIDN'T CREATE:"<<bcol2 <<" !\n";
                                               _Exit(-1);
                           }
                           DEBUG ("loop over "<< ipartMax<<" particles\n");
                           FuncNode *pippo;
                           DEBUG("it will do: "<<left->getStr()<<"\n");
                           if ((pippo=dynamic_cast< FuncNode*>(left)) ) {
                            DEBUG("downcast OK\n");
                           } else {
                            DEBUG("downcast FAILS\n");
                             if ((pippo=dynamic_cast< FuncNode*>(left->left)) ) {
                               DEBUG("down-downcast OK\n");
                             }
                           }
                           for (int ii=0; ii<ipartMax; ii++) {
                             DEBUG("now for particle "<<ii<<"\n");
                             pippo->setParticleIndex(0, ii);
                             double value = left->evaluate(ao);
                             DEBUG("Histo Loop retval:"<<value<<"\n");
		             ahisto1->Fill(value, ao->evt.user_evt_weight);
                           }
                           pippo->setParticleIndex(0, 6213);
                           return 1;
                          }// end of inner if with 6213
                    } // end of >0
                    double value = left->evaluate(ao);
                    DEBUG("Filling with:"<<value<<"\n");
		    ahisto1->Fill(value, ao->evt.user_evt_weight);
		    return 1;
};
//-----

HistoNode2D::HistoNode2D( std::string id,std::string desc,int nx, float xmin, float xmax, int ny, float ymin, float ymax, Node* l, Node* r){
    this->id=id;
    Desciption=desc;
    lowerLimitx=xmin;
    upperLimitx=xmax;
lowerLimity=ymin;
upperLimity=ymax;
    binsx=nx;
binsy=ny;
    symbol="histo "+id+","+Desciption+","+std::to_string(xmin)+","+std::to_string(xmax)+","+std::to_string(nx)+","+std::to_string(ymin)+","+std::to_string(ymax)+","+std::to_string(ny);
    ahisto2 = new TH2D(id.data(), Desciption.data(), binsx, lowerLimitx, upperLimitx, binsy, lowerLimity, upperLimity);
    left=l;
    right=r;
}

HistoNode2D::HistoNode2D( std::string id,std::string desc, vector<float> vx , int ny, float ymin, float ymax, Node* l, Node* r){
    this->id=id;
    Desciption=desc;
    lowerLimitx=vx[0];
    upperLimitx=vx[0];
lowerLimity=ymin;
upperLimity=ymax;
    binsx=vx.size();
    double *xvals=(double *)malloc(binsx*sizeof(double) );
    for (int jj=0; jj<binsx; jj++) {xvals[jj]=(double)vx[jj]; //cout << xvals[jj] << "\n";
                                   }
binsy=ny;
    symbol="histo "+id+","+Desciption+",variable,"+std::to_string(ymin)+","+std::to_string(ymax)+","+std::to_string(ny);
    ahisto2 = new TH2D(id.data(), Desciption.data(), binsx-1, xvals, binsy, lowerLimity, upperLimity);
    left=l;
    right=r;
    free(xvals);
}
HistoNode2D::HistoNode2D( std::string id,std::string desc, int nx, float xmin, float xmax,  vector<float> vy, Node* l, Node* r){
    this->id=id;
    Desciption=desc;
    lowerLimity=vy[0];
    upperLimity=vy[0];
lowerLimitx=xmin;
upperLimitx=xmax;
    binsy=vy.size();
    double *yvals=(double *)malloc(binsy*sizeof(double) );
    for (int jj=0; jj<binsy; jj++) {yvals[jj]=(double)vy[jj]; //cout << yvals[jj] << "\n";
                                   }
binsx=nx;
    symbol="histo "+id+","+Desciption+","+std::to_string(xmin)+","+std::to_string(xmax)+","+std::to_string(nx)+",variable";
    ahisto2 = new TH2D(id.data(), Desciption.data(), binsx, lowerLimitx, upperLimitx, binsy-1, yvals );
    left=l;
    right=r;
}


void HistoNode2D::Reset() { left->Reset(); }

void HistoNode2D::getParticles(std::vector<myParticle *>* particles) {
     left->getParticles(particles);
}
void HistoNode2D::getParticlesAt(std::vector<myParticle *>* particles, int index) {}
HistoNode2D::~HistoNode2D(){
if (left!=NULL) delete left;
if (right!=NULL) delete right;
}

double HistoNode2D::evaluate(AnalysisObjects* ao) {
/*
                  this->getParticles(&inputParticles);
                  for (int ii=0; ii<inputParticles.size(); ii++){
                      DEBUG("1DHisto particle ID:"<<ii<<" Type:"<<inputParticles[ii]->type<<" collection:"
                        << inputParticles[ii]->collection << " index:"<<inputParticles[ii]->index<<"\n");
                  }
*/
		      double value1=left->evaluate(ao);
		      double value2=right->evaluate(ao);
        	      ahisto2->Fill(value1, value2, ao->evt.user_evt_weight);
        	      return 1;
};
