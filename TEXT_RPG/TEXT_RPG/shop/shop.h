#ifndef SHOP_H  
#define SHOP_H  


#include <string>  
#include <vector>  
#include "../Item/Item.h" // 상대 경로로 수정하여 Item.h 파일을 올바르게 참조
#include "../Item/HealthPotion.h"
#include "../Item/AttackBoost.h" // 상대 경로로 수정하여 AttackBoost.h 파일을 올바르게 참조




class Character; // 아직 없어서 전방 선언 해놓은 것임  



class Shop {
private:
    vector<unique_ptr<Item>> availableItems;
public:
    void displayItems()const;
    void buyItem(int index, Character* player);
    void sellItem(int index, Character* player);
    Shop();
};

#endif // SHOP_H
