#include "BlackMarket.h"
#include "GameRole.h"
#include "GameWorld.h"
BlackMarket::BlackMarket()
{
	this->prt_id = 0;
	this->prt_name = "";
}
BlackMarket::~BlackMarket()
{

}

int BlackMarket::Sell(int id, int amounts)
{
	GameGood* commodity = nullptr;
	//ͨ����Ų�����Ʒ
	for (auto good : this->prt_goodList)
	{
		if (good->GetID() == id)
		{//���ҵ�����м�¼
			commodity = good; 
			break;
		}
	}

	if (commodity == nullptr) //==д����!=
	{//û�в鵽��Ʒ
		return 0;
	}

	//�ж���Ʒ�����Ƿ����
	int goodAmounts = commodity->GetCount();
	if (goodAmounts < amounts)
	{//��������
		return 1;
	}
	else
	{//��Ʒ���������£��ж��ֽ��Ƿ����
		GameRole* role = GameWorld::GetInstance()->GetGameRole();
		int cash = role->GetCash();
		int sellTotlePrice = amounts * commodity->GetValue();
		if (cash < sellTotlePrice)
		{//�ֽ������
			return 3;
		}
		else
		{//��Ʒ���ֽ��������������жϲֿ�������û�г���
			int totle = role->GetCurrentStore() + amounts;

			if (role->GetMaxStore() < totle)
			{
				return 4;
			}

			//���ֿ������㹻���ֽ���㣬��Ʒ����������ܽ�����һ������
			role->SetCurrentStore(totle);//��¼�ֿ��������
			role->SetCash(cash - sellTotlePrice);//�۳��ֽ�
			commodity->SetCount(goodAmounts - amounts);//�۳�������Ʒ����
			//�������������Ҳֿ�
			GameGood* storeGood = nullptr;
				//����ԭ�ֿ��Ƿ���ڸû���
			auto allstoreGoods = role->GetGameGood();
			for (auto store : *allstoreGoods)
			{
				if (store->GetID() == id)
				{
					storeGood = store;
					break;
				}
			}

			if (storeGood == nullptr)
			{//û���ҵ�����Ʒ�����
				storeGood = new GameGood();
				storeGood->SetID(id);
				storeGood->SetBuyPrice(commodity->GetValue());
				storeGood->SetCount(amounts);
				storeGood->SetName(commodity->GetName());
				//������Ҳֿ�
				allstoreGoods->push_back(storeGood);
			}
			else
			{//���ҵ������ֵ
				//���¼��㹺��۸�
				storeGood->SetBuyPrice((storeGood->GetBuyPrice() * storeGood->GetCount() + sellTotlePrice) / (storeGood->GetCount() + amounts));
				storeGood->SetCount(storeGood->GetCount() + amounts);
				
			}
			return 2;
		}
		
	}
}