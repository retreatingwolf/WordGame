#pragma once
#include <string>
#include <vector>
#include "GameGood.h"
#include <iostream>
using namespace std;
class BlackMarket
{
public:
	BlackMarket();
	virtual ~BlackMarket();

	int GetID() { return this->prt_id; }
	void SetID(int val) { this->prt_id = val; }
	string GetName() { return this->prt_name; }
	void SetName(string name) { this->prt_name = name; }

	//获取商品列表
	vector<GameGood*>* GetGoods() { return &this->prt_goodList; }
	//黑市商品出售
	int Sell(int id, int amount);

protected:
private:
	int prt_id;
	string prt_name;
	//商品列表
	vector<GameGood*> prt_goodList;//在何处赋值？
};

