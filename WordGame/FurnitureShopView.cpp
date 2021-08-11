#include "FurnitureShopView.h"
#include "Viewer.h"
#include "Parameter.h"
#include <sstream>


FurnitureShopView::FurnitureShopView()
{
	this->prt_furnitureShop = nullptr;
}
FurnitureShopView::~FurnitureShopView()
{

}

void FurnitureShopView::Show()
{
	system("cls");
	this->prt_furnitureShop = GameWorld::GetInstance()->GetFurnitureShop();
	GameInfoView::Show();
	this->ShowShop();
}

void FurnitureShopView::ShowShop()
{
	cout << "您进入了家具城" << endl;
	vector<string> items;
	items.push_back("买床");
	items.push_back("买储物柜");
	items.push_back("离开");

	switch (Viewer::ChooseMenuItem("家具城", items))
	{
	case 1://买床
	{
		this->ShowSellBed();
	}break;
	case 2://买储物柜
	{
		this->ShowSellStorage();
	}break;
	case 3://离开
	default:
		//Viewer::GetInstace()->StartGame();
		break;
	}
	Viewer::GetInstace()->StartGame();
}

void FurnitureShopView::ShowSellBed()
{
	GameRole* role = GameWorld::GetInstance()->GetGameRole();
	vector<FurnitureShopGood*>* furnitures = this->prt_furnitureShop->GetFurniture();
	vector<string> items;
	stringstream str;

	for (FurnitureShopGood* furniture : *furnitures)
	{
		str.str("");//stringstream的清空不用clear
		str << furniture->GetName();
		str << "\t" << furniture->GetPrice()<<"￥";
		items.push_back(str.str());
	}
	items.push_back("返回");

	switch (Viewer::ChooseMenuItem("客官需要些啥？", items))
	{
	case 1://稻草床
	{
		this->prt_furnitureShop->SellBed(1);
	}break;
	case 2://二手床
	{
		this->prt_furnitureShop->SellBed(2);
	}break;
	case 3://高级精品床
	{
		this->prt_furnitureShop->SellBed(3);
	}break;
	case 4://返回
	default:
		break;
	}
	//多层菜单返回时总是会用到递归
	this->Show();
}
void FurnitureShopView::ShowSellStorage()
{
	GameRole* role = GameWorld::GetInstance()->GetGameRole();
	vector<string> items;
	stringstream str;
	str << "储物能力+5 现有";
	str << role->GetMaxStore()<<"\t"<< STORAGE_LEVEL_UP_PRICE <<"￥";
	items.push_back(str.str());
	items.push_back("返回");
	switch (Viewer::ChooseMenuItem("",items))
	{
	case 1://仓库储物能力+5
	{
		this->prt_furnitureShop->SellStorage();
	}
	case 2://返回
	default:
		break;
	}
	this->Show();
}