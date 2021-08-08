#include "GameInfoView.h"

GameInfoView::GameInfoView()
{
	this->prt_CurrentDay = 0;
	this->prt_MaxDay = 0;
	this->prt_role = nullptr;
	//this->Show();调试用
}
GameInfoView::~GameInfoView()
{
	//这里不需要销毁，因为该属性并不在该类中创建
}

void GameInfoView::Show()
{
	system("cls");
	GameWorld* world = GameWorld::GetInstance();
	this->prt_CurrentDay = world->GetCurrentDay();
	this->prt_MaxDay = world->GetMaxDay();

	this->prt_role = world->GetGameRole();//类属性居然在这里初始化了
	//1.显示时间
	this->ShowDay();
	//2.显示随机事件
	this->ShowEvent();
	//3.显示角色信息
	this->ShowRoleInfo();
}

void GameInfoView::ShowDay()
{
	if (this->prt_CurrentDay == 1)
	{
		cout << "欢迎开启都市之旅" << endl;
	}
	cout << "第" << this->prt_CurrentDay << "天 " << "共" << this->prt_MaxDay << "天" << endl;
}

void GameInfoView::ShowEvent()
{
	Message* message = GameWorld::GetInstance()->GetCurrentMessage();
	if (message == nullptr)
	{
		return;
	}
	int width = 60;
	//第一行分隔符
	for (int i = 0; i < width; i++)
	{
		cout << "-";
	}
	cout << endl;
	//消息
	cout << "今日事件" << endl;
	cout << message->GetContent() << endl;
	//最后一行分隔符
	for (int i = 0; i < width; i++)
	{
		cout << "-";
	}
	cout << endl;
}

void GameInfoView::ShowRoleInfo()
{
	//GameRole* role = GameWorld::GetInstance()->GetGameRole();
	//绘制玩家信息的边框
	int width = 60;
	//第一行分隔符
	for (int i = 0; i < width; i++)
	{
		cout << "*"; 
	}
	cout << endl;
	//标题信息特殊处理
	cout << "*\t\t\t玩家信息\t\t\t   *" << endl;
	//共五个人物属性，加上标题共六行
	vector<string> infos;
	infos.push_back(this->ShowFormatForRoleProp(1, "现金", this->prt_role->GetCash(), "元"));
	infos.push_back(this->ShowFormatForRoleProp(2, "储蓄", this->prt_role->GetDeposit(), "元"));
	infos.push_back(this->ShowFormatForRoleProp(3, "欠债", this->prt_role->GetDebt(), "元"));
	infos.push_back(this->ShowFormatForRoleProp(4, "健康", this->prt_role->GetHP()));
	infos.push_back(this->ShowFormatForRoleProp(5, "名声", this->prt_role->GetFame()));

	for (string content : infos)
	{
		cout << "*";
		cout<< content;
		//右侧空格(稍微计算一下)
		for (int i = 0; i < width - content.length() - 6; i++)
		{
			cout << " ";
		}
		cout << "*" << endl;
	}
	//最后一行分隔符
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