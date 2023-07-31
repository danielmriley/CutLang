#include "ValueNode.h"
ValueNode::ValueNode(double v){
            value=v;
            pval=true;
            left=NULL;
            right=NULL;
            symbol=std::to_string(v);
        }
ValueNode::ValueNode(std::string evtvar){
            value=0;
            left=NULL;
            right=NULL;
            pval=false;
            symbol=evtvar;
        }

void ValueNode::getParticles(std::vector<myParticle *>* particles) {}
void ValueNode::getParticlesAt(std::vector<myParticle *>* particles,int index) {}
void ValueNode::Reset() {}
double ValueNode::evaluate(AnalysisObjects* ao)  {
    if (pval) return value;
    if (symbol=="RunYear")   return ao->evt.RunYear;
    if (symbol=="ChannelNo") return ao->evt.ChannelNo;
    if (symbol=="HFCLASSIFICATION") return ao->evt.m_HF_Classification;

    return ao->evt.event_no; // TO BE improved
}

 ValueNode::~ValueNode() {}
