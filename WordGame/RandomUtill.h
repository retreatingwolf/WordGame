#pragma once
/*�����������*/
class RandomUtill
{
public:
	RandomUtill();
	virtual ~RandomUtill();
	//ָ����Χ�ڲ����������
	static int GetRandomInteger(int min,int max); 
	//���ݸ��ʲ���һ��event�ɹ���ʧ�ܵĽ�����
	static bool GetProbabilityResult(int probability);
protected:
private:

};

