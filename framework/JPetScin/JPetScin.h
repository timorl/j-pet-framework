// JPetScin.h - Scintillator
#ifndef _JPETSCIN_H_
#define _JPETSCIN_H_

#include "TNamed.h"
#include <TRef.h>
#include "../JPetUser/JPetUser.h"
#include "../JPetPM/JPetPM.h"
//#include "../JPetParamManager/JPetParamManager.h"


class JPetScin: public TNamed
{
protected:
  enum Dimension {kLength, kHeight, kWidth};
  
  struct ScinDimensions
  {
    float fLength;
    float fHeight;
    float fWidth;
    
    ScinDimensions(float p_length, float p_height, float p_width) : fLength(p_length), fHeight(p_height), fWidth(p_width)
    {}
  };
  
  struct ScinType
  {
    int fId;
    std::string fName;
    std::string fDescription;
    
    ScinType(int p_id, std::string p_name, std::string p_description) : fId(p_id), fName(p_name), fDescription(p_description)
    {}
  };
  
  struct ScinCalibration
  {
    int fId;
    std::string fName;
    float fAttlength;
    
    ScinCalibration(int p_id, std::string p_name, float p_attlength) : fId(p_id), fName(p_name), fAttlength(p_attlength)
    {}
  };

public:
  JPetScin(void);
  JPetScin(int p_id,
	   bool p_isActive,
	   std::string p_status, 
	   float p_length, 
	   float p_height, 
	   float p_width, 
	   std::string p_description,
	   int p_typeId, 
	   std::string p_typeName, 
	   std::string p_typeDescription,
	   int p_calibrationId, 
	   std::string p_calibrationName, 
	   float p_calibrationAttlength,
	   const JPetUser &p_user);
  ~JPetScin(void);
  
  int getId() const { return fId; }
  bool getIsActive() const { return fIsActive; }
  std::string getStatus() const { return fStatus; }
  ScinDimensions getScinDimensions() const { return fScinDimensions; }
  std::string getDescription() const { return fDescription; }
  float getScinDimension(const JPetScin::Dimension &p_dimension) const;
  void setScinDimension(const JPetScin::Dimension &p_dimension, const float p_value);
  ScinType getScinType() const { return fScinType; }
  ScinCalibration getScinCalibration() const { return fScinCalibration; }
  JPetUser getUser() const { return fUser; }
  
  std::pair<TRef, TRef> getTRefPMs() const { return fTRefPMs; }
  void setTRefPMs(JPetPM &p_leftPM, JPetPM &p_rightPM)
  {
    fTRefPMs.first = &p_leftPM;
    fTRefPMs.second = &p_rightPM;
  }
  void setLeftTRefPM(JPetPM &p_PM)
  {
    fTRefPMs.first = &p_PM;
  }
  void setRightTRefPM(JPetPM &p_PM)
  {
    fTRefPMs.second = &p_PM;
  }

  friend class JPetParamManager;
  
protected:
  int fId;
  bool fIsActive;
  std::string fStatus;
  ScinDimensions fScinDimensions;
  std::string fDescription;
  ScinType fScinType;
  ScinCalibration fScinCalibration;
  JPetUser fUser;
  
  std::pair<TRef, TRef> fTRefPMs;
  
  void clearTRefPMs()
  {
    fTRefPMs.first = NULL;
    fTRefPMs.second = NULL;
  }
  
  ClassDef(JPetScin, 1);
};

#endif	// _JPETSCIN_H_
