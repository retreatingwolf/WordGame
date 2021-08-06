#pragma once
#include "GameRole.h"
#include "GameWorld.h"
//#include "Viewer.h" //�˴�����GameMainView��Viewer�������
#include <vector>
#include <string>
#include <sstream> 
#include <iostream>
using namespace std;

//��ʾ��Ϣ�࣬������Ϣ���󣬽����п�״����Ϣ��ֿ������ø����ۺϿ���
class GameInfoView
{
public:
	GameInfoView();
	virtual ~GameInfoView();
protected://������Ҫ�̳в�����show�������ڴ˴�
	//��ʾ
	virtual void Show();
private:
	//�˴���ʱ���GameWorld�е�ʱ���ǲ�һ����
	int prt_CurrentDay;
	int prt_MaxDay;

	//��ʾʱ��
	void ShowDay();
	//��ʾ����¼�
	void ShowEvent();
	//��ʾ�����Ϣ
	void ShowRoleInfo();
	//��ɫ������ʾ��ʽ
	string ShowFormatForRoleProp(int id, string name, int value, string unit = "");
	//��ɫ����
	GameRole* prt_role;
};

