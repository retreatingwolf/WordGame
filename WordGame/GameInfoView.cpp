#include "GameInfoView.h"

GameInfoView::GameInfoView()
{
	this->prt_CurrentDay = 0;
	this->prt_MaxDay = 0;
	this->prt_role = nullptr;
	//this->Show();������
}
GameInfoView::~GameInfoView()
{
	//���ﲻ��Ҫ���٣���Ϊ�����Բ����ڸ����д���
}

void GameInfoView::Show()
{
	system("cls");
	GameWorld* world = GameWorld::GetInstance();
	this->prt_CurrentDay = world->GetCurrentDay();
	this->prt_MaxDay = world->GetMaxDay();

	this->prt_role = world->GetGameRole();//�����Ծ�Ȼ�������ʼ����
	//1.��ʾʱ��
	this->ShowDay();
	//2.��ʾ����¼�
	this->ShowEvent();
	//3.��ʾ��ɫ��Ϣ
	this->ShowRoleInfo();
}

void GameInfoView::ShowDay()
{
	if (this->prt_CurrentDay == 1)
	{
		cout << "��ӭ��������֮��" << endl;
	}
	cout << "��" << this->prt_CurrentDay << "�� " << "��" << this->prt_MaxDay << "��" << endl;
}

void GameInfoView::ShowEvent()
{
	Message* message = GameWorld::GetInstance()->GetCurrentMessage();
	if (message == nullptr)
	{
		return;
	}
	int width = 60;
	//��һ�зָ���
	for (int i = 0; i < width; i++)
	{
		cout << "-";
	}
	cout << endl;
	//��Ϣ
	cout << "�����¼�" << endl;
	cout << message->GetContent() << endl;
	//���һ�зָ���
	for (int i = 0; i < width; i++)
	{
		cout << "-";
	}
	cout << endl;
}

void GameInfoView::ShowRoleInfo()
{
	//GameRole* role = GameWorld::GetInstance()->GetGameRole();
	//���������Ϣ�ı߿�
	int width = 60;
	//��һ�зָ���
	for (int i = 0; i < width; i++)
	{
		cout << "*"; 
	}
	cout << endl;
	//������Ϣ���⴦��
	cout << "*\t\t\t�����Ϣ\t\t\t   *" << endl;
	//������������ԣ����ϱ��⹲����
	vector<string> infos;
	infos.push_back(this->ShowFormatForRoleProp(1, "�ֽ�", this->prt_role->GetCash(), "Ԫ"));
	infos.push_back(this->ShowFormatForRoleProp(2, "����", this->prt_role->GetDeposit(), "Ԫ"));
	infos.push_back(this->ShowFormatForRoleProp(3, "Ƿծ", this->prt_role->GetDebt(), "Ԫ"));
	infos.push_back(this->ShowFormatForRoleProp(4, "����", this->prt_role->GetHP()));
	infos.push_back(this->ShowFormatForRoleProp(5, "����", this->prt_role->GetFame()));

	for (string content : infos)
	{
		cout << "*";
		cout<< content;
		//�Ҳ�ո�(��΢����һ��)
		for (int i = 0; i < width - content.length() - 6; i++)
		{
			cout << " ";
		}
		cout << "*" << endl;
	}
	//���һ�зָ���
	for (int i = 0; i < width; i++)
	{
		cout << "*";
	}
	cout << endl;
}

string GameInfoView::ShowFormatForRoleProp(int id, string name, int value, string unit)
{
	stringstream str;
	str <<"  " << id << "." << name << ": ";
	str << "\t" << value << unit;
	return str.str();
}