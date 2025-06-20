#include "AttackBoost.h"
#include ""//아직 캐릭터 클래스가 없음

#include <iostream>

using namespace std;

AttackBoost::AttackBoost()
	: name("공격력 증가"), attackIncrease(10) {} // 공격력 증가 초기값

string AttackBoost::getName() const // 아이템 이름 반환
{
	return name;
}

void AttackBoost::use(Character* character)
{
	character->increaseAttack(attackIncrease); //공격력증가
	cout << name << "사용 +" << attackIncrease << "공격력 증가 완료" << endl;
}