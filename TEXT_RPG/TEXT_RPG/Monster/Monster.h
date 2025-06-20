#pragma once
#include "../item/Item.h"
#include <string>

using namespace std;

class Monster {                                     // Monster는 추상 클래스(모든 몬스터의 공통 기능)
public:
    virtual string getName() const = 0;             // 이름
    virtual int getHealth() const = 0;              // 체력
    virtual int getAttack() const = 0;              // 공격력
    virtual void takeDamage(int damage) = 0;        // 데미지 처리
    virtual Item* dropItem() = 0;                   // 아이템 드랍 함수
    virtual int dropGold() const = 0;                     // 골드 드랍 함수
    virtual ~Monster() = default;                   // 다형성을 위한 가상 소멸자
};

// Goblin, Orc, Troll, BossMonster 클래스 선언부
// 각 클래스는 Monster를 상속하며 동일한 구조를 가짐
// 레벨 기반으로 생성되기 때문에 생성자에 int level 있음
class Goblin : public Monster {
public:
    Goblin(int level);
    string getName() const override;
    int getHealth() const override;
    int getAttack() const override;
    void takeDamage(int damage) override;
    
    Item* dropItem() override;
    int dropGold() override;

private:
    string name;
    int health;
    int attack;
};

class Orc : public Monster {
public:
    Orc(int level);
    string getName() const override;
    int getHealth() const override;
    int getAttack() const override;
    void takeDamage(int damage) override;
    
    Item* dropItem() override;
    int dropGold() override;

private:
    string name;
    int health;
    int attack;
};

class Troll : public Monster {
public:
    Troll(int level);
    string getName() const override;
    int getHealth() const override;
    int getAttack() const override;
    void takeDamage(int damage) override;
    
    Item* dropItem() override;
    int dropGold() override;

private:
    string name;
    int health;
    int attack;
};

class BossMonster : public Monster {
public:
    BossMonster(int level);
    string getName() const override;
    int getHealth() const override;
    int getAttack() const override;
    void takeDamage(int damage) override;
    
    Item* dropItem() override;
    int dropGold() override;

private:
    string name;
    int health;
    int attack;
};
