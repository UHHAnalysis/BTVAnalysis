#ifndef BTagEffHistsTopTagJim_H
#define BTagEffHistsTopTagJim_H

// ROOT include(s):
#include <TObject.h>
#include <TString.h>

// Local include(s):
#include "SFrameTools/include/BaseHists.h"
#include "SFrameTools/include/Utils.h"
/**
 *   Class for booking and filling btag histograms
 *
 *   
 *   @version $Revision: 1.1 $
 */

class BTagEffHistsTopTagJim : public BaseHists {

public:
   /// Named constructor
  BTagEffHistsTopTagJim(const char*,float csv = 0.679);

   /// Default destructor
   ~BTagEffHistsTopTagJim();

   void Init();

   void Fill();

   void Finish();
   

private:

  E_BtagType m_type;
  float m_CSVOperatingPoint;

}; // class BTagEffHistsTopTagJim

#endif // BTagEffHistsTopTagJim_H

