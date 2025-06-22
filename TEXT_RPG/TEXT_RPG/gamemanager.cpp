#include <iostream>
#include <cstdlib> // rand(), srand()
#include "GameManager.h"
#include "Monster/Monster.h"


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
	while (monster->getHealth || character->getHealth == 0)
	{
		Character->getHealth -= monster->getAttack;   //공격 주고 받기
		cout << Character->getName << "이(가)" << monster << "을(를) 공격했습니다. 체력: " << Character->getHealth << endl;
		monster->getHealth -= Character->getAttack;
		cout << monster << "이(가)" << Character->getName << "을(를) 공격했습니다. 체력: " << monster->getHealth << endl;

		if (monster->getHealth = 0)  //승리 선언
		{
			cout << monster << "와(과) 싸움에서 승리했다!" << endl;
			item->getgold, item;  //아이템과 골드 가져오기
			
			cout << Character->getName << "이(가)" << gold<< "골드, " << item << "을(를) 획득했다." << endl;
		}
		else
		{
			cout << "사망" << endl;
		}
	}


	//캐릭터의 체력에서 몬스터의 공격력을 뺀다
	//몬스터의 체력에서 캐릭터의 공격력을 뺀다
	//0이 될때까지 와일문을 돌린다. 
	//몬스터를 가져온다
	//몬스터와 공격을 주고 받는다.
	//어느 시점에서 아이템을 쓴다?
	//몬스터의 체력이 0이 되면 처음으로 돌아간다.
	//골드와 아이템을 받는다.
}
void GameManager::displayInventory()
{

}
void GameManager::visitShop()
{

}
