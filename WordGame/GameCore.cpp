#include "GameCore.h"
#include "Parameter.h"
#include <algorithm>

GameCore* GameCore::instance = nullptr;//����ֻ��һ��

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
	//��Ϣ�ļ���
	EventController::GetInstance()->LoadingData();//��������
	//��Ϸ��ѭ��
	while (this->prt_GameState)
	{
		//�߼���ˢ��
		this->LogicUpdate();
		//��ʾ��ˢ��
		this->ShowUpdate();
	}
}

void GameCore::GameOver()
{//�д�����
	this->prt_GameState = false;
}

void GameCore::LogicUpdate()
{
	//��ȡ��Ϸ��������
	GameWorld* world = GameWorld::GetInstance();
	GameRole* role = world->GetGameRole();
	House* house = world->GetHouse();
	if (world->GetCurrentDay() <= world->GetMaxDay())
	{//ÿ����й̶�����ֵ�仯
		//�����仯
		world->SetCurrentDay(world->GetCurrentDay() + 1);
		//���仯(�����̫�ٻ�û����Ϣ)
		role->SetDeposit((int)(role->GetDeposit() * (1 + BANK_RATES)));
		//ծ��仯
		role->SetDebt((int)(role->GetDebt() * (1 + DEBT_RATES)));
		//����ֵ�仯
		role->SetHP(role->GetHP() - house->GetComfortLevel());

		//����Ϣ����
		GameWorld::GetInstance()->SetCurrentMessage(nullptr);
		//�����¼�(��������50%)
		if (RandomUtill::GetProbabilityResult(EVENT_HAPPEN_PROBABILITY))
		{//�ɹ������¼�
			int id = RandomUtill::GetRandomInteger(1, world->GetMessages()->size());
			EventController::GetInstance()->PlayMessage(id);
		}

		//�ڿ͹�������
		Bank* bank = world->GetBank();
		bank->SetAttacked(false);
		if (bank->GetHacker() == true)
		{
			if (RandomUtill::GetProbabilityResult(HACKER_ATTACK_PROBABILITY))
			{
				bank->SetAttacked(true);
			}
		}
		
		//�����¶��ߵ�ˢ�»�ܸ��ӣ����Ƿ�װһ��������ʵ�֣�
		// ��������վ�б�
		for (auto station : *world->GetStations())
		{
			//ˢ�º�����Ʒ
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
		return;//��������������Ϸ����
	}
	Viewer::GetInstace()->StartGame();
}

void GameCore::UpdateMarketList(BlackMarket* market)
{//!!!!!���㷨ֵ��ע�⣬������Ʒ�ڴ˴�����
	//������Ϸ���ƣ�ÿ������ÿ����������5��6����Ʒ
	int amounts = RandomUtill::GetRandomInteger(MIN_MARKET_GOODS, MAX_MARKET_GOODS);
	//��ȡ��Ϸ������������Ʒ����
	GameWorld* world = GameWorld::GetInstance();
	map<int,GameGood*> *allGoodsMap = world->GetGameGoods();
	//��¼������Ʒ��ŵļ��ϣ�ע���ź��±������
	vector<int> allGoodIds;
	for (auto goodPair : *allGoodsMap)//����map�ķ���
	{
		allGoodIds.push_back(goodPair.first);
	}

	/*���һ����Ʒ����֤���ظ���Ʒ(ʵ�ַ�������)*/
	vector<int> randomGoodIds;
	int i = 0;
	while (i < amounts)//���ƺ�����Ʒ����
	{
		//��ʼ����Ʒ�������С������±�
		int minIndex = 0;
		int maxIndex = allGoodIds.size() - 1;
		//���������Ʒ���±꣨ע�ⲻ�Ǳ�ţ�
		int randomIndex = RandomUtill::GetRandomInteger(minIndex, maxIndex);
		//���±�ת��Ϊ��ţ���������ID���������Ž��ú��е���Ʒ�б���
		randomGoodIds.push_back(allGoodIds.at(randomIndex));
		//�Ƴ��ñ�ţ��±�Ҳ��Ӧ�ĸı䣨���Ա�֤�˲�������ظ���ֵ��ϸ�룩
		allGoodIds.erase(allGoodIds.begin() + randomIndex);//ƫ����
		i++;
	}//ѭ���˳���randomGoodIds�������õ���һ����Ʒ��ID

	//��Ʒ��������۸�(�۸��յ��¼�Ӱ��)
	vector<GameGood*> *marketGoodList = market->GetGoods();//��ø��г�������Ʒ����
	marketGoodList->clear();//�����һ��ĺ�����Ʒ(ϸ��)
	sort(randomGoodIds.begin(),randomGoodIds.end());//ϸ�ڣ�ʵ�ְ���˳������
	for (int goodId : randomGoodIds)//�������������õ���һ����Ʒ
	{
		//���ݱ�Ż�ȡ��Ʒ����allGoods����Ϸ������������Ʒ�ļ��ϣ����Ǻ�����Ʒ�ļ��ϣ�
		GameGood* good = allGoodsMap->at(goodId);//�����ѡ�е���Ʒ��������Ʒ���������������´�����
		//�ڷ�Χ����������۸�(Value)
		int randomPrice = RandomUtill::GetRandomInteger(good->GetMinPrice(),good->GetMaxPrice());

		//�������Ϣ,���ָ����ŵ���Ʒ�۸����Ӱ��
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

		//���´���һ����Ʒʵ��
		GameGood* commodity = new GameGood();//��������ɾ������
		commodity->SetID(good->GetID());//������Ʒ���
		commodity->SetName(good->GetName());
		commodity->SetCount(COMMODITY_NUM);//�趨��Ʒ��ʼ����
		commodity->SetValue(randomPrice);//��С���۸�Ͳ���Ҫ������
		//�������ɵ���Ʒ�ŵ��б���
		marketGoodList->push_back(commodity);
	}
}