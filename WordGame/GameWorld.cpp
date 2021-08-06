#include "GameWorld.h"

GameWorld* GameWorld::instance = nullptr;

GameWorld::GameWorld()
{
	this->prt_CurrentDay = 0;
	this->prt_MaxDay = 40;
	this->prt_role = nullptr;

	/*初始化游戏场景*/
	string placeNames[] = { "地铁站","银行","邮局","医院","机场","租房中介","网吧" };
	for (int i = 0; i < sizeof(placeNames) / sizeof(*placeNames); i++)
	{//此循环条件注意，此循环初始化方法注意
		GamePlace* place = new GamePlace(); //在哪里析构？
		place->SetID(i + 1);
		place->SetName(placeNames[i]);

		this->prt_places.push_back(place);
	}

	/*初始化游戏物品*/
	//初始化游戏物品名称
	string goodNames[] = {
		"进口香烟              ",
		"走私汽车              ",
		"盗版游戏VCD           ",
		"假白酒（剧毒）         ",
		"《都市小宝贝》         ",
		"进口玩具              ",
		"伪劣化妆品            ",
		"水货手机              "
	};
	//初始化游戏物品价格波动区间
	const int goodSize = sizeof(goodNames) / sizeof(*goodNames);
	int goodPrices[goodSize][2] = {//记录了对应物品价格的波动区间
		{100,450},//进口香烟
		{15000,30000},//走私汽车
		{5,55},//盗版游戏VCD
		{1000,3500},//假白酒（剧毒）
		{5000,9000},//《都市小宝贝》
		{250,850},//进口玩具
		{65,245},//伪劣化妆品
		{750,1500}//水货手机
	};
	for (int i = 0; i < goodSize; i++)
	{
		GameGood* good = new GameGood();
		good->SetID(i + 1);
		good->SetName(goodNames[i]);
		good->SetMinPrice(goodPrices[i][0]);
		good->SetMaxPrice(goodPrices[i][1]);
		//注意在此处是没有商品数量的(商品数量在黑市才有体现)
		this->prt_goods.insert(pair<int, GameGood*>(good->GetID(), good));
	}

	//初始化地铁站名称
	string stationNames[] = {
		"西直门",
		"积水潭",
		"东直门",
		"苹果园",
		"公主坟",
		"复兴门",
		"建国门",
		"长椿街",
		"崇文门",
		"北京站",
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
{//人物与游戏世界共存亡
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