#ifndef ITEM_HEALTHPOTION_H
#define ITEM_HEALTHPOTION_H

#include "Item.h"

class HealthPotion : public Item
{
private:
	std::string name;       //������ �̸�
	int healthRestore;      //ȸ���� ��ġ
	int buyPrice;           // ���� ����
	int sellPrice;          // �Ǹ� ����

public:
	HealthPotion();         //������
	std::string getName() const override;  //�̸� ��ȯ
	void use(Character* character) override;
	int getBuyPrice() const override;                // ���� ���� ��ȯ
	int getSellPrice() const override;               // �Ǹ� ���� ��ȯ
};

#endif