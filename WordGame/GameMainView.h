#pragma once
#include "GameInfoView.h"	

//��Ϸ��������
class GameMainView : public GameInfoView
{
public:
	GameMainView();
	virtual ~GameMainView();

	//��ʾ��Ϸ������
	void Show()override;
protected:
	
private:
	//��Ϸ����ѡ��
	void ShowFuncChoice();
};

