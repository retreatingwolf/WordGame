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
	//获得银行
	//Bank* GetBank() { return this->prt_bank; }
protected:
private:
	//显示银行界面
	void ShowBank();
	
	Bank* prt_bank;
};

