
#include "IfNode.h"

    IfNode::IfNode(Node* c,Node* l, Node* r,  std::string s ){
        symbol=s;
        condition=c;
        left=l;
        right=r;
    }

     void IfNode::getParticles(std::vector<myParticle *>* particles) {
     condition->getParticles(particles);
    }

     void IfNode::getParticlesAt(std::vector<myParticle *>* particles, int index) {
     condition->getParticlesAt(particles, index);
    }

     void IfNode::Reset() {
    }

     double IfNode::evaluate(AnalysisObjects* ao) {
/*
           std::vector<myParticle *>  bparticles;
           std::vector<myParticle *> *aparticles=&bparticles;
           cout <<"\nCL:"<<(this)->left->getStr()<<"\n";
           cout <<"CR:"<<(this)->right->getStr()<<"\n";
           (this)->left->getParticlesAt(aparticles,0);
           cout <<"B condition CL of "<<aparticles->size()<<" \t T:"<< aparticles->at(0)->type <<
                              " I:"<< aparticles->at(0)->index << " C:"<< aparticles->at(0)->collection << "\n";

           aparticles->clear();
           (this)->right->getParticlesAt(aparticles,0);
           cout <<"B condition CR of "<<aparticles->size()<<" \t T:"<< aparticles->at(0)->type <<
                              " I:"<< aparticles->at(0)->index << " C:"<< aparticles->at(0)->collection << "\n";
*/

        double testResult=condition->evaluate(ao);
/*
           cout <<"~~~~~condition evaluted as:"<<testResult<<"\n";
           aparticles->clear();
           (this)->left->getParticlesAt(aparticles,0);
           cout <<"A condition CL of "<<aparticles->size()<<" \t T:"<< aparticles->at(0)->type <<
                              " I:"<< aparticles->at(0)->index << " C:"<< aparticles->at(0)->collection << "\n";

           aparticles->clear();
           (this)->right->getParticlesAt(aparticles,0);
           cout <<"A condition CR of "<<aparticles->size()<<" \t T:"<< aparticles->at(0)->type <<
                              " I:"<< aparticles->at(0)->index << " C:"<< aparticles->at(0)->collection << "\n";
*/
        if ((bool) testResult) {
           return left->evaluate(ao);
        } else {
           return right->evaluate(ao);
        }
    }
     IfNode::~IfNode() {}
