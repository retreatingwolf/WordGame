#pragma once
#include "GameInfoView.h"
#include "FurnitureShop.h"

class FurnitureShopView :public GameInfoView
{
public:
	FurnitureShopView();
	virtual  ~FurnitureShopView();

	void Show() override;
private:
	void ShowShop();
	void ShowSellBed();
	void ShowSellStorage();

	FurnitureShop* prt_furnitureShop;
};

