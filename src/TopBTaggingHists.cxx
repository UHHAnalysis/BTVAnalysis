#include "include/TopBTaggingHists.h"
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

TopBTaggingHists::TopBTaggingHists(const char* name, double ptMin, double ptMax) : BaseHists(name)
{
  // named default constructor
  m_ptMin = ptMin;
  m_ptMax = ptMax;
 
}

TopBTaggingHists::~TopBTaggingHists()
{
  // default destructor, does nothing
}

void TopBTaggingHists::Init()
{
  // book all histograms here
  
  //Book( TH1D( "H_Example", "H example", 25, 0, 1000));

  //Following hostrograms are filled independently from the pt bin (same in any pt-bin collection)

  Book( TH1D( "effdriso3_fat_llb", "eff dr iso", 10, 0, 2.));
  Book( TH1D( "effdriso3_fat_llb_num", "eff dr iso", 10, 0, 2.));
  Book( TH1D( "effdriso3_llb1", "eff dr iso", 10, 0, 2.));
  Book( TH1D( "effdriso3_llb1_num", "eff dr iso", 10, 0, 2.));
  Book( TH1D( "effdriso3_llb_den", "eff dr iso", 10, 0, 2.));
  Book( TH1D( "effdriso3_llb2", "eff dr iso", 10, 0, 2.));
  Book( TH1D( "effdriso3_llb2_num", "eff dr iso", 10, 0, 2.));
  Book( TH1D( "effdriso3_llb3", "eff dr iso", 10, 0, 2.));
  Book( TH1D( "effdriso3_llb3_num", "eff dr iso", 10, 0, 2.));
  Book( TH1D( "effdriso3_llb_and", "eff dr iso", 10, 0, 2.));
  Book( TH1D( "effdriso3_llb_and_num", "eff dr iso", 10, 0, 2.));
  Book( TH1D( "effdriso3_llb_x", "eff dr iso", 10, 0, 2.));
  Book( TH1D( "effdriso3_llb_x_num", "eff dr iso", 10, 0, 2.));
  Book( TH1D( "effdriso_fat", "eff dr iso fat", 10, 0, 2.));
  Book( TH1D( "effdriso_fat_num", "eff dr iso fat num", 10, 0, 2.));
  Book( TH1D( "effdriso_fat_den", "eff dr iso fat den", 10, 0, 2.));
  Book( TH1D( "effdriso_fat_ll", "eff dr iso fat", 10, 0, 2.));
  Book( TH1D( "effdriso_fat_ll_num", "eff dr iso fat num", 10, 0, 2.));
  Book( TH1D( "effdriso_fat_ll_den", "eff dr iso fat den", 10, 0, 2.));
  Book( TH1D( "effdriso_fat_lb", "eff dr iso fat", 10, 0, 2.));
  Book( TH1D( "effdriso_fat_lb_num", "eff dr iso fat num", 10, 0, 2.));
  Book( TH1D( "effdriso_fat_lb_den", "eff dr iso fat den", 10, 0, 2.));
  Book( TH1D( "effdriso_ll1", "eff dr iso ll", 10, 0, 2.));
  Book( TH1D( "effdriso_ll2", "eff dr iso ll", 10, 0, 2.));
  Book( TH1D( "effdriso_ll_num1", "eff dr iso ll num 1", 10, 0, 2.));
  Book( TH1D( "effdriso_ll_num2", "eff dr iso ll num 2", 10, 0, 2.));
  Book( TH1D( "effdriso_ll_den", "eff dr iso ll den", 10, 0, 2.));
  Book( TH1D( "effdriso_lb1", "eff dr iso lb", 10, 0, 2.));
  Book( TH1D( "effdriso_lb2", "eff dr iso lb", 10, 0, 2.));
  Book( TH1D( "effdriso_lb_num1", "eff dr iso lb num 1", 10, 0, 2.));
  Book( TH1D( "effdriso_lb_num2", "eff dr iso lb num 2", 10, 0, 2.));
  Book( TH1D( "effdriso_lb_den", "eff dr iso lb den", 10, 0, 2.));
  Book( TH1D( "effdriso_ll_and_num", "eff dr iso ll & num", 10, 0, 2.));
  Book( TH1D( "effdriso_ll_and", "eff dr iso ll", 10, 0, 2.));
  Book( TH1D( "effdriso_lb_and_num", "eff dr iso lb & num", 10, 0, 2.));
  Book( TH1D( "effdriso_lb_and", "eff dr iso lb", 10, 0, 2.));
  Book( TH1D( "effdriso_ll_x", "eff dr iso ll x", 10, 0, 2.));
  Book( TH1D( "effdriso_lb_x", "eff dr iso lb x", 10, 0, 2.));
  Book( TH1D( "effdriso3_fat", "eff dr iso3 fat", 10, 0, 2.));
  Book( TH1D( "effdriso3_fat_num", "eff dr iso3 fat num", 10, 0, 2.));
  Book( TH1D( "effdriso3_fat_den", "eff dr iso3 fat den", 10, 0, 2.));
  Book( TH1D( "effdriso3_fat_ll", "eff dr iso3 fat", 10, 0, 2.));
  Book( TH1D( "effdriso3_fat_ll_num", "eff dr iso3 fat num", 10, 0, 2.));
  Book( TH1D( "effdriso3_fat_ll_den", "eff dr iso3 fat den", 10, 0, 2.));
  Book( TH1D( "effdriso3_fat_lb", "eff dr iso3 fat", 10, 0, 2.));
  Book( TH1D( "effdriso3_fat_lb_num", "eff dr iso3 fat num", 10, 0, 2.));
  Book( TH1D( "effdriso3_fat_lb_den", "eff dr iso3 fat den", 10, 0, 2.));
  Book( TH1D( "effdriso3_ll1", "eff dr iso3 ll", 10, 0, 2.));
  Book( TH1D( "effdriso3_ll2", "eff dr iso3 ll", 10, 0, 2.));
  Book( TH1D( "effdriso3_ll_num1", "eff dr iso3 ll num 1", 10, 0, 2.));
  Book( TH1D( "effdriso3_ll_num2", "eff dr iso3 ll num 2", 10, 0, 2.));
  Book( TH1D( "effdriso3_ll_den", "eff dr iso3 ll den", 10, 0, 2.));
  Book( TH1D( "effdriso3_lb1", "eff dr iso3 lb", 10, 0, 2.));
  Book( TH1D( "effdriso3_lb2", "eff dr iso3 lb", 10, 0, 2.));
  Book( TH1D( "effdriso3_lb_num1", "eff dr iso3 lb num 1", 10, 0, 2.));
  Book( TH1D( "effdriso3_lb_num2", "eff dr iso3 lb num 2", 10, 0, 2.));
  Book( TH1D( "effdriso3_lb_den", "eff dr iso3 lb den", 10, 0, 2.));
  Book( TH1D( "effdriso3_ll_and_num", "eff dr iso3 ll & num", 10, 0, 2.));
  Book( TH1D( "effdriso3_ll_and", "eff dr iso3 ll", 10, 0, 2.));
  Book( TH1D( "effdriso3_lb_and_num", "eff dr iso3 lb & num", 10, 0, 2.));
  Book( TH1D( "effdriso3_lb_and", "eff dr iso3 lb", 10, 0, 2.));
  Book( TH1D( "effdriso3_ll_x", "eff dr iso3 ll x", 10, 0, 2.));
  Book( TH1D( "effdriso3_lb_x", "eff dr iso3 lb x", 10, 0, 2.));
  Book( TH1D( "P_pt", "prunedjet pt", 100, 0, 1000));
  Book( TH1D( "P_pt", "prunedjet pt", 100, 0, 1000));
  Book( TH1D( "Top_pt", "topjet pt", 100, 0, 1000));
  Book( TH1D( "b_pt", "b-subjet pt", 100, 0, 1000));
  Book( TH1D( "flav_b_sub", "b-tagged subjets flavor", 22, 0, 22));
  Book( TH1D( "T_pt", "topjet pt", 100, 0, 1000));
  Book( TH1D( "DR_Matching", "DR Matching", 100, 0, 1));
  Book( TH2D( "DR_PT", "DR vs pt", 50, 0, 1000, 50 , 0, 3));
  Book( TH2D( "DR_PT_zoom", "DR vs pt", 50, 0, 600, 50 , 0, 3));
  Book( TH2D( "DR_PT_CA15", "DR vs pt", 50, 0, 1000, 50 , 0, 3));
  Book( TH2D( "DR_PT_CA15_Tag", "DR vs pt", 50, 0, 1000, 50 , 0, 3));
  Book( TH1D( "DR_PT_Matching", "DR PT Matching", 100, 0, 1));
  Book( TH1D( "H_All_Hadronic", "All Hadronic Tops", 25, 0, 1000));
  Book( TH1D( "H_Matched_Hadronic", "Matched Hadronic Tops", 25, 0, 1000));
  Book( TH1D( "H_TopTagged_Hadronic", "TopTagged Hadronic Tops", 25, 0, 1000));
  Book( TH1D( "H_TopTagged_SubM_Hadronic", "TopTagged SubM Hadronic Tops", 25, 0, 1000));
  Book( TH1D( "H_TopTagged_SubL_Hadronic", "TopTagged SubL Hadronic Tops", 25, 0, 1000));
  Book( TH1D( "H_TopTagged_CSVM_Hadronic", "TopTagged CSVM Hadronic Tops", 25, 0, 1000));
  Book( TH1D( "H_TopTagged_CSVL_Hadronic", "TopTagged CSVL Hadronic Tops", 25, 0, 1000));
  Book( TH1D( "H_TopTagged_IVF_Hadronic", "TopTagged IVF Hadronic Tops", 25, 0, 1000));
  Book( TH1D( "H_SubM_Hadronic", "SubM Hadronic Tops", 25, 0, 1000));
  Book( TH1D( "H_SubL_Hadronic", "SubL Hadronic Tops", 25, 0, 1000));
  Book( TH1D( "H_CSVM_Hadronic", "CSVM Hadronic Tops", 25, 0, 1000));
  Book( TH1D( "H_CSVL_Hadronic", "CSVL Hadronic Tops", 25, 0, 1000));
  Book( TH1D( "H_IVF_Hadronic", "IVF Hadronic Tops", 25, 0, 1000));
  Book( TH1D( "H_All_Mistag", "All Mistag", 25, 0, 1000));
  Book( TH1D( "H_TopTagged_Mistag", "TopTagged Mistag", 25, 0, 1000));
  Book( TH1D( "H_TopTagged_SubM_Mistag", "TopTagged SubM Mistag", 25, 0, 1000));
  Book( TH1D( "H_TopTagged_SubL_Mistag", "TopTagged SubL Mistag", 25, 0, 1000));
  Book( TH1D( "H_TopTagged_CSVM_Mistag", "TopTagged CSVM Mistag", 25, 0, 1000));
  Book( TH1D( "H_TopTagged_CSVL_Mistag", "TopTagged CSVL Mistag", 25, 0, 1000));
  Book( TH1D( "H_TopTagged_IVF_Mistag", "TopTagged IVF Mistag", 25, 0, 1000));
  Book( TH1D( "H_SubM_Mistag", "SubM Mistag", 25, 0, 1000));
  Book( TH1D( "H_SubL_Mistag", "SubL Mistag", 25, 0, 1000));
  Book( TH1D( "H_CSVM_Mistag", "CSVM Mistag", 25, 0, 1000));
  Book( TH1D( "H_CSVL_Mistag", "CSVL Mistag", 25, 0, 1000));
  Book( TH1D( "H_IVF_Mistag", "IVF Mistag", 25, 0, 1000));
  Book( TH1D( "H_B_Hadronic_pT", "B Hadronic Decay pT", 25, 0, 1000));

  Book( TH1D( "H_Effi_Matched","Effi Matched", 25, 0, 1000));
  Book( TH1D( "H_Effi_TopTag","Effi TopTag", 25, 0, 1000));
  Book( TH1D( "H_Effi_TopTag_SubM", "Effi TopTag SubM", 25, 0, 1000));
  Book( TH1D( "H_Effi_TopTag_SubL", "Effi TopTag SubL", 25, 0, 1000));
  Book( TH1D( "H_Effi_TopTag_CSVM", "Effi TopTag CSVM", 25, 0, 1000));
  Book( TH1D( "H_Effi_TopTag_CSVL", "Effi TopTag CSVL", 25, 0, 1000));
  Book( TH1D( "H_Effi_TopTag_IVF", "Effi TopTag IVF", 25, 0, 1000));
  Book( TH1D( "H_Effi_SubM", "Effi SubM", 25, 0, 1000));
  Book( TH1D( "H_Effi_SubL", "Effi SubL", 25, 0, 1000));
  Book( TH1D( "H_Effi_CSVM", "Effi CSVM", 25, 0, 1000));
  Book( TH1D( "H_Effi_CSVL", "Effi CSVL", 25, 0, 1000));
  Book( TH1D( "H_Effi_IVF", "Effi IVF", 25, 0, 1000));
  Book( TH1D( "H_Effi_TopTag_Mistag", "Effi TopTag Mistag", 25, 0, 1000));
  Book( TH1D( "H_Effi_TopTag_Mistag_SubM", "Effi TopTag Mistag SubM", 25, 0, 1000));
  Book( TH1D( "H_Effi_TopTag_Mistag_SubL", "Effi TopTag Mistag SubL", 25, 0, 1000));
  Book( TH1D( "H_Effi_TopTag_Mistag_CSVM", "Effi TopTag Mistag CSVM", 25, 0, 1000));
  Book( TH1D( "H_Effi_TopTag_Mistag_CSVL", "Effi TopTag Mistag CSVL", 25, 0, 1000));
  Book( TH1D( "H_Effi_TopTag_Mistag_IVF", "Effi TopTag Mistag IVF", 25, 0, 1000));
  Book( TH1D( "H_Effi_Mistag_SubM", "Effi Mistag SubM", 25, 0, 1000));
  Book( TH1D( "H_Effi_Mistag_SubL", "Effi Mistag SubL", 25, 0, 1000));
  Book( TH1D( "H_Effi_Mistag_CSVM", "Effi Mistag CSVM", 25, 0, 1000));
  Book( TH1D( "H_Effi_Mistag_CSVL", "Effi Mistag CSVL", 25, 0, 1000));
  Book( TH1D( "H_Effi_Mistag_IVF", "Effi Mistag IVF", 25, 0, 1000));

  // Following histograms are filled taking into account the pt bin

  Book( TH1D("CSV_Discr",";CSV Discr;#events",500,0.,1.));
  Book( TH1D("CSV_Sub_Discr",";CSV Sub Discr;#events",500,0.,1.));
  Book( TH1D("CSV_Sub_Discr_Num",";CSV Discr;#identified B",500,0.,1.));
  Book( TH1D("CSV_Sub_Discr_Effi",";CSV Discr;effi B",500,0.,1.));
  Book( TH1D("CSV_Sub_Discr_Den",";CSV Discr;#total",500,0.,1.));
  Book( TH1D("CSV_Sub_Discr_Mistag_Num",";CSV Discr;#mistag identified",500,0.,1.));
  Book( TH1D("CSV_Sub_Discr_Mistag_Effi",";CSV Discr;effi mistag",500,0.,1.));
  Book( TH1D("CSV_Sub_Discr_Mistag_Den",";CSV Discr;#mistag total",500,0.,1.));
  Book( TH1D("CSV_Sub_Discr_TopTag_Num",";CSV Discr;#identified B+Top",500,0.,1.));
  Book( TH1D("CSV_Sub_Discr_TopTag_Effi",";CSV Discr;effi B+Top",500,0.,1.));
  Book( TH1D("CSV_Sub_Discr_Mistag_TopTag_Num",";CSV Discr;#mistag identified+Top",500,0.,1.));
  Book( TH1D("CSV_Sub_Discr_Mistag_TopTag_Effi",";CSV Discr;effi mistag+Top",500,0.,1.));
  Book( TH1D("CSV_Discr_Num",";CSV Discr;#identified B",500,0.,1.));
  Book( TH1D("CSV_Discr_Effi",";CSV Discr;effi B",500,0.,1.));
  Book( TH1D("CSV_Discr_Den",";CSV Discr;#total",500,0.,1.));
  Book( TH1D("CSV_Discr_Mistag_Num",";CSV Discr;#mistag identified",500,0.,1.));
  Book( TH1D("CSV_Discr_Mistag_Effi",";CSV Discr;effi mistag",500,0.,1.));
  Book( TH1D("CSV_Discr_Mistag_Den",";CSV Discr;#mistag total",500,0.,1.));
  Book( TH1D("CSV_Discr_TopTag_Num",";CSV Discr;#identified B+Top",500,0.,1.));
  Book( TH1D("CSV_Discr_Mistag_TopTag_Num",";CSV Discr;#mistag identified+Top",500,0.,1.));
  Book( TH1D("CSV_Discr_TopTag_Effi",";CSV Discr;effi B+Top",500,0.,1.));
  Book( TH1D("CSV_Discr_Mistag_TopTag_Effi",";CSV Discr;effi mistag+Top",500,0.,1.));

}

void TopBTaggingHists::Fill()
{
  // fill the histograms

  EventCalc* calc = EventCalc::Instance();
  bool IsRealData = calc->IsRealData();
  LuminosityHandler* lumih = calc->GetLumiHandler();

  double weight = calc->GetWeight();

  //weight=1;

  if(weight!=1){
    //cout << "Using a special weight " << weight << endl;
  }

  //ObjectHandler* objs = ObjectHandler::Instance();
  BaseCycleContainer* bcc = calc->GetBaseCycleContainer();

  int run = calc->GetRunNum();
  int lumiblock = calc->GetLumiBlock();
  int Npvs = calc->GetPrimaryVertices()->size();

  TTbarGen* Decay = calc->GetTTbarGen();
  
  //Configuration stuff
  double assogen=1.5;
  float csvcutM=0.244;
  float csvcutL=0.244;
  float assoRcut=1.5;
  int applyiso=0;
  int doivf=0;

  int dohepmatch=0;

  int csvivf=0;

  float masswind=250.;

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

  TopJet topjet;
  TopJet antitopjet;

  std::vector<GenParticle> topsub;
  std::vector<GenParticle> antitopsub;
  
  topsub.reserve(3);
  antitopsub.reserve(3);

  topsub[0]=btop;
  topsub[1]=wtop1;
  topsub[2]=wtop2;

  antitopsub[0]=bantitop;
  antitopsub[1]=wantitop1;
  antitopsub[2]=wantitop2;

  double drtop[3];

  double drantitop[3];

  drtop[0]=topsub[1].deltaR(topsub[2]);
  drtop[1]=topsub[0].deltaR(topsub[2]);
  drtop[2]=topsub[1].deltaR(topsub[0]);

  drantitop[0]=antitopsub[1].deltaR(antitopsub[2]);
  drantitop[1]=antitopsub[0].deltaR(antitopsub[2]);
  drantitop[2]=antitopsub[1].deltaR(antitopsub[0]);

  LorentzVector sumtop(0,0,0,0);

  LorentzVector sumantitop(0,0,0,0);

  LorentzVector thirdtop(0,0,0,0);

  LorentzVector thirdantitop(0,0,0,0);

  Particle sumtopp;
  Particle sumantitopp;
  
  Particle thirdtopp;
  Particle thirdantitopp;

  double mindrtop=min(drtop[0],min(drtop[1],drtop[2]));
  double mindrantitop=min(drantitop[0],min(drantitop[1],drantitop[2]));

  if(mindrtop==drtop[0]){
    sumtop=topsub[1].v4()+topsub[2].v4();
    thirdtop=topsub[0].v4();
  }
  else if(mindrtop==drtop[1]){
    sumtop=topsub[0].v4()+topsub[2].v4();
    thirdtop=topsub[1].v4();
  }
  else if(mindrtop==drtop[2]){
    sumtop=topsub[1].v4()+topsub[0].v4();
    thirdtop=topsub[2].v4();
  }

  if(mindrantitop==drantitop[0]){
    sumantitop=antitopsub[1].v4()+antitopsub[2].v4();
    thirdantitop=antitopsub[0].v4();
  }
  else if(mindrantitop==drantitop[1]){
    sumantitop=antitopsub[0].v4()+antitopsub[2].v4();
    thirdantitop=antitopsub[1].v4();
  }
  else if(mindrantitop==drantitop[2]){
    sumantitop=antitopsub[1].v4()+antitopsub[0].v4();
    thirdantitop=antitopsub[2].v4();
  }


  sumtopp.set_v4(sumtop);
  sumantitopp.set_v4(sumantitop);

  thirdtopp.set_v4(thirdtop);
  thirdantitopp.set_v4(thirdantitop);

  double dr3top=sumtopp.deltaR(thirdtopp);
  double dr3antitop=sumantitopp.deltaR(thirdantitopp);

  double drconetop=max(dr3top,mindrtop);
  double drconeantitop=max(dr3antitop,mindrantitop);

  for(unsigned int itj=0; itj<bcc->topjets->size();++itj){
    Hist("T_pt")->Fill(bcc->topjets->at(itj).pt(),1);
  }

  TH2F* htop = (TH2F*)Hist("DR_PT"); 
  TH2F* htopzoom = (TH2F*)Hist("DR_PT_zoom"); 
  TH2F* htopca15 = (TH2F*)Hist("DR_PT_CA15"); 
  TH2F* htopca15tag = (TH2F*)Hist("DR_PT_CA15_Tag"); 
  

  if(decaytop>0&&decaytop<=5){
    goodtop=1;
    htop->Fill(topgen.pt(),drconetop);
    htopzoom->Fill(topgen.pt(),drconetop);
    //if(topgen.pt()>=m_ptMin&&topgen.pt()<m_ptMax){
    //for(unsigned int idiscr=0;idiscr<50;idiscr++){
    //double edge=Hist("CSV_Discr")->GetXaxis()->GetBinLowEdge(idiscr+1);
    //Hist("CSV_Discr_Den")->Fill(edge+0.005,1);
    //Hist("CSV_Sub_Discr_Den")->Fill(edge+0.005,1);
    //}
    //}
  }
  
  if(decayantitop>0&&decayantitop<=5){
    goodantitop=1;
    htop->Fill(antitopgen.pt(),drconeantitop);
    htopzoom->Fill(antitopgen.pt(),drconeantitop);
    //if(antitopgen.pt()>=m_ptMin&&antitopgen.pt()<m_ptMax){
    //for(unsigned int idiscr=0;idiscr<50;idiscr++){
    //double edge=Hist("CSV_Discr")->GetXaxis()->GetBinLowEdge(idiscr+1);
    //Hist("CSV_Discr_Den")->Fill(edge+0.005,1);
    //Hist("CSV_Sub_Discr_Den")->Fill(edge+0.005,1);
    //}
    //}
  }
  
  //Info for isolation cut
  GenParticle topiso;
  GenParticle antitopiso;
  GenParticle higgsiso1;
  GenParticle higgsiso2;

  int counthiggs=0;

  for(unsigned int ig=0; ig<bcc->genparticles->size(); ++ig){
    
    GenParticle genp = bcc->genparticles->at(ig); 
    
    if (genp.pdgId() == 6){
      topiso=bcc->genparticles->at(ig); 
    }
    
    if (genp.pdgId() == -6){
      antitopiso=bcc->genparticles->at(ig); 
    }
    
    if (abs(genp.pdgId()) == 25&&counthiggs==0){
      higgsiso1=bcc->genparticles->at(ig);
      //cout << "higgs mass " << higgsiso1.v4().M() << endl;
      counthiggs=counthiggs+1;
    }
    
    if (abs(genp.pdgId()) == 25&&counthiggs==1){
      higgsiso2=bcc->genparticles->at(ig); 
      counthiggs=counthiggs+1;
      
    }
    
  }

  int indextopjet=-99999;
  int indexantitopjet=-99999;
  int indextoppjet=-99999;
  int indexantitoppjet=-99999;

  if(goodtop==1){
    Hist("H_B_Hadronic_pT")->Fill(btop.pt(),1);
    Hist("H_All_Hadronic")->Fill(topgen.pt(),1);
    double mindeltar=9999999;    
    for(unsigned int itj=0; itj<bcc->topjets->size();++itj){
      if(bcc->topjets->at(itj).pt()<=150) continue;
      if((bcc->topjets->at(itj).deltaR(topgen)) < mindeltar){
	mindeltar=bcc->topjets->at(itj).deltaR(topgen);
	indextopjet=itj;
      }
    }
    if(indextopjet<0){
      goodtop=0;
    }
    else{
      topjet=bcc->topjets->at(indextopjet);
      if(!((topjet.deltaR(btop)<assogen)&&(topjet.deltaR(w)<assogen))){
	goodtop=0;
      }
    }
    if(applyiso==1){
      if(antitopiso.deltaR(topgen)<assogen){
	goodtop=0;
      }
      if(higgsiso1.deltaR(topgen)<assogen){
	goodtop=0;
      }
      if(higgsiso2.deltaR(topgen)<assogen){
	goodtop=0;
      }
    }
    //if(goodtop==1)Hist("H_All_Hadronic")->Fill(topgen.pt(),1);
  }

  if(goodantitop==1){
    Hist("H_B_Hadronic_pT")->Fill(bantitop.pt(),1);
    Hist("H_All_Hadronic")->Fill(antitopgen.pt(),1);
    double mindeltar=9999999;
    for(unsigned int itj=0; itj<bcc->topjets->size();++itj){
      if(bcc->topjets->at(itj).pt()<=150) continue;
      if((bcc->topjets->at(itj).deltaR(antitopgen)) < mindeltar){
	mindeltar=bcc->topjets->at(itj).deltaR(antitopgen);
	indexantitopjet=itj;
      }
    }
    if(indexantitopjet<0){
      goodantitop=0;
    }
    else{
      antitopjet=bcc->topjets->at(indexantitopjet);
      if(!((antitopjet.deltaR(bantitop)<assogen)&&(antitopjet.deltaR(antiw)<assogen))){
	goodantitop=0;
      }
    }
    if(applyiso==1){
      if(topiso.deltaR(antitopgen)<assogen){
	goodantitop=0;
      }
      if(higgsiso1.deltaR(antitopgen)<assogen){
	goodantitop=0;
      }
      if(higgsiso2.deltaR(antitopgen)<assogen){
	goodantitop=0;
      }
    }
    //if(goodantitop==1)Hist("H_All_Hadronic")->Fill(antitopgen.pt(),1);
  }
 

  std::vector<Particle> subjets_top;
  std::vector<float> btagsub_combinedSecondaryVertex_top;
  
  std::vector<Particle> subjets_antitop;
  std::vector<float> btagsub_combinedSecondaryVertex_antitop;
  std::vector<int> flavorsub_top;

  int countsbM_top=0;
  int countsbL_top=0;
  int countsbM_antitop=0;
  int countsbL_antitop=0;

  int countSV_top=0;
  int countSV_antitop=0;

  int toptag=0;
  int antitoptag=0;

  if(goodtop==1){
    Hist("H_Matched_Hadronic")->Fill(topgen.pt(),1);
    subjets_top=topjet.subjets();
    //
    double drtopR[3];
    
    drtopR[0]=subjets_top[1].deltaR(subjets_top[2]);
    drtopR[1]=subjets_top[0].deltaR(subjets_top[2]);
    drtopR[2]=subjets_top[1].deltaR(subjets_top[0]);

    LorentzVector sumtopR(0,0,0,0);

    LorentzVector thirdtopR(0,0,0,0);

    Particle sumtoppR;
    Particle thirdtoppR;
  
    double mindrtopR=min(drtopR[0],min(drtopR[1],drtopR[2]));

    if(mindrtopR==drtopR[0]){
      sumtopR=subjets_top[1].v4()+subjets_top[2].v4();
      thirdtopR=subjets_top[0].v4();
    }
    else if(mindrtopR==drtopR[1]){
      sumtopR=subjets_top[0].v4()+subjets_top[2].v4();
      thirdtopR=subjets_top[1].v4();
    }
    else if(mindrtopR==drtopR[2]){
      sumtopR=subjets_top[1].v4()+subjets_top[0].v4();
      thirdtopR=subjets_top[2].v4();
    }

    sumtoppR.set_v4(sumtopR);

    thirdtoppR.set_v4(thirdtopR);

    double dr3topR=sumtoppR.deltaR(thirdtoppR);

    double drconetopR=max(dr3topR,mindrtopR);

    //
    htopca15->Fill(topgen.pt(),drconetopR);
    if (HepTopTag(topjet)) htopca15tag->Fill(topgen.pt(),drconetop);
    if(topgen.pt()>=m_ptMin&&topgen.pt()<m_ptMax){
      for(unsigned int idiscr=0;idiscr<500;idiscr++){
	double edge=Hist("CSV_Discr")->GetXaxis()->GetBinLowEdge(idiscr+1);
	Hist("CSV_Discr_Den")->Fill(edge+0.005,1);
	Hist("CSV_Sub_Discr_Den")->Fill(edge+0.005,1);
      }
    }
    if(csvivf==1){
      //btagsub_combinedSecondaryVertex_top=topjet.btagsub_combinedInclusiveSecondaryVertex();
    }
    if(csvivf==0){
      btagsub_combinedSecondaryVertex_top=topjet.btagsub_combinedSecondaryVertex();
    }
    flavorsub_top=topjet.flavorsub();
    //Determine subjet associated to the true b
    double mindeltars=9999999;
    int indexsubb=-9999;
    for(unsigned int ist=0; ist<btagsub_combinedSecondaryVertex_top.size();++ist){
      Particle subjet=subjets_top[ist];
      if(abs(flavorsub_top[ist])==5) Hist("b_pt")->Fill(subjet.pt(),1);
      if((subjet.deltaR(btop)) < mindeltars){
	  mindeltars=subjet.deltaR(btop);
	  indexsubb=ist;
	}
    }
    if(indexsubb>0&&mindeltars<assogen){
      if(topgen.pt()>=m_ptMin&&topgen.pt()<m_ptMax){
	Hist("CSV_Sub_Discr")->Fill(btagsub_combinedSecondaryVertex_top[indexsubb],1);
      }
    }
    int indexb=-999;
    for(unsigned int ist=0; ist<btagsub_combinedSecondaryVertex_top.size();++ist){
      float test=btagsub_combinedSecondaryVertex_top[ist];
      if(test>csvcutM){
        countsbM_top=countsbM_top+1;
	indexb=ist;
      }
      if(test>csvcutL){
        countsbL_top=countsbL_top+1;
      }
    }

    if((HepTopTag(topjet))&&(topjet.v4().mass()> (172.4 - masswind))&&(topjet.v4().mass()< (172.4 + masswind))){
      toptag=1;
    }
    if(dohepmatch){
      toptag=0;
      if((HepTopTagMatch(topjet))&&(topjet.v4().mass()> (172.4 - masswind))&&(topjet.v4().mass()< (172.4 + masswind))){
	toptag=1;
      }
    }
    if(countsbM_top==1&&toptag==1) Hist("flav_b_sub")->Fill(abs(flavorsub_top[indexb]));
    //IVF tag
    if(doivf){
      /*for(unsigned int isv=0; isv< bcc->svs->size(); ++isv){

      PrimaryVertex pv=bcc->pvs->at(0);

      double xvdiff=bcc->svs->at(isv).x()-pv.x();
      double yvdiff=bcc->svs->at(isv).y()-pv.y();
      double zvdiff=bcc->svs->at(isv).z()-pv.z();

      TVector3 vdiff;

      vdiff.SetXYZ(xvdiff,yvdiff,zvdiff);

      LorentzVector vljet=topjet.v4();

      TVector3 vjet;

      vjet.SetXYZ(vljet.Px(),vljet.Py(),vljet.Pz());

      double etavdiff=vdiff.Eta();
      double phivdiff=vdiff.Phi();
      double etajet=vjet.Eta();
      double phijet=vjet.Phi();

      double deltaphivjet=phivdiff-phijet;
      if(deltaphivjet>PI) deltaphivjet = 2* PI - deltaphivjet;

      double deltaetavjet=etavdiff-etajet;
      
      double deltarvjet=sqrt(deltaetavjet*deltaetavjet+deltaphivjet*deltaphivjet);

      if(deltarvjet<assoRcut){
        countSV_top=countSV_top+1;
      }
    }//Loop over vertices
      */
    }
    if(toptag==1){
      Hist("H_TopTagged_Hadronic")->Fill(topgen.pt(),1);
    }
    if(toptag==1&&topjet.btag_combinedSecondaryVertex()>csvcutM){
      Hist("H_TopTagged_CSVM_Hadronic")->Fill(topgen.pt(),1);
    }
    if(toptag==1&&topjet.btag_combinedSecondaryVertex()>csvcutL){
      Hist("H_TopTagged_CSVL_Hadronic")->Fill(topgen.pt(),1);
    }
    //Filling pt-dependent collection
    if(topgen.pt()>=m_ptMin&&topgen.pt()<m_ptMax){
      Hist("CSV_Discr")->Fill(topjet.btag_combinedSecondaryVertex(),1);
      for(unsigned int idiscr=0;idiscr<500;idiscr++){
      double edge=Hist("CSV_Discr")->GetXaxis()->GetBinLowEdge(idiscr+1);
	if(topjet.btag_combinedSecondaryVertex()>edge){
	  Hist("CSV_Discr_Num")->Fill(edge+0.005,1);
	}
	if(topjet.btag_combinedSecondaryVertex()>edge&&toptag==1){
	  Hist("CSV_Discr_TopTag_Num")->Fill(edge+0.005,1);
	}
	//For subjets
	int checksdiscr=0;
	for(unsigned int ist=0; ist<btagsub_combinedSecondaryVertex_top.size();++ist){
	  float test=btagsub_combinedSecondaryVertex_top[ist];
	  if(test>edge){
	    checksdiscr=checksdiscr+1;
	  }
	}
	if(checksdiscr>=1){
	  Hist("CSV_Sub_Discr_Num")->Fill(edge+0.005,1);
	}
	if(checksdiscr>=1&&toptag==1){
	  Hist("CSV_Sub_Discr_TopTag_Num")->Fill(edge+0.005,1);
	}
      }
    }
    if(topjet.btag_combinedSecondaryVertex()>csvcutM){
      Hist("H_CSVM_Hadronic")->Fill(topgen.pt(),1);
    }
    if(topjet.btag_combinedSecondaryVertex()>csvcutL){
      Hist("H_CSVL_Hadronic")->Fill(topgen.pt(),1);
    }
    if(toptag==1&&countsbM_top>=1){
      Hist("H_TopTagged_SubM_Hadronic")->Fill(topgen.pt(),1);
    }
    if(toptag==1&&countsbL_top>=1){
      Hist("H_TopTagged_SubL_Hadronic")->Fill(topgen.pt(),1);
    }
    if(toptag==1&&countSV_top>=1){
      Hist("H_TopTagged_IVF_Hadronic")->Fill(topgen.pt(),1);
    }
    if(countsbM_top>=1){
      Hist("H_SubM_Hadronic")->Fill(topgen.pt(),1);
    }
    if(countsbL_top>=1){
      Hist("H_SubL_Hadronic")->Fill(topgen.pt(),1);
    }
    if(countSV_top>=1){
      Hist("H_IVF_Hadronic")->Fill(topgen.pt(),1);
    }
  }
  
  if(goodantitop==1){

    Hist("H_Matched_Hadronic")->Fill(antitopgen.pt(),1);
    subjets_antitop=antitopjet.subjets();
    //
    double drantitopR[3];
    
    drantitopR[0]=subjets_antitop[1].deltaR(subjets_antitop[2]);
    drantitopR[1]=subjets_antitop[0].deltaR(subjets_antitop[2]);
    drantitopR[2]=subjets_antitop[1].deltaR(subjets_antitop[0]);

    LorentzVector sumantitopR(0,0,0,0);

    LorentzVector thirdantitopR(0,0,0,0);

    Particle sumantitoppR;
    Particle thirdantitoppR;
  
    double mindrantitopR=min(drantitopR[0],min(drantitopR[1],drantitopR[2]));

    if(mindrantitopR==drantitopR[0]){
      sumantitopR=subjets_antitop[1].v4()+subjets_antitop[2].v4();
      thirdantitopR=subjets_antitop[0].v4();
    }
    else if(mindrantitopR==drantitopR[1]){
      sumantitopR=subjets_antitop[0].v4()+subjets_antitop[2].v4();
      thirdantitopR=subjets_antitop[1].v4();
    }
    else if(mindrantitopR==drantitopR[2]){
      sumantitopR=subjets_antitop[1].v4()+subjets_antitop[0].v4();
      thirdantitopR=subjets_antitop[2].v4();
    }

    sumantitoppR.set_v4(sumantitopR);

    thirdantitoppR.set_v4(thirdantitopR);

    double dr3antitopR=sumantitoppR.deltaR(thirdantitoppR);

    double drconeantitopR=max(dr3antitopR,mindrantitopR);

    //
    htopca15->Fill(antitopgen.pt(),drconeantitopR);
    if (HepTopTag(antitopjet)) htopca15tag->Fill(antitopgen.pt(),drconeantitopR);
    if(antitopgen.pt()>=m_ptMin&&antitopgen.pt()<m_ptMax){
      for(unsigned int idiscr=0;idiscr<500;idiscr++){
	double edge=Hist("CSV_Discr")->GetXaxis()->GetBinLowEdge(idiscr+1);
	Hist("CSV_Discr_Den")->Fill(edge+0.005,1);
	Hist("CSV_Sub_Discr_Den")->Fill(edge+0.005,1);
      }
    }
    if(csvivf==1){
      //btagsub_combinedSecondaryVertex_antitop=antitopjet.btagsub_combinedInclusiveSecondaryVertex();
    }
    if(csvivf==0){
      btagsub_combinedSecondaryVertex_antitop=antitopjet.btagsub_combinedSecondaryVertex();
    }
    flavorsub_top=antitopjet.flavorsub();
    //Determine subjet associated to the true b
    double mindeltars=9999999;
    int indexsubb=-9999;
    for(unsigned int ist=0; ist<btagsub_combinedSecondaryVertex_antitop.size();++ist){
      Particle subjet=subjets_antitop[ist];
      if(abs(flavorsub_top[ist])==5) Hist("b_pt")->Fill(subjet.pt(),weight);
      if((subjet.deltaR(bantitop)) < mindeltars){
	  mindeltars=subjet.deltaR(bantitop);
	  indexsubb=ist;
	}
    }
    if(indexsubb>0&&mindeltars<assogen){
      if(antitopgen.pt()>=m_ptMin&&antitopgen.pt()<m_ptMax){
	Hist("CSV_Sub_Discr")->Fill(btagsub_combinedSecondaryVertex_antitop[indexsubb],1);
      }
    }
    int indexb=-999;
    for(unsigned int ist=0; ist<btagsub_combinedSecondaryVertex_antitop.size();++ist){
      float test=btagsub_combinedSecondaryVertex_antitop[ist];
      if(test>csvcutM){
        countsbM_antitop=countsbM_antitop+1;
	indexb=ist;
      }
      if(test>csvcutL){
        countsbL_antitop=countsbL_antitop+1;
      }
    }
    if((HepTopTag(antitopjet))&&(antitopjet.v4().mass()> (172.4 - masswind))&&(antitopjet.v4().mass()< (172.4 + masswind))){
      antitoptag=1;
    }
    if(dohepmatch){
      antitoptag=0;
      if((HepTopTagMatch(antitopjet))&&(antitopjet.v4().mass()> (172.4 - masswind))&&(antitopjet.v4().mass()< (172.4 + masswind))){
	antitoptag=1;
      }
    }
    if(countsbM_antitop==1&&antitoptag==1) Hist("flav_b_sub")->Fill(abs(flavorsub_top[indexb]));
    //IVF tag
    if(doivf){
      /*
    for(unsigned int isv=0; isv< bcc->svs->size(); ++isv){

      PrimaryVertex pv=bcc->pvs->at(0);

      double xvdiff=bcc->svs->at(isv).x()-pv.x();
      double yvdiff=bcc->svs->at(isv).y()-pv.y();
      double zvdiff=bcc->svs->at(isv).z()-pv.z();

      TVector3 vdiff;

      vdiff.SetXYZ(xvdiff,yvdiff,zvdiff);

      LorentzVector vljet=antitopjet.v4();

      TVector3 vjet;

      vjet.SetXYZ(vljet.Px(),vljet.Py(),vljet.Pz());

      double etavdiff=vdiff.Eta();
      double phivdiff=vdiff.Phi();
      double etajet=vjet.Eta();
      double phijet=vjet.Phi();

      double deltaphivjet=phivdiff-phijet;
      if(deltaphivjet>PI) deltaphivjet = 2* PI - deltaphivjet;

      double deltaetavjet=etavdiff-etajet;
      
      double deltarvjet=sqrt(deltaetavjet*deltaetavjet+deltaphivjet*deltaphivjet);

      if(deltarvjet<assoRcut){
        countSV_antitop=countSV_antitop+1;
      }
    }//Loop over vertices
      */
    }
    if(antitoptag==1){
      Hist("H_TopTagged_Hadronic")->Fill(antitopgen.pt(),1);
    }
    if(antitoptag==1&&antitopjet.btag_combinedSecondaryVertex()>csvcutM){
      Hist("H_TopTagged_CSVM_Hadronic")->Fill(antitopgen.pt(),1);
    }
    if(antitoptag==1&&antitopjet.btag_combinedSecondaryVertex()>csvcutL){
      Hist("H_TopTagged_CSVL_Hadronic")->Fill(antitopgen.pt(),1);
    }
    //Filling pt-dependent collection
    if(antitopgen.pt()>=m_ptMin&&antitopgen.pt()<m_ptMax){
      Hist("CSV_Discr")->Fill(antitopjet.btag_combinedSecondaryVertex(),1);
      for(unsigned int idiscr=0;idiscr<500;idiscr++){
	double edge=Hist("CSV_Discr")->GetXaxis()->GetBinLowEdge(idiscr+1);
	if(antitopjet.btag_combinedSecondaryVertex()>edge){
	  Hist("CSV_Discr_Num")->Fill(edge+0.005,1);
	}
	if(antitopjet.btag_combinedSecondaryVertex()>edge&&antitoptag==1){
	  Hist("CSV_Discr_TopTag_Num")->Fill(edge+0.005,1);
	}
	//For subjets
	int checksdiscr=0;
	for(unsigned int ist=0; ist<btagsub_combinedSecondaryVertex_antitop.size();++ist){
	  float test=btagsub_combinedSecondaryVertex_antitop[ist];
	  if(test>edge){
	    checksdiscr=checksdiscr+1;
	  }
	}
	if(checksdiscr>=1){
	  Hist("CSV_Sub_Discr_Num")->Fill(edge+0.005,1);
	}
	if(checksdiscr>=1&&antitoptag==1){
	  Hist("CSV_Sub_Discr_TopTag_Num")->Fill(edge+0.005,1);
	}
      }
    }
    if(antitopjet.btag_combinedSecondaryVertex()>csvcutM){
      Hist("H_CSVM_Hadronic")->Fill(antitopgen.pt(),1);
    }
    if(antitopjet.btag_combinedSecondaryVertex()>csvcutL){
      Hist("H_CSVL_Hadronic")->Fill(antitopgen.pt(),1);
    }
    if(antitoptag==1&&countsbM_antitop>=1){
      Hist("H_TopTagged_SubM_Hadronic")->Fill(antitopgen.pt(),1);
    }
    if(antitoptag==1&&countsbL_antitop>=1){
      Hist("H_TopTagged_SubL_Hadronic")->Fill(antitopgen.pt(),1);
    }
    if(antitoptag==1&&countSV_antitop>=1){
      Hist("H_TopTagged_IVF_Hadronic")->Fill(antitopgen.pt(),1);
    }
    if(countsbM_antitop>=1){
      Hist("H_SubM_Hadronic")->Fill(antitopgen.pt(),1);
    }
    if(countsbL_antitop>=1){
      Hist("H_SubL_Hadronic")->Fill(antitopgen.pt(),1);
    }
    if(countSV_antitop>=1){
      Hist("H_IVF_Hadronic")->Fill(antitopgen.pt(),1);
    }
  }

  //Mistag

  std::vector<Particle> subjets_qcd;
  std::vector<float> btagsub_combinedSecondaryVertex_qcd;
  
  TopJet jetcheck;

  int countsbM_qcd=0;
  int countsbL_qcd=0;

  int countSV_qcd=0;
  int toptag_qcd=0;

  for(unsigned int itj=0; itj<bcc->topjets->size();++itj){

    if(bcc->topjets->at(itj).pt()<=150) continue;

    countsbM_qcd=0;
    countsbL_qcd=0;
    countSV_qcd=0;
    toptag_qcd=0;

    jetcheck=bcc->topjets->at(itj);

    Hist("H_All_Mistag")->Fill(jetcheck.pt(),1);

    subjets_qcd=jetcheck.subjets();
    if(csvivf==1){
      //btagsub_combinedSecondaryVertex_qcd=jetcheck.btagsub_combinedInclusiveSecondaryVertex();
    }
    if(csvivf==0){
      btagsub_combinedSecondaryVertex_qcd=jetcheck.btagsub_combinedSecondaryVertex();
    }
    flavorsub_top=jetcheck.flavorsub();
    int indexb=-999;
    for(unsigned int ist=0; ist<btagsub_combinedSecondaryVertex_qcd.size();++ist){
      float test=btagsub_combinedSecondaryVertex_qcd[ist];
      if(test>csvcutM){
        countsbM_qcd=countsbM_qcd+1;
	indexb=ist;
      }
      if(test>csvcutL){
        countsbL_qcd=countsbL_qcd+1;
      }
    }
    if(HepTopTag(jetcheck)&&(jetcheck.v4().mass()> (172.4 - masswind))&&(jetcheck.v4().mass()< (172.4 + masswind))){
      toptag_qcd=1;
    }
    if(dohepmatch){
      toptag_qcd=0;
      if(HepTopTagMatch(jetcheck)&&(jetcheck.v4().mass()> (172.4 - masswind))&&(jetcheck.v4().mass()< (172.4 + masswind))){
	toptag_qcd=1;
      }
    }
    if(countsbM_qcd==1&&toptag_qcd==1) Hist("flav_b_sub")->Fill(abs(flavorsub_top[indexb]));
    //IVF tag
    if(doivf){
      /*
    for(unsigned int isv=0; isv< bcc->svs->size(); ++isv){
      
      PrimaryVertex pv=bcc->pvs->at(0);
      
      double xvdiff=bcc->svs->at(isv).x()-pv.x();
      double yvdiff=bcc->svs->at(isv).y()-pv.y();
      double zvdiff=bcc->svs->at(isv).z()-pv.z();
      
      TVector3 vdiff;
      
      vdiff.SetXYZ(xvdiff,yvdiff,zvdiff);
      
      LorentzVector vljet=jetcheck.v4();
      
      TVector3 vjet;
      
      vjet.SetXYZ(vljet.Px(),vljet.Py(),vljet.Pz());
      
      double etavdiff=vdiff.Eta();
      double phivdiff=vdiff.Phi();
      double etajet=vjet.Eta();
      double phijet=vjet.Phi();
      
      double deltaphivjet=phivdiff-phijet;
      if(deltaphivjet>PI) deltaphivjet = 2* PI - deltaphivjet;
      
      double deltaetavjet=etavdiff-etajet;
      
      double deltarvjet=sqrt(deltaetavjet*deltaetavjet+deltaphivjet*deltaphivjet);
      
      if(deltarvjet<assoRcut){
        countSV_qcd=countSV_qcd+1;
      }
    }//Loop over vertices
      */
    }
    if(toptag_qcd==1){
      Hist("H_TopTagged_Mistag")->Fill(jetcheck.pt(),1);
    }
    if(toptag_qcd==1&&jetcheck.btag_combinedSecondaryVertex()>csvcutM){
      Hist("H_TopTagged_CSVM_Mistag")->Fill(jetcheck.pt(),1);
    }
    if(toptag_qcd==1&&jetcheck.btag_combinedSecondaryVertex()>csvcutL){
      Hist("H_TopTagged_CSVL_Mistag")->Fill(jetcheck.pt(),1);
    }
    //Filling pt-dependent collection
    if(jetcheck.pt()>=m_ptMin&&jetcheck.pt()<m_ptMax){
      for(unsigned int idiscr=0;idiscr<500;idiscr++){
	double edge=Hist("CSV_Discr")->GetXaxis()->GetBinLowEdge(idiscr+1);
	Hist("CSV_Discr_Mistag_Den")->Fill(edge+0.005,1);
	Hist("CSV_Sub_Discr_Mistag_Den")->Fill(edge+0.005,1);
	if(jetcheck.btag_combinedSecondaryVertex()>edge){
	  Hist("CSV_Discr_Mistag_Num")->Fill(edge+0.005,1);
	}
	if(jetcheck.btag_combinedSecondaryVertex()>edge&&toptag_qcd==1){
	  Hist("CSV_Discr_Mistag_TopTag_Num")->Fill(edge+0.005,1);
	}
	//For subjets
	int checksdiscr=0;
	for(unsigned int ist=0; ist<btagsub_combinedSecondaryVertex_qcd.size();++ist){
	  float test=btagsub_combinedSecondaryVertex_qcd[ist];
	  if(test>edge){
	    checksdiscr=checksdiscr+1;
	  }
	}
	if(checksdiscr>=1){
	  Hist("CSV_Sub_Discr_Mistag_Num")->Fill(edge+0.005,1);
	}
	if(checksdiscr>=1&&toptag_qcd==1){
	  Hist("CSV_Sub_Discr_Mistag_TopTag_Num")->Fill(edge+0.005,1);
	}
      }
    } 
    if(jetcheck.btag_combinedSecondaryVertex()>csvcutM){
      Hist("H_CSVM_Mistag")->Fill(jetcheck.pt(),1);
    }
    if(jetcheck.btag_combinedSecondaryVertex()>csvcutL){
      Hist("H_CSVL_Mistag")->Fill(jetcheck.pt(),1);
    }
    if(toptag_qcd==1&&countsbM_qcd>=1){
      Hist("H_TopTagged_SubM_Mistag")->Fill(jetcheck.pt(),1);
    }
    if(toptag_qcd==1&&countsbL_qcd>=1){
      Hist("H_TopTagged_SubL_Mistag")->Fill(jetcheck.pt(),1);
    }
    if(toptag_qcd==1&&countSV_qcd>=1){
      Hist("H_TopTagged_IVF_Mistag")->Fill(jetcheck.pt(),1);
    }
    if(countsbM_qcd>=1){
      Hist("H_SubM_Mistag")->Fill(jetcheck.pt(),1);
    }
    if(countsbL_qcd>=1){
      Hist("H_SubL_Mistag")->Fill(jetcheck.pt(),1);
    }
    if(countSV_qcd>=1){
      Hist("H_IVF_Mistag")->Fill(jetcheck.pt(),1);
    }

  }//loop over mistag jets

  Particle subjet1;
  Particle subjet2;
  double drisomin;
  double driso3;
  double csv1;
  double csv2;
  int tag1=0;
  int tag2=0;
  int fattag=0;
  int flav1;
  int flav2;

  int applySiso=0;
  int asklight=0;
  double isocut=0.6;

  std::vector<Particle> subjets;
  std::vector<float> subjets_combinedSecondaryVertex;

  int isiso=0;

  int light123_1=0;
  int light123_2=0;
  int light123_3=0;

  int b123_1=0;
  int b123_2=0;
  int b123_3=0;
 
  int countlight=0;
  int countb=0;

  Particle subjet123_1;
  Particle subjet123_2;
  Particle subjet123_3;
  double csv123_1;
  double csv123_2;
  double csv123_3;
  int tag123_1=0;
  int tag123_2=0;
  int tag123_3=0;
  int fattag123=0;

  int checkflav;

  if(HepTopTag(topjet)&&goodtop==1&&topjet.pt()>=m_ptMin&&topjet.pt()<m_ptMax){
    subjets = topjet.subjets();
    subjets_combinedSecondaryVertex=topjet.btagsub_combinedSecondaryVertex();
    flavorsub_top=topjet.flavorsub();
    double dr12=subjets[0].deltaR(subjets[1]);
    double dr13=subjets[0].deltaR(subjets[2]);
    double dr23=subjets[1].deltaR(subjets[2]);
    driso3=sqrt(dr12*dr12+dr13*dr13+dr23*dr23);
    //123 study
    checkflav=flavorsub_top[0];
    if(abs(checkflav)==1||abs(checkflav)==2||abs(checkflav)==3||abs(checkflav)==21){
      light123_1=1;
      countlight=countlight+1;
    }
    if(abs(checkflav)==5){
      b123_1=1;
      countb=countb+1;
    }
    checkflav=flavorsub_top[1];
    if(abs(checkflav)==1||abs(checkflav)==2||abs(checkflav)==3||abs(checkflav)==21){
      light123_2=1;
      countlight=countlight+1;
    }
    if(abs(checkflav)==5){
      b123_2=1;
      countb=countb+1;
    }
    checkflav=flavorsub_top[2];
    if(abs(checkflav)==1||abs(checkflav)==2||abs(checkflav)==3||abs(checkflav)==21){
      light123_3=1;
      countlight=countlight+1;
    }
    if(abs(checkflav)==5){
      b123_3=1;
      countb=countb+1;
    }
    if(countb!=0){
      if(b123_1==1){
	subjet123_1=subjets[0];
	csv123_1=subjets_combinedSecondaryVertex[0];
	if(!asklight){
	  if((subjets[1].pt()<=subjets[2].pt())){
	    subjet123_2=subjets[1];
	    csv123_2=subjets_combinedSecondaryVertex[1];
	    subjet123_3=subjets[2];
	    csv123_3=subjets_combinedSecondaryVertex[2];
	  }
	  if((subjets[1].pt()>subjets[2].pt())){
	    subjet123_2=subjets[2];
	    csv123_2=subjets_combinedSecondaryVertex[2];
	    subjet123_3=subjets[1];
	    csv123_3=subjets_combinedSecondaryVertex[1];
	  }
	}
      }
      if(b123_2==1){
	subjet123_1=subjets[1];
	csv123_1=subjets_combinedSecondaryVertex[1];
	if(!asklight){
	  if((subjets[0].pt()<=subjets[2].pt())){
	    subjet123_2=subjets[0];
	    csv123_2=subjets_combinedSecondaryVertex[0];
	    subjet123_3=subjets[2];
	    csv123_3=subjets_combinedSecondaryVertex[2];
	  }
	  if((subjets[0].pt()>subjets[2].pt())){
	    subjet123_2=subjets[2];
	    csv123_2=subjets_combinedSecondaryVertex[2];
	    subjet123_3=subjets[0];
	    csv123_3=subjets_combinedSecondaryVertex[0];
	  }
	}
      }
      if(b123_3==1){
	subjet123_1=subjets[2];
	csv123_1=subjets_combinedSecondaryVertex[2];
	if(!asklight){
	  if((subjets[0].pt()<=subjets[1].pt())){
	    subjet123_2=subjets[0];
	    csv123_2=subjets_combinedSecondaryVertex[0];
	    subjet123_3=subjets[1];
	    csv123_3=subjets_combinedSecondaryVertex[1];
	  }
	  if((subjets[0].pt()>subjets[1].pt())){
	    subjet123_2=subjets[1];
	    csv123_2=subjets_combinedSecondaryVertex[1];
	    subjet123_3=subjets[0];
	    csv123_3=subjets_combinedSecondaryVertex[0];
	  }
	}
      }
      if(asklight&&light123_1==1&&light123_2==1&&(subjets[0].pt()<=subjets[1].pt())){
	subjet123_2=subjets[0];
	csv123_2=subjets_combinedSecondaryVertex[0];
	subjet123_3=subjets[1];
	csv123_3=subjets_combinedSecondaryVertex[1];
      }
      if(asklight&&light123_1==1&&light123_2==1&&(subjets[0].pt()>subjets[1].pt())){
	subjet123_2=subjets[1];
	csv123_2=subjets_combinedSecondaryVertex[1];
	subjet123_3=subjets[0];
	csv123_3=subjets_combinedSecondaryVertex[0];
      }
      if(asklight&&light123_2==1&&light123_3==1&&(subjets[1].pt()<=subjets[2].pt())){
	subjet123_2=subjets[1];
	csv123_2=subjets_combinedSecondaryVertex[1];
	subjet123_3=subjets[2];
	csv123_3=subjets_combinedSecondaryVertex[2];
      }
      if(asklight&&light123_2==1&&light123_3==1&&(subjets[1].pt()>subjets[2].pt())){
	subjet123_2=subjets[2];
	csv123_2=subjets_combinedSecondaryVertex[2];
	subjet123_3=subjets[1];
	csv123_3=subjets_combinedSecondaryVertex[1];
      }
      if(asklight&&light123_1==1&&light123_3==1&&(subjets[0].pt()<=subjets[2].pt())){
	subjet123_2=subjets[0];
	csv123_2=subjets_combinedSecondaryVertex[0];
	subjet123_3=subjets[2];
	csv123_3=subjets_combinedSecondaryVertex[2];
      }
      if(asklight&&light123_1==1&&light123_3==1&&(subjets[0].pt()>subjets[2].pt())){
	subjet123_2=subjets[2];
	csv123_2=subjets_combinedSecondaryVertex[2];
	subjet123_3=subjets[0];
	csv123_3=subjets_combinedSecondaryVertex[0];
      }
      if(csv123_1>csvcutM) tag123_1=1;
      if(csv123_2>csvcutM) tag123_2=1;
      if(csv123_3>csvcutM) tag123_3=1;
      if((!asklight)||(asklight&&countb==1&&countlight==2)){
	if(topjet.btag_combinedSecondaryVertex()>csvcutM) fattag123=1;
	Hist("effdriso3_llb_den")->Fill(driso3, weight);
	if(fattag123) Hist("effdriso3_fat_llb_num")->Fill(driso3, weight);
	if(tag123_1) Hist("effdriso3_llb1_num")->Fill(driso3, weight);
	if(tag123_2) Hist("effdriso3_llb2_num")->Fill(driso3, weight);
	if(tag123_3) Hist("effdriso3_llb3_num")->Fill(driso3, weight);
	if(tag123_1&&tag123_2&&tag123_3) Hist("effdriso3_llb_and_num")->Fill(driso3, weight);
      }
    }//123 case
    if(dr12<=dr13&&dr12<=dr23){
      if(dr13>isocut&&dr23>isocut) isiso=1;
      if(subjets[0].pt()<=subjets[1].pt()){
	subjet1=subjets[0];
	subjet2=subjets[1];
	csv1=subjets_combinedSecondaryVertex[0];
	csv2=subjets_combinedSecondaryVertex[1];
	flav1=flavorsub_top[0];
	flav2=flavorsub_top[1];
	drisomin=dr12;
      }
      else{
	subjet1=subjets[1];
	subjet2=subjets[0];
	csv1=subjets_combinedSecondaryVertex[1];
	csv2=subjets_combinedSecondaryVertex[0];
	flav1=flavorsub_top[1];
	flav2=flavorsub_top[0];
	drisomin=dr12;
      }
    }
    if(dr13<=dr12&&dr13<=dr23){
      if(dr12>isocut&&dr23>isocut) isiso=1;
      if(subjets[0].pt()<=subjets[2].pt()){
	subjet1=subjets[0];
	subjet2=subjets[2];
	csv1=subjets_combinedSecondaryVertex[0];
	csv2=subjets_combinedSecondaryVertex[2];
	flav1=flavorsub_top[0];
	flav2=flavorsub_top[2];
	drisomin=dr13;
      }
      else{
	subjet1=subjets[2];
	subjet2=subjets[0];
	csv1=subjets_combinedSecondaryVertex[2];
	csv2=subjets_combinedSecondaryVertex[0];
	flav1=flavorsub_top[2];
	flav2=flavorsub_top[0];
	drisomin=dr13;
      }
    }
    if(dr23<=dr12&&dr23<=dr13){
      if(dr12>isocut&&dr13>isocut) isiso=1;
      if(subjets[1].pt()<=subjets[2].pt()){
	subjet1=subjets[1];
	subjet2=subjets[2];
	csv1=subjets_combinedSecondaryVertex[1];
	csv2=subjets_combinedSecondaryVertex[2];
	flav1=flavorsub_top[1];
	flav2=flavorsub_top[2];
	drisomin=dr23;
      }
      else{
	subjet1=subjets[2];
	subjet2=subjets[1];
	csv1=subjets_combinedSecondaryVertex[2];
	csv2=subjets_combinedSecondaryVertex[1];
	flav1=flavorsub_top[2];
	flav2=flavorsub_top[1];
	drisomin=dr23;
      }
    }
    if(applySiso==0 || (applySiso==1&&isiso==1)){
      if(csv1>csvcutM) tag1=1;
      if(csv2>csvcutM) tag2=1;
      if(topjet.btag_combinedSecondaryVertex()>csvcutM) fattag=1;
      if(fattag) Hist("effdriso_fat_num")->Fill(drisomin, weight);
      if(fattag) Hist("effdriso3_fat_num")->Fill(driso3, weight);
      Hist("effdriso_fat_den")->Fill(drisomin, weight);
      Hist("effdriso3_fat_den")->Fill(driso3, weight);
      int light1=0;
      int light2=0;
      int b1=0;
      int b2=0;
      if(abs(flav1)==1||abs(flav1)==2||abs(flav1)==3||abs(flav1)==21) light1=1; 
      if(abs(flav2)==1||abs(flav2)==2||abs(flav2)==3||abs(flav2)==21) light2=1;
      if(abs(flav1)==5) b1=1;
      if(abs(flav2)==5) b2=1;
      if(light1&&light2&&(!asklight||(asklight&&(abs(flav1)!=abs(flav2))))){//leave ordering in pT
	if(fattag) Hist("effdriso_fat_ll_num")->Fill(drisomin, weight);
	if(fattag) Hist("effdriso3_fat_ll_num")->Fill(driso3, weight);
	Hist("effdriso_fat_ll_den")->Fill(drisomin, weight);
	Hist("effdriso3_fat_ll_den")->Fill(driso3, weight);
	Hist("effdriso_ll_den")->Fill(drisomin,weight);
	Hist("effdriso3_ll_den")->Fill(driso3,weight);
	if(tag1) Hist("effdriso_ll_num1")->Fill(drisomin,weight);
	if(tag2) Hist("effdriso_ll_num2")->Fill(drisomin,weight);
	if(tag1) Hist("effdriso3_ll_num1")->Fill(driso3,weight);
	if(tag2) Hist("effdriso3_ll_num2")->Fill(driso3,weight);
	if(tag1&&tag2) Hist("effdriso_ll_and_num")->Fill(drisomin,weight);
	if(tag1&&tag2) Hist("effdriso3_ll_and_num")->Fill(driso3,weight);
      }
      if(b2){//order in flavor
	if(!asklight||(asklight&&light1)){
	  if(fattag) Hist("effdriso_fat_lb_num")->Fill(drisomin, weight);
	  if(fattag) Hist("effdriso3_fat_lb_num")->Fill(driso3, weight);
	  Hist("effdriso_fat_lb_den")->Fill(drisomin, weight);
	  Hist("effdriso3_fat_lb_den")->Fill(driso3, weight);
	  Hist("effdriso_lb_den")->Fill(drisomin,weight);
	  Hist("effdriso3_lb_den")->Fill(driso3,weight);
	  if(tag1) Hist("effdriso_lb_num2")->Fill(drisomin,weight);
	  if(tag2) Hist("effdriso_lb_num1")->Fill(drisomin,weight);
	  if(tag1) Hist("effdriso3_lb_num2")->Fill(driso3,weight);
	  if(tag2) Hist("effdriso3_lb_num1")->Fill(driso3,weight);
	  if(tag1&&tag2) Hist("effdriso_lb_and_num")->Fill(drisomin,weight);
	  if(tag1&&tag2) Hist("effdriso3_lb_and_num")->Fill(driso3,weight);
	}
      }
      if(b1){//order in flavor
	if(!asklight||(asklight&&light2)){
	  if(fattag) Hist("effdriso_fat_lb_num")->Fill(drisomin, weight);
	  if(fattag) Hist("effdriso3_fat_lb_num")->Fill(driso3, weight);
	  Hist("effdriso_fat_lb_den")->Fill(drisomin, weight);
	  Hist("effdriso3_fat_lb_den")->Fill(driso3, weight);
	  Hist("effdriso_lb_den")->Fill(drisomin,weight);
	  Hist("effdriso3_lb_den")->Fill(driso3,weight);
	  if(tag1) Hist("effdriso_lb_num1")->Fill(drisomin,weight);
	  if(tag2) Hist("effdriso_lb_num2")->Fill(drisomin,weight);
	  if(tag1) Hist("effdriso3_lb_num1")->Fill(driso3,weight);
	  if(tag2) Hist("effdriso3_lb_num2")->Fill(driso3,weight);
	  if(tag1&&tag2) Hist("effdriso_lb_and_num")->Fill(drisomin,weight);
	  if(tag1&&tag2) Hist("effdriso3_lb_and_num")->Fill(driso3,weight);
	}
      }
    }//is iso
  }//goodtop
  
  tag1=0;
  tag2=0;
  fattag=0;
  isiso=0;

  light123_1=0;
  light123_2=0;
  light123_3=0;

  b123_1=0;
  b123_2=0;
  b123_3=0;
 
  countlight=0;
  countb=0;

  tag123_1=0;
  tag123_2=0;
  tag123_3=0;
  fattag123=0;

  if(HepTopTag(antitopjet)&&goodantitop==1&&antitopjet.pt()>=m_ptMin&&antitopjet.pt()<m_ptMax){
    subjets = antitopjet.subjets();
    subjets_combinedSecondaryVertex=antitopjet.btagsub_combinedSecondaryVertex();
    flavorsub_top=antitopjet.flavorsub();
    double dr12=subjets[0].deltaR(subjets[1]);
    double dr13=subjets[0].deltaR(subjets[2]);
    double dr23=subjets[1].deltaR(subjets[2]);
    driso3=sqrt(dr12*dr12+dr13*dr13+dr23*dr23);
    //123 study
    checkflav=flavorsub_top[0];
    if(abs(checkflav)==1||abs(checkflav)==2||abs(checkflav)==3||abs(checkflav)==21){
      light123_1=1;
      countlight=countlight+1;
    }
    if(abs(checkflav)==5){
      b123_1=1;
      countb=countb+1;
    }
    checkflav=flavorsub_top[1];
    if(abs(checkflav)==1||abs(checkflav)==2||abs(checkflav)==3||abs(checkflav)==21){
      light123_2=1;
      countlight=countlight+1;
    }
    if(abs(checkflav)==5){
      b123_2=1;
      countb=countb+1;
    }
    checkflav=flavorsub_top[2];
    if(abs(checkflav)==1||abs(checkflav)==2||abs(checkflav)==3||abs(checkflav)==21){
      light123_3=1;
      countlight=countlight+1;
    }
    if(abs(checkflav)==5){
      b123_3=1;
      countb=countb+1;
    }
    if(countb!=0){
      if(b123_1==1){
	subjet123_1=subjets[0];
	csv123_1=subjets_combinedSecondaryVertex[0];
	if(!asklight){
	  if((subjets[1].pt()<=subjets[2].pt())){
	    subjet123_2=subjets[1];
	    csv123_2=subjets_combinedSecondaryVertex[1];
	    subjet123_3=subjets[2];
	    csv123_3=subjets_combinedSecondaryVertex[2];
	  }
	  if((subjets[1].pt()>subjets[2].pt())){
	    subjet123_2=subjets[2];
	    csv123_2=subjets_combinedSecondaryVertex[2];
	    subjet123_3=subjets[1];
	    csv123_3=subjets_combinedSecondaryVertex[1];
	  }
	}
      }
      if(b123_2==1){
	subjet123_1=subjets[1];
	csv123_1=subjets_combinedSecondaryVertex[1];
	if(!asklight){
	  if((subjets[0].pt()<=subjets[2].pt())){
	    subjet123_2=subjets[0];
	    csv123_2=subjets_combinedSecondaryVertex[0];
	    subjet123_3=subjets[2];
	    csv123_3=subjets_combinedSecondaryVertex[2];
	  }
	  if((subjets[0].pt()>subjets[2].pt())){
	    subjet123_2=subjets[2];
	    csv123_2=subjets_combinedSecondaryVertex[2];
	    subjet123_3=subjets[0];
	    csv123_3=subjets_combinedSecondaryVertex[0];
	  }
	}
      }
      if(b123_3==1){
	subjet123_1=subjets[2];
	csv123_1=subjets_combinedSecondaryVertex[2];
	if(!asklight){
	  if((subjets[0].pt()<=subjets[1].pt())){
	    subjet123_2=subjets[0];
	    csv123_2=subjets_combinedSecondaryVertex[0];
	    subjet123_3=subjets[1];
	    csv123_3=subjets_combinedSecondaryVertex[1];
	  }
	  if((subjets[0].pt()>subjets[1].pt())){
	    subjet123_2=subjets[1];
	    csv123_2=subjets_combinedSecondaryVertex[1];
	    subjet123_3=subjets[0];
	    csv123_3=subjets_combinedSecondaryVertex[0];
	  }
	}
      }
      if(asklight&&light123_1==1&&light123_2==1&&(subjets[0].pt()<=subjets[1].pt())){
	subjet123_2=subjets[0];
	csv123_2=subjets_combinedSecondaryVertex[0];
	subjet123_3=subjets[1];
	csv123_3=subjets_combinedSecondaryVertex[1];
      }
      if(asklight&&light123_1==1&&light123_2==1&&(subjets[0].pt()>subjets[1].pt())){
	subjet123_2=subjets[1];
	csv123_2=subjets_combinedSecondaryVertex[1];
	subjet123_3=subjets[0];
	csv123_3=subjets_combinedSecondaryVertex[0];
      }
      if(asklight&&light123_2==1&&light123_3==1&&(subjets[1].pt()<=subjets[2].pt())){
	subjet123_2=subjets[1];
	csv123_2=subjets_combinedSecondaryVertex[1];
	subjet123_3=subjets[2];
	csv123_3=subjets_combinedSecondaryVertex[2];
      }
      if(asklight&&light123_2==1&&light123_3==1&&(subjets[1].pt()>subjets[2].pt())){
	subjet123_2=subjets[2];
	csv123_2=subjets_combinedSecondaryVertex[2];
	subjet123_3=subjets[1];
	csv123_3=subjets_combinedSecondaryVertex[1];
      }
      if(asklight&&light123_1==1&&light123_3==1&&(subjets[0].pt()<=subjets[2].pt())){
	subjet123_2=subjets[0];
	csv123_2=subjets_combinedSecondaryVertex[0];
	subjet123_3=subjets[2];
	csv123_3=subjets_combinedSecondaryVertex[2];
      }
      if(asklight&&light123_1==1&&light123_3==1&&(subjets[0].pt()>subjets[2].pt())){
	subjet123_2=subjets[2];
	csv123_2=subjets_combinedSecondaryVertex[2];
	subjet123_3=subjets[0];
	csv123_3=subjets_combinedSecondaryVertex[0];
      }
      if(csv123_1>csvcutM) tag123_1=1;
      if(csv123_2>csvcutM) tag123_2=1;
      if(csv123_3>csvcutM) tag123_3=1;
      if((!asklight)||(asklight&&countb==1&&countlight==2)){
	if(antitopjet.btag_combinedSecondaryVertex()>csvcutM) fattag123=1;
	Hist("effdriso3_llb_den")->Fill(driso3, weight);
	if(fattag123) Hist("effdriso3_fat_llb_num")->Fill(driso3, weight);
	if(tag123_1) Hist("effdriso3_llb1_num")->Fill(driso3, weight);
	if(tag123_2) Hist("effdriso3_llb2_num")->Fill(driso3, weight);
	if(tag123_3) Hist("effdriso3_llb3_num")->Fill(driso3, weight);
	if(tag123_1&&tag123_2&&tag123_3) Hist("effdriso3_llb_and_num")->Fill(driso3, weight);
      }
    }//123 case
    if(dr12<=dr13&&dr12<=dr23){
      if(dr13>isocut&&dr23>isocut) isiso=1;
      if(subjets[0].pt()<=subjets[1].pt()){
	subjet1=subjets[0];
	subjet2=subjets[1];
	csv1=subjets_combinedSecondaryVertex[0];
	csv2=subjets_combinedSecondaryVertex[1];
	flav1=flavorsub_top[0];
	flav2=flavorsub_top[1];
	drisomin=dr12;
      }
      else{
	subjet1=subjets[1];
	subjet2=subjets[0];
	csv1=subjets_combinedSecondaryVertex[1];
	csv2=subjets_combinedSecondaryVertex[0];
	flav1=flavorsub_top[1];
	flav2=flavorsub_top[0];
	drisomin=dr12;
      }
    }
    if(dr13<=dr12&&dr13<=dr23){
      if(dr12>isocut&&dr23>isocut) isiso=1;
      if(subjets[0].pt()<=subjets[2].pt()){
	subjet1=subjets[0];
	subjet2=subjets[2];
	csv1=subjets_combinedSecondaryVertex[0];
	csv2=subjets_combinedSecondaryVertex[2];
	flav1=flavorsub_top[0];
	flav2=flavorsub_top[2];
	drisomin=dr13;
      }
      else{
	subjet1=subjets[2];
	subjet2=subjets[0];
	csv1=subjets_combinedSecondaryVertex[2];
	csv2=subjets_combinedSecondaryVertex[0];
	flav1=flavorsub_top[2];
	flav2=flavorsub_top[0];
	drisomin=dr13;
      }
    }
    if(dr23<=dr12&&dr23<=dr13){
      if(dr12>isocut&&dr13>isocut) isiso=1;
      if(subjets[1].pt()<=subjets[2].pt()){
	subjet1=subjets[1];
	subjet2=subjets[2];
	csv1=subjets_combinedSecondaryVertex[1];
	csv2=subjets_combinedSecondaryVertex[2];
	flav1=flavorsub_top[1];
	flav2=flavorsub_top[2];
	drisomin=dr23;
      }
      else{
	subjet1=subjets[2];
	subjet2=subjets[1];
	csv1=subjets_combinedSecondaryVertex[2];
	csv2=subjets_combinedSecondaryVertex[1];
	flav1=flavorsub_top[2];
	flav2=flavorsub_top[1];
	drisomin=dr23;
      }
    }
    if(applySiso==0 || (applySiso==1&&isiso==1)){
      if(csv1>csvcutM) tag1=1;
      if(csv2>csvcutM) tag2=1;
      if(antitopjet.btag_combinedSecondaryVertex()>csvcutM) fattag=1;
      if(fattag) Hist("effdriso_fat_num")->Fill(drisomin, weight);
      if(fattag) Hist("effdriso3_fat_num")->Fill(driso3, weight);
      Hist("effdriso_fat_den")->Fill(drisomin, weight);
      Hist("effdriso3_fat_den")->Fill(driso3, weight);
      int light1=0;
      int light2=0;
      int b1=0;
      int b2=0;
      if(abs(flav1)==1||abs(flav1)==2||abs(flav1)==3||abs(flav1)==21) light1=1; 
      if(abs(flav2)==1||abs(flav2)==2||abs(flav2)==3||abs(flav2)==21) light2=1;
      if(abs(flav1)==5) b1=1;
      if(abs(flav2)==5) b2=1;
      if(light1&&light2&&(!asklight||(asklight&&(abs(flav1)!=abs(flav2))))){//leave ordering in pT
	if(fattag) Hist("effdriso_fat_ll_num")->Fill(drisomin, weight);
	if(fattag) Hist("effdriso3_fat_ll_num")->Fill(driso3, weight);
	Hist("effdriso_fat_ll_den")->Fill(drisomin, weight);
	Hist("effdriso3_fat_ll_den")->Fill(driso3, weight);
	Hist("effdriso_ll_den")->Fill(drisomin,weight);
	Hist("effdriso3_ll_den")->Fill(driso3,weight);
	if(tag1) Hist("effdriso_ll_num1")->Fill(drisomin,weight);
	if(tag2) Hist("effdriso_ll_num2")->Fill(drisomin,weight);
	if(tag1) Hist("effdriso3_ll_num1")->Fill(driso3,weight);
	if(tag2) Hist("effdriso3_ll_num2")->Fill(driso3,weight);
	if(tag1&&tag2) Hist("effdriso_ll_and_num")->Fill(drisomin,weight);
	if(tag1&&tag2) Hist("effdriso3_ll_and_num")->Fill(driso3,weight);
      }
      if(b2){//order in flavor
	if(!asklight||(asklight&&light1)){
	  if(fattag) Hist("effdriso_fat_lb_num")->Fill(drisomin, weight);
	  if(fattag) Hist("effdriso3_fat_lb_num")->Fill(driso3, weight);
	  Hist("effdriso_fat_lb_den")->Fill(drisomin, weight);
	  Hist("effdriso3_fat_lb_den")->Fill(driso3, weight);
	  Hist("effdriso_lb_den")->Fill(drisomin,weight);
	  Hist("effdriso3_lb_den")->Fill(driso3,weight);
	  if(tag1) Hist("effdriso_lb_num2")->Fill(drisomin,weight);
	  if(tag2) Hist("effdriso_lb_num1")->Fill(drisomin,weight);
	  if(tag1) Hist("effdriso3_lb_num2")->Fill(driso3,weight);
	  if(tag2) Hist("effdriso3_lb_num1")->Fill(driso3,weight);
	  if(tag1&&tag2) Hist("effdriso_lb_and_num")->Fill(drisomin,weight);
	  if(tag1&&tag2) Hist("effdriso3_lb_and_num")->Fill(driso3,weight);
	}
      }
      if(b1){//order in flavor
	if(!asklight||(asklight&&light2)){
	  if(fattag) Hist("effdriso_fat_lb_num")->Fill(drisomin, weight);
	  if(fattag) Hist("effdriso3_fat_lb_num")->Fill(driso3, weight);
	  Hist("effdriso_fat_lb_den")->Fill(drisomin, weight);
	  Hist("effdriso3_fat_lb_den")->Fill(driso3, weight);
	  Hist("effdriso_lb_den")->Fill(drisomin,weight);
	  Hist("effdriso3_lb_den")->Fill(driso3,weight);
	  if(tag1) Hist("effdriso_lb_num1")->Fill(drisomin,weight);
	  if(tag2) Hist("effdriso_lb_num2")->Fill(drisomin,weight);
	  if(tag1) Hist("effdriso3_lb_num1")->Fill(driso3,weight);
	  if(tag2) Hist("effdriso3_lb_num2")->Fill(driso3,weight);
	  if(tag1&&tag2) Hist("effdriso_lb_and_num")->Fill(drisomin,weight);
	  if(tag1&&tag2) Hist("effdriso3_lb_and_num")->Fill(driso3,weight);
	}
      }
    }//is iso
  }//goodantitop
  
}

void TopBTaggingHists::Finish()
{
  // final calculations, like division and addition of certain histograms
  EventCalc* calc = EventCalc::Instance();
  bool IsRealData = calc->IsRealData();

  //Hist("effdriso_fat")->Divide(Hist("effdriso_fat_num"),Hist("effdriso_fat_den"),1,1,"B");
  //Hist("effdriso3_fat")->Divide(Hist("effdriso3_fat_num"),Hist("effdriso3_fat_den"),1,1,"B");
  //Hist("effdriso_fat_ll")->Divide(Hist("effdriso_fat_ll_num"),Hist("effdriso_fat_ll_den"),1,1,"B");
  //Hist("effdriso3_fat_ll")->Divide(Hist("effdriso3_fat_ll_num"),Hist("effdriso3_fat_ll_den"),1,1,"B");
  //Hist("effdriso_fat_lb")->Divide(Hist("effdriso_fat_lb_num"),Hist("effdriso_fat_lb_den"),1,1,"B");
  //Hist("effdriso3_fat_lb")->Divide(Hist("effdriso3_fat_lb_num"),Hist("effdriso3_fat_lb_den"),1,1,"B");
  //Hist("effdriso_ll1")->Divide(Hist("effdriso_ll_num1"),Hist("effdriso_ll_den"),1,1,"B");
  //Hist("effdriso_ll2")->Divide(Hist("effdriso_ll_num2"),Hist("effdriso_ll_den"),1,1,"B");
  //Hist("effdriso_lb1")->Divide(Hist("effdriso_lb_num1"),Hist("effdriso_lb_den"),1,1,"B");
  //Hist("effdriso_lb2")->Divide(Hist("effdriso_lb_num2"),Hist("effdriso_lb_den"),1,1,"B");
  //Hist("effdriso3_ll1")->Divide(Hist("effdriso3_ll_num1"),Hist("effdriso3_ll_den"),1,1,"B");
  //Hist("effdriso3_ll2")->Divide(Hist("effdriso3_ll_num2"),Hist("effdriso3_ll_den"),1,1,"B");
  //Hist("effdriso3_lb1")->Divide(Hist("effdriso3_lb_num1"),Hist("effdriso3_lb_den"),1,1,"B");
  //Hist("effdriso3_lb2")->Divide(Hist("effdriso3_lb_num2"),Hist("effdriso3_lb_den"),1,1,"B");
  //Hist("effdriso3_lb_and")->Divide(Hist("effdriso3_lb_and_num"),Hist("effdriso3_lb_den"),1,1,"B");
  //Hist("effdriso3_ll_and")->Divide(Hist("effdriso3_ll_and_num"),Hist("effdriso3_ll_den"),1,1,"B");
  //Hist("effdriso_lb_and")->Divide(Hist("effdriso_lb_and_num"),Hist("effdriso_lb_den"),1,1,"B");
  //Hist("effdriso_ll_and")->Divide(Hist("effdriso_ll_and_num"),Hist("effdriso_ll_den"),1,1,"B");
  //Hist("effdriso_ll_x")->Multiply(Hist("effdriso_ll1"),Hist("effdriso_ll2"),1,1);
  //Hist("effdriso3_ll_x")->Multiply(Hist("effdriso3_ll1"),Hist("effdriso3_ll2"),1,1);
  //Hist("effdriso_lb_x")->Multiply(Hist("effdriso_lb1"),Hist("effdriso_lb2"),1,1);
  //Hist("effdriso3_lb_x")->Multiply(Hist("effdriso3_lb1"),Hist("effdriso3_lb2"),1,1);

  //Hist("H_Example_Effi")->Divide(Hist("H_Example"),Hist("H_Example"),1,1,"B");
  Hist("H_Effi_Matched")->Divide(Hist("H_Matched_Hadronic"),Hist("H_All_Hadronic"),1,1,"B");
  Hist("H_Effi_TopTag")->Divide(Hist("H_TopTagged_Hadronic"),Hist("H_All_Hadronic"),1,1,"B");
  Hist("H_Effi_TopTag_SubM")->Divide(Hist("H_TopTagged_SubM_Hadronic"),Hist("H_All_Hadronic"),1,1,"B");
  Hist("H_Effi_TopTag_SubL")->Divide(Hist("H_TopTagged_SubL_Hadronic"),Hist("H_All_Hadronic"),1,1,"B");
  Hist("H_Effi_TopTag_IVF")->Divide(Hist("H_TopTagged_IVF_Hadronic"),Hist("H_All_Hadronic"),1,1,"B");
  Hist("H_Effi_SubM")->Divide(Hist("H_SubM_Hadronic"),Hist("H_All_Hadronic"),1,1,"B");
  Hist("H_Effi_SubL")->Divide(Hist("H_SubL_Hadronic"),Hist("H_All_Hadronic"),1,1,"B");
  Hist("H_Effi_IVF")->Divide(Hist("H_IVF_Hadronic"),Hist("H_All_Hadronic"),1,1,"B");
  Hist("H_Effi_TopTag_Mistag")->Divide(Hist("H_TopTagged_Mistag"),Hist("H_All_Mistag"),1,1,"B");
  Hist("H_Effi_TopTag_Mistag_SubM")->Divide(Hist("H_TopTagged_SubM_Mistag"),Hist("H_All_Mistag"),1,1,"B");
  Hist("H_Effi_TopTag_Mistag_SubL")->Divide(Hist("H_TopTagged_SubL_Mistag"),Hist("H_All_Mistag"),1,1,"B");
  Hist("H_Effi_TopTag_Mistag_IVF")->Divide(Hist("H_TopTagged_IVF_Mistag"),Hist("H_All_Mistag"),1,1,"B");
  Hist("H_Effi_Mistag_SubM")->Divide(Hist("H_SubM_Mistag"),Hist("H_All_Mistag"),1,1,"B");
  Hist("H_Effi_Mistag_SubL")->Divide(Hist("H_SubL_Mistag"),Hist("H_All_Mistag"),1,1,"B");
  Hist("H_Effi_Mistag_IVF")->Divide(Hist("H_IVF_Mistag"),Hist("H_All_Mistag"),1,1,"B");
  Hist("H_Effi_TopTag_CSVM")->Divide(Hist("H_TopTagged_CSVM_Hadronic"),Hist("H_All_Hadronic"),1,1,"B");
  Hist("H_Effi_TopTag_CSVL")->Divide(Hist("H_TopTagged_CSVL_Hadronic"),Hist("H_All_Hadronic"),1,1,"B");
  Hist("H_Effi_CSVM")->Divide(Hist("H_CSVM_Hadronic"),Hist("H_All_Hadronic"),1,1,"B");
  Hist("H_Effi_CSVL")->Divide(Hist("H_CSVL_Hadronic"),Hist("H_All_Hadronic"),1,1,"B");
  Hist("H_Effi_TopTag_Mistag_CSVM")->Divide(Hist("H_TopTagged_CSVM_Mistag"),Hist("H_All_Mistag"),1,1,"B");
  Hist("H_Effi_TopTag_Mistag_CSVL")->Divide(Hist("H_TopTagged_CSVL_Mistag"),Hist("H_All_Mistag"),1,1,"B");
  Hist("H_Effi_Mistag_CSVM")->Divide(Hist("H_CSVM_Mistag"),Hist("H_All_Mistag"),1,1,"B");
  Hist("H_Effi_Mistag_CSVL")->Divide(Hist("H_CSVL_Mistag"),Hist("H_All_Mistag"),1,1,"B");
  
  Hist("CSV_Sub_Discr_Effi")->Divide(Hist("CSV_Sub_Discr_Num"),Hist("CSV_Sub_Discr_Den"),1,1,"B");
  Hist("CSV_Sub_Discr_Mistag_Effi")->Divide(Hist("CSV_Sub_Discr_Mistag_Num"),Hist("CSV_Sub_Discr_Mistag_Den"),1,1,"B");
  Hist("CSV_Sub_Discr_TopTag_Effi")->Divide(Hist("CSV_Sub_Discr_TopTag_Num"),Hist("CSV_Sub_Discr_Den"),1,1,"B");
  Hist("CSV_Sub_Discr_Mistag_TopTag_Effi")->Divide(Hist("CSV_Sub_Discr_Mistag_TopTag_Num"),Hist("CSV_Sub_Discr_Mistag_Den"),1,1,"B");
  Hist("CSV_Discr_Effi")->Divide(Hist("CSV_Discr_Num"),Hist("CSV_Discr_Den"),1,1,"B");
  Hist("CSV_Discr_Mistag_Effi")->Divide(Hist("CSV_Discr_Mistag_Num"),Hist("CSV_Discr_Mistag_Den"),1,1,"B");
  Hist("CSV_Discr_TopTag_Effi")->Divide(Hist("CSV_Discr_TopTag_Num"),Hist("CSV_Discr_Den"),1,1,"B");
  Hist("CSV_Discr_Mistag_TopTag_Effi")->Divide(Hist("CSV_Discr_Mistag_TopTag_Num"),Hist("CSV_Discr_Mistag_Den"),1,1,"B");

}

