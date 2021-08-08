#include "GameRole.h"
#include "Parameter.h"

GameRole::GameRole()
{
	//�������Գ�ʼֵ�趨
	this->prt_cash = INIT_CASH;
	this->prt_debt = INIT_DEBT;
	this->prt_deposit = INIT_DEPOSIT;
	this->prt_hp = INIT_HP;
	this->prt_fame = INIT_FAME;
	//�ֿ��ʼֵ�趨
	this->prt_currentStore = 0;
	this->prt_maxStore = INIT_MAXSTORAGE;
}
GameRole::~GameRole()
{

}

int GameRole::Sell(GameGood* commodity, int amounts)
{
	//�ڲֿ��в��һ����Ƿ����
	GameGood* storeGoods = nullptr;
	for (auto storeGood : this->prt_storeGoods)
	{
		if (storeGood->GetID() == commodity->GetID())
		{
			storeGoods = storeGood;
			break;
		}
	}
	if (storeGoods == nullptr)
	{//û�鵽
		return COMMODITY_NOT_FOUND;
	}
	else
	{//�鵽�ˣ������������Ƿ����
		int storeGoodsNumber = storeGoods->GetCount();
		if (storeGoodsNumber < amounts)
		{//��������
			return GOOD_AMOUNT_NOT_ENOUGH;
		}
		else
		{//����ͬʱҲ���㣬������ݲ���
			//����ֽ�����
			this->SetCash(this->GetCash() + commodity->GetValue() * amounts);
			//��ҿ�����
			this->SetCurrentStore(this->GetCurrentStore() - amounts);
			//��һ�����٣�ȫ����������б��Ƴ���
			if (amounts == storeGoodsNumber)
			{
				auto itor = this->prt_storeGoods.begin();
				while (itor != this->prt_storeGoods.end())
				{
					if ( (*itor)->GetID()==commodity->GetID())
					{
						this->prt_storeGoods.erase(itor);
						break;
					}
					itor++;
				}
			}
			else
			{
				storeGoods->SetCount(storeGoods->GetCount() - amounts);
			}
			return SUCCESSFUL_SELL;
		}
	}
}

int GameRole::ReceiveDeposit()
{
	cout << "������Ҫȡ��Ǯ:" ;
	int money;
	cin >> money;
	if (this->GetDeposit() < money || money<=0)
	{
		return DEPOSIT_NOT_ENOUGH;
	}
	else
	{
		this->SetDeposit(this->GetDeposit()-money);
		this->SetCash(this->GetCash() + money);
		return SUCCESSFUL_RECEIVE;
	}
}