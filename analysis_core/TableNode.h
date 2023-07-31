//
//  TableNode.h
//  mm
//
//  Created by ngu  on Oct19.
//  Copyright © 2019 . All rights reserved.
//

#ifndef TableNode_h
#define TableNode_h

#include <stdio.h>
#include <math.h>
#include "Node.h"
//takes care of Table Operations
//#define _CLV_
#ifdef _CLV_
#define DEBUG(a) std::cout<<a
#else
#define DEBUG(a)
#endif


class TableNode : public Node{
private:
    double (*f)(double, AnalysisObjects* );
    std::vector<float>   atable;
    std::vector<float> errtable;
    Node* left2;
    bool errors;

public:
    TableNode(double (*func)(double, AnalysisObjects*),
              Node* l, std::pair<std::vector<float>, bool> tabe, std::string s);
    TableNode(double (*func)(double, AnalysisObjects*),
              Node* l, Node* l2, std::pair<std::vector<float>, bool> tabe, std::string s);

    virtual double evaluate(AnalysisObjects* ao) override;
    virtual void getParticles(std::vector<myParticle *>* particles) override;
    virtual void getParticlesAt(std::vector<myParticle *>* particles,int index) override;
    virtual void Reset() override;
    virtual ~TableNode();
};

double tweight(double value, AnalysisObjects* ao ) ;
double thitmiss(double value, AnalysisObjects* ao ) ;

#endif /* TableNode */
