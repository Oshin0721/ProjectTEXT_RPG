// Monsters.cpp
#include "Monster.h"
#include "../item/HealthPotion.h"
#include "../item/AttackBoost.h"
#include <random>
#include <cstdlib>      //rand(), srand() �Լ� ����� ���� ���
#include <ctime>        //time() �Լ� ����� ���� ���

using namespace std;

// ���� ���� ���� �Լ�
// ���� ������ ĳ���� ������ ����ؼ� �����ϰ� �����ؾ��ϱ� ������ �ʿ�
int getRandomInRange(int min, int max) {
    static random_device rd;
    static mt19937 gen(rd());                          // ���� ������
    uniform_int_distribution<> dist(min, max);         // �յ� ����
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

//������ ���: 50% Ȯ���� ȸ������, 25�ۼ�Ʈ Ȯ���� ���ݷ� ����, �������� ����
Item* Goblin::dropItem()
{
    int roll = rand() % 100;

    if (roll < 50)
    {
        return new HealthPotion();      //50% Ȯ�� ȸ������ ���
    }
    else if (roll < 75)
    {
        return new AttackBoost();      //25% Ȯ�� ���ݷ� ���� ���
    }
    else
    {
        return nullptr;                 //������ 25% ������ ����
    }
}

// ��� ���: ����� 10~30��� ���
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

//������ ���: 40% ȸ�� ���� 40% ���ݷ� ���� 20% ����
Item* Orc::dropItem()
{
    int roll = rand() % 100;

    if (roll < 40)
    {
        return new HealthPotion();    // 40% Ȯ��
    }
    else if (roll < 80)
    {
        return new AttackBoost();     // 40% Ȯ��
    }
    else
    {
        return nullptr;               // 20% Ȯ�� ����
    }
}

int Orc::dropGold()
{
    return getRandomInRange(10, 40);  // Orc�� 10~40 ��� ���
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

//������ ���: 30% ȸ�� ���� 40% ���ݷ� ���� 20% ����
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
    return getRandomInRange(20, 50);    //��� ���� 20~50���
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

//������ ���: 60%ȸ�� �׿� ���ݷ� ����
Item* BossMonster::dropItem()
{
    int roll = rand() % 100;

    if (roll < 60)
    {
        return new HealthPotion();
    }
    else
    {
        return new AttackBoost();  // Boss�� ������ ������ ���
    }
}

int BossMonster::dropGold()
{
    return getRandomInRange(100, 200);  //100~200������ ���
}