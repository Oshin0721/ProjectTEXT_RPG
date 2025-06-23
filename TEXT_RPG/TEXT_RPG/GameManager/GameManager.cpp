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
	srand(0); //랜덤 값 초기화
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
	Monster* monster = generateMonster(player -> getLevel());  //몬스터 생성
	cout << monster->getName() << " 등장" << endl;  //몬스터 생성 알림
	
	while (monster->getHealth() == 0 || player->getHealth() == 0) //전투 시스템
	{
		//공격 주고 받기
		monster->takeDamage(player->getAttack());  //플레이어가 공격할때
		cout << player->getName << "이(가)" << monster << "을(를) 공격했습니다. 체력: " << player->getHealth << endl;

		if (player->getHealth() <= player->maxHealth*0.5)  //아이템 사용 시스템 //맥스헬스가 프라이빗이라 접근 안됨
		{
			HealthPotion->use(Character* player);
		}
		else if (player->getHealth() <= player->maxHealth*0.75)
		{
			Attackboost->use(Character* player);
		};

		if (monster->getHealth() == 0)  //승리 선언
		{
			cout << monster->getName() << "와(과) 싸움에서 승리했다!" << endl;
			delete monster;   //몬스터 삭제
			int gold = 100;
			player->addGold(gold);
			Item* item = monster->dropItem();
			if (item != nullptr)
			{
				player->addItem(item);
			}
			player->addExperience(50);   //임의의 숫자 50 레벨업 하기
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
	for (Item* item : player->getInventory()) //겟 인벤토리 없음 사이즈만 있음
	{
		cout << item ->getName() << endl;
	}
}
void GameManager::visitShop(Character* player)
{
	while (true)
	{
		cout << "상점에 왔습니다." << endl;
		cout << "보유 골드:" << player->getGold() << endl;
		cout << "1. 회복 물약 구매" << endl;
		cout << "2. 회복 물약 판매" << endl;
		cout << "3. 공격력 강화 구매" << endl;
		cout << "4. 공격력 강화 판매" << endl;
		cout << "5. 상점 나가기" << endl;
		int choice = 0;
		cin >> choice;
		if (choice == 1)
		{
			player->setgold (player->getGold() - HealthPotion->getBuyPrice(20)); //셋 골드 없음
			cout << "구매 완료. 남은 골드 " << gold << endl;
			player->addItem(new HealthPotion);
		}
		else if (choice == 2)
		{
			player->setgold (player->getGold() + HealthPotion->getBuyPrice(20)); //셋 골드 없음
			cout << "판매 완료. 남은 골드 " << gold << endl;
			player->removeItem(HealthPotion);
		}
		else if (choice == 3)
		{
			player->setgold (player->getGold() - AttackBoost->getBuyPrice(30)); //셋 골드 없음
			cout << "구매 완료. 남은 골드 " << gold << endl;
			player->addItem(new AttackBoost);
		}
		else if (choice == 4)
		{
			player->setgold (player->getGold() + AttackBoost->getBuyPrice(30)); //셋 골드 없음
			cout << "판매 완료. 남은 골드 " << gold << endl;
			player->removeItem()Item(AttackBoost);
		}
		else if (choice == 5)
		{
			return false;
		}
	}
}
