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

	std::cout << "===== [���� �α�] =====";
	std::cout << std::endl;
	for (const auto& pair : monsterLog)
	{
		cout << pair.first << ": " << pair.second << "���� óġ" << endl;
	}

	std::cout << "===== [������ ��� �α�] =====";
	std::cout << std::endl;
	for (const auto& pair : usedItemLog)
	{
		cout << pair.first << ": " << pair.second << "�� ���" << endl;
	}

	std::cout << "===== [���� �α�] =====";
	std::cout << std::endl;
	for (const auto& pair : shopBuyLog)
	{
		cout << pair.first << ": " << pair.second << "�� ����" << endl;
	}

	for (const auto& pair : shopSellLog)
	{
		cout << pair.first << ": " << pair.second << "�� �Ǹ�" << endl;
	}

	std::cout << "===== [������ �α�] =====";
	std::cout << std::endl;
	cout << "�� ���� ������: " << giveDamage << endl;
	std::cout << std::endl;
	cout << "�� ���� ������: " << takeDamage << endl;
	std::cout << std::endl;

	std::cout << "===== [���� ũ����] =====" << endl;
	cout << "����: " << endl;
	cout << "�ŵ���" << endl;
	std::cout << std::endl;

	cout << "����: " << endl;
	cout << "��Ź��" << endl;
	cout << "���ػ�" << endl;
	cout << "�̿���" << endl;
	cout << "������" << endl;
	cout << "������" << endl;

}


#include <thread>
#include <chrono>
void SimpleScrollLine(const std::string& text, int delay_ms) {
	std::cout << text << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(delay_ms));
}

void LogManager::PrintAllLogsSlow() {
	SimpleScrollLine("===== [���� �α�] =====");
	for (const auto& pair : monsterLog)
		SimpleScrollLine(pair.first + ": " + std::to_string(pair.second) + "���� óġ");

	SimpleScrollLine("");
	SimpleScrollLine("===== [������ ��� �α�] =====");
	for (const auto& pair : usedItemLog)
		SimpleScrollLine(pair.first + ": " + std::to_string(pair.second) + "�� ���");

	SimpleScrollLine("");
	SimpleScrollLine("===== [���� �α�] =====");
	for (const auto& pair : shopBuyLog)
		SimpleScrollLine(pair.first + ": " + std::to_string(pair.second) + "�� ����");
	for (const auto& pair : shopSellLog)
		SimpleScrollLine(pair.first + ": " + std::to_string(pair.second) + "�� �Ǹ�");

	SimpleScrollLine("");
	SimpleScrollLine("===== [������ �α�] =====");
	SimpleScrollLine("�� ���� ������: " + std::to_string(giveDamage));
	SimpleScrollLine("�� ���� ������: " + std::to_string(takeDamage));

	SimpleScrollLine("");
	SimpleScrollLine("===== [���� ũ����] =====");
	SimpleScrollLine("����: �ŵ���");
	SimpleScrollLine("����: ��Ź��");
	SimpleScrollLine("����: ���ػ�");
	SimpleScrollLine("����: �̿���");
	SimpleScrollLine("����: ������");
	SimpleScrollLine("����: ������");
}
