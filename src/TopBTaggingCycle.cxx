// $Id: ExampleCycle.cxx,v 1.4 2012/06/22 07:46:17 peiffer Exp $

#include <iostream>

using namespace std;

// Local include(s):
#include "include/TopBTaggingCycle.h"
//#include "include/SelectionModules.h"
#include "include/TopBTaggingHists.h"
//#include "include/ObjectHandler.h"
//#include "JetCorrectorParameters.h"

ClassImp( TopBTaggingCycle );

TopBTaggingCycle::TopBTaggingCycle()
   : AnalysisCycle() {

  // constructor, declare additional variables that should be 
  // obtained from the steering-xml file
  
  // set the integrated luminosity per bin for the lumi-yield control plots
  SetIntLumiPerBin(25.);

  m_corrector = NULL;

}

TopBTaggingCycle::~TopBTaggingCycle() 
{
  // destructor
  if (m_corrector) delete m_corrector;

}

void TopBTaggingCycle::BeginCycle() throw( SError ) 
{
  // Start of the job, general set-up and definition of 
  // objects are done here

  // Important: first call BeginCycle of base class
  AnalysisCycle::BeginCycle();

  return;

}

void TopBTaggingCycle::EndCycle() throw( SError ) 
{
  // clean-up, info messages and final calculations after the analysis

  
  // call the base cycle class for all standard methods
  AnalysisCycle::EndCycle();

  return;

}

void TopBTaggingCycle::BeginInputData( const SInputData& id ) throw( SError ) 
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
  RegisterHistCollection( new TopBTaggingHists("NoCuts" , 0. , 1000.));
  RegisterHistCollection( new TopBTaggingHists("pt0_200" , 0. , 200.));
  RegisterHistCollection( new TopBTaggingHists("pt200_400" , 200. , 400.));
  RegisterHistCollection( new TopBTaggingHists("pt400_600" , 400. , 600.));
  RegisterHistCollection( new TopBTaggingHists("pt600_800" , 600. , 800.));
  RegisterHistCollection( new TopBTaggingHists("pt800_1000" , 800. , 1000.));
  // histograms after the top selection
  //RegisterHistCollection( new TopBTaggingHists("TopSel") );

  // important: initialise histogram collections after their definition
  InitHistos();

  return;

}

void TopBTaggingCycle::EndInputData( const SInputData& id ) throw( SError ) 
{
  AnalysisCycle::EndInputData( id );
  return;

}

void TopBTaggingCycle::BeginInputFile( const SInputData& id ) throw( SError ) 
{
  // Connect all variables from the Ntuple file with the ones needed for the analysis
  // The variables are commonly stored in the BaseCycleContaincer

  // important: call to base function to connect all variables to Ntuples from the input tree
  AnalysisCycle::BeginInputFile( id );

  return;

}

void TopBTaggingCycle::ExecuteEvent( const SInputData& id, Double_t weight) throw( SError ) 
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
  BaseHists* Histspt0_200 = GetHistCollection("pt0_200");
  BaseHists* Histspt200_400 = GetHistCollection("pt200_400");
  BaseHists* Histspt400_600 = GetHistCollection("pt400_600");
  BaseHists* Histspt600_800 = GetHistCollection("pt600_800");
  BaseHists* Histspt800_1000 = GetHistCollection("pt800_1000");

  //BaseHists* HistsTopSel = GetHistCollection("TopSel");

  // start the analysis
  HistsNoCuts->Fill();
  //Histspt0_200->Fill();
  //Histspt200_400->Fill();
  //Histspt400_600->Fill();
  //Histspt600_800->Fill();
  //Histspt800_1000->Fill();
  
  //if(!TopSel->passSelection(bcc))  throw SError( SError::SkipEvent );

  //HistsTopSel->Fill();
  
  return;
  
}

