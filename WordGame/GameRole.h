#pragma once
#include "GameGood.h"
#include <vector>
using namespace std;
//��Ϸ��ɫ����ģ��
class GameRole
{
public:
	GameRole();
	virtual ~GameRole();
	int GetCash() { return this->prt_cash; }
	void SetCash(int val) { this->prt_cash = val; }
	int GetDebt() { return this->prt_debt; }
	void SetDebt(int val) { this->prt_debt = val; }
	int GetDeposit() { return this->prt_deposit; }
	void SetDeposit(int val) { this->prt_deposit = val; }
	int GetHP() { return this->prt_hp; }
	void SetHP(int val) { this->prt_hp = val; }
	int GetFame() { return this->prt_fame; }
	void SetFame(int val) { this->prt_fame = val; }
	int GetCurrentStore() { return this->prt_currentStore; }
	void SetCurrentStore(int val) { this->prt_currentStore = val; }
	int GetMaxStore() { return this->prt_maxStore; }
	void SetMaxStore(int val) { this->prt_maxStore = val; }
	//��ȡ�����ݵ���Ʒ
	vector<GameGood*>* GetStoreGood() { return &this->prt_storeGoods; }
	//��Ϸ��ɫ������Ʒ
	int Sell(GameGood* commodity, int amounts);
protected:
private:
	int prt_cash;
	int prt_debt;
	int prt_deposit;
	int prt_hp;
	int prt_fame;

	//��¼��ҳ������еĻ�����������ã���
	vector<GameGood*> prt_storeGoods;
	//��ǰ�������
	int prt_currentStore;
	//���������
	int prt_maxStore;
};

