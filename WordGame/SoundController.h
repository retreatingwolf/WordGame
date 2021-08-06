#pragma once

#include <tchar.h>
#include <sstream>
#include<windows.h>//一定要放在前面
#include<Mmsystem.h>
#pragma comment(lib,"winmm.lib")
using namespace std;

/*声音控制器*/
class SoundController
{
public:
	SoundController();
	virtual ~SoundController();

	//单例的实现
	static SoundController* GetInstance();
	//播放音效
	void PlaySoundEffect(int id);
	//停止播放音效
	void StopSoundEffect(int id);
	//播放背景音乐
	void PlayBGM();
	//停止播放背景音乐
	void StopBGM();
	//停止所有声音播放
	void StopAll();

	//获取声音状态
	bool GetSilence();
	//设置是否静音
	void SetSilence(bool silence);
protected:
private:
	static SoundController* instance;
	//当前声音状态（true为静音）
	bool prt_silence;
};

