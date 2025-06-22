#pragma once
#include <iostream>
#include <cstdlib> // rand(), srand()

using namespace std;


class GameManager
{
private:

public:
	void generateMonster(int level);
	void battle(Character* character);
	void displayInventory();
	void visitShop();
	int random = rand();
};;