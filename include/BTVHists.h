#ifndef BTVHists_H
#define BTVHists_H

#include "SFrameTools/include/BaseHists.h"

/**
 *   BTV class for booking and filling histograms
 *
 *   This class books and fills a collection of histograms.
 *   It should have a unique name, such that the histograms
 *   of multiple instances of this class are ordered in the
 *   output file. 
 *   Always sort your histograms and used methods topically.
 *   This example collection can be used for data and reconstructed
 *   MC events.
 *   
 *   @version $Revision: 1.2 $
 */

class BTVHists : public BaseHists {

public:
   /// Named constructor
  BTVHists(const char* name,TString mode="default", TString filename="");

   /// Default destructor
   ~BTVHists();

   void Init();

   void Fill();

   void Finish();

private:

   std::string m_BTagEffiFilenameMC;
   std::string m_BTaggingMode;

}; // class BTVHists


#endif // BTVHists_H
