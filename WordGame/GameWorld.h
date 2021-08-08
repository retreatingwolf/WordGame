#pragma once

#include "GameRole.h"
#include "GamePlace.h"
#include "GameGood.h"
#include "Station.h"
#include "Message.h"
#include "Bank.h"

#include <vector>
#include <map>

using namespace std;
/*��Ϸ��������ģ��*/
/*�Ƕ����Ľ�ϣ���Ϸʱ�䣬��Ϸ�����Ϸ��������Ϸ��Ʒ���ڴ����н��й��������˵��*/
class GameWorld
{
public:
	GameWorld();
	virtual ~GameWorld();

	//��ϵͳ�ṩʵ��
	static GameWorld* GetInstance();
	//��ȡ��ǰʱ��
	int GetCurrentDay() { return this->prt_CurrentDay; }
	//���ĵ�ǰʱ��
	void SetCurrentDay(int day) { this->prt_CurrentDay = day; }
	//��ȡ���ʱ��
	int GetMaxDay() { return this->prt_MaxDay; }

	//��ȡ��Ϸ��ɫ
	GameRole* GetGameRole();
	//��ȡ����
	Bank* GetBank();
	//��ȡ������Ϸ����
	vector<GamePlace*>* GetGamePlaces() { return &this->prt_places; }
	//��ȡ���е���Ϸ��Ʒ
	map<int, GameGood*>* GetGameGoods() { return &this->prt_goods; }
	//��ȡ���е���վ
	vector<Station*>* GetStations() { return &this->prt_stations; }
	//��ȡ�����¼�
	map<int, Message*>* GetMessages() { return &this->prt_messages; }

	//��ȡ�����õ�ǰ�¼�
	Message* GetCurrentMessage() { return this->prt_CurrentMessage; }
	void SetCurrentMessage(Message* message) { this->prt_CurrentMessage = message; }
protected:
private:
	//��̬��Ա������Ҫ��cpp�ļ�������
	static GameWorld* instance;//�������ģʽ

	//��Ϸ��ǰʱ��
	int prt_CurrentDay;
	//��Ϸ���ʱ��
	int prt_MaxDay;
	//��Ϸ��ɫ
	GameRole* prt_role;
	//��Ϸ�����ļ���
	vector<GamePlace*> prt_places;
	//��Ϸ��Ʒ�ļ���
	map<int, GameGood*> prt_goods;
	//����վ�ļ���
	vector<Station*> prt_stations;
	//����
	Bank* prt_bank;
	//�¼��ļ���
	map<int, Message*> prt_messages;
	//��¼��ǰ��������Ϣ
	Message* prt_CurrentMessage;

};

