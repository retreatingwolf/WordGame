#pragma once
/*��Ϸϵͳ�Ľ��̿���*/
#include "SoundController.h"
#include "Viewer.h"
class GameController
{
public:
	GameController();
	virtual ~GameController();

	//��ȡ��������
	static GameController* GetInstance();
	//��Ϸ��ʼ
	void GameStart();
	//��Ϸ����
	void GameOver();

protected:
private:
	static GameController* instance;
};

