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
void Shop::buyItem(int index, Character* player) {
	if (index < 0 || index >= availableItems.size()) {
		cout << "잘못된 아이템 선택입니다." << endl;
		return;
	}
	auto& item = availableItems[index];
	if (player.getGold() < item->getbuyprice()) {
		cout << "골드가 부족합니다." << endl;
		return;
	}
	Character.addItem(item->clone()); // 아이템을 플레이어에게 추가
	Character.setGold(player.getGold() - item->getbuyprice()); // 골드 차감
	cout << item->getName() << "을(를) 구매했습니다!" << endl;
}
void Shop::sellItem(int index, Character* player) {   //캐릭터 클래스 필요함
	if (index < 0 || index >= player.getItems().size()) {
		cout << "잘못된 아이템 선택입니다." << endl;
		return;
	}
	auto& item = player.getItems()[itemIndex];
	player.setGold(player.getGold() + item->getsellprice()); // 골드 증가
	player.removeItem(itemIndex); // 아이템 제거
	cout << item->getName() << "을(를) 판매했습니다!" << endl;
}