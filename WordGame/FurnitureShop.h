#pragma once
#include "FurnitureShopGood.h"
#include <vector>
using namespace std;
class FurnitureShop
{
public:
	FurnitureShop();
	virtual  ~FurnitureShop();

	//��üҾ�
	vector<FurnitureShopGood*>* GetFurniture() { return &this->prt_goods; }

	//���۴�
	void SellBed(int choice);
	//���Ӵ���ռ�
	void SellStorage();
private:
	vector<FurnitureShopGood*> prt_goods;
};

