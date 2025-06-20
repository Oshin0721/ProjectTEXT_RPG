#include "shop.h"
#include <iostream>
using namespace std;



Shop::Shop() {
	cout << "상점이 열렸습니다!" << endl;
	cout << "아이템을 구매하거나 판매할 수 있습니다." << endl;
	cout << "상점에서 원하는 작업을 선택하세요." << endl;


	availableItems.push_back(make_unique<HealthPotion>("기본 체력 포션", 50)); // 이름, 가격, 
	availableItems.push_back(make_unique<AttackBoost>("공격력 증가 물약", 70)); // 이름, 가격, 
	// 초기화 작업이 필요하다면 여기에 작성
}

void Shop::displayItems() const {
	cout << "상점에 있는 아이템 목록:" << endl;
	for (availableItems.empty()) {
		cout << "아이템이 없습니다." << endl;
		return;

	}
	for (int i = 0; i < availableItems.size(); ++i) {
		cout << i + 1 << ". " << availableItems[i]->getName() << " - 가격: " << availableItems[i]->getbuyprice() << endl;
	}
}
void Shop::buyItem(int index, Character* player) 
{  
    if (index < 0 || index >= availableItems.size())
    {  
        cout << "잘못된 아이템 선택입니다." << endl;  
        return;  
    }  
    auto& item = availableItems[index];  
    if (player->getGold() < item->getBuyPrice())
    {  
        cout << "골드가 부족합니다." << endl;  
        return;  
    }  
	int thistimegold = player->getGold();
    
    player->addItem(item.get());  
	player->addGold(player->getGold()- player->getGold());
    player->addGold(thistimegold - item->getBuyPrice());  
    cout << item->getName() << "을(를) 구매했습니다!" << endl;  
}
void Shop::sellItem(int index, Character* player)
{    
    if (index < 0 || index >= player->getInventorySize())
    { 
        cout << "잘못된 아이템 선택입니다." << endl;
        return;
    }
    if (player->getInventorySize() == 0) {
        cout << "인벤토리에 아이템이 없습니다." << endl;
        return;
    }

    
	Item* item = player->getItem(index); //아이템 인벤토리에서 가져오기

    
	player->addGold(player->getGold() + item->getSellPrice());//아이템 판매 가격을 플레이어의 골드에 추가


	player->removeItem(index);//아이템을 인벤토리에서 제거 추가 해주시면 감사합니다.

    cout << item->getName() << "을(를) 판매했습니다!" << endl;
}