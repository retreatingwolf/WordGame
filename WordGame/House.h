#pragma once
#include "Parameter.h"
class House
{
public:
	House();
	virtual ~House();

	int GetComfortLevel() { return this->prt_comfortLevel; }
	void SetComfortLevel(int val) { this->prt_comfortLevel = val; }
protected:
private:
	int prt_comfortLevel;//���ʶȣ�����ÿ��˯��������Ѫ
};

//������ʱ����GameRole�е��������ת�ƹ���

