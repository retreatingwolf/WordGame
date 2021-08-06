#pragma once
#include "BlackMarket.h"
#include "GameInfoView.h"
#include "Viewer.h"

#include <Windows.h>

//���н�����ʾ��
class MarketView : public GameInfoView
{
public:
	//����һ�����н���ʵ��
	static MarketView* Creat(BlackMarket* market);
	
	virtual ~MarketView();

	void Show() override;
protected:
	MarketView();//�ѹ��캯�����ڴ˴���ԭ��
private:
	//����ʵ��
	BlackMarket* prt_market;
	//�б���ʾ��Ʒ�ͻ����б��ˢ����ʾ
	void UpdateShowList(BlackMarket* market);
	//���׹��ܲ˵�
	void ShowMenu();
};

