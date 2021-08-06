#include "StationView.h"
#include "Viewer.h"
#include "MarketView.h"

StationView::StationView()
{

}
StationView::~StationView()
{

}

void StationView::Show()
{
	GameInfoView::Show();//չʾ����վ��Ϣ��ͬʱҲҪչʾ��ɫ����Ϣ���
	this->ShowStationNet();
}

void StationView::ShowStationNet()
{
	vector<string> stationNames;
	auto stations = *GameWorld::GetInstance()->GetStations();//�������л�ȡ���е���վ������
	for (auto station : stations)
	{
		stationNames.push_back(station->GetName());
	}

	int id = Viewer::ChooseMenuItem("���е���ʾ��ͼ", stationNames);//��ȡ�û�ѡ��ĵ���վ���

	//��ȡ�û�ѡ��ĳ�վ�����ĺ��в���ʾ���Ժ������½�����һ����ķ�װ��
	auto marketView=MarketView::Creat(stations.at(id - 1)->GetBlackMarket());//IDת�±��Сϸ��
	marketView->Show();
	delete marketView;//show���ɾ����static�����������ڴˣ�
}

