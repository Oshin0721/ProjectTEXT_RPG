#include "AttackBoost.h"
#include ""//���� ĳ���� Ŭ������ ����

#include <iostream>

using namespace std;

AttackBoost::AttackBoost()
	: name("���ݷ� ��ȭ"), attackIncrease(10) {} // ���ݷ� ���� �ʱⰪ //����->��ȭ ����

string AttackBoost::getName() const // ������ �̸� ��ȯ
{
	return name;
}

void AttackBoost::use(Character* character)
{
	character->increaseAttack(attackIncrease); //���ݷ�����
	cout << name << "��� +" << attackIncrease << "���ݷ� ���� �Ϸ�" << endl;
}

int AttackBoost::getBuyPrice() const
{
	return buyPrice;
}

int AttackBoost::getSellPrice() const
{
	return sellPrice;
}