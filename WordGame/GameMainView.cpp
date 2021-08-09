#include "GameMainView.h" 
#include "Viewer.h"//��ͷ�ļ�ֻ���ڴ˴����룬�������ѭ������ĺ��
#include "StationView.h"
#include "BankView.h"
#include "HouseView.h"

GameMainView::GameMainView()
{

}
GameMainView::~GameMainView()
{

}

void GameMainView::Show()
{
	GameInfoView::Show();
	//��ʾ��Ϸ����ѡ�����
	this->ShowFuncChoice();
}

void GameMainView::ShowFuncChoice()
{
	GameWorld* world = GameWorld::GetInstance();//����ģʽ�ı��֮�����κεط�������ȡֵ��ȡ���������磩
	//��ȡ����������
	vector<string> items;
	for (auto place : *world->GetGamePlaces())
	{
		items.push_back(place->GetName());//��ȡ�������֣�������һ�����л�ȡ��
	}

	//��item���в���
	/*items.push_back("��ʼ�µ�һ��");*/
	items.push_back("������Ϸ");

	switch (Viewer::ChooseMenuItem("���е���ʾ��ͼ", items))
	{
	case 1://����վ
	{
		StationView* stationView = new StationView();
		stationView->Show();
		delete stationView;
	}return;
	case 2://����
	{
		BankView* bankView = new BankView();
		bankView->Show();
		delete bankView;
	}break;
	case 3://�ʾ�
	{

	}break;
	case 4://ҽԺ
	{

	}break;
	case 5://����
	{

	}break;
	case 6://�Ҿ߳�
	{

	}break;
	case 7://����
	{

	}break;
	case 8://������
	{
		HouseView* houseView = new HouseView();
		houseView->Show();
		delete houseView;
	}break;
	case 9://������Ϸ
	default://��ѡҲ�˳���Ϸ
	{
		cout << "�Ƿ񱣴���Ϸ���ȣ�" << endl;
		//�ṩһ������ӿ�
		exit(0);
	}
	}
}