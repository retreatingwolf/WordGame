#pragma once
#include "GameInfoView.h"	

//游戏主界面类
class GameMainView : public GameInfoView
{
public:
	GameMainView();
	virtual ~GameMainView();

	//显示游戏主界面
	void Show()override;
protected:
	
private:
	//游戏功能选择
	void ShowFuncChoice();
};

