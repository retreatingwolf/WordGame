#include "GameController.h"

GameController* GameController::instance = nullptr;

GameController::GameController()
{

}
GameController::~GameController()
{

}

GameController* GameController::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new GameController();
	}
	return instance;
}

void GameController::GameStart()
{
	//开场背景音乐播放
	//SoundController::GetInstance()->PlayBGM();
	//开场剧情动画播放
	//Viewer::GetInstace()->ShowStory();
	//系统菜单的展示
	Viewer::GetInstace()->ShowSystemMenu();
}

void GameController::GameOver()
{

}