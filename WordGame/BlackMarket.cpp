#include "BlackMarket.h"
#include "GameRole.h"
#include "GameWorld.h"
#include "Parameter.h"

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
	//通过编号在自己的(黑市的)商品列表中查找商品
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
		return COMMODITY_NOT_FOUND;
	}
	else
	{//查到商品,判断商品是否充足
		int goodsNumber = commodity->GetCount();
		if (goodsNumber < amounts)
		{//数量不足
			return GOOD_AMOUNT_NOT_ENOUGH;
		}
		else
		{//商品充足的情况下，判断现金是否充足
			GameRole* role = GameWorld::GetInstance()->GetGameRole();
			int cash = role->GetCash();
			int sellTotlePrice = amounts * commodity->GetValue();
			if (cash < sellTotlePrice)
			{//现金不足情况
				return MONEY_AMOUNT_NOT_ENOUGH;
			}
			else
			{//商品和现金数量充足,判断仓库容量有没有超过
				int storeTotle = role->GetCurrentStore() + amounts;
				if (role->GetMaxStore() < storeTotle)
				{
					return STORE_AMOUNT_NOT_ENOUGH;
				}

				/*仓库容量足够，现金充足，商品数量充足,进行下一步操作*/
				role->SetCurrentStore(storeTotle);//记录仓库货物总数
				role->SetCash(cash - sellTotlePrice);//扣除现金
				commodity->SetCount(goodsNumber - amounts);//扣除黑市商品数量
					/*创建货物放入玩家仓库*/
				GameGood* storeGoods = nullptr;
						//查找原仓库是否存在该货物
				vector<GameGood*> *allstoreGoods = role->GetStoreGood();
				for (GameGood* storeGood : *allstoreGoods)
				{
					if (storeGood->GetID() == id)
					{
						storeGoods = storeGood;
						break;
					}
				}
				if (storeGoods == nullptr)
				{//原仓库没有找到该物品
					storeGoods = new GameGood();
					storeGoods->SetID(id);
					storeGoods->SetBuyPrice(commodity->GetValue());
					storeGoods->SetCount(amounts);
					storeGoods->SetName(commodity->GetName());
					//放入玩家仓库
					allstoreGoods->push_back(storeGoods);
				}
				else
				{//若找到则更改值
					//重新计算购买价格
					storeGoods->SetBuyPrice((storeGoods->GetBuyPrice() * storeGoods->GetCount() + sellTotlePrice) / (storeGoods->GetCount() + amounts));
					storeGoods->SetCount(storeGoods->GetCount() + amounts);
				}
				return SUCCESSFUL_SELL;
			}
		}
	}
}