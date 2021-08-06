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
	//获取故事内容
	string story[] = {
	"*************************************************",
	"*                都市浮生记                 *",
	"	在此游戏中，您将扮演一位前往大城市谋生的青年。  ",
	"临走前，父母往你手里塞了2000元。在城里，您欠了一   ",
	"位流氓头子5500元，债务每天的利息高达10%，若不及时  ",
	"还清，流氓头子会召集他的狐朋狗友来扁你，您可能会牺牲 ",
	"在大马路上。为了还债，您决定在城市最阴暗的那些黑市里 ",
	"倒卖各种物资来发财致富，甚至荣登富人排行榜。",
	"	您只能在城市里待40天，每次奔走一个黑市算一天。",
	"一开始，您租的房子只能存放100个东西。您会在市区",
	"遭遇各种事件，您需要与小偷、流氓、凶手、贪官等人",
	"斗智斗勇，还需要在市区恶劣的环境中存活下来。",
	"	您将体验在城市贩卖盗版光碟和走私汽车的刺激以及",
	"我们这个时代才有的搞笑事件。",
	"*************************************************"
	};

	//打印输出(个别行特殊处理)
	int len = sizeof(story) / sizeof(*story);
	cout << story[0] << endl << story[1] << endl;
	for (int i = 2; i < len - 1; i++)
	{
		this->PlayTypewrite(story[i]);
	}
	SoundController::GetInstance()->StopSoundEffect(1);//停止播放音效
	cout << story[len - 1] << endl;;
}

void Viewer::PlayTypewrite(string line)
{
	//定义打字速度
	float speed = 5;
	//逐个打印出文字
	for (int i = 0; i < line.length(); i++)
	{
		cout << line[i];
		if (line[i] == ' ')
		{
			continue;
		}
		//添加打字音效
		SoundController::GetInstance()->PlaySoundEffect(1);

		Sleep(speed);
	}
	
	cout << endl;
}

void Viewer::ShowSystemMenu()
{
	//菜单项
	vector<string> itemNames;
	itemNames.push_back("系统");
	itemNames.push_back("场景");
	itemNames.push_back("帮助");

	switch (this->ChooseMenuItem("欢迎来到都市浮生记！",itemNames))
	{
	case 1://系统菜单
	{
		this->ShowSystemMenuItem();
	}break;
	case 2://场景
	{

	}break;
	case 3://帮助
	{

	}break;
	}
}

void Viewer::ShowSystemMenuItem()
{
	system("cls");
	//菜单项
	vector<string> itemNames;
	itemNames.push_back("新游戏");
	itemNames.push_back("高手排行榜");
	itemNames.push_back("游戏设置");
	itemNames.push_back("退出游戏");

	switch (this->ChooseMenuItem("系统菜单",itemNames))
	{
	case 1://新游戏
	{
		system("cls");
		GameCore::GetInstance()->GameStart();
	}break;
	case 2://高手排行榜
	{

	}break;
	case 3://游戏设置
	{
		system("cls");
		this->ShowSettingMenu();
	}break;
	case 4://退出游戏
	{
		system("cls");
		cout << "欢迎下次游玩" << endl;
		exit(0);
	}break;
	}
}

void Viewer::ShowSettingMenu()
{
	//菜单项
	vector<string> itemNames;
	itemNames.push_back("允许黑客攻击银行网络");
	//此处要判断音效是否开启
	auto sound = SoundController::GetInstance();
	bool silence = sound->GetSilence();
	if (silence)
	{
		itemNames.push_back("声音开启");
	}
	else
	{
		itemNames.push_back("声音关闭");
	}
	itemNames.push_back("返回");

	switch (this->ChooseMenuItem("游戏设置", itemNames))
	{
	case 1://允许黑客攻击银行网络
	{
		
	}break;
	case 2://声音设置
	{
		system("cls");
		sound->SetSilence(!silence);//此处是先改变状态再播放
		if (silence)
		{
			sound->PlayBGM();
			//sound->PlaySoundEffect(1);
		}
		else
		{
			sound->StopAll();
		}
		this->ShowSettingMenu();
	}break;
	case 3://返回
	{
		system("cls");
		this->ShowSystemMenuItem();//调用之前的界面
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

	//等待玩家输入选择
	cout << "请作出选择：" ;
	int choice = 0;
	cin >> choice;

	return choice;
}

void Viewer::StartGame()
{
	//显示游戏主界面
	if (this->prt_mainView == nullptr)
	{
		this->prt_mainView = new GameMainView();
	}
	//system("cls");
	this->prt_mainView->Show();
}

void Viewer::EndGame()
{
	//运行结局显示

	//销毁主面板
	if (this->prt_mainView != nullptr)
	{
		delete this->prt_mainView;
		this->prt_mainView = nullptr;
	}
}