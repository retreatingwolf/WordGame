#include "GameMainView.h" 
#include "Viewer.h"//��ͷ�ļ�ֻ���ڴ˴����룬�������ѭ������ĺ��
#include "StationView.h"

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
	auto world = GameWorld::GetInstance();//����ģʽ�ı��֮�����κεط�������ȡֵ��ȡ���������磩
	//��ȡ����������
	vector<string> items;
	for (auto place : *world->GetGamePlaces())
	{
		items.push_back(place->GetName());//��ȡ�������֣�������һ�����л�ȡ��
	}

	//��item���в���
	items.push_back("��ʼ�µ�һ��");
	items.push_back("������Ϸ");

	switch (Viewer::ChooseMenuItem("���е���ʾ��ͼ", items))
	{
	case 1://����վ
	{
		//system("cls");
		StationView* stationView = new StationView();
		stationView->Show();
		delete stationView;
	}return;
	case 2://����
	{

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
	case 6://�ⷿ�н� 
	{

	}break;
	case 7://����
	{

	}break;
	case 8://�µ�һ��
	{
		return;
	}break;
	case 9://������Ϸ
	default://��ѡҲ�˳���Ϸ
	{
		exit(0);
	}
		break;
	}
}