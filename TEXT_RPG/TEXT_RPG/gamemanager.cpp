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
	//������ ���� �����ɴϴ�
	//�� ������ ������ �ν��Ͻ��� �����մϴ�

}
void GameManager::battle(character* player)
{
	Monster* monster = generateMonster(int level);


	//ĳ������ ü�¿��� ������ ���ݷ��� ����
	//������ ü�¿��� ĳ������ ���ݷ��� ����
	//0�� �ɶ����� ���Ϲ��� ������. 
	//���͸� �����´�
	//���Ϳ� ������ �ְ� �޴´�.
	//��� �������� �������� ����?
	//������ ü���� 0�� �Ǹ� ó������ ���ư���.
	//���� �������� �޴´�.
}
void GameManager::displayInventory()
{

}
void GameManager::visitShop()
{

}
