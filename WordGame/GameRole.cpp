#include "GameRole.h"

GameRole::GameRole()
{
	//人物属性初始值设定
	this->prt_cash = 2000;
	this->prt_debt = 5500;
	this->prt_deposit = 0;
	this->prt_hp = 100; 
	this->prt_fame = 100;
	//仓库初始值设定
	this->prt_currentStore = 0;
	this->prt_maxStore = 100;
}
GameRole::~GameRole()
{

}

int GameRole::Sell(GameGood* commodity, int amounts)
{
	//货物是否存在
	GameGood* storeGoods = nullptr;
	for (auto storeGood : this->prt_goods)
	{
		if (storeGood->GetID() == commodity->GetID())
		{
			storeGoods = storeGood;
			break;
		}
	}
	if (storeGoods == nullptr)
	{//没查到
		return 0;
	}
	else
	{//货物数量是否充足
		int number = storeGoods->GetCount();
		if (number < amounts)
		{//数量不足
			return 1;
		}
		else
		{//数据操作
			//玩家现金增加
			this->SetCash(this->GetCash() + commodity->GetValue() * amounts);
			//玩家库存减少
			this->SetCurrentStore(this->GetCurrentStore() - amounts);
			//玩家货物减少（全部卖出则从列表移除）
			if (amounts == number)
			{
				auto itor = this->prt_goods.begin();
				while (itor != this->prt_goods.end())
				{
					if ( (*itor)->GetID()==commodity->GetID())
					{
						this->prt_goods.erase(itor);
						break;
					}
					itor++;
				}
			}
			else
			{
				storeGoods->SetCount(storeGoods->GetCount() - amounts);
			}
			return 2;
		}
	}
	
	
}