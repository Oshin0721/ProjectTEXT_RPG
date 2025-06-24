#ifndef ITEM_ATTACKBOOST_H
#define ITEM_ATTACKBOOST_H

#include "Item.h"

class AttackBoost : public Item
{
private:
	std::string name;     //아이템 이름
	int attackIncrease;    //공격력 증가 수치
	int buyPrice;        // 구매 가격
	int sellPrice;       // 판매 가격

public:
	AttackBoost();                           //생성자
	std::string getName() const override;    //이름 반환
	void use(Character* character) override; //효과 적용
	int getBuyPrice() const override;                // 구매 가격 반환
	int getSellPrice() const override;               // 판매 가격 반환
	std::unique_ptr<Item> clone() const override;
};

#endif
