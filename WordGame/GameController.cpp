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
	//�����������ֲ���
	//SoundController::GetInstance()->PlayBGM();
	//�������鶯������
	//Viewer::GetInstace()->ShowStory();
	//ϵͳ�˵���չʾ
	Viewer::GetInstace()->ShowSystemMenu();
}

void GameController::GameOver()
{

}