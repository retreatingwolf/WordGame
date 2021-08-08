#include "GameRole.h"
#include "Parameter.h"

GameRole::GameRole()
{
	//人物属性初始值设定
	this->prt_cash = INIT_CASH;
	this->prt_debt = INIT_DEBT;
	this->prt_deposit = INIT_DEPOSIT;
	this->prt_hp = INIT_HP;
	this->prt_fame = INIT_FAME;
	//仓库初始值设定
	this->prt_currentStore = 0;
	this->prt_maxStore = INIT_MAXSTORAGE;
}
GameRole::~GameRole()
{

}

int GameRole::Sell(GameGood* commodity, int amounts)
{
	//在仓库中查找货物是否存在
	GameGood* storeGoods = nullptr;
	for (auto storeGood : this->prt_storeGoods)
	{
		if (storeGood->GetID() == commodity->GetID())
		{
			storeGoods = storeGood;
			break;
		}
	}
	if (storeGoods == nullptr)
	{//没查到
		return COMMODITY_NOT_FOUND;
	}
	else
	{//查到了，检查货物数量是否充足
		int storeGoodsNumber = storeGoods->GetCount();
		if (storeGoodsNumber < amounts)
		{//数量不足
			return GOOD_AMOUNT_NOT_ENOUGH;
		}
		else
		{//数量同时也充足，相关数据操作
			//玩家现金增加
			this->SetCash(this->GetCash() + commodity->GetValue() * amounts);
			//玩家库存减少
			this->SetCurrentStore(this->GetCurrentStore() - amounts);
			//玩家货物减少（全部卖出则从列表移除）
			if (amounts == storeGoodsNumber)
			{
				auto itor = this->prt_storeGoods.begin();
				while (itor != this->prt_storeGoods.end())
				{
					if ( (*itor)->GetID()==commodity->GetID())
					{
						this->prt_storeGoods.erase(itor);
						break;
					}
					itor++;
				}
			}
			else
			{
				storeGoods->SetCount(storeGoods->GetCount() - amounts);
			}
			return SUCCESSFUL_SELL;
		}
	}
}

int GameRole::ReceiveDeposit()
{
	cout << "请输入要取的钱:" ;
	int money;
	cin >> money;
	if (this->GetDeposit() < money || money<=0)
	{
		return DEPOSIT_NOT_ENOUGH;
	}
	else
	{
		this->SetDeposit(this->GetDeposit()-money);
		this->SetCash(this->GetCash() + money);
		return SUCCESSFUL_RECEIVE;
	}
}