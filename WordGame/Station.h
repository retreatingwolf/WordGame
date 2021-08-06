#pragma once
#include "BlackMarket.h"
#include <string>
using namespace std;
/*����վ�ࣨ�����ࣩ*/
class Station
{
public:
	Station();
	virtual ~Station();

	int GetID() { return this->prt_id; }
	void SetID(int val) { this->prt_id = val; }
	string GetName() { return this->prt_name; }
	void SetName(string name) { this->prt_name = name; }
	//��ȡ���еķ���
	BlackMarket* GetBlackMarket();
protected:
private:
	int prt_id;
	string prt_name;
	//ÿ������վ��һ������(ÿ�����ж���һ����Ʒ�б�)
	BlackMarket* prt_market;
};

