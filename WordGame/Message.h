#pragma once
//ÊÂ¼şÀà
#include <string>
using namespace std;
class Message
{
public:
	Message();
	virtual ~Message();

	int GetID() { return this->prt_id; }
	void SetID(int val) { this->prt_id=val; }

	int GetGoodsID() { return this->prt_goodsID; }
	void SetGoodsID(int val) { this->prt_goodsID = val; }

	int GetPriceInc() { return this->prt_priceInc; }
	void SetPriceInc(int val) { this->prt_priceInc = val; }

	int GetPriceDec() { return this->prt_priceDec; }
	void SetPriceDec(int val) { this->prt_priceDec = val; }

	int GetGoodsCount() { return this->prt_goodsCount; }
	void SetGoodsCount(int val) { this->prt_goodsCount = val; }

	string GetContent() { return this->prt_content; }
	void SetContent(string val) { this->prt_content = val; }
protected:
private:
	int prt_id;
	int prt_goodsID;
	int prt_priceInc;
	int prt_priceDec;
	int prt_goodsCount;
	string prt_content;
};

