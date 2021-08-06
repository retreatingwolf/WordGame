#pragma once
/*游戏系统的进程控制*/
#include "SoundController.h"
#include "Viewer.h"
class GameController
{
public:
	GameController();
	virtual ~GameController();

	//获取单例对象
	static GameController* GetInstance();
	//游戏开始
	void GameStart();
	//游戏结束
	void GameOver();

protected:
private:
	static GameController* instance;
};

