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
	//��ʾ����ʾ��ͼ
	void ShowStationNet();
	//��ʾָ�����еĽ���
	//void ShowMarket(BlackMarket* market);
};

