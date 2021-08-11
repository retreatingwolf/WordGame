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
	cout << "�������˼Ҿ߳�" << endl;
	vector<string> items;
	items.push_back("��");
	items.push_back("�����");
	items.push_back("�뿪");

	switch (Viewer::ChooseMenuItem("�Ҿ߳�", items))
	{
	case 1://��
	{
		this->ShowSellBed();
	}break;
	case 2://�����
	{
		this->ShowSellStorage();
	}break;
	case 3://�뿪
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
		str.str("");//stringstream����ղ���clear
		str << furniture->GetName();
		str << "\t" << furniture->GetPrice()<<"��";
		items.push_back(str.str());
	}
	items.push_back("����");

	switch (Viewer::ChooseMenuItem("�͹���ҪЩɶ��", items))
	{
	case 1://���ݴ�
	{
		this->prt_furnitureShop->SellBed(1);
	}break;
	case 2://���ִ�
	{
		this->prt_furnitureShop->SellBed(2);
	}break;
	case 3://�߼���Ʒ��
	{
		this->prt_furnitureShop->SellBed(3);
	}break;
	case 4://����
	default:
		break;
	}
	//���˵�����ʱ���ǻ��õ��ݹ�
	this->Show();
}
void FurnitureShopView::ShowSellStorage()
{
	GameRole* role = GameWorld::GetInstance()->GetGameRole();
	vector<string> items;
	stringstream str;
	str << "��������+5 ����";
	str << role->GetMaxStore()<<"\t"<< STORAGE_LEVEL_UP_PRICE <<"��";
	items.push_back(str.str());
	items.push_back("����");
	switch (Viewer::ChooseMenuItem("",items))
	{
	case 1://�ֿⴢ������+5
	{
		this->prt_furnitureShop->SellStorage();
	}
	case 2://����
	default:
		break;
	}
	this->Show();
}