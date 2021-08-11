#include "FurnitureShop.h"
#include "Parameter.h"
#include "GameWorld.h"
#include <Windows.h>
#include <iostream>
using namespace std;

FurnitureShop::FurnitureShop()
{
	//��ʼ���Ҿ�
	string furnitureNames[] = { "���ݴ�","���ִ�","�߼���Ʒ��" };
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
	case 1://���˵��ݴ�
	{
		if (role->GetCash() < this->prt_goods[choice - 1]->GetPrice())
		{
			cout << "����Ǯ������" << endl;
		}
		else
		{
			cout << "����ɹ�" << endl;
			role->SetCash(role->GetCash() - this->prt_goods[choice - 1]->GetPrice());
			house->SetComfortLevel(RICE_STRAW_BED);
		}
	}break;
	case 2://���˶��ִ�
	{
		if (role->GetCash() < this->prt_goods[choice - 1]->GetPrice())
		{
			cout << "����Ǯ������" << endl;
		}
		else
		{
			cout << "����ɹ�" << endl;
			role->SetCash(role->GetCash() - this->prt_goods[choice - 1]->GetPrice());
			house->SetComfortLevel(SECOND_HAND_BED);
		}
	}break;
	case 3://���˸߼���Ʒ��
	{
		cout << "��������������" << endl;
	}break;
	}
	Sleep(2000);
}

void FurnitureShop::SellStorage()
{
	GameRole* role = GameWorld::GetInstance()->GetGameRole();
	if (role->GetCash() < STORAGE_LEVEL_UP_PRICE)
	{
		cout << "�������˳�ȥ" << endl;
	}
	else
	{
		role->SetCash(role->GetCash() - STORAGE_LEVEL_UP_PRICE);
		role->SetMaxStore(role->GetMaxStore() + 5);
	}
	Sleep(2000);
}