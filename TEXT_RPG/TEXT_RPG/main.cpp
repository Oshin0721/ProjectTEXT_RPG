#include "GameManager\GameManager.h"
#include "Character\Character.h"
#include <string>
#include <iostream>
#include "shop/shop.h"
#include "LogManager/LogManager.h"
#include <cctype>
#include <limits>
using namespace std;


int main()
{
	cout << "====================" << endl;
	cout << "  텍스트 RPG 게임" << endl;
	cout << "====================" << endl;
	cout << " 게임을 시작합니다." << endl;
	cout << "====================" << endl;
	cout << "캐릭터 이름을 입력하세요:";
	
	string name;
	cin >> name;
	Character* player = Character::getInstance(name);
	GameManager* gm = new GameManager();
	bool game = true;
	srand(time(0)); //제너레이트 몬스터 할때 랜덤값 초기화 해주는 코드
	while (game)
	{
		// Battle
		system("cls");
		std::cout << "======== ======== ========" << endl;
		cout << "전투 시작!" << endl;
		std::cout << "======== ======== ========" << endl;
		gm->battle(player);
		if (gm->isDead() || gm->isAllEnemyDefeated()) {    //isALlEnemyDegeated 사용 안됨. 꼭 필요한가?
			if (gm->isDead()) {
				cout << player->getName() << "이(가) 죽었습니다. 게임을 종료합니다." << endl;
				break;
			}
			else if (gm->isAllEnemyDefeated()) {   //사용 안됨
				cout << "모든 적을 처치했습니다. 승리!!!" << endl;
				break;
			}
		}
		cout << "====================" << endl;
		cout << "계속하려면 Enter 키를 누르세요...";

		// 이전 입력 버퍼에 남아있는 개행문자 등 모두 비우기
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		char ch = cin.get();

		if (ch != '\n') {
			// 남은 입력 모두 비우기
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "잘못된 입력입니다.\n";
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
			cout << "4. 상점 방문" << endl;
			cout << "=======================" << endl;
			cout << "5. 게임 종료" << endl;
			cout << "=======================" << endl;
			cin >> choice_stage;

			// 입력값이 숫자가 아닐 경우 처리
			if (cin.fail()) {
				cin.clear(); // 입력 스트림 오류 상태 초기화
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 버퍼 비우기
				system("cls");
				cout << "잘못된 입력입니다. 숫자를 입력해 주세요." << endl;
				continue;
			}
			if (choice_stage == 1) {
				system("cls");
				player->displayStatus();
			}
			else if (choice_stage == 2) {
				system("cls");
				player->displayInventory();
				cout << "계속하려면 Enter 키를 누르세요...";
				cin.ignore(); // 이전 입력 버퍼 제거
				cin.get();    // Enter 키 대기

				system("cls"); // 화면 정리
				
			}
			else if (choice_stage == 3) {
				break;
			}
			else if (choice_stage == 4) {
				system("cls");
				gm->visitShop(player);
			}
			else if (choice_stage == 5) {
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

	cout << "엔딩 크레딧(Enter)" << endl;
	while (true)
	{
		cin.ignore(); // 이전 입력 버퍼 제거
		if (cin.get()) break;
	}
	system("cls");
	LogManager::getInstance()->PrintAllLogsSlow();
	
	delete player;
	delete gm;

	return 0;
}