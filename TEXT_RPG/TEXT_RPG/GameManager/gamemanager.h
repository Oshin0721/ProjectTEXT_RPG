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
	void generateMonster();
	void battle(Character* character);
	void displayInventory();
	void visitShop();
	int random = rand();
};;