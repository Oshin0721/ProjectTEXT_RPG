#ifndef SHOP_H  
#define SHOP_H  

#include <string>  
#include <vector>  
#include <memory> // 추가: unique_ptr를 사용하기 위해 필요
#include "../Item/Item.h" // 상대 경로로 수정하여 Item.h 파일을 올바르게 참조
#include "../Item/HealthPotion.h"
#include "../Item/AttackBoost.h" // 상대 경로로 수정하여 AttackBoost.h 파일을 올바르게 참조
#include "../Character/Character.h" // 상대 경로로 수정하여 Character.h 파일을 올바르게 참조



class Shop {
private:
    std::vector<std::unique_ptr<Item>> availableItems; // std::를 추가하여 네임스페이스 명시
    Character* player;

public:
    Shop(Character* player);
    void displayItems() const;
    void buyItem(int index);
    void sellItem(int index);
    void interact();
    

};

#endif // SHOP_H
