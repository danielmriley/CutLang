//
//  AONode.hpp
//  mm
//
//  Created by Anna-Monica  on 8/1/18.
//  Copyright © 2018 Anna-Monica. All rights reserved.
//

#ifndef BinaryNode_hpp
#define BinaryNode_hpp

#include <stdio.h>
#include <math.h>
#include "Node.h"

//#define _CLV_

#ifdef _CLV_
#define DEBUG(a) std::cout<<a
#else
#define DEBUG(a)
#endif


//takes care of Arithmetical Operators, Logical Operators, and Comparison Operators
class BinaryNode : public Node{
private:
    double (*f)(double, double);
public:
    BinaryNode(double (*func)(double, double), Node* l, Node* r, std::string s);

    virtual void getParticles(std::vector<myParticle *>* particles) override;

    virtual void getParticlesAt(std::vector<myParticle *>* particles,int index) override;
    virtual void Reset() override;
    virtual double evaluate(AnalysisObjects* ao) override;
    virtual ~BinaryNode();

};

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


//if CONDITION-> later
#endif /* AONode_hpp */
