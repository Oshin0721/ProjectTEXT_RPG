#include "LogManager.h"
#include "../Monster/Monster.h"
#include <iostream>
#include <thread>
#include <chrono>


using namespace std;


LogManager* LogManager::instance = nullptr;

LogManager::LogManager() : giveDamage(0), takeDamage(0)
{

}

LogManager::~LogManager()
{

}


LogManager* LogManager::getInstance()
{
	if (instance == nullptr) {
		instance = new LogManager();
	}
	return instance;
}


void LogManager::AddMonsterLog(Monster *monster) { monsterLog[monster->getName()]++; }

void LogManager::AddShopSellLog(Item * item) { shopSellLog[item->getName()]++; }

void LogManager::AddShopBuyLog(Item* item) { shopBuyLog[item->getName()]++; }

void LogManager::AddItemLog(Item* item) { usedItemLog[item->getName()]++; }

void LogManager::AddGiveDamageLog(int damage) { giveDamage += damage; }

void LogManager::AddTakeDamageLog(int damage) { takeDamage += damage; }

void LogManager::PrintAllLogs() {

	std::cout << "===== [몬스터 로그] =====";
	std::cout << std::endl;
	for (const auto& pair : monsterLog)
	{
		cout << pair.first << ": " << pair.second << "마리 처치" << endl;
	}

	std::cout << "===== [아이템 사용 로그] =====";
	std::cout << std::endl;
	for (const auto& pair : usedItemLog)
	{
		cout << pair.first << ": " << pair.second << "개 사용" << endl;
	}

	std::cout << "===== [상점 로그] =====";
	std::cout << std::endl;
	for (const auto& pair : shopBuyLog)
	{
		cout << pair.first << ": " << pair.second << "개 구매" << endl;
	}

	for (const auto& pair : shopSellLog)
	{
		cout << pair.first << ": " << pair.second << "개 판매" << endl;
	}

	std::cout << "===== [데미지 로그] =====";
	std::cout << std::endl;
	cout << "총 가한 데미지: " << giveDamage << endl;
	std::cout << std::endl;
	cout << "총 받은 데미지: " << takeDamage << endl;
	std::cout << std::endl;

	std::cout << "===== [엔딩 크레딧] =====" << endl;
	cout << "팀장: " << endl;
	cout << "신동하" << endl;
	std::cout << std::endl;

	cout << "팀원: " << endl;
	cout << "강탁완" << endl;
	cout << "곽준상" << endl;
	cout << "이예빈" << endl;
	cout << "정성현" << endl;
	cout << "조정원" << endl;

}


#include <thread>
#include <chrono>
void SimpleScrollLine(const std::string& text, int delay_ms) {
	std::cout << text << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(delay_ms));
}

void LogManager::PrintAllLogsSlow() {
	SimpleScrollLine("===== [몬스터 로그] =====");
	for (const auto& pair : monsterLog)
		SimpleScrollLine(pair.first + ": " + std::to_string(pair.second) + "마리 처치");

	SimpleScrollLine("");
	SimpleScrollLine("===== [아이템 사용 로그] =====");
	for (const auto& pair : usedItemLog)
		SimpleScrollLine(pair.first + ": " + std::to_string(pair.second) + "개 사용");

	SimpleScrollLine("");
	SimpleScrollLine("===== [상점 로그] =====");
	for (const auto& pair : shopBuyLog)
		SimpleScrollLine(pair.first + ": " + std::to_string(pair.second) + "개 구매");
	for (const auto& pair : shopSellLog)
		SimpleScrollLine(pair.first + ": " + std::to_string(pair.second) + "개 판매");

	SimpleScrollLine("");
	SimpleScrollLine("===== [데미지 로그] =====");
	SimpleScrollLine("총 가한 데미지: " + std::to_string(giveDamage));
	SimpleScrollLine("총 받은 데미지: " + std::to_string(takeDamage));

	SimpleScrollLine("");
	SimpleScrollLine("===== [엔딩 크레딧] =====");
	SimpleScrollLine("팀장: 신동하");
	SimpleScrollLine("팀원: 강탁완");
	SimpleScrollLine("팀원: 곽준상");
	SimpleScrollLine("팀원: 이예빈");
	SimpleScrollLine("팀원: 정성현");
	SimpleScrollLine("팀원: 조정원");
}
