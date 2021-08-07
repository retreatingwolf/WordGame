#pragma once

#define GAME_MAXDAY 40
#define INIT_CASH 2000
#define INIT_DEBT 6050
#define INIT_DEPOSIT 0
#define INIT_HP 100
#define INIT_FAME 100
#define INIT_MAXSTORAGE 100

#define BANK_RATES 0.05
#define DEBT_RATES 0.1
#define COMMODITY_NUM 20

#define MIN_MARKET_GOODS 5
#define MAX_MARKET_GOODS 7

enum SellState
{
	COMMODITY_NOT_FOUND,
	GOOD_AMOUNT_NOT_ENOUGH,
	STORE_AMOUNT_NOT_ENOUGH,
	MONEY_AMOUNT_NOT_ENOUGH,
	SUCCESSFUL_SELL
};