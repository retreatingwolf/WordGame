#pragma once
#include "Parameter.h"

class Hospital
{
public:
	Hospital();
	virtual ~Hospital();

	int GetTreatPrice() { return this->prt_treatPrice; }
	void SetTreatPrice(int val) { this->prt_treatPrice = val; }
protected:
private:
	int prt_treatPrice;
};

