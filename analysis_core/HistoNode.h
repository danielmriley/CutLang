#ifndef HistoNode_h
#define HistoNode_h

#include "Node.h"
#include <string>
#include "TH1F.h"
#include "TH2F.h"

using namespace std;

class HistoNode1D : public Node{
private:
    std::string id;
    std::string Desciption;
    float lowerLimitx;
    float upperLimitx;
    int binsx;
    TH1D *ahisto1;
    std::vector<myParticle*> inputParticles;

public:
    HistoNode1D( std::string id,std::string desc,int n, float l1, float l2,Node* l);
    HistoNode1D( std::string id,std::string desc, vector<float> ls, Node* l);
    virtual void Reset() override;

    virtual void getParticles(std::vector<myParticle *>* particles) override;
    virtual void getParticlesAt(std::vector<myParticle *>* particles, int index) override;
    double evaluate(AnalysisObjects* ao) override;
    virtual ~HistoNode1D();

};
//----------------------------------------------------------------
class HistoNode2D : public Node{
private:
    std::string id;
    std::string Desciption;
    float lowerLimitx;
    float upperLimitx;
    float lowerLimity;
    float upperLimity;
    int binsx;
    int binsy;
    TH2D *ahisto2;
    std::vector<myParticle*> inputParticles;

public:
    HistoNode2D( std::string id,std::string desc,int nx, float xmin, float xmax, int ny, float ymin, float ymax, Node* l, Node* r);

    HistoNode2D( std::string id,std::string desc, vector<float> vx , int ny, float ymin, float ymax, Node* l, Node* r);

    HistoNode2D( std::string id,std::string desc, int nx, float xmin, float xmax,  vector<float> vy, Node* l, Node* r);


virtual void Reset() override;

virtual void getParticles(std::vector<myParticle *>* particles) override;
virtual void getParticlesAt(std::vector<myParticle *>* particles, int index) override;
double evaluate(AnalysisObjects* ao) override;
virtual ~HistoNode2D();

};

#endif
