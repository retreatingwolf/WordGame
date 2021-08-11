#pragma once

#define GAME_MAXDAY 40
#define INIT_CASH 2000
#define INIT_DEBT 6050
#define INIT_DEPOSIT 0
#define INIT_HP 100
#define INIT_FAME 100
#define INIT_MAXSTORAGE 20

enum MyEnum
{
	NO_BED = 3,
	RICE_STRAW_BED = 2,
	SECOND_HAND_BED = 1
};
#define RICE_STRAW_BED_PRICE 5000
#define SECON_DHAND_BED_PRICE 20000
#define HIGH_LEVEL_BED_PRICE 1000000000
#define STORAGE_LEVEL_UP_PRICE 100000

#define BANK_RATES 0.05
#define DEBT_RATES 0.1
#define COMMODITY_NUM 20

#define MIN_MARKET_GOODS 5
#define MAX_MARKET_GOODS 7

#define HACKER_ATTACK_PROBABILITY 50
#define EVENT_HAPPEN_PROBABILITY 50

enum SellState
{
	COMMODITY_NOT_FOUND,
	GOOD_AMOUNT_NOT_ENOUGH,
	STORE_AMOUNT_NOT_ENOUGH,
	MONEY_AMOUNT_NOT_ENOUGH,
	SUCCESSFUL_SELL
};

enum BankState
{
	DEPOSIT_NOT_ENOUGH,
	SUCCESSFUL_RECEIVE,
};