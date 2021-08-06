#include "StationView.h"
#include "Viewer.h"
#include "MarketView.h"

StationView::StationView()
{

}
StationView::~StationView()
{

}

void StationView::Show()
{
	GameInfoView::Show();//展示地铁站信息的同时也要展示角色主信息面板
	this->ShowStationNet();
}

void StationView::ShowStationNet()
{
	vector<string> stationNames;
	auto stations = *GameWorld::GetInstance()->GetStations();//从世界中获取所有地铁站的名字
	for (auto station : stations)
	{
		stationNames.push_back(station->GetName());
	}

	int id = Viewer::ChooseMenuItem("城市地铁示意图", stationNames);//获取用户选择的地铁站编号

	//获取用户选择的车站所属的黑市并显示（对黑市重新进行了一个类的封装）
	auto marketView=MarketView::Creat(stations.at(id - 1)->GetBlackMarket());//ID转下标的小细节
	marketView->Show();
	delete marketView;//show完就删除（static的作用体现在此）
}

