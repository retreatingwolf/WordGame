#include "FurnitureShop.h"
#include "Parameter.h"
#include "GameWorld.h"
#include <Windows.h>
#include <iostream>
using namespace std;

FurnitureShop::FurnitureShop()
{
	//初始化家具
	string furnitureNames[] = { "稻草床","二手床","高级精品床" };
	int furniturePrices[] = { RICE_STRAW_BED_PRICE ,SECON_DHAND_BED_PRICE ,HIGH_LEVEL_BED_PRICE };
	for (int i = 0; i < sizeof(furnitureNames) / sizeof(*furnitureNames); i++)
	{
		FurnitureShopGood* furniture = new FurnitureShopGood();
		furniture->SetName(furnitureNames[i]);
		furniture->SetPrice(furniturePrices[i]);
		this->prt_goods.push_back(furniture);
	}
}
FurnitureShop::~FurnitureShop()
{

}

void FurnitureShop::SellBed(int choice)
{
	GameRole* role = GameWorld::GetInstance()->GetGameRole();
	House* house = GameWorld::GetInstance()->GetHouse();
	switch (choice)
	{
	case 1://买了稻草床
	{
		if (role->GetCash() < this->prt_goods[choice - 1]->GetPrice())
		{
			cout << "您的钱不够！" << endl;
		}
		else
		{
			cout << "购买成功" << endl;
			role->SetCash(role->GetCash() - this->prt_goods[choice - 1]->GetPrice());
			house->SetComfortLevel(RICE_STRAW_BED);
		}
	}break;
	case 2://买了二手床
	{
		if (role->GetCash() < this->prt_goods[choice - 1]->GetPrice())
		{
			cout << "您的钱不够！" << endl;
		}
		else
		{
			cout << "购买成功" << endl;
			role->SetCash(role->GetCash() - this->prt_goods[choice - 1]->GetPrice());
			house->SetComfortLevel(SECOND_HAND_BED);
		}
	}break;
	case 3://买了高级精品床
	{
		cout << "别做梦了你买不起" << endl;
	}break;
	}
	Sleep(2000);
}

void FurnitureShop::SellStorage()
{
	GameRole* role = GameWorld::GetInstance()->GetGameRole();
	if (role->GetCash() < STORAGE_LEVEL_UP_PRICE)
	{
		cout << "您被赶了出去" << endl;
	}
	else
	{
		role->SetCash(role->GetCash() - STORAGE_LEVEL_UP_PRICE);
		role->SetMaxStore(role->GetMaxStore() + 5);
	}
	Sleep(2000);
}