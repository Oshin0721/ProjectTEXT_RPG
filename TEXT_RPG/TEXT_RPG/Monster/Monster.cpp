// Monsters.cpp
#include "Monster.h"
#include "../item/HealthPotion.h"
#include "../item/AttackBoost.h"
#include "../LogManager/LogManager.h"
#include <random>
// #include <cstdlib>      //rand(), srand() 함수 사용을 위한 헤더 -> Monster.cpp에서 사용안함
// #include <ctime>        //time() 함수 사용을 위한 헤더 -> Monster.cpp에서 사용안함

using namespace std;

// 공통 랜덤 생성 함수
// 몬스터 스펙을 캐릭터 레벨에 비례해서 랜덤하게 생성해야하기 때문에 필요
int getRandomInRange(int min, int max) {
    static random_device rd;
    static mt19937 gen(rd());                          // 난수 생성기
    uniform_int_distribution<> dist(min, max);         // 균등 분포
    return dist(gen);
}

// BasicMonster 구현
BasicMonster::BasicMonster(const std::string& name_, int level)
    : name(name_)

{
    health = getRandomInRange(level * 30, level * 30);
    attack = getRandomInRange(level * 20, level * 20);
}

std::string BasicMonster::getName() const { return name; }
int BasicMonster::getHealth() const { return health; }
int BasicMonster::getAttack() const { return attack; }

void BasicMonster::takeDamage(int damage) {
    // Logging
    LogManager::getInstance()->AddGiveDamageLog(damage);
    health -= damage;
    if (health < 0) health = 0;
}

// Goblin
Goblin::Goblin(int level) : BasicMonster("Goblin", level) {}

//아이템 드랍: 75% 확률은 회복포션, 25퍼센트 확률은 공격력 증가, 나머지는 없음
std::unique_ptr<Item> Goblin::dropItem() {
    int roll = getRandomInRange(0, 99);
    if (roll < 75)
    { 
        return std::make_unique<HealthPotion>(); 
    }
    else
    {
        return std::make_unique<AttackBoost>();
    }
}

// 골드 드랍: 고블린은 5~10골드 드랍
int Goblin::dropGold() const {
    return getRandomInRange(5, 10);
}

// Orc
Orc::Orc(int level) : BasicMonster("Orc", level) {}

//아이템 드랍: 50% 회복 포션 50% 공격력 증가
std::unique_ptr<Item> Orc::dropItem() {
    int roll = getRandomInRange(0, 99);
    if (roll < 50)
    {
        return std::make_unique<HealthPotion>();
    }
    else
    {
        return std::make_unique<AttackBoost>();
    }
}

// Orc는 10~20 골드 드랍
int Orc::dropGold() const {
    return getRandomInRange(10, 20);
}

// Troll
Troll::Troll(int level) : BasicMonster("Troll", level) {}

//아이템 드랍: 10% 회복 포션 10% 공격력 증가 80% 없음
std::unique_ptr<Item> Troll::dropItem() {
    int roll = getRandomInRange(0, 99);
    if (roll < 10)
    {
        return std::make_unique<HealthPotion>();
    }
    else if (roll < 20)
    {
        return std::make_unique<AttackBoost>();
    }
    else
    {
        return nullptr;
    }
}

//골드 범위 50~80골드
int Troll::dropGold() const {
    return getRandomInRange(50, 80);
}

// BossMonster
BossMonster::BossMonster(int level) : name("Dragon") {
    health = getRandomInRange(level * 60, level * 80);
    attack = getRandomInRange(level * 60, level * 80);
}

std::string BossMonster::getName() const { return name; }
int BossMonster::getHealth() const { return health; }
int BossMonster::getAttack() const { return attack; }

void BossMonster::takeDamage(int damage) {
    // Logging
    LogManager::getInstance()->AddGiveDamageLog(damage);
    health -= damage;
    if (health < 0) health = 0;
}

//아이템 드랍: 60%회복 그외 공격력 증가(Boss는 무조건 아이템 드랍)
std::unique_ptr<Item> BossMonster::dropItem() {
    int roll = getRandomInRange(0, 99);
    if (roll < 60) return std::make_unique<HealthPotion>();
    else return std::make_unique<AttackBoost>();
}

//100~200골드사이 드랍
int BossMonster::dropGold() const {
    return getRandomInRange(150, 250);
}
