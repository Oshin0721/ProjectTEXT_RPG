#include <iostream>
#include <cstdlib> // rand(), srand()
#include "GameManager.h"
#include "Monster/Monster.h"


Monster* GameManager::generateMonster()
{
	srand(0); //���� �� �ʱ�ȭ
	int random = rand() % 3;  //������ ���� 3���� ��ⷯ�ؼ� 1,2,3�� ����
	int monster.getlevel = 1;   //���� ����� ������ ������. ������ 1�� �ʱ�ȭ

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
	Monster* monster = generateMonster();  //���� ����
	cout << monster << " ����" << endl;  //���� ���� �˸�
	Character* character;  //ĳ���� ����
	while (monster->getHealth || character->getHealth == 0)
	{
		Character->getHealth -= monster->getAttack;   //���� �ְ� �ޱ�
		cout << Character->getName << "��(��)" << monster << "��(��) �����߽��ϴ�. ü��: " << Character->getHealth << endl;
		monster->getHealth -= Character->getAttack;
		cout << monster << "��(��)" << Character->getName << "��(��) �����߽��ϴ�. ü��: " << monster->getHealth << endl;

		if (monster->getHealth = 0)  //�¸� ����
		{
			cout << monster << "��(��) �ο򿡼� �¸��ߴ�!" << endl;
			item->getgold, item;  //�����۰� ��� ��������
			
			cout << Character->getName << "��(��)" << gold<< "���, " << item << "��(��) ȹ���ߴ�." << endl;
		}
		else
		{
			cout << "���" << endl;
		}
	}


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
