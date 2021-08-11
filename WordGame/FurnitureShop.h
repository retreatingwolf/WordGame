#pragma once
#include "FurnitureShopGood.h"
#include <vector>
using namespace std;
class FurnitureShop
{
public:
	FurnitureShop();
	virtual  ~FurnitureShop();

	//获得家具
	vector<FurnitureShopGood*>* GetFurniture() { return &this->prt_goods; }

	//出售床
	void SellBed(int choice);
	//增加储物空间
	void SellStorage();
private:
	vector<FurnitureShopGood*> prt_goods;
};

