#ifndef LOGMANAGER_H
#define LOGMANAGER_H

#include <unordered_map>
#include <string>
#include "LogManager.h"
#include "../Monster/Monster.h"

class LogManager
{
private:
	static LogManager* instance;
	LogManager();

	std::unordered_map<std::string, int> monsterLog;
	std::unordered_map<std::string, int> shopSellLog;
	std::unordered_map<std::string, int> shopBuyLog;
	std::unordered_map<std::string, int> usedItemLog;
	
	int giveDamage;
	int takeDamage; 

public:

	// singleton property
	~LogManager();

	LogManager(const LogManager&) = delete;
	LogManager& operator=(const LogManager&) = delete;

	static LogManager* getInstance();

	// Add Log
	void AddMonsterLog(Monster* monster);
	
	void AddShopSellLog(Item* item);

	void AddShopBuyLog(Item* item);

	void AddItemLog(Item* item);

	void AddGiveDamageLog(int damage);

	void AddTakeDamageLog(int damage);

	// Print Log
	void PrintAllLogs();

	void PrintAllLogsSlow();

};
#endif