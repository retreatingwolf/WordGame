#include "HouseView.h"
#include "Viewer.h"
HouseView::HouseView()
{
	this->prt_house = nullptr;
	this->prt_role = nullptr;
}
HouseView::~HouseView()
{

}

void HouseView::Show()
{
	system("cls");
	this->prt_role = GameWorld::GetInstance()->GetGameRole();
	this->prt_house = GameWorld::GetInstance()->GetHouse();
	GameInfoView::Show();
	this->ShowHouse();
}

void HouseView::ShowHouse()
{
	vector<string> items;
	items.push_back("�鿴�ֿ�");
	items.push_back("���Ŵ���");
	items.push_back("�ϴ�˯��");

	string title;//��ͬ���ʶȴ�����ͬ�����Լ�˯�߾���
	switch (this->prt_house->GetComfortLevel())
	{
	case NO_BED:title = "�������˼ң����ſյ����ķ��䣬��̾һ����"; break;
	case RICE_STRAW_BED:title = "�������˼ң��������˵ĵ��ݴ�����̾һ����"; break;
	case SECOND_HAND_BED:title = "�������˼ң������ƾɵ�ľ�崲����̾һ����"; break;
	}

	switch (Viewer::ChooseMenuItem(title, items))
	{
	case 1://�鿴�ֿ�
	{
		system("cls");
		GameInfoView::Show();
		this->ShowStore();
		system("pause");
		this->Show(); //�˴��ݹ�����ˣ���ô�����
		return;
	}break;
	case 2://���Ŵ���
	{
		break;
	}
	case 3://�ϴ�˯��
	default:
	{
		switch (this->prt_house->GetComfortLevel())
		{
		case NO_BED:title = "���ڵذ��ϴպ���һҹ"; break;
		case RICE_STRAW_BED:title = "���ݲ������ʣ�����������һ�Ŵ�"; break;
		case SECOND_HAND_BED:title = "������������ʱ��֨��֨��"; break;
		}
		cout << title << endl;
		Sleep(2000);
		return;
	}
	}
	Viewer::GetInstace()->StartGame();
}

void HouseView::ShowStore()
{
	int width = 62;
	//���ӵ�л�����ʾ���������б���ʾ��
	GameRole* role = GameWorld::GetInstance()->GetGameRole();
	cout << endl << "���Ĳֿ�(��棺" << role->GetCurrentStore() << "/" << role->GetMaxStore() << ")" << endl;
	int number = role->GetStoreGood()->size();
	if (number == 0)
	{//���û����Ʒ�����
		cout << "����һ��" << endl;
	}
	else
	{
		for (auto good : *role->GetStoreGood())
		{
			//ƴ�ӻ�����Ϣ
			stringstream str;
			//����Ϊ�Ҷ������
			int spaceSize = 6 - str.str().length();
			str.str("");
			int counter = 0;
			while (counter < spaceSize)
			{
				str << " ";
				counter++;
			}
			str << good->GetBuyPrice();
			cout << good->GetID() << "." << good->GetName() << " ���ۣ�" << str.str() << "Ԫ    ������" << good->GetCount() << endl;
		}
	}
	//����·ָ���
	for (int i = 0; i < width; i++)
	{
		cout << "*";
	}
	cout << endl;
}//�˶δ�����������Σ����Կ��Ƿ�װһ��