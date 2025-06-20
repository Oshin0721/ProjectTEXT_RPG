#ifndef SHOP_H  
#define SHOP_H  

#include <string>  
#include <vector>  
#include <memory> // �߰�: unique_ptr�� ����ϱ� ���� �ʿ�
#include "../Item/Item.h" // ��� ��η� �����Ͽ� Item.h ������ �ùٸ��� ����
#include "../Item/HealthPotion.h"
#include "../Item/AttackBoost.h" // ��� ��η� �����Ͽ� AttackBoost.h ������ �ùٸ��� ����



class Shop {
private:
    std::vector<std::unique_ptr<Item>> availableItems; // std::�� �߰��Ͽ� ���ӽ����̽� ���
public:
    void displayItems() const;
    void buyItem(int index, Character* player);
    void sellItem(int index, Character* player);
    Shop();
};

#endif // SHOP_H
