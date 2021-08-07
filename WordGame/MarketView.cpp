#include "MarketView.h"
#include "Parameter.h"

MarketView::MarketView()
{
	this->prt_market = nullptr;
}
MarketView::~MarketView()
{

}

MarketView* MarketView::Creat(BlackMarket* market)
{//此函数特殊，需要注意
	MarketView* view = new MarketView();
	if (view)
	{
		view->prt_market = market;
	}
	else
	{
		delete view;
		view = nullptr;
	}
	return view;
}

void MarketView::Show()
{
	GameInfoView::Show();//固定的界面显示
	//刷新列表显示
	this->UpdateShowList(this->prt_market);
	//显示交易菜单
	this->ShowMenu();
}

void MarketView::UpdateShowList(BlackMarket* market)
{
	//黑市商品列表显示
	cout << "您现在在" << market->GetName() << "的黑市" << endl;
	for (auto good : *market->GetGoods())
	{
		//拼接商品信息
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
		str << good->GetValue();
		cout << good->GetID() << "." << good->GetName() << " 售价：" << str.str() << "元    数量：" << good->GetCount() << endl;
	}

	//添加上分隔符
	int width = 62;
	for (int i = 0; i < width; i++)
	{
		cout << "*";
	}
	cout << endl;

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
}

void MarketView::ShowMenu()
{
	//以下实现购买出售功能 
	vector<string> itemNames;//菜单项
	itemNames.push_back("购买");
	itemNames.push_back("出售");
	itemNames.push_back("离开");
	switch (Viewer::ChooseMenuItem("交易类型", itemNames))
	{
	case 1://购买
	{
		cout << "您要购买的商品编号是：";
		int goodId;
		cin >> goodId;
		cout << "您要购买的商品数量：";
		int goodNum;
		cin >> goodNum;

		//对黑市商品数据进行操作
		switch (this->prt_market->Sell(goodId, goodNum))
		{
		case COMMODITY_NOT_FOUND://当前黑市不存在该商品
		{
			cout << "商品断货！" << endl;
		}break;
		case GOOD_AMOUNT_NOT_ENOUGH://商品数量不足无法购买
		{
			cout << "商品不足！" << endl;
		}break;
		case SUCCESSFUL_SELL://购买成功
		{
			cout << "交易成功！" << endl;
		}break;
		case MONEY_AMOUNT_NOT_ENOUGH://玩家现金不足的情况
		{
			cout << "您的钱不够！" << endl;
		}break;
		case STORE_AMOUNT_NOT_ENOUGH://仓库容量不够
		{
			cout << "您的出租屋放不下了！" << endl;
		}break;
		}

		Sleep(2000);
		//刷新界面
		MarketView::Show();//退回到黑市显示的界面
	}return;

	case 2://出售
	{
		cout << "您要出售的货物编号是：";
		int goodId;
		cin >> goodId;
		cout << "您要出售的货物数量：";
		int goodNum;
		cin >> goodNum;

		//在黑市中查找商品
		GameGood* commodity = nullptr;
		for (auto good : *this->prt_market->GetGoods())
		{
			if (good->GetID() == goodId)
			{
				commodity = good;
				break;
			}
		}
		if (commodity == nullptr)
		{
			cout << "商品断货（但是为什么不能出售呢，因为实现太麻烦了）" << endl;
		}
		else
		{
			int errorcode = GameWorld::GetInstance()->GetGameRole()->Sell(commodity, goodNum);
			switch (errorcode)
			{
			case COMMODITY_NOT_FOUND://仓库不存在该物品
			{
				cout << "您仓库中没有该商品" << endl;
			}break;
			case GOOD_AMOUNT_NOT_ENOUGH://货物数量不足
			{
				cout << "您仓库中货物不足" << endl;
			}break;
			case SUCCESSFUL_SELL://交易成功
			{
				cout << "交易成功" << endl;
			}break;
			}
		}
		Sleep(2000);
		//刷新界面
		MarketView::Show();//退回到黑市显示的界面
	}return;
	case 3://离开
	default:
		Viewer::GetInstace()->StartGame();
		return;
	}
}