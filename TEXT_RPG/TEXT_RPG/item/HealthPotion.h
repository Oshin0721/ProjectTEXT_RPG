#ifndef ITEM_HEALTHPOTION_H
#define ITEM_HEALTHPOTION_H

#include "Item.h"
#include "../Character/Character.h"

class HealthPotion : public Item
{
private:
	std::string name;       //아이템 이름
	int healthRestore;      //회복할 수치
	int buyPrice;           // 구매 가격
	int sellPrice;          // 판매 가격

public:
	HealthPotion();         //생성자
	
	std::string getName() const override;  //이름 반환
	void use(Character* character) override;
	int getBuyPrice() const override;                // 구매 가격 반환
	int getSellPrice() const override;               // 판매 가격 반환
	std::unique_ptr<Item> clone() const override;
};

#endif