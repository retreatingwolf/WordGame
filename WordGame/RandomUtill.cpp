#include "RandomUtill.h"
#include <cstdlib>
#include <ctime>
RandomUtill::RandomUtill()
{

}
RandomUtill::~RandomUtill()
{

}

static bool flag = false;//��ʶ�Ƿ�������������
int RandomUtill::GetRandomInteger(int min, int max)
{
	if (flag == false)
	{
		srand((unsigned int)time(NULL));
		flag = true;
	}
	return rand() % (max - min) + min;
}

bool RandomUtill::GetProbabilityResult(int probability)
{//ע��˴��㷨����һ�μ�
	return probability * 100 >= RandomUtill::GetRandomInteger(0, 10000);
}