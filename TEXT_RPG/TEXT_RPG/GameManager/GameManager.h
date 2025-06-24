#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

class Character;

class GameManager
{
private:

public:
    Monster* generateMonster(int level);
    void battle(Character* player);
    void visitShop(Character* player);
    void displayInventory(Character* player); // displayInventory 메서드 선언 추가
};

#endif