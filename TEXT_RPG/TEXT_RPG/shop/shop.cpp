#include "shop.h"
#include <iostream>
using namespace std;



Shop::Shop(Character* player) : player(player) {
    
    availableItems.push_back(make_unique<HealthPotion>()); 
    availableItems.push_back(make_unique<AttackBoost>()); 

  
}

Shop::Shop() : player(nullptr) {
    // 기본 생성자: player를 nullptr로 초기화
    // 필요한 경우 기본 아이템을 availableItems에 추가할 수 있음
}

void Shop::interact() {
    cout << "상점이 열렸습니다!" << endl;
    cout << "아이템을 구매하거나 판매할 수 있습니다." << endl;
    cout << "상점에서 원하는 작업을 선택하세요." << endl;
    while (true) { // 상점이 열려있는 동안 반복

		cout << "----------------------" << endl;
		cout << "현재 골드: " << player->getGold()<< "G" << endl;
		cout << "----------------------" << endl;
        cout << "1. 아이템 구매" << endl;
        cout << "2. 아이템 판매" << endl;
        cout << "3. 상점 종료" << endl;


        int choice;
        cin >> choice;
        system("cls");
        if (choice == 1) {
            displayItems();
            int itemIndex;
            cout << "----------------------" << endl;
            cout << "현재 골드: " << player->getGold() << "G" << endl;
            cout << "----------------------" << endl;
            cout << "구매할 아이템의 번호를 입력하세요(0:취소): ";

            cin >> itemIndex;
            buyItem(itemIndex - 1); // 인덱스는 0부터 시작하므로 -1
            if (itemIndex == 0) {
                cout << "구매를 취소합니다." << endl;
                continue; 
            }
        }
        else if (choice == 2) {
            if (player->getInventorySize() == 0) {
                cout << "인벤토리에 아이템이 없습니다." << endl;
                continue;
            }
            player->displayInventory();
            int itemIndex;
            cout << "----------------------" << endl;
            cout << "현재 골드: " << player->getGold() << "G" << endl;
            cout << "----------------------" << endl;
            cout << "판매할 아이템의 번호를 입력하세요(0:취소): ";
            cin >> itemIndex;
            sellItem(itemIndex - 1); // 인덱스는 0부터 시작하므로 -1
            if(itemIndex == 0) {
                cout << "판매를 취소합니다." << endl;
                continue; 
			}
        }

        else if (choice == 3) {
            cout << "상점을 종료합니다." << endl;
            break; // 반복 종료
        }
        else {
            cout << "잘못된 선택입니다. 다시 시도하세요." << endl;
		}

    }
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
    system("cls");
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
	
    // subtractGold 함수 필요!
    player->addItem(item->clone());
    player->subtractGold(item->getBuyPrice());
    cout << item->getName() << "을(를) 구매했습니다!\n";
}
void Shop::sellItem(int index)
{
    system("cls");
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
    
	player->addGold(item->getSellPrice());//아이템 판매 가격을 플레이어의 골드에 추가


	player->removeItem(index, true); // 아이템 인벤토리 제거, true -> 판매용 로그 출력

    cout << itemName << "을(를) 판매했습니다!" << endl;
}
