#include "AttackBoost.h"
#include "../Character/Character.h"

#include <iostream>

using namespace std;

AttackBoost::AttackBoost()
	: name("공격력 강화"), attackIncrease(10), buyPrice(30), sellPrice(15) {} // 공격력 증가 초기값 //증가->강화 수정

string AttackBoost::getName() const // 아이템 이름 반환
{
	return name;
}

void AttackBoost::use(Character* character)
{
	character->increaseAttack(attackIncrease); //공격력증가
	cout << name << "사용 +" << attackIncrease << "공격력 증가 완료" << endl;
}

int AttackBoost::getBuyPrice() const
{
	return buyPrice;
}

int AttackBoost::getSellPrice() const
{
	return sellPrice;
}