#include "BinaryNode.hpp"
BinaryNode::BinaryNode(double (*func)(double, double), Node* l, Node* r, std::string s){
    f=func;
    symbol=s;
    left=l;
    right=r;
}

 void BinaryNode::getParticles(std::vector<myParticle *>* particles) {
    left->getParticles(particles);
    right->getParticles(particles);

}

 void BinaryNode::getParticlesAt(std::vector<myParticle *>* particles,int index) {
    left->getParticlesAt(particles,index);
    right->getParticlesAt(particles,index);
}
 void BinaryNode::Reset() {
    left->Reset();
    right->Reset();
}
 double BinaryNode::evaluate(AnalysisObjects* ao) {
//        std::vector<myParticle *> myParticles;
//        left->getParticles(&myParticles);
//        for (int ip=0; ip<myParticles.size(); ip++){
//                  DEBUG("LEFT pid "<<ip<<"\t");
//                  DEBUG(" Coll:"<<myParticles.at(ip)->collection<<"\t");
//                  DEBUG("\ttype:"<< myParticles.at(ip)->type <<"\tindex:"<<myParticles.at(ip)->index<<"\n");
//              }
//        right->getParticles(&myParticles);
//        for (int ip=0; ip<myParticles.size(); ip++){
//                  DEBUG("RIGHT pid "<<ip<<"\t");
//                  DEBUG(" Coll:"<<myParticles.at(ip)->collection<<"\t");
//                  DEBUG("\ttype:"<< myParticles.at(ip)->type <<"\tindex:"<<myParticles.at(ip)->index<<"\n");
//              }

        return (*f)(left->evaluate(ao),right->evaluate(ao));
}
 BinaryNode::~BinaryNode() {
//        if (left!=NULL) delete left;
//        if (right!=NULL) delete right;
}


double add(double left, double right) {
    return left + right;
}

double mult(double left, double right) {
    return left * right;
}

double sub(double left, double right) {
    return left - right;
}

double div(double left, double right) {
    return left / right;
}

//double power ALREADY EXIST
double lt(double left, double right){
    return (double)(left<right);
}
double le(double left, double right){
    return (double)(left<=right);
}
double ge(double left, double right){
    return (double)(left>=right);
}
double gt(double left, double right){
    return (double)(left>right);
}
double eq(double left, double right){
    return (double)(left==right);
}
double ne(double left, double right){
    return (double)(left!=right);
}
double LogicalAnd(double left, double right){
    return (double)(left&&right);
}
double LogicalOr(double left, double right){
    return (double)(left||right);
}
double mnof(double left, double right){
    return (double)( (left<right)*left +(left>right)*right );
}
double mxof(double left, double right){
    return (double)( (left>right)*left +(left<right)*right );
}
