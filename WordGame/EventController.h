#pragma once
#include "GameWorld.h"
#include <string>
using namespace std;
class EventController
{
public:
	EventController();
	virtual ~EventController();
	static EventController* GetInstance();

	//�����¼�����
	void LoadingData();
	//����������ã���GameCore���߼�����г�������
	void PlayMessage(int id);
protected:
private:
	static EventController* instance;
};

