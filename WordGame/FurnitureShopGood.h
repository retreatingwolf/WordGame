#pragma once
//家具城商品类
#include <string>
using namespace std;

class FurnitureShopGood
{
public:
	FurnitureShopGood();
	virtual ~FurnitureShopGood();

	string GetName() { return this->prt_name; }
	void SetName(string val) { this->prt_name = val; }
	int GetPrice() { return this->prt_price; }
	void SetPrice(int val) { this->prt_price = val; }
private:
	string prt_name;
	int prt_price;
};

