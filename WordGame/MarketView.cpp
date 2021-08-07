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
{//�˺������⣬��Ҫע��
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
	GameInfoView::Show();//�̶��Ľ�����ʾ
	//ˢ���б���ʾ
	this->UpdateShowList(this->prt_market);
	//��ʾ���ײ˵�
	this->ShowMenu();
}

void MarketView::UpdateShowList(BlackMarket* market)
{
	//������Ʒ�б���ʾ
	cout << "��������" << market->GetName() << "�ĺ���" << endl;
	for (auto good : *market->GetGoods())
	{
		//ƴ����Ʒ��Ϣ
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
		str << good->GetValue();
		cout << good->GetID() << "." << good->GetName() << " �ۼۣ�" << str.str() << "Ԫ    ������" << good->GetCount() << endl;
	}

	//����Ϸָ���
	int width = 62;
	for (int i = 0; i < width; i++)
	{
		cout << "*";
	}
	cout << endl;

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
}

void MarketView::ShowMenu()
{
	//����ʵ�ֹ�����۹��� 
	vector<string> itemNames;//�˵���
	itemNames.push_back("����");
	itemNames.push_back("����");
	itemNames.push_back("�뿪");
	switch (Viewer::ChooseMenuItem("��������", itemNames))
	{
	case 1://����
	{
		cout << "��Ҫ�������Ʒ����ǣ�";
		int goodId;
		cin >> goodId;
		cout << "��Ҫ�������Ʒ������";
		int goodNum;
		cin >> goodNum;

		//�Ժ�����Ʒ���ݽ��в���
		switch (this->prt_market->Sell(goodId, goodNum))
		{
		case COMMODITY_NOT_FOUND://��ǰ���в����ڸ���Ʒ
		{
			cout << "��Ʒ�ϻ���" << endl;
		}break;
		case GOOD_AMOUNT_NOT_ENOUGH://��Ʒ���������޷�����
		{
			cout << "��Ʒ���㣡" << endl;
		}break;
		case SUCCESSFUL_SELL://����ɹ�
		{
			cout << "���׳ɹ���" << endl;
		}break;
		case MONEY_AMOUNT_NOT_ENOUGH://����ֽ�������
		{
			cout << "����Ǯ������" << endl;
		}break;
		case STORE_AMOUNT_NOT_ENOUGH://�ֿ���������
		{
			cout << "���ĳ����ݷŲ����ˣ�" << endl;
		}break;
		}

		Sleep(2000);
		//ˢ�½���
		MarketView::Show();//�˻ص�������ʾ�Ľ���
	}return;

	case 2://����
	{
		cout << "��Ҫ���۵Ļ������ǣ�";
		int goodId;
		cin >> goodId;
		cout << "��Ҫ���۵Ļ���������";
		int goodNum;
		cin >> goodNum;

		//�ں����в�����Ʒ
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
			cout << "��Ʒ�ϻ�������Ϊʲô���ܳ����أ���Ϊʵ��̫�鷳�ˣ�" << endl;
		}
		else
		{
			int errorcode = GameWorld::GetInstance()->GetGameRole()->Sell(commodity, goodNum);
			switch (errorcode)
			{
			case COMMODITY_NOT_FOUND://�ֿⲻ���ڸ���Ʒ
			{
				cout << "���ֿ���û�и���Ʒ" << endl;
			}break;
			case GOOD_AMOUNT_NOT_ENOUGH://������������
			{
				cout << "���ֿ��л��ﲻ��" << endl;
			}break;
			case SUCCESSFUL_SELL://���׳ɹ�
			{
				cout << "���׳ɹ�" << endl;
			}break;
			}
		}
		Sleep(2000);
		//ˢ�½���
		MarketView::Show();//�˻ص�������ʾ�Ľ���
	}return;
	case 3://�뿪
	default:
		Viewer::GetInstace()->StartGame();
		return;
	}
}