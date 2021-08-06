#include "Station.h"
Station::Station()
{
	this->prt_id = 0;
	this->prt_name = "";
	this->prt_market = nullptr;
}
Station::~Station()
{//���кͻ�վ������
	if (this->prt_market != nullptr)
	{
		delete this->prt_market;
		this->prt_market = nullptr;
	}
}

BlackMarket* Station::GetBlackMarket()
{//�����ڵ������ģʽ�Ķ���
	if (this->prt_market == nullptr)
	{//��Ϊ���е�id����������������վ��ͬ
		this->prt_market = new BlackMarket();
		this->prt_market->SetID(this->prt_id);
		this->prt_market->SetName(this->prt_name);
	}
	return this->prt_market;
}
//����վ�ͺ��й��������˴��������ֶ��������ڵĹ���
//�е���վ��һ���к������ݣ��к�������һ���е���վ