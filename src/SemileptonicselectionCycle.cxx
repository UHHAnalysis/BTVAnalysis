#include <iostream>

using namespace std;

// Local include(s):
#include "include/SemileptonicselectionHists.h"
#include "include/SemileptonicselectionCycle.h"
#include "SFrameAnalysis/include/SelectionModules.h"
#include "include/BTagEffHistsTopTag.h"

ClassImp( SemileptonicselectionCycle );

SemileptonicselectionCycle::SemileptonicselectionCycle()
    : AnalysisCycle()
{

    // constructor, declare additional variables that should be
    // obtained from the steering-xml file

    // set the integrated luminosity per bin for the lumi-yield control plots
    SetIntLumiPerBin(25.);

    DeclareProperty( "ValidationType", m_ValidationType );
    DeclareProperty( "CSVOperatingPoint", m_CSVOperatingPoint );
    DeclareProperty( "BTagEffiFilenameMC", m_BTagEffiFilenameMC);
    DeclareProperty( "BTaggingMode", m_BTaggingMode );
}

SemileptonicselectionCycle::~SemileptonicselectionCycle()
{
    // destructor
}

void SemileptonicselectionCycle::BeginCycle() throw( SError )
{
    // Start of the job, general set-up and definition of
    // objects are done here

    // Important: first call BeginCycle of base class
    AnalysisCycle::BeginCycle();

    return;

}

void SemileptonicselectionCycle::EndCycle() throw( SError )
{
    // clean-up, info messages and final calculations after the analysis


    // call the base cycle class for all standard methods
    // and a summary of the made selections
    AnalysisCycle::EndCycle();

    return;

}

void SemileptonicselectionCycle::BeginInputData( const SInputData& id ) throw( SError )
{
    // declaration of histograms and selections

    // Important: first call BeginInputData of base class
    AnalysisCycle::BeginInputData( id );

    // -------------------- set up the selections ---------------------------

    Selection* trigger = new Selection("trigger");

    trigger->addSelectionModule(new TriggerSelection("HLT_IsoMu40_eta2p1"));

    RegisterSelection(trigger);

    Selection* preselection = new Selection("preselection");

    preselection->addSelectionModule(new NPrimaryVertexSelection(1));
    preselection->addSelectionModule(new NElectronSelection(0,0));
    preselection->addSelectionModule(new NMuonSelection(1,1));
    preselection->addSelectionModule(new NJetSelection(2,int_infinity(),30.,2.5));//at least two jets with pt>30GeV and eta<2.5
    preselection->addSelectionModule(new NTopJetSelection(1,int_infinity(),150.,2.5));//at least one jet with pt>150GeV and eta<2.5
    preselection->addSelectionModule(new NAntiMuonTopJetsSelection(1,1,150.,2.5));

    RegisterSelection(preselection);

    Selection* nleptbtags = new Selection("nleptbtags");

    nleptbtags->addSelectionModule(new NMuonBTagSelection(1,int_infinity(),e_CSVM,30.,2.5)); // at least one b-topjet in the muon hemisphere with pt>30GeV and eta<2.5

    RegisterSelection(nleptbtags);

    Selection* probesele = new Selection("probesele");

    if(m_ValidationType == "toptagger"){
      
      probesele->addSelectionModule(new NAntiMuonSubBTagSelection(1,1,e_CSVM,150.,2.5)); // one b-tagged subjets of topjet in the muon anti-hemisphere with pt>150GeV and eta<2.5
      
    }

    if(m_ValidationType == "btagging"){

      probesele->addSelectionModule(new NAntiMuonHEPTopSelection(1,1,150.,2.5)); // at least one top-tagged jet in the muon anti-hemisphere with pt>150GeV and eta<2.5

    }

    Selection *subbtagantimu = new Selection ("subbtagantimu");

    std::string fileforSF;
    
    if(id.GetType()=="DATA" || id.GetType()=="Data" ||
       id.GetType()=="data"){
      fileforSF="";
    }
    else{
      fileforSF="/scratch/hh/dust/naf/cms/user/imarches/newSFrame/SemileptonicselectionReweight_forSF/SemileptonicselectionReweightCycle.MC."+id.GetVersion()+".root";
    }
    
    subbtagantimu->addSelectionModule(new NAntiMuonSubBTagSelection(1,1,e_CSVM,150.,2.5,fileforSF));

    RegisterSelection(subbtagantimu);

    RegisterSelection(probesele);

    Selection* htcut = new Selection("htcut");

    htcut->addSelectionModule(new HTlepCut(150.));
 
    RegisterSelection(htcut);

    Selection* etmiss = new Selection("etmiss");

    RegisterSelection(etmiss);

    etmiss->addSelectionModule(new METCut(20.));

    RegisterHistCollection( new SemileptonicselectionHists("nocutshists") );
    RegisterHistCollection( new SemileptonicselectionHists("triggerhists") );
    RegisterHistCollection( new SemileptonicselectionHists("preselectionhists") );
    RegisterHistCollection( new SemileptonicselectionHists("nleptbtagshists") );
    RegisterHistCollection( new SemileptonicselectionHists("probeselehists_pre") );
    RegisterHistCollection( new SemileptonicselectionHists("probeselehists") );
    RegisterHistCollection( new SemileptonicselectionHists("probeselehistswithhepweight") );
    RegisterHistCollection( new SemileptonicselectionHists("htcuthists") );
    RegisterHistCollection( new SemileptonicselectionHists("etmisshists") );

    RegisterHistCollection( new BTagEffHistsTopTag("btageffhists",atof(m_CSVOperatingPoint.c_str())) );

    bool dobtag = false;
    if(m_BTagEffiFilenameMC.size()>0)
      {
	m_BTagEffiFilenameMC += ".";
	m_BTagEffiFilenameMC += id.GetType();
	m_BTagEffiFilenameMC += ".";
	m_BTagEffiFilenameMC += id.GetVersion();
	m_BTagEffiFilenameMC += ".root";
	dobtag=true;
      }
    
    if(id.GetType()=="DATA" || id.GetType()=="Data" ||
       id.GetType()=="data") dobtag=false;
    
    m_bsf = NULL;
    
    if(dobtag)
      {
	std::cout << m_BTagEffiFilenameMC << std::endl;
	m_bsf = new
	  BTaggingRoutineTopTag(atof(m_CSVOperatingPoint.c_str()),
				m_BTaggingMode, m_BTagEffiFilenameMC);
      }

     // important: initialise histogram collections after their definition
    InitHistos();

    return;
}

void SemileptonicselectionCycle::EndInputData( const SInputData& id ) throw( SError )
{
    AnalysisCycle::EndInputData( id );

    return;
}

void SemileptonicselectionCycle::BeginInputFile( const SInputData& id ) throw( SError )
{
    // Connect all variables from the Ntuple file with the ones needed for the analysis
    // The variables are commonly stored in the BaseCycleContaincer

    // important: call to base function to connect all variables to Ntuples from the input tree
    AnalysisCycle::BeginInputFile( id );

    return;
}

void SemileptonicselectionCycle::ExecuteEvent( const SInputData& id, Double_t weight) throw( SError )
{
    // this is the most important part: here the full analysis happens
    // user should implement selections, filling of histograms and results

    // first step: call Execute event of base class to perform basic consistency checks
    // also, the good-run selection is performed there and the calculator is reset

    AnalysisCycle::ExecuteEvent( id, weight);

    Cleaner cleaner;

    static Selection* trigger = GetSelection("trigger");
    static Selection* preselection = GetSelection("preselection");
    static Selection* nleptbtags = GetSelection("nleptbtags");
    static Selection* probesele = GetSelection("probesele");
    static Selection* htcut = GetSelection("htcut");
    static Selection* etmiss = GetSelection("etmiss");
    static Selection* subbtagantimu = GetSelection("subbtagantimu");

    BaseHists* Histsnocuts = GetHistCollection("nocutshists");
    BaseHists* Histstrigger = GetHistCollection("triggerhists");
    BaseHists* Histspreselection = GetHistCollection("preselectionhists");
    BaseHists* Histsnleptbtags = GetHistCollection("nleptbtagshists");
    BaseHists* Histsprobesele_pre = GetHistCollection("probeselehists_pre");
    BaseHists* Histsprobesele = GetHistCollection("probeselehists");
    BaseHists* Histsprobeselehepweight = GetHistCollection("probeselehistswithhepweight");
    BaseHists* Histshtcut = GetHistCollection("htcuthists");
    BaseHists* Histsetmiss = GetHistCollection("etmisshists");
    BaseHists* Histsbtageff = GetHistCollection("btageffhists");
    
    EventCalc* calc = EventCalc::Instance();
    //ObjectHandler* objs = ObjectHandler::Instance();
    BaseCycleContainer* bcc = calc->GetBaseCycleContainer();
    bool IsRealData = calc->IsRealData();

    if(bcc->muons) cleaner.MuonCleaner(45,2.1);
    if(bcc->electrons) cleaner.ElectronCleaner(35,2.5);

    //As we select no hadronic decays separating only the semileptonic component from the leptonic
    if((!IsRealData) && (id.GetVersion()=="TTbarlept")){
      TTbarGen* Decay = calc->GetTTbarGen();
      if ((Decay->DecayChannel()==TTbarGen::e_ehad||Decay->DecayChannel()==TTbarGen::e_muhad||Decay->DecayChannel()==TTbarGen::e_tauhad))
	{
	  throw SError( SError::SkipEvent );
	  return;
	}
    }
    
    if((!IsRealData) && (id.GetVersion()=="TTbarsemi")){
      TTbarGen* Decay = calc->GetTTbarGen();
      if (!(Decay->DecayChannel()==TTbarGen::e_ehad||Decay->DecayChannel()==TTbarGen::e_muhad||Decay->DecayChannel()==TTbarGen::e_tauhad))
	{
	  throw SError( SError::SkipEvent );
	  return;
	}
    }
    
    Histsnocuts->Fill();

    if(trigger->passSelection())  Histstrigger->Fill();
    else throw SError( SError::SkipEvent );

    if(preselection->passSelection())  Histspreselection->Fill();
    else throw SError( SError::SkipEvent );

    if (!IsRealData)
      {
	Histsbtageff->Fill();
      }

    if(nleptbtags->passSelection()){
      //weight for standard b-tag
      if (!IsRealData)
      {
	if(m_bsf!=NULL) {
	  calc->ProduceWeight(m_bsf->GetScaleWeight());
	}
      }
      Histsnleptbtags->Fill();
    }
    else throw SError( SError::SkipEvent );

    if(probesele->passSelection()){
      Histsprobesele->Fill();
    }
    else throw SError( SError::SkipEvent );

    if(htcut->passSelection())  Histshtcut->Fill();
    else throw SError( SError::SkipEvent );

    if(etmiss->passSelection())  Histsetmiss->Fill();
    else throw SError( SError::SkipEvent );

    Histsprobeselehepweight->Fill();
    
    WriteOutputTree();
    
    return;
}

