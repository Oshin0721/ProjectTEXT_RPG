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
};

#endif