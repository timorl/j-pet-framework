/**
 *  @copyright Copyright 2016 The J-PET Framework Authors. All rights reserved.
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may find a copy of the License in the LICENCE file.
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *  @file SDARecoDrawAllOffsets.h
 *  @brief Draws charges spectra for PMT
 *  Reads a TTree of JPetRecoSignals and fills offset values from PMTs to the histo. 
 */

#ifndef _JPETANALYSISMODULE_DRAWALLOFFSETS_H_
#define _JPETANALYSISMODULE_DRAWALLOFFSETS_H_

#include "../../JPetTask/JPetTask.h"
#include "TCanvas.h"

class SDARecoDrawAllOffsets: public JPetTask
{

public:

  SDARecoDrawAllOffsets(const char* name, const char* description);
  virtual ~SDARecoDrawAllOffsets();
  virtual void exec();
  virtual void init();
  virtual void terminate();

private:
  // put any custom variables (e.g. histograms) here:
    std::vector<TH1F*> fOffsetHistos;
    std::vector<std::vector<double> > fOffsets;
    double fOffset;
    std::vector<int> fIDs;
    unsigned int fNumberOfPMTs;
    std::string fFileName;
};

#endif
