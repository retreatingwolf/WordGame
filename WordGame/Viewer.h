#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>
#include "GameCore.h"
#include "SoundController.h"
#include "GameMainView.h"
using namespace std;

/*��ͼ�࣬�ۺϿ��������иø��û���ʾ�Ķ�����ͬʱҪ����model���ṩ�����ݽ��*/
class Viewer
{
public:
	Viewer();
	virtual ~Viewer();
	//��ȡ��������
	static Viewer* GetInstace();
	//���ſ������鶯��
	void ShowStory();
	//չʾϵͳ�˵�
	void ShowSystemMenu();
	//��Ϸ������ʾ
	void StartGame();
	//��Ϸ������ʾ
	void EndGame();

	/*
	��װһ���˵�ѡ������
	����˵����ƺ�ѡ������
	����ѡ����
	*/
	static int ChooseMenuItem(string title, vector<string> items);//�ú����ǳ���Ч

protected:
private:
	static Viewer* instance;
	//���Ŵ��ֶ��� ������ʾÿһ�е�����
	void PlayTypewrite(string line);
	//��ʾϵͳ�˵���
	void ShowSystemMenuItem();
	//��ʾ��Ϸ���ò˵���
	void ShowSettingMenu();
	//��Ϸ�����ʵ��
	GameMainView *prt_mainView;
};

