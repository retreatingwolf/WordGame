#pragma once

#include "GameRole.h"
#include "GamePlace.h"
#include "GameGood.h"
#include "Station.h"
#include "Message.h"
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
	int GetCurrentDay();
	//���ĵ�ǰʱ��
	void SetCurrentDay(int day);
	//��ȡ���ʱ��
	int GetMaxDay();

	//��ȡ��Ϸ��ɫ
	GameRole* GetGameRole();
	//��ȡ��Ϸ�������ϵķ���
	vector<GamePlace*>* GetGamePlaces() { return &this->prt_places; }
	//��ȡ���е���Ϸ��Ʒ
	map<int, GameGood*>* GetGameGoods() { return &this->prt_goods; }
	//��ȡ����վ�б�
	vector<Station*>* GetStations() { return &this->prt_stations; }
	//��ȡ��Ϣ��¼
	map<int, Message*>* GetMessages() { return &this->prt_messages; }

	//��ǰ�¼�����
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
	//��Ϸ��������һ����Ϸ��ɫ
	GameRole* prt_role;
	//��Ϸ�����ļ���
	vector<GamePlace*> prt_places;
	//��Ϸ��Ʒ�ļ���
	map<int, GameGood*> prt_goods;
	//����վ�б�
	vector<Station*> prt_stations;
	//�洢��Ϣ�б�
	map<int, Message*> prt_messages;
	//��¼��ǰ��������Ϣ
	Message* prt_CurrentMessage;
};

