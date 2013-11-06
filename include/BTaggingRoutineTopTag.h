#ifndef BTaggingRoutineTopTag_H
#define BTaggingRoutineTopTag_H

#include "TF1.h"

#include "SFrameTools/include/Utils.h"
#include "SFrameAnalysis/include/AnalysisCycle.h"

/**
 *  @module to apply data-MC scale factors for b tagging
 *
 *
 */
class BTaggingRoutineTopTag {
public:
    /**
     * constructor
     *
     */
    BTaggingRoutineTopTag(
		    float csvcut, TString mode, TString filename
    );
    ///Default destructor
    ~BTaggingRoutineTopTag() {};

    ///return the weighted correction factor
    double GetScaleWeight();

private:

    float m_csvcut;
    TString m_mode;
    TString m_filename;
                 
};

#endif
