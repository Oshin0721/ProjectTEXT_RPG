#include "GameManager\GameManager.h"
#include "Character\Character.h"
#include <string>
#include <iostream>
#include "shop/shop.h"
#include <cctype>
using namespace std;


int main()
{
	cout << "====================" << endl;
	cout << "  텍스트 RPG 게임" << endl;
	cout << "====================" << endl;
	cout << "게임을 시작합니다." << endl;
	cout << "====================" << endl;
	cout << "캐릭터 이름을 입력하세요:";
	
	string name;
	cin >> name;
	Character* player = Character::getInstance(name);
	GameManager* gm = new GameManager();
	bool game = true;
	while (game)
	{
		// Battle
		system("cls");
		std::cout << "======== ======== ========" << endl;
		cout << "전투 시작!" << endl;
		std::cout << "======== ======== ========" << endl;
		gm->battle(player);
		if (gm->isDead() || gm->isAllEnemyDefeated()) {   // 구현필요
			if (gm->isDead()) {
				cout << "캐릭터가 죽었습니다. 게임을 종료합니다." << endl;
				break;
			}
			else if (gm->isAllEnemyDefeated()) {
				cout << "모든 적을 처치했습니다!" << endl;
				break;
			}
		}

		// Shop Event
		char choice_shop;
		while (true)
		{
			cout << "상점에 방문시겠습니까? (Y/N) " << endl;
			cin >> choice_shop;

			choice_shop = toupper(choice_shop);

			if (choice_shop == 'Y' || choice_shop == 'N')
			{
				system("cls");
				break;
			}
			else
			{
				system("cls");
				cout << "잘못된 입력입니다. 다시 입력해 주세요" << endl;
			}

		}

		if (choice_shop == 'Y') {
			gm->visitShop(player);
		}

		// Next Stage
		system("cls");
		int choice_stage;
		
		while (true)
		{
			cout << "====================" << endl;
			cout << "1. 캐릭터 상태 보기" << endl;
			cout << "=======================" << endl;
			cout << "2. 인벤토리 보기" << endl;
			cout << "=======================" << endl;
			cout << "3. 전투 계속하기" << endl;
			cout << "=======================" << endl;
			cout << "4. 게임 종료" << endl;
			cout << "=======================" << endl;
			cin >> choice_stage;
			if (choice_stage == 1) {
				system("cls");
				player->displayStatus();
			}
			else if (choice_stage == 2) {
				system("cls");
				player->displayInventory();
			}
			else if (choice_stage == 3) {
				break;
			}
			else if (choice_stage == 4) {
				system("cls");
				cout << "게임 종료" << endl;
				game = false;
				break;
			}
			else
			{
				system("cls");
				cout << "잘못된 입력입니다. 다시 입력해 주세요" << endl;
			}
		}
	}
	delete player;
	delete gm;

	return 0;
}