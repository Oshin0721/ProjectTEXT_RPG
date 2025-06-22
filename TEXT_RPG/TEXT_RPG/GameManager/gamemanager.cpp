#include <iostream>
#include <cstdlib> // rand(), srand()
#include "GameManager.h"
#include "../Character/Character.h"
#include "../item/HealthPotion.h"
#include "../Monster/Monster.h"


Monster* GameManager::generateMonster()
{
	srand(0); //랜덤 값 초기화
	int random = rand() % 3;  //랜덤한 수를 3으로 모듈러해서 1,2,3만 생성
	int monster.getlevel = 1;   //몬스터 헤더의 레벨을 가져옴. 시작을 1로 초기화

	if (random == 0)
	{
		return new Goblin(monster.getLevel);
	}
	else if (random == 1)
	{
		return new Orc(monster.getLevel);
	}
	else if (random == 2)
	{
		return new Troll(monster.getLevel);
	}
	else if (getlevel == 10)
	{
		return new BossMonster(10);
	}
}
void GameManager::battle(Character* character)
{
	Monster* monster = generateMonster();  //몬스터 생성
	cout << monster << " 등장" << endl;  //몬스터 생성 알림
	Character* character;  //캐릭터 생성
	
	while (monster->getHealth || character->getHealth == 0) //전투 시스템
	{
		Character->getHealth -= monster->getAttack;   //공격 주고 받기
		cout << Character->getName << "이(가)" << monster << "을(를) 공격했습니다. 체력: " << Character->getHealth << endl;
		monster->getHealth -= Character->getAttack;
		cout << monster << "이(가)" << Character->getName << "을(를) 공격했습니다. 체력: " << monster->getHealth << endl;

		if (Character->getHealth <= 50)  //아이템 사용 시스템
		{
			HealthPotion->use(Character* character);
		}
		else if (Character->getHealth <= 75)
		{
			Attackboost->use(Character* character);
		};

		if (monster->getHealth = 0)  //승리 선언
		{
			cout << monster << "와(과) 싸움에서 승리했다!" << endl;
			delete monster;   //몬스터 삭제
			item->getgold;
			new item name;
			Character->addExperience(Monster->getAttack)  //몬스터의 공격력만큼 레벨업 하기
			
			cout << Character->getName << "이(가)" << gold<< "골드," << item name << "을(를) 획득했다." << endl;
		}
		else
		{
			cout << "사망" << endl;
		};
	}
}
void GameManager::displayInventory()
{
	int potion = healthpotion();  //회복 물약 개수
	int boost = attackboost();  //공격력 강화 개수
	int gold = getgold;  //보유 골드
	cout << "회복 물약" << potion << "개 보유." << endl;
	cout << "공격력 강화" << boost << "개 보유." << endl;
}
void GameManager::visitShop()
{
	while (true)
	{
		cout << "상점에 왔습니다." << endl;
		cout << "보유 골드:" << gold << endl;
		cout << "1. 회복 물약 구매" << endl;
		cout << "2. 회복 물약 판매" << endl;
		cout << "3. 공격력 강화 구매" << endl;
		cout << "4. 공격력 강화 판매" << endl;
		cout << "5. 상점 나가기" << endl;
		int choice = 0;
		cin >> choice;
		if (choice == 1)
		{
			gold -= HealthPotion->getBuyPrice(20);
			cout << "구매 완료." << potion << "개 보유. 남은 골드 " << gold << endl; 
		}
		else if (choice == 2)
		{
			gold += HealthPotion->getBuyPrice(20);
			cout << "판매 완료." << potion << "개 보유. 남은 골드 " << gold << endl; 
		}
		else if (choice == 3)
		{
			gold -=attackboost->getBuyPrice(30);
			cout << "구매 완료." << boost << "개 보유. 남은 골드 " << gold << endl; 
		}
		else if (choice == 4)
		{
			gold -= attackboost->getBuyPrice(30);
			cout << "판매 완료." << boost << "개 보유. 남은 골드 " << gold << endl;
		}
		else if (choice == 5)
		{
			return false;
		}
	}
	
}
