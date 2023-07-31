//
//  SaveNode.h
//  Created by Jinen Setpal on 18/2/20.
//

#ifndef SaveNode_h
#define SaveNode_h
#include "Node.h"
#include "TFile.h"
#include "TTree.h"
#include "DBXNtuple.h"

#include <iostream>
#include <fstream>
#include <ios>
#include <stdio.h>
#include <cstdio>

class SaveNode : public Node{
private:
	std::string name, fname, savetype;
	DBXNtuple *ntsave;
	TFile *ftsave;
	TTree *ttsave;
      std::ofstream csvsave;
      vector<Node*> variableList;
         short int selector;
public:
	SaveNode(std::string s);
	SaveNode(std::string s, short int sele, vector<Node*> VariableList);
    virtual void getParticles(std::vector<myParticle *>* particles) override;
    virtual void getParticlesAt(std::vector<myParticle *>* particles,int index) override;
    virtual void Reset() override;
    virtual void createFile() override ;
    virtual void saveFile() override ;
    virtual double evaluate(AnalysisObjects* ao) override ;
    virtual ~SaveNode() ;
};

#endif // SaveNode_h
