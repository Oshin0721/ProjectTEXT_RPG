#pragma once
#include <iostream>
#include <cstdlib> // rand(), srand()

using namespace std;


class GameManager
{
private:

public:
	void generateMonster(int level);
	void battle(character* player);
	void displayInventory();
	void visitShop();
	int random = rand();
};;