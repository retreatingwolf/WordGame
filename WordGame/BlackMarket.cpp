#include "BlackMarket.h"
#include "GameRole.h"
#include "GameWorld.h"
#include "Parameter.h"

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
	//ͨ��������Լ���(���е�)��Ʒ�б��в�����Ʒ
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
		return COMMODITY_NOT_FOUND;
	}
	else
	{//�鵽��Ʒ,�ж���Ʒ�Ƿ����
		int goodsNumber = commodity->GetCount();
		if (goodsNumber < amounts)
		{//��������
			return GOOD_AMOUNT_NOT_ENOUGH;
		}
		else
		{//��Ʒ���������£��ж��ֽ��Ƿ����
			GameRole* role = GameWorld::GetInstance()->GetGameRole();
			int cash = role->GetCash();
			int sellTotlePrice = amounts * commodity->GetValue();
			if (cash < sellTotlePrice)
			{//�ֽ������
				return MONEY_AMOUNT_NOT_ENOUGH;
			}
			else
			{//��Ʒ���ֽ���������,�жϲֿ�������û�г���
				int storeTotle = role->GetCurrentStore() + amounts;
				if (role->GetMaxStore() < storeTotle)
				{
					return STORE_AMOUNT_NOT_ENOUGH;
				}

				/*�ֿ������㹻���ֽ���㣬��Ʒ��������,������һ������*/
				role->SetCurrentStore(storeTotle);//��¼�ֿ��������
				role->SetCash(cash - sellTotlePrice);//�۳��ֽ�
				commodity->SetCount(goodsNumber - amounts);//�۳�������Ʒ����
					/*�������������Ҳֿ�*/
				GameGood* storeGoods = nullptr;
						//����ԭ�ֿ��Ƿ���ڸû���
				vector<GameGood*> *allstoreGoods = role->GetStoreGood();
				for (GameGood* storeGood : *allstoreGoods)
				{
					if (storeGood->GetID() == id)
					{
						storeGoods = storeGood;
						break;
					}
				}
				if (storeGoods == nullptr)
				{//ԭ�ֿ�û���ҵ�����Ʒ
					storeGoods = new GameGood();
					storeGoods->SetID(id);
					storeGoods->SetBuyPrice(commodity->GetValue());
					storeGoods->SetCount(amounts);
					storeGoods->SetName(commodity->GetName());
					//������Ҳֿ�
					allstoreGoods->push_back(storeGoods);
				}
				else
				{//���ҵ������ֵ
					//���¼��㹺��۸�
					storeGoods->SetBuyPrice((storeGoods->GetBuyPrice() * storeGoods->GetCount() + sellTotlePrice) / (storeGoods->GetCount() + amounts));
					storeGoods->SetCount(storeGoods->GetCount() + amounts);
				}
				return SUCCESSFUL_SELL;
			}
		}
	}
}