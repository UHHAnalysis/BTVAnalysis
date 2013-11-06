#include "include/SemileptonicselectionHists.h"
#include "SFrameTools/include/EventCalc.h"
#include <iostream>
#include <iostream>
#include "TH3.h"

using namespace std;

SemileptonicselectionHists::SemileptonicselectionHists(const char* name, TString filename) : BaseHists(name)
{
  // named default constructor
  m_filename=filename;
}

SemileptonicselectionHists::~SemileptonicselectionHists()
{
  // default destructor, does nothing
}

void SemileptonicselectionHists::Init()
{
  // book all histograms here

  double jetpt_bbins[] = {
    20, 30, 40, 50, 60, 70, 80, 100, 120, 160, 210, 260, 320, 400, 500, 600, 800, 1600
  };

  Book( TH1F( "N_topjets", ";N^{jets};Events", 20, 0, 20 ) );
  Book( TH1F( "N_topjets_had", ";N^{jets};Events", 20, 0, 20 ) );
  Book( TH1D( "MassTop_had", ";Top jet mass (GeV);Events", 50, 0, 500));
  Book( TH1D( "Toppt_had", ";Pt top-jet (GeV);Events", 25, 0, 1000));  
  Book( TH1F( "N_mu", ";N^{muons};Events", 5, 0, 5 ) );
  Book( TH1F( "N_pv", ";N^{PV};Events", 50, 0, 50 ) );
  Book( TH1F( "N_events_perLumiBin", ";N^{evt};Events", 24, 0, 24 ) );
  Book( TH1F( "N_pv_perLumiBin", ";N^{PV};Events", 24, 0, 24 ) );
  Book( TH1D( "DR_Mub", ";DR muon-b;Events", 100, 0, 6.28));
  Book( TH1D( "DR_Sum", ";DR sum;Events", 100, 0, 6.28));
  Book( TH1D( "DPhi_Mub", ";DPhi muon-b;Events", 100, 0, 6.28));
  Book( TH1D( "DR_Mutop", ";DR muon-top;Events", 100, 0, 6.28));
  Book( TH1D( "DPhi_Mutop", ";DPhi muon-top;Events", 100, 0, 6.28));
  Book( TH1D( "DR_btop", ";DR b-top;Events", 100, 0, 6.28));
  Book( TH1D( "DPhi_btop", ";DPhi b-top;Events", 100, 0, 6.28));
  Book( TH1D( "MassTop", ";Top jet mass (GeV);Events", 50, 0, 500));
  Book( TH1D( "MassTop_1", ";Top jet mass (GeV);Events", 50, 0, 500));
  Book( TH1D( "Pt_b_sub", ";Pt b-subjet (GeV);Events", 17, jetpt_bbins));
  Book( TH1D( "Pt_HEPb_sub", ";Pt HEP-b-subjet (GeV);Events", 17, jetpt_bbins));
  Book( TH1D( "Pt_HEP_sub", ";Pt HEP-b-subjet (GeV);Events", 17, jetpt_bbins));
  Book( TH1D( "Pt_HEPnonb_sub", ";Pt HEP-nonb-subjet (GeV);Events", 17, jetpt_bbins));
  Book( TH1D( "Pt_nonb_sub", ";Pt non-b-subjet (GeV);Events", 17, jetpt_bbins));
  Book( TH1D( "Pt_tagged_sub", ";Pt non-b-subjet (GeV);Events", 17, jetpt_bbins));
  Book( TH1D( "Eta_tagged_sub", ";Eta non-b-subjet (GeV);Events", 100,-4,4));
  Book( TH1D( "Phi_tagged_sub", ";Phi non-b-subjet (GeV);Events", 100,-4,4));
  Book( TH1D( "Pt_all_sub", ";Pt all subjets (GeV);Events", 17, jetpt_bbins));
  Book( TH1D( "Eta_all_sub", ";Eta all subjets (GeV);Events", 100, -4.,4.));
  Book( TH1D( "Phi_all_sub", ";Phi all subjets (GeV);Events", 100, -4.,4.));
  Book( TH1D( "Pt_all_sub_nobin", ";Pt all subjets (GeV);Events", 40, 0, 500));
  Book( TH1D( "Toppt", ";Pt top-jet (GeV);Events", 25, 0, 1000));
  Book( TH1D( "Toppt_1", ";Pt top-jet (GeV);Events", 25, 0, 1000));
  Book( TH1D( "N_tagged_sub", ";Number tagged top-subjets;Events", 4, 0, 4));
  Book( TH1D( "N_all_b", ";Number all top b-subjets;Events", 1, 0, 1));
  Book( TH1D( "N_all_c", ";Number all top c-subjets;Events", 1, 0, 1));
  Book( TH1D( "N_all_l", ";Number all top l-subjets;Events", 1, 0, 1));
  Book( TH1D( "N_all_no", ";Number all top no flavor-subjets;Events", 1, 0, 1));
  Book( TH1D( "N_tagged_b", ";Number tagged top b-subjets;Events", 1, 0, 1));
  Book( TH1D( "N_tagged_b_uncorr", ";Number tagged top b-subjets no scale factor;Events", 1, 0, 1));
  Book( TH1D( "N_tagged_c_uncorr", ";Number tagged top c-subjets no scale factor;Events", 1, 0, 1));
  Book( TH1D( "N_tagged_l_uncorr", ";Number tagged top l-subjets no scale factor;Events", 1, 0, 1));
  Book( TH1D( "N_tagged_c", ";Number tagged top c-subjets;Events", 1, 0, 1));
  Book( TH1D( "N_tagged_l", ";Number tagged top l-subjets;Events", 1, 0, 1));
  Book( TH1D( "N_tagged_no", ";Number tagged top no flavor-subjets;Events", 1, 0, 1));
  Book( TH1D( "N_all0_b", ";Number all top b-subjets;Events", 1, 0, 1));
  Book( TH1D( "N_all0_c", ";Number all top c-subjets;Events", 1, 0, 1));
  Book( TH1D( "N_all0_l", ";Number all top l-subjets;Events", 1, 0, 1));
  Book( TH1D( "N_all0_no", ";Number all top no flavor-subjets;Events", 1, 0, 1));
  Book( TH1D( "N_tagged0_b", ";Number tagged top b-subjets;Events", 1, 0, 1));
  Book( TH1D( "N_tagged0_c", ";Number tagged top c-subjets;Events", 1, 0, 1));
  Book( TH1D( "N_tagged0_l", ";Number tagged top l-subjets;Events", 1, 0, 1));
  Book( TH1D( "N_tagged0_no", ";Number tagged top no flavor-subjets;Events", 1, 0, 1));
  Book( TH1D( "N_all1_b", ";Number all top b-subjets;Events", 1, 0, 1));
  Book( TH1D( "N_all1_c", ";Number all top c-subjets;Events", 1, 0, 1));
  Book( TH1D( "N_all1_l", ";Number all top l-subjets;Events", 1, 0, 1));
  Book( TH1D( "N_all1_no", ";Number all top no flavor-subjets;Events", 1, 0, 1));
  Book( TH1D( "N_tagged1_b", ";Number tagged top b-subjets;Events", 1, 0, 1));
  Book( TH1D( "N_tagged1_c", ";Number tagged top c-subjets;Events", 1, 0, 1));
  Book( TH1D( "N_tagged1_l", ";Number tagged top l-subjets;Events", 1, 0, 1));
  Book( TH1D( "N_tagged1_no", ";Number tagged top no flavor-subjets;Events", 1, 0, 1));
  Book( TH1D( "N_all2_b", ";Number all top b-subjets;Events", 1, 0, 1));
  Book( TH1D( "N_all2_c", ";Number all top c-subjets;Events", 1, 0, 1));
  Book( TH1D( "N_all2_l", ";Number all top l-subjets;Events", 1, 0, 1));
  Book( TH1D( "N_all2_no", ";Number all top no flavor-subjets;Events", 1, 0, 1));
  Book( TH1D( "N_tagged2_b", ";Number tagged top b-subjets;Events", 1, 0, 1));
  Book( TH1D( "N_tagged2_c", ";Number tagged top c-subjets;Events", 1, 0, 1));
  Book( TH1D( "N_tagged2_l", ";Number tagged top l-subjets;Events", 1, 0, 1));
  Book( TH1D( "N_tagged2_no", ";Number tagged top no flavor-subjets;Events", 1, 0, 1));
  Book( TH1D( "N_all3_b", ";Number all top b-subjets;Events", 1, 0, 1));
  Book( TH1D( "N_all3_c", ";Number all top c-subjets;Events", 1, 0, 1));
  Book( TH1D( "N_all3_l", ";Number all top l-subjets;Events", 1, 0, 1));
  Book( TH1D( "N_all3_no", ";Number all top no flavor-subjets;Events", 1, 0, 1));
  Book( TH1D( "N_tagged3_b", ";Number tagged top b-subjets;Events", 1, 0, 1));
  Book( TH1D( "N_tagged3_c", ";Number tagged top c-subjets;Events", 1, 0, 1));
  Book( TH1D( "N_tagged3_l", ";Number tagged top l-subjets;Events", 1, 0, 1));
  Book( TH1D( "N_tagged3_no", ";Number tagged top no flavor-subjets;Events", 1, 0, 1));
  Book( TH1D( "N_b_0tags", ";Number top b-subjets in 0tags tops;Events", 4, 0, 4));
  Book( TH1D( "N_c_0tags", ";Number top c-subjets in 0tags tops;Events", 4, 0, 4));
  Book( TH1D( "N_l_0tags", ";Number top l-subjets in 0tags tops;Events", 4, 0, 4));
  Book( TH1D( "N_no_0tags", ";Number top no flavor-subjets in 0tags tops;Events", 4, 0, 4));
  Book( TH1D( "N_b_1tags", ";Number top b-subjets in 1tags tops;Events", 4, 0, 4));
  Book( TH1D( "N_c_1tags", ";Number top c-subjets in 1tags tops;Events", 4, 0, 4));
  Book( TH1D( "N_l_1tags", ";Number top l-subjets in 1tags tops;Events", 4, 0, 4));
  Book( TH1D( "N_no_1tags", ";Number top no flavor-subjets in 1tags tops;Events", 4, 0, 4));
  Book( TH1D( "N_b_2tags", ";Number top b-subjets in 2tags tops;Events", 4, 0, 4));
  Book( TH1D( "N_c_2tags", ";Number top c-subjets in 2tags tops;Events", 4, 0, 4));
  Book( TH1D( "N_l_2tags", ";Number top l-subjets in 2tags tops;Events", 4, 0, 4));
  Book( TH1D( "N_no_2tags", ";Number top no flavor-subjets in 2tags tops;Events", 4, 0, 4));
  Book( TH1D( "N_b_3tags", ";Number top b-subjets in 3tags tops;Events", 4, 0, 4));
  Book( TH1D( "N_c_3tags", ";Number top c-subjets in 3tags tops;Events", 4, 0, 4));
  Book( TH1D( "N_l_3tags", ";Number top l-subjets in 3tags tops;Events", 4, 0, 4));
  Book( TH1D( "N_no_3tags", ";Number top no flavor-subjets in 3tags tops;Events", 4, 0, 4));
  Book( TH3D( "Fijk", ";flavor fractions;Events", 4, 0, 4, 4, 0, 4, 4, 0, 4));
  Book( TH1D( "Pat_flav", ";flavor pat;Events", 4, 0, 4));
  Book( TH1D( "Pat_flav_drcut", ";flavor pat;Events", 4, 0, 4));
  Book( TH2D( "Pat_flav_dr", ";flavor pat;dr", 4, 0, 4, 100, 0, 6.28));
  Book( TH1D( "My_flav_3", ";my flavor 0.3 cone;Events", 4, 0, 4));
  Book( TH1D( "My_flav_2", ";my flavor 0.2 cone;Events", 4, 0, 4));
  Book( TH1D( "My_flav_1", ";my flavor 0.1 cone;Events", 4, 0, 4));
  Book( TH1F( "Fract_4", ";flavor fractions;Events", 3334, 0, 3334));
  Book( TH1F( "Fract_4_drcut", ";flavor fractions;Events", 3334, 0, 3334));
  Book( TH1F( "Fract_4_no", ";flavor fractions no no;Events", 3334, 0, 3334));

}

void SemileptonicselectionHists::Fill()
{

  // fill the histograms

  EventCalc* calc = EventCalc::Instance();
  bool IsRealData = calc->IsRealData();
  LuminosityHandler* lumih = calc->GetLumiHandler();

  // important: get the event weight
  double weight = calc->GetWeight();

  int run = calc->GetRunNum();
  int lumiblock = calc->GetLumiBlock();
  int Npvs = calc->GetPrimaryVertices()->size();

  //ObjectHandler* objs = ObjectHandler::Instance();
  BaseCycleContainer* bcc = calc->GetBaseCycleContainer();

  GenParticle part1, part2, part3;

  double drsum=0.;

  if(!IsRealData){
  //Filling generator-level information for semi-leptonic ttbar events
  TTbarGen* Decay = calc->GetTTbarGen();

  GenParticle topgen=Decay->Top();
  GenParticle antitopgen=Decay->Antitop();
  GenParticle btop=Decay->bTop();
  GenParticle bantitop=Decay->bAntitop();
  int decaytop=abs(Decay->Wdecay1().pdgId());
  int decayantitop=abs(Decay->WMinusdecay1().pdgId());
  int semileptop=0;
  int semilepantitop=0;
  GenParticle muongen;

  if((decaytop==13||decaytop==14)&&decayantitop>0&&decayantitop<=5){
    semileptop=1;
    if(decaytop==13){
      muongen=Decay->Wdecay1();
    }
    if(decaytop==14){
      muongen=Decay->Wdecay2();
    }
  }
  if((decayantitop==13||decayantitop==14)&&decaytop>0&&decaytop<=5){
    semilepantitop=1;
    if(decayantitop==13){
      muongen=Decay->WMinusdecay1();
    }
    if(decaytop==14){
      muongen=Decay->WMinusdecay2();
    }
  }

  if(semileptop){
    part1=Decay->bAntitop();
    part2=Decay->WMinusdecay1();
    part3=Decay->WMinusdecay2();
    Hist("DR_Mub")->Fill(muongen.deltaR(btop),weight);
    Hist("DPhi_Mub")->Fill(muongen.deltaPhi(btop),weight);
    Hist("DR_Mutop")->Fill(muongen.deltaR(antitopgen),weight);
    Hist("DPhi_Mutop")->Fill(muongen.deltaPhi(antitopgen),weight);
    Hist("DR_btop")->Fill(btop.deltaR(antitopgen),weight);
    Hist("DPhi_btop")->Fill(btop.deltaPhi(antitopgen),weight);
  }

  if(semilepantitop){
    part1=Decay->bTop();
    part2=Decay->Wdecay1();
    part3=Decay->Wdecay2();
    Hist("DR_Mub")->Fill(muongen.deltaR(bantitop),weight);
    Hist("DPhi_Mub")->Fill(muongen.deltaPhi(bantitop),weight);
    Hist("DR_Mutop")->Fill(muongen.deltaR(topgen),weight);
    Hist("DPhi_Mutop")->Fill(muongen.deltaPhi(topgen),weight);
    Hist("DR_btop")->Fill(bantitop.deltaR(topgen),weight);
    Hist("DPhi_btop")->Fill(bantitop.deltaPhi(topgen),weight);
  }

  }//if Monte Carlo

  Hist("N_pv")->Fill(Npvs, weight);
  if(calc->IsRealData()){  
    Hist( "N_pv_perLumiBin")->Fill( lumih->GetLumiBin(run, lumiblock), Npvs*weight);
  Hist( "N_events_perLumiBin")->Fill( lumih->GetLumiBin(run, lumiblock), weight);
  }

  //double npu = bcc.genInfo->pileup_TrueNumInteractions();
  //if(npu>50) npu=49.9999;
  //Hist( "N_pileup_hist" )->Fill( npu, weight );

  //MET* met = calc->GetMET();
  //Hist("MET_lx")->Fill(met->pt(), weight);

  //double HT = calc->GetHT();
  //Hist("HT_lx")->Fill(HT, weight);

  //double HTlep = calc->GetHTlep();
  //Hist("HTlep_lx")->Fill(HTlep, weight);

  int Ntopjets = bcc->topjets->size();
  Hist("N_topjets")->Fill(Ntopjets, weight);

  std::vector<Muon>* muons = calc->GetMuons();
  int Nmuons = muons->size();
  Hist("N_mu")->Fill(Nmuons, weight);

  //for (int i=0; i<Nmuons; ++i){
  //Muon thismu = muons->at(i);
  //Hist("pt_mu_lx")->Fill(thismu.pt(), weight);
  //Hist("eta_mu")->Fill(thismu.eta(), weight);
  //Hist("reliso_mu")->Fill(thismu.relIso(), weight);
  //}

  double limpt=0;
  int indexjet=-99999;

  int countjets=0;

  std::vector<Particle> subjets_top;
  std::vector<float> btagsub_combinedSecondaryVertex_top;
  std::vector<int> flavorsub_top;

  int counthadjets=0;

  for(unsigned int i=0; i<bcc->topjets->size(); ++i) {

    //control plots
    LorentzVector all3subjets(0,0,0,0);

    double mjetall=0;
    double deltaphi=-99999.;

    if(bcc->muons->size()>0){
      deltaphi=bcc->topjets->at(i).deltaPhi(bcc->muons->at(0));
    }
 
    if((deltaphi>(2*PI/3))&&(bcc->topjets->at(i).pt()>150.)&&(fabs(bcc->topjets->at(i).eta())<2.5)){

      counthadjets+=1;

      for(unsigned int j=0; j < 3; ++j){
	
        all3subjets += bcc->topjets->at(i).subjets()[j].v4();
      }
      
      if(!all3subjets.isTimelike()) {
        mjetall=0;
      }
      else{
	mjetall = all3subjets.M();
      }
      
      Hist("MassTop_had")->Fill(mjetall,weight);
      
      Hist("Toppt_had")->Fill(bcc->topjets->at(i).pt(),weight);
      
    }//control plots hadronic side

    Hist("N_topjets_had")->Fill(counthadjets, weight);

    int jettagged=0;
   
    subjets_top=bcc->topjets->at(i).subjets();
    btagsub_combinedSecondaryVertex_top=bcc->topjets->at(i).btagsub_combinedSecondaryVertex();
    
    for(unsigned int j=0; j < btagsub_combinedSecondaryVertex_top.size(); ++j){
      
      if(j==0){
	LorentzVector v01=subjets_top[0].v4()+subjets_top[1].v4();
	double m01=0;
	if(v01.isTimelike()) {
	  m01=abs(v01.M()-80.4);
	}
	LorentzVector v12=subjets_top[1].v4()+subjets_top[2].v4();
	double m12=0;
	if(v12.isTimelike()) {
	  m12=abs(v12.M()-80.4);
	}
	LorentzVector v02=subjets_top[0].v4()+subjets_top[2].v4();
	double m02=0;
	if(v02.isTimelike()) {
	  m02=abs(v02.M()-80.4);
	}
	if(m01<=m12&&m01<=m02){
	  //cout << "Mass b is 3" << endl;
	}
	if(m12<=m01&&m12<=m02){
	  cout << "Mass b is 1" << endl;
	}
	if(m02<=m12&&m02<=m01){
	  cout << "Mass b is 2" << endl;
	}
	
      }

      float test=btagsub_combinedSecondaryVertex_top[j];

      //if(test>0.244) jettagged=1;
      if(test>0.679) jettagged=1;
      //if(test>0.898) jettagged=1;
      
    }

    jettagged=0;

    if(HepTopTag(bcc->topjets->at(i))){

	 jettagged=1;

    }
      
    if(bcc->muons->size()>0){
      double deltaphi=bcc->topjets->at(i).deltaPhi(bcc->muons->at(0));
    
      if(jettagged&&(deltaphi>(2*PI/3))&&(bcc->topjets->at(i).pt()>150.)&&(fabs(bcc->topjets->at(i).eta())<2.5)){
	
	countjets=countjets+1;

	if(bcc->topjets->at(i).pt()>limpt){

	  indexjet=i;
	  limpt=bcc->topjets->at(i).pt();

	}
    
      }
    }
    
  }//loop over top jets
  
  if(indexjet!=-99999&&bcc->topjets->at(indexjet).pt()>150.){
  
    LorentzVector allsubjets(0,0,0,0);

    double mjet=0;

    for(unsigned int j=0; j < 3; ++j){

        allsubjets += bcc->topjets->at(indexjet).subjets()[j].v4();
    }
  
    if(!allsubjets.isTimelike()) {
        mjet=0;
    }
    else{
      mjet = allsubjets.M();
    }

    //uncomments to have mass jet from jet and not from sum subjets
    mjet=bcc->topjets->at(indexjet).v4().M();

    Hist("MassTop")->Fill(mjet,weight);

    Hist("Toppt")->Fill(bcc->topjets->at(indexjet).pt(),weight);

    if(countjets==1){

      Hist("MassTop_1")->Fill(mjet,weight);

      Hist("Toppt_1")->Fill(bcc->topjets->at(indexjet).pt(),weight);

    }

    subjets_top=bcc->topjets->at(indexjet).subjets();
    btagsub_combinedSecondaryVertex_top=bcc->topjets->at(indexjet).btagsub_combinedSecondaryVertex();
    flavorsub_top=bcc->topjets->at(indexjet).flavorsub();

    drsum=0.;
    
    for(unsigned int k=0; k < 3; ++k){
      
      double drsummin=min(subjets_top[k].deltaR(part1),min(subjets_top[k].deltaR(part2),subjets_top[k].deltaR(part3)));
      
      drsum+=drsummin*drsummin;

    }

    Hist("DR_Sum")->Fill(drsum,weight);

    int countL=0;
    int countT=0;

    int counttags=0;
    int counttagsb=0;
    int counttagsc=0;
    int counttagsl=0;
    int counttagsno=0;

    int countall=0;
    int countb=0;
    int countc=0;
    int countl=0;
    int countno=0;

    int countbmy3=0;
    int countcmy3=0;
    int countlmy3=0;
    int countnomy3=0;

    int countbmy2=0;
    int countcmy2=0;
    int countlmy2=0;
    int countnomy2=0;

    int countbmy1=0;
    int countcmy1=0;
    int countlmy1=0;
    int countnomy1=0;

    for(unsigned int j=0; j < btagsub_combinedSecondaryVertex_top.size(); ++j){
      
      Hist("Pt_all_sub")->Fill(subjets_top[j].pt(),weight);
      Hist("Eta_all_sub")->Fill(subjets_top[j].eta(),weight);
      Hist("Phi_all_sub")->Fill(subjets_top[j].phi(),weight);
      Hist("Pt_all_sub_nobin")->Fill(subjets_top[j].pt(),weight);
      if(!calc->IsRealData()){  
	if(abs(flavorsub_top[j])==5&&j==2) Hist("Pt_HEPb_sub")->Fill(subjets_top[j].pt(),weight);
      }
      if(j==2) Hist("Pt_HEP_sub")->Fill(subjets_top[j].pt(),weight);
      if(!calc->IsRealData()){  
	if(abs(flavorsub_top[j])!=5&&j==2) Hist("Pt_HEPnonb_sub")->Fill(subjets_top[j].pt(),weight);
      }
      
      int isbtagged=0;

      if(btagsub_combinedSecondaryVertex_top[j]>0.679&&abs(flavorsub_top[j])==5) Hist("N_tagged_b_uncorr")->Fill(0.5,weight);
      if(btagsub_combinedSecondaryVertex_top[j]>0.679&&abs(flavorsub_top[j])==4) Hist("N_tagged_c_uncorr")->Fill(0.5,weight);
      if(btagsub_combinedSecondaryVertex_top[j]>0.679&&(abs(flavorsub_top[j])==1||abs(flavorsub_top[j])==2||abs(flavorsub_top[j])==3||abs(flavorsub_top[j])==21)) Hist("N_tagged_l_uncorr")->Fill(0.5,weight);

      //if(btagsub_combinedSecondaryVertex_top[j]>0.244) isbtagged=1;
      //if(btagsub_combinedSecondaryVertex_top[j]>0.679) isbtagged=1;
      //if(btagsub_combinedSecondaryVertex_top[j]> 0.898) isbtagged=1;

      //if(((abs(flavorsub_top[j])==1||abs(flavorsub_top[j])==2||abs(flavorsub_top[j])==3||abs(flavorsub_top[j])==21||abs(flavorsub_top[j])==4))&&(m_filename!="")){
      ///if(((abs(flavorsub_top[j])==1||abs(flavorsub_top[j])==2||abs(flavorsub_top[j])==3||abs(flavorsub_top[j])==21||abs(flavorsub_top[j])==4)||abs(flavorsub_top[j])==5)&&(m_filename!="")){
      //if((abs(flavorsub_top[j])==4)&&(m_filename!="")){
      //if((!calc->IsRealData())&&(m_filename!="")){  
	
      //isbtagged=subJetBTagOne(bcc->topjets->at(indexjet), e_CSVM, "mean", m_filename, j);
	
      //}
      
      //if(((abs(flavorsub_top[j])==1||abs(flavorsub_top[j])==2||abs(flavorsub_top[j])==3||abs(flavorsub_top[j])==21))&&(m_filename!="")){
      //isbtagged=subJetBTagOne(bcc->topjets->at(indexjet), e_CSVL, "mean", m_filename, j);
      //}
      //else if((abs(flavorsub_top[j])==4)&&(m_filename!="")){
      //isbtagged=subJetBTagOne(bcc->topjets->at(indexjet), e_CSVL, "mean", m_filename, j);
      //}
      //else if((abs(flavorsub_top[j])==4||abs(flavorsub_top[j])==5)&&(m_filename!="")){
      //isbtagged=subJetBTagOne(bcc->topjets->at(indexjet), e_CSVL, "mean", m_filename, j);
      //}
      //else{
      if(btagsub_combinedSecondaryVertex_top[j]>0.679) isbtagged=1;
      //}
      
      //if(btagsub_combinedSecondaryVertex_top[j]>0.679) isbtagged=1;
      

      if(btagsub_combinedSecondaryVertex_top[j]>0.244) countL+=1;
      if(btagsub_combinedSecondaryVertex_top[j]>0.898) countT+=1;

      if(isbtagged){

	counttags=counttags+1;

	if(!calc->IsRealData()){  
	  if(abs(flavorsub_top[j])==5) counttagsb=counttagsb+1;
	  else if(abs(flavorsub_top[j])==4) counttagsc=counttagsc+1;
	  //else counttagsl=counttagsl+1;
	  else if(abs(flavorsub_top[j])==1||abs(flavorsub_top[j])==2||abs(flavorsub_top[j])==3||abs(flavorsub_top[j])==21) counttagsl=counttagsl+1;
	  else counttagsno=counttagsno+1;
	}

	Hist("Pt_tagged_sub")->Fill(subjets_top[j].pt(),weight);
	Hist("Eta_tagged_sub")->Fill(subjets_top[j].eta(),weight);
	Hist("Phi_tagged_sub")->Fill(subjets_top[j].phi(),weight);

	if(!calc->IsRealData()){  
	  if(abs(flavorsub_top[j])==5) Hist("Pt_b_sub")->Fill(subjets_top[j].pt(),weight);
	  if(abs(flavorsub_top[j])!=5) Hist("Pt_nonb_sub")->Fill(subjets_top[j].pt(),weight);
	}

      }
      
      countall=countall+1;
      
      if(!calc->IsRealData()){  
	if(abs(flavorsub_top[j])==5) countb=countb+1;
	else if(abs(flavorsub_top[j])==4) countc=countc+1;
	//else countl=countl+1;
	else if(abs(flavorsub_top[j])==1||abs(flavorsub_top[j])==2||abs(flavorsub_top[j])==3||abs(flavorsub_top[j])==21) countl=countl+1;
	else countno=countno+1;
      }

      if(!calc->IsRealData()){  
	
	int myflav3=abs(SubJetFlavor(bcc->topjets->at(indexjet),j,0.3));
	int myflav2=abs(SubJetFlavor(bcc->topjets->at(indexjet),j,0.2));
	int myflav1=abs(SubJetFlavor(bcc->topjets->at(indexjet),j,0.1));

	if(myflav3==5) countbmy3=countbmy3+1;
	else if(myflav3==4) countcmy3=countcmy3+1;
	else if(myflav3==1||myflav3==2||myflav3==3||myflav3==21) countlmy3=countlmy3+1;
	else countnomy3=countnomy3+1;

	if(myflav2==5) countbmy2=countbmy2+1;
	else if(myflav2==4) countcmy2=countcmy2+1;
	else if(myflav2==1||myflav2==2||myflav2==3||myflav2==21) countlmy2=countlmy2+1;
	else countnomy2=countnomy2+1;

	if(myflav1==5) countbmy1=countbmy1+1;
	else if(myflav1==4) countcmy1=countcmy1+1;
	else if(myflav1==1||myflav1==2||myflav1==3||myflav1==21) countlmy1=countlmy1+1;
	else countnomy1=countnomy1+1;

      }
      
    }

    TH3D* h3 = (TH3D*)Hist("Fijk"); 
    h3->Fill(countb,countc,countl, weight);
    float valfill=countb*1000+countc*100+countl*10+countno+0.5;
    if (countno==0){
      Hist("Fract_4")->Fill(valfill, weight);
      if (drsum<0.4){
	Hist("Fract_4_drcut")->Fill(valfill, weight);
      }
    }

    Hist("Fract_4_no")->Fill(valfill, weight);

    Hist("Pat_flav")->Fill(0.5,countb*weight);
    Hist("Pat_flav")->Fill(1.5,countc*weight);
    Hist("Pat_flav")->Fill(2.5,countl*weight);
    Hist("Pat_flav")->Fill(3.5,countno*weight);

    TH2D* h2 = (TH2D*)Hist("Pat_flav_dr"); 
    h2->Fill(countno,drsum, weight);

    if (drsum<0.4){
      Hist("Pat_flav_drcut")->Fill(0.5,countb*weight);
      Hist("Pat_flav_drcut")->Fill(1.5,countc*weight);
      Hist("Pat_flav_drcut")->Fill(2.5,countl*weight);
      Hist("Pat_flav_drcut")->Fill(3.5,countno*weight);
    }

    Hist("My_flav_3")->Fill(0.5,countbmy3*weight);
    Hist("My_flav_3")->Fill(1.5,countcmy3*weight);
    Hist("My_flav_3")->Fill(2.5,countlmy3*weight);
    Hist("My_flav_3")->Fill(3.5,countnomy3*weight);

    Hist("My_flav_2")->Fill(0.5,countbmy2*weight);
    Hist("My_flav_2")->Fill(1.5,countcmy2*weight);
    Hist("My_flav_2")->Fill(2.5,countlmy2*weight);
    Hist("My_flav_2")->Fill(3.5,countnomy2*weight);

    Hist("My_flav_1")->Fill(0.5,countbmy1*weight);
    Hist("My_flav_1")->Fill(1.5,countcmy1*weight);
    Hist("My_flav_1")->Fill(2.5,countlmy1*weight);
    Hist("My_flav_1")->Fill(3.5,countnomy1*weight);

    Hist("N_tagged_sub")->Fill(counttags,weight);
    Hist("N_tagged_b")->Fill(0.5,counttagsb*weight);
    Hist("N_tagged_c")->Fill(0.5,counttagsc*weight);
    Hist("N_tagged_l")->Fill(0.5,counttagsl*weight);
    Hist("N_tagged_no")->Fill(0.5,counttagsno*weight);

    Hist("N_all_b")->Fill(0.5,countb*weight);
    Hist("N_all_c")->Fill(0.5,countc*weight);
    Hist("N_all_l")->Fill(0.5,countl*weight);
    Hist("N_all_no")->Fill(0.5,countno*weight);

    if(countL==1&&countT==1){
      std::cout << calc->GetRunNum() << ":" << calc->GetLumiBlock() << ":" << calc->GetEventNum() << " " << bcc->topjets->at(indexjet).v4().M() << std::endl;
    }

    if(counttags==0){
      Hist("N_b_0tags")->Fill(countb,weight);
      Hist("N_c_0tags")->Fill(countc,weight);
      Hist("N_l_0tags")->Fill(countl,weight);
      Hist("N_no_0tags")->Fill(countno,weight);    
      Hist("N_tagged0_b")->Fill(0.5,counttagsb*weight);
      Hist("N_tagged0_c")->Fill(0.5,counttagsc*weight);
      Hist("N_tagged0_l")->Fill(0.5,counttagsl*weight);
      Hist("N_tagged0_no")->Fill(0.5,counttagsno*weight);
      
      Hist("N_all0_b")->Fill(0.5,countb*weight);
      Hist("N_all0_c")->Fill(0.5,countc*weight);
      Hist("N_all0_l")->Fill(0.5,countl*weight);
      Hist("N_all0_no")->Fill(0.5,countno*weight);
    }
    if(counttags==1){
      Hist("N_b_1tags")->Fill(countb,weight);
      Hist("N_c_1tags")->Fill(countc,weight);
      Hist("N_l_1tags")->Fill(countl,weight);
      Hist("N_no_1tags")->Fill(countno,weight);      
      Hist("N_tagged1_b")->Fill(0.5,counttagsb*weight);
      Hist("N_tagged1_c")->Fill(0.5,counttagsc*weight);
      Hist("N_tagged1_l")->Fill(0.5,counttagsl*weight);
      Hist("N_tagged1_no")->Fill(0.5,counttagsno*weight);
      
      Hist("N_all1_b")->Fill(0.5,countb*weight);
      Hist("N_all1_c")->Fill(0.5,countc*weight);
      Hist("N_all1_l")->Fill(0.5,countl*weight);
      Hist("N_all1_no")->Fill(0.5,countno*weight);
    }
    if(counttags==2){
      Hist("N_b_2tags")->Fill(countb,weight);
      Hist("N_c_2tags")->Fill(countc,weight);
      Hist("N_l_2tags")->Fill(countl,weight);
      Hist("N_no_2tags")->Fill(countno,weight); 
      Hist("N_tagged2_b")->Fill(0.5,counttagsb*weight);
      Hist("N_tagged2_c")->Fill(0.5,counttagsc*weight);
      Hist("N_tagged2_l")->Fill(0.5,counttagsl*weight);
      Hist("N_tagged2_no")->Fill(0.5,counttagsno*weight);
      
      Hist("N_all2_b")->Fill(0.5,countb*weight);
      Hist("N_all2_c")->Fill(0.5,countc*weight);
      Hist("N_all2_l")->Fill(0.5,countl*weight);
      Hist("N_all2_no")->Fill(0.5,countno*weight);
    }
    if(counttags==3){
      Hist("N_b_3tags")->Fill(countb,weight);
      Hist("N_c_3tags")->Fill(countc,weight);
      Hist("N_l_3tags")->Fill(countl,weight);
      Hist("N_no_3tags")->Fill(countno,weight);      
      Hist("N_tagged3_b")->Fill(0.5,counttagsb*weight);
      Hist("N_tagged3_c")->Fill(0.5,counttagsc*weight);
      Hist("N_tagged3_l")->Fill(0.5,counttagsl*weight);
      Hist("N_tagged3_no")->Fill(0.5,counttagsno*weight);
      
      Hist("N_all3_b")->Fill(0.5,countb*weight);
      Hist("N_all3_c")->Fill(0.5,countc*weight);
      Hist("N_all3_l")->Fill(0.5,countl*weight);
      Hist("N_all3_no")->Fill(0.5,countno*weight);
    }
   
  }
  
}

void SemileptonicselectionHists::Finish()
{

}

