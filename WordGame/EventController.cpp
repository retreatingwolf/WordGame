#include "EventController.h"

EventController* EventController::instance = nullptr;

EventController::EventController()
{
}
EventController::~EventController()
{
}

EventController* EventController::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new EventController();
	}
	return instance;
}

#define GAME_MESSAGE_COUNT 3

//随机消息数据结构体
typedef struct MessageType 
{
	string content;//消息内容
	int goodsId;//商品编号
	int priceInc;//商品价格增加
	int priceDec;//商品价格减少倍数
	int goodsCount;//游戏角色增加的货物数量
}Msg;

Msg messagesConfig[GAME_MESSAGE_COUNT] = {
	{"专家提议提高小学生“动手能力”，进口玩具大受欢迎",6,2,0,0},
	{"南京的老同学资助我两部走私汽车！",2,0,0,2},
	{"市场上充斥着来自福建的走私香烟！",1,0,8,0},
};

void EventController::LoadingData()
{
	auto goodsMessage = GameWorld::GetInstance()->GetMessages();
	for (int i = 0; i < GAME_MESSAGE_COUNT; i++)
	{
		Msg msg = messagesConfig[i];
		Message* message = new Message();
		message->SetID(i + 1);
		message->SetGoodsID(msg.goodsId);
		message->SetContent(msg.content);
		message->SetPriceInc(msg.priceInc);
		message->SetPriceDec(msg.priceDec);
		message->SetGoodsCount(msg.goodsCount);

		goodsMessage->insert(pair<int, Message*>(message->GetID(), message));
	}
}

void EventController::PlayMessage(int id)
{
	auto world = GameWorld::GetInstance();
	auto currMessage = world->GetMessages()->at(id);
	if (currMessage != nullptr)
	{
		world->SetCurrentMessage(currMessage);
		//修改玩家货物数量
		if (currMessage->GetGoodsCount() > 0)
		{
			int goodsId = currMessage->GetGoodsID();
			auto role = world->GetGameRole();
			auto allGoods = world->GetGameGoods();
			auto storeGoods = role->GetGameGood();
			//通过编号查找货物
			GameGood* gameGood = nullptr;
			for (auto store : *storeGoods)
			{
				if (store->GetID() == goodsId)
				{
					gameGood = store;
					break;
				}
			}

			if (gameGood == nullptr)
			{//若货物不存在，增加货物
				gameGood = new GameGood();
				gameGood->SetID(currMessage->GetGoodsID());
				gameGood->SetBuyPrice(0); 
				gameGood->SetCount(currMessage->GetGoodsCount());
				gameGood->SetName(allGoods->at(currMessage->GetGoodsID())->GetName());

				storeGoods->push_back(gameGood);
			}
			else
			{//货物存在，改变数量
				//暂时不做库存上限处理
				gameGood->SetBuyPrice((gameGood->GetBuyPrice() * gameGood->GetCount()) / (gameGood->GetCount() + currMessage->GetGoodsCount()));
				gameGood->SetCount(gameGood->GetCount() + currMessage->GetGoodsCount());
			}

			role->SetCurrentStore(role->GetCurrentStore() + currMessage->GetGoodsCount());
		}
	}
}