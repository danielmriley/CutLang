//
//  UnaryAONode.h
//  mm
//
//  Created by Anna-Monica  on 8/1/18.
//  Copyright © 2018 Anna-Monica. All rights reserved.
//

#ifndef UnaryAONode_h
#define UnaryAONode_h
#include "Node.h"
//takes care of Unary Minus and other Math.h functions
class UnaryAONode : public Node{
private:
    double (*f)(double);
public:
    UnaryAONode(double (*func)(double), Node* l, std::string s);

    virtual void getParticles(std::vector<myParticle *>* particles) override;

    virtual void getParticlesAt(std::vector<myParticle *>* particles, int index) override;

    virtual void Reset() override;

    virtual double evaluate(AnalysisObjects* ao) override;

    virtual ~UnaryAONode();

};
double unaryMinu(double left);
double hstep(double x);
double delta(double x);
double LogicalNot(double condition);

//double COS SIN TAN ALREADY EXIST
#endif /* UnaryAONode_h */
