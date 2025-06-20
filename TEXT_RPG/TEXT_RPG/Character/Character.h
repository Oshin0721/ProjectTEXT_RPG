#pragma once
#include <string>
#include <vector>
#include "../item/Item.h" // 아이템 클래스 사용 위해서

class Character {
private:
    static Character* instance; // 싱글톤 인스턴스
    std::string name;
    int level;
    int health;
    int maxHealth;
    int attack;
    int experience;
    int gold;
    std::vector<Item*> inventory; // 아이템 인벤토리

    Character(std::string name); // private 생성자, 이름 받아서 초기값 세팅

public:
    static Character* getInstance(std::string name = ""); // 싱글톤 인스턴스 반환, 이름이 없으면 생성 안함

    void displayStatus() const;
    void levelUp();
    void addExperience(int exp);
    void addGold(int amount);
    void takeDamage(int damage);
    bool isDead() const;

    void addItem(Item* item);
    void useItem(int index);
    void visitShop();

    std::string getName() const;
    int getHealth() const;
    int getAttack() const;
    int getLevel() const;
    int getGold() const;
    int getExperience() const;
    int getInventorySize() const;
    Item* getItem(int index);
};

