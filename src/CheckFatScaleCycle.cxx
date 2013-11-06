// $Id: ExampleCycle.cxx,v 1.4 2012/06/22 07:46:17 peiffer Exp $

#include <iostream>

using namespace std;

// Local include(s):
#include "include/CheckFatScaleCycle.h"
//#include "include/SelectionModules.h"
#include "include/CheckFatScaleHists.h"
//#include "include/ObjectHandler.h"
//#include "JetCorrectorParameters.h"

ClassImp( CheckFatScaleCycle );

CheckFatScaleCycle::CheckFatScaleCycle()
   : AnalysisCycle() {

  // constructor, declare additional variables that should be 
  // obtained from the steering-xml file
  
  // set the integrated luminosity per bin for the lumi-yield control plots
  SetIntLumiPerBin(25.);

  m_corrector = NULL;

}

CheckFatScaleCycle::~CheckFatScaleCycle() 
{
  // destructor
  if (m_corrector) delete m_corrector;

}

void CheckFatScaleCycle::BeginCycle() throw( SError ) 
{
  // Start of the job, general set-up and definition of 
  // objects are done here

  // Important: first call BeginCycle of base class
  AnalysisCycle::BeginCycle();

  return;

}

void CheckFatScaleCycle::EndCycle() throw( SError ) 
{
  // clean-up, info messages and final calculations after the analysis

  
  // call the base cycle class for all standard methods
  AnalysisCycle::EndCycle();

  return;

}

void CheckFatScaleCycle::BeginInputData( const SInputData& id ) throw( SError ) 
{
  // declaration of histograms and selections

  // Important: first call BeginInputData of base class
  AnalysisCycle::BeginInputData( id );

  //std::vector<JetCorrectorParameters> pars;
  
  //see https://twiki.cern.ch/twiki/bin/view/CMSPublic/WorkBookJetEnergyCorrections#GetTxtFiles how to get the txt files with jet energy corrections from the database
  //if(!addGenInfo()) {
  //pars.push_back(JetCorrectorParameters(m_JECFileLocation + "/" + m_JECDataGlobalTag + "_L1FastJet_" + m_JECJetCollection + ".txt"));
  //pars.push_back(JetCorrectorParameters(m_JECFileLocation + "/" + m_JECDataGlobalTag + "_L2Relative_" + m_JECJetCollection + ".txt"));
  //pars.push_back(JetCorrectorParameters(m_JECFileLocation + "/" + m_JECDataGlobalTag + "_L3Absolute_" + m_JECJetCollection + ".txt"));
  //pars.push_back(JetCorrectorParameters(m_JECFileLocation + "/" + m_JECDataGlobalTag + "_L2L3Residual_" + m_JECJetCollection + ".txt"));
  //} else {
  //pars.push_back(JetCorrectorParameters(m_JECFileLocation + "/" + m_JECMCGlobalTag + "_L1FastJet_" + m_JECJetCollection + ".txt"));
  //pars.push_back(JetCorrectorParameters(m_JECFileLocation + "/" + m_JECMCGlobalTag + "_L2Relative_" + m_JECJetCollection + ".txt"));
  //pars.push_back(JetCorrectorParameters(m_JECFileLocation + "/" + m_JECMCGlobalTag + "_L3Absolute_" + m_JECJetCollection + ".txt"));
  //}
  
  //m_corrector = new FactorizedJetCorrector(pars);


  // -------------------- set up the selections ---------------------------

  //Selection* TopSel = new Selection("TopSelection");
  //DO NOT use trigger selection in PROOF mode at the moment
  //TopSel->addSelectionModule(new TriggerSelection("HLT_PFJet320_v"));
  //TopSel->addSelectionModule(new NTopJetSelection(2,999,350,2.5));
  //TopSel->addSelectionModule(new NTopTagSelection(2,999));
  //RegisterSelection(TopSel);

  // ---------------- set up the histogram collections --------------------

  // histograms without any cuts
  RegisterHistCollection( new CheckFatScaleHists("NoCuts" , 0. , 10000.));
  RegisterHistCollection( new CheckFatScaleHists("pt200" , 200. , 100000.));
  RegisterHistCollection( new CheckFatScaleHists("pt300" , 300. , 100000.));
  RegisterHistCollection( new CheckFatScaleHists("pt400" , 400. , 100000.));
  // histograms after the top selection
  //RegisterHistCollection( new CheckFatScaleHists("TopSel") );

  // important: initialise histogram collections after their definition
  InitHistos();

  return;

}

void CheckFatScaleCycle::EndInputData( const SInputData& id ) throw( SError ) 
{
  AnalysisCycle::EndInputData( id );
  return;

}

void CheckFatScaleCycle::BeginInputFile( const SInputData& id ) throw( SError ) 
{
  // Connect all variables from the Ntuple file with the ones needed for the analysis
  // The variables are commonly stored in the BaseCycleContaincer

  // important: call to base function to connect all variables to Ntuples from the input tree
  AnalysisCycle::BeginInputFile( id );

  return;

}

void CheckFatScaleCycle::ExecuteEvent( const SInputData& id, Double_t weight) throw( SError ) 
{
  // this is the most important part: here the full analysis happens
  // user should implement selections, filling of histograms and results

  // first step: call Execute event of base class to perform basic consistency checks
  // also, the good-run selection is performed there and the calculator is reset
  AnalysisCycle::ExecuteEvent( id, weight);

  Cleaner cleaner;

  // get the selections
  //static Selection* TopSel = GetSelection("TopSelection");

  //ObjectHandler* objs = ObjectHandler::Instance();
  EventCalc* calc = EventCalc::Instance();
  BaseCycleContainer* bcc = calc->GetBaseCycleContainer();

  //if(bcc->topjets) cleaner.JetTopRecorrector(m_corrector,true);
  //if(bcc->prunedjets) cleaner.JetPrunedRecorrector(m_corrector,true);

  // get the histogram collections
  BaseHists* HistsNoCuts = GetHistCollection("NoCuts");
  BaseHists* Histspt200 = GetHistCollection("pt200");
  BaseHists* Histspt300 = GetHistCollection("pt300");
  BaseHists* Histspt400 = GetHistCollection("pt400");
  //BaseHists* HistsTopSel = GetHistCollection("TopSel");

  // start the analysis
  HistsNoCuts->Fill();
  Histspt200->Fill();
  Histspt300->Fill();
  Histspt400->Fill();

  //if(!TopSel->passSelection(bcc))  throw SError( SError::SkipEvent );

  //HistsTopSel->Fill();
  
  return;
  
}

