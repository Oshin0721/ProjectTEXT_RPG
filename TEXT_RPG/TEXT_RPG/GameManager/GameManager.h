#pragma once
#include <iostream>
#include <cstdlib> // rand(), srand()

#include 
#include 

using namespace std;


class GameManager
{
private:

public:
	void generateMonster(int level);
	void battle(Charactor* player);
	void displayInventory(Charactor* player);
	void visitShop(Charactor* player);
	int random = rand();
};;