#include "include/BTVHists.h"
#include "SFrameTools/include/EventCalc.h"
#include "../SFrameTools/include/Utils.h"
#include "../SFrameTools/include/TTbarGen.h"
#include <iostream>

using namespace std;

BTVHists::BTVHists(const char* name, TString mode,TString filename) : BaseHists(name)
{
  // named default constructor
  m_BTaggingMode = mode;
  m_BTagEffiFilenameMC=filename;

}

BTVHists::~BTVHists(){
}

void BTVHists::Init()
{
  // book all histograms here

  // missing ET and HT
  double* logMET_bins = MakeLogBinning(40, 50, 1200);
  Book( TH1F( "MET_lx", "missing E_{T} [GeV]", 40, logMET_bins ) );
  delete[] logMET_bins;
  
  double* logHT_bins = MakeLogBinning(40, 150, 3000);
  Book( TH1F( "HT_lx", "H_{T} [GeV]", 40, logHT_bins ) );
  delete[] logHT_bins;
  
  double* logHTlep_bins = MakeLogBinning(40, 150, 1200);
  Book( TH1F( "HTlep_lx", "H_{T}^{lep} [GeV]", 40, logHTlep_bins ) );
  delete[] logHTlep_bins;

  // jets
  Book( TH1F( "N_jets_ly", "N^{jets}", 20, 0, 20 ) );
  double* logPtjet1_bins = MakeLogBinning(40, 150, 1500);
  double* logPtjet2_bins = MakeLogBinning(40, 50, 1000);
  double* logPtjet3_bins = MakeLogBinning(40, 50, 500);
  double* logPtjet4_bins = MakeLogBinning(40, 50, 250);
  Book( TH1F( "pt_jet1_lx", "p_{T}^{jet 1} [GeV/c]", 40, logPtjet1_bins ) );
  Book( TH1F( "pt_jet2_lx", "p_{T}^{jet 2} [GeV/c]", 40, logPtjet2_bins ) ); 
  Book( TH1F( "pt_jet3_lx", "p_{T}^{jet 3} [GeV/c]", 40, logPtjet3_bins ) );
  Book( TH1F( "pt_jet4_lx", "p_{T}^{jet 4} [GeV/c]", 40, logPtjet4_bins ) );
  delete[] logPtjet1_bins;
  delete[] logPtjet2_bins;
  delete[] logPtjet3_bins;
  delete[] logPtjet4_bins;
  
  
  Book( TH1F( "eta_jet1", "#eta^{jet 1}", 40, -2.5, 2.5) );
  Book( TH1F( "eta_jet2", "#eta^{jet 2}", 40, -2.5, 2.5) );
  Book( TH1F( "eta_jet3", "#eta^{jet 3}", 40, -2.5, 2.5) );
  Book( TH1F( "eta_jet4", "#eta^{jet 4}", 40, -2.5, 2.5) );

  // leptons
  Book( TH1F( "N_mu", "N^{#mu}", 10, 0, 10 ) );
  double* logPtlep_bins = MakeLogBinning(40, 45, 500);
  Book( TH1F( "pt_mu_lx", "p_{T}^{#mu} [GeV/c]", 40, logPtlep_bins ) );
  delete[] logPtlep_bins;
  
  Book( TH1F( "eta_mu", "#eta^{#mu}", 40, -2.1, 2.1) );
  Book( TH1F( "reliso_mu", "#mu rel. Iso", 40, 0, 0.5) );


  // primary vertices
  Book( TH1F( "N_pv", "N^{PV}", 50, 0, 50 ) );
  Book( TH1F( "N_events_perLumiBin", "N^{evt}", 24, 0, 24 ) );
  Book( TH1F( "N_pv_perLumiBin", "N^{PV}", 24, 0, 24 ) );

  //Generator level
  Book( TH1F( "pthadtop", "p_{T} Hadronic tops [GeV/c]", 50, 0 ,1000 ) );
  Book( TH1F( "pthiggsbb", "p_{T} Higgs bb [GeV/c]", 50, 0 ,1000 ) );
  Book( TH1F( "DRhiggsbb", "delta R bb [GeV/c]", 50, 0 ,4 ) );
  
  //cross-checks with Rebekka
  //HT
  Book( TH1F( "HTJets", "HT (GeV)", 50, 0, 3000));
  Book( TH1F( "HTJetsLept", "HT (GeV)", 50, 0, 3000));
  Book( TH1F( "HTSubJets", "HT (GeV)", 50, 0, 3000));
  Book( TH1F( "HTJetsSingleHiggsTagBin", "HT (GeV)", 50, 0, 3000));
  Book( TH1F( "HTJetsLeptSingleHiggsTagBin", "HT (GeV)", 50, 0, 3000));
  Book( TH1F( "HTSubJetsSingleHiggsTagBin", "HT (GeV)", 50, 0, 3000));
  Book( TH1F( "HTJetsMultiHiggsTagBin", "HT (GeV)", 50, 0, 3000));
  Book( TH1F( "HTJetsLeptMultiHiggsTagBin", "HT (GeV)", 50, 0, 3000));
  Book( TH1F( "HTSubJetsMultiHiggsTagBin", "HT (GeV)", 50, 0, 3000));

  //HTT Criteria
  Book( TH1F( "pairwiseMassCriterium1AllJets", "crit1", 50, 0, 1));
  Book( TH1F( "pairwiseMassCriterium2AllJets", "crit2", 50, 0, 1));
  Book( TH1F( "pairwiseMassCriterium1AfterTag", "crit1", 50, 0, 1));
  Book( TH1F( "pairwiseMassCriterium2AfterTag", "crit2", 50, 0, 1));
  Book( TH1F( "topCandidateMass", "mass of Top candidate (GeV)", 25, 0, 300));
 
  //DR cross-checks
  Book( TH1D( "DrclossubHiggs", "dr close", 20, 0, 2.));
  Book( TH1D( "DrclossubTop", "dr close", 20, 0, 2.));
  Book( TH1D( "DrclossubTopHTT", "dr close", 20, 0, 2.));

  //DR cross-checks < 0.4
  Book( TH1D( "DrclossubHiggs_low", "dr close", 20, 0, 2.));
  Book( TH1D( "DrclossubTop_low", "dr close", 20, 0, 2.));
  Book( TH1D( "DrclossubTopHTT_low", "dr close", 20, 0, 2.));

}

void BTVHists::Fill()
{
  // fill the histogram


  //cout << "###############EVENT " << endl;

  EventCalc* calc = EventCalc::Instance();
  bool IsRealData = calc->IsRealData();
  LuminosityHandler* lumih = calc->GetLumiHandler();
  BaseCycleContainer* bcc = calc->GetBaseCycleContainer();

  // important: get the event weight
  double weight = calc->GetWeight();

   if(!IsRealData){
    weight=weight*HiggsBRweight();
  }

  int run = calc->GetRunNum();
  int lumiblock = calc->GetLumiBlock();
  int Npvs = calc->GetPrimaryVertices()->size();

  // Generator level information
  TTbarGen* Decay = calc->GetTTbarGen();
  
  //Configuration stuff

  GenParticle topgen=Decay->Top();
  GenParticle antitopgen=Decay->Antitop();
  GenParticle btop=Decay->bTop();
  GenParticle bantitop=Decay->bAntitop();
  GenParticle wtop1=Decay->Wdecay1();
  GenParticle w=Decay->WTop();
  GenParticle antiw=Decay->WAntitop();
  GenParticle wtop2=Decay->Wdecay2();
  GenParticle wantitop1=Decay->WMinusdecay1();
  GenParticle wantitop2=Decay->WMinusdecay2();
  int decaytop=-99;
  decaytop=abs(Decay->Wdecay1().pdgId());
  int decayantitop=-99;
  decayantitop=abs(Decay->WMinusdecay1().pdgId());
  int goodtop=0;
  int goodantitop=0;
  
  if(decaytop>0&&decaytop<=5){
    goodtop=1;
    Hist("pthadtop")->Fill(topgen.pt(),weight); 
  }
  
  if(decayantitop>0&&decayantitop<=5){
    goodantitop=1;
    Hist("pthadtop")->Fill(antitopgen.pt(),weight); 
  }

  for(unsigned int ig=0; ig<bcc->genparticles->size(); ++ig){
    
    GenParticle genp = bcc->genparticles->at(ig); 

    if (abs(genp.pdgId()) == 25){
      
      if (genp.daughter(bcc->genparticles,1) && genp.daughter(bcc->genparticles,2)){

        if (abs(genp.daughter(bcc->genparticles,1)->pdgId()) == 5 && abs(genp.daughter(bcc->genparticles,2)->pdgId()) == 5){

	  int indexb1 = genp.daughter(bcc->genparticles,1)->index();
          int indexb2 = genp.daughter(bcc->genparticles,2)->index();
	  
           GenParticle b1_1 = bcc->genparticles->at(indexb1);
	   GenParticle b1_2 = bcc->genparticles->at(indexb2);

	  Hist("pthiggsbb")->Fill(bcc->genparticles->at(ig).pt(),weight);
	  Hist("DRhiggsbb")->Fill(b1_1.deltaR(b1_2));

	}
      }
    }
  }

  Hist("N_pv")->Fill(Npvs, weight);
  if(calc->IsRealData()){  
    Hist( "N_pv_perLumiBin")->Fill( lumih->GetLumiBin(run, lumiblock), Npvs*weight);
    Hist( "N_events_perLumiBin")->Fill( lumih->GetLumiBin(run, lumiblock), weight);
  }

  //double npu = bcc.genInfo->pileup_TrueNumInteractions();
  //if(npu>50) npu=49.9999;
  //Hist( "N_pileup_hist" )->Fill( npu, weight );

  MET* met = calc->GetMET();
  Hist("MET_lx")->Fill(met->pt(), weight);

  double HT = calc->GetHT();
  Hist("HT_lx")->Fill(HT, weight);

  double HTlep = calc->GetHTlep();
  Hist("HTlep_lx")->Fill(HTlep, weight);

  std::vector<Jet>* jets = calc->GetJets();
  int Njets = jets->size();
  Hist("N_jets_ly")->Fill(Njets, weight);

  if(Njets>=1){
    Hist("pt_jet1_lx")->Fill(jets->at(0).pt(), weight);
    Hist("eta_jet1")->Fill(jets->at(0).eta(), weight);
  }
  if(Njets>=2){
    Hist("pt_jet2_lx")->Fill(jets->at(1).pt(), weight);
    Hist("eta_jet2")->Fill(jets->at(1).eta(), weight);
  }
  if(Njets>=3){
    Hist("pt_jet3_lx")->Fill(jets->at(2).pt(), weight);
    Hist("eta_jet3")->Fill(jets->at(2).eta(), weight);
  }
  if(Njets>=4){
    Hist("pt_jet4_lx")->Fill(jets->at(3).pt(), weight);
    Hist("eta_jet4")->Fill(jets->at(3).eta(), weight);
  }

  std::vector<Muon>* muons = calc->GetMuons();
  int Nmuons = muons->size();
  Hist("N_mu")->Fill(Nmuons, weight);
  for (int i=0; i<Nmuons; ++i){
    Muon thismu = muons->at(i);
    Hist("pt_mu_lx")->Fill(thismu.pt(), weight);
    Hist("eta_mu")->Fill(thismu.eta(), weight);

    Hist("reliso_mu")->Fill(thismu.relIso(), weight);
  }

  //Reproduce cutflow
  std::vector<int> topTaggedJets;
  std::vector<int> HiggsTaggedJets;
  int finallySelected = 1;
  int indexTopCandidate = -99;
  int indexHiggsCandidate = -99;
  int nheptoptag=0;
  int nhiggstag=0;
  int nhiggstagWithCut=0;

  for(unsigned int i=0; i< bcc->topjets->size(); ++i){
    TopJet topjet =  bcc->topjets->at(i);

    if(HepTopTagWithMatch(topjet) && subJetBTagTop(topjet, e_CSVM, m_BTaggingMode, m_BTagEffiFilenameMC)>=1){
      nheptoptag++;
      topTaggedJets.push_back(i);
    }
    if (HiggsTag(topjet, e_CSVM, e_CSVM, m_BTaggingMode, m_BTagEffiFilenameMC)){
      nhiggstag++;
      if (HiggsMassFromBTaggedSubjets(topjet, e_CSVM, m_BTaggingMode, m_BTagEffiFilenameMC)>60.){
        nhiggstagWithCut ++;
        HiggsTaggedJets.push_back(i);
      }
    }
  }//loop over top jets

  if (nheptoptag == 0){
    finallySelected = 0;
    if (nhiggstagWithCut != 0){
      indexHiggsCandidate = HiggsTaggedJets[0];
    }
  }
  if (nhiggstagWithCut == 0){
    finallySelected = 0; 
    if(nheptoptag != 0){
      indexTopCandidate = topTaggedJets[0];
    }
  }
  if(nheptoptag == 1 && nhiggstagWithCut == 1 && topTaggedJets[0] == HiggsTaggedJets[0]){
    finallySelected = 0;
    indexTopCandidate = topTaggedJets[0];
  } 
  if (finallySelected == 1){
    if (topTaggedJets[0] != HiggsTaggedJets[0]){
      indexTopCandidate = topTaggedJets[0];
      indexHiggsCandidate = HiggsTaggedJets[0];
    }
    if (topTaggedJets[0] == HiggsTaggedJets[0]){
      if (HiggsTaggedJets.size()>1){
        indexTopCandidate = topTaggedJets[0];
        indexHiggsCandidate = HiggsTaggedJets[1];
      }
      if(topTaggedJets.size()>1){
        indexTopCandidate = topTaggedJets[1];
        indexHiggsCandidate = HiggsTaggedJets[0];
      }     
    }
  }

  std::vector<Particle> subjets_top;
  std::vector<Particle> subjets_htt;
  std::vector<Particle> subjets_higgs;

  if (indexHiggsCandidate != -99 && indexTopCandidate!= -99){
    
    TopJet higgsCandidateJet=bcc->topjets->at(indexHiggsCandidate);
    TopJet topCandidateJet=bcc->topjets->at(indexTopCandidate);

    //find htt matched jets
    TopJet nextjet;

    double deltarmin = double_infinity();

    for(unsigned int it=0; it<bcc->toptagjets->size();++it){
     
      TopJet top4jet=bcc->toptagjets->at(it);

      if(top4jet.deltaR(topCandidateJet) < deltarmin){
	deltarmin = top4jet.deltaR(topCandidateJet);
	nextjet = top4jet;
      }
      
    }

    if(deltarmin<0.3){
      
      subjets_htt = nextjet.subjets();
      
      double dr12=subjets_htt[0].deltaR(subjets_htt[1]);
      double dr13=subjets_htt[0].deltaR(subjets_htt[2]);
      double dr23=subjets_htt[1].deltaR(subjets_htt[2]);
      
      if(dr12<=dr13&&dr12<=dr23){
	Hist("DrclossubTopHTT")->Fill(dr12,weight);
	if(dr12<0.4){
	  Hist("DrclossubTopHTT_low")->Fill(dr12,weight);
	}
      }
      else if(dr13<=dr12&&dr13<=23){
	Hist("DrclossubTopHTT")->Fill(dr13,weight);
	if(dr13<0.4){
	  Hist("DrclossubTopHTT_low")->Fill(dr13,weight);
	}
      }
      else if(dr23<=dr12&&dr23<=dr13){
	Hist("DrclossubTopHTT")->Fill(dr23,weight);
	if(dr23<0.4){
	  Hist("DrclossubTopHTT_low")->Fill(dr23,weight);
	}
      }
      
    }//matched htt
   
    //subjet studies top
    
    subjets_top = topCandidateJet.subjets();
    subjets_higgs = higgsCandidateJet.subjets();

    double dr12=subjets_top[0].deltaR(subjets_top[1]);
    double dr13=subjets_top[0].deltaR(subjets_top[2]);
    double dr23=subjets_top[1].deltaR(subjets_top[2]);

    if(dr12<=dr13&&dr12<=dr23){
      Hist("DrclossubTop")->Fill(dr12,weight);
      if(dr12<0.4){
	Hist("DrclossubTop_low")->Fill(dr12,weight);
      }
    }
    else if(dr13<=dr12&&dr13<=23){
      Hist("DrclossubTop")->Fill(dr13,weight);
      if(dr13<0.4){
	Hist("DrclossubTop_low")->Fill(dr13,weight);
      }
    }
    else if(dr23<=dr12&&dr23<=dr13){
      Hist("DrclossubTop")->Fill(dr23,weight);
      if(dr23<0.4){
	Hist("DrclossubTop_low")->Fill(dr23,weight);
      }
    }

    //subjet studies higgs
    
    dr12=subjets_higgs[0].deltaR(subjets_higgs[1]);
    dr13=subjets_higgs[0].deltaR(subjets_higgs[2]);
    dr23=subjets_higgs[1].deltaR(subjets_higgs[2]);

    if(dr12<=dr13&&dr12<=dr23){
      Hist("DrclossubHiggs")->Fill(dr12,weight);
      if(dr12<0.4){
	Hist("DrclossubHiggs_low")->Fill(dr12,weight);
      }
    }
    else if(dr13<=dr12&&dr13<=23){
      Hist("DrclossubHiggs")->Fill(dr13,weight);
      if(dr13<0.4){
	Hist("DrclossubHiggs_low")->Fill(dr13,weight);
      }
    }
    else if(dr23<=dr12&&dr23<=dr13){
      Hist("DrclossubHiggs")->Fill(dr23,weight);
      if(dr23<0.4){
	Hist("DrclossubHiggs_low")->Fill(dr23,weight);
      }
    }
 
  }

  //Cross-checks with Rebekka

  double HTJets = 0.;
  double HTJetsLept = 0.;
  double HTSubJets = 0.;

  for (unsigned int itj=0;itj<bcc->jets->size();itj++){
    //cout << "Jet " << itj << " pt " << bcc->jets->at(itj).pt() << " jec " << bcc->jets->at(itj).JEC_factor_raw() << endl;
    if(bcc->jets->at(itj).pt()<40.) continue;
    HTJets += jets->at(itj).pt();
  }

  HTJetsLept = calc->GetHT();
 
 for (unsigned int itj = 0; itj < bcc->topjets->size(); itj++){
   if(bcc->topjets->at(itj).pt()<150.) continue;
   //cout << "TOPJet " << itj << " pt " << bcc->topjets->at(itj).pt() << " jec " << bcc->topjets->at(itj).JEC_factor_raw() << endl;
    TopJet topjet = bcc->topjets->at(itj);
    subjets_top=topjet.subjets();
    std::vector<float> subjets_JECraw;
    subjets_JECraw=topjet.subJEC_raw();
    for (unsigned int subj = 0; subj < subjets_top.size(); subj++){
      //cout << "===> subjet TOPJet " << subj << " pt " << subjets_top.at(subj).pt() << " jec " << subjets_JECraw[subj] << endl;
      HTSubJets += subjets_top.at(subj).pt();
    }
 }

 int higgstags=0;
 
 for(int i =0; i<bcc->topjets->size(); i++ ){
   TopJet myJet = bcc->topjets->at(i);
   if(HiggsTag(myJet, e_CSVM, e_CSVM, m_BTaggingMode, m_BTagEffiFilenameMC)) higgstags+=1;
   Hist("pairwiseMassCriterium1AllJets") -> Fill(HepTopTagPairwiseMassWithMatch1(myJet), weight);
   Hist("pairwiseMassCriterium2AllJets") -> Fill(HepTopTagPairwiseMassWithMatch2(myJet), weight);
   
   if (HepTopTagWithMatch(myJet)){
     Hist("pairwiseMassCriterium1AfterTag") -> Fill(HepTopTagPairwiseMassWithMatch1(myJet), weight);
     Hist("pairwiseMassCriterium2AfterTag") -> Fill(HepTopTagPairwiseMassWithMatch2(myJet), weight);
   }
   
 }
 
 Hist("HTJets")-> Fill(HTJets, weight);
 Hist("HTJetsLept")-> Fill(HTJetsLept, weight);
 if(HTSubJets>720) Hist("HTSubJets")-> Fill(HTSubJets, weight);

 if(higgstags==1){
   if(HTJets>1000) Hist("HTJetsSingleHiggsTagBin")-> Fill(HTJets, weight);
   if(HTJetsLept>1380) Hist("HTJetsLeptSingleHiggsTagBin")-> Fill(HTJetsLept, weight);
   if(HTSubJets>720) Hist("HTSubJetsSingleHiggsTagBin")-> Fill(HTSubJets, weight);
 }
 if(higgstags>=2){
   if(HTJets>1000) Hist("HTJetsMultiHiggsTagBin")-> Fill(HTJets, weight);
   if(HTJetsLept>1380) Hist("HTJetsLeptMultiHiggsTagBin")-> Fill(HTJetsLept, weight);
   if(HTSubJets>720) Hist("HTSubJetsMultiHiggsTagBin")-> Fill(HTSubJets, weight);
 }

}

void BTVHists::Finish()
{
  // final calculations, like division and addition of certain histograms
  EventCalc* calc = EventCalc::Instance();
  bool IsRealData = calc->IsRealData();
  if (IsRealData){
    Hist("N_pv_perLumiBin")->Divide( Hist("N_pv_perLumiBin"), Hist("N_events_perLumiBin"));
    Hist( "N_pv_perLumiBin")->GetYaxis()->SetTitle("Events/Lumi");
  }

}

