#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>
#include "GameCore.h"
#include "SoundController.h"
#include "GameMainView.h"
using namespace std;

/*视图类，综合控制了所有该给用户显示的东西，同时要调用model中提供的数据借口*/
class Viewer
{
public:
	Viewer();
	virtual ~Viewer();
	//获取单例对象
	static Viewer* GetInstace();
	//播放开场剧情动画
	void ShowStory();
	//展示系统菜单
	void ShowSystemMenu();
	//游戏开启显示
	void StartGame();
	//游戏结束显示
	void EndGame();

	/*
	封装一个菜单选择函数，
	传入菜单名称和选项名称
	返回选择结果
	*/
	static int ChooseMenuItem(string title, vector<string> items);//该函数非常有效

protected:
private:
	static Viewer* instance;
	//播放打字动画 参数表示每一行的内容
	void PlayTypewrite(string line);
	//显示系统菜单项
	void ShowSystemMenuItem();
	//显示游戏设置菜单项
	void ShowSettingMenu();
	//游戏主面板实例
	GameMainView *prt_mainView;
};

