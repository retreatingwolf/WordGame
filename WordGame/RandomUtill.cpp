#include "RandomUtill.h"
#include <cstdlib>
#include <ctime>
RandomUtill::RandomUtill()
{

}
RandomUtill::~RandomUtill()
{

}

static bool flag = false;//标识是否产生过随机种子
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
{//注意此处算法，第一次见
	return probability * 100 >= RandomUtill::GetRandomInteger(0, 10000);
}