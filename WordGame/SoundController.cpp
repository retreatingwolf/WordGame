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
	//����windows�������ֵ�API��ֻ�ܲ���.wav .wave��ʽ
	//�����첽����
	//����ֵ���������Ƿ���Ч��
	//����һ��Ҫ�����ļ���
	//��������Ӧ�ó����ʾ�������NULL
	//����������־���
	if (this->prt_silence == true) return;
	PlaySound(TEXT("sound/bgm1.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
	//Ҫֹͣ���ڲ���һ������ַ���
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
	//ֹͣ������Ч
	int soundIds[] = { 1 };
	for (int i = 0; i < sizeof(soundIds) / sizeof(int); i++)
	{
		this->StopSoundEffect(soundIds[i]);
	}
	//ֹͣ���ű�������
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
