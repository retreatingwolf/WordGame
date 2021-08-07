#pragma once
#include "GameGood.h"
#include <vector>
using namespace std;
//游戏角色数据模型
class GameRole
{
public:
	GameRole();
	virtual ~GameRole();
	int GetCash() { return this->prt_cash; }
	void SetCash(int val) { this->prt_cash = val; }
	int GetDebt() { return this->prt_debt; }
	void SetDebt(int val) { this->prt_debt = val; }
	int GetDeposit() { return this->prt_deposit; }
	void SetDeposit(int val) { this->prt_deposit = val; }
	int GetHP() { return this->prt_hp; }
	void SetHP(int val) { this->prt_hp = val; }
	int GetFame() { return this->prt_fame; }
	void SetFame(int val) { this->prt_fame = val; }
	int GetCurrentStore() { return this->prt_currentStore; }
	void SetCurrentStore(int val) { this->prt_currentStore = val; }
	int GetMaxStore() { return this->prt_maxStore; }
	void SetMaxStore(int val) { this->prt_maxStore = val; }
	//获取出租屋的物品
	vector<GameGood*>* GetStoreGood() { return &this->prt_storeGoods; }
	//游戏角色出售商品
	int Sell(GameGood* commodity, int amounts);
protected:
private:
	int prt_cash;
	int prt_debt;
	int prt_deposit;
	int prt_hp;
	int prt_fame;

	//记录玩家出租屋中的货物（在哪里设置？）
	vector<GameGood*> prt_storeGoods;
	//当前库存数量
	int prt_currentStore;
	//最大库存数量
	int prt_maxStore;
};

