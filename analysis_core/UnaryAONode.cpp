#include "UnaryAONode.h"

UnaryAONode::UnaryAONode(double (*func)(double), Node* l, std::string s){
    f=func;
    symbol=s;
    left=l;
    right=NULL;
}

void UnaryAONode::getParticles(std::vector<myParticle *>* particles) {
     left->getParticles(particles);
}

void UnaryAONode::getParticlesAt(std::vector<myParticle *>* particles, int index) {
    left->getParticlesAt(particles,index);
}

void UnaryAONode::Reset() {
    left->Reset();
}

double UnaryAONode::evaluate(AnalysisObjects* ao)  {
    return (*f)(left->evaluate(ao));
}

UnaryAONode::~UnaryAONode() {
    if (left!=NULL) delete left;
}

double unaryMinu(double left) {
    return -left;
}
double hstep(double x){
	if(x>0) {return 1;}
	else return 0;
}
double delta(double x){
	if(x==0) {return 1;}
	else return 0;
}

double LogicalNot(double condition){
        return (double)(!(condition));
}
