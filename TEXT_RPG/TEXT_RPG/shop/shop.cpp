#include "shop.h"
#include <iostream>
using namespace std;



Shop::Shop(Character* player) : player(player) {
    
    availableItems.push_back(make_unique<HealthPotion>("기본 체력 포션", 50)); // 이름, 가격, 
    availableItems.push_back(make_unique<AttackBoost>("공격력 증가 물약", 70)); // 이름, 가격, 

    //interact() 함수로 이동
	cout << "상점이 열렸습니다!" << endl;
	cout << "아이템을 구매하거나 판매할 수 있습니다." << endl;
	cout << "상점에서 원하는 작업을 선택하세요." << endl;
	cout << "1. 아이템 구매" << endl;
	cout << "2. 아이템 판매" << endl;
	cout << "3. 상점 종료" << endl;


	int choice;
	cin >> choice;
    if(choice == 1) {
        displayItems();
        int itemIndex;
        cout << "구매할 아이템의 번호를 입력하세요: ";
        cin >> itemIndex;
        buyItem(itemIndex - 1); // 인덱스는 0부터 시작하므로 -1
    } else if (choice == 2) {
        if (player->getInventorySize() == 0) {
            cout << "인벤토리에 아이템이 없습니다." << endl;
            return;
        }
        player->displayInventory();
        int itemIndex;
        cout << "판매할 아이템의 번호를 입력하세요: ";
        cin >> itemIndex;
        sellItem(itemIndex - 1); // 인덱스는 0부터 시작하므로 -1
    } else if (choice == 3) {
        cout << "상점을 종료합니다." << endl;
    } else if (choice == 44){
        cout << "관리자 코드입니다" << endl;

	}   


	
	// 초기화 작업이 필요하다면 여기에 작성
}

void Shop::shopClose() {
    cout << "상점을 종료합니다." << endl;
}

void Shop::displayItems() const {
	cout << "상점에 있는 아이템 목록:" << endl;
	if (availableItems.empty()) {
		cout << "아이템이 없습니다." << endl;
        cout << "----------------------" << endl;
		return;

	}
	for (int i = 0; i < availableItems.size(); ++i) {
		cout << i + 1 << ". " << availableItems[i]->getName() << " - 가격: " << availableItems[i]->getBuyPrice() << endl;
	}
}
void Shop::buyItem(int index) 
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
	
    
    player->addItem(item.get());
    player->addGold(-item->getBuyPrice());
    cout << item->getName() << "을(를) 구매했습니다!\n";
}
void Shop::sellItem(int index)
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
    string itemName = item->getName(); // 안전하게 이름만 복사
    
	player->addGold(player->getGold() + item->getSellPrice());//아이템 판매 가격을 플레이어의 골드에 추가


	player->removeItem(index);//아이템을 인벤토리에서 제거 추가 해주시면 감사합니다.

    cout << itemName << "을(를) 판매했습니다!" << endl;
}
