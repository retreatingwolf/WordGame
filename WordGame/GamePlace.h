#pragma once
#include <string>
using namespace std;
//游戏场景数据模型
class GamePlace
{
public:
	GamePlace();
	virtual ~GamePlace();

	int GetID() { return this->prt_id; }
	void SetID(int val) { this->prt_id = val; }
	string GetName() { return this->prt_name; }
	void SetName(string val) { this->prt_name = val; }
protected:
private:
	int prt_id;
	string prt_name;
};

