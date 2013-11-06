// Dear emacs, this is -*- c++ -*-
#ifndef SemileptonicselectionCycle_H
#define SemileptonicselectionCycle_H

#include "SFrameAnalysis/include/AnalysisCycle.h"
#include "SFrameAnalysis/include/Cleaner.h"
#include "include/BTaggingRoutineTopTag.h"

/**
 *  @short Selection cycle to perform 
 *         pre-selection for Z'->ttbar analysis
 *  @author Thomas Peiffer
 */


class SemileptonicselectionCycle : public AnalysisCycle {

public:
  /// Default constructor
  SemileptonicselectionCycle();
  /// Default destructor
  ~SemileptonicselectionCycle();

  /// Function called at the beginning of the cycle
  void BeginCycle() throw( SError );
  /// Function called at the end of the cycle
  void EndCycle() throw( SError );

  /// Function called at the beginning of a new input data
  void BeginInputData( const SInputData& ) throw( SError );
  /// Function called after finishing to process an input data
  void EndInputData  ( const SInputData& ) throw( SError );

  /// Function called after opening each new input file
  void BeginInputFile( const SInputData& ) throw( SError );

  /// Function called for every event
  void ExecuteEvent( const SInputData&, Double_t ) throw( SError );

private:
  //
  // Put all your private variables here
  //
  
  std::string m_ValidationType;
  std::string m_CSVOperatingPoint;
  std::string m_BTagEffiFilenameMC;
  std::string m_BTaggingMode;
  BTaggingRoutineTopTag * m_bsf;

  // Macro adding the functions for dictionary generation
  ClassDef( SemileptonicselectionCycle, 0 );

}; // class SemileptonicselectionCycle

#endif // SemileptonicselectionCycle_H

