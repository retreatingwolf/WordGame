#pragma once
#include "GameInfoView.h"
#include "GameRole.h"
#include "House.h"

//�����ݽ�����ʾ��
class HouseView : public GameInfoView
{
public:
	HouseView();
	virtual ~HouseView();

	void Show() override;
protected:
private:
	void ShowHouse();
	void ShowStore();
	GameRole* prt_role;
	House* prt_house;
};
