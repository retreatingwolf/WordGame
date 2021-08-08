#include "Bank.h"
#include "GameWorld.h"
#include "GameRole.h"
#include "Parameter.h"

Bank::Bank()
{
	this->prt_Hacker = false;
	this->prt_Attacked = false;
}
Bank::~Bank()
{

}

int Bank::ReceiveDeposit()
{
	GameRole* role = GameWorld::GetInstance()->GetGameRole();
	cout << "ÇëÊäÈëÒª´æµÄÇ®:" ;
	int money;
	cin >> money;
	if (role->GetCash() < money || money <= 0)
	{
		return DEPOSIT_NOT_ENOUGH;
	}
	else
	{
		role->SetDeposit(role->GetDeposit() + money);
		role->SetCash(role->GetCash() - money);
		return SUCCESSFUL_RECEIVE;
	}
}