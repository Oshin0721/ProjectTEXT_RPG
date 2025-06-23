#ifndef MONSTER_H
#define MONSTER_H

#include <string>
#include <memory>
#include "../item/Item.h"

// 추상 몬스터 클래스
class Monster {
public:
    virtual ~Monster() = default;

    virtual std::string getName() const = 0;
    virtual int getHealth() const = 0;
    virtual int getAttack() const = 0;
    virtual void takeDamage(int damage) = 0;
    virtual std::unique_ptr<Item> dropItem() = 0;
    virtual int dropGold() const = 0;
};

// Goblin, Orc, Troll의 공통 기반 클래스
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

// Goblin 몬스터
class Goblin : public BasicMonster {
public:
    Goblin(int level);
    std::unique_ptr<Item> dropItem() override;
    int dropGold() const override;
};

// Orc 몬스터
class Orc : public BasicMonster {
public:
    Orc(int level);
    std::unique_ptr<Item> dropItem() override;
    int dropGold() const override;
};

// Troll 몬스터
class Troll : public BasicMonster {
public:
    Troll(int level);
    std::unique_ptr<Item> dropItem() override;
    int dropGold() const override;
};

// BossMonster는 Monster에서 직접 상속
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
