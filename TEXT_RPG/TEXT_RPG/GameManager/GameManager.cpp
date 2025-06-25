#include <iostream>
#include <cstdlib> // rand(), srand()
#include <ctime>
#include <thread>
#include <chrono>

#include "../GameManager/GameManager.h"
#include "../Character/Character.h"
#include "../item/AttackBoost.h"
#include "../item/HealthPotion.h"
#include "../Monster/Monster.h"
#include "../shop/shop.h"
#include "../LogManager/LogManager.h"

using namespace std;

Monster* GameManager::generateMonster(int level)
{
	//srand(time(0)); //랜덤값이 잘 안나와서 메인에서 초기화 해야할듯
	int random = rand() % 3;  //랜덤한 수를 3으로 모듈러해서 1,2,3만 생성

	if (level == 10)
	{
	    return new BossMonster(level);
	}
	else if (random == 0)
	{
		return new Goblin(level);
	}
	else if (random == 1)
	{
		return new Orc(level);
	}
	else if (random == 2)
	{
		return new Troll(level);
	}
	else
	{
		return nullptr; //의도하지 않은 상황일 때
	}

}


void GameManager::battle(Character* player)
{
	
	// 몬스터 생성
	Monster* monster = generateMonster(player -> getLevel());
	SimpleScrollLine(monster->getName() + " 등장! 체력: " + to_string(monster->getHealth()) + ", 공격력 : " + to_string(monster->getAttack()));
	cout <<"======== ======== ========" << endl;

	// 전투 시스템
	while (monster->getHealth() > 0 && player->getHealth() > 0)
	{
		// 체력 50% 이하 -> 힐 아이템 사용 (인벤토리 자동 탐색)
		if (player->getHealth() <= player->getMaxHealth() * 0.5)
		{
			for (int i = 0; i < player->getInventorySize(); i++)
			{
				Item* item = player->getItem(i);
				if (item->getName() == "회복 물약")
				{
					// Logging
					LogManager::getInstance()->AddItemLog(item);
					SimpleScrollLine("[아이템 사용] " + item->getName());
					item->use(player);
					player->removeItem(i);
					break;
				}
			}
		}
		// 체력 75% 이하? 
		else if (player->getHealth() <= player->getMaxHealth() * 0.75)
		{
			for (int i = 0; i < player->getInventorySize(); i++)
			{
				Item* item = player->getItem(i);
				if (item->getName() == "공격력 강화")
				{
					// Logging
					LogManager::getInstance()->AddItemLog(item);
					SimpleScrollLine("[아이템 사용] " + item->getName());
					item->use(player);
					player->removeItem(i); // 아이템 사용 로그 출력
					break;
				}
			}
		}

		// 플레이어가 공격
		monster->takeDamage(player->getAttack());
		SimpleScrollLine(player->getName() + "이(가) " + monster->getName() + "을(를) 공격했습니다." + monster->getName() + "의 남은 체력 : " + to_string(monster->getHealth()));
		std::cout << "======== ======== ========" << endl;

		// 몬스터 죽음 체크
		if (monster->getHealth() <= 0)
		{
			// Logging
			LogManager::getInstance()->AddMonsterLog(monster);
			if (monster->getName() == "Dragon")
			{
				clear = true;
				break;
			}
			SimpleScrollLine(monster->getName() + "와(과) 싸움에서 승리했다!");
			std:: cout << "======== ======== ========" << endl;
			int gold = monster->dropGold();   //몬스터에 따라서 골드 획득

			// 캐릭터 상태 명시
			SimpleScrollLine(player->getName() + "이(가) 50 EXP와 " + to_string(gold) + " 골드를 획득했습니다!");
			std::cout << "======== ======== ========" << endl;
			player->addGold(gold);
			player->addExperience(50);   //임의의 숫자 50 경험치 얻기 //여기 숫자 조절하기
			if (player->getExperience() == 100)  //100이 되면 레벨업
			{
				player->levelUp();
			}


			// 아이템 드랍
			std::unique_ptr<Item> dropped = monster->dropItem();
			if (dropped) {
				//std::cout << dropped->getName() << " 아이템을 획득했습니다!" << std::endl;
				//std::cout << "======== ======== ========" << endl;
				player->addItem(std::move(dropped));
				
				
			}
			
			delete monster;
			break;
		}
		
		player->takeDamage(monster->getAttack());   //몬스터가 공격할 때
		SimpleScrollLine(monster->getName() + "이(가) " + player->getName() + "을(를) 공격했습니다." + player->getName() + "의 남은 체력 : " + to_string(player->getHealth()));
		std:: cout << "======== ======== ========" << endl;

		if (player->getHealth() <= 0)
		{

			delete monster;
			Dead = true;
			break;
		};
		
	}
}
bool GameManager::isAllEnemyDefeated()
{
	return clear;
}
bool GameManager::isDead()
{
	return Dead;
}
void GameManager::displayInventory(Character* player)
{
	player->displayInventory();
}

void GameManager::visitShop(Character* player)
{
    Shop shop(player); // Shop 객체 생성 시 player 전달
    shop.interact();   // Shop과 상호작용
}
