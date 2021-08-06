#pragma once
#include "GameInfoView.h"
#include "BlackMarket.h"
#include <sstream>
#include <iostream>
using namespace std;
class StationView : public GameInfoView
{
public:
	StationView();
	virtual ~StationView();

	void Show()override; 
protected:
private:
	//显示地铁示意图
	void ShowStationNet();
	//显示指定黑市的界面
	//void ShowMarket(BlackMarket* market);
};

