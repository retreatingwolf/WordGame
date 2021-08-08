#pragma once
#include <string>
using namespace std;
class Bank
{
public:
	Bank();
	virtual ~Bank();

	bool GetHacker() { return this->prt_Hacker; }
	void SetHacker(bool val) { this->prt_Hacker = val; }
	bool GetAttacked() { return this->prt_Attacked; }
	void SetAttacked(bool val) { this->prt_Attacked = val; }

	//银行的存钱操作
	int ReceiveDeposit();
protected:
private:
	bool prt_Hacker;
	bool prt_Attacked;
};

