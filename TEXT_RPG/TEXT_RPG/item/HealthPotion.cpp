#include "HealthPotion.h"
#include "../Character/Character.h"
#include "Item.h"

#include <iostream>

using namespace std;

HealthPotion::HealthPotion()
	: name("회복 물약"), healthRestore(50), buyPrice(50), sellPrice(40) {} //초기값 //표션->물약 수정

string HealthPotion::getName() const
{
	return name;
}

void HealthPotion::use(Character* character)
{
	character->restoreHealth(healthRestore); // 캐릭터 체력 증가인데 아직 없음
	cout << name << "사용!" << healthRestore << "HP 회복" << endl;
}
int HealthPotion::getBuyPrice() const
{
	return buyPrice;
}

int HealthPotion::getSellPrice() const
{
	return sellPrice;
}

std::unique_ptr<Item> HealthPotion::clone() const {
	return std::make_unique<HealthPotion>(*this);
}