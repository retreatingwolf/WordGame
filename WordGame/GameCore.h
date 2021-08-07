#pragma once
#include "GameWorld.h"
#include "Viewer.h"
#include "RandomUtill.h"
#include "BlackMarket.h"
#include "EventController.h"
#include <iostream>
using namespace std;

/*��Ϸ�ں�*/
//��Ϸ�Ŀ�ʼ�ͽ���
class GameCore
{
public:
	GameCore();
	virtual ~GameCore();

	static GameCore* GetInstance();
	void GameStart();
	void GameOver();
protected:
private:
	static GameCore* instance;
	//��¼��Ϸ״̬
	bool prt_GameState;
	//�߼�ˢ��
	void LogicUpdate();
	//��ʾˢ��
	void ShowUpdate();
	//ָ��������Ʒ�б����
	void UpdateMarketList(BlackMarket* market);//������б��
};

