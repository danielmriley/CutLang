//
//  LoopNode.h
//
//

#ifndef LoopNode_h
#define LoopNode_h
#include "Node.h"
#include <TRandom3.h>

//Looping over variables
class LoopNode : public Node{
private:
    double (*f)(std::vector<double>);
    std::vector<bool> (*g)(std::vector<double>);
    std::vector <Node*> lefs;
    TRandom3 rand3;

protected:
    std::vector<myParticle*> inputParticles;

public:
    LoopNode(std::vector<bool> (*func)(std::vector<double>), Node* l, std::string s);
    LoopNode(double (*func)(std::vector<double>), Node* l, std::string s);
    LoopNode(double (*func)(std::vector<double>), std::vector<Node*> ls, std::string s);

    static double getRand(); //{return (rand3.Uniform(0,1) );}
    virtual void getParticles(std::vector<myParticle *>* particles) override;

    virtual void getParticlesAt(std::vector<myParticle *>* particles, int index) override;

    virtual void Reset() override;

    virtual double evaluate(AnalysisObjects* ao) override;

    virtual ~LoopNode();

};

double aveof(std::vector<double> xlist);
double sumof(std::vector<double> xlist);
double minof(std::vector<double> xlist);
double maxof(std::vector<double> xlist);
std::vector<bool> hitmissA(std::vector<double> xlist);
std::vector<bool> hitmissR(std::vector<double> xlist);


#endif /* LoopNode_h */
