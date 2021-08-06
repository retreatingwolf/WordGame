#include "SoundController.h"

SoundController* SoundController::instance = nullptr;

SoundController::SoundController()
{
	this->prt_silence = false;
}
SoundController::~SoundController()
{

}

SoundController* SoundController::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new SoundController();
	}
	return instance;
}

void SoundController::PlayBGM()
{
	//调用windows播放音乐的API，只能播放.wav .wave格式
	//可以异步播放
	//返回值：参数三是否起效果
	//参数一：要播放文件名
	//参数二：应用程序的示例句柄。NULL
	//参数三：标志组合
	if (this->prt_silence == true) return;
	PlaySound(TEXT("sound/bgm1.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
	//要停止则在参数一传入空字符串
}

void SoundController::StopBGM()
{
	PlaySound(TEXT(NULL), NULL, SND_FILENAME);

}

void SoundController::PlaySoundEffect(int id)
{
	if (this->prt_silence == true) return;
	stringstream cmd;
	cmd << "play ./sound/";
	cmd << id;
	cmd << ".wav";
	mciSendString(cmd.str().c_str(), 0, 0, NULL);
}

void SoundController::StopSoundEffect(int id)
{
	stringstream cmd;
	cmd << "stop ./sound/";
	cmd << id;
	cmd << ".wav";
	mciSendString(cmd.str().c_str(), 0, 0, NULL);
}

void SoundController::StopAll()
{
	//停止所有音效
	int soundIds[] = { 1 };
	for (int i = 0; i < sizeof(soundIds) / sizeof(int); i++)
	{
		this->StopSoundEffect(soundIds[i]);
	}
	//停止播放背景音乐
	this->StopBGM();
}

bool SoundController::GetSilence()
{
	return this->prt_silence;
}

void SoundController::SetSilence(bool silence)
{
	this->prt_silence = silence;
}
