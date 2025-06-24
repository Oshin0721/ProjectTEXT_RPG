#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include "../Character/Character.h"
#include "../Monster/Monster.h"

class GameManager
{
private:

public:
    bool Dead;
    bool clear;
    Monster* generateMonster(int level);
    void battle(Character* player);
    void visitShop(Character* player);
    void displayInventory(Character* player); // displayInventory 메서드 선언 추가
    bool isAllEnemyDefeated();
    bool isDead();
};

#endif