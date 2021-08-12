#include "HospitalView.h"
#include "Viewer.h"
#include "RandomUtill.h"

HospitalView::HospitalView()
{
	this->prt_hospital = nullptr;
}
HospitalView::~HospitalView()
{

}

void HospitalView::Show()
{
	system("cls");
	this->prt_hospital = GameWorld::GetInstance()->GetHospital();
	GameInfoView::Show();
	this->ShowHospital();
}

void HospitalView::ShowHospital()
{
	vector<string> items;
	items.push_back("�β�");
	items.push_back("�߳�ҽԺ");
	cout << endl << "ҽԺ����д�ţ���ͯ�����ۡ�"<<endl;
	Sleep(1000);
	switch (Viewer::ChooseMenuItem("��������ҽԺ", items))
	{
	case 1:
	{
		this->ShowTreat();
	}break;
	case 2:
	default:
		Viewer::GetInstace()->StartGame();
		break;
	}
}

void HospitalView::ShowTreat()
{
	GameRole* role = GameWorld::GetInstance()->GetGameRole();
	int treat = RandomUtill::GetRandomInteger(HOSPITAL_TREAT_MIN, HOSPITAL_TREAT_MAX);

	cout << endl;
	cout << "��������" << this->prt_hospital->GetTreatPrice() << "��" << "�Ի�����15��HP�ָ�" << endl;
	if (role->GetHP() >= 90)
	{
		cout << "����������ɫ����" << endl;
	}
	else if (role->GetHP() < 90 && role->GetHP() >= 40)
	{
		cout << "��������Ҫ��һ��" << endl;
	}
	else
	{
		cout << "���������˵ú���" << endl;
	}

	cout << "�Ƿ����ƣ�(y/n)" << endl;
	int money = role->GetCash();
	char choice;
	cin >> choice;
	switch (choice)
	{
	case 'y':
	{
		if (money < HOSPITAL_TREAT_PRICE)
		{
			role->SetDebt(role->GetDebt() + (HOSPITAL_TREAT_PRICE - role->GetCash()));
			role->SetCash(0);
			cout << "�����Ĳ���ҽԺ�ϰ���ʱ���㣬�ǵû�" << endl;
			role->SetHP(role->GetHP()+treat);
		}
		else
		{
			role->SetCash(role->GetCash() - HOSPITAL_TREAT_PRICE);
			role->SetHP(role->GetHP() + treat);
		}
		if (role->GetHP() > 100)
		{//����ֵ���100
			role->SetHP(100);
		}
	}break;
	case 'n':
	default:
		return;
	}
	Sleep(2000);
}