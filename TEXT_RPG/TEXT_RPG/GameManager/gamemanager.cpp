#include <iostream>
#include <cstdlib> // rand(), srand()
#include "GameManager.h"
#include "../Character/Character.h"
#include "../item/HealthPotion.h"
#include "../Monster/Monster.h"


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
	
	while (monster->getHealth || character->getHealth == 0) //���� �ý���
	{
		Character->getHealth -= monster->getAttack;   //���� �ְ� �ޱ�
		cout << Character->getName << "��(��)" << monster << "��(��) �����߽��ϴ�. ü��: " << Character->getHealth << endl;
		monster->getHealth -= Character->getAttack;
		cout << monster << "��(��)" << Character->getName << "��(��) �����߽��ϴ�. ü��: " << monster->getHealth << endl;

		if (Character->getHealth <= 50)  //������ ��� �ý���
		{
			HealthPotion->use(Character* character);
		}
		else if (Character->getHealth <= 75)
		{
			Attackboost->use(Character* character);
		};

		if (monster->getHealth = 0)  //�¸� ����
		{
			cout << monster << "��(��) �ο򿡼� �¸��ߴ�!" << endl;
			delete monster;   //���� ����
			item->getgold;
			new item name;
			Character->addExperience(Monster->getAttack)  //������ ���ݷ¸�ŭ ������ �ϱ�
			
			cout << Character->getName << "��(��)" << gold<< "���," << item name << "��(��) ȹ���ߴ�." << endl;
		}
		else
		{
			cout << "���" << endl;
		};
	}
}
void GameManager::displayInventory()
{
	int potion = healthpotion();  //ȸ�� ���� ����
	int boost = attackboost();  //���ݷ� ��ȭ ����
	int gold = getgold;  //���� ���
	cout << "ȸ�� ����" << potion << "�� ����." << endl;
	cout << "���ݷ� ��ȭ" << boost << "�� ����." << endl;
}
void GameManager::visitShop()
{
	while (true)
	{
		cout << "������ �Խ��ϴ�." << endl;
		cout << "���� ���:" << gold << endl;
		cout << "1. ȸ�� ���� ����" << endl;
		cout << "2. ȸ�� ���� �Ǹ�" << endl;
		cout << "3. ���ݷ� ��ȭ ����" << endl;
		cout << "4. ���ݷ� ��ȭ �Ǹ�" << endl;
		cout << "5. ���� ������" << endl;
		int choice = 0;
		cin >> choice;
		if (choice == 1)
		{
			gold -= HealthPotion->getBuyPrice(20);
			cout << "���� �Ϸ�." << potion << "�� ����. ���� ��� " << gold << endl; 
		}
		else if (choice == 2)
		{
			gold += HealthPotion->getBuyPrice(20);
			cout << "�Ǹ� �Ϸ�." << potion << "�� ����. ���� ��� " << gold << endl; 
		}
		else if (choice == 3)
		{
			gold -=attackboost->getBuyPrice(30);
			cout << "���� �Ϸ�." << boost << "�� ����. ���� ��� " << gold << endl; 
		}
		else if (choice == 4)
		{
			gold -= attackboost->getBuyPrice(30);
			cout << "�Ǹ� �Ϸ�." << boost << "�� ����. ���� ��� " << gold << endl;
		}
		else if (choice == 5)
		{
			return false;
		}
	}
	
}
