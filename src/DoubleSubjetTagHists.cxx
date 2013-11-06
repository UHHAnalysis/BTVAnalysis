#include "include/DoubleSubjetTagHists.h"

#include "SFrameTools/include/EventCalc.h"
//#include "include/ObjectHandler.h"
//#include "include/EventCalc.h"
#include "TH2.h"
#include "TGraphErrors.h"

//Added for the subjettiness calculation
//#include "include/Nsubjettiness.hh"
//#include <fastjet/JetDefinition.hh>
//#include <fastjet/PseudoJet.hh>
//#include <fastjet/ClusterSequence.hh>
//#include <fastjet/ClusterSequenceArea.hh>
//#include <fastjet/GhostedAreaSpec.hh>

#include <iostream>

using namespace std;


using namespace std;

DoubleSubjetTagHists::DoubleSubjetTagHists(const char* name) : BaseHists(name)
{
  // named default constructor
   
}

DoubleSubjetTagHists::~DoubleSubjetTagHists()
{
  // default destructor, does nothing
}

void DoubleSubjetTagHists::Init()
{
  // book all histograms here
  
  Book( TH1D( "H_bb_Tag_Den", "H bb Tag Den", 25, 0, 1000));
  Book( TH1D( "H_bb_Tag_Den_Reco", "H bb Tag Den Reco", 25, 0, 1000));
  Book( TH1D( "H_bb_Tag_Num", "H bb Tag Num", 25, 0, 1000));
  Book( TH1D( "H_bb_Tag_Effi_Abs", "H bb Tag Effi Abs", 25, 0, 1000));
  Book( TH1D( "H_bb_Tag_Num_Reco", "H bb Tag Num Reco", 25, 0, 1000));
  Book( TH1D( "H_bb_Tag_Effi", "H bb Tag Effi", 25, 0, 1000));
  Book( TH1D( "H_bb_Tag_Effi_Reco", "H bb Tag Effi Reco", 25, 0, 1000));
  Book( TH1D( "H_bb_Tag_NumL", "H bb Tag NumL", 25, 0, 1000));
  Book( TH1D( "H_bb_Tag_Effi_AbsL", "H bb Tag Effi AbsL", 25, 0, 1000));
  Book( TH1D( "H_bb_Tag_Num_RecoL", "H bb Tag Num RecoL", 25, 0, 1000));
  Book( TH1D( "H_bb_Tag_EffiL", "H bb Tag EffiL", 25, 0, 1000));
  Book( TH1D( "H_bb_Tag_Effi_RecoL", "H bb Tag Effi RecoL", 25, 0, 1000));
  Book( TH1D( "H_bb_Match_Num", "H bb Match Num", 25, 0, 1000));
  Book( TH1D( "H_bb_Match_Den", "H bb Match Den", 25, 0, 1000));
  Book( TH1D( "H_bb_Match_Effi", "H bb Match Effi", 25, 0, 1000));
  Book( TH1D( "H_bb_Mistag_Den", "H bb Mistag Den", 25, 0, 1000));
  Book( TH1D( "H_bb_Mistag_Num", "H bb Mistag Num", 25, 0, 1000));
  Book( TH1D( "H_bb_Mistag_Effi", "H bb Mistag Effi", 25, 0, 1000));
  Book( TH1D( "H_bb_Mistag_NumL", "H bb Mistag NumL", 25, 0, 1000));
  Book( TH1D( "H_bb_Mistag_EffiL", "H bb Mistag EffiL", 25, 0, 1000));
  
}

void DoubleSubjetTagHists::Fill()
{
  // fill the histograms

  // important: get the event weight
  double weight = 1.;

  EventCalc* calc = EventCalc::Instance();
  bool IsRealData = calc->IsRealData();
  LuminosityHandler* lumih = calc->GetLumiHandler();

  //EventCalc* calc = EventCalc::Instance();
  BaseCycleContainer* bcc = calc->GetBaseCycleContainer();

  int run = calc->GetRunNum();
  int lumiblock = calc->GetLumiBlock();
  int Npvs = calc->GetPrimaryVertices()->size();

  int ishbb=0;
  GenParticle b1_1;
  GenParticle b1_2;
  GenParticle b2_1;
  GenParticle b2_2;
  double deltarbb=-999999.;
  double higgspt=-99999.;
  GenParticle higgs1;
  GenParticle higgs2;
  GenParticle higgs;
  GenParticle top1;
  GenParticle top2;

  int counthiggsbb=0;

  for(unsigned int ig=0; ig<bcc->genparticles->size(); ++ig){
    
    GenParticle genp = bcc->genparticles->at(ig); 

    if (genp.pdgId() == 6){
      top1=bcc->genparticles->at(ig); 
    }
    
    if (genp.pdgId() == -6){
      top2=bcc->genparticles->at(ig); 
    }

    if (abs(genp.pdgId()) == 25){
      
      higgs= bcc->genparticles->at(ig);
      
      if (genp.daughter(bcc->genparticles,1) && genp.daughter(bcc->genparticles,2)){

	if (abs(genp.daughter(bcc->genparticles,1)->pdgId()) == 5 && abs(genp.daughter(bcc->genparticles,2)->pdgId()) == 5){
	  
	  ishbb=1;
  
	  counthiggsbb=counthiggsbb+1;

	  int indexb1 = genp.daughter(bcc->genparticles,1)->index();
	  int indexb2 = genp.daughter(bcc->genparticles,2)->index();
	  
	  if(counthiggsbb==1){
	    b1_1 = bcc->genparticles->at(indexb1);
	    b1_2 = bcc->genparticles->at(indexb2);
	    higgs1=higgs;
	    deltarbb =  b1_1.deltaR(b1_2);
	    Hist("H_bb_Match_Den")->Fill(higgs1.pt());
	  }
	  else if(counthiggsbb==2){
	    b2_1 = bcc->genparticles->at(indexb1);
	    b2_2 = bcc->genparticles->at(indexb2);
	    higgs2=higgs;
	    deltarbb =  b2_1.deltaR(b2_2);
	    Hist("H_bb_Match_Den")->Fill(higgs2.pt());
	  }
	  
	  higgspt=higgs.pt();

	}//If bb decay
	
      }//If two decays
      else
	{
	  std::cout << "ATTENTION!!! Problem number of decays" << std::endl;
	}

    }//If higgs

  }//Loop over gen particles

  //Study double association

  //NOTE: fundamental parameters to tune, for true MC-jet association and jet-SV association
  double assomatch=0.8;
  float csvcut=0.679;
  float csvcutL=0.244;
  TopJet jetcheck;

  int hbbjet;

  int checkmatch1=0;
  int checkmatch2=0;

  for(unsigned int ij=0; ij< bcc->topjets->size(); ++ij){

    jetcheck=bcc->topjets->at(ij);

    //Check whether it is a true double b jet

    double deltarhjet=99999.;
    double deltarb1jet=99999.;
    double deltarb2jet=99999.;

    //Use to eventually ask isolation from tops in the event
    double deltatop1=jetcheck.deltaR(top1);
    double deltatop2=jetcheck.deltaR(top2);

    hbbjet=0;

    if(ishbb==1){

      deltarhjet=jetcheck.deltaR(higgs1);
      deltarb1jet=jetcheck.deltaR(b1_1);
      deltarb2jet=jetcheck.deltaR(b1_2);
      
      int wrongjet=0;
      for(unsigned int ih=0; ih<bcc->topjets->size();++ih){
	if(((pow((bcc->topjets->at(ih).deltaR(b1_1)),2) + pow((bcc->topjets->at(ih).deltaR(b1_2)),2)) <= (pow(deltarb1jet,2) + pow(deltarb2jet,2))) && ih!=ij){
	  wrongjet=1;
	}
      }
      
      //MEMO: eventually add also isolation from other event constituents
      if(deltarb1jet<assomatch&&deltarb2jet<assomatch&&wrongjet==0){
	
	checkmatch1=checkmatch1+1;
	
	hbbjet=1;
	
      }

      if(counthiggsbb==2){
	deltarhjet=jetcheck.deltaR(higgs2);
	deltarb1jet=jetcheck.deltaR(b2_1);
	deltarb2jet=jetcheck.deltaR(b2_2);

	int wrongjet=0;
	for(unsigned int ih=0; ih<bcc->topjets->size();++ih){
	  if(((pow((bcc->topjets->at(ih).deltaR(b2_1)),2) + pow((bcc->topjets->at(ih).deltaR(b2_2)),2)) <= (pow(deltarb1jet,2) + pow(deltarb2jet,2))) && ih!=ij){
	    wrongjet=1;
	  }
	}
	
	if(deltarb1jet<assomatch&&deltarb2jet<assomatch&&wrongjet==0){
	  
	  checkmatch2=checkmatch2+1;
	  
	  hbbjet=2;
	  
	}
	
      }

    }//ishbb==1

    //Count subjet btags
    int countsb=0;
    int countsbL=0;
    std::vector<Particle> subjets_jet;
    std::vector<float> btagsub_combinedSecondaryVertex_jet;

    subjets_jet=jetcheck.subjets();
    btagsub_combinedSecondaryVertex_jet=jetcheck.btagsub_combinedSecondaryVertex();

    if(subjets_jet.size()!=btagsub_combinedSecondaryVertex_jet.size()){
      std::cout << "ATTENTION!!! Problem subjet discriminator dimension" << std::endl;
    }
    else{
      //std::cout << "Size subjets " << subjets_jet.size() << std::endl;
    }

    //std::cout<< "event: " <<bcc->event << " jet " << ij << std::endl;
    //std::cout << "Size is " << btagsub_combinedSecondaryVertex_jet.size() << std::endl;
    for(unsigned int itt=0; itt<btagsub_combinedSecondaryVertex_jet.size();++itt){
      //std::cout << "Element " << itt << " is " << btagsub_combinedSecondaryVertex_jet[itt] << std::endl;
      float test=btagsub_combinedSecondaryVertex_jet[itt];
      if(test>csvcut){
	countsb=countsb+1;
      }
      if(test>csvcutL){
	countsbL=countsbL+1;
      }
    }//Itera oversubjets

    //if(hbbjet==1&&subjets_jet.size()>=2&&jetcheck.v4().M()>75&&jetcheck.v4().M()<135){
    if(hbbjet==1&&subjets_jet.size()>=2){
      Hist("H_bb_Match_Num")->Fill(higgs1.pt());
      Hist("H_bb_Tag_Den_Reco")->Fill(jetcheck.pt());
      Hist("H_bb_Tag_Den")->Fill(higgs1.pt());
      if(countsb>=2){
	Hist("H_bb_Tag_Num")->Fill(higgs1.pt());
	Hist("H_bb_Tag_Num_Reco")->Fill(jetcheck.pt());
      }
      if(countsbL>=2){
	Hist("H_bb_Tag_NumL")->Fill(higgs1.pt());
	Hist("H_bb_Tag_Num_RecoL")->Fill(jetcheck.pt());
      }
    }

    //if(hbbjet==2&&subjets_jet.size()>=2&&jetcheck.v4().M()>75&&jetcheck.v4().M()<135){
    if(hbbjet==2&&subjets_jet.size()>=2){
      Hist("H_bb_Match_Num")->Fill(higgs2.pt());
      Hist("H_bb_Tag_Den_Reco")->Fill(jetcheck.pt());
      Hist("H_bb_Tag_Den")->Fill(higgs2.pt());
      if(countsb>=2){
	Hist("H_bb_Tag_Num")->Fill(higgs2.pt());
	Hist("H_bb_Tag_Num_Reco")->Fill(jetcheck.pt());
      }
      if(countsbL>=2){
	Hist("H_bb_Tag_NumL")->Fill(higgs2.pt());
	Hist("H_bb_Tag_Num_RecoL")->Fill(jetcheck.pt());
      }
    }


    if(checkmatch1>1||checkmatch2>1){

      cout << "ATTENTION matching problem: checkmatch1 " << checkmatch1 << " checkmatch2 " << checkmatch2 << endl;

      for(unsigned int ih=0; ih<bcc->topjets->size();++ih){
	TopJet jetcheckmatch=bcc->topjets->at(ih);
	cout << "Jet " << ih << " deltar1 " << jetcheckmatch.deltaR(higgs1) << endl;
	if(counthiggsbb==2){
	  cout << "Jet " << ih << " deltar2 " << jetcheckmatch.deltaR(higgs2) << endl;
	}
      }
    }

    int countbs=0;
    double deltacheckbs=99999;

    for(unsigned int ig=0; ig<bcc->genparticles->size(); ++ig){

      GenParticle checkgen=bcc->genparticles->at(ig);
      
      deltacheckbs=jetcheck.deltaR(checkgen);
 
      if(deltacheckbs<assomatch&&abs(checkgen.pdgId())==5){
	countbs=countbs+1;
      }

    }

    if(countbs<1000000000000000){
      Hist("H_bb_Mistag_Den")->Fill(jetcheck.pt());
      if(countsb>=2){
	Hist("H_bb_Mistag_Num")->Fill(jetcheck.pt());
      }
      if(countsbL>=2){
	Hist("H_bb_Mistag_NumL")->Fill(jetcheck.pt());
      }
    } 
    
  }//Loop over jets
  
}

void DoubleSubjetTagHists::Finish()
{
  // final calculations, like division and addition of certain histograms
  EventCalc* calc = EventCalc::Instance();
  bool IsRealData = calc->IsRealData();

  Hist("H_bb_Tag_Effi")->Divide(Hist("H_bb_Tag_Num"),Hist("H_bb_Tag_Den"),1,1,"B");
  Hist("H_bb_Tag_Effi_Reco")->Divide(Hist("H_bb_Tag_Num_Reco"),Hist("H_bb_Tag_Den_Reco"),1,1,"B");
  Hist("H_bb_Tag_Effi_Abs")->Divide(Hist("H_bb_Tag_Num"),Hist("H_bb_Match_Den"),1,1,"B");
  Hist("H_bb_Match_Effi")->Divide(Hist("H_bb_Match_Num"),Hist("H_bb_Match_Den"),1,1,"B");
  Hist("H_bb_Mistag_Effi")->Divide(Hist("H_bb_Mistag_Num"),Hist("H_bb_Mistag_Den"),1,1,"B");
  Hist("H_bb_Tag_EffiL")->Divide(Hist("H_bb_Tag_NumL"),Hist("H_bb_Tag_Den"),1,1,"B");
  Hist("H_bb_Tag_Effi_RecoL")->Divide(Hist("H_bb_Tag_Num_RecoL"),Hist("H_bb_Tag_Den_Reco"),1,1,"B");
  Hist("H_bb_Tag_Effi_AbsL")->Divide(Hist("H_bb_Tag_NumL"),Hist("H_bb_Match_Den"),1,1,"B");
  Hist("H_bb_Mistag_EffiL")->Divide(Hist("H_bb_Mistag_NumL"),Hist("H_bb_Mistag_Den"),1,1,"B");

}

