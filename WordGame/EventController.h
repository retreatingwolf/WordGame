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

	//加载事件数据
	void LoadingData();
	//处理触发调用（在GameCore的逻辑层进行触发调用）
	void PlayMessage(int id);
protected:
private:
	static EventController* instance;
};

