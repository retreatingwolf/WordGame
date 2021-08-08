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
	this->prt_bank = GameWorld::GetInstance()->GetBank();//���ݼ���
	GameInfoView::Show();
	this->ShowBank();
}

void BankView::ShowBank()
{
	if (this->prt_bank->GetAttacked() == true)
	{
		cout << "\t\t�������б��ڿ͹�������ȡҵ��ȡ��" << endl;
		system("pause");
		Viewer::GetInstace()->StartGame();
	}
	else
	{
		GameRole* role = GameWorld::GetInstance()->GetGameRole();
		vector<string> items;
		items.push_back("��Ǯ");
		items.push_back("ȡǮ");
		items.push_back("�뿪");
		switch (Viewer::ChooseMenuItem("������������", items))
		{
		case 1://��Ǯ
		{
			switch (this->prt_bank->ReceiveDeposit())
			{
			case DEPOSIT_NOT_ENOUGH:
			{
				cout << "�����ϳ�����" << endl;
				system("pause");
			}break;
			case SUCCESSFUL_RECEIVE:
			{
				cout << "�ɹ���Ǯ" << endl;
				system("pause");
			}
			}
		}break;
		case 2://ȡǮ
		{
			switch (role->ReceiveDeposit())
			{
			case DEPOSIT_NOT_ENOUGH:
			{
				cout << "�����ϳ�����" << endl;
				system("pause");
			}break;
			case SUCCESSFUL_RECEIVE:
			{
				cout << "�ɹ�ȡǮ" << endl;
				system("pause");
			}
			}
		}break;
		case 3://�뿪
		default:
		{
			Viewer::GetInstace()->StartGame();
		}
		}
		Viewer::GetInstace()->StartGame();
	}
}