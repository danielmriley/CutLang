#include "Node.h"

//generic node interface

void Node::getStr(TString *ss){
        if(left!=NULL) left->getStr(ss);
               (*ss)+=" ";
               (*ss)+=symbol;
        if(right!=NULL) right->getStr(ss);
}

void Node::display(std::string indent){
        if(left!=NULL) left->display(indent+"     ");
        std::cout<<indent+symbol<<std::endl;
        if(right!=NULL) right->display("\n"+indent+"     ");
}

void Node::display(){ this->display(""); }
     TString Node::getStr(){ TString ss; this->getStr(&ss); return ss;
}

void Node::saveFile() {}
void Node::createFile() {}

Node::~ Node(){ }

std::vector<dbxJet> Node::tagJets(AnalysisObjects *ao, int jtype, std::string cn) {
                                std::vector<dbxJet>      rjets;
                                for (size_t jj=0; jj<ao->jets[cn].size(); jj++)
                                       if (ao->jets[cn].at(jj).isbtagged_77() == jtype) {rjets.push_back(ao->jets[cn].at(jj)); }
                                return rjets;
}

void Node::setUserObjects(Node *objectNodea, Node *objectNodeb, Node *objectNodec, Node *objectNoded) {
  std::cout<<"Mother adds UOs.\n";
    userObjectA=objectNodea;
    userObjectB=objectNodeb;
    userObjectC=objectNodec;
    userObjectD=objectNoded;
 }

 double Node::evaluate(AnalysisObjects* ao){
    if(userObjectA)  userObjectA->evaluate(ao); // returns 1, hardcoded. see ObjectNode.cpp
    if(userObjectB)  userObjectB->evaluate(ao); // returns 1, hardcoded. see ObjectNode.cpp
    if(userObjectC)  userObjectC->evaluate(ao); // returns 1, hardcoded. see ObjectNode.cpp
    if(userObjectD)  userObjectD->evaluate(ao); // returns 1, hardcoded. see ObjectNode.cpp
    if( userObjectA || userObjectB || userObjectC || userObjectD ) std::cout<<"UOs EVALUATED:"<< getStr() <<"\n";

   return 0;
 }
