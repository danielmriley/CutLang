//
//  ValueNode.h
//  mm
//
//  Created by Anna-Monica  on 7/31/18.
//  Copyright © 2018 Anna-Monica. All rights reserved.
//

#ifndef ValueNode_h
#define ValueNode_h
#include "Node.h"
//takes care of integers and real values
class ValueNode :public Node{
private:
    double value;
    bool pval;
public:
    ValueNode(double v=0);
    ValueNode(std::string evtvar);

    virtual void getParticles(std::vector<myParticle *>* particles) override;
    virtual void getParticlesAt(std::vector<myParticle *>* particles,int index) override;
    virtual void Reset() override;
    virtual double evaluate(AnalysisObjects* ao) override ;

    virtual ~ValueNode();
};

#endif /* ValueNode_h */
