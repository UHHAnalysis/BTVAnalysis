// Dear emacs, this is -*- c++ -*-
// $Id: CheckFatScaleCycle.h,v 1.1 2012/06/05 14:45:24 rkogler Exp $
#ifndef CheckFatScaleCycle_H
#define CheckFatScaleCycle_H

// SFrame include(s):
#include "SFrameAnalysis/include/AnalysisCycle.h"
//#include "FactorizedJetCorrector.h"
#include "SFrameAnalysis/include/Cleaner.h"
/**
 *   @short Example of an analysis cycle
 *
 *          This is an example of an analysis cycle. It can be used
 *          as a template for writing your own analysis. Also should
 *          be used for quick cross checks of the system setup.
 *
 *  @author Roman Kogler
 *  @version $Revision: 1.1 $
 */

class CheckFatScaleCycle : public AnalysisCycle {

public:
  /// Default constructor
  CheckFatScaleCycle();
  /// Default destructor
  ~CheckFatScaleCycle();

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

  FactorizedJetCorrector* m_corrector;


  // Macro adding the functions for dictionary generation
  ClassDef( CheckFatScaleCycle, 0 );

}; // class CheckFatScaleCycle

#endif // CheckFatScaleCycle_H

