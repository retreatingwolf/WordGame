#pragma once
#include "Hospital.h"
#include "GameInfoView.h"
class HospitalView : public GameInfoView
{
public:
	HospitalView();
	virtual ~HospitalView();
	void Show() override;
	void ShowHospital();
	void ShowTreat();
protected:
private:
	Hospital* prt_hospital;
};

