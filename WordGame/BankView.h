#pragma once
#include "GameInfoView.h"
#include "Bank.h"
#include "RandomUtill.h"
class BankView : public GameInfoView
{
public:
	BankView();
	virtual ~BankView();

	void Show() override;
	//�������
	//Bank* GetBank() { return this->prt_bank; }
protected:
private:
	//��ʾ���н���
	void ShowBank();
	
	Bank* prt_bank;
};

