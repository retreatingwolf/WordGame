#pragma once
#include "BlackMarket.h"
#include "GameInfoView.h"
#include "Viewer.h"

#include <Windows.h>

//黑市界面显示类
class MarketView : public GameInfoView
{
public:
	//构建一个黑市界面实例
	static MarketView* Creat(BlackMarket* market);
	
	virtual ~MarketView();

	void Show() override;
protected:
	MarketView();//把构造函数放在此处的原因
private:
	//黑市实例
	BlackMarket* prt_market;
	//列表显示商品和货物列表的刷新显示
	void UpdateShowList(BlackMarket* market);
	//交易功能菜单
	void ShowMenu();
};

