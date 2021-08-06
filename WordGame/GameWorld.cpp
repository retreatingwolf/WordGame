#include "GameWorld.h"

GameWorld* GameWorld::instance = nullptr;

GameWorld::GameWorld()
{
	this->prt_CurrentDay = 0;
	this->prt_MaxDay = 40;
	this->prt_role = nullptr;

	/*��ʼ����Ϸ����*/
	string placeNames[] = { "����վ","����","�ʾ�","ҽԺ","����","�ⷿ�н�","����" };
	for (int i = 0; i < sizeof(placeNames) / sizeof(*placeNames); i++)
	{//��ѭ������ע�⣬��ѭ����ʼ������ע��
		GamePlace* place = new GamePlace(); //������������
		place->SetID(i + 1);
		place->SetName(placeNames[i]);

		this->prt_places.push_back(place);
	}

	/*��ʼ����Ϸ��Ʒ*/
	//��ʼ����Ϸ��Ʒ����
	string goodNames[] = {
		"��������              ",
		"��˽����              ",
		"������ϷVCD           ",
		"�ٰ׾ƣ��綾��         ",
		"������С������         ",
		"�������              ",
		"α�ӻ�ױƷ            ",
		"ˮ���ֻ�              "
	};
	//��ʼ����Ϸ��Ʒ�۸񲨶�����
	const int goodSize = sizeof(goodNames) / sizeof(*goodNames);
	int goodPrices[goodSize][2] = {//��¼�˶�Ӧ��Ʒ�۸�Ĳ�������
		{100,450},//��������
		{15000,30000},//��˽����
		{5,55},//������ϷVCD
		{1000,3500},//�ٰ׾ƣ��綾��
		{5000,9000},//������С������
		{250,850},//�������
		{65,245},//α�ӻ�ױƷ
		{750,1500}//ˮ���ֻ�
	};
	for (int i = 0; i < goodSize; i++)
	{
		GameGood* good = new GameGood();
		good->SetID(i + 1);
		good->SetName(goodNames[i]);
		good->SetMinPrice(goodPrices[i][0]);
		good->SetMaxPrice(goodPrices[i][1]);
		//ע���ڴ˴���û����Ʒ������(��Ʒ�����ں��в�������)
		this->prt_goods.insert(pair<int, GameGood*>(good->GetID(), good));
	}

	//��ʼ������վ����
	string stationNames[] = {
		"��ֱ��",
		"��ˮ̶",
		"��ֱ��",
		"ƻ��԰",
		"������",
		"������",
		"������",
		"������",
		"������",
		"����վ",
	};
	for (int i = 0; i < sizeof(stationNames) / sizeof(*stationNames); i++)
	{
		Station* station = new Station();
		station->SetID(i + 1);
		station->SetName(stationNames[i]);

		this->prt_stations.push_back(station);
	}

	this->prt_CurrentMessage = nullptr;
}

GameWorld::~GameWorld()
{//��������Ϸ���繲����
	if (this->prt_role != nullptr)
	{
		delete this->prt_role;
		this->prt_role = nullptr;
	}
}

int GameWorld::GetCurrentDay()
{
	return this->prt_CurrentDay;
}

void GameWorld::SetCurrentDay(int day)
{
	this->prt_CurrentDay = day;
}

int GameWorld::GetMaxDay()
{
	return this->prt_MaxDay;
}

GameWorld* GameWorld::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new GameWorld();
	}
	return instance;
}

GameRole* GameWorld::GetGameRole()
{
	if (this->prt_role == nullptr)
	{
		this->prt_role = new GameRole();
	}
	return prt_role;
}