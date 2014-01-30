// $Id: BTVCycle.cxx,v 1.10 2012/12/07 14:21:51 peiffer Exp $

#include <iostream>

using namespace std;

#include "include/BTVCycle.h"
#include "include/BTVHists.h"

#include "SFrameAnalysis/include/SelectionModules.h"
#include "SFrameAnalysis/include/HypothesisHists.h"
#include "../SFrameAnalysis/include/LikelihoodHists.h"
ClassImp( BTVCycle );

BTVCycle::BTVCycle()
   : AnalysisCycle() {

  // constructor, declare additional variables that should be 
  // obtained from the steering-xml file
  
  // set the integrated luminosity per bin for the lumi-yield control plots
  SetIntLumiPerBin(500.);
  DeclareProperty( "Thetafile", m_thetainput);
  DeclareProperty( "BTagEffi_Filename_MC", m_BTagEffiFilenameMC );
  DeclareProperty( "BTaggingMode", m_BTaggingMode);

}

BTVCycle::~BTVCycle() 
{
  // destructor
}

void BTVCycle::BeginCycle() throw( SError ) 
{
  // Start of the job, general set-up and definition of 
  // objects are done here

  // Important: first call BeginCycle of base class
  AnalysisCycle::BeginCycle();

  return;

}

void BTVCycle::EndCycle() throw( SError ) 
{
  // clean-up, info messages and final calculations after the analysis

  
  // call the base cycle class for all standard methods
  AnalysisCycle::EndCycle();

  return;

}

void BTVCycle::BeginInputData( const SInputData& id ) throw( SError ) 
{
  // declaration of histograms and selections.
  // AnalysisCyle expects Selections and HistCollections to be registered here.
  // Their memory will be released in AnalysisCycle::EndInputData.

   if(m_BTagEffiFilenameMC.size()>0)
    {
      m_BTagEffiFilenameMC += ".";
      m_BTagEffiFilenameMC += id.GetType();
      m_BTagEffiFilenameMC += ".";
      m_BTagEffiFilenameMC += id.GetVersion();
      m_BTagEffiFilenameMC += ".root";
    }
  else{
    m_BTagEffiFilenameMC="";
  }

  if(!(m_BTaggingMode.size()>0))  m_BTaggingMode="default";

  // Important: first call BeginInputData of base class
  AnalysisCycle::BeginInputData( id );

  


  // -------------------- set up the selections ---------------------------

  //Cross-checks with Rebekka
  Selection* trigger = new Selection("HLT_HT750");
  Selection* nJets = new Selection("nJets");
  Selection* topTag = new Selection("topTag");
  Selection* topAndSubBTag = new Selection("topAndSubBTag");
  Selection* topAndSubBTagPlusHiggsTag = new Selection("topAndSubBTagPlusHiggsTag");
  Selection* HT1000 = new Selection("HT1000");
  Selection* invertedTopTag = new Selection("invertedTopTag");
  Selection* fullyInvertedHiggsTag = new Selection("fullyInvertedHiggsTag");
  Selection* fullyInvertedTopAndHiggsTag = new Selection("fullyInvertedTopAndHiggsTag");
  Selection* HTSubJets720 = new Selection("HTSubJets720");

  HTSubJets720->addSelectionModule(new HTSubJetsCut(720.));
  trigger->addSelectionModule(new TriggerSelection("HLT_HT750"));
  nJets->addSelectionModule(new NTopJetSelection(2, 99, 0., 99.));
  topTag->addSelectionModule(new NHEPTopTagSelection(1, 99));
  topAndSubBTag->addSelectionModule(new NHEPTopAndSubBTagSelection(1, 99, e_CSVM, m_BTaggingMode, m_BTagEffiFilenameMC ));
  topAndSubBTagPlusHiggsTag->addSelectionModule(new HEPTopAndSubBTagPlusOtherHiggsTag(e_CSVM, e_CSVM, e_CSVM,  m_BTaggingMode, m_BTagEffiFilenameMC, 60.));										  
  HT1000->addSelectionModule(new HTCut(1380.));
  invertedTopTag->addSelectionModule(new InvertedTopTagRegularBTagRegularHiggsTag(e_CSVM, e_CSVM, e_CSVM,  m_BTaggingMode, m_BTagEffiFilenameMC, 60.));
  fullyInvertedHiggsTag->addSelectionModule(new RegularTopTagRegularBTagFullyInvertedHiggsTag(e_CSVM, e_CSVL, e_CSVL));
  fullyInvertedTopAndHiggsTag->addSelectionModule(new InvertedTopTagRegularBTagFullyInvertedHiggsTag(e_CSVM, e_CSVL, e_CSVL));
  
  RegisterSelection(trigger);
  RegisterSelection(nJets);
  RegisterSelection(topTag);
  RegisterSelection(topAndSubBTag);
  RegisterSelection(topAndSubBTagPlusHiggsTag);
  RegisterSelection(HT1000);
  RegisterSelection(invertedTopTag);
  RegisterSelection(fullyInvertedHiggsTag);
  RegisterSelection(fullyInvertedTopAndHiggsTag);
  RegisterSelection(HTSubJets720);

  // ---------------- set up the histogram collections --------------------

  // histograms without any cuts
  RegisterHistCollection( new BTVHists("NoCuts",m_BTaggingMode, m_BTagEffiFilenameMC) );
  RegisterHistCollection( new BTVHists("Trigger",  m_BTaggingMode, m_BTagEffiFilenameMC) );
  RegisterHistCollection( new BTVHists("Signal",  m_BTaggingMode, m_BTagEffiFilenameMC) );
  RegisterHistCollection( new BTVHists("Invertedtopregularhiggs",  m_BTaggingMode, m_BTagEffiFilenameMC) );
  RegisterHistCollection( new LikelihoodHists("like500", m_thetainput, "500",  m_BTaggingMode, m_BTagEffiFilenameMC) );
  // important: initialise histogram collections after their definition
  InitHistos();

}

void BTVCycle::EndInputData( const SInputData& id ) throw( SError ) 
{
  AnalysisCycle::EndInputData( id );
}

void BTVCycle::BeginInputFile( const SInputData& id ) throw( SError ) 
{
  // Connect all variables from the Ntuple file with the ones needed for the analysis
  // The variables are commonly stored in the BaseCycleContaincer

  // important: call to base function to connect all variables to Ntuples from the input tree
  AnalysisCycle::BeginInputFile( id );
}

void BTVCycle::ExecuteEvent( const SInputData& id, Double_t weight) throw( SError ) 
{
  // this is the most important part: here the full analysis happens
  // user should implement selections, filling of histograms and results

  // first step: call Execute event of base class to perform basic consistency checks
  // also, the good-run selection is performed there and the calculator is reset
  AnalysisCycle::ExecuteEvent( id, weight );

  // get the histogram collections. NOTE: this could be done more performant by making
  // all thse BaseHists* vairables private member variables of BTVCycle and
  // setting them in BeginInputData. Then, there is no need here to call GetHistColletion ...

  BaseHists* HistsNoCuts = GetHistCollection("NoCuts");
  BaseHists* HistsTrigger = GetHistCollection("Trigger");
  BaseHists* HistsSignal = GetHistCollection("Signal");
  BaseHists* HistsInvertedtopregularhiggs = GetHistCollection("Invertedtopregularhiggs");
  BaseHists* like500 = GetHistCollection("like500");

  static Selection* trigger = GetSelection("HLT_HT750");
  static Selection* nJets = GetSelection("nJets");
  static Selection* topTag = GetSelection("topTag");
  static Selection* topAndSubBTag = GetSelection("topAndSubBTag");
  static Selection* topAndSubBTagPlusHiggsTag = GetSelection("topAndSubBTagPlusHiggsTag");
  static Selection* HT1000 = GetSelection("HT1000");
  static Selection* invertedTopTag = GetSelection("invertedTopTag");
  static Selection* fullyInvertedHiggsTag = GetSelection("fullyInvertedHiggsTag");
  static Selection* fullyInvertedTopAndHiggsTag = GetSelection("fullyInvertedTopAndHiggsTag");
  static Selection* HTSubJets720= GetSelection("HTSubJets720");
  
  EventCalc* calc = EventCalc::Instance();
  BaseCycleContainer* bcc = calc->GetBaseCycleContainer();

  //HistsNoCuts->Fill();
  /*if(topAndSubBTagPlusHiggsTag->passSelection(bcc)){
    HistsSignal->Fill();
  }
  else{
    throw SError( SError::SkipEvent );
    }*/

  if(!trigger->passSelection(bcc)) throw SError( SError::SkipEvent );
  if(!nJets->passSelection(bcc)) throw SError( SError::SkipEvent );
  if(!topAndSubBTagPlusHiggsTag->passSelection(bcc)) throw SError( SError::SkipEvent );
  if(!HTSubJets720->passSelection(bcc)) throw SError( SError::SkipEvent );
  HistsSignal->Fill();

  //like500->Fill();
  //if(invertedTopTag->passSelection(bcc)) HistsInvertedtopregularhiggs->Fill();
  
  return;
  
}


