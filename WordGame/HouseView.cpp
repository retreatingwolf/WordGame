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
	items.push_back("查看仓库");
	items.push_back("出门闯荡");
	items.push_back("上床睡觉");

	string title;//不同舒适度触发不同标题以及睡眠剧情
	switch (this->prt_house->GetComfortLevel())
	{
	case NO_BED:title = "您进入了家，看着空荡荡的房间，长叹一口气"; break;
	case RICE_STRAW_BED:title = "您进入了家，看着扎人的稻草床，长叹一口气"; break;
	case SECOND_HAND_BED:title = "您进入了家，看着破旧的木板床，长叹一口气"; break;
	}

	switch (Viewer::ChooseMenuItem(title, items))
	{
	case 1://查看仓库
	{
		system("cls");
		GameInfoView::Show();
		this->ShowStore();
		system("pause");
		this->Show(); //此处递归调用了，怎么解决？
		return;
	}break;
	case 2://出门闯荡
	{
		break;
	}
	case 3://上床睡觉
	default:
	{
		switch (this->prt_house->GetComfortLevel())
		{
		case NO_BED:title = "您在地板上凑和了一夜"; break;
		case RICE_STRAW_BED:title = "稻草不够舒适，但至少算是一张床"; break;
		case SECOND_HAND_BED:title = "床会在您翻身时嘎吱嘎吱响"; break;
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
	//玩家拥有货物显示（出租屋列表显示）
	GameRole* role = GameWorld::GetInstance()->GetGameRole();
	cout << endl << "您的仓库(库存：" << role->GetCurrentStore() << "/" << role->GetMaxStore() << ")" << endl;
	int number = role->GetStoreGood()->size();
	if (number == 0)
	{//玩家没有物品的情况
		cout << "空无一物" << endl;
	}
	else
	{
		for (auto good : *role->GetStoreGood())
		{
			//拼接货物信息
			stringstream str;
			//以下为右对齐操作
			int spaceSize = 6 - str.str().length();
			str.str("");
			int counter = 0;
			while (counter < spaceSize)
			{
				str << " ";
				counter++;
			}
			str << good->GetBuyPrice();
			cout << good->GetID() << "." << good->GetName() << " 购价：" << str.str() << "元    数量：" << good->GetCount() << endl;
		}
	}
	//添加下分隔符
	for (int i = 0; i < width; i++)
	{
		cout << "*";
	}
	cout << endl;
}//此段代码出现了两次，可以考虑封装一下