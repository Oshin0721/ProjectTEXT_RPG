#ifndef ITEM_H
#define ITEM_H

#include <string>

class Character; //정의할 Character 클래스 참조만 하기위한 선언

class Item //모든 아이템 공통 인터페이스 정의(추상클래스)
{
public:
	virtual ~Item() {} //소멸자(메모리 누수 방지)
	virtual std::string getName() const = 0; //아이템 이름을 반환하는 순수 가상 함수
	virtual void use(Character* character) = 0; //캐릭터에게 아이템을 사용할 때 호출되는 함수
	virtual int getBuyPrice() const = 0;   // 구매 가격을 정수로 반환 (Shop 등에서 사용)
	virtual int getSellPrice() const = 0;  // 판매 가격을 정수로 반환 (판매 시 사용)
};


#endif