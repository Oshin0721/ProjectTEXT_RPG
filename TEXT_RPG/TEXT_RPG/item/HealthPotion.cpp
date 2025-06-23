#include "HealthPotion.h"
#include "../Character/Character.h"

#include <iostream>

using namespace std;

HealthPotion::HealthPotion()
	: name("ȸ�� ����"), healthRestore(50) {} //�ʱⰪ //ǥ��->���� ����

string HealthPotion::getName() const
{
	return name;
}

void HealthPotion::use(Character* character)
{
	Character->restoreHealth(healthRestore); // ĳ���� ü�� �����ε� ���� ����
	cout << name << "���!" << healthRestore << "HP ȸ��" << endl;
}
int HealthPotion::getBuyPrice() const
{
	return buyPrice;
}

int HealthPotion::getSellPrice() const
{
	return sellPrice;
}