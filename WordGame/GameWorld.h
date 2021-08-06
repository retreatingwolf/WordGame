#pragma once

#include "GameRole.h"
#include "GamePlace.h"
#include "GameGood.h"
#include "Station.h"
#include "Message.h"
#include <vector>
#include <map>
using namespace std;
/*游戏世界数据模型*/
/*是多个类的结合，游戏时间，游戏人物，游戏场景，游戏商品均在此类中进行构造和数据说明*/
class GameWorld
{
public:
	GameWorld();
	virtual ~GameWorld();

	//向系统提供实例
	static GameWorld* GetInstance();
	//获取当前时间
	int GetCurrentDay();
	//更改当前时间
	void SetCurrentDay(int day);
	//获取最大时间
	int GetMaxDay();

	//获取游戏角色
	GameRole* GetGameRole();
	//获取游戏场景集合的方法
	vector<GamePlace*>* GetGamePlaces() { return &this->prt_places; }
	//获取所有的游戏物品
	map<int, GameGood*>* GetGameGoods() { return &this->prt_goods; }
	//获取地铁站列表
	vector<Station*>* GetStations() { return &this->prt_stations; }
	//获取消息记录
	map<int, Message*>* GetMessages() { return &this->prt_messages; }

	//当前事件操作
	Message* GetCurrentMessage() { return this->prt_CurrentMessage; }
	void SetCurrentMessage(Message* message) { this->prt_CurrentMessage = message; }
protected:
private:
	//静态成员变量需要在cpp文件中声明
	static GameWorld* instance;//单例设计模式

	//游戏当前时间
	int prt_CurrentDay;
	//游戏最大时间
	int prt_MaxDay;
	//游戏世界中有一个游戏角色
	GameRole* prt_role;
	//游戏场景的集合
	vector<GamePlace*> prt_places;
	//游戏物品的集合
	map<int, GameGood*> prt_goods;
	//地铁站列表
	vector<Station*> prt_stations;
	//存储消息列表
	map<int, Message*> prt_messages;
	//记录当前触发的消息
	Message* prt_CurrentMessage;
};

