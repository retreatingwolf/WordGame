#include "GameRole.h"

GameRole::GameRole()
{
	//�������Գ�ʼֵ�趨
	this->prt_cash = 2000;
	this->prt_debt = 5500;
	this->prt_deposit = 0;
	this->prt_hp = 100; 
	this->prt_fame = 100;
	//�ֿ��ʼֵ�趨
	this->prt_currentStore = 0;
	this->prt_maxStore = 100;
}
GameRole::~GameRole()
{

}

int GameRole::Sell(GameGood* commodity, int amounts)
{
	//�����Ƿ����
	GameGood* storeGoods = nullptr;
	for (auto storeGood : this->prt_goods)
	{
		if (storeGood->GetID() == commodity->GetID())
		{
			storeGoods = storeGood;
			break;
		}
	}
	if (storeGoods == nullptr)
	{//û�鵽
		return 0;
	}
	else
	{//���������Ƿ����
		int number = storeGoods->GetCount();
		if (number < amounts)
		{//��������
			return 1;
		}
		else
		{//���ݲ���
			//����ֽ�����
			this->SetCash(this->GetCash() + commodity->GetValue() * amounts);
			//��ҿ�����
			this->SetCurrentStore(this->GetCurrentStore() - amounts);
			//��һ�����٣�ȫ����������б��Ƴ���
			if (amounts == number)
			{
				auto itor = this->prt_goods.begin();
				while (itor != this->prt_goods.end())
				{
					if ( (*itor)->GetID()==commodity->GetID())
					{
						this->prt_goods.erase(itor);
						break;
					}
					itor++;
				}
			}
			else
			{
				storeGoods->SetCount(storeGoods->GetCount() - amounts);
			}
			return 2;
		}
	}
	
	
}