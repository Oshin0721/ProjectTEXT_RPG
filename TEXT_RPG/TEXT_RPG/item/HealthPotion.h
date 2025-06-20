#ifndef ITEM_HEALTHPOTION_H
#define ITEM_HEALTHPOTION_H

#include "Item.h"

class HealthPotion : public Item
{
private:
	std::string name;       //아이템 이름
	int healthRestore;      //회복할 수치

public:
	HealthPotion();         //생성자
	std::string getName() const override;  //이름 반환
	void use(Character* character) override;
};

#endif