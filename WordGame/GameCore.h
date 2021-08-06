#pragma once
#include "GameWorld.h"
#include "Viewer.h"
#include "RandomUtill.h"
#include "BlackMarket.h"
#include "EventController.h"
#include <iostream>
using namespace std;
#define BANK_RATES 0.05
#define DEBT_RATES 0.1
#define COMMODITY_NUM 20
/*游戏内核*/
//游戏的开始和结束
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
	//记录游戏状态
	bool prt_GameState;
	//逻辑刷新
	void LogicUpdate();
	//显示刷新
	void ShowUpdate();
	//指定黑市商品列表更新
	void UpdateMarketList(BlackMarket* market);//传入黑市编号
};

