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
	items.push_back("治病");
	items.push_back("走出医院");
	cout << endl << "医院门外写着：“童叟无欺”"<<endl;
	Sleep(1000);
	switch (Viewer::ChooseMenuItem("您进入了医院", items))
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
	cout << "您将花费" << this->prt_hospital->GetTreatPrice() << "￥" << "以获得最多15点HP恢复" << endl;
	if (role->GetHP() >= 90)
	{
		cout << "您看起来气色不错" << endl;
	}
	else if (role->GetHP() < 90 && role->GetHP() >= 40)
	{
		cout << "您可能需要补一补" << endl;
	}
	else
	{
		cout << "您看起来伤得很重" << endl;
	}

	cout << "是否治疗？(y/n)" << endl;
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
			cout << "不够的部分医院老板暂时借你，记得还" << endl;
			role->SetHP(role->GetHP()+treat);
		}
		else
		{
			role->SetCash(role->GetCash() - HOSPITAL_TREAT_PRICE);
			role->SetHP(role->GetHP() + treat);
		}
		if (role->GetHP() > 100)
		{//健康值最大100
			role->SetHP(100);
		}
	}break;
	case 'n':
	default:
		return;
	}
	Sleep(2000);
}