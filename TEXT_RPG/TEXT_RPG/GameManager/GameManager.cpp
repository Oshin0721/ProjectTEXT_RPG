#include <iostream>
#include <cstdlib> // rand(), srand()
#include <ctime>
#include "GameManager.h"

#include "../Character/Character.h"
#include "../item/AttackBoost.h"
#include "../item/HealthPotion.h"
#include "../Monster/Monster.h"
#include "../shop/shop.h"


Monster* GameManager::generateMonster(int level)
{
	srand(time(0)); //랜덤 값 초기화
	int random = rand() % 3;  //랜덤한 수를 3으로 모듈러해서 1,2,3만 생성

	if (random == 0)
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
	else if (level == 10)
	{
		return new BossMonster(level);
	}
}
void GameManager::battle(Character* player)
{
	// 몬스터 생성
	Monster* monster = generateMonster(player -> getLevel());
	std::cout << monster->getName() << " 등장! 체력: " << monster->getHealth() << ", 공격력 : " << monster->getAttack() << std::endl;  //몬스터 생성 알림
	
	// 전투 시스템
	while (monster->getHealth() > 0 && player->getHealth() > 0)
	{
		// 플레이어가 공격
		monster->takeDamage(player->getAttack());
		std::cout << player->getName() << "이(가) " << monster->getName() << "을(를) 공격했습니다. 남은 체력: " << monster->getHealth() << std::endl;

		if (player->getHealth() <= player->getMaxHealth()*0.5 && player->getItem(HealthPotion))  //아이템 사용 시스템 
		{
			HealthPotion->use(Character* player);
		}
		else if (player->getHealth() <= player->getMaxHealth()*0.75 && player->getItem(AttackBoost))
		{
			AttackBoost->use(Character* player);
		};

		if (monster->getHealth() == 0)  //승리 선언
		{
			cout << monster->getName() << "와(과) 싸움에서 승리했다!" << endl;
			delete monster;   //몬스터 삭제
			int gold = 100;   //골드 얻기 숫자 조절
			player->addGold(gold);
			Item* item = monster->dropItem();
			if (item != nullptr)
			{
				player->addItem(item);
			}
			player->addExperience(50);   //임의의 숫자 50 경험치 얻기//여기 숫자 조절하기
			if (player->getExperience(100))  //100이 되면 레벨업
			{
				player->levelUp();
			}
			cout << player->getName() << "이(가)" << gold << "골드," << item->getName() << "을(를) 획득했다." << endl;
			break;
		}
		
		player->takeDamage(monster->getAttack());   //몬스터가 공격할 때
		cout << monster << "이(가)" << player->getName() << "을(를) 공격했습니다. 체력: " << monster->getHealth() << endl;
		
		if (player->getHealth() == 0)
		{
			cout << "사망" << endl;
		};
		
	}
}

void GameManager::displayInventory(Character* player)
{
	player->displayInventory();
}

void GameManager::visitShop(Character* player)
{
	Shop->interact();
}
