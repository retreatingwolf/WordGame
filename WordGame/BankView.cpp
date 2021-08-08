#include "BankView.h"
#include "Viewer.h"
#include "Parameter.h"

BankView::BankView()
{
	this->prt_bank = nullptr;
}
BankView::~BankView()
{

}

void BankView::Show()
{
	system("cls");
	this->prt_bank = GameWorld::GetInstance()->GetBank();//数据加载
	GameInfoView::Show();
	this->ShowBank();
}

void BankView::ShowBank()
{
	if (this->prt_bank->GetAttacked() == true)
	{
		cout << "\t\t今日银行被黑客攻击，存取业务取消" << endl;
		system("pause");
		Viewer::GetInstace()->StartGame();
	}
	else
	{
		GameRole* role = GameWorld::GetInstance()->GetGameRole();
		vector<string> items;
		items.push_back("存钱");
		items.push_back("取钱");
		items.push_back("离开");
		switch (Viewer::ChooseMenuItem("您进入了银行", items))
		{
		case 1://存钱
		{
			switch (this->prt_bank->ReceiveDeposit())
			{
			case DEPOSIT_NOT_ENOUGH:
			{
				cout << "您被赶出银行" << endl;
				system("pause");
			}break;
			case SUCCESSFUL_RECEIVE:
			{
				cout << "成功存钱" << endl;
				system("pause");
			}
			}
		}break;
		case 2://取钱
		{
			switch (role->ReceiveDeposit())
			{
			case DEPOSIT_NOT_ENOUGH:
			{
				cout << "您被赶出银行" << endl;
				system("pause");
			}break;
			case SUCCESSFUL_RECEIVE:
			{
				cout << "成功取钱" << endl;
				system("pause");
			}
			}
		}break;
		case 3://离开
		default:
		{
			Viewer::GetInstace()->StartGame();
		}
		}
		Viewer::GetInstace()->StartGame();
	}
}