#pragma once
/*商品类，用于描述商品本身具有的属性，在别的类中具有实例*/
#include <string>
using namespace std;
class GameGood
{
public:
	GameGood();
	virtual ~GameGood();
	
	int GetID() { return this->prt_id; }
	void SetID(int val) { this->prt_id = val; }
	string GetName() { return this->prt_name; }
	void SetName(string name) { this->prt_name = name; }
	int GetValue() { return this->prt_value; }
	void SetValue(int val) { this->prt_value = val; }
	int GetBuyPrice() { return this->prt_buyPrice; }
	void SetBuyPrice(int val) { this->prt_buyPrice = val; }
	int GetMinPrice() { return this->prt_minPrice; }
	void SetMinPrice(int val) { this->prt_minPrice = val; }
	int GetMaxPrice() { return this->prt_maxPrice; }
	void SetMaxPrice(int val) { this->prt_maxPrice = val; }
	int GetCount() { return this->prt_count; }
	void SetCount(int val) { this->prt_count = val; }

protected:
private:
	int prt_id;
	string prt_name;
	int prt_value; //售价
	int prt_buyPrice;//购买时价格
	int prt_minPrice;
	int prt_maxPrice;
	int prt_count;
};

