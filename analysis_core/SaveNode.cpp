#include "SaveNode.h"

SaveNode::SaveNode(std::string s){
              symbol="save";
	name = s;
	left = NULL;
	right = NULL;
	ntsave = new DBXNtuple();
       	fname = "lvl0_" + name + ".root";
          savetype = "lvl0";
}
SaveNode::SaveNode(std::string s, short int sele, vector<Node*> VariableList){
              symbol="save";
	name = s;
              selector=sele;
	left = NULL;
	right = NULL;
	ntsave = NULL;
       	fname = name + ".csv"; // based on sele this could also be a txt file
          savetype = "variableList";
          variableList = VariableList;
}
   void SaveNode::getParticles(std::vector<myParticle *>* particles) {
               std::vector<myParticle *>  bparticles;
               std::vector<myParticle *> *aparticles=&bparticles;
               variableList[0]->getParticlesAt(aparticles,0);
                particles->push_back(bparticles[0]);
               }
   void SaveNode::getParticlesAt(std::vector<myParticle *>* particles,int index) {
               std::vector<myParticle *>  bparticles;
               std::vector<myParticle *> *aparticles=&bparticles;
               variableList[0]->getParticlesAt(aparticles,0);
                particles->push_back(bparticles[index]);
               }
   void SaveNode::Reset() {}
   void SaveNode::createFile()  {
          if(savetype=="variableList"){
              if (selector) csvsave.open(fname);
              return ;
          }
    ftsave = new TFile (fname.c_str(),"RECREATE"); // il faut changer le nom du fichier
    ttsave = new TTree ("nt_tree", "saving data on the grid");
          ttsave->Branch("dbxAsave", ntsave);
          ttsave->SetAutoFlush();
          ttsave->SetAutoSave(30000);
  }
   void SaveNode::saveFile()  {
//            std::cout << "Closing file\n";
          if(savetype=="variableList"){
             if (selector) csvsave.close();
          } else {
    	ftsave->Write();
    	ftsave->Close();
          }
  }
   double SaveNode::evaluate(AnalysisObjects* ao)  {
    if(variableList.size() > 0){
         std::vector<myParticle *>  bparticles;
         std::vector<myParticle *> *aparticles=&bparticles;
         if (selector) {
          for (int i = 0; i < (int)variableList.size(); i++)
          {
                csvsave << variableList[i]->evaluate(ao) << " , ";
          }
          csvsave << "\n";
         } else {
// .........vector<Node*> variableList;
          for (int i = 0; i < (int)variableList.size(); i++)
          {
              variableList[i]->getParticlesAt(aparticles,0);
              //std::cout<< aparticles->at(i)->index <<"c "; // what if we have 0 particles?
              std::cout<< variableList[i]->evaluate(ao) << " , ";
          }
          if (aparticles->size()>0){
            if (aparticles->at(0)->type == 21) {std::cout<<"\t";} else std::cout << "\n";
          } else
          std::cout << "\n";
         }
          return 1;
    }

    vector<dbxMuon>        muons = ao->muos.begin()->second;
    vector<dbxElectron> electrons= ao->eles.begin()->second;
    vector <dbxPhoton>    photons= ao->gams.begin()->second;
    vector<dbxJet>           jets= ao->jets.begin()->second;
    vector<dbxJet>          ljets= ao->ljets.begin()->second;
    vector<dbxTau>           taus= ao->taus.begin()->second;
    vector<dbxTruth>        truth= ao->truth.begin()->second;
    vector<dbxParticle>    combos= ao->combos.begin()->second;
    //-----------------------------------------

    TVector2 met = ao->met.begin()->second;
    evt_data anevt = ao->evt;
    //      here we save the DBXNTuple
    ntsave->Clean();
    ntsave->nEle=electrons.size();
    for ( int i=0; i<(int)electrons.size(); i++) {
ntsave->nt_eles.push_back(electrons.at(i) );
    }

    ntsave->nMuo=muons.size();
    for ( int i=0; i<(int)muons.size(); i++) {
ntsave->nt_muos.push_back(muons.at(i) );
    }
    ntsave->nJet=jets.size();
    for ( int i=0; i<(int)jets.size(); i++) {
ntsave->nt_jets.push_back(jets.at(i) );
    }
    ntsave->nPhoton=photons.size();
    for ( int i=0; i<(int)photons.size(); i++) {
ntsave->nt_photons.push_back(photons.at(i) );
    }
    ntsave->nLJet=ljets.size();
    for ( int i=0; i<(int)ljets.size(); i++) {
ntsave->nt_ljets.push_back(ljets.at(i) );
    }
    ntsave->nTau=taus.size();
    for ( int i=0; i<(int)taus.size(); i++) {
ntsave->nt_taus.push_back(taus.at(i) );
    }
    ntsave->nTruth=truth.size();
    for ( int i=0; i<(int)truth.size(); i++) {
ntsave->nt_truth.push_back(truth.at(i) );
    }
    ntsave->nCombo=combos.size();
    for ( int i=0; i<(int)combos.size(); i++) {
ntsave->nt_combos.push_back(combos.at(i) );
    }

    ntsave->nt_met=met;
    ntsave->nt_evt=anevt;
    ntsave->nt_eles.resize    ( electrons.size()         );
    ntsave->nt_muos.resize    ( muons.size()             );
    ntsave->nt_taus.resize    ( taus.size()              );
    ntsave->nt_jets.resize    ( jets.size()              );
    ntsave->nt_ljets.resize   ( ljets.size()             );
    ntsave->nt_photons.resize ( photons.size()           );
    ntsave->nt_combos.resize  ( combos.size()            );
    ntsave->nt_truth.resize   ( truth.size()             );

    ttsave->Fill();
    return 1;
  }
   SaveNode::~SaveNode() {}
