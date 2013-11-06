#include "include/CheckFatScaleHists.h"
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

CheckFatScaleHists::CheckFatScaleHists(const char* name, double ptMin, double ptMax) : BaseHists(name)
{
  // named default constructor
  m_ptMin = ptMin;
  m_ptMax = ptMax;
 
}

CheckFatScaleHists::~CheckFatScaleHists()
{
  // default destructor, does nothing
}

void CheckFatScaleHists::Init()
{
  // book all histograms here
  
  //Book( TH1D( "H_Example", "H example", 25, 0, 1000));

  //Following hostrograms are filled independently from the pt bin (same in any pt-bin collection)

  Book( TH1D( "P_reco_CA15", "CA15 pt reco", 50, 150, 1000));
  Book( TH1D( "P_reco_AK5", "AK5 pt reco", 50, 150, 1000));
  
  Book( TH1D( "P_gen_CA15", "CA15 pt gen", 50, 150, 1000));
  Book( TH1D( "P_gen_AK5", "AK5 pt gen", 50, 150, 1000));


  Book( TH1D( "P_ratio_CA15_num", "CA15 pt reco num", 50, 150, 1000));
  Book( TH1D( "P_ratio_CA15_den", "CA15 pt reco den", 50, 150, 1000));
  Book( TH1D( "P_ratio_CA15","CA15 ratio", 50, 150, 1000));
  
  Book( TH1D( "P_ratio_AK5_num", "AK5 pt reco num", 50, 150, 1000));
  Book( TH1D( "P_ratio_AK5_den", "AK5 pt reco den", 50, 150, 1000));
  Book( TH1D( "P_ratio_AK5","AK5 ratio", 50, 150, 1000));

  Book( TH1D( "P_ratio_CA15_unmod_num", "CA15 pt reco num", 50, 150, 1000));
  Book( TH1D( "P_ratio_CA15_unmod_den", "CA15 pt reco den", 50, 150, 1000));
  Book( TH1D( "P_ratio_CA15_unmod","CA15 ratio", 50, 150, 1000));

  Book( TH1D( "P_match_CA15_num", "CA15 pt reco num", 50, 150, 1000));
  Book( TH1D( "P_match_CA15_den", "CA15 pt reco den", 50, 150, 1000));
  Book( TH1D( "P_match_CA15","CA15 match", 50, 150, 1000));
  
  Book( TH1D( "P_match_AK5_num", "AK5 pt reco num", 50, 150, 1000));
  Book( TH1D( "P_match_AK5_den", "AK5 pt reco den", 50, 150, 1000));
  Book( TH1D( "P_match_AK5","AK5 match", 50, 150, 1000));

}

void CheckFatScaleHists::Fill()
{
  // fill the histograms

  EventCalc* calc = EventCalc::Instance();
  bool IsRealData = calc->IsRealData();
  LuminosityHandler* lumih = calc->GetLumiHandler();

  double weight = calc->GetWeight();

  //weight=1;

  std::cout << "Using weight " << weight << std::endl;

  int usesubjets=0;

  //ObjectHandler* objs = ObjectHandler::Instance();
  BaseCycleContainer* bcc = calc->GetBaseCycleContainer();

  int run = calc->GetRunNum();
  int lumiblock = calc->GetLumiBlock();
  int Npvs = calc->GetPrimaryVertices()->size();

  std::vector<Particle> subjets_top;

  for(unsigned int itj=0; itj<bcc->topjets->size();++itj){

    if(bcc->topjets->at(itj).pt()<m_ptMin) continue;

    TopJet checktop=bcc->topjets->at(itj);

    double deltarmin = double_infinity();
    
    GenTopJet nextjet;

    for(unsigned int igj=0; igj<bcc->topjetsgen->size();++igj){
     
      GenTopJet checkgen=bcc->topjetsgen->at(igj);
      
      if(itj==0){
	
	Hist("P_match_CA15_den")->Fill(checkgen.pt());
	
      }
      
      if(checkgen.deltaR(checktop) < deltarmin){
	deltarmin = checkgen.deltaR(checktop);
	nextjet = checkgen;
      }
      
    }//loop over genjets

    if(deltarmin<0.8){
      
      Hist("P_match_CA15_num")->Fill(nextjet.pt());
      
      double ptreco=checktop.pt();
      
      if(usesubjets){
	ptreco=0;
	subjets_top=checktop.subjets();
	for(unsigned int ist=0; ist<subjets_top.size();++ist){
	  Particle subjet=subjets_top[ist];
	  ptreco=ptreco+subjet.pt();
	}
      }//usesubjets

      Hist("P_reco_CA15")->Fill(ptreco);
      Hist("P_gen_CA15")->Fill(nextjet.pt());
      Hist("P_ratio_CA15_num")->Fill(nextjet.pt(),ptreco);
      Hist("P_ratio_CA15_den")->Fill(nextjet.pt(),nextjet.pt());

    }
    
    //vs true top pT

    for(unsigned int ig=0; ig<bcc->genparticles->size(); ++ig){
      
      GenParticle genp = bcc->genparticles->at(ig); 

      GenParticle top;

      if (genp.pdgId() == 6 || genp.pdgId() == -6){
	top=bcc->genparticles->at(ig); 

	if(top.deltaR(checktop) < 0.8){

	  double ptreco=checktop.pt();
	  
	  if(usesubjets){
	    ptreco=0;
	    subjets_top=checktop.subjets();
	    for(unsigned int ist=0; ist<subjets_top.size();++ist){
	      Particle subjet=subjets_top[ist];
	      ptreco=ptreco+subjet.pt();
	    }
	  }//usesubjets

	  Hist("P_ratio_CA15_unmod_num")->Fill(top.pt(),ptreco);
	  Hist("P_ratio_CA15_unmod_den")->Fill(top.pt(),top.pt());
	  
	}
      }

    }//loop over gen particles
    
  }//loop over top jets
 
  for(unsigned int itj=0; itj<bcc->jets->size();++itj){

    Jet checkjet=bcc->jets->at(itj);

    double deltarmin = double_infinity();
    
    Particle closejet;

    for(unsigned int igj=0; igj<bcc->genjets->size();++igj){
     
      Particle checkgenjet=bcc->genjets->at(igj);

      if(itj==0){
	
	Hist("P_match_AK5_den")->Fill(checkgenjet.pt());
	
      }

      if(checkgenjet.deltaR(checkjet) < deltarmin){
	deltarmin = checkgenjet.deltaR(checkjet);
	closejet = checkgenjet;
      }
      
    }//loop over genjets

    if(deltarmin<0.3){

      Hist("P_match_AK5_num")->Fill(closejet.pt());

      Hist("P_reco_AK5")->Fill(checkjet.pt());
      Hist("P_gen_AK5")->Fill(closejet.pt());
      Hist("P_ratio_AK5_num")->Fill(closejet.pt(),checkjet.pt());
      Hist("P_ratio_AK5_den")->Fill(closejet.pt(),closejet.pt());

   }
    
  }//loop over jets
  
}

void CheckFatScaleHists::Finish()
{
  // final calculations, like division and addition of certain histograms

  Hist("P_ratio_CA15")->Divide(Hist("P_ratio_CA15_num"),Hist("P_ratio_CA15_den"),1,1,"B");
  Hist("P_ratio_CA15_unmod")->Divide(Hist("P_ratio_CA15_unmod_num"),Hist("P_ratio_CA15_unmod_den"),1,1,"B");
  Hist("P_ratio_AK5")->Divide(Hist("P_ratio_AK5_num"),Hist("P_ratio_AK5_den"),1,1,"B");

  Hist("P_match_CA15")->Divide(Hist("P_match_CA15_num"),Hist("P_match_CA15_den"),1,1,"B");
  Hist("P_match_AK5")->Divide(Hist("P_match_AK5_num"),Hist("P_match_AK5_den"),1,1,"B");

}

