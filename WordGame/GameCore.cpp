#include "GameCore.h"
#include "Parameter.h"
#include <algorithm>

GameCore* GameCore::instance = nullptr;//核心只有一个

GameCore::GameCore()
{
	this->prt_GameState = false;
}
GameCore::~GameCore()
{

}

GameCore* GameCore::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new GameCore();
	}
	return instance;
}

void GameCore::GameStart()
{
	this->prt_GameState = true;
	//消息的加载
	EventController::GetInstance()->LoadingData();//加载数据
	//游戏主循环
	while (this->prt_GameState)
	{
		//逻辑的刷新
		this->LogicUpdate();
		//显示的刷新
		this->ShowUpdate();
	}
}

void GameCore::GameOver()
{//有待补充
	this->prt_GameState = false;
}

void GameCore::LogicUpdate()
{
	//获取游戏世界数据
	GameWorld* world = GameWorld::GetInstance();
	GameRole* role = world->GetGameRole();
	House* house = world->GetHouse();
	if (world->GetCurrentDay() <= world->GetMaxDay())
	{//每天会有固定的数值变化
		//天数变化
		world->SetCurrentDay(world->GetCurrentDay() + 1);
		//存款变化(若存款太少会没有利息)
		role->SetDeposit((int)(role->GetDeposit() * (1 + BANK_RATES)));
		//债务变化
		role->SetDebt((int)(role->GetDebt() * (1 + DEBT_RATES)));
		//健康值变化
		role->SetHP(role->GetHP() - house->GetComfortLevel());

		//将消息重置
		GameWorld::GetInstance()->SetCurrentMessage(nullptr);
		//触发事件(触发概率50%)
		if (RandomUtill::GetProbabilityResult(EVENT_HAPPEN_PROBABILITY))
		{//成功触发事件
			int id = RandomUtill::GetRandomInteger(1, world->GetMessages()->size());
			EventController::GetInstance()->PlayMessage(id);
		}

		//黑客攻击银行
		Bank* bank = world->GetBank();
		bank->SetAttacked(false);
		if (bank->GetHacker() == true)
		{
			if (RandomUtill::GetProbabilityResult(HACKER_ATTACK_PROBABILITY))
			{
				bank->SetAttacked(true);
			}
		}
		
		//（以下二者的刷新会很复杂，考虑封装一个方法来实现）
		// 遍历地铁站列表
		for (auto station : *world->GetStations())
		{
			//刷新黑市商品
			this->UpdateMarketList(station->GetBlackMarket());
		}
	}
	else
	{
		this->GameOver();
	}
}

void GameCore::ShowUpdate()
{
	auto world = GameWorld::GetInstance();
	if (world->GetCurrentDay() > world->GetMaxDay())
	{
		return;//天数超过，则游戏结束
	}
	Viewer::GetInstace()->StartGame();
}

void GameCore::UpdateMarketList(BlackMarket* market)
{//!!!!!此算法值得注意，黑市商品在此处生成
	//根据游戏机制，每个黑市每天会随机产生5到6个商品
	int amounts = RandomUtill::GetRandomInteger(MIN_MARKET_GOODS, MAX_MARKET_GOODS);
	//获取游戏世界里所有物品数据
	GameWorld* world = GameWorld::GetInstance();
	map<int,GameGood*> *allGoodsMap = world->GetGameGoods();
	//记录所有物品编号的集合（注意编号和下标的区别）
	vector<int> allGoodIds;
	for (auto goodPair : *allGoodsMap)//遍历map的方法
	{
		allGoodIds.push_back(goodPair.first);
	}

	/*随机一组物品，保证不重复物品(实现方法巧妙)*/
	vector<int> randomGoodIds;
	int i = 0;
	while (i < amounts)//控制黑市商品数量
	{
		//初始化商品数组的最小和最大下标
		int minIndex = 0;
		int maxIndex = allGoodIds.size() - 1;
		//随机生成物品的下标（注意不是编号）
		int randomIndex = RandomUtill::GetRandomInteger(minIndex, maxIndex);
		//将下标转化为编号，并从所有ID中挑出来放进该黑市的商品列表当中
		randomGoodIds.push_back(allGoodIds.at(randomIndex));
		//移除该编号，下标也对应的改变（所以保证了不会出现重复，值得细想）
		allGoodIds.erase(allGoodIds.begin() + randomIndex);//偏移量
		i++;
	}//循环退出后，randomGoodIds数组中拿到了一组物品的ID

	//物品随机产生价格(价格收到事件影响)
	vector<GameGood*> *marketGoodList = market->GetGoods();//获得该市场所有商品数据
	marketGoodList->clear();//清空上一天的黑市商品(细节)
	sort(randomGoodIds.begin(),randomGoodIds.end());//细节，实现按照顺序排序
	for (int goodId : randomGoodIds)//遍历上述代码拿到的一组物品
	{
		//根据编号获取物品对象（allGoods是游戏世界里所有物品的集合，不是黑市商品的集合）
		GameGood* good = allGoodsMap->at(goodId);//将随机选中的商品从所有商品中挑出来（不是新创建）
		//在范围内随机产生价格(Value)
		int randomPrice = RandomUtill::GetRandomInteger(good->GetMinPrice(),good->GetMaxPrice());

		//如果有消息,会对指定编号的物品价格产生影响
		Message* message = world->GetCurrentMessage();
		if (message != nullptr && message->GetGoodsID() == goodId)
		{
			if (message->GetPriceInc() > 0)
			{
				randomPrice *= message->GetPriceInc();
			}
			if (message->GetPriceDec() > 0)
			{
				randomPrice /= message->GetPriceDec();
			}
		}

		//重新创建一个商品实例
		GameGood* commodity = new GameGood();//（在哪里删除？）
		commodity->SetID(good->GetID());//设置商品编号
		commodity->SetName(good->GetName());
		commodity->SetCount(COMMODITY_NUM);//设定商品初始数量
		commodity->SetValue(randomPrice);//最小最大价格就不必要设置了
		//将新生成的商品放到列表中
		marketGoodList->push_back(commodity);
	}
}