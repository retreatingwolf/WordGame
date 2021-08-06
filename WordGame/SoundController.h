#pragma once

#include <tchar.h>
#include <sstream>
#include <windows.h>//һ��Ҫ����ǰ��
#include <Mmsystem.h>
#pragma comment(lib,"winmm.lib")
using namespace std;

/*����������*/
class SoundController
{
public:
	SoundController();
	virtual ~SoundController();
	static SoundController* GetInstance();

	//������Ч
	void PlaySoundEffect(int id);
	//ֹͣ������Ч
	void StopSoundEffect(int id);
	//���ű�������
	void PlayBGM();
	//ֹͣ���ű�������
	void StopBGM();
	//ֹͣ������������
	void StopAll();
	//����ת��
	void SoundTransform();

	bool GetSilence() { return this->prt_silence; }
	void SetSilence(bool silence) { this->prt_silence = silence; }
protected:
private:
	static SoundController* instance;
	//��ǰ����״̬��trueΪ������
	bool prt_silence;
};

