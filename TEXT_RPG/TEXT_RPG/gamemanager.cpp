#include <iostream>
#include <cstdlib> // rand(), srand()
#include "GameManager.h"


void GameManager::generateMonster(int level)   //monster*
{
	srand(0);
	int random = rand() % 3;

	if (random == 0)
	{
		/*return new monster1();
	}
	else if (random == 1)
	{
		return new monster2();
	}
	else if (random == 2)
	{
		return new monster3();*/
	}
	//랜덤한 값을 가져옵니다
	//그 값으로 랜덤한 인스턴스를 생성합니다

}
void GameManager::battle(character* player)
{
	Monster* monster = generateMonster(int level);


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
