#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <vector>
#include <memory>
#include "../Item/Item.h" // 상대 경로로 수정하여 Item.h 파일을 찾을 수 있도록 설정

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
    
    std::vector<std::unique_ptr<Item>> inventory; // 아이템 인벤토리

    Character(std::string name); // private 생성자, 이름 받아서 초기값 세팅

public:
    static Character* getInstance(std::string name = ""); // 싱글톤 인스턴스 반환, 이름이 없으면 생성 안함

    static void destroyInstance();

    void displayStatus() const;

    void levelUp();
    void addExperience(int exp);
    void addGold(int amount);
    void takeDamage(int damage);
    bool isDead() const;

    void restoreHealth(int amount);       // 체력 회복
    void increaseAttack(int amount);     // 공격력 증가

    void addItem(std::unique_ptr<Item> item);
    void useItem(int index);
    void removeItem(int index); // 추가 : 인벤토리에서 아이템 제거
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

#endif // CHARACTER_H