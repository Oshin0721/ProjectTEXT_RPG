#ifndef MONSTER_H
#define MONSTER_H

#include <string>
#include <memory>
#include "../item/Item.h"

class Monster {                                     // Monster는 추상 클래스(모든 몬스터의 공통 기능)
public:
    virtual ~Monster() = default;                   // 다형성을 위한 가상 소멸자
    
    virtual std::string getName() const = 0;        // 이름
    virtual int getHealth() const = 0;              // 체력
    virtual int getAttack() const = 0;              // 공격력
    virtual void takeDamage(int damage) = 0;        // 데미지 처리
    virtual std::unique_ptr<Item> dropItem() = 0;   // 아이템 드랍 함수
    virtual int dropGold() const = 0;              // 골드 드랍 함수
};

class BasicMonster : public Monster {
public:
    BasicMonster(const std::string& name, int level);

    std::string getName() const override;
    int getHealth() const override;
    int getAttack() const override;
    void takeDamage(int damage) override;

protected:
    std::string name;
    int health;
    int attack;
};

// BasicMonster(Goblin, Orc, Troll)와 BossMonster 클래스 선언부
// 각 클래스는 Monster를 상속하며 동일한 구조를 가짐
class BasicMonster : public Monster {
public:
    BasicMonster(const std::string& name, int level);

    std::string getName() const override;
    int getHealth() const override;
    int getAttack() const override;
    void takeDamage(int damage) override;

protected:
    std::string name;
    int health;
    int attack;
    std::unique_ptr<Item> dropItem();
    int dropGold();
};

class BossMonster : public Monster {
public:
    BossMonster(int level);
    std::string getName() const override;
    int getHealth() const override;
    int getAttack() const override;
    void takeDamage(int damage) override;
    std::unique_ptr<Item> dropItem() override;
    int dropGold() const override;

private:
    std::string name;
    int health;
    int attack;
};

#endif
