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

//�����Ϣ���ݽṹ��
typedef struct MessageType 
{
	string content;//��Ϣ����
	int goodsId;//��Ʒ���
	int priceInc;//��Ʒ�۸�����
	int priceDec;//��Ʒ�۸���ٱ���
	int goodsCount;//��Ϸ��ɫ���ӵĻ�������
}Msg;

Msg messagesConfig[GAME_MESSAGE_COUNT] = {
	{"ר���������Сѧ����������������������ߴ��ܻ�ӭ",6,2,0,0},
	{"�Ͼ�����ͬѧ������������˽������",2,0,0,2},
	{"�г��ϳ�������Ը�������˽���̣�",1,0,8,0},
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
		//�޸���һ�������
		if (currMessage->GetGoodsCount() > 0)
		{
			int goodsId = currMessage->GetGoodsID();
			auto role = world->GetGameRole();
			auto allGoods = world->GetGameGoods();
			auto storeGoods = role->GetGameGood();
			//ͨ����Ų��һ���
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
			{//�����ﲻ���ڣ����ӻ���
				gameGood = new GameGood();
				gameGood->SetID(currMessage->GetGoodsID());
				gameGood->SetBuyPrice(0); 
				gameGood->SetCount(currMessage->GetGoodsCount());
				gameGood->SetName(allGoods->at(currMessage->GetGoodsID())->GetName());

				storeGoods->push_back(gameGood);
			}
			else
			{//������ڣ��ı�����
				//��ʱ����������޴���
				gameGood->SetBuyPrice((gameGood->GetBuyPrice() * gameGood->GetCount()) / (gameGood->GetCount() + currMessage->GetGoodsCount()));
				gameGood->SetCount(gameGood->GetCount() + currMessage->GetGoodsCount());
			}

			role->SetCurrentStore(role->GetCurrentStore() + currMessage->GetGoodsCount());
		}
	}
}