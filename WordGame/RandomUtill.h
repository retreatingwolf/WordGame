#pragma once
/*随机数工具类*/
class RandomUtill
{
public:
	RandomUtill();
	virtual ~RandomUtill();
	//指定范围内产生随机整数
	static int GetRandomInteger(int min,int max); 
	//根据概率产生一个event成功或失败的结果结果
	static bool GetProbabilityResult(int probability);
protected:
private:

};

