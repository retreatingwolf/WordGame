#include "BlackMarket.h"
#include "GameRole.h"
#include "GameWorld.h"
BlackMarket::BlackMarket()
{
	this->prt_id = 0;
	this->prt_name = "";
}
BlackMarket::~BlackMarket()
{

}

int BlackMarket::Sell(int id, int amounts)
{
	GameGood* commodity = nullptr;
	//通过编号查找商品
	for (auto good : this->prt_goodList)
	{
		if (good->GetID() == id)
		{//查找到后进行记录
			commodity = good; 
			break;
		}
	}

	if (commodity == nullptr) //==写成了!=
	{//没有查到商品
		return 0;
	}

	//判断商品数量是否充足
	int goodAmounts = commodity->GetCount();
	if (goodAmounts < amounts)
	{//数量不足
		return 1;
	}
	else
	{//商品充足的情况下，判断现金是否充足
		GameRole* role = GameWorld::GetInstance()->GetGameRole();
		int cash = role->GetCash();
		int sellTotlePrice = amounts * commodity->GetValue();
		if (cash < sellTotlePrice)
		{//现金不足情况
			return 3;
		}
		else
		{//商品和现金数量充足的情况判断仓库容量有没有超过
			int totle = role->GetCurrentStore() + amounts;

			if (role->GetMaxStore() < totle)
			{
				return 4;
			}

			//若仓库容量足够，现金充足，商品数量充足才能进行下一步操作
			role->SetCurrentStore(totle);//记录仓库货物总数
			role->SetCash(cash - sellTotlePrice);//扣除现金
			commodity->SetCount(goodAmounts - amounts);//扣除黑市商品数量
			//创建货物放入玩家仓库
			GameGood* storeGood = nullptr;
				//查找原仓库是否存在该货物
			auto allstoreGoods = role->GetGameGood();
			for (auto store : *allstoreGoods)
			{
				if (store->GetID() == id)
				{
					storeGood = store;
					break;
				}
			}

			if (storeGood == nullptr)
			{//没有找到该物品的情况
				storeGood = new GameGood();
				storeGood->SetID(id);
				storeGood->SetBuyPrice(commodity->GetValue());
				storeGood->SetCount(amounts);
				storeGood->SetName(commodity->GetName());
				//放入玩家仓库
				allstoreGoods->push_back(storeGood);
			}
			else
			{//若找到则更改值
				//重新计算购买价格
				storeGood->SetBuyPrice((storeGood->GetBuyPrice() * storeGood->GetCount() + sellTotlePrice) / (storeGood->GetCount() + amounts));
				storeGood->SetCount(storeGood->GetCount() + amounts);
				
			}
			return 2;
		}
		
	}
}