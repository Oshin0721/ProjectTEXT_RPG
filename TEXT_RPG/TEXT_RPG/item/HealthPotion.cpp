#include "HealthPotion.h"
#include //캐릭터 클래스 함수

#include <iostream>

using namespace std;

HealthPotion::HealthPotion()
	: name("회복 표션"), healthRestore(50) {} //초기값

string HealthPotion::getName() const
{
	return name;
}

void HealthPotion::use(Character* character)
{
	character->restoreHealth(healthRestore); // 캐릭터 체력 증가인데 아직 없음
	cout << name << "사용!" << healthRestore << "HP 회복" << endl;
}