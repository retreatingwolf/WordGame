#pragma once
#include "GameRole.h"
#include "GameWorld.h"
//#include "Viewer.h" //此处导致GameMainView和Viewer互相包含
#include <vector>
#include <string>
#include <sstream> 
#include <iostream>
using namespace std;

//显示信息类，由于信息量大，将所有块状的信息拆分开来，用该类综合控制
class GameInfoView
{
public:
	GameInfoView();
	virtual ~GameInfoView();
protected://由于需要继承操作，show函数放在此处
	//显示
	virtual void Show();
private:
	//此处的时间和GameWorld中的时间是不一样的
	int prt_CurrentDay;
	int prt_MaxDay;

	//显示时间
	void ShowDay();
	//显示随机事件
	void ShowEvent();
	//显示玩家信息
	void ShowRoleInfo();
	//角色属性显示格式
	string ShowFormatForRoleProp(int id, string name, int value, string unit = "");
	//角色数据
	GameRole* prt_role;
};

