// Monsters.cpp
#include "Monster.h"
#include <random>

using namespace std;

// 공통 랜덤 생성 함수
// 몬스터 스펙을 캐릭터 레벨에 비례해서 랜덤하게 생성해야하기 때문에 필요
int getRandomInRange(int min, int max) {
    static random_device rd;
    static mt19937 gen(rd());                          // 난수 생성기
    uniform_int_distribution<> dist(min, max);         // 균등 분포
    return dist(gen);
}

// Goblin
Goblin::Goblin(int level) {
    name = "Goblin";
    health = getRandomInRange(level * 20, level * 30);
    attack = getRandomInRange(level * 5, level * 10);
}

string Goblin::getName() const { return name; }
int Goblin::getHealth() const { return health; }
int Goblin::getAttack() const { return attack; }

void Goblin::takeDamage(int damage) {
    health -= damage;
    if (health < 0) health = 0;
}

//Item* Goblin::dropItem() {
//    return new Item("Goblin Tooth");
//}

// Orc
Orc::Orc(int level) {
    name = "Orc";
    health = getRandomInRange(level * 20, level * 30);
    attack = getRandomInRange(level * 5, level * 10);
}

string Orc::getName() const { return name; }
int Orc::getHealth() const { return health; }
int Orc::getAttack() const { return attack; }

void Orc::takeDamage(int damage) {
    health -= damage;
    if (health < 0) health = 0;
}

//Item* Orc::dropItem() {
//    return new Item("Orc Axe");
//}

// Troll
Troll::Troll(int level) {
    name = "Troll";
    health = getRandomInRange(level * 20, level * 30);
    attack = getRandomInRange(level * 5, level * 10);
}

string Troll::getName() const { return name; }
int Troll::getHealth() const { return health; }
int Troll::getAttack() const { return attack; }

void Troll::takeDamage(int damage) {
    health -= damage;
    if (health < 0) health = 0;
}

//Item* Troll::dropItem() {
//    return new Item("Troll Club");
//}

// BossMonster
BossMonster::BossMonster(int level) {
    name = "BossMonster";
    health = getRandomInRange(level * 30, level * 40);
    attack = getRandomInRange(level * 10, level * 15);
}

string BossMonster::getName() const { return name; }
int BossMonster::getHealth() const { return health; }
int BossMonster::getAttack() const { return attack; }

void BossMonster::takeDamage(int damage) {
    health -= damage;
    if (health < 0) health = 0;
}

//Item* BossMonster::dropItem() {
//    return new Item("Boss Core");
//}
