#include "Viewer.h"

Viewer* Viewer::instance = nullptr;

Viewer::Viewer()
{
	this->prt_mainView = nullptr;
}
Viewer::~Viewer()
{

}

Viewer* Viewer::GetInstace()
{
	if (instance == nullptr)
	{
		instance = new Viewer();
	}

	return instance;
}

void Viewer::ShowStory()
{
	//��ȡ��������
	string story[] = {
	"*************************************************",
	"*                ���и�����                 *",
	"	�ڴ���Ϸ�У���������һλǰ�������ı�������ꡣ  ",
	"����ǰ����ĸ������������2000Ԫ���ڳ����Ƿ��һ   ",
	"λ��åͷ��5500Ԫ��ծ��ÿ�����Ϣ�ߴ�10%��������ʱ  ",
	"���壬��åͷ�ӻ��ټ����ĺ����������㣬�����ܻ����� ",
	"�ڴ���·�ϡ�Ϊ�˻�ծ���������ڳ�������������Щ������ ",
	"�������������������¸��������ٵǸ������а�",
	"	��ֻ���ڳ������40�죬ÿ�α���һ��������һ�졣",
	"һ��ʼ������ķ���ֻ�ܴ��100������������������",
	"���������¼�������Ҫ��С͵����å�����֡�̰�ٵ���",
	"���Ƕ��£�����Ҫ���������ӵĻ����д��������",
	"	���������ڳ��з�������������˽�����Ĵ̼��Լ�",
	"�������ʱ�����еĸ�Ц�¼���",
	"*************************************************"
	};

	//��ӡ���(���������⴦��)
	int len = sizeof(story) / sizeof(*story);
	cout << story[0] << endl << story[1] << endl;
	for (int i = 2; i < len - 1; i++)
	{
		this->PlayTypewrite(story[i]);
	}
	SoundController::GetInstance()->StopSoundEffect(1);//ֹͣ������Ч
	cout << story[len - 1] << endl;;
}

void Viewer::PlayTypewrite(string line)
{
	//��������ٶ�
	float speed = 5;
	//�����ӡ������
	for (int i = 0; i < line.length(); i++)
	{
		cout << line[i];
		if (line[i] == ' ')
		{
			continue;
		}
		//��Ӵ�����Ч
		SoundController::GetInstance()->PlaySoundEffect(1);

		Sleep(speed);
	}
	cout << endl;
}

void Viewer::ShowMainMenu()
{
	//�˵���
	vector<string> itemNames;
	itemNames.push_back("ϵͳ");
	itemNames.push_back("����");
	itemNames.push_back("����");

	switch (this->ChooseMenuItem("��ӭ�������и����ǣ�",itemNames))
	{
	case 1://ϵͳ
	{
		this->ShowSystemMenu();
	}break;
	case 2://����
	{

	}break;
	case 3://����
	{

	}break;
	}
}

void Viewer::ShowSystemMenu()
{
	system("cls");
	//�˵���
	vector<string> itemNames;
	itemNames.push_back("����Ϸ");
	itemNames.push_back("������Ϸ");
	itemNames.push_back("���а�");
	itemNames.push_back("����");
	itemNames.push_back("����");
	itemNames.push_back("�˳���Ϸ");

	switch (this->ChooseMenuItem("ϵͳ�˵�",itemNames))
	{
	case 1://����Ϸ
	{
		system("cls");
		GameCore::GetInstance()->GameStart();
	}break;
	case 2://������Ϸ
	{

	}break;
	case 3://���а�
	{

	}break;
	case 4://��Ϸ����
	{
		system("cls");
		this->ShowSettingMenu();
	}break;
	case 5://������һ��
	{
		system("cls");
		this->ShowMainMenu();
	}break;
	case 6://�˳���Ϸ
	{
		system("cls");
		cout << "��ӭ�´�����" << endl;
	}break;
	}
}

void Viewer::ShowSettingMenu()
{
	//�˵���
	vector<string> itemNames;
	//�˴�Ҫ�ж��Ƿ����ڿ�ģʽ
	Bank* bank = GameWorld::GetInstance()->GetBank();
	bool isHacker = bank->GetHacker();
	if (isHacker)
	{
		itemNames.push_back("������ڿ͹�����������");
	}
	else
	{
		itemNames.push_back("����ڿ͹�����������");
	}
	//�˴�Ҫ�ж���Ч�Ƿ���
	SoundController* sound = SoundController::GetInstance();
	bool silence = sound->GetSilence();
	if (silence)
	{
		itemNames.push_back("��������");
	}
	else
	{
		itemNames.push_back("�����ر�");
	}
	itemNames.push_back("����");

	switch (this->ChooseMenuItem("��Ϸ����", itemNames))
	{
	case 1://����ڿ͹�����������
	{
		system("cls");
		bank->SetHacker(!bank->GetHacker());
		this->ShowSettingMenu();
	}break;
	case 2://��������
	{
		system("cls");
		sound->SoundTransform();
		this->ShowSettingMenu();
	}break;
	case 3://����
	{
		system("cls");
		this->ShowSystemMenu();//����֮ǰ�Ľ���
	}break;
	}
}

int Viewer::ChooseMenuItem(string title, vector<string> items)
{
	cout << "\t\t" <<title << endl;

	for (int i = 0; i < items.size(); i++)
	{
		cout << "\t\t" << i + 1 << "." << items[i] << endl;
	}

	//�ȴ��������ѡ��
	cout << "������ѡ��" ;
	int choice = 0;
	cin >> choice;

	return choice;
}

void Viewer::StartGame()
{
	//��ʾ��Ϸ������
	if (this->prt_mainView == nullptr)
	{
		this->prt_mainView = new GameMainView();
	}
	this->prt_mainView->Show();
}

void Viewer::EndGame()
{
	//���н����ʾ

	//���������
	if (this->prt_mainView != nullptr)
	{
		delete this->prt_mainView;
		this->prt_mainView = nullptr;
	}
}