#pragma once
#include <string>
#include <vector>
#include "GameGood.h"
#include <iostream>
using namespace std;
class BlackMarket
{
public:
	BlackMarket();
	virtual ~BlackMarket();

	int GetID() { return this->prt_id; }
	void SetID(int val) { this->prt_id = val; }
	string GetName() { return this->prt_name; }
	void SetName(string name) { this->prt_name = name; }

	//��ȡ��Ʒ�б�
	vector<GameGood*>* GetGoods() { return &this->prt_goodList; }
	//������Ʒ����
	int Sell(int id, int amount);

protected:
private:
	int prt_id;
	string prt_name;
	//��Ʒ�б�
	vector<GameGood*> prt_goodList;//�ںδ���ֵ��
};

