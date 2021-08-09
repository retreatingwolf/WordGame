#pragma once
#include "Parameter.h"
class House
{
public:
	House();
	virtual ~House();

	int GetComfortLevel() { return this->prt_comfortLevel; }
	void SetComfortLevel(int val) { this->prt_comfortLevel = val; }
protected:
private:
	int prt_comfortLevel;//舒适度，决定每天睡觉掉多少血
};

//这里暂时不把GameRole中的相关属性转移过来

