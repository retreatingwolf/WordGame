#include "Station.h"
Station::Station()
{
	this->prt_id = 0;
	this->prt_name = "";
	this->prt_market = nullptr;
}
Station::~Station()
{//黑市和火车站共存亡
	if (this->prt_market != nullptr)
	{
		delete this->prt_market;
		this->prt_market = nullptr;
	}
}

BlackMarket* Station::GetBlackMarket()
{//类似于单例设计模式的定义
	if (this->prt_market == nullptr)
	{//认为黑市的id和名称与所处地铁站相同
		this->prt_market = new BlackMarket();
		this->prt_market->SetID(this->prt_id);
		this->prt_market->SetName(this->prt_name);
	}
	return this->prt_market;
}
//地铁站和黑市共存亡，此处代码体现对生命周期的管理
//有地铁站不一定有黑市数据，有黑市数据一定有地铁站