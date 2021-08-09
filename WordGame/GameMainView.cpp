#include "GameMainView.h" 
#include "Viewer.h"//此头文件只能在此处导入，避免出现循环导入的后果
#include "StationView.h"
#include "BankView.h"
#include "HouseView.h"

GameMainView::GameMainView()
{

}
GameMainView::~GameMainView()
{

}

void GameMainView::Show()
{
	GameInfoView::Show();
	//显示游戏场景选择界面
	this->ShowFuncChoice();
}

void GameMainView::ShowFuncChoice()
{
	GameWorld* world = GameWorld::GetInstance();//单例模式的便捷之处！任何地方都可以取值（取得整个世界）
	//获取功能项名称
	vector<string> items;
	for (auto place : *world->GetGamePlaces())
	{
		items.push_back(place->GetName());//获取场景名字（从另外一个类中获取）
	}

	//对item进行补充
	/*items.push_back("开始新的一天");*/
	items.push_back("结束游戏");

	switch (Viewer::ChooseMenuItem("城市地面示意图", items))
	{
	case 1://地铁站
	{
		StationView* stationView = new StationView();
		stationView->Show();
		delete stationView;
	}return;
	case 2://银行
	{
		BankView* bankView = new BankView();
		bankView->Show();
		delete bankView;
	}break;
	case 3://邮局
	{

	}break;
	case 4://医院
	{

	}break;
	case 5://机场
	{

	}break;
	case 6://家具城
	{

	}break;
	case 7://网吧
	{

	}break;
	case 8://出租屋
	{
		HouseView* houseView = new HouseView();
		houseView->Show();
		delete houseView;
	}break;
	case 9://结束游戏
	default://乱选也退出游戏
	{
		cout << "是否保存游戏进度？" << endl;
		//提供一个保存接口
		exit(0);
	}
	}
}