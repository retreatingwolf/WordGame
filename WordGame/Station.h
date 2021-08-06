#pragma once
#include "BlackMarket.h"
#include <string>
using namespace std;
/*地铁站类（黑市类）*/
class Station
{
public:
	Station();
	virtual ~Station();

	int GetID() { return this->prt_id; }
	void SetID(int val) { this->prt_id = val; }
	string GetName() { return this->prt_name; }
	void SetName(string name) { this->prt_name = name; }
	//获取黑市的方法
	BlackMarket* GetBlackMarket();
protected:
private:
	int prt_id;
	string prt_name;
	//每个地铁站有一个黑市(每个黑市都有一个商品列表)
	BlackMarket* prt_market;
};

