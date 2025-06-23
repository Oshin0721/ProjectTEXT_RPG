// Monsters.cpp
#include "../Monster/Monster.h"
#include "../item/HealthPotion.h"
#include "../item/AttackBoost.h"
#include <random>
#include <cstdlib>      //rand(), srand() 함수 사용을 위한 헤더
#include <ctime>        //time() 함수 사용을 위한 헤더

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

//아이템 드랍: 50% 확률은 회복포션, 25퍼센트 확률은 공격력 증가, 나머지는 없음
Item* Goblin::dropItem()
{
    int roll = rand() % 100;

    if (roll < 50)
    {
        return new HealthPotion();      //50% 확률 회복포션 드랍
    }
    else if (roll < 75)
    {
        return new AttackBoost();      //25% 확률 공격력 증가 드랍
    }
    else
    {
        return nullptr;                 //나머지 25% 아이템 없음
    }
}

// 골드 드랍: 고블린은 10~30골드 드랍
int Goblin::dropGold() {
    return getRandomInRange(5, 25);
}

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

//아이템 드랍: 40% 회복 포션 40% 공격력 증가 20% 없음
Item* Orc::dropItem()
{
    int roll = rand() % 100;

    if (roll < 40)
    {
        return new HealthPotion();    // 40% 확률
    }
    else if (roll < 80)
    {
        return new AttackBoost();     // 40% 확률
    }
    else
    {
        return nullptr;               // 20% 확률 없음
    }
}

int Orc::dropGold()
{
    return getRandomInRange(10, 40);  // Orc는 10~40 골드 드랍
}

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

//아이템 드랍: 30% 회복 포션 40% 공격력 증가 20% 없음
Item* Troll::dropItem()
{
    int roll = rand() % 100;

    if (roll < 30)
    {
        return new HealthPotion();
    }
    else if (roll < 70)
    {
        return new AttackBoost();
    }
    else
    {
        return nullptr;
    }
}

int Troll::dropGold()
{
    return getRandomInRange(20, 50);    //골드 범위 20~50골드
}

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

//아이템 드랍: 60%회복 그외 공격력 증가
Item* BossMonster::dropItem()
{
    int roll = rand() % 100;

    if (roll < 60)
    {
        return new HealthPotion();
    }
    else
    {
        return new AttackBoost();  // Boss는 무조건 아이템 드랍
    }
}

int BossMonster::dropGold()
{
    return getRandomInRange(100, 200);  //100~200골드사이 드랍
}
