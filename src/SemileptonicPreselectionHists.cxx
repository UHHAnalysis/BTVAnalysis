#include "include/SemileptonicPreselectionHists.h"

#include "SFrameTools/include/EventCalc.h"
#include "TH2.h"
#include "TGraphErrors.h"

#include <iostream>

using namespace std;

SemileptonicPreselectionHists::SemileptonicPreselectionHists(const char* name) : BaseHists(name)
{
  // named default constructor
   
}

SemileptonicPreselectionHists::~SemileptonicPreselectionHists()
{
  // default destructor, does nothing
}

void SemileptonicPreselectionHists::Init()
{
  // book all histograms here

  Book( TH1F( "N_topjets", ";N^{jets};Events", 20, 0, 20 ) );
  Book( TH1F( "N_mu", ";N^{muons};Events", 5, 0, 5 ) );
  Book( TH1F( "N_pv", ";N^{PV};Events", 50, 0, 50 ) );

}

void SemileptonicPreselectionHists::Fill()
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

  BaseCycleContainer* bcc = calc->GetBaseCycleContainer();

  Hist("N_pv")->Fill(Npvs, weight);

  int Ntopjets = bcc->topjets->size();
  Hist("N_topjets")->Fill(Ntopjets, weight);

  std::vector<Muon>* muons = calc->GetMuons();
  int Nmuons = muons->size();
  Hist("N_mu")->Fill(Nmuons, weight);


}

void SemileptonicPreselectionHists::Finish()
{
  // final calculations, like division and addition of certain histograms
  EventCalc* calc = EventCalc::Instance();
  bool IsRealData = calc->IsRealData();

}

